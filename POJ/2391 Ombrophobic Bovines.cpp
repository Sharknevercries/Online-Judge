/* 13871934	840502	2391	Accepted	2168K	485MS	C++	3037B	2015-02-08 19:53:52 */
#include<bits\stdc++.h>
using namespace std;
#define MAX_N 500
#define NONE -1
#define INF 1e9
struct edge{ 
	int v, cap, rev; 
	edge(int v, int cap, int rev) :v(v), cap(cap), rev(rev){}
};
int level[MAX_N], iter[MAX_N];
int n, m;
long long int dist[MAX_N][MAX_N];
long long int cow[MAX_N], size[MAX_N], cowSum, sizeSum, maxTime;;
vector<edge> G[MAX_N];
void addEdge(int u, int v, int cap){
	G[u].push_back(edge(v, cap, G[v].size()));
	G[v].push_back(edge(u, 0, G[u].size() - 1));
}
void BFS(int s){
	memset(level, NONE, sizeof(level));
	queue<int> Q;
	level[s] = 0;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front();	Q.pop();
		for (int i = 0; i < G[u].size(); i++){
			edge &e = G[u][i];
			if (e.cap > 0 && level[e.v] == NONE)
				level[e.v] = level[u] + 1, Q.push(e.v);
		}
	}
}
int DFS(int u, int t, int flow){
	if (u == t)	return flow;
	for (int &i = iter[u]; i < G[u].size(); i++){
		edge &e = G[u][i];
		if (e.cap > 0 && level[u] < level[e.v]){
			int d = DFS(e.v, t, min(flow, e.cap));
			if (d > 0){
				e.cap -= d;
				G[e.v][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t){
	int flow = 0;
	while (true){
		BFS(s);
		if (level[t] == NONE)
			return flow;
		memset(iter, 0, sizeof(iter));
		while (true){
			int tmp = DFS(s, t, INF);
			if (tmp <= 0)	break;
			flow += tmp;
		}
	}
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = (long long)1e15;
		cowSum = sizeSum = maxTime = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld", &cow[i], &size[i]), cowSum += cow[i], sizeSum += size[i];
		for (int i = 0; i < m; i++){
			long long int a, b, w;
			scanf("%lld%lld%lld", &a, &b, &w);
			dist[a][b] = dist[b][a] = min(dist[a][b], w);
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] < (long long)1e15)
					maxTime = max(dist[i][j], maxTime);
		long long int L = 0, R = maxTime, ans = -1;
		while (L <= R){
			for (int i = 0; i < MAX_N; i++)
				G[i].clear();
			long long int mid = (L + R) / 2;
			for (int i = 1; i <= n; i++)
				addEdge(0, i, cow[i]);
			for (int i = 1; i <= n; i++)
				addEdge(n + i, 2 * n + 1, size[i]);
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dist[i][j] <= mid)
						addEdge(i, n + j, INF);
			int res = maxFlow(0, 2 * n + 1);
			if (res == cowSum)
			    R = mid - 1, ans = mid;
			else
				L = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Description

FJ's cows really hate getting wet so much that the mere thought of getting caught in the rain makes them shake in their hooves. They have decided to put a rain siren on the farm to let them know when rain is approaching. They intend to create a rain evacuation plan so that all the cows can get to shelter before the rain begins. Weather forecasting is not always correct, though. In order to minimize false alarms, they want to sound the siren as late as possible while still giving enough time for all the cows to get to some shelter.

The farm has F (1 <= F <= 200) fields on which the cows graze. A set of P (1 <= P <= 1500) paths connects them. The paths are wide, so that any number of cows can traverse a path in either direction.

Some of the farm's fields have rain shelters under which the cows can shield themselves. These shelters are of limited size, so a single shelter might not be able to hold all the cows. Fields are small compared to the paths and require no time for cows to traverse.

Compute the minimum amount of time before rain starts that the siren must be sounded so that every cow can get to some shelter.
Input

* Line 1: Two space-separated integers: F and P

* Lines 2..F+1: Two space-separated integers that describe a field. The first integer (range: 0..1000) is the number of cows in that field. The second integer (range: 0..1000) is the number of cows the shelter in that field can hold. Line i+1 describes field i.

* Lines F+2..F+P+1: Three space-separated integers that describe a path. The first and second integers (both range 1..F) tell the fields connected by the path. The third integer (range: 1..1,000,000,000) is how long any cow takes to traverse it.
Output

* Line 1: The minimum amount of time required for all cows to get under a shelter, presuming they plan their routes optimally. If it not possible for the all the cows to get under a shelter, output "-1".
Sample Input

3 4
7 2
0 4
2 6
1 2 40
3 2 70
2 3 90
1 3 120
Sample Output

110
Hint

OUTPUT DETAILS:

In 110 time units, two cows from field 1 can get under the shelter in that field, four cows from field 1 can get under the shelter in field 2, and one cow can get to field 3 and join the cows from that field under the shelter in field 3. Although there are other plans that will get all the cows under a shelter, none will do it in fewer than 110 time units.
Source

USACO 2005 March Gold

*/
