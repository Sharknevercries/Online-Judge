/* 13810492	840502	3468	Accepted	7080K	1797MS	C++	2081B	2015-01-24 15:47:11 */
#include<bits\stdc++.h>
using namespace std;
struct node{
	int L, R;
	long long int sum, fix;
};
node T[500000];
long long int A[100005];
void build(int L, int R, int pos){
	T[pos].L = L, T[pos].R = R;
	T[pos].fix = 0;
	if (L == R)
		T[pos].sum = A[L];
	else{
		int mid = (L + R) / 2;
		build(L, mid, pos * 2);
		build(mid + 1, R, pos * 2 + 1);
		T[pos].sum = T[pos * 2].sum + T[pos * 2 + 1].sum;
	}
}
void pushDown(int pos){
	if (T[pos].fix != 0){
		T[pos].sum += (T[pos].R - T[pos].L + 1LL) * T[pos].fix;
		if (T[pos].L != T[pos].R){
			T[pos * 2].fix += T[pos].fix;
			T[pos * 2 + 1].fix += T[pos].fix;
		}
		T[pos].fix = 0;
	}
}
long long query(int L, int R, int pos){
	pushDown(pos);
	if (L == T[pos].L && R == T[pos].R)
		return T[pos].sum;
	else{
		int mid = (T[pos].L + T[pos].R) / 2;
		if (R <= mid)
			return query(L, R, pos * 2);
		else if (L > mid)
			return query(L, R, pos * 2 + 1);
		else
			return query(L, mid, pos * 2) + query(mid + 1, R, pos * 2 + 1);
	}
}
void update(int L, int R, long long x, int pos){
	pushDown(pos);
	if (L == T[pos].L && R == T[pos].R)
		T[pos].fix = x;
	else{
		int mid = (T[pos].L + T[pos].R) / 2;
		T[pos].sum += (R - L + 1LL)*x;
		if (R <= mid)
			update(L, R, x, pos * 2);
		else if (L > mid)
			update(L, R, x, pos * 2 + 1);
		else{
			update(L, mid, x, pos * 2);
			update(mid + 1, R, x, pos * 2 + 1);
		}
	}	
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", A + i);
	build(1, n, 1);
	for (int i = 0; i < m; i++){
		char com[2];
		int a, b;
		long long c;
		scanf("%s", com);
		if (com[0] == 'Q'){
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(a, b, 1));
		}
		else{
			scanf("%d%d%lld", &a, &b, &c);
			update(a, b, c, 1);
		}
	}
	
	return 0;
}
/*

A Simple Problem with Integers
Time Limit: 5000MS		Memory Limit: 131072K
Total Submissions: 67504		Accepted: 20815
Case Time Limit: 2000MS
Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
Hint

The sums may exceed the range of 32-bit integers.
Source

POJ Monthly--2007.11.25, Yang Yi

*/