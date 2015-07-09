/* 15249403	10617	Again Palindrome	Accepted	C++	0.015	2015-03-31 14:15:53 */
#include<bits\stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		long long DP[105][105] = { 0 };
		string s;
		cin >> s;
		n = s.length();
		for (int i = 0; i < n; i++)
			DP[i][i] = 1;
		for (int i = 1; i < n; i++){
			for (int j = 0; j + i < n; j++){
				DP[j][j + i] = 1 + DP[j][j + i - 1];
				for (int k = j; k < j + i; k++)
					if (s[k] == s[j + i])
						DP[j][j + i] += 1 + DP[k + 1][j + i - 1];
			}
		}
		printf("%lld\n", DP[0][n - 1]);
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