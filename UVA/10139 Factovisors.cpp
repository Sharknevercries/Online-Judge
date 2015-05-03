/* 15279099	10139	Factovisors	Accepted	C++	0.432	2015-04-06 13:26:23 */
#include<bits\stdc++.h>
using namespace std;
int prime[50000], ptr;
inline void make_prime(){
	int limit = sqrt((double)3e9);
	ptr = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (int i = 5, j, gap = 2; i <= limit; i++){
		for (j = 0; j < ptr; j++)
			if (i % prime[j] == 0)
				break;
		if (j >= ptr)
			prime[ptr++] = i;
	}
}
bool check(int a, int b){
	// a! / b
	for (int i = 0; i < ptr; i++){
		int count = 0;
		while (b % prime[i] == 0)
			b /= prime[i], count++;
		long long j = prime[i];
		while (j <= a && count > 0)
			count -= a / j, j *= prime[i];
		if (count > 0)	return false;
	}
	if (b > 1 && a < b)
		return false;
	return true;
}
int main(){
	make_prime();
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int nn = n;
		if (nn == 0) nn = 1;
		if (check(nn, m))
			printf("%d divides %d!\n", m, n);
		else
			printf("%d does not divide %d!\n", m, n);
	}
	return 0;
}
/*

The factorial function, n! is defined thus for n a non-negative integer:
0! = 1
n! = n × (n − 1)! (n > 0)
We say that a divides b if there exists an integer k such that
k × a = b
Input
The input to your program consists of several lines, each containing two non-negative integers, n and
m, both less than 231
.
Output
For each input line, output a line stating whether or not m divides n!, in the format shown below.
Sample Input
6 9
6 27
20 10000
20 100000
1000 1009
Sample Output
9 divides 6!
27 does not divide 6!
10000 divides 20!
100000 does not divide 20!
1009 does not divide 1000!

*/