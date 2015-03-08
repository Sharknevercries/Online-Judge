/* 9995455	2015-02-24 20:37:40	Shark	518A - Vitaly and Strings	GNU C++	Accepted	31 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	string a, b, c;
	cin >> a >> b;
	int len = a.length() -1;
	a[len]++;
	bool flag = true;
	while (flag && a[len] > 'z'){
		a[len] -= 26;
		if (len - 1 >= 0)
			a[len - 1]++;
		else
			flag = false;
		len--;
	}
	if (!flag || a == b)
		puts("No such string");
	else
		cout << a << endl;
	return 0;
}
/*

A. Vitaly and Strings
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vitaly is a diligent student who never missed a lesson in his five years of studying in the university. He always does his homework on time and passes his exams in time.

During the last lesson the teacher has provided two strings s and t to Vitaly. The strings have the same length, they consist of lowercase English letters, string s is lexicographically smaller than string t. Vitaly wondered if there is such string that is lexicographically larger than string s and at the same is lexicographically smaller than string t. This string should also consist of lowercase English letters and have the length equal to the lengths of strings s and t.

Let's help Vitaly solve this easy problem!

Input
The first line contains string s (1 ≤ |s| ≤ 100), consisting of lowercase English letters. Here, |s| denotes the length of the string.

The second line contains string t (|t| = |s|), consisting of lowercase English letters.

It is guaranteed that the lengths of strings s and t are the same and string s is lexicographically less than string t.

Output
If the string that meets the given requirements doesn't exist, print a single string "No such string" (without the quotes).

If such string exists, print it. If there are multiple valid strings, you may print any of them.

Sample test(s)
input
a
c
output
b
input
aaa
zzz
output
kkk
input
abcdefg
abcdefh
output
No such string
Note
String s = s1s2... sn is said to be lexicographically smaller than t = t1t2... tn, if there exists such i, that s1 = t1, s2 = t2, ... si - 1 = ti - 1, si < ti.

*/