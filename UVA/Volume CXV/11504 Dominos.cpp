/* 14059317	11504	Dominos	Accepted	C++	0.415	2014-08-18 09:51:33 */
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
#define MAX_N 200000
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
int n, m;
bool V[MAX_N];
vector<int> F;
vector<int> E1[MAX_N], E2[MAX_N];
int T[MAX_N];
vector<int> tmp;
vector< vector<int> > G;
int degree[MAX_N];
void DFS1(int i){
	if (V[i])	return;
	V[i] = true;
	for (int j = 0; j < E1[i].size(); j++)
		DFS1(E1[i][j]);
	F.push_back(i);
}
void DFS2(int i){
	if (V[i])	return;
	V[i] = true;
	for (int j = 0; j < E2[i].size(); j++)
		DFS2(E2[i][j]);
	T[i] = G.size();
	tmp.push_back(i);
}
int main(){
	int c;
	scanf("%d", &c);
	while (c--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			E1[i].clear(), E2[i].clear();
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E1[a - 1].push_back(b - 1);
			E2[b - 1].push_back(a - 1);
		}
		G.clear();
		F.clear();
		memset(V, false, sizeof(V));
		for (int i = 0; i < n; i++)	DFS1(i);
		memset(V, false, sizeof(V));
		for (int i = n - 1; i >= 0; i--){
			tmp.clear(), DFS2(F[i]); 
			if (tmp.size() > 0)	G.push_back(tmp);
		}
		memset(degree, 0, sizeof(degree));
		for (int i = 0; i < G.size(); i++){
			for (int j = 0; j < G[i].size(); j++){
				for (int k = 0; k < E1[G[i][j]].size(); k++){
					int target = E1[G[i][j]][k];
					if (T[target] != i)
						degree[T[target]]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < G.size(); i++)
			if (degree[i] == 0)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem D: Dominos

Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line. However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.

Input Specification

The first line of input contains one integer specifying the number of test cases to follow. Each test case begins with a line containing two integers, each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n. Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Sample Input

1
3 2
1 2
2 3
Output Specification

For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Output for Sample Input

1
Ondřej Lhoták

*/