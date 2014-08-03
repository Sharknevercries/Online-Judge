/* 13494481	10842	Traffic Flow	Accepted	C++	0.202	2014-04-14 07:42:53 */
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
struct edge{
	int a, b, w;
};
struct edge E[10000];
int P[100];
int n, m;
bool cmp(struct edge A, struct edge B){
	return A.w > B.w;
}
int find(int x){
	return x == P[x] ? x : P[x] = find(P[x]);
}
int MST(){
	int min = 2e9;
	for (int i = 0; i < n; i++)
		P[i] = i;
	sort(E, E + m, cmp);
	for (int i = 0, j = 0; i < m && j < n - 1; i++){
		int x = find(E[i].a), y = find(E[i].b);
		if (x != y){
			P[y] = x;
			j++;
			if (E[i].w < min)
				min = E[i].w;
		}
	}
	return min;
}

int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].w);
		printf("Case #%d: %d\n", c++, MST());
	}
	return 0;
}
/*

Problem C
Traffic Flow
Time Limit: 2 seconds
"Arnie Pie in the sky with the morning commute.
Traffic this morning is as bad as it gets. Due to
a fire at the army testing lab a bunch of escaped,
infected mokeys are roaming the expressway. Despite
the swealtering heat, don't unroll your windows
'cause those monkeys seem confused and irritable."
Arnie Pie, "The Simpsons."

A city has n intersections and m bidirectional roads connecting pairs of intersections. Each road has a certain traffic flow capacity, measured in cars per minute. There is a path from every intersection to every other intersection along some sequence of roads. The road maintenance department is over budget and needs to close as many roads as possible without disconnecting any intersections. They want to do it in such a way that the minimum capacity among all of the remaining roads is as large as possible.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a line containing n (0<n<=100) and m (0<m<=10000). The next m lines will describe the m roads, each one using 3 integers, u, v and c (0<=u,v<n), (0<c<=1000). u and v are the endpoints of the road and c is its capacity.

Output
For each test case, output one line containing "Case #x:" followed by the capacity of the minimum-capacity remaining road.

Sample Input	Sample Output
2
2 3
0 1 10
0 1 20
0 0 30
4 5
0 1 1
3 1 2
1 2 3
2 3 4
0 2 5
Case #1: 20
Case #2: 3
Problemsetter: Igor Naverniouk

*/