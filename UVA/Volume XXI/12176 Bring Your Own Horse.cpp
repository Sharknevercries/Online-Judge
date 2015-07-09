/* 15588013	12176	Bring Your Own Horse	Accepted	C++	0.238	2015-06-06 14:43:03 */
#include<bits\stdc++.h>
using namespace std;
struct Edge{
	int a, b, w;
	Edge(){}
	Edge(int a, int b, int w) :a(a), b(b), w(w){}
};
vector<Edge> E;
vector<Edge> G[3005];
int P[3005];
int find(int x){
	return x == P[x] ? x : P[x] = find(P[x]);
}
bool cmp(Edge A, Edge B){
	return A.w < B.w;
}
bool query(int cur, int prev, int target, int &ans){
	if (cur == target) return true;
	for (int i = 0; i < G[cur].size(); i++){
		Edge &e = G[cur][i];
		if (e.b == prev)	continue;
		if (query(e.b, cur, target, ans)){
			ans = max(ans, e.w);
			return true;
		}
	}
	return false;
}
int main(){
	int t, c= 1;
	scanf("%d", &t);
	while (t--){
		int n, m, q;
		scanf("%d%d", &n, &m);
		E.clear();
		for (int i = 1; i <= n; i++)
			P[i] = i, G[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			E.push_back(Edge(a, b, w));
		}
		sort(E.begin(), E.end(), cmp);
		for (int i = 0; i < m; i++){
			int a = find(E[i].a);
			int b = find(E[i].b);
			if (a == b)	continue;
			P[b] = a;
			G[E[i].a].push_back(Edge(E[i].a, E[i].b, E[i].w));
			G[E[i].b].push_back(Edge(E[i].b, E[i].a, E[i].w));
		}
		scanf("%d", &q);
		printf("Case %d\n", c++);
		for (int i = 0; i < q; i++){
			int a, b, ans = 0;
			scanf("%d%d", &a, &b);
			query(a, -1, b, ans);
			printf("%d\n", ans);
		}
		putchar('\n');
	}
	return 0;
}
/*

12176 Bring Your Own Horse
One of the essential activities of a knight is to compete in tournaments. Frequently, groups of knights
gather around the country to compare their skills. On such a typical contest day, everyone has five
hours to do ten disciplines, such as sword fighting, bow and arrow, and various forms of horseback
riding. Needless to say, you have to bring your own horse.
This is not as easy as it seems. It often takes a knight several days to go from the castle where he
lives to the place where a tournament is held. But horses sometimes are very, very stubborn. After
having covered a certain distance on a single day, they sometimes simply stop and refuse to go any
further. Luckily, they start anew on the next day. To make sure that the horse does not refuse service
before the scheduled day trip is completed, a knight wants to choose an itinerary on which the longest
day trip is as short as possible. Hence, a trip that takes many days with short distances is preferable
over a shorter route that has the risk of a refusing horse.
Write a program which answers queries from knights spread all over the country about the best way
to go from their castles to a tournament site. Given a description of the relevant places (i.e. castles,
locations of tournaments, and hostels for overnight stays), the program should tell them the largest
distance they have to cover on a single day so that this distance is minimal among all possible itineraries.
The places are designated by consecutive integers from 1 to N , while a road is represented by
three integers, namely its place of origin, its destination, and its length. Every road can be used in
both directions, and there is at least one route (i.e. a sequence of roads) between any two places. The
knights stick to the given roads while travelling and spend their nights only at one of the N places.
Input
The first line contains the total number of test cases that follow.
Each test case begins with a line that first holds the number N of places (1 ≤ N ≤ 3000) followed
by the number R of roads (1 ≤ R ≤ 100000). Then there are R lines with three integers each (a,
b, and l), each of which defines a road connecting the places a and b (1 ≤ a, b ≤ N) with length l
(1 ≤ l ≤ 1000000).
Thereafter, each test case continues with the number Q of queries on a line by itself (1 ≤ Q ≤ 1000).
Each of the next Q lines holds two integers k and t, indicating a query by a knight who lives at place
k and needs to go to a tournament at place t (1 ≤ k, t ≤ N, k = t).
Output
For each test case output a line containing the word ‘Case’, a single space, and its serial number
(starting with 1 for the first test case). Then, print one line for each query in this test case, containing
the smallest maximal day trip distance as described above. Print a blank line after each test case.
Sample Input
2
4 4
1 2 100
2 3 100
3 4 100
4 1 200
1
Universidad de Valladolid OJ: 12176 – Bring Your Own Horse 2/2
1 4
6 9
2 4 5
5 1 7
3 6 6
3 1 4
2 3 2
1 2 1
6 5 42
4 5 3
4 6 5
4
1 3
3 4
5 4
6 1
Sample Output
Case 1
100
Case 2
2
5
3
5

*/