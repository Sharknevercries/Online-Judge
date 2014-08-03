/* 5440931	 Dec 14, 2013 10:03:45 PM	Shark	 235A - LCM Challenge	 GNU C++	Accepted	498 ms	0 KB */
#include<cstdio>
typedef unsigned long long ull;
ull GCD(ull a, ull b){
	ull r;
	do{
		r = a%b;
		a = b; 
		b = r;
	} while (r != 0);
	return a;
}
ull LCM(ull a, ull b){
	return a*b / GCD(a, b);
}
int main(){
	ull n;
	while (scanf("%llu", &n) == 1){
		unsigned long long ans = 0;
		if (n == 1)
			ans = 1;
		else if (n == 2)
			ans = 2;
		else{

			for (ull i = n - 2; i >= 1; i--){ // type 1 n, n - 1, ...
				if (LCM(n, i*(n - 1)) > ans)
					ans = LCM(n, i*(n - 1));
			}
			for (ull i = n - 3; i >= 1; i--){ // type 2 n - 1, n - 2, ... 
				if (LCM(n - 1, i*(n - 2)) > ans)
					ans = LCM(n - 1, i*(n - 2));
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
/*

A. LCM Challenge
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Some days ago, I learned the concept of LCM (least common multiple). I've played with it for several times and I want to make a big number with it.

But I also don't want to use many numbers, so I'll choose three positive integers (they don't have to be distinct) which are not greater than n. Can you help me to find the maximum possible least common multiple of these three integers?

Input
The first line contains an integer n (1 ≤ n ≤ 106) — the n mentioned in the statement.

Output
Print a single integer — the maximum possible LCM of three not necessarily distinct positive integers that are not greater than n.

Sample test(s)
input
9
output
504
input
7
output
210
Note
The least common multiple of some positive integers is the least positive integer which is multiple for each of them.

The result may become very large, 32-bit integer won't be enough. So using 64-bit integers is recommended.

For the last example, we can chose numbers 7, 6, 5 and the LCM of them is 7·6·5 = 210. It is the maximum value we can get.

*/