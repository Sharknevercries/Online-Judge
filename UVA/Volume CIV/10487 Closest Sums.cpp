/* 13997357	10487	Closest Sums	Accepted	C++	0.066	2014-08-06 07:09:41 */
/* Template By Shark */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n, m, c = 1;
	while (scanf("%d", &n) == 1 && n){
		int S[MAX_N];
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		scanf("%d", &m);
		printf("Case %d:\n", c++);
		for (int i = 0; i < m; i++){
			int target, gap = INF, sum;
			scanf("%d", &target);
			for (int j = 0; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (abs(target - S[j] - S[k]) < gap)
						gap = abs(target - S[j] - S[k]), sum = S[j] + S[k];
			printf("Closest sum to %d is %d.\n", target, sum);
		}
	}
	return 0;
}
/*

Problem D
Closest Sums
Input: standard input
Output: standard output
Time Limit: 3 seconds

Given is a set of integers and then a sequence of queries. A query gives you a number and asks to find a sum of two distinct numbers from the set, which is closest to the query number.
Input

Input contains multiple cases.

Each case starts with an integer n (1<n<=1000), which indicates, how many numbers are in the set of integer. Next n lines contain n numbers. Of course there is only one number in a single line. The next line contains a positive integer m giving the number of queries, 0 < m < 25. The next m lines contain an integer of the query, one per line.

Input is terminated by a case whose n=0. Surely, this case needs no processing.

Output

Output should be organized as in the sample below. For each query output one line giving the query value and the closest sum in the format as in the sample. Inputs will be such that no ties will occur.

Sample input

5
3
12
17
33
34
3
1
51
30
3
1
2
3
3
1
2
3
3
1
2
3
3
4
5
6
0
Sample output

Case 1:
Closest sum to 1 is 15.
Closest sum to 51 is 51.
Closest sum to 30 is 29.
Case 2:
Closest sum to 1 is 3.
Closest sum to 2 is 3.
Closest sum to 3 is 3.
Case 3:
Closest sum to 4 is 4.
Closest sum to 5 is 5.
Closest sum to 6 is 5.
Piotr Rudnicki

*/