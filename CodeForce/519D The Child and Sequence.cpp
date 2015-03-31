/* 10350913	2015-03-19 19:17:02	Shark	D - The Child and Sequence	GNU C++	Accepted	936 ms	6664 KB */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	long long int sum;
	int maxValue, maxFrom;
};
Node T[400005];
int n, m;
int a[100005];
void pushUp(int root){
	T[root].sum = T[root * 2].sum + T[root * 2 + 1].sum;
	if (T[root * 2].maxValue < T[root * 2 + 1].maxValue){
		T[root].maxValue = T[root * 2 + 1].maxValue;
		T[root].maxFrom = T[root * 2 + 1].maxFrom;
	}
	else{
		T[root].maxValue = T[root * 2].maxValue;
		T[root].maxFrom = T[root * 2].maxFrom;
	}
}
void build(int root, int L, int R){
	if (L == R)
		T[root].sum = T[root].maxValue = a[L], T[root].maxFrom = L;
	else{
		int mid = (L + R) / 2;
		build(root * 2, L, mid);
		build(root * 2 + 1, mid + 1, R);
		pushUp(root);
	}
}
long long int query(int root,int TL,int TR, int L, int R){
	if (TL >= L && TR <= R)
		return T[root].sum;
	else{
		int mid = (TL + TR) / 2;
		long long int res = 0;
		if (L <= mid)	res += query(root * 2, TL, mid, L, R);
		if (R > mid)	res += query(root * 2 + 1, mid + 1, TR, L, R);
		return res;
	}
}
pair<int, int> findMax(int root, int TL, int TR, int L, int R, int x){
	if (TL >= L && TR <= R)
		return make_pair(T[root].maxValue, T[root].maxFrom);
	else{
		int mid = (TL + TR) / 2;
		pair<int, int >res = make_pair(-1, 0);
		if (L <= mid)	res = max(res, findMax(root * 2, TL, mid, L, R, x));
		if (R > mid)	res = max(res, findMax(root * 2 + 1, mid + 1, TR, L, R, x));
		return res;
	}
}
void assign(int root, int TL, int TR, int pos, int value){
	if (TL == TR)
		T[root].maxValue = T[root].sum = value;
	else{
		int mid = (TL + TR) / 2;
		if (mid >= pos)
			assign(root * 2, TL, mid, pos, value);
		else
			assign(root * 2 + 1, mid + 1, TR, pos, value);
		pushUp(root);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 0; i < m; i++){
		int op, a, b, c, d;
		scanf("%d%d%d", &op, &a, &b);
		if (op == 1)
			printf("%lld\n", query(1, 1, n, a, b));
		else if (op == 2){
			scanf("%d", &c);
			while (true){
				pair<int, int> res = findMax(1, 1, n, a, b, c);
				if (res.first >= c)
					assign(1, 1, n, res.second, res.first % c);
				else
					break;
			}
		}
		else
			assign(1, 1, n, a, b);
	}
	return 0;
}
/*

D. The Child and Sequence
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
At the children's day, the child came to Picks's house, and messed his house up. Picks was angry at him. A lot of important things were lost, in particular the favorite sequence of Picks.

Fortunately, Picks remembers how to repair the sequence. Initially he should create an integer array a[1], a[2], ..., a[n]. Then he should perform a sequence of m operations. An operation can be one of the following:

Print operation l, r. Picks should write down the value of .
Modulo operation l, r, x. Picks should perform assignment a[i] = a[i] mod x for each i (l ≤ i ≤ r).
Set operation k, x. Picks should set the value of a[k] to x (in other words perform an assignment a[k] = x).
Can you help Picks to perform the whole sequence of operations?

Input
The first line of input contains two integer: n, m (1 ≤ n, m ≤ 105). The second line contains n integers, separated by space: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109) — initial value of array elements.

Each of the next m lines begins with a number type .

If type = 1, there will be two integers more in the line: l, r (1 ≤ l ≤ r ≤ n), which correspond the operation 1.
If type = 2, there will be three integers more in the line: l, r, x (1 ≤ l ≤ r ≤ n; 1 ≤ x ≤ 109), which correspond the operation 2.
If type = 3, there will be two integers more in the line: k, x (1 ≤ k ≤ n; 1 ≤ x ≤ 109), which correspond the operation 3.
Output
For each operation 1, please print a line containing the answer. Notice that the answer may exceed the 32-bit integer.

Sample test(s)
input
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
output
8
5
input
10 10
6 9 6 7 6 1 10 10 9 5
1 3 9
2 7 10 9
2 5 10 8
1 4 7
3 3 7
2 7 9 9
1 2 4
1 6 6
1 5 9
3 1 10
output
49
15
23
1
9
Note
Consider the first testcase:

At first, a = {1, 2, 3, 4, 5}.
After operation 1, a = {1, 2, 3, 0, 1}.
After operation 2, a = {1, 2, 5, 0, 1}.
At operation 3, 2 + 5 + 0 + 1 = 8.
After operation 4, a = {1, 2, 2, 0, 1}.
At operation 5, 1 + 2 + 2 = 5.

*/