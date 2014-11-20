/* 7867362	2014-09-20 17:03:43	Shark	A - I Wanna Be the Guy	GNU C++	Accepted	31 ms	88 KB */
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
	int n, n1, n2;
	bool V[MAX_N] = { false };
	scanf("%d", &n);
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++){
		int a;
		scanf("%d", &a);
		V[a] = true;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++){
		int a;
		scanf("%d", &a);
		V[a] = true;
	}
	bool res = true;
	for (int i = 1; i <= n; i++)
		if (!V[i])
			res = false;
	if (res)
		puts("I become the guy.");
	else
		puts("Oh, my keyboard!");
	return 0;
}
/*

A. I Wanna Be the Guy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a game called "I Wanna Be the Guy", consisting of n levels. Little X and his friend Little Y are addicted to the game. Each of them wants to pass the whole game.

Little X can pass only p levels of the game. And Little Y can pass only q levels of the game. You are given the indices of levels Little X can pass and the indices of levels Little Y can pass. Will Little X and Little Y pass the whole game, if they cooperate each other?

Input
The first line contains a single integer n (1 ≤  n ≤ 100).

The next line contains an integer p (0 ≤ p ≤ n) at first, then follows p distinct integers a1, a2, ..., ap (1 ≤ ai ≤ n). These integers denote the indices of levels Little X can pass. The next line contains the levels Little Y can pass in the same format. It's assumed that levels are numbered from 1 to n.

Output
If they can pass all the levels, print "I become the guy.". If it's impossible, print "Oh, my keyboard!" (without the quotes).

Sample test(s)
input
4
3 1 2 3
2 2 4
output
I become the guy.
input
4
3 1 2 3
2 2 3
output
Oh, my keyboard!
Note
In the first sample, Little X can pass levels [1 2 3], and Little Y can pass level [2 4], so they can pass all the levels both.

In the second sample, no one can pass level 4.

*/