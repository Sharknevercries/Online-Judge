/* 7831511	2014-09-18 19:46:16	Shark	B - Fedor and New Game	GNU C++	Accepted	15 ms	8 KB */
// C++
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
int main(){
	int n, m, k, S[MAX_N], ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", S + i);
	for (int i = 0; i < m; i++){
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if ((S[i] & (1 << j)) != (S[m] & (1 << j)))
				cnt++;
		if (cnt <= k)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
/*

B. Fedor and New Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
After you had helped George and Alex to move in the dorm, they went to help their friend Fedor play a new computer game «Call of Soldiers 3».

The game has (m + 1) players and n types of soldiers in total. Players «Call of Soldiers 3» are numbered form 1 to (m + 1). Types of soldiers are numbered from 0 to n - 1. Each player has an army. Army of the i-th player can be described by non-negative integer xi. Consider binary representation of xi: if the j-th bit of number xi equal to one, then the army of the i-th player has soldiers of the j-th type.

Fedor is the (m + 1)-th player of the game. He assume that two players can become friends if their armies differ in at most k types of soldiers (in other words, binary representations of the corresponding numbers differ in at most k bits). Help Fedor and count how many players can become his friends.

Input
The first line contains three integers n, m, k (1 ≤ k ≤ n ≤ 20; 1 ≤ m ≤ 1000).

The i-th of the next (m + 1) lines contains a single integer xi (1 ≤ xi ≤ 2n - 1), that describes the i-th player's army. We remind you that Fedor is the (m + 1)-th player.

Output
Print a single integer — the number of Fedor's potential friends.

Sample test(s)
input
7 3 1
8
5
111
17
output
0
input
3 3 3
1
2
3
4
output
3

*/