/* 12780471	2015-01-23 19:59:23	Accepted	3308	436MS	6696K	2498 B	G++	Shark */
#include<bits\stdc++.h>
#define N 100005
using namespace std;
struct node{
	int L, R;
	int Lsum, Msum, Rsum;
};
node T[4 * N];
int S[N];
int n, m;
void pushUp(int pos){
	T[pos].Msum = max(T[pos * 2].Msum, T[pos * 2 + 1].Msum);
	T[pos].Lsum = T[pos * 2].Lsum;
	T[pos].Rsum = T[pos * 2 + 1].Rsum;
	if (S[T[pos * 2].R] < S[T[pos * 2 + 1].L]){
		T[pos].Msum = max(T[pos].Msum, T[pos * 2].Rsum + T[pos * 2 + 1].Lsum);
		if (T[pos * 2].Lsum == T[pos * 2].R - T[pos * 2].L + 1)
			T[pos].Lsum += T[pos * 2 + 1].Lsum;
		if (T[pos * 2 + 1].Rsum == T[pos * 2 + 1].R - T[pos * 2 + 1].L + 1)
			T[pos].Rsum += T[pos * 2].Rsum;
	}
}
void build(int L, int R, int pos){
	T[pos].L = L, T[pos].R = R;
	if (L == R)
		T[pos].Lsum = T[pos].Msum = T[pos].Rsum = 1;
	else{
		int mid = (L + R) / 2;
		build(L, mid, pos * 2);
		build(mid + 1, R, pos * 2 + 1);
		pushUp(pos);
	}
}
void update(int a, int b, int pos){
	if (T[pos].L == T[pos].R)
		S[a] = b;
	else{
		int mid = (T[pos].L + T[pos].R) / 2;
		if (a <= mid)
			update(a, b, pos * 2);
		else
			update(a, b, pos * 2 + 1);
		pushUp(pos);
	}
}
int queryL(int L, int R, int pos){
	if (R - L + 1 >= T[pos].Lsum)
		return T[pos].Lsum;
	else
		return R - L + 1;
}
int queryR(int L, int R, int pos){
	if (R - L + 1 >= T[pos].Rsum)
		return T[pos].Rsum;
	else
		return R - L + 1;
}
int query(int L, int R, int pos){
	if (L == T[pos].L && R == T[pos].R)
		return T[pos].Msum;
	int mid = (T[pos].L + T[pos].R) / 2;
	if (R <= mid)
		return query(L, R, pos * 2);
	else if (L > mid)
		return query(L, R, pos * 2 + 1);
	else{
		int res = 0;
		if (S[T[pos * 2].R] < S[T[pos * 2 + 1].L])
			res = max(res, queryL(mid + 1, R, pos * 2 + 1) + queryR(L, mid, pos * 2));
		res = max(res, query(L, mid, pos * 2));
		res = max(res, query(mid + 1, R, pos * 2 + 1));
		return res;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		build(1, n, 1);
		for (int i = 0; i < m; i++){
			char com[2];
			int a, b;
			scanf("%s%d%d", com, &a, &b);
			if (com[0] == 'Q')
				printf("%d\n", query(a + 1, b + 1, 1));
			else
				update(a + 1, b, 1);
		}
	}
	return 0;
}
/*

LCIS

Time Limit: 6000/2000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 4486    Accepted Submission(s): 2026


Problem Description
Given n integers.
You have two operations:
U A B: replace the Ath number by B. (index counting from 0)
Q A B: output the length of the longest consecutive increasing subsequence (LCIS) in [a, b].


Input
T in the first line, indicating the case number.
Each case starts with two integers n , m(0<n,m<=105).
The next line has n integers(0<=val<=105).
The next m lines each has an operation:
U A B(0<=A,n , 0<=B=105)
OR
Q A B(0<=A<=B< n).


Output
For each Q, output the answer.


Sample Input
1
10 10
7 7 3 3 5 9 9 8 1 8
Q 6 6
U 3 4
Q 0 1
Q 0 5
Q 4 7
Q 3 5
Q 0 2
Q 4 6
U 6 10
Q 0 9


Sample Output
1
1
4
2
3
1
2
5


Author
shǎ崽


Source
HDOJ Monthly Contest – 2010.02.06


Recommend
wxl   |   We have carefully selected several similar problems for you:  2795 1698 3397 1542 1828 

*/