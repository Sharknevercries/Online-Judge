/* 5207669	 Nov 24, 2013 3:00:29 PM	Shark	 53A - Autocomplete	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
char T[100][200];
char S[200];
int n;
bool bigger(char A[], char B[]){ // lexicographical order
	int len1 = strlen(A);
	int len2 = strlen(B);
	int i;
	for (i = 0; i < len1 && i < len2; i++){
		if (A[i] > B[i])
			return true;
		if (A[i] < B[i])
			return false;
	}
	if (A[i] == '\0')
		return false;
	if (B[i] == '\0')
		return true;

	return false;
}
void SWAP(char A[], char B[]){
	char tmp[200];
	strcpy(tmp, A);
	strcpy(A, B);
	strcpy(B, tmp);
}
int query(){
	int i, len1;
	len1 = strlen(S);
	for (i = 0; i < n; i++){
		if (strncmp(S, T[i], len1) == 0){
			return i;
		}
	}
	return -1;
}
int main(){
	while (scanf("%s", S) == 1){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (bigger(T[i], T[j]))
					SWAP(T[i], T[j]);
			}
		}
		int result = query();
		if (result >= 0)
			printf("%s\n", T[result]);
		else
			printf("%s\n", S);
	}
	return 0;
}
/*

A. Autocomplete
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Autocomplete is a program function that enables inputting the text (in editors, command line shells, browsers etc.) completing the text by its inputted part. Vasya is busy working on a new browser called 'BERowser'. He happens to be working on the autocomplete function in the address line at this very moment. A list consisting of n last visited by the user pages and the inputted part s are known. Your task is to complete s to make it an address of one of the pages from the list. You have to find the lexicographically smallest address having a prefix s.

Input
The first line contains the s line which is the inputted part. The second line contains an integer n (1 ≤ n ≤ 100) which is the number of visited pages. Then follow n lines which are the visited pages, one on each line. All the lines have lengths of from 1 to 100 symbols inclusively and consist of lowercase Latin letters only.

Output
If s is not the beginning of any of n addresses of the visited pages, print s. Otherwise, print the lexicographically minimal address of one of the visited pages starting from s.

The lexicographical order is the order of words in a dictionary. The lexicographical comparison of lines is realized by the '<' operator in the modern programming languages.

Sample test(s)
input
next
2
nextpermutation
nextelement
output
nextelement
input
find
4
find
findfirstof
findit
fand
output
find
input
find
4
fondfind
fondfirstof
fondit
fand
output
find

*/