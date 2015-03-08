/* 858489	840502	1588	Accepted	1820 kb	144 ms	C++/Edit	2925 B	2015-02-05 19:35:13 */
#include<bits\stdc++.h>
using namespace std;
struct node{
	int data;
	int parent;
	int L, R;
	node(){}
	node(int data, int parent, int L, int R) :data(data), parent(parent), L(L), R(R){}
};
node T[35000];
int root, size;
int n, k, ans;
void leftRotate(int x){
	int y;
	y = T[x].parent;
	T[y].R = T[x].L;
	if (T[x].L != 0)
		T[T[x].L].parent = y;
	T[x].parent = T[y].parent;
	T[x].L = y;
	if (T[y].parent != 0)
		if (y == T[T[y].parent].L)
			T[T[y].parent].L = x;
		else
			T[T[y].parent].R = x;
	T[y].parent = x;
}
void rightRotate(int x){
	int y;
	y = T[x].parent;
	T[y].L = T[x].R;
	if (T[x].R != 0)
		T[T[x].R].parent = y;
	T[x].parent = T[y].parent;
	T[x].R = y;
	if (T[y].parent != 0)
		if (y == T[T[y].parent].L)
			T[T[y].parent].L = x;
		else
			T[T[y].parent].R = x;
	T[y].parent = x;
}
void splay(int x){
	int y;
	while (T[x].parent != 0){
		y = T[x].parent;
		if (T[y].parent == 0){
			if (x == T[y].L)
				rightRotate(x);
			else
				leftRotate(x);
			break;
		}
		if (x == T[y].L){
			if (y == T[T[y].parent].L){
				rightRotate(y);
				rightRotate(x);
			}
			else{
				rightRotate(x);
				leftRotate(x);
			}
		}
		else{
			if (y == T[T[y].parent].R){
				leftRotate(y);
				leftRotate(x);
			}
			else{
				leftRotate(x);
				rightRotate(x);
			}
		}
	}
	root = x;
}
void insert(int x){
	int cur, parent;
	T[++size] = node(x, 0, 0, 0);
	if (root == 0)
		root = size;
	else{
		cur = root;
		do{
			parent = cur;
			if (x <= T[cur].data)
				cur = T[cur].L;
			else
				cur = T[cur].R;
		} while (cur != 0);
		T[size].parent = parent;
		if (x <= T[parent].data)
			T[parent].L = size;
		else
			T[parent].R = size;
		splay(size);
	}
}
int query(){
	int cur, res = 0x7FFFFFFF;
	cur = T[root].L;
	while (cur != 0){
		if (T[cur].R == 0)
			break;
		cur = T[cur].R;
	}
	if (cur != 0)
		res = T[root].data - T[cur].data;
	cur = T[root].R;
	while (cur != 0){
		if (T[cur].L == 0)
			break;
		cur = T[cur].L;
	}
	if ((cur != 0))
		res = min(res, T[cur].data - T[root].data);
	return res;
}
int main(){
	scanf("%d", &n);
	memset(T, 0, sizeof(T));
	size = ans = 0;
	for (int i = 0; i < n; i++){
		k = 0;
		scanf("%d", &k);
		insert(k);
		if (size >= 2)
			ans += query();
		else
			ans += k;
	}
	printf("%d\n", ans);
	return 0;
}
/*

Description

营业额统计 Tiger最近被公司升任为营业部经理，他上任后接受公司交给的第一项任务便是统计并分析公司成立以来的营业情况。 Tiger拿出了公司的账本，账本上记录了公司成立以来每天的营业额。分析营业情况是一项相当复杂的工作。由于节假日，大减价或者是其他情况的时候，营业额会出现一定的波动，当然一定的波动是能够接受的，但是在某些时候营业额突变得很高或是很低，这就证明公司此时的经营状况出现了问题。经济管理学上定义了一种最小波动值来衡量这种情况： 该天的最小波动值 当最小波动值越大时，就说明营业情况越不稳定。 而分析整个公司的从成立到现在营业情况是否稳定，只需要把每一天的最小波动值加起来就可以了。你的任务就是编写一个程序帮助Tiger来计算这一个值。 第一天的最小波动值为第一天的营业额。 	输入输出要求

Input

第一行为正整数 ，表示该公司从成立一直到现在的天数，接下来的n行每行有一个整数(有可能有负数) ，表示第i天公司的营业额。

Output

输出文件仅有一个正整数，即Sigma(每天最小的波动值) 。结果小于2^31 。

Sample Input

6

5

1

2

5

4

6	
Sample Output

12

HINT

结果说明：5+|1-5|+|2-1|+|5-5|+|4-5|+|6-5|=5+4+1+0+1+1=12


此题数据有问题，详见讨论版http://www.lydsy.com/JudgeOnline/wttl/wttl.php?pid=1588

Source

*/