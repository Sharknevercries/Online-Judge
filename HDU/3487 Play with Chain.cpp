/* 12812752	2015-01-26 19:23:30	Accepted	3487	873MS	8212K	3580 B	G++	Shark */
#include<bits\stdc++.h>
#define keyValue T[T[root].child[1]].child[0]
using namespace std;
struct node{
	int value;
	int child[2], parent;
	int size;
	bool rev;
	node(){}
	node(int value, int L, int R, int parent) :value(value), parent(parent){
		child[0] = L, child[1] = R, rev = false, size = 1;
	}
};
node T[300005];
int n, m;
int root, total;
bool first;
void pushUp(int x){
	T[x].size = T[T[x].child[0]].size + T[T[x].child[1]].size + 1;
}
void pushDown(int x){
	if (T[x].rev){
		swap(T[x].child[0], T[x].child[1]);
		T[T[x].child[0]].rev ^= 1;
		T[T[x].child[1]].rev ^= 1;
		T[x].rev = false;
	}
}
void newNode(int &cur, int parent, int value){
	cur = ++total;
	T[cur] = node(value, 0, 0, parent);
}
void build(int &cur, int parent, int L, int R){
	if (L > R)return;
	int mid = (L + R) / 2;
	newNode(cur, parent, mid);
	build(T[cur].child[0], cur, L, mid - 1);
	build(T[cur].child[1], cur, mid + 1, R);
	pushUp(cur);
}
void rotate(int x, int k){
	int y = T[x].parent;
	T[y].child[!k] = T[x].child[k];
	T[T[x].child[k]].parent = y;
	if (T[y].parent != 0)
		T[T[y].parent].child[T[T[y].parent].child[1] == y] = x;
	T[x].parent = T[y].parent;
	T[x].child[k] = y;
	T[y].parent = x;
	pushUp(y);
}
void splay(int x, int r){
	while (T[x].parent != r){
		if (T[T[x].parent].parent == r)
			rotate(x, T[T[x].parent].child[0] == x);
		else{
			int y = T[x].parent;
			int k = (T[T[y].parent].child[0] == y);
			if (T[y].child[k] == x)
				rotate(x, !k), rotate(x, k);
			else
				rotate(y, k), rotate(x, k);
		}
	}
	pushUp(x);
	if (r == 0)	root = x;
}
int getMin(int x){
	pushDown(x);
	while (T[x].child[0])
		x = T[x].child[0], pushDown(x);
	return x;
}
int getKth(int x, int k){
	pushDown(x);
	int tmp = T[T[x].child[0]].size;
	if (tmp == k - 1)
		return x;
	else if (tmp >= k)
		return getKth(T[x].child[0], k);
	else
		return getKth(T[x].child[1], k - tmp - 1);
}
void cut(int a, int b, int c){
	int x = getKth(root, a);
	int y = getKth(root, b);
	splay(x, 0);
	splay(y, root);
	int tmp = keyValue;
	keyValue = 0;
	pushUp(T[root].child[1]);
	pushUp(root);
	int z = getKth(root, c);
	splay(z, 0);
	int m = getMin(T[root].child[1]);
	splay(m, root);
	keyValue = tmp;
	T[keyValue].parent = T[root].child[1];
	pushUp(T[root].child[1]);
	pushUp(root);
}
void flip(int a, int b){
	int x = getKth(root, a);
	int y = getKth(root, b);
	splay(x, 0);
	splay(y, root);
	T[keyValue].rev ^= 1;
}
void inOrder(int x){
	if (x == 0)	return;
	pushDown(x);
	inOrder(T[x].child[0]);
	if (T[x].value >= 1 && T[x].value <= n){
		if (!first)	putchar(' ');
		first = false;
		printf("%d", T[x].value);
	}
	inOrder(T[x].child[1]);
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		if (n == -1 && m == -1)	break;
		total = root = 0;
		memset(T, 0, sizeof(T));
		newNode(root, 0, 0);
		newNode(T[root].child[1], root, n + 1);
		pushUp(root);
		build(keyValue, T[root].child[1], 1, n);
		pushUp(T[root].child[1]);
		pushUp(root);
		for (int i = 0; i < m; i++){
			char com[5];
			int a, b, c;
			scanf("%s", com);
			if (com[0] == 'C')
				scanf("%d%d%d", &a, &b, &c), cut(a, b + 2, c + 1);
			else
				scanf("%d%d", &a, &b), flip(a, b + 2);
		}
		first = true;
		inOrder(root);
		putchar('\n');
	}
	return 0;
}
/*

Play with Chain

Time Limit: 6000/2000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 4122    Accepted Submission(s): 1686


Problem Description
YaoYao is fond of playing his chains. He has a chain containing n diamonds on it. Diamonds are numbered from 1 to n.
At first, the diamonds on the chain is a sequence: 1, 2, 3, …, n.
He will perform two types of operations:
CUT a b c: He will first cut down the chain from the ath diamond to the bth diamond. And then insert it after the cth diamond on the remaining chain.
For example, if n=8, the chain is: 1 2 3 4 5 6 7 8; We perform “CUT 3 5 4”, Then we first cut down 3 4 5, and the remaining chain would be: 1 2 6 7 8. Then we insert “3 4 5” into the chain before 5th diamond, the chain turns out to be: 1 2 6 7 3 4 5 8.

FLIP a b: We first cut down the chain from the ath diamond to the bth diamond. Then reverse the chain and put them back to the original position.
For example, if we perform “FLIP 2 6” on the chain: 1 2 6 7 3 4 5 8. The chain will turn out to be: 1 4 3 7 6 2 5 8

He wants to know what the chain looks like after perform m operations. Could you help him?


Input
There will be multiple test cases in a test data.
For each test case, the first line contains two numbers: n and m (1≤n, m≤3*100000), indicating the total number of diamonds on the chain and the number of operations respectively.
Then m lines follow, each line contains one operation. The command is like this:
CUT a b c // Means a CUT operation, 1 ≤ a ≤ b ≤ n, 0≤ c ≤ n-(b-a+1).
FLIP a b    // Means a FLIP operation, 1 ≤ a < b ≤ n.
The input ends up with two negative numbers, which should not be processed as a case.

Output
For each test case, you should print a line with n numbers. The ith number is the number of the ith diamond on the chain.

Sample Input
8 2
CUT 3 5 4
FLIP 2 6
-1 -1

Sample Output
1 4 3 7 6 2 5 8

Source
2010 ACM-ICPC Multi-University Training Contest（5）——Host by BJTU

Recommend
zhengfeng   |   We have carefully selected several similar problems for you:  3486 3479 3480 3481 3482 

*/