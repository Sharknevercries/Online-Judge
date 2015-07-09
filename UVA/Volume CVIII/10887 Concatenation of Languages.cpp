/* 15098347	10887	Concatenation of Languages	Accepted	C++	1.475	2015-03-07 12:23:04 */
#include<bits\stdc++.h>
using namespace std;
string S[1505], T[1505];
int main(){
	int t, ca = 1;
	scanf("%d", &t);
	while (t--){
		int n, m;
		map<string, int> map;
		scanf("%d%d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++)
			getline(cin, S[i]);
		for (int i = 0; i < m; i++)
			getline(cin, T[i]);
		printf("Case %d: ", ca++);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[S[i] + T[j]]++;
		printf("%d\n", map.size());
	}
	return 0;
}
/*

Problem A
Concatenation of Languages
Input File: Standard Input
Output: Standard Output

A language is a set of strings. And the concatenation of two languages is the set of all strings that are formed by concatenating the strings of the second language at the end of the strings of the first language.

For example, if we have two language A and B such that:
A = {cat, dog, mouse}
B = {rat, bat}
The concatenation of A and B would be:
C = {catrat, catbat, dograt, dogbat, mouserat, mousebat}

Given two languages your task is only to count the number of strings in the concatenation of the two languages.

Input
There can be multiple test cases. The first line of the input file contains the number of test cases, T (1≤T≤25). Then T test cases follow. The first line of each test case contains two integers, M and N (M,N<1500), the number of strings in each of the languages. Then the next M lines contain the strings of the first language. The N following lines give you the strings of the second language. You can assume that the strings are formed by lower case letters (‘a’ to ‘z’) only, that they are less than 10 characters long and that each string is presented in one line without any leading or trailing spaces. The strings in the input languages may not be sorted and there will be no duplicate string.

Output
For each of the test cases you need to print one line of output. The output for each test case starts with the serial number of the test case, followed by the number of strings in the concatenation of the second language after the first language.

Sample Input                               Output for Sample Input
2
3 2
cat
dog
mouse
rat
bat
1 1
abc
cab
Case 1: 6
Case 2: 1

Problem setter: Monirul Hasan
Special Thanks: Shahriar Manzoor

*/