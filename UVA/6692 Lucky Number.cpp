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
#define MAX_N 1000005
#define MAX_M 1000
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
pair<int, int> S[MAX_N];
int n;
bool cmp(pair<int, int> A, pair<int, int>B){
	return A.first < B.first || (A.first == B.first && A.second < B.second);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			S[i] = make_pair(tmp, i);
		}
		sort(S, S + n, cmp);
		int L = INF, ans = 0;
		for (int i = 0, j = 0; i < n; i = j){
			for (; j < n && S[i].first == S[j].first; j++);
			ans = max(ans, S[j - 1].second - L);
			L = min(S[i].second, L);
		}
		printf("%d\n", ans);
	}
	return 0;
}