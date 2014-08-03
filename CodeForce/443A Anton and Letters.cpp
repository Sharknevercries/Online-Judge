/* 6923389	 2014-06-19 21:56:37	Shark	 443A - Anton and Letters	 GNU C++	Accepted	 15 ms	 0 KB */
#include<cstdio>
int main(){
	char S[10000];
	while (gets(S)){
		int ans = 0;
		bool V[300] = { false };
		for (int i = 0; S[i] != '\0'; i++){
			if (S[i] >= 'a'&&S[i] <= 'z'){
				if (!V[S[i]])
					ans++;
				V[S[i]] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

A. Anton and Letters
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently, Anton has found a set. The set consists of small English letters. Anton carefully wrote out all the letters from the set in one line, separated by a comma. He also added an opening curved bracket at the beginning of the line and a closing curved bracket at the end of the line.

Unfortunately, from time to time Anton would forget writing some letter and write it again. He asks you to count the total number of distinct letters in his set.

Input
The first and the single line contains the set of letters. The length of the line doesn't exceed 1000. It is guaranteed that the line starts from an opening curved bracket and ends with a closing curved bracket. Between them, small English letters are listed, separated by a comma. Each comma is followed by a space.

Output
Print a single number — the number of distinct letters in Anton's set.

Sample test(s)
input
{a, b, c}
output
3
input
{b, a, b, a}
output
2
input
{}
output
0

*/