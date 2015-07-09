/* 14031575	988	Many Paths, One Destination	Accepted	C++11	0.019	2014-08-13 06:52:03 */
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
#include<tuple>
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
#define MAX_N 1000
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
int W[MAX_N];
int n;
int BFS(int source){
	memset(W, 0, sizeof(W));
	queue<int> Q;
	Q.push(source);
	W[source] = 1;
	while (!Q.empty()){
		int cur = Q.front();	Q.pop();
		for (int i = 0; i < E[cur].size(); i++){
			int target = E[cur][i];
			in[target]--;
			W[target] += W[cur];
			if (in[target] == 0)
				Q.push(target);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		if (E[i].size() == 0)
			res += W[i];
	return res;
}
int main(){
	bool first = true;
	while (scanf("%d", &n) == 1){
		if (!first)	putchar('\n');
		first = false;
		memset(in, 0, sizeof(in));
		for (int i = 0; i < n; i++)
			E[i].clear();
		for (int i = 0; i < n; i++){
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++){
				int a;
				scanf("%d", &a);
				E[i].push_back(a);
				in[a]++;
			}
		}
		printf("%d\n", BFS(0));
	}
	return 0;
}
/*

http://uva.onlinejudge.org/external/9/988.pdf

*/