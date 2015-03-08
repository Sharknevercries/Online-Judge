/* 858449	840502	2002	Accepted	5180 kb	1332 ms	C++/Edit	2350 B	2015-02-05 18:10:16 */
#include<bits\stdc++.h>
#define N 200005
using namespace std;
struct Node{
	int size;
	int index;
	Node *parent, *child[2];
};
Node t[N], *EMPTY = t;
int n, m;
void update(Node *x){
	x->size = x->child[0]->size + 1 + x->child[1]->size;
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
	y->parent = x;
	x->child[k] = y;
	update(y);
}
bool splayParent(Node *x, Node *(&y)){
	return (y = x->parent) != EMPTY && (y->child[0] == x || y->child[1] == x);
}
void splay(Node *x){
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
Node* access(Node *u){
	Node *v = EMPTY;
	for (; u != EMPTY; u = u->parent){
		splay(u);
		u->child[1] = v;
		update(v = u);
	}
	return v;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++){
		Node *node = t + i;
		node->parent = node->child[0] = node->child[1] = EMPTY;
		node->size = 0;
	}
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		Node *node = t + i;
		node->parent = i + x <= n ? t + i + x : EMPTY;
		node->size = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int command, x, y;
		scanf("%d%d", &command, &x);
		Node *node = t + (++x);
		if (command == 1)
			printf("%d\n", access(node)->size);
		else{
			scanf("%d", &y);
			splay(node);
			node->child[0]->parent = node->parent;
			node->child[0] = EMPTY;
			node->parent = x + y <= n ? t + x + y : EMPTY;
		}
	}
	return 0;
}
/*

Description

某天，Lostmonkey发明了一种超级弹力装置，为了在他的绵羊朋友面前显摆，他邀请小绵羊一起玩个游戏。游戏一开始，Lostmonkey在地上沿着一条直线摆上n个装置，每个装置设定初始弹力系数ki，当绵羊达到第i个装置时，它会往后弹ki步，达到第i+ki个装置，若不存在第i+ki个装置，则绵羊被弹飞。绵羊想知道当它从第i个装置起步时，被弹几次后会被弹飞。为了使得游戏更有趣，Lostmonkey可以修改某个弹力装置的弹力系数，任何时候弹力系数均为正整数。

Input

第一行包含一个整数n，表示地上有n个装置，装置的编号从0到n-1,接下来一行有n个正整数，依次为那n个装置的初始弹力系数。第三行有一个正整数m，接下来m行每行至少有两个数i、j，若i=1，你要输出从j出发被弹几次后被弹飞，若i=2则还会再输入一个正整数k，表示第j个弹力装置的系数被修改成k。对于20%的数据n,m<=10000，对于100%的数据n<=200000,m<=100000

Output

对于每个i=1的情况，你都要输出一个需要的步数，占一行。

Sample Input

4

1 2 1 1

3

1 1

2 1 1

1 1

Sample Output

2

3

HINT

Source

Splay 启发式合并

*/