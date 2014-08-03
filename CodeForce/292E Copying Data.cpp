/* 5414543	 Dec 12, 2013 4:13:59 PM	Shark	 292E - Copying Data	 GNU C++	Accepted	 312 ms	 7200 KB */
#include<cstdio>
#include<stdlib.h>
typedef struct node tree;
struct node{
	int L, R;
	tree *LC;
	tree *RC;
	int sa, sb; // stamp
};
int n, m;
int A[100001];
int B[100001];
tree* root;
void pushdown(tree* cur){
	if (cur->sa != 0){
		if (cur->LC != NULL)
			cur->LC->sa = cur->sa, cur->LC->sb = cur->sb;
		if ( cur->RC!=NULL)
			cur->RC->sa = cur->sa, cur->RC->sb = cur->sb;
		cur->sa = cur->sb = 0;
	}
}
tree* make_tree(int L, int R){
	tree* cur = (tree*)malloc(sizeof(tree));
	cur->L = L, cur->R = R;
	cur->LC = cur->RC = NULL;
	cur->sa = cur->sb = 0;
	if (L != R){
		int M = (L + R) / 2;
		cur->LC = make_tree(L, M);
		cur->RC = make_tree(M + 1, R);
	}
	return cur;
}
void change(tree* cur, int L, int R, int sa, int sb){
	if (cur->L == L&&cur->R == R){
		cur->sa = sa, cur->sb = sb;
		return;
	}
	else{
		pushdown(cur);
		int M = (cur->L + cur->R) / 2;
		if (M < L)
			change(cur->RC, L, R, sa, sb);
		else if (M >= R)
			change(cur->LC, L, R, sa, sb);
		else{
			change(cur->LC, L, M, sa, sb);
			change(cur->RC, M + 1, R, sa, sb);
		}
	}
}
int query(tree* cur, int num){
	if (cur->L == cur->R){
		if (cur->sa != 0)
			return A[num - cur->sb + cur->sa];
		else
			return B[num];
	}
	else{
		pushdown(cur);
		int M = (cur->L + cur->R) / 2;
		if (M >= num)
			return query(cur->LC, num);
		else
			return query(cur->RC, num);
	}
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &B[i]);
		root = make_tree(1, n);
		for (int i = 0; i < m; i++){
			int com;
			scanf("%d", &com);
			if (com == 1){
				int x, y, k;
				scanf("%d%d%d", &x, &y, &k);
				change(root, y, y + k - 1, x, y);
			}
			else{
				int num;
				scanf("%d", &num);
				printf("%d\n", query(root, num));
			}
		}
	}
	return 0;
}
/*

E. Copying Data
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We often have to copy large volumes of information. Such operation can take up many computer resources. Therefore, in this problem you are advised to come up with a way to copy some part of a number array into another one, quickly.

More formally, you've got two arrays of integers a1, a2, ..., an and b1, b2, ..., bn of length n. Also, you've got m queries of two types:

Copy the subsegment of array a of length k, starting from position x, into array b, starting from position y, that is, execute by + q = ax + q for all integer q (0 ≤ q < k). The given operation is correct — both subsegments do not touch unexistent elements.
Determine the value in position x of array b, that is, find value bx.
For each query of the second type print the result — the value of the corresponding element of array b.

Input
The first line contains two space-separated integers n and m (1 ≤ n, m ≤ 105) — the number of elements in the arrays and the number of queries, correspondingly. The second line contains an array of integers a1, a2, ..., an (|ai| ≤ 109). The third line contains an array of integers b1, b2, ..., bn (|bi| ≤ 109).

Next m lines contain the descriptions of the queries. The i-th line first contains integer ti — the type of the i-th query (1 ≤ ti ≤ 2). If ti = 1, then the i-th query means the copying operation. If ti = 2, then the i-th query means taking the value in array b. If ti = 1, then the query type is followed by three integers xi, yi, ki (1 ≤ xi, yi, ki ≤ n) — the parameters of the copying query. If ti = 2, then the query type is followed by integer xi (1 ≤ xi ≤ n) — the position in array b.

All numbers in the lines are separated with single spaces. It is guaranteed that all the queries are correct, that is, the copying borders fit into the borders of arrays a and b.

Output
For each second type query print the result on a single line.

Sample test(s)
input
5 10
1 2 0 -1 3
3 1 5 -2 0
2 5
1 3 3 3
2 5
2 4
2 1
1 2 1 4
2 1
2 4
1 4 2 1
2 2
output
0
3
-1
3
2
3
-1

*/