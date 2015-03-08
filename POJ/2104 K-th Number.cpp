/* 13797873	840502	2104	Accepted	14284K	1110MS	C++	1782B	2015-01-20 19:31:38 */
#include<bits\stdc++.h>
using namespace std;
int S[100005];
int sorted[100005];
int T[30][100005];
int toLeft[30][100005];
void build(int L, int R, int dep){
	if (L == R)	return;
	int mid = (L + R) / 2;
	int same = mid - L + 1;
	for (int i = L; i <= R; i++)
		if (T[dep][i] < sorted[mid])
			same--;
	int posL = L, posR = mid + 1;
	for (int i = L; i <= R; i++){
		if (T[dep][i] < sorted[mid])
			T[dep + 1][posL++] = T[dep][i];
		else if (T[dep][i] == sorted[mid] && same > 0)
			T[dep + 1][posL++] = T[dep][i], same--;
		else
			T[dep + 1][posR++] = T[dep][i];
		toLeft[dep][i] = toLeft[dep][L - 1] + posL - L;
	}
	build(L, mid, dep + 1);
	build(mid + 1, R, dep + 1);
}
int query(int L, int R, int l, int r, int dep, int k){
	if (l == r)return T[dep][l];
	int mid = (L + R) / 2;
	int count = toLeft[dep][r] - toLeft[dep][l - 1];
	if (count >= k){
		int nextL = L + toLeft[dep][l - 1] - toLeft[dep][L - 1];
		int nextR = nextL + count - 1;
		return query(L, mid, nextL, nextR, dep + 1, k);
	}
	else{
		int nextR = r + toLeft[dep][R] - toLeft[dep][r];
		int nextL = nextR - (r - l - count);
		return query(mid + 1, R, nextL, nextR, dep + 1, k - count);
	}
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &T[0][i]);
	for (int i = 1; i <= n; i++)
		sorted[i] = T[0][i];
	sort(sorted + 1, sorted + n + 1);
	build(1, n, 0);
	for (int i = 0; i < m; i++){
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		printf("%d\n", query(1, n, a, b, 0, k));
	}
	return 0;
}
/*

K-th Number
Time Limit: 20000MS		Memory Limit: 65536K
Total Submissions: 39294		Accepted: 12798
Case Time Limit: 2000MS
Description

You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?"
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
Input

The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000).
The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given.
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k).
Output

For each question output the answer to it --- the k-th number in sorted a[i...j] segment.
Sample Input

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output

5
6
3
Hint

This problem has huge input,so please use c-style input(scanf,printf),or you may got time limit exceed.
Source

Northeastern Europe 2004, Northern Subregion

*/