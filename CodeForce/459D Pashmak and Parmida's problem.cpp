/* 7490070	2014-08-17 10:59:44	Shark	D - Pashmak and Parmida's problem	GNU C++	Accepted	2557 ms	86300 KB */
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1000050
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int n;
int P[MAX_N] = { 0 };
int T[MAX_N] = { 0 };
lli F[MAX_N] = { 0 };
lli C[MAX_N] = { 0 };
lli ans;
map<int, int> S;
map<int, int> R;
void update(lli B[], int x, int value){
	if (x == 0)	return;
	for (int s = x; s <= n; s += (s & -s))
		B[s] += value;
}
lli query(lli B[], int x){
	lli sum = 0;
	for (int s = x; s > 0; s -= (s&-s))
		sum += B[s];
	return sum;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", P + i), S[P[i]]++;
	for (map<int, int>::iterator it = S.begin(); it != S.end(); it++)
		T[it->second]++;
	for (int i = 1; i <= n; i++)
		update(F, i, T[i] * (i - 1)), update(C, i, T[i]);
	ans = 0;
	for (int i = n; i >= 1; i--){
		int target = S[P[i]]--, frequency = ++R[P[i]];
		update(F, target, -(target - 1));
		update(F, target - 1, target - 2);
		update(C, target, -1);
		update(C, target - 1, 1);
		ans += query(F, n) - query(F, frequency) - (query(C, n) - query(C, frequency)) * (frequency - 1);
		//printf("%d, %lld\n",i, ans);
	}
	printf("%lld\n", ans);
	//while (true);
	return 0;
}
/*

D. Pashmak and Parmida's problem
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Parmida is a clever girl and she wants to participate in Olympiads this year. Of course she wants her partner to be clever too (although he's not)! Parmida has prepared the following test problem for Pashmak.

There is a sequence a that consists of n integers a1, a2, ..., an. Let's denote f(l, r, x) the number of indices k such that: l ≤ k ≤ r and ak = x. His task is to calculate the number of pairs of indicies i, j (1 ≤ i < j ≤ n) such that f(1, i, ai) > f(j, n, aj).

Help Pashmak with the test.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 106). The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print a single integer — the answer to the problem.

Sample test(s)
input
7
1 2 1 1 2 2 1
output
8
input
3
1 1 1
output
1
input
5
1 2 3 4 5
output
0

*/