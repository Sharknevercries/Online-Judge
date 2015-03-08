/* 12802123	2015-01-25 19:10:54	Accepted	3436	421MS	15280K	3925 B	G++	Shark */
#include<bits\stdc++.h>
using namespace std;
struct command{
	char com[10];
	int x;
};
struct segment{
	int L, R;
};
struct node{
	segment interval;
	int child[2], parent;
	int size, num;
	node(){}
	node(segment interval, int parent) :interval(interval), parent(parent){
		num = size = interval.R - interval.L + 1;
		child[0] = child[1] = 0;
	}
};
command C[400005];
segment seg[400005];
node T[400005];
int pos[400005]; // segment pos
int cnt;
int S[200005], ptr;
int t, n, m;
int root, total;
void pushUp(int x){
	T[x].size = T[T[x].child[0]].size + T[T[x].child[1]].size + T[x].num;
}
void build(int L, int R, int parent, int &r){
	if (L > R)	return;
	int mid = (L + R) / 2;
	r = ++total;
	T[r] = node(seg[mid], parent);
	pos[mid] = r;
	build(L, mid - 1, r, T[r].child[0]);
	build(mid + 1, R, r, T[r].child[1]);
	pushUp(r);
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
	pushUp(x);
	while (T[x].child[0])
		x = T[x].child[0], pushUp(x);
	return x;
}
void remove(int x){
	splay(x, 0);
	if (!T[root].child[0] || !T[root].child[1])
		root = T[root].child[0] + T[root].child[1], T[root].parent = 0;
	else{
		int k = getMin(T[root].child[1]);
		splay(k, root);
		T[T[root].child[1]].child[0] = T[root].child[0];
		root = T[root].child[1];
		T[T[root].child[0]].parent = root;
		T[root].parent = 0;
		pushUp(root);
	}
}
int findSeg(int x){
	int L = 1, R = cnt;
	while (L <= R){
		int mid = (L + R) / 2;
		if (seg[mid].L <= x && seg[mid].R >= x)
			return mid;
		else if (seg[mid].R < x)
			L = mid + 1;
		else
			R = mid - 1;
	}
	return 0;
}
int getPos(int x){
	int k = findSeg(x);
	int y = pos[k];
	splay(y, 0);
	return T[T[root].child[0]].size + 1;
}
int getRank(int r, int x){
	int tmp = T[T[r].child[0]].size;
	if (x <= tmp)
		return getRank(T[r].child[0], x);
	else if (x <= tmp + T[r].num)
		return T[r].interval.L + (x - tmp) - 1;
	else
		return getRank(T[r].child[1], x - tmp - T[r].num);
}
void top(int x){
	int k = findSeg(x);
	int y = pos[k];
	remove(y);
	splay(getMin(root), 0);
	T[y].child[0] = 0;
	T[y].child[1] = root;
	T[y].parent = 0;
	T[root].parent = y;
	root = y;
	pushUp(root);
}
int main(){
	int c = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		memset(T, 0, sizeof(T));
		ptr = 0;
		for (int i = 0; i < m; i++){
			scanf("%s%d", C[i].com, &C[i].x);
			if (C[i].com[0] == 'T' || C[i].com[0] == 'Q')
				S[ptr++] = C[i].x;
		}
		S[ptr++] = 0;
		S[ptr++] = n;
		sort(S, S + ptr);
		cnt = 0;
		for (int i = 1; i < ptr; i++){
			if (S[i] != S[i - 1]){
				if (S[i] - S[i - 1] > 1)
					seg[cnt].L = S[i - 1] + 1, seg[cnt++].R = S[i] - 1;
				seg[cnt].L = S[i], seg[cnt++].R = S[i];
			}
		}
		root = total = 0;
		build(0, cnt - 1, 0, root);
		printf("Case %d:\n", ++c);
		for (int i = 0; i < m; i++){
			if (C[i].com[0] == 'T')
				top(C[i].x);
			else if (C[i].com[0] == 'Q')
				printf("%d\n", getPos(C[i].x));
			else
				printf("%d\n", getRank(root, C[i].x));
		}
	}
	return 0;
}
/*

Queue-jumpers

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2459    Accepted Submission(s): 636


Problem Description
Ponyo and Garfield are waiting outside the box-office for their favorite movie. Because queuing is so boring, that they want to play a game to kill the time. The game is called ¡§Queue-jumpers¡¨. Suppose that there are N people numbered from 1 to N stand in a line initially. Each time you should simulate one of the following operations:
1.  Top x :Take person x to the front of the queue
2.  Query x: calculate the current position of person x
3.  Rank x: calculate the current person at position x
Where x is in [1, N].
Ponyo is so clever that she plays the game very well while Garfield has no idea. Garfield is now turning to you for help.


Input
In the first line there is an integer T, indicates the number of test cases.(T<=50)
In each case, the first line contains two integers N(1<=N<=10^8), Q(1<=Q<=10^5). Then there are Q lines, each line contain an operation as said above.


Output
For each test case, output ¡§Case d:¡§ at first line where d is the case number counted from one, then for each ¡§Query x¡¨ operation ,output the current position of person x at a line, for each ¡§Rank x¡¨ operation, output the current person at position x at a line.


Sample Input
3
9 5
Top 1
Rank 3
Top 7
Rank 6
Rank 8
6 2
Top 4
Top 5
7 4
Top 5
Top 2
Query 1
Rank 6


Sample Output
Case 1:
3
5
8
Case 2:
Case 3:
3
6


Author
wzc1989


Source
2010 ACM-ICPC Multi-University Training Contest¡]1¡^¡X¡XHost by FZU


Recommend
zhouzeyong   |   We have carefully selected several similar problems for you:  3433 3434 3435 3437 3438 

*/