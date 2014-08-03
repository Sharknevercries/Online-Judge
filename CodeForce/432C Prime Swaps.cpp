/* 6627057	 May 15, 2014 8:23:39 PM	Shark	 C - Prime Swaps	 GNU C++	Accepted	 264 ms	 5000 KB */
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int M[100001];
int S[100001];
int P[100001];
int prime[50000], ptr;
vector<pair<int, int> >ans;
void make_prime(){
	ptr = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (int i = 5, gap = 2, j = 0; i <= 100000; i += gap, gap = 6 - gap){
		for (j = 0; j < ptr; j++)
			if (i % prime[j] == 0)
				break;
		if (j >= ptr)
			prime[ptr++] = i;
	}
}
int find(int x){
	int L, R;
	L = 0, R = ptr - 1;
	while (L <= R){
		int m = (L + R) / 2;
		if (prime[m] == x)
			return prime[m];
		else if (prime[m] > x)
			R = m - 1;
		else
			L = m + 1;
	}
	return prime[L - 1];
}
int main(){
	make_prime();

	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 1; i <= n; i++){
			scanf("%d", M + i);
			P[M[i]] = i;
			S[i] = M[i];
		}
		ans.clear();
		sort(M + 1, M + n + 1);
		for (int i = 1; i <= n; i++){
			if (i == P[M[i]])
				continue;
			int delta = P[M[i]] - i + 1;
			int curP = P[M[i]];
			while (S[i] != M[i]){
				int target = find(delta);
				ans.push_back(make_pair(curP - target + 1, curP));
				swap(S[curP], S[curP - target + 1]);
				swap(P[S[curP]], P[S[curP - target + 1]]);
				curP -= (target - 1);
				delta -= (target - 1);
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
/*

C. Prime Swaps
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have an array a[1], a[2], ..., a[n], containing distinct integers from 1 to n. Your task is to sort this array in increasing order with the following operation (you may need to apply it multiple times):

choose two indexes, i and j (1 ≤ i < j ≤ n; (j - i + 1) is a prime number);
swap the elements on positions i and j; in other words, you are allowed to apply the following sequence of assignments: tmp = a[i], a[i] = a[j], a[j] = tmp (tmp is a temporary variable).
You do not need to minimize the number of used operations. However, you need to make sure that there are at most 5n operations.

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains n distinct integers a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ n).

Output
In the first line, print integer k (0 ≤ k ≤ 5n) — the number of used operations. Next, print the operations. Each operation must be printed as "i j" (1 ≤ i < j ≤ n; (j - i + 1) is a prime).

If there are multiple answers, you can print any of them.

Sample test(s)
input
3
3 2 1
output
1
1 3
input
2
1 2
output
0
input
4
4 2 3 1
output
3
2 4
1 2
2 4

*/