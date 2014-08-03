/* 5902937	 Feb 5, 2014 3:14:23 PM	Shark	 389A - Fox and Number Game	 GNU C++	Accepted	15 ms	0 KB */
#include<cstdio>
int GCD(int a, int b){
	int r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[100];
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				M[i] = M[j] = GCD(M[i], M[j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += M[i];
		printf("%d\n", ans);
	}
	return 0;
}
/*

A. Fox and Number Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel is playing a game with numbers now.

Ciel has n positive integers: x1, x2, ..., xn. She can do the following operation as many times as needed: select two different indexes i and j such that xi > xj hold, and then apply assignment xi = xi - xj. The goal is to make the sum of all numbers as small as possible.

Please help Ciel to find this minimal sum.

Input
The first line contains an integer n (2 ≤ n ≤ 100). Then the second line contains n integers: x1, x2, ..., xn (1 ≤ xi ≤ 100).

Output
Output a single integer — the required minimal sum.

Sample test(s)
input
2
1 2
output
2
input
3
2 4 6
output
6
input
2
12 18
output
12
input
5
45 12 27 30 18
output
15
Note
In the first example the optimal way is to do the assignment: x2 = x2 - x1.

In the second example the optimal sequence of operations is: x3 = x3 - x2, x2 = x2 - x1.

*/