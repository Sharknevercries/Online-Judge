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
#define MAX_N 100
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
	printf("%d\n", t);
	while (t--){
		int n;
		scanf("%d", &n);
		int S[MAX_N][MAX_N] = { 0 };
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &S[i][j]);
		for (int j = 1; j <= n; j++){
			int s = S[j][j];
			for (int k = 1; k < j; k++)
				s -= S[j][k] * S[j][k];
			S[j][j] = sqrt((double)s);
			for (int i = j + 1; i <= n; i++){
				int s = S[i][j];
				for (int k = 1; k <= j - 1; k++)
					s -= S[i][k] * S[j][k];
				S[i][j] = s / S[j][j];
			}
		}
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (j > i)
					S[i][j] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (j > 1)	putchar(' ');
				printf("%d",S[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}