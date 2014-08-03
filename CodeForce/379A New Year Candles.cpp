/* 5590402	 Dec 31, 2013 11:57:17 AM	Shark	 379A - New Year Candles	 GNU C++	Happy New Year!	 15 ms	 0 KB */
#include<cstdio>
int main(){
	int a, b;
	while (scanf("%d%d", &a, &b) == 2){
		int ans = 0, tmp = 0;
		while (a > 0){
			ans += a;
			tmp += a;
			a = tmp / b;
			tmp %= b;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

A. New Year Candles
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasily the Programmer loves romance, so this year he decided to illuminate his room with candles.

Vasily has a candles.When Vasily lights up a new candle, it first burns for an hour and then it goes out. Vasily is smart, so he can make b went out candles into a new candle. As a result, this new candle can be used like any other new candle.

Now Vasily wonders: for how many hours can his candles light up the room if he acts optimally well? Help him find this number.

Input
The single line contains two integers, a and b (1 ≤ a ≤ 1000; 2 ≤ b ≤ 1000).

Output
Print a single integer — the number of hours Vasily can light up the room for.

Sample test(s)
input
4 2
output
7
input
6 3
output
8
Note
Consider the first sample. For the first four hours Vasily lights up new candles, then he uses four burned out candles to make two new ones and lights them up. When these candles go out (stop burning), Vasily can make another candle. Overall, Vasily can light up the room for 7 hours.

*/