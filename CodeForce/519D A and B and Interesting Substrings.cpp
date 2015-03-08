/* 10121019	2015-03-02 18:10:14	Shark	519D - A and B and Interesting Substrings	GNU C++	Accepted	46 ms	5500 KB */
#include<bits\stdc++.h>
using namespace std;
int w[26];
long long int sum[100005];
char str[100005];
vector<int> P[26];
int main(){
	for (int i = 0; i < 26; i++)
		scanf("%d", w + i);
	scanf("%s", str + 1);
	for (int i = 1; str[i] != '\0'; i++){
		sum[i] = sum[i - 1] + w[str[i] - 'a'];
		P[str[i] - 'a'].push_back(i);
	}
	long long int ans = 0;
	for (int i = 0; i < 26; i++){
		map<long long int, int> res;
		for (int j = 0; j < P[i].size(); j++){
			int p = P[i][j];
			ans += res[sum[p - 1]];
			res[sum[p]]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*

D. A and B and Interesting Substrings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A and B are preparing themselves for programming contests.

After several years of doing sports programming and solving many problems that require calculating all sorts of abstract objects, A and B also developed rather peculiar tastes.

A likes lowercase letters of the Latin alphabet. He has assigned to each letter a number that shows how much he likes that letter (he has assigned negative numbers to the letters he dislikes).

B likes substrings. He especially likes the ones that start and end with the same letter (their length must exceed one).

Also, A and B have a string s. Now they are trying to find out how many substrings t of a string s are interesting to B (that is, t starts and ends with the same letter and its length is larger than one), and also the sum of values of all letters (assigned by A), except for the first and the last one is equal to zero.

Naturally, A and B have quickly found the number of substrings t that are interesting to them. Can you do it?

Input
The first line contains 26 integers xa, xb, ..., xz ( - 105 ≤ xi ≤ 105) — the value assigned to letters a, b, c, ..., z respectively.

The second line contains string s of length between 1 and 105 characters, consisting of Lating lowercase letters— the string for which you need to calculate the answer.

Output
Print the answer to the problem.

Sample test(s)
input
1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
xabcab
output
2
input
1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 8 1 1 1 1 1 1
aaa
output
2
Note
In the first sample test strings satisfying the condition above are abca and bcab.

In the second sample test strings satisfying the condition above are two occurences of aa.

*/