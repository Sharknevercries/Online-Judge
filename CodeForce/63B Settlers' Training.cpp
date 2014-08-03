/* 5708750	 Jan 17, 2014 12:59:16 PM	Shark	 63B - Settlers' Training	 GNU C++	Accepted	30 ms	0 KB */
#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int T[100], min = 2e9;
		priority_queue<int> Q;
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			if (min > tmp)
				min = tmp;
			Q.push(tmp);
		}
		int ans = 0;
		while (min < k){
			int prev = -1;
			min = 2e9;
			for (int i = 0; i < n; i++){
				int cur = Q.top();
				Q.pop();
				if (cur == prev)
					T[i] = cur;
				else
					prev = cur, T[i] = cur + 1;
			}
			ans++;
			for (int i = 0; i < n; i++){
				if (min>T[i])
					min = T[i];
				Q.push(T[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. Settlers' Training
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In a strategic computer game "Settlers II" one has to build defense structures to expand and protect the territory. Let's take one of these buildings. At the moment the defense structure accommodates exactly n soldiers. Within this task we can assume that the number of soldiers in the defense structure won't either increase or decrease.

Every soldier has a rank — some natural number from 1 to k. 1 stands for a private and k stands for a general. The higher the rank of the soldier is, the better he fights. Therefore, the player profits from having the soldiers of the highest possible rank.

To increase the ranks of soldiers they need to train. But the soldiers won't train for free, and each training session requires one golden coin. On each training session all the n soldiers are present.

At the end of each training session the soldiers' ranks increase as follows. First all the soldiers are divided into groups with the same rank, so that the least possible number of groups is formed. Then, within each of the groups where the soldiers below the rank k are present, exactly one soldier increases his rank by one.

You know the ranks of all n soldiers at the moment. Determine the number of golden coins that are needed to increase the ranks of all the soldiers to the rank k.

Input
The first line contains two integers n and k (1 ≤ n, k ≤ 100). They represent the number of soldiers and the number of different ranks correspondingly. The second line contains n numbers in the non-decreasing order. The i-th of them, ai, represents the rank of the i-th soldier in the defense building (1 ≤ i ≤ n, 1 ≤ ai ≤ k).

Output
Print a single integer — the number of golden coins needed to raise all the soldiers to the maximal rank.

Sample test(s)
input
4 4
1 2 2 3
output
4
input
4 3
1 1 1 1
output
5
Note
In the first example the ranks will be raised in the following manner:

1 2 2 3  →  2 2 3 4  →  2 3 4 4  →  3 4 4 4  →  4 4 4 4

Thus totals to 4 training sessions that require 4 golden coins.

*/