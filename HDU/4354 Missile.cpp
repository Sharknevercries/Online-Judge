/* 12939291	2015-02-12 14:56:00	Accepted	4354	1404MS	1264K	2059 B	G++	Shark */
#include<bits\stdc++.h>
#define N 5005
using namespace std;
struct City{
	int pos, country;
	bool operator<(const City &other) const{
		return pos < other.pos;
	}
};
struct Relation{
	int x, y;
};
struct Edge{
	int v, next;
	Edge(){}
	Edge(int v, int next) :v(v), next(next){}
};
int n, k, m, c;
City C[N];
Relation R[N];
bool V[N];
int mx[N];
int head[N], ptr;
Edge E[N];
void addEdge(int u, int v){
	E[ptr] = Edge(v, head[u]), head[u] = ptr++;
	E[ptr] = Edge(u, head[v]), head[v] = ptr++;
}
void DFS(int cur, int pre, int &res){
	V[cur] = false;
	for (int i = head[cur]; i != -1; i = E[i].next){
		int next = E[i].v;
		if (!V[next])	continue;
		DFS(next, cur, res);
	}
	if (mx[cur] == -1)
		mx[cur] = pre, mx[pre] = cur, res++;
}
bool bipartiteMatching(int a, int b, int k, int m){
	int res = 0;
	memset(V, false, sizeof(V));
	memset(mx, -1, sizeof(mx));
	memset(head, -1, sizeof(head));
	ptr = 0;
	for (int i = a; i <= b; i++)
		V[C[i].country] = true;
	for (int i = 0; i < m; i++)
		if (V[R[i].x] && V[R[i].y])
			addEdge(R[i].x, R[i].y);
	for (int i = a; i <= b; i++)
		if (V[C[i].country])
			DFS(C[i].country, C[i].country, res);
	return res >= k;
}
int solve(){
	sort(C, C + c);
	if (!bipartiteMatching(0, c - 1, k, m))	return -1;
	if (k <= 1)	return 0;
	int L = 0, R = 0;
	int ans = 2e9;
	while (R < c){
		if (bipartiteMatching(L, R, k, m))
			ans = min(ans, C[R].pos - C[L].pos), L++;
		else
			R++;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; q++){
		scanf("%d%d%d%d", &c, &n, &k, &m);
		for (int i = 0; i < c; i++)
			scanf("%d%d", &C[i].pos, &C[i].country);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &R[i].x, &R[i].y);
		printf("Case #%d: %d\n", q, solve());
	}
	return 0;
}
/*

Problem Description
Long long ago,there is a strange area where all the C cities are located in a straight line.To make things easy,lets regard the line as X axis.
Even more strangely,cities belonging to the same country are not necessarily adjacent to each other.
But people of these countries are still living happily with their friends.
However,their enemies are preparing for a disastrous attack.Recently they have invented a new weapon called missile,which can destroy any city if they have enough power.If they want to destroy a set of cities,the power required is max{xi}-min{xj},where i and j are all from the city set they want to destroy.Now the enenies are wondering the minimum power needed to destroy some cities which are from at least K different countries.This is an easy task.The problem is that some countries are strangely protected.That means ,if country A and country B has a special relationship,you can destroy at most one country's cities.A good news is that the relationships will not form circles.But the enemies regard it as helpless,so they order you to write a programme to calculate the specific power.In this task,you can assume that once the missile is launched with certain power,it will destroy the cities from as more countries as possible.


Input
There is an integer T (1<=T<=60) indicating the cases you have to solve.Then the following T cases,each one begins with four integers C,N,K,M.C is the number of cities.N is the number of different countries.K is the number of distinct countries the enemies want to destroy.M is the number of the strange relationships. Then comes the next C lines,each line has two integers.The first one is the city's position x(-109<=x<=109),and the second one is the country Y it belongs to(1<=Y<=N).
No two cities are located in the same position.In last M lines, each line contains two integers A and B (1 <= A, B <= N) which means country A and country B has a special relationship.(1<=C<=5000,1<=N<=2000,1<=K<=N,0<=M<=1000)


Output
First you should output "Case #X:" ,without quote.X means the case number you are dealing with.After that ,you should output a blank and the answer.If it's impossible,then the answer should be -1.See sample for more details.


Sample Input
2
3 3 2 1
0 1
2 2
5 3
1 2

3 3 3 1
0 1
2 2
5 3
1 2


Sample Output
Case #1: 3
Case #2: -1
Hint

Not all the cases are big ones.

Author
1guangnian@UESTC03

Source
2012 Multi-University Training Contest 6

Recommend
zhuyuanchen520

*/