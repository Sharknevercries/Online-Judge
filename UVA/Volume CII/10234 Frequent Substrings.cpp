/* 13252568	10234	Frequent Substrings	Accepted	C++	0.038	2014-03-03 08:03:09 */
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char S[1001];
int H[1001];
int sa[1001];
int c[1001];
int R[2][1001];
int len;
void suffix_array(){
	int N = len;
	int A = 256;
	int *rank = R[0];
	int *sa2 = R[1];
	for (int i = 0; i < A; i++)	c[i] = 0;
	for (int i = 0; i < N; i++)	c[rank[i] = S[i]]++;
	for (int i = 1; i < A; i++)	c[i] += c[i - 1];
	for (int i = N - 1; i >= 0; i--)	sa[--c[S[i]]] = i;
	for (int n = 1; n < N; n *= 2){
		int r = 0;
		for (int i = N - n; i < N; i++)
			sa2[r++] = i;
		for (int i = 0; i < N; i++){
			if (sa[i] >= n)
				sa2[r++] = sa[i] - n;
		}
		for (int i = 0; i < A; i++)	c[i] = 0;
		for (int i = 0; i < N; i++)	c[rank[sa2[i]]]++;
		for (int i = 1; i < A; i++)	c[i] += c[i - 1];
		for (int i = N - 1; i >= 0; i--)	sa[--c[rank[sa2[i]]]] = sa2[i];
		int *&newRank = sa2;
		newRank[sa[0]] = r = 0;
		for (int i = 1; i < N; i++){
			if (!(rank[sa[i - 1]] == rank[sa[i]] && rank[sa[i - 1] + n] == rank[sa[i] + n]))
				r++;
			newRank[sa[i]] = r;
		}
		swap(rank, sa2);
		if (r == N - 1)
			break;
		A = r + 1;
	}
}
void buildHeight(){
	int i, j;
	int N = len;
	int *rank = R[0];
	memset(H, 0, sizeof(H));
	for (i = 0; i < N; i++)	rank[sa[i]] = i;
	for (i = 0; i < N; i++){
		if (rank[i] == 0){
			H[rank[i]] = 0;
			continue;
		}
		if (i == 0 || H[rank[i - 1]] <= 1)
			j = 0;
		else
			j = H[rank[i - 1]] - 1;
		while (S[sa[rank[i] - 1] + j] == S[sa[rank[i]] + j])
			j++;
		H[rank[i]] = j;
	}
}
int main(){
	while (gets(S)){
		len = strlen(S);
		for (int i = 0; i < len; i++){
			if (S[i] >= 'A'&&S[i] <= 'Z')
				S[i] = S[i] - 'A' + 'a';
		}
		suffix_array();
		buildHeight();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int ask, N = len;
			scanf("%d", &ask);

			int maxCount = 0, start = 0;
			for (int j = 0; j < N; j++){
				if (H[j] >= ask){
					int count = 1, k = j;
					while (k < N && H[k] >= ask)
						count++, k++;
					if (count>maxCount)
						maxCount = count, start = sa[j - 1];
					j = k - 1;
				}
			}
			if (maxCount == 0){
				for (int j = 0; j < N; j++){
					if (N - sa[j] >= ask){
						maxCount = 1, start = sa[j];
						break;
					}
				}
			}
			printf("%d ", maxCount);
			for (int j = 0; j < ask; j++)
				putchar(S[start + j]);
			putchar('\n');
		}
		(void)getchar();
	}
	return 0;
}
/*

Problem F: Frequent Substrings
You are working for the R&D department of International Embedded Equipments Enterprise (IEEE). One day, your boss calls you up and tells this:

"Yes, I think we should use the N-Gram Analysis for the project. What do you think ??"
"Ye...s, I also thought so...", you replied.

After the conversation, having no clue about what he said, you start searching the internet and find the following sentences.

N-Grams are substrings of length N. N-Gram Analysis is a method of matching text, based on the statistical similarity of occurrences of N-Grams. N-Gram Analysis is used in research areas such as speech recognition, database interfacing, network communication etc.

After going through the topic a few times and reading several articles, you figure out the main parts of the project you have to accomplish. One of the parts required you to do this: Given a string S, you have to find the most frequently occurring N-Gram in S. Since you found this part interesting, you decide to complete it soon. Note that the occurrences can partially overlap. That is, the string bcbcbc has two occurrences of the substring cbc.

Input

Input consists of several test cases. Each test case begins with a line specifying the string S. S will contain no more than 1,000 characters. S can contain any of the printable ASCII characters. Capitalization should be ignored while finding the N-Grams. The next line specifies an integer T. Next T lines give the values for N, 0< N� Length(S).

Output

For each test case, output T lines specifying the number of occurrences of the N-Gram followed by the N-Gram itself separated by exactly one space. If there are several such N-Grams, output the least lexicographical one, compared in terms of ASCII values.

Note :  Given two strings a=a0a1a2...am and b=b0b1b2...bm over the same alphabet V, we say that a is lexicographically less than b if there exist an integer j, 0� j� m, so that ai=bi for all i=0,1,...,j-1 and aj< bj.

Sample Input

In theory, there is no difference between theory and practice, but in practice, there is.
2
4
9
Sample Output

4  the
2  practice

Arun Kishore

*/
