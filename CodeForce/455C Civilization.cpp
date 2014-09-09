/* 7472873	2014-08-15 21:22:47	Shark	459C - Pashmak and Buses	GNU C++	Accepted	171 ms	100 KB */
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
#define MAX_N 300005
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
vector<int> E[MAX_N];
int diameter[MAX_N], G[MAX_N];
bool used[MAX_N];
int maxH, maxHV;
void DFS(int v, int depth, int p){
	if (depth > maxH)
		maxH = depth, maxHV = v;
	for (int i = 0; i < E[v].size(); i++){
		int target = E[v][i];
		if (target != p)
			DFS(target, depth + 1, v);
	}
}
int getH(int v){
	maxH = -1;
	DFS(v, 0, -1);
	maxH = -1;
	DFS(maxHV, 0, -1);
	return maxH;
}
int find(int x){
	return x == G[x] ? x : G[x] = find(G[x]);
}
int rad(int v){
	return (diameter[v] + 1) / 2;
}
void union1(int a, int b){
	a = find(a);
	b = find(b);
	G[a] = b;
}
void union2(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b)	return;
	G[a] = b;
	diameter[b] = max(rad(a) + rad(b) + 1, diameter[a], diameter[b]);
}
int main(){
	int n, m, q;
	while (scanf("%d%d%d", &n, &m, &q) == 3){
		for (int i = 1; i <= n; i++)
			E[i].clear(), diameter[i] = 0, G[i] = i;
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
			union1(a, b);
		}
		for (int i = 1; i <= n; i++){
			int p = find(i);
			if (!used[p])
				used[p] = true, diameter[p] = getH(i);
		}
		for (int i = 0; i < q; i++){
			int command, a, b;
			scanf("%d", &command);
			if (command == 1){
				scanf("%d", &a);
				printf("%d\n", diameter[find(a)]);
			}
			else{
				scanf("%d%d", &a, &b);
				union2(a, b);
			}
		}
	}
	return 0;
}
/*

C. Pashmak and Buses
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently Pashmak has been employed in a transportation company. The company has k buses and has a contract with a school which has n students. The school planned to take the students to d different places for d days (each day in one place). Each day the company provides all the buses for the trip. Pashmak has to arrange the students in the buses. He wants to arrange the students in a way that no two students become close friends. In his ridiculous idea, two students will become close friends if and only if they are in the same buses for all d days.

Please help Pashmak with his weird idea. Assume that each bus has an unlimited capacity.

Input
The first line of input contains three space-separated integers n, k, d (1 ≤ n, d ≤ 1000; 1 ≤ k ≤ 109).

Output
If there is no valid arrangement just print -1. Otherwise print d lines, in each of them print n integers. The j-th integer of the i-th line shows which bus the j-th student has to take on the i-th day. You can assume that the buses are numbered from 1 to k.

Sample test(s)
input
3 2 2
output
1 1 2
1 2 1
input
3 2 1
output
-1
Note
Note that two students become close friends only if they share a bus each day. But the bus they share can differ from day to day.

*/