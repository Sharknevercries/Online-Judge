/* 7457516	2014-08-15 19:48:36	Shark	B - Pashmak and Flowers	GNU C++	Accepted	62 ms	800 KB */
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
#define MAX_N 200010
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int S[MAX_N];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int count[2] = { 0 }, T[2] = { 0 };
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		T[0] = 0, T[1] = INF;
		for (int i = 0; i < n; i++){
			if (S[i] > T[0])
				T[0] = S[i], count[0] = 1;
			else if (S[i] == T[0])
				count[0]++;
			if (S[i] < T[1])
				T[1] = S[i], count[1] = 1;
			else if (S[i] == T[1])
				count[1]++;
		}
		if (T[0] == T[1])
			printf("%d %lld\n", 0, (lli)count[0] * (count[0] - 1) / 2);
		else
			printf("%d %lld\n", T[0] - T[1], (lli)count[0] * count[1]);
	}
	return 0;
}
/*

B. Pashmak and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

The maximum beauty difference of flowers that Pashmak can give to Parmida.
The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.
Input
The first line of the input contains n (2 ≤ n ≤ 2·105). In the next line there are n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109).

Output
The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

Sample test(s)
input
2
1 2
output
1 1
input
3
1 4 5
output
4 1
input
5
3 1 2 3 1
output
2 4
Note
In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:

choosing the first and the second flowers;
choosing the first and the fifth flowers;
choosing the fourth and the second flowers;
choosing the fourth and the fifth flowers.

*/