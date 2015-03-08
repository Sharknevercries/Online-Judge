/* 9856298	2015-02-15 10:53:39	Shark	514D - R2D2 and Droid Army	GNU C++	Accepted	389 ms	12900 KB */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	int L, R;
	int hp[5];
};
Node T[400005];
int w[100005][5];
int n, m, k, ptr;
int ans[5];
void build(int L, int R, int pos){
	T[pos].L = L, T[pos].R = R;
	if (L == R){
		for (int i = 0; i < m; i++)
			T[pos].hp[i] = w[L][i];
		return;
	}
	else{
		int mid = (L + R) / 2;
		build(L, mid, pos * 2);
		build(mid + 1, R, pos * 2 + 1);
		for (int i = 0; i < m; i++)
			T[pos].hp[i] = max(T[pos * 2].hp[i], T[pos * 2 + 1].hp[i]);
	}
}
void query(int L, int R, int pos, int res[]){
	if (T[pos].L == L && T[pos].R == R){
		for (int i = 0; i < m; i++)
			res[i] = T[pos].hp[i];
		return;
	}
	else{
		int tmp1[5] = { 0 }, tmp2[5] = { 0 };
		int mid = (T[pos].L + T[pos].R) / 2;
		if (mid >= R)
			query(L, R, pos * 2, tmp1);
		else if (mid < L)
			query(L, R, pos * 2 + 1, tmp2);
		else{
			query(L, mid, pos * 2, tmp1);
			query(mid + 1, R, pos * 2 + 1, tmp2);
		}
		for (int i = 0; i < m;i++)
			res[i] = max(tmp1[i], tmp2[i]);
	}
}
bool solve(int interval){
	if (interval == 0)	return true;
	for (int i = 1; i + interval - 1 <= n; i++){
		int tmp[5] = { 0 };
		query(i, i + interval - 1, 1, tmp);
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum += tmp[j];
		if (sum <= k){
			for (int j = 0; j < m; j++)
				ans[j] = tmp[j];
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &w[i][j]);
	ptr == 1;
	build(1, n, 1);
	int L = 0, R = n;
	while (L <= R){
		int mid = (L + R) / 2;
		if (solve(mid))
			L = mid + 1;
		else
			R = mid - 1;
	}
	printf("%d", ans[0]);
	for (int i = 1; i < m; i++)
		printf(" %d", ans[i]);
	putchar('\n');
	return 0;
}
/*

D. R2D2 and Droid Army
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
An army of n droids is lined up in one row. Each droid is described by m integers a1, a2, ..., am, where ai is the number of details of the i-th type in this droid's mechanism. R2-D2 wants to destroy the sequence of consecutive droids of maximum length. He has m weapons, the i-th weapon can affect all the droids in the army by destroying one detail of the i-th type (if the droid doesn't have details of this type, nothing happens to it).

A droid is considered to be destroyed when all of its details are destroyed. R2-D2 can make at most k shots. How many shots from the weapon of what type should R2-D2 make to destroy the sequence of consecutive droids of maximum length?

Input
The first line contains three integers n, m, k (1 ≤ n ≤ 105, 1 ≤ m ≤ 5, 0 ≤ k ≤ 109) — the number of droids, the number of detail types and the number of available shots, respectively.

Next n lines follow describing the droids. Each line contains m integers a1, a2, ..., am (0 ≤ ai ≤ 108), where ai is the number of details of the i-th type for the respective robot.

Output
Print m space-separated integers, where the i-th number is the number of shots from the weapon of the i-th type that the robot should make to destroy the subsequence of consecutive droids of the maximum length.

If there are multiple optimal solutions, print any of them.

It is not necessary to make exactly k shots, the number of shots can be less.

Sample test(s)
input
5 2 4
4 0
1 2
2 1
0 2
1 3
output
2 2
input
3 2 4
1 2
1 3
2 2
output
1 3
Note
In the first test the second, third and fourth droids will be destroyed.

In the second test the first and second droids will be destroyed.

*/