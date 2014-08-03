/* 5244946	 00:06:23	Shark	 A - Sereja and Coat Rack	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n, d, m;
	while (scanf("%d%d", &n, &d) == 2){
		int M[100], k, profit;
		for (int i = 0; i < n; i++)
			scanf("%d", &M[i]);
		scanf("%d", &m);
		std::sort(M, M + n);
		for (profit = k = 0; k < m && k < n; k++)
			profit += M[k];
		if (k >= n)
			profit -= d*(m - n);
		printf("%d\n", profit);
	}
	return 0;

}
/*

A. Sereja and Coat Rack
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sereja owns a restaurant for n people. The restaurant hall has a coat rack with n hooks. Each restaurant visitor can use a hook to hang his clothes on it. Using the i-th hook costs ai rubles. Only one person can hang clothes on one hook.

Tonight Sereja expects m guests in the restaurant. Naturally, each guest wants to hang his clothes on an available hook with minimum price (if there are multiple such hooks, he chooses any of them). However if the moment a guest arrives the rack has no available hooks, Sereja must pay a d ruble fine to the guest.

Help Sereja find out the profit in rubles (possibly negative) that he will get tonight. You can assume that before the guests arrive, all hooks on the rack are available, all guests come at different time, nobody besides the m guests is visiting Sereja's restaurant tonight.

Input
The first line contains two integers n and d (1 ≤ n, d ≤ 100). The next line contains integers a1, a2, ..., an (1 ≤ ai ≤ 100). The third line contains integer m (1 ≤ m ≤ 100).

Output
In a single line print a single integer — the answer to the problem.

Sample test(s)
input
2 1
2 1
2
output
3
input
2 1
2 1
10
output
-5
Note
In the first test both hooks will be used, so Sereja gets 1 + 2 = 3 rubles.

In the second test both hooks will be used but Sereja pays a fine 8 times, so the answer is 3 - 8 =  - 5.

*/