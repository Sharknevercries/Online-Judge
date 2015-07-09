/* 13924155	10930	A-Sequence	Accepted	C++	0.029	2014-07-22 07:58:28 */
/*

Template By Shark

*/
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 30
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int main(){
	int n, t = 1;
	while (scanf("%d", &n) == 1){
		int S[MAX_N];
		int DP[MAX_N*MAX_M + 1] = { 0 };
		bool C[MAX_N*MAX_M + 1] = { false };
		bool invalid = false;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		if (S[0] < 1)	invalid = true;
		for (int i = 1; i < n; i++)
			if (S[i] <= S[i - 1])
				invalid = true;
		C[0] = true;
		for (int i = 0; i < n; i++)
			for (int j = MAX_N*MAX_M; j >= S[i]; j--)
				if (C[j - S[i]])
					DP[j] = max(DP[j], DP[j - S[i]] + 1), C[j] = true;
		for (int i = 0; i < n; i++)
			if (DP[S[i]] >= 2)
				invalid = true;

		printf("Case #%d:", t++);
		for (int i = 0; i < n; i++)
			printf(" %d", S[i]);
		if (invalid)
			puts("\nThis is not an A-sequence.");
		else
			puts("\nThis is an A-sequence.");
	}
	return 0;
}
/*

Problem D - A-Sequence

Time Limit: 1 second

For this problem an A-sequence is a sequence of positive integers ai satisfying 1 ≤ a1 < a2 < a3 < ... and every ak of the sequence is not the sum of two or more distinct earlier terms of the sequence.

You should write a program to determine if a given sequence it is or it is not an A-sequence.

Input

The input consists of a set of lines, each line starts with an integer 2 ≤ D ≤ 30 that indicates the number of integers that the current sequence has. Following this number there is the sequence itself. The sequence is composed by integers, each integer is greater than or equal to 1 and less than or equal to 1000. The input is terminated by enf of file (EOF).

Output

For each test case in the input you should print two lines: the first line should indicate the number of the test case and the test case itself; in the the second line you should print This is an A-sequence., if the corresponding test case is an A-sequence or This is not an A-sequence., if the corresponding test case is not an A-sequence.

Sample Input

2 1 2
3 1 2 3
10 1 3 16 19 25 70 100 243 245 306
Sample Output

Case #1: 1 2
This is an A-sequence.
Case #2: 1 2 3
This is not an A-sequence.
Case #3: 1 3 16 19 25 70 100 243 245 306
This is not an A-sequence.
Problem setter: S�rgio Queiroz de Medeiros

*/