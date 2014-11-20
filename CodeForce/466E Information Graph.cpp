/* 7809212	2014-09-16 16:43:50	Shark	466E - Information Graph	GNU C++	Accepted	62 ms	8400 KB */
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
#define MAX_N 100005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MOD 1000000007
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
struct data{
	int type;
	int x, y;
};
data S[MAX_N];
int queryToNumber[MAX_N], num;
int timer;
int tin[MAX_N], tout[MAX_N], degIn[MAX_N];
int answer[MAX_N];
int group[MAX_N];
vector<int> ask[MAX_N];
vector<int> G[MAX_N];
void DFS(int i, int p){
	tin[i] = timer++;
	for (int j = 0; j < G[i].size(); j++){
		int target = G[i][j];
		if (target != p && tin[target] == NONE)
			DFS(target, i);
	}
	tout[i] = timer++;
}
bool parent(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int find(int x){
	return x == group[x] ? x : group[x] = find(group[x]);
}
void uni(int u, int v){
	u = find(u), v = find(v);
	group[u] = v;
}
int main(){
	int n, q;
	while (scanf("%d%d", &n, &q) == 2){
		timer = num = 0;
		memset(tin, NONE, sizeof(tin));
		memset(tout, NONE, sizeof(tout));
		memset(degIn, 0, sizeof(degIn));
		memset(answer, NONE, sizeof(answer));
		for (int i = 1; i <= n; i++)
			group[i] = i;
		for (int i = 1; i <= q; i++){
			scanf("%d", &S[i].type);
			if (S[i].type == 1)
				scanf("%d%d", &S[i].x, &S[i].y);
			if (S[i].type == 2){
				scanf("%d", &S[i].x);
				queryToNumber[i] = ++num;
			}
			if (S[i].type == 3){
				scanf("%d%d", &S[i].x, &S[i].y);
				ask[S[i].y].push_back(i);
			}
		}
		for (int i = 1; i <= q; i++)
			if (S[i].type == 1)
				G[S[i].y].push_back(S[i].x), degIn[S[i].x]++;
		for (int i = 1; i <= n; i++){
			if (tin[i] != NONE || degIn[i] != 0)	continue;
			DFS(i, NONE);
		}
		for (int i = 1; i <= q; i++){
			if (S[i].type == 1)
				uni(S[i].x, S[i].y);
			if (S[i].type == 2){
				int target = queryToNumber[i];
				int v = S[i].x;
				for (int j = 0; j < ask[target].size(); j++){
					int u = S[ask[target][j]].x;
					answer[ask[target][j]] = (find(u) == find(v) && parent(u, v));
				}
			}
		}
		for (int i = 1; i <= q; i++)
			if (S[i].type == 3)
				printf("%s\n", answer[i] ? "YES" : "NO");
	}
	return 0;
}
/*

E. Information Graph
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
There are n employees working in company "X" (let's number them from 1 to n for convenience). Initially the employees didn't have any relationships among each other. On each of m next days one of the following events took place:

either employee y became the boss of employee x (at that, employee x didn't have a boss before);
or employee x gets a packet of documents and signs them; then he gives the packet to his boss. The boss signs the documents and gives them to his boss and so on (the last person to sign the documents sends them to the archive);
or comes a request of type "determine whether employee x signs certain documents".
Your task is to write a program that will, given the events, answer the queries of the described type. At that, it is guaranteed that throughout the whole working time the company didn't have cyclic dependencies.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 105) — the number of employees and the number of events.

Each of the next m lines contains the description of one event (the events are given in the chronological order). The first number of the line determines the type of event t (1 ≤ t ≤ 3).

If t = 1, then next follow two integers x and y (1 ≤ x, y ≤ n) — numbers of the company employees. It is guaranteed that employee x doesn't have the boss currently.
If t = 2, then next follow integer x (1 ≤ x ≤ n) — the number of the employee who got a document packet.
If t = 3, then next follow two integers x and i (1 ≤ x ≤ n; 1 ≤ i ≤ [number of packets that have already been given]) — the employee and the number of the document packet for which you need to find out information. The document packets are numbered started from 1 in the chronological order.
It is guaranteed that the input has at least one query of the third type.

Output
For each query of the third type print "YES" if the employee signed the document package and "NO" otherwise. Print all the words without the quotes.

Sample test(s)
input
4 9
1 4 3
2 4
3 3 1
1 2 3
2 2
3 1 2
1 3 1
2 2
3 1 3
output
YES
NO
YES

*/