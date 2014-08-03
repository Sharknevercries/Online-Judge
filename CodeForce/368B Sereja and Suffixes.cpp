/* 5246538	 00:14:54	Shark	 B - Sereja and Suffixes	 GNU C++	Accepted	 78 ms	 4088 KB */
#include<stdio.h>
#include<map>
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int S[100000];
		int ans[100001] = { 0 };
		std::map<int, int> T;
		for (int i = 0; i < n; i++)
			scanf("%d", &S[i]);
		T.clear();
		for (int i = n - 1; i >= 0; i--){
			if (T[S[i]] == 0){
				ans[i] = ans[i + 1] + 1;
				T[S[i]] = 1;
			}
			else
				ans[i] = ans[i + 1];
		}
		for (int i = 0; i < m; i++){
			int tmp;
			scanf("%d", &tmp);
			printf("%d\n", ans[tmp - 1]);
		}
	}
	return 0;
}
/*

B. Sereja and Suffixes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sereja has an array a, consisting of n integers a1, a2, ..., an. The boy cannot sit and do nothing, he decided to study an array. Sereja took a piece of paper and wrote out m integers l1, l2, ..., lm (1 ≤ li ≤ n). For each number li he wants to know how many distinct numbers are staying on the positions li, li + 1, ..., n. Formally, he want to find the number of distinct numbers among ali, ali + 1, ..., an.?

Sereja wrote out the necessary array elements but the array was so large and the boy was so pressed for time. Help him, find the answer for the described question for each li.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 105). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 105) — the array elements.

Next m lines contain integers l1, l2, ..., lm. The i-th line contains integer li (1 ≤ li ≤ n).

Output
Print m lines — on the i-th line print the answer to the number li.

Sample test(s)
input
10 10
1 2 3 4 1 2 3 4 100000 99999
1
2
3
4
5
6
7
8
9
10
output
6
6
6
6
6
5
4
3
2
1

*/