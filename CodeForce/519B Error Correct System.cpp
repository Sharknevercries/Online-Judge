/* 10320462	2015-03-17 20:43:22	Shark	527B - Error Correct System	GNU C++	Accepted	108 ms	2700 K */
#include<bits\stdc++.h>
using namespace std;
int main(){
	int n;
	map<int, int> Q;
	vector<int> P[26];
	string s, t;
	cin >> n >> s >> t;
	int dist = 0, a = -1, b = -1, fix = 0;
	for (int i = 1; i <= n; i++){
		if (s[i - 1] != t[i - 1]){
			int hashCode1 = 100 * (s[i - 1] - 'a') + t[i - 1] - 'a';
			int hashCode2 = 100 * (t[i - 1] - 'a') + s[i - 1] - 'a';
			if (Q[hashCode2])
				fix = 2, a = i, b = Q[hashCode2];
			Q[hashCode1] = i;
			dist++;
			P[s[i - 1] - 'a'].push_back(i);
		}
	}
	for (int i = 1; i <= n && fix == 0; i++)
		if (s[i - 1] != t[i - 1]){
			for (int j = 0; j < P[t[i - 1] - 'a'].size(); j++){
				int next = P[t[i - 1] - 'a'][j];
				fix = 1, a = i, b = next;
				break;
			}
		}


	printf("%d\n", dist - fix);
	printf("%d %d\n", a, b);
	return 0;
}
/*

B. Error Correct System
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ford Prefect got a job as a web developer for a small company that makes towels. His current work task is to create a search engine for the website of the company. During the development process, he needs to write a subroutine for comparing strings S and T of equal length to be "similar". After a brief search on the Internet, he learned about the Hamming distance between two strings S and T of the same length, which is defined as the number of positions in which S and T have different characters. For example, the Hamming distance between words "permanent" and "pergament" is two, as these words differ in the fourth and sixth letters.

Moreover, as he was searching for information, he also noticed that modern search engines have powerful mechanisms to correct errors in the request to improve the quality of search. Ford doesn't know much about human beings, so he assumed that the most common mistake in a request is swapping two arbitrary letters of the string (not necessarily adjacent). Now he wants to write a function that determines which two letters should be swapped in string S, so that the Hamming distance between a new string S and string T would be as small as possible, or otherwise, determine that such a replacement cannot reduce the distance between the strings.

Help him do this!

Input
The first line contains integer n (1 ≤ n ≤ 200 000) — the length of strings S and T.

The second line contains string S.

The third line contains string T.

Each of the lines only contains lowercase Latin letters.

Output
In the first line, print number x — the minimum possible Hamming distance between strings S and T if you swap at most one pair of letters in S.

In the second line, either print the indexes i and j (1 ≤ i, j ≤ n, i ≠ j), if reaching the minimum possible distance is possible by swapping letters on positions i and j, or print "-1 -1", if it is not necessary to swap characters.

If there are multiple possible answers, print any of them.

Sample test(s)
input
9
pergament
permanent
output
1
4 6
input
6
wookie
cookie
output
1
-1 -1
input
4
petr
egor
output
2
1 2
input
6
double
bundle
output
2
4 1
Note
In the second test it is acceptable to print i = 2, j = 3.

*/