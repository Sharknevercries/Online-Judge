/* 5518281	 Dec 25, 2013 3:03:47 PM	Shark	 376B - I.O.U.	 GNU C++	Accepted	 15 ms	 0 KB */
#include<cstdio>
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int M[101] = { 0 }, ans = 0;
		for (int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			M[a] -= c, M[b] += c;
		}
		for (int i = 1; i <= n; i++){
			if (M[i]>0)
				ans += M[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. I.O.U.
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Imagine that there is a group of three friends: A, B and С. A owes B 20 rubles and B owes C 20 rubles. The total sum of the debts is 40 rubles. You can see that the debts are not organized in a very optimal manner. Let's rearrange them like that: assume that A owes C 20 rubles and B doesn't owe anything to anybody. The debts still mean the same but the total sum of the debts now equals 20 rubles.

This task is a generalisation of a described example. Imagine that your group of friends has n people and you know the debts between the people. Optimize the given debts without changing their meaning. In other words, finally for each friend the difference between the total money he should give and the total money he should take must be the same. Print the minimum sum of all debts in the optimal rearrangement of the debts. See the notes to the test samples to better understand the problem.

Input
The first line contains two integers n and m (1 ≤ n ≤ 100; 0 ≤ m ≤ 104). The next m lines contain the debts. The i-th line contains three integers ai, bi, ci (1 ≤ ai, bi ≤ n; ai ≠ bi; 1 ≤ ci ≤ 100), which mean that person ai owes person bi ci rubles.

Assume that the people are numbered by integers from 1 to n.

It is guaranteed that the same pair of people occurs at most once in the input. The input doesn't simultaneously contain pair of people (x, y) and pair of people (y, x).

Output
Print a single integer — the minimum sum of debts in the optimal rearrangement.

Sample test(s)
input
5 3
1 2 10
2 3 1
2 4 1
output
10
input
3 0
output
0
input
4 3
1 2 1
2 3 1
3 1 1
output
0
Note
In the first sample, you can assume that person number 1 owes 8 rubles to person number 2, 1 ruble to person number 3 and 1 ruble to person number 4. He doesn't owe anybody else anything. In the end, the total debt equals 10.

In the second sample, there are no debts.

In the third sample, you can annul all the debts.

*/