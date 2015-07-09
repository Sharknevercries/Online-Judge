/* 14239982	12485	Perfect Choir	Accepted	C++	0.032	2014-09-21 07:28:43 */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 10005
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int S[MAX_N], sum = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		for (int i = 0; i < n; i++)
			sum += S[i];
		if (sum % n != 0)
			puts("-1");
		else{
			int ans = 0, avg = sum / n;
			for (int i = 0; i < n; i++)
				ans += abs(avg - S[i]);
			ans /= 2;
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}
/*


Perfect Choir
The Conductor of the choir is planning to take part in the famous Brazilian Choir Week, and therefore she wants the choir to rehearse a new song, described as follows:
each member of the choir starts singing one note, and only changes the note when determined by the Conductor;
at the end of each bar measure, the Conductor determines that exactly two singers change the note they are singing: one singer starts to sing the note immediately above the note she sang, and another singer starts to sing the note immediately below the note she sang;
the song finishes at the end of the first bar measure in which all singers are singing the same note.
The Conductor already has several ideas of how to distribute the notes among choir members at the beginning of the song, in order to create the desired effect. However, she is worried about whether, given a note distribution for the singers, it is possible to reach the end of the song in the way she wants (all singing the same note). And, if that is possible, she wants to know the minimum number of bar measures the song can have. Can you help her?

Input

The input contains several test cases. The first line of a test case contains an integer N indicating the number of members of the choir. Notes are indicated by integers. The second line contains N integers, indicating the note that each singer must sing at the beginning of the song. Notes are given in non-decreasing order.
Output

For each test case, print a line containing a single integer indicating the minimum number of bar measures the song can have. If it is not possible to have all members singing the same note, then print the value `-1'.

Restrictions

2$ \le$N$ \le$104
-105$ \le$notei$ \le$105 for 0$ \le$i$ \le$N - 1
notei$ \le$notei+1 for 0$ \le$i$ \le$N - 2
Sample Input

3
1 2 3
4
3 6 9 12
6
1 2 3 4 5 723
5
10 10 10 10 10
Sample Output

2
-1
601
1

*/