/* 13887337	840502	1714	Accepted	776K	79MS	G++	2706B	2015-02-13 19:07:29 */
#include<bits\stdc++.h>
#define N 505
using namespace std;
struct Node{
	int time;
	int neighbor;
};
struct Edge{
	int v, w;
	Edge(){}
	Edge(int v, int w) :v(v), w(w){}
};
Node S[N];
vector<Edge> E[N];
int n, k;
int outer[N], outerPtr, fix;
int ans[N], minCost;
int tmp[N];
void findOuterCircle(){
	outerPtr = 0;
	outer[outerPtr++] = 1;
	int cur = 1, pre = 1;
	do{
		for (int i = 0; i < E[cur].size(); i++){
			int next = E[cur][i].v;
			if (next == pre || next > k)	continue;
			outer[outerPtr++] = next;
			pre = cur, cur = next;
			break;
		}
	} while (cur != 1);
}
bool check(int cur, int next){
	for (int i = 0; i<E[cur].size(); i++){
		int s = E[cur][i].v;
		if (s == 1)continue;
		if (s != next){
			if (S[s].neighbor <= 1 && S[s].time > 0)
				return false;
		}
		else{
			if (S[s].neighbor <= 0 && S[s].time > 0)
				return false;
		}
	}
	return true;
}
void DFS(int cur, int pre, int cost, int last, int len){
	if (cur == 1 && pre != 0 && len == n){
		if (minCost > cost)
			memcpy(ans, tmp, sizeof(int) * n), minCost = cost;
		return ;
	}
	for (int i = 0; i < E[cur].size() && cur != 1; i++){
		int next = E[cur][i].v;
		S[next].neighbor--;
	}
	for (int i = 0; i < E[cur].size(); i++){
		int next = E[cur][i].v;
		int w = E[cur][i].w;
		if (next == pre || S[next].time == 0)	continue;
		if (!check(cur, next))	continue;
		tmp[len] = next;
		S[next].time--;
		if (next <= k){
			if (last == -1){
				if (next == outer[1])
					DFS(next, cur, cost + w, 1, len + 1);
				else if (next == outer[n])
					DFS(next, cur, cost + w, n, len + 1);
			}
			else{
				if (next == outer[last - 1])
					DFS(next, cur, cost + w, last - 1, len + 1);
				else if (next == outer[last + 1])
					DFS(next, cur, cost + w, last + 1, len + 1);
			}
		}
		else
			DFS(next, cur, cost + w, last, len + 1);
		S[next].time++;
	}
	for (int i = 0; i < E[cur].size() && cur != 1; i++){
		int next = E[cur][i].v;
		S[next].neighbor++;
	}
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 3 * n / 2; i++){
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		E[a].push_back(Edge(b, w));
		E[b].push_back(Edge(a, w));
	}
	for (int i = 1; i <= n; i++)
		S[i].neighbor = 3, S[i].time = 1;
	minCost = 2e9, fix = 0;
	findOuterCircle();
	DFS(1, 0, 0, -1, 0);
	printf("%d", ans[n - 1]);
	for (int i = 0; i < n - 1; i++)
		printf(" %d", ans[i]);
	putchar('\n');
	return 0;
}
/*

Description

There is a lot of caves in Byteland. This is the map of one of them:

All caves in Byteland have the following properties:
All the chambers and passages are on the same level.
No two passages cross each other.
Some of the chambers are situated on the outer circle. They are called outer chambers.
All the other chambers lie inside the outer circle and are called inner chambers.
There is an entrance to the cave leading to one of the outer chambers.
There are exactly three passages leading from every chamber to three different other chambers. If a chamber is an outer chamber then two of the passages lead to two neighbouring outer chambers on the circle and exactly one leads to an inner chamber.
Passages connecting outer chambers are called outer passages and the remaining ones are called inner passages.

It is possible to walk from one chamber to another using only inner passages but there is only one way to do that if we allow to walk through every inner passage at most once.
Not all passages are equally hard to go through. They are divided into two groups: easy and hard.
It has been decided to open all the caves to the public. To assure a "smooth" and safe flow through a cave, visitors should follow a route marked in advance and visit every chamber of this cave exactly once. An exception from this rule is the entrance chamber where every tour begins and ends, you are allowed to visit this chamber exactly twice. The tour route should be fit for an average visitor and contain as few hard passages to walk through as possible.
Example
Consider the cave showed in the figure. The entrance chamber is 1. The dashed passages are hard to walk through. Route 1, 5, 4, 6, 8, 7, 2, 3 contains no hard passages at all. The final chamber, number 1, is implied and not listed.
Task
Write a program that:
reads the description of a cave from standard input;
finds a route through the cave that begins and ends in the entrance chamber, lets the visitors see all the other chambers only once and contains as few hard passages as possible;
writes the result to the standard output.
Input

There are two integers n, k (separated by a single space) in the first line The integer n, 3 < n <= 500, is the number of all chambers in a cave and k is the number of all its outer chambers, k >= 3. The chambers are numbered from 1 to n. Chamber 1 is the entrance chamber. Chambers 1, 2, ..., k are outer chambers. They do not have to appear on the outer circle in this order.

The next 3n / 2 lines contain descriptions of the passages. Each description consists of three integers a, b, c separated by single spaces. The integers a and b are numbers of chambers at the ends of a passage. The integer c equals 0 or 1, where 0 means that the passage is easy to walk through and 1 that it is hard.
Output

Your program should write a sequence of n integers separated by single spaces to the first line of the standard output; the sequence has to begin with 1 (the entrance chamber). The following n - 1 integers should be consecutive chambers on the computed route.
Sample Input

8 5
1 3 0
3 2 0
7 3 1
7 2 0
8 7 0
1 8 0
6 8 0
6 4 0
6 5 1
5 4 0
2 4 0
5 1 0
Sample Output

1 5 4 6 8 7 2 3
Source

CEOI 1997

*/