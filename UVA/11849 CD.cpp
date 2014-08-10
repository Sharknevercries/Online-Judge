/* 13992819	11849	CD	Accepted	C++	0.542	2014-08-05 06:38:00 */
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
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		queue<int> Q;
		int ans = 0;
		for (int i = 0; i < n; i++){
			int a;	scanf("%d", &a);
			Q.push(a);
		}
		for (int i = 0; i < m; i++){
			int b;	scanf("%d", &b);
			while (!Q.empty()){
				if (Q.front() == b){
					ans++, Q.pop();
					break;
				}
				else if (Q.front() > b)
					break;
				else
					Q.pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem A: CD

Jack and Jill have decided to sell some of their Compact Discs, while they still have some value. They have decided to sell one of each of the CD titles that they both own. How many CDs can Jack and Jill sell?
Neither Jack nor Jill owns more than one copy of each CD.

Input Specification

The input consists of a sequence of test cases. The first line of each test case contains two non-negative integers N and M, each at most one million, specifying the number of CDs owned by Jack and by Jill, respectively. This line is followed by N lines listing the catalog numbers of the CDs owned by Jack in increasing order, and M more lines listing the catalog numbers of the CDs owned by Jill in increasing order. Each catalog number is a positive integer no greater than one billion. The input is terminated by a line containing two zeros. This last line is not a test case and should not be processed.
Sample Input

3 3
1
2
3
1
2
4
0 0
Output Specification

For each test case, output a line containing one integer, the number of CDs that Jack and Jill both own.
Output for Sample Input

2
Gordon Cormack

*/