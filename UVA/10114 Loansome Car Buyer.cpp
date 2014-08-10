/* 13987689	10114	Loansome Car Buyer	Accepted	C++	0.016	2014-08-04 07:09:48 */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n, m;
	double paid, loan;
	while (scanf("%d %lf %lf %d", &n, &paid, &loan, &m) == 4){
		if (n <= 0)
			break;
		double p[MAX_N] = { 0 };
		bool V[MAX_N] = { false };
		double car, pay;
		pay = loan / n;
		for (int i = 0; i < m; i++){
			int s; double t;
			scanf("%d %lf", &s, &t);
			p[s] = (1.0 - t), V[s] = true;
		}
		for (int i = 1; i <= n; i++){
			if (!V[i])
				p[i] = p[i - 1];
		}
		car = (paid + loan) * p[0];
		int ans;
		for (ans = 1; ans <= n; ans++){
			if (car + 1e-8 > loan)	break;
			car *= p[ans];
			loan -= pay;
		}
		ans--;
		printf("%d month", ans);
		if (ans != 1)	putchar('s');
		putchar('\n');
	}
	return 0;
}
/*

Problem D: Loansome Car Buyer

Source file:	loan.{c, cpp, java, pas}
Input file:	loan.in
Output file:	loan.out
Kara Van and Lee Sabre are lonesome. A few months ago they took out a loan to buy a new car, but now they're stuck at home on Saturday night without wheels and without money. You see, there was a wreck and the car was totaled. Their insurance paid $10,000, the current value of the car. The only problem is that they owed the bank $15,000, and the bank wanted payment immediately, since there was no longer a car for collateral. In just a few moments, this unfortunate couple not only lost their car, but lost an additional $5,000 in cash too.

What Kara and Lee failed to account for was depreciation, the loss in value as the car ages. Each month the buyer's loan payment reduces the amount owed on the car. However, each month, the car also depreciates as it gets older. Your task is to write a program that calculates the first time, measured in months, that a car buyer owes less money than a car is worth. For this problem, depreciation is specified as a percentage of the previous month's value.

Input consists of information for several loans. Each loan consists of one line containing the duration in months of the loan, the down payment, the amount of the loan, and the number of depreciation records that follow. All values are nonnegative, with loans being at most 100 months long and car values at most $75,000. Since depreciation is not constant, the varying rates are specified in a series of depreciation records. Each depreciation record consists of one line with a month number and depreciation percentage, which is more than 0 and less than 1. These are in strictly increasing order by month, starting at month 0. Month 0 is the depreciation that applies immediately after driving the car off the lot and is always present in the data. All the other percentages are the amount of depreciation at the end of the corresponding month. Not all months may be listed in the data. If a month is not listed, then the previous depreciation percentage applies. The end of the input is signalled by a negative loan duration - the other three values will be present but indeterminate.

For simplicity, we will assume a 0% interest loan, thus the car's initial value will be the loan amount plus the down payment. It is possible for a car's value and amount owed to be positive numbers less than $1.00. Do not round values to a whole number of cents ($7,347.635 should not be rounded to $7,347.64).

Consider the first example below of borrowing $15,000 for 30 months. As the buyer drives off the lot, he still owes $15,000, but the car has dropped in value by 10% to $13,950. After 4 months, the buyer has made 4 payments, each of $500, and the car has further depreciated 3% in months 1 and 2 and 0.2% in months 3 and 4. At this time, the car is worth $13,073.10528 and the borrower only owes $13,000.

For each loan, the output is the number of complete months before the borrower owes less than the car is worth. Note that English requires plurals (5 months) on all values other than one (1 month).

Example input:

30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1
Example output:

4 months
1 month
49 months

*/