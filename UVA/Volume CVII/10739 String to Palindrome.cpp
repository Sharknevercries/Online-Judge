/* 15150123	10739	String to Palindrome	Accepted	C++	0.032	2015-03-15 13:25:36 */
#include<bits\stdc++.h>
using namespace std;
string S;
int DP[1005][1005];
int solve(int a, int b){
	int &res = DP[a][b];
	if (res != 2e9)	return res;
	if (b <= a)	return res = 0;
	if (S[a] == S[b])
		return res = solve(a + 1, b - 1);
	else
		return res = 1 + min(solve(a + 1, b), min(solve(a, b - 1), solve(a + 1, b - 1)));
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		cin >> S;
		for (int j = 0; j <= S.length(); j++)
			for (int k = 0; k <= S.length(); k++)
				DP[j][k] = 2e9;
		printf("Case %d: %d\n", i + 1, solve(0, S.length() - 1));
	}
	return 0;
}
/*

Problem H
String to Palindrome
Input: Standard Input
Output: Standard Output
Time Limit: 1 Second

In this problem you are asked to convert a string into a palindrome with minimum number of operations. The operations are described below:

Here you’d have the ultimate freedom. You are allowed to:
Add any character at any position
Remove any character from any position
Replace any character at any position with another character
Every operation you do on the string would count for a unit cost. You’d have to keep that as low as possible.

For example, to convert “abccda” you would need at least two operations if we allowed you only to add characters. But when you have the option to replace any character you can do it with only one operation. We hope you’d be able to use this feature to your advantage.

Input
The input file contains several test cases. The first line of the input gives you the number of test cases, T (1≤T≤10). Then T test cases will follow, each in one line. The input for each test case consists of a string containing lower case letters only. You can safely assume that the length of this string will not exceed 1000 characters.

Output
For each set of input print the test case number first. Then print the minimum number of characters needed to turn the given string into a palindrome.

Sample Input                               Output for Sample Input
6
tanbirahmed
shahriarmanzoor
monirulhasan
syedmonowarhossain
sadrulhabibchowdhury
mohammadsajjadhossain
Case 1: 5
Case 2: 7
Case 3: 6
Case 4: 8
Case 5: 8
Case 6: 8
Problem setter: Monirul Hasan, EPS

*/