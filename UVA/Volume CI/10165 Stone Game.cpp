/* 14285099	10165	Stone Game	Accepted	C++	0.009	2014-09-30 04:10:28 */
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
#define MAX_N 1000000
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
int S[MAX_N];
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		int ans = S[0];
		for (int i = 1; i < n; i++)
			ans ^= S[i];
		puts(ans == 0 ? "No" : "Yes");
	}
	return 0;
}
/*


Problem E.Stone Game

Background

Jack and Jim are playing an interesting stone game. At the beginning of the game there are N pile(s)of stones. Each pile has Pi (I=1..N, 1<=Pi<=2*109) stones. They take turns to take away some of the stones. There are some rules: they must choose one pile at a time. They can take away any number of stones except 0, of course, not bigger than the number of stones in the pile. One who takes away the last stone will win the game. Jack is the first to fetch the match, and Jim is the second. Now Jack asks you for help, to decide while facing some initializations whether he is sure to win or not.

Input

The input file contains several scenarios. Each of them consists of 2 lines:
The first line consists of a number N. The second line consists of N numbers, meaning Pi (I=1..M). There is only one space between two border numbers.
The input file is ended with N=0.

Output

For each scenario, print a line containing ．Yes・ if he is sure to win, or ．No・ otherwise.

Sample Input

1
100
3
1 5 1
4
1 1 1 1
0

Sample Output

Yes
Yes
No

*/