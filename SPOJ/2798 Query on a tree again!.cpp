/* 13599470		2015-02-04 17:17:49	Query on a tree again!	83.33	
edit  run	1.32	21M	
C++
4.9 */
#include<bits\stdc++.h>
#define N 100005
using namespace std;
struct Node{
	int index;
	bool color, mark;
	Node *parent, *child[2];
};
vector<int> E[N];
Node t[N], *EMPTY = t;
int n, q;
void update(Node *x){
	x->mark = x->color;
	if (x->child[0] != EMPTY)	x->mark |= x->child[0]->mark;
	if (x->child[1] != EMPTY)	x->mark |= x->child[1]->mark;
}
void rotate(Node *x, int k){
	Node *y = x->parent;
	y->child[k ^ 1] = x->child[k];
	if (x->child[k] != EMPTY)
		x->child[k]->parent = y;
	x->parent = y->parent;
	if (y->parent->child[0] == y)
		y->parent->child[0] = x;
	else if (y->parent->child[1] == y)
		y->parent->child[1] = x;
	x->child[k] = y;
	y->parent = x;
	update(y);
}
bool splayParent(Node *x, Node *(&y)){
	return (y = x->parent) && (y->child[0] == x || y->child[1] == x);
}
void splay(Node *x){
	if (x == EMPTY)	return;
	for (Node *y, *z; splayParent(x, y);){
		if (splayParent(y, z)){
			int k = y == z->child[0];
			if (x == y->child[k])
				rotate(x, k ^ 1), rotate(x, k);
			else
				rotate(y, k), rotate(x, k);
		}
		else{
			rotate(x, x == y->child[0]);
			break;
		}
	}
	update(x);
}
Node *access(Node *u){
	Node *v = EMPTY;
	for (; u != EMPTY; u = u->parent){
		splay(u);
		u->child[1] = v;
		update(v = u);
	}
	return v;
}
int query(Node *y){
	access(y), splay(y);
	int ans = -1;
	while (y != EMPTY){
		if (y->child[0]->mark)
			y = y->child[0];
		else if (y->color){
			ans = y->index;
			break;
		}
		else
			y = y->child[1];
	}
	return ans;
}
void modify(Node *x){
	splay(x);
	x->color ^= 1;
	update(x);
}
void DFS(int u, int parent){
	for (int i = 0; i < E[u].size(); i++){
		int v = E[u][i];
		if (v != parent)
			t[v].parent = t + u, DFS(v, u);
	}
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 0; i <= n; i++){
		Node *node = t + i;
		node->color = node->mark = false;
		node->index = i;
		node->parent = node->child[0] = node->child[1] = EMPTY;
	}
	for (int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	DFS(1, 0);
	for (int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 0)
			modify(t + y);
		else
			printf("%d\n", query(t + y));
	}
	return 0;
}
/*

You are given a tree (an acyclic undirected connected graph) with N nodes. The tree nodes are numbered from 1 to N. In the start, the color of any node in the tree is white.

We will ask you to perfrom some instructions of the following form:

0 i : change the color of the i-th node (from white to black, or from black to white);
or
1 v : ask for the id of the first black node on the path from node 1 to node v. if it doesn't exist, you may return -1 as its result.
Input

In the first line there are two integers N and Q.

In the next N-1 lines describe the edges in the tree: a line with two integers a b denotes an edge between a and b.

The next Q lines contain instructions "0 i" or "1 v" (1 ≤ i, v ≤ N).

Output

For each "1 v" operation, write one integer representing its result.

Example

Input:
9 8
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
0 2
1 9

Output:
-1
8
-1
2
-1

*/