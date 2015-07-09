/* 15620891	1451	Average	Accepted	C++	0.164	2015-06-12 15:36:52 */
#include<bits\stdc++.h>
using namespace std;
int Q[100005];
char s[100005];
int sum[100005];
int n, k;
int check(int a, int b, int c, int d){
	return (sum[b] - sum[a - 1]) * (d - c + 1) - (sum[d] - sum[c - 1]) * (b - a + 1);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + s[i] - '0';
		pair<int, int> ans = make_pair(1, k);
		int L = 0, R = 0;
		for (int i = k; i <= n; i++){
			int j = i - k;
			while (L + 1 < R && check(Q[R - 2], j, Q[R - 1], j) >= 0) R--;
			Q[R++] = j + 1;
			while (L + 1 < R && check(Q[L], i, Q[L + 1], i) <= 0) L++;
			int tmp = check(Q[L], i, ans.first, ans.second);
			if (tmp > 0 || (tmp == 0 && i - Q[L] < ans.second - ans.first))
				ans.first = Q[L], ans.second = i;
		}
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
/*

A DNA sequence consists of four letters, A, C, G, and T. The GC-ratio of a DNA sequence is the number of Cs and Gs of the sequence divided by the length of the sequence. GC-ratio is important in gene finding because DNA sequences with relatively high GC-ratios might be good candidates for the starting parts of genes. Given a very long DNA sequence, researchers are usually interested in locating a subsequence whose GC-ratio is maximum over all subsequences of the sequence. Since short subsequences with high GC-ratios are sometimes meaningless in gene finding, a length lower bound is given to ensure that a long subsequence with high GC-ratio could be found. If, in a DNA sequence, a 0 is assigned to every A and T and a 1 to every C and G, the DNA sequence is transformed into a binary sequence of the same length. GC-ratios in the DNA sequence are now equivalent to averages in the binary sequence.


Position										1	1	1	1	1	1	1	1
Index	1	2	3	4	5	6	7	8	9	0	1	2	3	4	5	6	7
Sequence	0	0	1	0	1	0	1	1	0	1	1	0	1	1	0	1	0

For the binary sequence above, if the length lower bound is 7, the maximum average is 6/8 which happens in the subsequence [7,14]. Its length is 8, which is greater than the length lower bound 7. If the length lower bound is 5, then the subsequence [7,11] gives the maximum average 4/5. The length is 5 which is equal to the length lower bound. For the subsequence [7,11], 7 is its starting index and 11 is its ending index.

Given a binary sequence and a length lower bound L, write a program to find a subsequence of the binary sequence whose length is at least L and whose average is maximum over all subsequences of the binary sequence. If two or more subsequences have the maximum average, then find the shortest one; and if two or more shortest subsequences with the maximum average exist, then find the one with the smallest starting index.

Input

Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing two integers n (1$ \le$n$ \le$100, 000) and L (1$ \le$L$ \le$1, 000) which are the length of a binary sequence and a length lower bound, respectively. In the next line, a string, binary sequence, of length n is given.

Output

Your program is to write to standard output. Print the starting and ending index of the subsequence.

The following shows sample input and output for two test cases.

Sample Input

2
17 5
00101011011011010
20 4
11100111100111110000
Sample Output

7 11
6 9

*/