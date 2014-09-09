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
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
vector<int> E[MAX_N];
int pre[MAX_N];
int h1[MAX_N], h2[MAX_N];
int s1[MAX_N], s2[MAX_N];
void record(int x, int h, int target){
	if (h > h1[x]){
		h2[x] = h1[x], s2[x] = s1[x];
		h1[x] = h, s1[x] = target;
	}
	else if (h > h2[x])
		h2[x] = h, s2[x] = target;
}
void DFS1(int x){
	for (int i = 0; i < E[x].size(); i++){
		int target = E[x][i];
		if (target != pre[x]){
			pre[target] = x;
			DFS1(target);
			record(x, h1[target] + 1, target);
		}
	}
}
void DFS2(int x){
	if (x != pre[x]){
		int target = pre[x];
		if (s1[target] == x)
			record(x, h2[target] + 1, target);
		else
			record(x, h1[target] + 1, target);
	}
	for (int i = 0; i < E[x].size(); i++){
		int target = E[x][i];
		if (target != pre[x])
			DFS2(target);
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			E[i].clear();
		for (int i = 0; i < n - 1; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		memset(h1, 0, sizeof(h1));
		memset(h2, 0, sizeof(h2));
		pre[1] = 1;
		DFS1(1);
		DFS2(1);
		int height = 2e9, count = 0, sum = 0;
		for (int i = 1; i <= n; i++)
			height = min(height, h1[i]);
		for (int i = 1; i <= n; i++)
			if (height == h1[i])
				count++, sum += i;
		printf("%d %d\n", count, sum);
	}
	return 0;
}