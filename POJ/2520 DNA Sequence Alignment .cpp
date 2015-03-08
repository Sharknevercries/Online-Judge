/* 13931419	840502	2520	Accepted	1236K	10875MS	G++	2165B	2015-03-05 19:17:50 */
#include<bits\stdc++.h>
using namespace std;
struct Status{
	int v, score;
};
char A[50005], B[50005];
int va[50005], vb[50005], ans;
int lenA, lenB;
int cost[4][4] = { { 0, 5, 5, 5 }, { 5, 0, 4, 5 }, { 5, 4, 0, 5 }, { 5, 5, 5, 0 } };
Status f1[50005], f2[50005];
int ptr1, ptr2, cnt;
int convert(char c){
	if (c == 'A')	return 0;
	if (c == 'G')	return 1;
	if (c == 'C')	return 2;
	if (c == 'T')	return 3;
}
int main(){
	while (gets(A) && gets(B)){
		lenA = strlen(A), lenB = strlen(B);
		for (int i = 0; i < lenA; i++)
			va[i] = convert(A[i]);
		for (int i = 0; i < lenB; i++)
			vb[i] = convert(B[i]);
		ans = (lenA + lenB) / 10 * 3;
		f1[0].v = -1, f1[0].score = 0, cnt = 1;
		for (int i = -1; i < lenA - 1; i++){
			ptr1 = ptr2 = 0;
			while (ptr1 < cnt){
				int pos = f1[ptr1].v, score = f1[ptr1].score;
				if ((ptr1 + 1 == cnt || score < f1[ptr1 + 1].score + 3 * (f1[ptr1 + 1].v - pos)) &&
					(ptr2 == 0 || score < f2[ptr2 - 1].score + 3 * (pos - f2[ptr2 - 1].v + 1)) &&
					(score + 3 * abs((int)(lenA - i) - (int)(lenB - pos)) <= ans)){
					if (pos + 1 < lenB && va[i + 1] == vb[pos + 1])
						f2[ptr2].v = pos + 1, f2[ptr2++].score = score;
					else{
						if (ptr2 == 0 || f2[ptr2 - 1].v != pos)
							f2[ptr2].v = pos, f2[ptr2++].score = score + 3;
						else
							f2[ptr2 - 1].score = min(f2[ptr2 - 1].score, score + 3);
						if (pos < lenB - 1){
							f2[ptr2].v = pos + 1;
							f2[ptr2++].score = score + cost[va[i + 1]][vb[pos + 1]];
							if (ptr1 + 1 == cnt || f1[ptr1 + 1].v != pos + 1)
								f1[ptr1].v = pos + 1, f1[ptr1--].score = score + 3;
							else
								f1[ptr1 + 1].score = min(f1[ptr1 + 1].score, score + 3);
						}
					}
				}
				ptr1++;
			}
			cnt = ptr2;
			memcpy(f1, f2, cnt * sizeof * f1);
		}
		ans = f2[ptr2 - 1].score + 3 * (lenB - 1 - f2[ptr2 - 1].v);
		printf("%d\n", ans);
	}
	return 0;
}
/*

DNA Sequence Alignment
Time Limit: 25000MS		Memory Limit: 65536K
Total Submissions: 2347		Accepted: 285
Case Time Limit: 5000MS
Description

Gnaileux Iew is attracted in Bioinformatics recently. He reads papers day and night and devotes all his mind in studying. Today he is going to review the basic problem in Bioinformatics: DNA sequence alignment. His purpose is to find a simple and effective algorithm that performs global alignment with two highly similar DNA sequences.

A DNA sequence is presented as a sequence of characters, which may be 'A', 'G', 'C' or 'T'. To align two DNA sequences, some gaps may be inserted to sequences so that two sequences have the same length. And then it is counted up for every pair of matched characters by a score matrix. Gnaileux Iew uses a minimal-score matrix hence the total score of alignment should be minimized. Following is the score matrix Gnaileux Iew uses:


For example, an alignment for DNA sequences "AAGACG" and "CAGAGCTC" may be:
-AAGA-C-G
CA-GAGCTC
The total score is 3+0+3+0+0+3+0+3+4=16.

Gnaileux Iew is only interested in aligning highly similar sequences. Strictly speaking, |LCS(A,B)| * 2 / (|A |+ |B|) >= 90%, where A and B are the sequences to align, and LCS(A,B) is the longest common subsequence of A and B.
Input

Input contains multiple test cases. Each test case contains two lines, which are the two DNA sequences to align. DNA sequences contain only characters 'A', 'G', 'C' and 'T'. The length of each sequence is not greater than 50000.

You can assume that all the input cases are highly similar sequences.
Output

For each test case print the minimal total score of alignment in one line.
Sample Input

AGTGCTGAAAGTTGCGCCAGTGAC
AGTGCTGAAGTTCGCCAGTTGACG
CACAATTTTTCCCAGAGAGA
CGAATTTTTCCCAGAGAGA
Sample Output

12
7
Source

POJ Monthly--2005.07.31, CHEN Shixi

*/