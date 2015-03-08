/* 12751062	2015-01-20 20:44:39	Accepted	4417	686MS	15256K	2171 B	G++	Shark */
#include<bits\stdc++.h>
using namespace std;
int T[30][100005];
int toLeft[30][100005];
int sorted[100005];
void build(int L, int R, int dep){
	if (L == R)return;
	int mid = (L + R) / 2;
	int same = mid - L + 1;
	for (int i = L; i <= R; i++)
		if (T[dep][i] < sorted[mid])
			same--;
	int posL = L;
	int posR = mid + 1;
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
int solve(int a, int b, int n, int h){
	int res = 0;
	int L = 1;
	int R = b - a + 1;
	while (L <= R){
		int mid = (L + R) / 2;
		int tmp = query(1, n, a, b, 0, mid);
		if (tmp <= h)
			res = mid, L = mid + 1;
		else
			R = mid - 1;
	}
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	for (int p = 1; p <= t;p++){
		printf("Case %d:\n", p);
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &T[0][i]);
		for (int i = 1; i <= n; i++)
			sorted[i] = T[0][i];
		sort(sorted + 1, sorted + n + 1);
		build(1, n, 0);
		for (int i = 0; i < m; i++){
			int a, b, h;
			scanf("%d%d%d", &a, &b, &h);
			printf("%d\n", solve(a + 1, b + 1, n, h));
		}
	}
	return 0;
}
/*

Super Mario

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2805    Accepted Submission(s): 1355


Problem Description
Mario is world-famous plumber. His ¡§burly¡¨ figure and amazing jumping ability reminded in our memory. Now the poor princess is in trouble again and Mario needs to save his lover. We regard the road to the boss¡¦s castle as a line (the length is n), on every integer point i there is a brick on height hi. Now the question is how many bricks in [L, R] Mario can hit if the maximal height he can jump is H.


Input
The first line follows an integer T, the number of test data.
For each test data:
The first line contains two integers n, m (1 <= n <=10^5, 1 <= m <= 10^5), n is the length of the road, m is the number of queries.
Next line contains n integers, the height of each brick, the range is [0, 1000000000].
Next m lines, each line contains three integers L, R,H.( 0 <= L <= R < n 0 <= H <= 1000000000.)


Output
For each case, output "Case X: " (X is the case number starting from 1) followed by m lines, each line contains an integer. The ith integer is the number of bricks Mario can hit for the ith query.


Sample Input
1
10 10
0 5 2 7 5 4 3 8 7 7
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3


Sample Output
Case 1:
4
0
0
3
1
2
0
1
5
1

Source
2012 ACM/ICPC Asia Regional Hangzhou Online

Recommend
liuyiding   |   We have carefully selected several similar problems for you:  5161 5160 5159 5158 5157 

*/