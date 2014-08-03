/* 7021728	 2014-07-06 17:08:46	Shark	 445A - DZY Loves Chessboard	 GNU C++	Accepted	 30 ms	 0 KB */
#include<cstdio>
#include<string.h>
bool con[51][51] = { false };
bool V[51];
int n, m;
int DFS(int s){
	V[s] = true;
	int cnt = 1;
	for (int i = 1; i <= n; i++){
		if (!V[i] && con[s][i]){
			cnt += DFS(i);
		}
	}
	return cnt;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		memset(con, false, sizeof(con));
		memset(V, false, sizeof(V));
		long long int ans = 1;
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			con[a][b] = con[b][a] = true;
		}
		for (int i = 1; i <= n; i++){
			if (!V[i]){
				int cnt = DFS(i);
				cnt--;
				ans *= (long long int)(1LL << cnt);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

B. DZY Loves Chemistry
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
DZY loves chemistry, and he enjoys mixing chemicals.

DZY has n chemicals, and m pairs of them will react. He wants to pour these chemicals into a test tube, and he needs to pour them in one by one, in any order.

Let's consider the danger of a test tube. Danger of an empty test tube is 1. And every time when DZY pours a chemical, if there are already one or more chemicals in the test tube that can react with it, the danger of the test tube will be multiplied by 2. Otherwise the danger remains as it is.

Find the maximum possible danger after pouring all the chemicals one by one in optimal order.

Input
The first line contains two space-separated integers n and m .

Each of the next m lines contains two space-separated integers xi and yi (1 ≤ xi < yi ≤ n). These integers mean that the chemical xi will react with the chemical yi. Each pair of chemicals will appear at most once in the input.

Consider all the chemicals numbered from 1 to n in some order.

Output
Print a single integer — the maximum possible danger.

Sample test(s)
input
1 0
output
1
input
2 1
1 2
output
2
input
3 2
1 2
2 3
output
4
Note
In the first sample, there's only one way to pour, and the danger won't increase.

In the second sample, no matter we pour the 1st chemical first, or pour the 2nd chemical first, the answer is always 2.

In the third sample, there are four ways to achieve the maximum possible danger: 2-1-3, 2-3-1, 1-2-3 and 3-2-1 (that is the numbers of the chemicals in order of pouring).

*/