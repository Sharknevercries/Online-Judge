/* 5452996	 Dec 17, 2013 6:24:45 AM	Shark	 52C - Circular RMQ	 GNU C++	Accepted	780 ms	16700 KB */
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node tree;
struct node{
	int L, R;
	tree *LC, *RC;
	long long int min;
	long long int add;
};
int M[200001];
void pushdown(tree* cur){
	if (cur->add != 0){
		if (cur->LC != NULL)	cur->LC->add += cur->add;
		if (cur->RC != NULL)	cur->RC->add += cur->add;
		cur->add = 0;
	}
}
tree* build(int L, int R){
	tree* cur = (tree*)malloc(sizeof(tree));
	cur->L = L, cur->R = R;
	cur->LC = cur->RC = NULL;
	cur->add = 0;
	if (R > L){
		int mid = (L + R) / 2;
		cur->LC = build(L, mid);
		cur->RC = build(mid + 1, R);
		if (cur->LC->min > cur->RC->min)
			cur->min = cur->RC->min;
		else
			cur->min = cur->LC->min;
	}
	else
		cur->min = M[L];
	return cur;
}
void update(tree* cur, int L, int R, long long int value){
	if (cur->L == L&&cur->R == R)
		cur->add += value;
	else{
		int mid = (cur->L + cur->R) / 2;
		pushdown(cur);
		if (mid >= R)
			update(cur->LC, L, R, value);
		else if (L > mid)
			update(cur->RC, L, R, value);
		else{
			update(cur->LC, L, mid, value);
			update(cur->RC, mid + 1, R, value);
		}
		if (cur->LC->min + cur->LC->add > cur->RC->min + cur->RC->add)
			cur->min = cur->RC->min + cur->RC->add;
		else
			cur->min = cur->LC->min + cur->LC->add;
	}
}
long long int query(tree* cur, int L, int R){
	if (cur->L == L&&cur->R == R)
		return cur->min + cur->add;
	else{
		int mid = (cur->L + cur->R) / 2;
		long long int min = 2e9;
		pushdown(cur);
		if (mid >= R)
			min = query(cur->LC, L, R);
		else if (L > mid)
			min = query(cur->RC, L, R);
		else{
			long long int min1 = query(cur->LC, L, mid);
			long long int min2 = query(cur->RC, mid + 1, R);
			if (min > min1)	min = min1;
			if (min > min2)	min = min2;
		}
		if (cur->LC->min + cur->LC->add > cur->RC->min + cur->RC->add)
			cur->min = cur->RC->min + cur->RC->add;
		else
			cur->min = cur->LC->min + cur->LC->add;
		return min;
	}
}
int main(){
	int n, m;
	while (scanf("%d", &n) == 1){
		for (int i = 1; i <= n; i++)
			scanf("%d", &M[i]);
		tree* root = build(1, n);
		scanf("%d", &m);
		(void)getchar();
		for (int i = 0; i < m; i++){
			char S[1000];
			int T[3];
			bool minus = false;
			gets(S);
			if (sscanf(S, "%d%d%d", &T[0], &T[1], &T[2]) == 3){
				T[0]++, T[1]++;
				if (T[0] <= T[1])
					update(root, T[0], T[1], T[2]);
				else{
					update(root, 1, T[1], T[2]);
					update(root, T[0], n, T[2]);
				}
			}
			else{
				sscanf(S, "%d%d", &T[0], &T[1]);			
				T[0]++, T[1]++;
				long long int ans = 0;
				if (T[0] <= T[1])
					ans = query(root, T[0], T[1]);
				else{
					ans = query(root, 1, T[1]);
					long long int tmp = query(root, T[0], n);
					if (ans > tmp)
						ans = tmp;
				}
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
/*

C. Circular RMQ
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given circular array a0, a1, ..., an - 1. There are two types of operations with it:

inc(lf, rg, v) — this operation increases each element on the segment [lf, rg] (inclusively) by v;
rmq(lf, rg) — this operation returns minimal value on the segment [lf, rg] (inclusively).
Assume segments to be circular, so if n = 5 and lf = 3, rg = 1, it means the index sequence: 3, 4, 0, 1.

Write program to process given sequence of operations.

Input
The first line contains integer n (1 ≤ n ≤ 200000). The next line contains initial state of the array: a0, a1, ..., an - 1 ( - 106 ≤ ai ≤ 106), ai are integer. The third line contains integer m (0 ≤ m ≤ 200000), m — the number of operartons. Next m lines contain one operation each. If line contains two integer lf, rg (0 ≤ lf, rg ≤ n - 1) it means rmq operation, it contains three integers lf, rg, v (0 ≤ lf, rg ≤ n - 1; - 106 ≤ v ≤ 106) — inc operation.

Output
For each rmq operation write result for it. Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cout (also you may use %I64d).

Sample test(s)
input
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1
output
1
0
0

*/