/* 5355793	 Dec 5, 2013 8:42:54 PM	Shark	 23A - You're Given a String...	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
#include<string.h>
int main(){
	char str[1000];
	while (scanf("%s", str) == 1){
		int len = strlen(str);
		int ans = len - 1;
		bool found = false;
		for (; ans >= 1 && !found; ans--){
			for (int L = 0; L + ans - 1 < len&&!found; L++){
				for (int LL = L + 1; LL + ans - 1 < len&&!found; LL++){
					if (strncmp(str + L, str + LL, ans) == 0){
						found = true;
						printf("%d\n", ans);
					}
				}
			}
		}
		if (!found)
			puts("0");
	}
	return 0;
}
/*

A. You're Given a String...
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You're given a string of lower-case Latin letters. Your task is to find the length of its longest substring that can be met in the string at least twice. These occurrences can overlap (see sample test 2).

Input
The first input line contains the string. It's guaranteed, that the string is non-empty, consists of lower-case Latin letters, and its length doesn't exceed 100.

Output
Output one number ¡X length of the longest substring that can be met in the string at least twice.

Sample test(s)
input
abcd
output
0
input
ababa
output
3
input
zzz
output
2

*/