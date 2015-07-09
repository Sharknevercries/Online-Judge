/* 13953201	10020	Minimal coverage	Accepted	C++	0.092	2014-07-27 10:17:26 */
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
#define MAX_N 100005
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
struct segment{
	int L, R;
};
bool cmp(segment A, segment B){
	return A.L < B.L;
}
segment S[MAX_N];
vector<int> ans;
int n, m;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &m);
		n = 0;
		while (scanf("%d%d", &S[n].L, &S[n].R) == 2 && (S[n].L || S[n].R))
			n++;
		sort(S, S + n, cmp);
		ans.clear();

		int start = 0, maxR = 0, pos = NONE, cur = 0;
		while (cur < n && start < m){
			for (; cur < n; cur++){
				if (S[cur].L <= start){
					if (S[cur].R > maxR)
						maxR = S[cur].R, pos = cur;
				}
				else
					break;
			}
			if (pos != NONE)
				ans.push_back(pos), start = maxR, pos = NONE;
			else
				cur++;
		}
		if (pos != NONE)
			ans.push_back(pos);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d %d\n", S[ans[i]].L, S[ans[i]].R);
		if (t)
			putchar('\n');
	}
	return 0;
}
/*

Minimal coverage

The Problem

Given several segments of line (int the X axis) with coordinates [Li,Ri]. You are to choose the minimal amount of them, such they would completely cover the segment [0,M].

The Input

The first line is the number of test cases, followed by a blank line.

Each test case in the input should contains an integer M(1<=M<=5000), followed by pairs "Li Ri"(|Li|, |Ri|<=50000, i<=100000), each on a separate line. Each test case of input is terminated by pair "0 0".

Each test case will be separated by a single line.

The Output

For each test case, in the first line of output your programm should print the minimal number of line segments which can cover segment [0,M]. In the following lines, the coordinates of segments, sorted by their left end (Li), should be printed in the same format as in the input. Pair "0 0" should not be printed. If [0,M] can not be covered by given line segments, your programm should print "0"(without quotes).

Print a blank line between the outputs for two consecutive test cases.

Sample Input

2

1
-1 0
-5 -3
2 5
0 0

1
-1 0
0 1
0 0
Sample Output

0

1
0 1
Alex Gevak
September 10, 2000 (Revised 2-10-00, Antonio Sanchez)

*/