/* 14178664	11368	Nested Dolls	Accepted	C++	0.092	2014-09-10 15:34:38 */
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
#define MAX_N 20005
#define MAX_M 10000
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
struct doll{
	int w, h;
};
doll D[MAX_N];
bool cmp(doll A, doll B){
	return A.w > B.w || (A.w == B.w&&A.h < B.h);
}
vector<int> LDS;
int search(int h){
	int L = 0, R = LDS.size() - 1;
	while (L < R){
		int mid = (L + R) / 2;
		if (LDS[mid] <= h)
			L = mid + 1;
		else
			R = mid;
	}
	return L ;
}
int main(){
	int n, t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &D[i].w, &D[i].h);
		sort(D, D + n, cmp);
		LDS.clear();
		LDS.push_back(D[0].h);
		for (int i = 1; i < n; i++){
			int pos = search(D[i].h);
			if (LDS[pos]>D[i].h)
				LDS[pos] = D[i].h;
			else
				LDS.push_back(D[i].h);
		}
		printf("%d\n", LDS.size());
	}
	return 0;
}
/*


G: Nested Dolls
Dilworth is the world's most prominent collector of Russian nested dolls: he literally has thousands of them! You know, the wooden hollow dolls of different sizes of which the smallest doll is contained in the second smallest, and this doll is in turn contained in the next one and so forth. One day he wonders if there is another way of nesting them so he will end up with fewer nested dolls? After all, that would make his collection even more magnificent! He unpacks each nested doll and measures the width and height of each contained doll. A doll with width w1 and height h1 will fit in another doll of width w2 and height h2 if and only if w1 < w2 and h1 < h2 . Can you help him calculate the smallest number of nested dolls possible to assemble from his massive list of measurements?

\epsfbox{p11368.eps}
Input

On the first line of input is a single positive integer 1$ \le$t$ \le$20 specifying the number of test cases to follow. Each test case begins with a positive integer 1$ \le$m$ \le$20000 on a line of itself telling the number of dolls in the test case. Next follow 2m positive integers w1, h1, w2, h2,..., wm, hm , where wi is the width and hi is the height of doll number i . 1$ \le$wi, hi$ \le$10000 for all i .

Output

For each test case there should be one line of output containing the minimum number of nested dolls possible.

Sample Input

4
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
Sample Output

1
2
3
2

*/