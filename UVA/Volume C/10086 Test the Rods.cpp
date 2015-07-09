/* 13903731	10086	Test the Rods	Accepted	C++	0.182	2014-07-18 14:18:16 */
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
#define MAX_N 301
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int DP[MAX_N][MAX_N];
int record[MAX_N][MAX_N][2];
int main(){
	int t1, t2;
	while (scanf("%d%d", &t1, &t2) == 2 && t1 + t2){
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				DP[i][j] = INF, record[i][j][0] = record[i][j][1] = -1;
		DP[0][0] = 0;

		int n, total = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int m, A[MAX_N] = { 0 }, B[MAX_N] = { 0 };
			scanf("%d", &m);
			for (int j = 1; j <= m; j++)
				scanf("%d", A + j);
			for (int j = 1; j <= m; j++)
				scanf("%d", B + j);
			for (int j = 0; j <= m; j++){
				for (int k = 0; k <= total; k++){
					if (j + k <= t1 && total + m - j - k <= t2){
						if (DP[j + k][total + m - j - k] > DP[k][total - k] + A[j] + B[m - j]){
							DP[j + k][total + m - j - k] = DP[k][total - k] + A[j] + B[m - j];
							record[j + k][total + m - j - k][0] = k;
							record[j + k][total + m - j - k][1] = total - k;
						}
					}
				}
			}
			total += m;
		}
		printf("%d\n", DP[t1][t2]);
		int res[MAX_N], p = t1, q = t2;
		for (int i = n - 1; i >= 0; i--){
			int s = p, t = q;
			res[i] = p - record[p][q][0];
			p = record[s][t][0];
			q = record[s][t][1];
		}
		for (int i = 0; i < n; i++){
			if (i > 0)	putchar(' ');
			printf("%d", res[i]);
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
/*

Problem B
Test the Rods
Input: standard input
Output: standard output

National Construction and Project Centre (NCPC) and the Bureau of Civil Engineering Works (BCEW) have been given the authority of testing and certifying the quality of rods used in construction works in the country. The Get and Do construction company has recently got a contract of construction at different sites of the country. Before the construction can start they want to get the rods from their n sites tested either at NCPC or at BCEW. Get and Do has got the permission of testing T1 rods at NCPC and T2 at BCEW. There are mi samples at site i (1 <= i <= n). Sum total of these samples over all the n sites is just equal to (T1 + T2). The cost of testing j items from site i at NCPC is Ci,j,1 and that of testing at BCEW is Ci,j,2. Write a program to find a minimum cost testing schedule for the Get and Do company.

Input

The input may contain multiple test cases. The first line of each test case contains the two nonnegative integers T1 and T2 (1 <= T1 + T2 <= 300). The next line contains n (1 <= n <= 30). Then follow 3n lines. For 1 <= i <= n, line (3i - 2) contains the value of mi (1 <= mi <= 20), line (3i - 1) contains mi nonnegative integers Ci,j,1 (1 <= j <= mi) and line 3i contains mi nonnegative integers Ci,j,2 (1 <= j <= mi). You may assume that 0 <= Ci,j,1, Ci,j,2 <= 1000.

A test case containing two zeros for T1 and T2 terminates the input, and this case must not be processed.

Output

For each test case in the input print two lines. The first line contains an integer giving the minimum cost for testing all the samples at NCPC and BCEW. The next line contains n integers with two consecutive integers separated by a single space. The i-th integer gives the numbers of samples from site i that are tested at NCPC (it is implicit that the rest are tested at BCEW). Note that the second output line is not unique, and hence any optimal testing schedule is acceptable. Print a blank line after the outputs of each test case.

Sample Input

10 12
5
5
10 30 70 150 310
10 20 40 60 180
7
30 60 90 120 160 200 240
20 60 100 130 160 200 240
4
40 60 80 100
30 70 100 120
3
60 120 180
20 50 90
3
30 70 100
30 70 100
0 0

Sample Output

580
1 3 4 0 2

_________________________________________________________________________________________
Rezaul Alam Chowdhury

"Two things are infinite. One is the universe, the other is human stupidity and I am not sure about the former."

*/