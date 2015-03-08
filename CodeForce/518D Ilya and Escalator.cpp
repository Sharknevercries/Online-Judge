/* 10014839	2015-02-25 09:30:59	Shark	518D - Ilya and Escalator	GNU C++	Accepted	30 ms	31500 KB */
#include<bits\stdc++.h>
using namespace std;
double DP[2005][2005] = { 0 };
int main(){
	int n, t;
	double p;
	scanf("%d%lf%d", &n, &p, &t);
	DP[1][0] = 1 - p, DP[1][1] = p;
	for (int i = 2; i <= t; i++){
		for (int j = 0; j <= i && j <= n; j++){
			if (j - 1 >= 0)
				DP[i][j] += DP[i - 1][j - 1] * p;
			if (j < n)
				DP[i][j] += DP[i - 1][j] * (1 - p);
			else
				DP[i][j] += DP[i - 1][j];
		}
	}
	double res = 0;
	for (int i = 1; i <= n; i++)
		res += i * DP[t][i];
	printf("%lf\n", res);
	return 0;
}
/*

D. Ilya and Escalator
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ilya got tired of sports programming, left university and got a job in the subway. He was given the task to determine the escalator load factor.

Let's assume that n people stand in the queue for the escalator. At each second one of the two following possibilities takes place: either the first person in the queue enters the escalator with probability p, or the first person in the queue doesn't move with probability (1 - p), paralyzed by his fear of escalators and making the whole queue wait behind him.

Formally speaking, the i-th person in the queue cannot enter the escalator until people with indices from 1 to i - 1 inclusive enter it. In one second only one person can enter the escalator. The escalator is infinite, so if a person enters it, he never leaves it, that is he will be standing on the escalator at any following second. Ilya needs to count the expected value of the number of people standing on the escalator after t seconds.

Your task is to help him solve this complicated task.

Input
The first line of the input contains three numbers n, p, t (1 ≤ n, t ≤ 2000, 0 ≤ p ≤ 1). Numbers n and t are integers, number p is real, given with exactly two digits after the decimal point.

Output
Print a single real number — the expected number of people who will be standing on the escalator after t seconds. The absolute or relative error mustn't exceed 10 - 6.

Sample test(s)
input
1 0.50 1
output
0.5
input
1 0.50 4
output
0.9375
input
4 0.20 2
output
0.4

*/