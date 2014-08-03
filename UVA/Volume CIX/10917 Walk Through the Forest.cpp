/* 13674197	10917	Walk Through the Forest	Accepted	C++	0.049	2014-05-24 11:32:21 */
#include<cstdio>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
struct edge{
	int dest, w;
};
vector<struct edge> D[1001];
vector<int> M[1001];
int DP[1001];
bool V[1001];
int C[1001];
int n, m;
void SPFA(){
	queue<int> Q;
	memset(V, false, sizeof(V));
	for (int i = 0; i <= n; i++)
		DP[i] = 2e9;

	Q.push(2);
	V[2] = true;
	DP[2] = 0;
	while (!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < D[cur].size(); i++){
			int next = D[cur][i].dest;
			int dist = D[cur][i].w;
			if (DP[cur] + dist < DP[next]){
				if (!V[next])
					Q.push(next);
				DP[next] = DP[cur] + dist;
			}
		}
		V[cur] = false;
	}
}
void Toplogical(){
	int in[1001] = { 0 };
	for (int i = 0; i <= n; i++)
		M[i].clear();
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < D[i].size(); j++){
			int next = D[i][j].dest;
			if (DP[i] > DP[next]){
				M[i].push_back(next);
				in[next]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		C[i] = 0, V[i] = false;
	C[1] = 1;

	while (true){
		int cur = -1;
		for (int i = 1; i <= n; i++)
			if (!V[i] && in[i] == 0)
				cur = i;
		if (cur == -1)	break;
		V[cur] = true;
		for (int i = 0; i < M[cur].size(); i++){
			C[M[cur][i]] += C[cur];
			in[M[cur][i]]--;
		}
	}
}

int main(){
	while (scanf("%d", &n) == 1){
		if (n == 0)	break;
		scanf("%d", &m);
		for (int i = 0; i <= n; i++)
			D[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			struct edge tmp;
			tmp.dest = b, tmp.w = w;
			D[a].push_back(tmp);
			tmp.dest = a;
			D[b].push_back(tmp);
		}
		SPFA();
		Toplogical();
		printf("%d\n", C[2]);
	}
	return 0;
}
/*

Problem C: A Walk Through the Forest

Jimmy experiences a lot of stress at work these days, especially since his accident made working difficult. To relax after a hard day, he likes to walk home. To make things even nicer, his office is on one side of a forest, and his house is on the other. A nice walk through the forest, seeing the birds and chipmunks is quite enjoyable.
The forest is beautiful, and Jimmy wants to take a different route everyday. He also wants to get home before dark, so he always takes a path to make progress towards his house. He considers taking a path from A to B to be progress if there exists a route from B to his home that is shorter than any possible route from A. Calculate how many different routes through the forest Jimmy might take.

Input

Input contains several test cases followed by a line containing 0. Jimmy has numbered each intersection or joining of paths starting with 1. His office is numbered 1, and his house is numbered 2. The first line of each test case gives the number of intersections N, 1 < N ≤ 1000, and the number of paths M. The following M lines each contain a pair of intersections a b and an integer distance 1 ≤ d ≤ 1000000 indicating a path of length d between intersection a and a different intersection b. Jimmy may walk a path any direction he chooses. There is at most one path between any pair of intersections.
Output

For each test case, output a single integer indicating the number of different routes through the forest. You may assume that this number does not exceed 2147483647.
Sample Input

5 6
1 3 2
1 4 2
3 4 3
1 5 12
4 2 34
5 2 24
7 8
1 3 1
1 4 1
3 7 1
7 4 1
7 5 1
6 7 1
5 2 1
6 2 1
0
Output for Sample Input

2
4
(apologies to) Richard Krueger

*/