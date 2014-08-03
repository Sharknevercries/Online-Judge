/* 13850436	11038	How Many O's?	Accepted	C++	0.022	2014-07-08 09:54:03 */
/*

計算第 i 位為零的數量並加總

*/
#include<cstdio>
#include<math.h>
long long int solve(long long int s){ // how many 0 in 1 ~ s
	long long int res = 0, L = 1, R = 1, S = s;
	int mid;
	while (S >= 10){
		mid = S % 10;
		S /= 10;
		if (mid == 0)
			res += L * (S - 1) + s % R + 1;
		else
			res += L * S;
		L *= 10, R *= 10;
	}
	return res;
}
int main(){
	long long int n, m;
	while (scanf("%lld%lld", &m, &n) == 2){
		if (m == -1)
			break;
		long long int ans = solve(n) - solve(m - 1);
		if (m == 0)	ans++;
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem E: How many 0's?

A Benedict monk No. 16 writes down the decimal representations of all natural numbers between and including m and n, m ≤ n. How many 0's will he write down?
Input consists of a sequence of lines. Each line contains two unsigned 32-bit integers m and n, m ≤ n. The last line of input has the value of m negative and this line should not be processed.

For each line of input print one line of output with one integer number giving the number of 0's written down by the monk.

Sample input

10 11
100 200
0 500
1234567890 2345678901
0 4294967295
-1 -1
Output for sample input

1
22
92
987654304
3825876150
Piotr Rudnicki

*/