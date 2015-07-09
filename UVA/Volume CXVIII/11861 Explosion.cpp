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
#define MAX_N 4005
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
struct condition{
	int a, b, c, d;
	condition(int x, int y, int z, int u){
		a = x, b = y, c = z, d = u;
	}
};
vector<condition> C;
vector<int> E[MAX_N];
int V[MAX_N], sat[MAX_N];
int must[MAX_N];
int n, m, k;
void addEdge(int u, int v){
	E[u].push_back(v);
}
bool DFS_try(int i){
	if (V[i] == 1 || sat[i] == 1)return true;
	if (V[i] == 2 || sat[i] == 2)return false;
	if (must[i] == 2)return false;
	V[i] = 1, V[i ^ 1] = 2;
	for (int j = 0; j < E[i].size(); j++)
		if (!DFS_try(E[i][j]))
			return false;
	return true;
}
void DFS_mark(int i){
	if (sat[i] == 1)return;
	sat[i] = 1, sat[i ^ 1] = 2;
	for (int j = 0; j < E[i].size(); j++)
		DFS_mark(E[i][j]);
}
bool DFS(int x){
	if (x == k){
		memset(sat, 0, sizeof(sat));
		for (int i = 0; i < n; i++){
			memset(V, 0, sizeof(V));
			if (DFS_try(2 * i)){ DFS_mark(2 * i); continue; }
			memset(V, 0, sizeof(V));
			if (DFS_try(2 * i + 1)){ DFS_mark(2 * i + 1); continue; }
			return false;
		}
		return true;
	}
	int a, b, c, d;
	a = C[x].a, b = C[x].b, c = C[x].c, d = C[x].d;
	if (a == 1){
		if (must[2 * b] == 1 || must[2 * c] == 1 || must[2 * d] == 1){
			if (DFS(x + 1))
				return true;
		}
		else if (must[2 * b] == 2 && must[2 * c] == 2 && must[2 * d] == 2)
			return false;
		else{
			if (must[2 * b] == NONE){ must[2 * b] = 1, must[2 * b + 1] = 2; if (DFS(x + 1))return true; must[2 * b] = must[2 * b + 1] = NONE; }
			if (must[2 * c] == NONE){ must[2 * c] = 1, must[2 * c + 1] = 2; if (DFS(x + 1))return true; must[2 * c] = must[2 * c + 1] = NONE; }
			if (must[2 * d] == NONE){ must[2 * d] = 1, must[2 * d + 1] = 2; if (DFS(x + 1))return true; must[2 * d] = must[2 * d + 1] = NONE; }
		}
	}
	else{
		if (must[2 * b] == 2 || must[2 * c] == 2 || must[2 * d] == 2){
			if (DFS(x + 1))
				return true;
		}
		else if (must[2 * b] == 1 && must[2 * c] == 1 && must[2 * d] == 1)
			return false;
		else{
			if (must[2 * b] == NONE){ must[2 * b] = 2, must[2 * b + 1] = 1; if (DFS(x + 1))return true; must[2 * b] = must[2 * b + 1] = NONE; }
			if (must[2 * c] == NONE){ must[2 * c] = 2, must[2 * c + 1] = 1; if (DFS(x + 1))return true; must[2 * c] = must[2 * c + 1] = NONE; }
			if (must[2 * d] == NONE){ must[2 * d] = 2, must[2 * d + 1] = 1; if (DFS(x + 1))return true; must[2 * d] = must[2 * d + 1] = NONE; }
		}
	}
	return false;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < 2 * n; i++)
			E[i].clear();
		C.clear();
		for (int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			b--, c--;
			b *= 2, c *= 2;
			switch (a){
			case 1:addEdge(b ^ 1, c); addEdge(c ^ 1, b); break;
			case 2:addEdge(b ^ 1, c ^ 1); break;
			case 3:addEdge(b, c ^ 1); addEdge(c, b ^ 1); break;
			case 4:addEdge(b, c ^ 1); addEdge(c, b ^ 1); 
				addEdge(b ^ 1, c); addEdge(c ^ 1, b); break;
			}
		}
		for (int i = 0; i < k; i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			b--, c--, d--;
			C.push_back(condition(a, b, c, d));
		}
		memset(must, NONE, sizeof(must));
		printf("Case %d:", c++);
		if (!DFS(0))
			printf(" Impossible");
		else{
			printf(" Possible");
			vector<int> ans;
			for (int i = 0; i < n; i++)
				if (sat[2 * i] == 1)
					ans.push_back(i);
			printf(" %d", ans.size());
			for (int i = 0; i < ans.size(); i++)
				printf(" %d", ans[i] + 1);
		}
		putchar('.');
		putchar('\n');
	}
	return 0;
}
