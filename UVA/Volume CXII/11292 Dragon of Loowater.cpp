/* 14007848	11292	Dragon of Loowater	Accepted	C++	0.036	2014-08-08 07:57:28 */
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
#define MAX_N 30000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
// main
int n, m;
int A[MAX_N], B[MAX_N];
bool search(int &ans){
	int i, j;
	for (ans = i = j = 0; i < n && j < m;)
		if (A[i] > B[j])
			j++;
		else
			ans += B[j], i++, j++;
	return i >= n;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2 && n  && m){
		for (int i = 0; i < n; i++)
			scanf("%d", A + i);
		for (int i = 0; i < m; i++)
			scanf("%d", B + i);
		sort(A, A + n);
		sort(B, B + m);
		int ans = 0;

		if (search(ans))
			printf("%d\n", ans);
		else
			puts("Loowater is doomed!");
	}
	return 0;
}
/*


Problem C: The Dragon of Loowater

Once upon a time, in the Kingdom of Loowater, a minor nuisance turned into a major problem.
The shores of Rellau Creek in central Loowater had always been a prime breeding ground for geese. Due to the lack of predators, the geese population was out of control. The people of Loowater mostly kept clear of the geese. Occasionally, a goose would attack one of the people, and perhaps bite off a finger or two, but in general, the people tolerated the geese as a minor nuisance.

One day, a freak mutation occurred, and one of the geese spawned a multi-headed fire-breathing dragon. When the dragon grew up, he threatened to burn the Kingdom of Loowater to a crisp. Loowater had a major problem. The king was alarmed, and called on his knights to slay the dragon and save the kingdom.

The knights explained: "To slay the dragon, we must chop off all its heads. Each knight can chop off one of the dragon's heads. The heads of the dragon are of different sizes. In order to chop off a head, a knight must be at least as tall as the diameter of the head. The knights' union demands that for chopping off a head, a knight must be paid a wage equal to one gold coin for each centimetre of the knight's height."

Would there be enough knights to defeat the dragon? The king called on his advisors to help him decide how many and which knights to hire. After having lost a lot of money building Mir Park, the king wanted to minimize the expense of slaying the dragon. As one of the advisors, your job was to help the king. You took it very seriously: if you failed, you and the whole kingdom would be burnt to a crisp!

Input Specification:

The input contains several test cases. The first line of each test case contains two integers between 1 and 20000 inclusive, indicating the number n of heads that the dragon has, and the number m of knights in the kingdom. The next n lines each contain an integer, and give the diameters of the dragon's heads, in centimetres. The following m lines each contain an integer, and specify the heights of the knights of Loowater, also in centimetres.

The last test case is followed by a line containing:

0 0
Output Specification:

For each test case, output a line containing the minimum number of gold coins that the king needs to pay to slay the dragon. If it is not possible for the knights of Loowater to slay the dragon, output the line:

Loowater is doomed!
Sample Input:

2 3
5
4
7
8
4
2 1
5
5
10
0 0
Output for Sample Input:

11
Loowater is doomed!
Ondřej Lhoták

*/