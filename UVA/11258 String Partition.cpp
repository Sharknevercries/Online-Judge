/* 15387682	11258	String Partition	Accepted	C++	0.042	2015-04-26 07:52:41 */
#include<bits\stdc++.h>
using namespace std;
char s[100005];
long long DP[205];
long long cal(int a, int b){
	long long res = 0;
	for (int i = a; i <= b; i++)
		res = res * 10 + s[i] - '0';
	return res <= 2147483647 ? res : -1;
}
long long solve(int a){
	if (DP[a] != -1)	return DP[a];
	long long &res = DP[a];
	for (int i = 1; i <= 10; i++)
		res = max(res, solve(a - i) + cal(a - i + 1, a));
	return res;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s + 1);
		s[0] = '0';
		memset(DP, -1, sizeof(DP));
		printf("%lld\n", solve(strlen(s) - 1));
	}
	return 0;
}
/*

Problem F - String Partition


John was absurdly busy for preparing a programming contest recently. He wanted to create a ridiculously easy problem for the contest. His problem was not only easy, but also boring: Given a list of non-negative integers, what is the sum of them?

However, he made a very typical mistake when he wrote a program to generate the input data for his problem. He forgot to print out spaces to separate the list of integers. John quickly realized his mistake after looking at the generated input file because each line is simply a string of digits instead of a list of integers.

He then got a better idea to make his problem a little more interesting: There are many ways to split a string of digits into a list of non-zero-leading (0 itself is allowed) 32-bit signed integers. What is the maximum sum of the resultant integers if the string is split appropriately?

Input
The input begins with an integer N (≤ 500) which indicates the number of test cases followed. Each of the following test cases consists of a string of at most 200 digits.

Output
For each input, print out required answer in a single line.

Sample input
6
1234554321
5432112345
000
121212121212
2147483648
11111111111111111111111111111111111111111111111111111

Sample output
1234554321
543211239
0
2121212124
214748372
5555555666

Problem setter: Cho
Source: Tsinghua-HKUST Programming Contest 2007

*/