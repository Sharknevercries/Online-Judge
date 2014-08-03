/* 13392962	10617	Again Palindrome	Accepted	C++	0.019	2014-03-26 12:43:42 */
#include<cstdio>
#include<string.h>
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		char str[100];
		unsigned long long  DP[100][100] = { 0 };
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			DP[i][i] = 1;
		for (int j = 1; j < len; j++){
			for (int i = j - 1; i >= 0; i--){
				if (str[i] == str[j])
					DP[i][j] = DP[i + 1][j] + DP[i][j - 1] + 1;
				else
					DP[i][j] = DP[i + 1][j] + DP[i][j - 1] - DP[i + 1][j - 1];

			}
		}
		printf("%llu\n", DP[0][len - 1]);
	}
	return 0;
}
/*

Problem I
Again Palindromes
Input: Standard Input
Output: Standard Output
Time Limit: 2 Seconds

A palindorme is a sequence of one or more characters that reads the same from the left as it does from the right. For example, Z, TOT and MADAM are palindromes, but ADAM is not.

Given a sequence S of N capital latin letters. How many ways can one score out a few symbols (maybe 0) that the rest of sequence become a palidrome. Varints that are only  different by an order of scoring out should be considered the same.

Input
The input file contains several test cases (less than 15). The first line contains an integer T that indicates how many test cases are to follow.

Each of the T lines contains a sequence S (1≤N≤60). So actually each of these lines is a test case.

Output
For each test case output in a single line an integer – the number of ways.

Sample Input                             Output for Sample Input
3
BAOBAB
AAAA
ABA
22
15
5
Russian Olympic Camp

*/