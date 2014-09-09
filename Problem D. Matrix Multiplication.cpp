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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 100005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int main(){
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n, m, S[MAX_N] = { 0 };
	lli ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		S[a]++, S[b]++;
	}
	for (int i = 1; i <= n; i++)
		ans += S[i] * S[i];
	printf("%lld\n", ans);
	return 0;
}