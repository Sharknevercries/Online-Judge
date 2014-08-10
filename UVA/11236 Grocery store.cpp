/* 13997971	11236	Grocery store	Accepted	C++	0.599	2014-08-06 08:55:17 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 2000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	lli hundred3 = 100 * 100 * 100;
	lli a = 0, b = 0, c = 0;
	int count = 0;
	for (lli i = 1; i <= 125; i++){
		for (lli j = i; j <= 594; j++){
			for (lli k = j; k <= 884; k++){
				if (i*j*k - hundred3 <= 0 || (hundred3 * (i + j + k)) % (i*j*k - hundred3) != 0)
					continue;
				lli s = hundred3 * (i + j + k) / (i*j*k - hundred3);
				if (s >= k && i + j + k + s <= MAX_N){
					printf("%.2lf %.2lf %.2lf %.2lf\n", i / 100.0, j / 100.0, k / 100.0, s / 100.0), count++;
					/*
					a = max(a, i);
					b = max(b, j);
					c = max(c, k);
					*/
				}
			}
		}
	}
	// printf("%d\n", count);
	return 0;
}
/*

2007/2008 ACM International Collegiate Programming Contest
University of Ulm Local Contest
Problem G: Grocery store

A cashier in a grocery store seems to have difficulty in distinguishing the multiplication symbol and the addition symbol. To make things easier for him, you want to buy goods in such a way that the product of their prices is the same as the sum of their prices.

Of course, if you buy only one item, this is always true. With two items and three items, it still seems quite a boring task to you, so now you are interested in finding possible prices of four items such that the sum of the four prices is equal to the product of the four prices. You should consider the prices are in £á with two digits after the decimal point. Obviously, each product costs at least one cent.

Input Specification

This problem has no input.

Output Specification

Print all solutions which have a sum of the four items of at most 20.00 £á. For each solution, print one line with the prices of the four items in non-decreasing order, with one space character between them. You may print the solutions in any order, but make sure to print each solution only once.
Sample Output

0.50 1.00 2.50 16.00
1.25 1.60 1.75 1.84
1.25 1.40 1.86 2.00
...

*/