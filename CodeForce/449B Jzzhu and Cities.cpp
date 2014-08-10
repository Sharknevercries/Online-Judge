/* 7178162	2014-07-19 21:52:42	Shark	449B - Jzzhu and Cities	GNU C++	Accepted	826 ms	26100 KB */
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
#define MAX_N 100001
#define MAX_M 1000
#define INF 1e14
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
struct edge{
	int next;
	lli w;
};
bool cmp(edge A, edge B){
	return A.w < B.w;
}
vector<edge> con[MAX_N];
vector<edge> E;
lli dist[MAX_N];
void SPFA(int s){
	queue<int> Q;
	bool V[MAX_N] = { false };
	Q.push(s);
	V[s] = true;
	while (!Q.empty()){
		int cur = Q.front();	Q.pop();
		for (int i = 0; i < con[cur].size(); i++){
			edge &e = con[cur][i];
			if (dist[cur] + e.w < dist[e.next]){
				dist[e.next] = dist[cur] + e.w;
				if (!V[e.next])
					Q.push(e.next), V[e.next] = true;
			}
		}
		V[cur] = false;
	}
}
int main(){
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 0; i <= n; i++)	dist[i] = INF, con[i].clear();
		E.clear();
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%lld", &a, &b, &w);
			con[a].push_back(edge{ b, w });
			con[b].push_back(edge{ a, w });
		}
		dist[1] = 0;
		SPFA(1);

		int ans = 0;
		for (int i = 0; i < k; i++){
			int b, w;
			scanf("%d%d", &b, &w);
			E.push_back(edge{ b, w });
		}
		sort(E.begin(), E.end(), cmp);
		for (int i = 0; i < k; i++)
			if (dist[E[i].next] > E[i].w)
				dist[E[i].next] = E[i].w, SPFA(E[i].next);
			else
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. Jzzhu and Cities
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jzzhu is the president of country A. There are n cities numbered from 1 to n in his country. City 1 is the capital of A. Also there are m roads connecting the cities. One can go from city ui to vi (and vise versa) using the i-th road, the length of this road is xi. Finally, there are k train routes in the country. One can use the i-th train route to go from capital of the country to city si (and vise versa), the length of this route is yi.

Jzzhu doesn't want to waste the money of the country, so he is going to close some of the train routes. Please tell Jzzhu the maximum number of the train routes which can be closed under the following condition: the length of the shortest path from every city to the capital mustn't change.

Input
The first line contains three integers n, m, k (2 ≤ n ≤ 105; 1 ≤ m ≤ 3·105; 1 ≤ k ≤ 105).

Each of the next m lines contains three integers ui, vi, xi (1 ≤ ui, vi ≤ n; ui ≠ vi; 1 ≤ xi ≤ 109).

Each of the next k lines contains two integers si and yi (2 ≤ si ≤ n; 1 ≤ yi ≤ 109).

It is guaranteed that there is at least one way from every city to the capital. Note, that there can be multiple roads between two cities. Also, there can be multiple routes going to the same city from the capital.

Output
Output a single integer representing the maximum number of the train routes which can be closed.

Sample test(s)
input
5 5 3
1 2 1
2 3 2
1 3 3
3 4 4
1 5 5
3 5
4 5
5 5
output
2
input
2 2 3
1 2 2
2 1 3
2 1
2 2
2 3
output
2

*/