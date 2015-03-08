/* 12894341	2015-02-05 14:15:41	Accepted	4010	1310MS	3912K	3793 B	G++	Shark */
#include<bits\stdc++.h>
#define N 300005
using namespace std;
struct Node{
	int value, max, inc;
	bool rev;
	Node *parent, *child[2];
};
Node t[N], *EMPTY = t;
int n, m;
void _inc(Node *x, int value){
	if (x == EMPTY)	return;
	x->inc += value, x->value += value, x->max += value;
}
void clear(Node *x){
	if (x == EMPTY)return;
	if (x->inc != 0){
		_inc(x->child[0], x->inc);
		_inc(x->child[1], x->inc);
		x->inc = 0;
	}
	if (x->rev){
		swap(x->child[0], x->child[1]);
		x->child[0]->rev ^= 1;
		x->child[1]->rev ^= 1;
		x->rev = false;
	}
}
void update(Node *x){
	clear(x), clear(x->child[0]), clear(x->child[1]);
	x->max = max(x->value, max(x->child[0]->max, x->child[1]->max));
}
void rotate(Node *x, int k){
	Node *y = x->parent;
	y->child[k ^ 1] = x->child[k];
	if (x->child[k] != EMPTY)
		x->child[k]->parent = y;
	x->parent = y->parent;
	if (y->parent->child[0] == y)
		x->parent->child[0] = x;
	else if (y->parent->child[1] == y)
		x->parent->child[1] = x;
	x->child[k] = y;
	y->parent = x;
	update(y);
}
bool splayParent(Node *x, Node *(&y)){
	return (y = x->parent) != EMPTY && (y->child[0] == x || y->child[1] == x);
}
void splay(Node *x){
	if (x == EMPTY)return;
	clear(x);
	for (Node *y, *z; splayParent(x, y);){
		if (splayParent(y, z)){
			clear(z), clear(y), clear(x);
			int k = y == z->child[0];
			if (x == y->child[k])
				rotate(x, k ^ 1), rotate(x, k);
			else
				rotate(y, k), rotate(x, k);
		}
		else{
			clear(y), clear(x);
			rotate(x, x == y->child[0]);
			break;
		}
	}
	update(x);
}
Node *access(Node *x){
	Node *y = EMPTY;
	for (; x != EMPTY; x = x->parent){
		splay(x);
		x->child[1] = y;
		update(y = x);
	}
	return y;
}
Node *getRoot(Node *x){
	for (x = access(x); clear(x), x->child[0] != EMPTY; x = x->child[0]);
	return x;
}
void makeRoot(Node *x){
	access(x)->rev ^= 1;
	splay(x);
}
void link(Node *x, Node *y){
	makeRoot(x);
	x->parent = y;
	access(x);
}
void cut(Node *x, Node *y){
	makeRoot(x);
	access(y);
	splay(y);
	y->child[0]->parent = EMPTY;
	y->child[0] = EMPTY;
	update(y);
}
int query(Node *x, Node *y){
	makeRoot(x);
	access(y), splay(y);
	return y->max;
}
void modify(Node *x, Node *y, int value){
	makeRoot(x);
	access(y), splay(y);
	_inc(y, value);
}
int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i <= n; i++){
			t[i].value = t[i].max = t[i].inc = 0;
			t[i].parent = t[i].child[0] = t[i].child[1] = EMPTY;
			t[i].rev = false;
		}
		for (int i = 0; i < n - 1; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			link(t + x, t + y);
		}
		for (int i = 1; i <= n; i++){
			int value;
			scanf("%d", &value);
			Node *node = t + i;
			splay(node);
			node->value = node->max = value;
			update(node);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int command, x, y, z;
			scanf("%d%d%d", &command, &x, &y);
			switch (command){
			case 1:
				if (getRoot(t + x) == getRoot(t + y))
					printf("-1\n");
				else
					link(t + x, t + y);
				break;
			case 2:
				if (x == y || getRoot(t + x) != getRoot(t + y))
					printf("-1\n");
				else
					cut(t + x, t + y);
				break;
			case 3:
				scanf("%d", &z);
				if (getRoot(t + y) != getRoot(t + z))
					printf("-1\n");
				else
					modify(t + y, t + z, x);
				break;
			case 4:
				if (getRoot(t + x) != getRoot(t + y))
					printf("-1\n");
				else
					printf("%d\n", query(t + x, t + y));
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
/*

Problem Description
We have met so many problems on the tree, so today we will have a query problem on a set of trees.
There are N nodes, each node will have a unique weight Wi. We will have four kinds of operations on it and you should solve them efficiently. Wish you have fun!

Input
There are multiple test cases in our dataset.
For each case, the first line contains only one integer N.(1 ≤ N ≤ 300000) The next N‐1 lines each contains two integers x, y which means there is an edge between them. It also means we will give you one tree initially.
The next line will contains N integers which means the weight Wi of each node. (0 ≤ Wi ≤ 3000)
The next line will contains an integer Q. (1 ≤ Q ≤ 300000) The next Q lines will start with an integer 1, 2, 3 or 4 means the kind of this operation.
1. Given two integer x, y, you should make a new edge between these two node x and y. So after this operation, two trees will be connected to a new one.
2. Given two integer x, y, you should find the tree in the tree set who contain node x, and you should make the node x be the root of this tree, and then you should cut the edge between node y and its parent. So after this operation, a tree will be separate into two parts.
3. Given three integer w, x, y, for the x, y and all nodes between the path from x to y, you should increase their weight by w.
4. Given two integer x, y, you should check the node weights on the path between x and y, and you should output the maximum weight on it.


Output
For each query you should output the correct answer of it. If you find this query is an illegal operation, you should output ‐1.
You should output a blank line after each test case.


Sample Input
5
1 2
2 4
2 5
1 3
1 2 3 4 5
6
4 2 3
2 1 2
4 2 3
1 3 5
3 2 1 4
4 1 4


Sample Output
3
-1
7

Hint

We define the illegal situation of different operations:
In first operation: if node x and y belong to a same tree, we think it's illegal.
In second operation: if x = y or x and y not belong to a same tree, we think it's illegal.
In third operation: if x and y not belong to a same tree, we think it's illegal.
In fourth operation: if x and y not belong to a same tree, we think it's illegal.

Source
The 36th ACM/ICPC Asia Regional Dalian Site —— Online Contest

Recommend
lcy   |   We have carefully selected several similar problems for you:  4004 4005 4006 4007 4001

*/