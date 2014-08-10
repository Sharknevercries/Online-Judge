/* 14012880	11080	Place the Guards	Accepted	C++	0.019	2014-08-09 10:16:28 */
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
#define MAX_N 300
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
vector<int> E[MAX_N];
int G[MAX_N];
int n, m;
int BFS(int source){
	queue<int> Q;
	int count[2] = { 0 };
	Q.push(source);
	G[source] = 0, count[0]++;
	while (!Q.empty()){
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < E[cur].size(); i++){
			int target = E[cur][i];
			if (G[target] != NONE && G[target] == G[cur])
				return NONE;
			if (G[target] == NONE)
				Q.push(target), count[1 - G[cur]]++;
			G[target] = 1 - G[cur];
		}
	}
	if (count[1] == 0) // a dot
		return 1;
	return min(count[0], count[1]);
}
int check(){
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (G[i] == NONE){
			int res = BFS(i);
			if (res == NONE)
				return NONE;
			ans += res;
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			E[i].clear();
		memset(G, NONE, sizeof(G));
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		printf("%d\n", check());
	}
	return 0;
}
/*

Problem G
Place the Guards
Input: Standard Input
Output: Standard Output

In the country of Ajabdesh there are some streets and junctions. Each street connects 2 junctions. The king of Ajabdesh wants to place some guards in some junctions so that all the junctions and streets can be guarded by them. A guard in a junction can guard all the junctions and streets adjacent to it. But the guards themselves are not gentle. If a street is guarded by multiple guards then they start fighting. So the king does not want the scenario where a street may be guarded by two guards. Given the information about the streets and junctions of Ajabdesh, help the king to find the minimum number of guards needed to guard all the junctions and streets of his country.

Input:
The first line of the input contains a single integer T (T<80) indicating the number of test cases. Each test case begins with 2 integers v (1 ≤ v ≤ 200) and e (0 ≤ e ≤ 10000.). v is the number of junctions and e is the number of streets. Each of the next e line contains 2 integer f and t denoting that there is a street between f and t. All the junctions are numbered from 0 to v-1.

Output:
For each test case output in a single line an integer m denoting the minimum number of guards needed to guard all the junctions and streets. Set the value of m as -1 if it is impossible to place the guards without fighting.

Sample Input                             Output for Sample Input
2
4 2
0 1
2 3
5 5
0 1
1 2
2 3
0 4
3 4

2
-1

Problemsetter: Abdullah-al-Mahmud
Special Thanks: Md. Kamruzzaman

*/