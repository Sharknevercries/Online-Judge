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
#define MAX_N 50
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
	int t;
	scanf("%d", &t);
	while (t--){
		int n, S[MAX_N], sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", S + i), sum += S[i];
		int ans = sum;
		for (int i = 0, j = n - 1; i + 1 < j;){
			if (S[i] > S[j])
				ans += sum - S[j], sum -= S[j], j--;
			else
				ans += sum - S[i], sum -= S[i], i++;
		}
		printf("%d\n", ans);
	}
	return 0;
}