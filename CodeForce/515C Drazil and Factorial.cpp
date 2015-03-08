/* 9892867	2015-02-17 20:12:06	Shark	515C - Drazil and Factorial	GNU C++	Accepted	15 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int prime[4] = { 0 };
int cost[4][4] = { { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 3, 1, 1, 0 }, { 4, 2, 1, 1 } };
void f(int s){
	int t = 1;
	for (int i = 2; i <= s;i++)
		t *= i;
	while (t % 2 == 0)	prime[0]++, t /= 2;
	while (t % 3 == 0)	prime[1]++, t /= 3;
	while (t % 5 == 0)	prime[2]++, t /= 5;
	while (t % 7 == 0)	prime[3]++, t /= 7;
}
void solve(){
	string ans = "";
	for (int i = 3; i >= 0; i--){
		while (prime[i] > 0){
			if (i == 3)		ans.push_back('7');
			if (i == 2)		ans.push_back('5');
			if (i == 1)		ans.push_back('3');
			if (i == 0)		ans.push_back('2');
			for (int j = 0; j < 4; j++)
				prime[j] -= cost[i][j];
		}
	}
	cout << ans << endl;
}
int main(){
	long long int n;
	scanf("%lld", &n);
	scanf("%lld", &n);
	for (long long int i = n; i > 0; i /= 10){
		int digit = i % 10;
		f(digit);
	}
	solve();
	return 0;
}
/*

C. Drazil and Factorial
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Drazil is playing a math game with Varda.

Let's define  for positive integer x as a product of factorials of its digits. For example, .

First, they choose a decimal number a consisting of n digits that contains at least one digit larger than 1. This number may possibly start with leading zeroes. Then they should find maximum positive number x satisfying following two conditions:

1. x doesn't contain neither digit 0 nor digit 1.

2.  = .

Help friends find such number.

Input
The first line contains an integer n (1 ≤ n ≤ 15) — the number of digits in a.

The second line contains n digits of a. There is at least one digit in a that is larger than 1. Number a may possibly contain leading zeroes.

Output
Output a maximum possible integer satisfying the conditions above. There should be no zeroes and ones in this number decimal representation.

Sample test(s)
input
4
1234
output
33222
input
3
555
output
555
Note
In the first case,

 */