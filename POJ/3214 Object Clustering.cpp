/* 13084405	840502	3241	Accepted	992K	110MS	C++	2473B	2014-07-15 15:50:08 */
/*

Template By Shark

*/
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
#define MAX_N 50001
#define MAX_M 1000
#define INF 2e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
struct point{
	int x, y, num;
};
struct edge{
	int a, b, w;
};
struct node{
	int p, w;
};
bool cmpP(point &A, point &B){
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}
bool cmpE(edge &A, edge &B){
	return A.w < B.w;
}
bool cmpQ(int *A, int *B){
	return *A < *B;
}
int dist(point &A, point &B){
	return abs(A.x - B.x) + abs(A.y - B.y);
}
point P[MAX_N];
edge E[MAX_N];
node T[MAX_N];
int delta[MAX_N];
int *Q[MAX_N];
int G[MAX_N];
int n, k, e;
int query(int x){
	int min = INF, pos = -1;
	for (int s = x; s <= n; s += s & -s)
		if (T[s].w < min)
			min = T[s].w, pos = T[s].p;
	return pos;
}
void update(int x, int w, int p){
	for (int s = x; s > 0; s -= s & -s)
		if (T[s].w > w)
			T[s].w = w, T[s].p = p;
}
void addEdge(int a, int b, int w){
	E[e].a = a, E[e].b = b, E[e].w = w, e++;
}
int find(int x){
	return x == G[x] ? x : G[x] = find(G[x]);
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &P[i].x, &P[i].y), P[i].num = i;
	e = 0;
	for (int dir = 1; dir <= 4; dir++){
		if (dir == 2 || dir == 4)
			for (int i = 1; i <= n; i++)
				swap(P[i].x, P[i].y);
		else if (dir == 3)
			for (int i = 1; i <= n; i++)
				P[i].x = -P[i].x;
		sort(P + 1, P + n + 1, cmpP);
		for (int i = 1; i <= n; i++)
			delta[i] = P[i].y - P[i].x, Q[i] = &delta[i];
		sort(Q + 1, Q + n + 1, cmpQ);
		for (int i = 1; i <= n; i++)
			*Q[i] = i;
		for (int i = 1; i <= n; i++)
			T[i].p = -1, T[i].w = INF;
		for (int i = n; i >= 1; i--){
			int pos = query(delta[i]);
			if (pos != -1)
				addEdge(P[i].num, P[pos].num, dist(P[i], P[pos]));
			update(delta[i], P[i].x + P[i].y, i);
		}
	}
	sort(E, E + e, cmpE);
	for (int i = 1; i <= n; i++)	G[i] = i;
	for (int i = 0, s = n; s > k && i < e; i++){
		int a = find(E[i].a);
		int b = find(E[i].b);
		if (a != b){
			G[a] = b;
			if (--s == k)
				printf("%d\n", E[i].w);
		}
	}
	return 0;
}
/*

Object Clustering
Time Limit: 2000MS		Memory Limit: 131072K
Total Submissions: 1491		Accepted: 327
Description

We have N (N ≤ 10000) objects, and wish to classify them into several groups by judgement of their resemblance. To simply the model, each object has 2 indexes a and b (a, b ≤ 500). The resemblance of object i and object j is defined by dij = |ai - aj| + |bi - bj|, and then we say i is dij resemble to j. Now we want to find the minimum value of X, so that we can classify the N objects into K (K < N) groups, and in each group, one object is at most X resemble to another object in the same group, i.e, for every object i, if i is not the only member of the group, then there exists one object j (i ≠ j) in the same group that satisfies dij ≤ X

Input

The first line contains two integers N and K. The following N lines each contain two integers a and b, which describe a object.

Output

A single line contains the minimum X.

Sample Input

6 2
1 2
2 3
2 2
3 4
4 3
3 1
Sample Output

2
Source

POJ Monthly--2007.08.05, Li, Haoyuan

*/