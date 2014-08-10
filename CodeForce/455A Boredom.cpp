/* 7396936	2014-08-09 00:03:32	Shark	455A - Boredom	GNU C++	Accepted	46 ms	2400 KB */
/* Template By Shark */
// C++
#include<iostream>
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
// const variable
#define MAX_N 100000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
// main
int n;
int S[MAX_N + 5];
int T[MAX_N + 5];
lli DP[MAX_N + 5][2];
int main(){
	while (scanf("%d", &n) == 1){
		memset(T, 0, sizeof(T));
		memset(DP, 0, sizeof(DP));
		bool found ;
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		for (int i = 1; i <= n; i++)
			T[S[i]]++;
		for (int i = 1; i <= MAX_N; i++){
			DP[i][0] = (lli)DP[i - 1][1] + (lli)T[i] * i;
			DP[i][1] = max(DP[i - 1][0], DP[i - 1][1]);
		}
		printf("%lld\n", max(DP[MAX_N][0],DP[MAX_N][1]));
	}
	return 0;
}
/*

A. Boredom
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games. One long winter evening he came up with a game and decided to play it.

Given a sequence a consisting of n integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 also must be deleted from the sequence. That step brings ak points to the player.

Alex is a perfectionist, so he decided to get as many points as possible. Help him.

Input
The first line contains integer n (1 ≤ n ≤ 105) that shows how many numbers are in Alex's sequence.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 105).

Output
Print a single integer — the maximum number of points that Alex can earn.

Sample test(s)
input
2
1 2
output
2
input
3
1 2 3
output
4
input
9
1 2 1 3 2 2 2 2 3
output
10
Note
Consider the third test example. At first step we need to choose any element equal to 2. After that step our sequence looks like this [2, 2, 2, 2]. Then we do 4 steps, on each step we choose any element equals to 2. In total we earn 10 points.

*/