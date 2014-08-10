/* 14016562	10054	The Necklace	Accepted	C++	0.342	2014-08-10 08:27:54 */
/* Template By Shark */
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
#define MAX_N 1005
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct edge{
	int v, rev;
	bool visit;
	edge(){};
	edge(int a, int b, bool c){
		v = a, rev = b, visit = c;
	}
};
struct node{
	int v;
	node *next;
};
vector<edge> E[MAX_N + 1];
node *head;
void print(){
	node *cur = head;
	while (cur->next != NULL){
		printf("%d %d\n", cur->v, cur->next->v);
		cur = cur->next;
	}
}
void insert(node *cur, node *route){
	if (head == NULL)
		head = route;
	else{
		node *tmp = route;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = cur->next;
		cur->next = route;
	}
}
node* makeNode(int v){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->v = v;
	return newnode;
}
bool DFS(int v, int start, node *cur){
	if (v == start)
		return true;
	for (int i = 0; i < E[v].size(); i++){
		edge &e = E[v][i];
		if (!e.visit){
			e.visit = E[e.v][e.rev].visit = true;
			insert(cur, makeNode(e.v));
			cur = cur->next;
			if (DFS(e.v, start, cur))
				return true;
		}
	}
	return true;
}
void connect(int source){
	node *cur, *route;
	cur = head = NULL;
	insert(cur, makeNode(source));
	cur = head;
	while (cur != NULL){
		for (int i = 0; i < E[cur->v].size(); i++){
			edge &e = E[cur->v][i];
			if (!e.visit){
				e.visit = E[e.v][e.rev].visit = true;
				route = makeNode(e.v);
				DFS(e.v, cur->v, route);
				insert(cur, route);
			}
		}
		cur = cur->next;
	}
}
void push(int a, int b){
	if (a != b){
		E[a].push_back(edge(b, E[b].size(), false));
		E[b].push_back(edge(a, E[a].size() - 1, false));
	}
	else{
		E[a].push_back(edge(a, E[a].size() + 1, false));
		E[b].push_back(edge(b, E[b].size() - 1, false));
	}
}
void del(node *cur){
	if (cur->next != NULL)
		del(cur->next);
	free(cur);
}
void init(){
	for (int i = 0; i <= MAX_N; i++)
		E[i].clear();
	if (head != NULL)
		del(head);
	head = NULL;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		init();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			push(a, b);
		}
		bool ok = true;
		for (int i = 1; i <= MAX_N; i++)
			ok &= (E[i].size() % 2 == 0);
		printf("Case #%d\n", c++);
		if (ok){
			for (int i = 1; i <= MAX_N; i++){
				if (E[i].size() > 0){
					connect(i);
					break;
				}
			}
			print();
		}
		else
			puts("some beads may be lost");
		if (t)	putchar('\n');
	}
	return 0;
}
/*

Problem D: The Necklace
My little sister had a beautiful necklace made of colorful beads. Two successive beads in the necklace shared a common color at their meeting point. The figure below shows a segment of the necklace:

But, alas! One day, the necklace was torn and the beads were all scattered over the floor. My sister did her best to recollect all the beads from the floor, but she is not sure whether she was able to collect all of them. Now, she has come to me for help. She wants to know whether it is possible to make a necklace using all the beads she has in the same way her original necklace was made and if so in which order the bids must be put.

Please help me write a program to solve the problem.

Input

The input contains T test cases. The first line of the input contains the integer T.

The first line of each test case contains an integer N (  $5 \le
N \le 1000$) giving the number of beads my sister was able to collect. Each of the next N lines contains two integers describing the colors of a bead. Colors are represented by integers ranging from 1 to 50.

Output

For each test case in the input first output the test case number as shown in the sample output. Then if you apprehend that some beads may be lost just print the sentence ``some beads may be lost" on a line by itself. Otherwise, print N lines with a single bead description on each line. Each bead description consists of two integers giving the colors of its two ends. For  $1 \le i \le N ­ 1$, the second integer on line i must be the same as the first integer on line i + 1. Additionally, the second integer on line N must be equal to the first integer on line 1. Since there are many solutions, any one of them is acceptable.

Print a blank line between two successive test cases.

Sample Input

2
5
1 2
2 3
3 4
4 5
5 6
5
2 1
2 2
3 4
3 1
2 4
Sample Output

Case #1
some beads may be lost

Case #2
2 1
1 3
3 4
4 2
2 2

Miguel Revilla
2000-12-28

*/