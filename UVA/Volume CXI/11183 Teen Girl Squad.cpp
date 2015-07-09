/* 15573779	11183	Teen Girl Squad	Accepted	C++	0.077	2015-06-04 05:38:59 */
#include<bits\stdc++.h>
using namespace std;
struct Edge{
	int a, b, w;
	Edge(){}
	Edge(int a, int b, int w) :a(a), b(b), w(w){}
};
int n, m;
Edge E[40005];
int d[1005], s[1005], p[1005], q[1005], v[1005];
int MST(int root){
	memset(q, 0, sizeof(q));
	int w1 = 0, w2 = 0;
	while (true){
		memset(d, 1, sizeof(d));
		memset(s, -1, sizeof(s));
		for (int i = 0; i < m; i++){
			Edge &e = E[i];
			if (e.a != e.b && e.b != root && e.w < d[e.b])
				d[e.b] = e.w, s[e.b] = e.a;
		}
		memset(v, -1, sizeof(v));
		memset(p, -1, sizeof(p));
		w1 = 0;
		bool jf = false;
		for (int i = 0; i < n; i++){
			if (q[i])	continue;
			if (s[i] == -1 && i != root)	return -1;
			if (s[i] >= 0)	w1 += d[i];
			int tp;
			for (tp = i; tp != -1 && v[tp] == -1; tp = s[tp])
				v[tp] = i;
			if (tp != -1 && v[tp] == i){
				jf = true;
				int j = tp;
				do{
					p[j] = tp, q[j] = 1;
					w2 += d[j], j = s[j];
				} while (j != tp);
				q[tp] = 0;
			}
		}
		if (!jf)	break;
		for (int i = 0; i < m; i++){
			Edge &e = E[i];
			if (p[e.b] >= 0)	e.w -= d[e.b];
			if (p[e.a] >= 0)	e.a = p[e.a];
			if (p[e.b] >= 0)	e.b = p[e.b];
			if (e.a == e.b)
				E[i--] = E[--m];
		}
	}
	return w1 + w2;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].w);
		int res = MST(0);
		printf("Case #%d: ", c++);
		if (res == -1)
			puts("Possums!");
		else
			printf("%d\n", res);
	}
	return 0;
}
/*

Problem I
Teen Girl Squad
Input: Standard Input
Output: Standard Output

-- 3 spring rolls please.
-- MSG'D!!
-- Oh! My stomach lining!
Strong Bad

You are part of a group of n teenage girls armed with cellphones. You have some news you want to tell everyone in the group. The problem is that no two of you are in the same room, and you must communicate using only cellphones. What's worse is that due to excessive usage, your parents have refused to pay your cellphone bills, so you must distribute the news by calling each other in the cheapest possible way. You will call several of your friends, they will call some of their friends, and so on until everyone in the group hears the news.

Each of you is using a different phone service provider, and you know the price of girl A calling girl B for all possible A and B. Not all of your friends like each other, and some of them will never call people they don't like. Your job is to find the cheapest possible sequence of calls so that the news spreads from you to all n-1 other members of the group.

Input
The first line of input gives the number of cases, N (N<150). N test cases follow. Each one starts with two lines containing n (0<=n<=1000) and m (0 <= m <= 40,000). Girls are numbered from 0 to n-1, and you are girl 0. The next m lines will each contain 3 integers, u, v and w, meaning that a call from girl u to girl v costs w cents (0 <= w <= 1000). No other calls are possible because of grudges, rivalries and because they are, like, lame. The input file size is around 1200 KB.

Output
For each test case, output one line containing "Case #x:" followed by the cost of the cheapest method of distributing the news. If there is no solution, print "Possums!" instead.

Sample Input                                  Output for Sample Input
4
2
1
0 1 10
2
1
1 0 10
4
4
0 1 10
0 2 10
1 3 20
2 3 30
4
4
0 1 10
1 2 20
2 0 30
2 3 100
Case #1: 10
Case #2: Possums!
Case #3: 40
Case #4: 130

Problem setter: Igor Naverniouk

*/