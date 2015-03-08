/* 857035	840502	2594	Accepted	48544 kb	23212 ms	C++/Edit	4501 B	2015-02-04 16:20:25 */
#include<bits\stdc++.h>
#define N 100005
#define M 1000005
using namespace std;
int getint(){
	char ch = getchar();
	for (; ch > '9' || ch < '0'; ch = getchar());
	int tmp = 0;
	for (; '0' <= ch && ch <= '9'; ch = getchar())
		tmp = tmp * 10 + int(ch) - 48;
	return tmp;
}
struct Command{
	int op, u, v, ans;
};
struct Edge{
	int a, b, w;
	bool deleted;
	Edge(int a = 0, int b = 0) :a(a), b(b){}
	friend bool operator<(Edge A, Edge B){ return A.a < B.a || (A.a == B.a && A.b < B.b); }
};
struct Node{
	int value, index;
	bool rev;
	Node *max, *parent, *child[2];
};
Edge e[M];
Command c[N];
Node t[N + M], *EMPTY = t;
int n, m, q;
void clear(Node *x){
	if (x == EMPTY) return;
	if (x->rev){
		x->child[0]->rev ^= true;
		x->child[1]->rev ^= true;
		swap(x->child[0], x->child[1]);
		x->rev = false;
	}
}
void update(Node *x){
	x->max = x;
	if (x->child[0]->max->value > x->max->value) 
		x->max = x->child[0]->max;
	if (x->child[1]->max->value > x->max->value)
		x->max = x->child[1]->max;
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
Node* access(Node *u){
	Node *v = EMPTY;
	for (; u != EMPTY; u = u->parent){
		splay(u);
		u->child[1] = v;
		update(v = u);
	}
	return v;
}
void makeRoot(Node *x){
	access(x)->rev ^= 1;
	splay(x);
}
Node* getRoot(Node *x){
	for (x = access(x); clear(x), x->child[0] != EMPTY; x = x->child[0]);
	return x;
}
void link(Node *x, Node *y){
	makeRoot(x);
	x->parent = y;
	access(x);
}
void cut(Node *y){
	splay(y);
	y->child[0]->parent = y->parent;
	y->child[1]->parent = EMPTY;
	y->child[0] = y->child[1] = y->parent = EMPTY;
	y->max = y, y->value = 0;
}
int query(Node *x, Node *y){
	makeRoot(x);
	access(y), splay(y);
	return y->max->value;
}
void join(Node *u, Node *v, Node *w){
	if (getRoot(u) == getRoot(v)){
		makeRoot(u);
		access(v), splay(v);
		if (v->max->value < w->value)	return;
		cut(v->max);
		update(v);
	}
	link(v, w);
	link(w, u);
}
int main(){
	n = getint(), m = getint(), q = getint();
	for (int i = 0; i <= n + m; i++){
		Node *node = t + i;
		node->parent = node->child[0] = node->child[1] = EMPTY;
		node->index = i, node->max = node;
	}
	for (int i = 0; i < m; i++){
		e[i].a = getint(), e[i].b = getint(), e[i].w = getint();
		if (e[i].a > e[i].b)	swap(e[i].a, e[i].b);
	}
	sort(e, e + m);
	for (int i = 0; i < q; i++){
		c[i].op = getint(), c[i].u = getint(), c[i].v = getint();
		if (c[i].u > c[i].v)	swap(c[i].u, c[i].v);
		if (c[i].op == 2){
			Edge *node = lower_bound(e, e + m, Edge(c[i].u, c[i].v));
			node->deleted = true;
		}
	}
	for (int i = 0; i < m; i++){
		t[n + 1 + i].value = e[i].w;
		if (!e[i].deleted)
			join(t + e[i].a, t + e[i].b, t + n + 1 + i);
	}
	for (int i = q - 1; i >= 0; i--){
		if (c[i].op == 1)
			c[i].ans = query(t + c[i].u, t + c[i].v);
		else{
			Edge *node = lower_bound(e, e + m, Edge(c[i].u, c[i].v));
			join(t + node->a, t + node->b, t + n + 1 + (node - e));
		}
	}
	for (int i = 0; i < q; i++)
		if (c[i].op == 1)
			printf("%d\n", c[i].ans);
	return 0;
}
/*

Description

SC省MY市有着庞大的地下水管网络，嘟嘟是MY市的水管局长（就是管水管的啦），嘟嘟作为水管局长的工作就是：每天供水公司可能要将一定量的水从x处送往y处，嘟嘟需要为供水公司找到一条从A至B的水管的路径，接着通过信息化的控制中心通知路径上的水管进入准备送水状态，等到路径上每一条水管都准备好了，供水公司就可以开始送水了。嘟嘟一次只能处理一项送水任务，等到当前的送水任务完成了，才能处理下一项。
在处理每项送水任务之前，路径上的水管都要进行一系列的准备操作，如清洗、消毒等等。嘟嘟在控制中心一声令下，这些水管的准备操作同时开始，但由于各条管道的长度、内径不同，进行准备操作需要的时间可能不同。供水公司总是希望嘟嘟能找到这样一条送水路径，路径上的所有管道全都准备就绪所需要的时间尽量短。嘟嘟希望你能帮助他完成这样的一个选择路径的系统，以满足供水公司的要求。另外，由于MY市的水管年代久远，一些水管会不时出现故障导致不能使用，你的程序必须考虑到这一点。
不妨将MY市的水管网络看作一幅简单无向图（即没有自环或重边）：水管是图中的边，水管的连接处为图中的结点。

Input

输入文件第一行为3个整数：N, M, Q分别表示管道连接处（结点）的数目、目前水管（无向边）的数目，以及你的程序需要处理的任务数目（包括寻找一条满足要求的路径和接受某条水管坏掉的事实）。
以下M行，每行3个整数x, y和t，描述一条对应的水管。x和y表示水管两端结点的编号，t表示准备送水所需要的时间。我们不妨为结点从1至N编号，这样所有的x和y都在范围[1, N]内。
以下Q行，每行描述一项任务。其中第一个整数为k：若k=1则后跟两个整数A和B，表示你需要为供水公司寻找一条满足要求的从A到B的水管路径；若k=2，则后跟两个整数x和y，表示直接连接x和y的水管宣布报废（保证合法，即在此之前直接连接x和y尚未报废的水管一定存在）。

Output

按顺序对应输入文件中每一项k=1的任务，你需要输出一个数字和一个回车/换行符。该数字表示：你寻找到的水管路径中所有管道全都完成准备工作所需要的时间（当然要求最短）。

Sample Input

4 4 3

1 2 2

2 3 3

3 4 2

1 4 2

1 1 4

2 1 4

1 1 4

Sample Output

2

3


【原题数据范围】

N ≤ 1000

M ≤ 100000

Q ≤ 100000

测试数据中宣布报废的水管不超过5000条；且任何时候我们考虑的水管网络都是连通的，即从任一结点A必有至少一条水管路径通往任一结点B。


【加强版数据范围】

N ≤ 100000

M ≤ 1000000

Q ≤ 100000

任何时候我们考虑的水管网络都是连通的，即从任一结点A必有至少一条水管路径通往任一结点B。

【C/C++选手注意事项】

由于此题输入规模较大（最大的测试点约20MB），因此即使使用scanf读入数据也会花费较多的时间。为了节省读入耗时，建议使用以下函数读入正整数（返回值为输入文件中下一个正整数）：

int getint()

{

char ch = getchar();

for ( ; ch > '9' || ch < '0'; ch = getchar());

int tmp = 0;

for ( ; '0' <= ch && ch <= '9'; ch = getchar())

tmp = tmp * 10 + int(ch) - 48;

return tmp;

}

HINT

Source

鸣谢Kac

*/