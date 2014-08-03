/* *5410251	 Dec 11, 2013 7:30:59 PM	Shark	 305C - Ivan and Powers of Two	 GNU C++	Accepted	 92 ms	 3300 KB */
#include<cstdio>
#include<algorithm>
#include<map>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		std::map<int, int> Q;
		int max = -1;
		for (int i = 0; i < n; i++){
			int exp;
			scanf("%d", &exp);
			Q[exp]++;
			while (Q[exp] >= 2){
				Q[exp] -= 2;
				Q[++exp]++;
			}
			if (exp>max)
				max = exp;
		}
		int ans = max + 1;
		for (std::map<int, int>::iterator it = Q.begin(); it != Q.end(); it++){
			if (it->second == 1)
				ans--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

C. Ivan and Powers of Two
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ivan has got an array of n non-negative integers a1, a2, ..., an. Ivan knows that the array is sorted in the non-decreasing order.

Ivan wrote out integers 2a1, 2a2, ..., 2an on a piece of paper. Now he wonders, what minimum number of integers of form 2b (b ≥ 0) need to be added to the piece of paper so that the sum of all integers written on the paper equalled 2v - 1 for some integer v (v ≥ 0).

Help Ivan, find the required quantity of numbers.

Input
The first line contains integer n (1 ≤ n ≤ 105). The second input line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 2·109). It is guaranteed that a1 ≤ a2 ≤ ... ≤ an.

Output
Print a single integer — the answer to the problem.

Sample test(s)
input
4
0 1 1 1
output
0
input
1
3
output
3
Note
In the first sample you do not need to add anything, the sum of numbers already equals 23 - 1 = 7.

In the second sample you need to add numbers 20, 21, 22.

*/