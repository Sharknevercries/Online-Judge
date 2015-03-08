/* 9984986	2015-02-24 19:43:36	Shark	518B - Tanya and Postcard	GNU C++	Accepted	78 ms	800 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	string s, t;
	int ans1 = 0, ans2 = 0;
	int a[500] = { 0 }, b[500] = { 0 };
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++)
		a[s[i]]++;
	for (int i = 0; i < t.length(); i++)
		b[t[i]]++;
	for (int i = 0; i < 500; i++){
		int tmp = min(a[i], b[i]);
		ans1 += tmp;
		a[i] -= tmp, b[i] -= tmp;
	}
	for (int i = 65; i < 97; i++){
		int tmp = min(a[i] + a[i + 32], b[i] + b[i + 32]);
		ans2 += tmp;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
/*

B. Tanya and Postcard
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Tanya decided to present her dad a postcard on his Birthday. She has already created a message — string s of length n, consisting of uppercase and lowercase English letters. Tanya can't write yet, so she found a newspaper and decided to cut out the letters and glue them into the postcard to achieve string s. The newspaper contains string t, consisting of uppercase and lowercase English letters. We know that the length of string t greater or equal to the length of the string s.

The newspaper may possibly have too few of some letters needed to make the text and too many of some other letters. That's why Tanya wants to cut some n letters out of the newspaper and make a message of length exactly n, so that it looked as much as possible like s. If the letter in some position has correct value and correct letter case (in the string s and in the string that Tanya will make), then she shouts joyfully "YAY!", and if the letter in the given position has only the correct value but it is in the wrong case, then the girl says "WHOOPS".

Tanya wants to make such message that lets her shout "YAY!" as much as possible. If there are multiple ways to do this, then her second priority is to maximize the number of times she says "WHOOPS". Your task is to help Tanya make the message.

Input
The first line contains line s (1 ≤ |s| ≤ 2·105), consisting of uppercase and lowercase English letters — the text of Tanya's message.

The second line contains line t (|s| ≤ |t| ≤ 2·105), consisting of uppercase and lowercase English letters — the text written in the newspaper.

Here |a| means the length of the string a.

Output
Print two integers separated by a space:

the first number is the number of times Tanya shouts "YAY!" while making the message,
the second number is the number of times Tanya says "WHOOPS" while making the message.
Sample test(s)
input
AbC
DCbA
output
3 0
input
ABC
abc
output
0 3
input
abacaba
AbaCaBA
output
3 4

*/