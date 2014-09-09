/* 7450901	2014-08-15 11:38:25	Shark	C - New Year Bonus Grant	GNU C++	Accepted	498 ms	20300 KB */
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
#define MAX_N 500001
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
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
int in[MAX_N];
bool V[MAX_N], used[MAX_N]; 
vector<int> ans;
int main(){
	freopen("grant.in", "r", stdin);
	freopen("grant.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1){
		memset(V, 0, sizeof(V));
		ans.clear();
		for (int i = 1; i <= n; i++)
			E[i].clear();
		for (int i = 2; i <= n; i++){
			int a;
			scanf("%d", &a);
			E[i].push_back(a);
			in[a]++;
		}
		queue<int> Q;
		for (int i = 1; i <= n; i++)
			if (in[i] == 0)
				Q.push(i);
		while (!Q.empty()){
			int cur = Q.front();	Q.pop();
			V[cur] = true;
			for (int i = 0; i < E[cur].size(); i++){
				int target = E[cur][i];
				if (V[target])	continue;
				in[target]--;
				if (in[target] == 0 && !V[target])
					Q.push(target);
				if (!used[target] && !used[cur]){
					ans.push_back(cur);
					used[target] = used[cur] = true;
				}
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size() * 1000);
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}