/* 5830843	 Jan 29, 2014 12:59:15 PM	Shark	 385C - Bear and Prime Numbers	 GNU C++	Accepted	546 ms	88000 KB */
#include<cstdio>
#include<cmath>
#define MAX 10000000
bool prime[MAX+1] = { false };
int count[MAX+1] = { 0 };
int F[MAX + 1] = { 0 };
void makePrime(){
	int limit = sqrt((double)MAX);
	for (int i = 0; i <= MAX; i++)
		prime[i] = true;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= limit; i++){
		if (prime[i]){
			for (int k = MAX / i, j = i*k; k >= i; k--, j -= i){
				if (prime[k])
					prime[j] = false;
			}
		}
	}
}
void compute(){
	for (int i = 2; i <= MAX; i++){
		if (prime[i]){
			for (int j = i; j <= MAX; j += i)
				F[i] += count[j];
		}
	}
	for (int i = 1; i <= MAX; i++)
		F[i] += F[i - 1];
}
int main(){
	makePrime();
	int n, m;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			count[tmp]++;
		}
		compute();
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int L, R;
			scanf("%d%d", &L, &R);
			if (R>MAX)
				R = MAX;
			if (L > MAX)
				printf("%d\n", 0);
			else
				printf("%d\n", F[R] - F[L - 1]);
		}
	}
	return 0;
}
/*

C. Bear and Prime Numbers
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Recently, the bear started studying data structures and faced the following problem.

You are given a sequence of integers x1, x2, ..., xn of length n and m queries, each of them is characterized by two integers li, ri. Let's introduce f(p) to represent the number of such indexes k, that xk is divisible by p. The answer to the query li, ri is the sum: , where S(li, ri) is a set of prime numbers from segment [li, ri] (both borders are included in the segment).

Help the bear cope with the problem.

Input
The first line contains integer n (1 ≤ n ≤ 106). The second line contains n integers x1, x2, ..., xn (2 ≤ xi ≤ 107). The numbers are not necessarily distinct.

The third line contains integer m (1 ≤ m ≤ 50000). Each of the following m lines contains a pair of space-separated integers, li and ri (2 ≤ li ≤ ri ≤ 2·109) — the numbers that characterize the current query.

Output
Print m integers — the answers to the queries on the order the queries appear in the input.

Sample test(s)
input
6
5 5 7 10 14 15
3
2 11
3 12
4 4
output
9
7
0
input
7
2 3 5 7 11 4 8
2
8 10
2 123
output
0
7
Note
Consider the first sample. Overall, the first sample has 3 queries.

The first query l = 2, r = 11 comes. You need to count f(2) + f(3) + f(5) + f(7) + f(11) = 2 + 1 + 4 + 2 + 0 = 9.
The second query comes l = 3, r = 12. You need to count f(3) + f(5) + f(7) + f(11) = 1 + 4 + 2 + 0 = 7.
The third query comes l = 4, r = 4. As this interval has no prime numbers, then the sum equals 0.

*/