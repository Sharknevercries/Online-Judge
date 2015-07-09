/* 14078919	11294	Wedding	Accepted	C++	0.015	2014-08-22 10:32:57 */
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
#define MAX_N 1000
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
int V[MAX_N], sat[MAX_N];
void addEdge(int u, int v){
	E[u ^ 1].push_back(v), E[v ^ 1].push_back(u);
}
bool DFS(int i){
	if (V[i] == 1 || sat[i] == 1)return true;
	if (V[i] == 2 || sat[i] == 2)return false;
	V[i] = 1, V[i ^ 1] = 2;
	for (int j = 0; j < E[i].size(); j++)
		if (!DFS(E[i][j]))
			return false;
	return true;
}
void DFS_mark(int i){
	if (sat[i] == 1)return;
	sat[i] = 1, sat[i ^ 1] = 2;
	for (int j = 0; j < E[i].size(); j++)
		DFS_mark(E[i][j]);
}
bool solve(int n){
	memset(sat, NONE, sizeof(sat));
	for (int i = 0; i < n; i++){
		memset(V, NONE, sizeof(V));
		if (DFS(2 * i)){ DFS_mark(2 * i); continue; }
		memset(V, NONE, sizeof(V));
		if (DFS(2 * i + 1)){ DFS_mark(2 * i + 1); continue; }
		return false;
	}
	return true;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < 2 * n; i++)
			E[i].clear();
		for (int i = 0; i < m; i++){
			int a, c;
			char b, d;
			int v1, v2;
			// not (v1 and v2)
			scanf("%d%c%d%c", &a, &b, &c, &d);
			v1 = b == 'h' ? 2 * a : 2 * a + 1;
			v2 = d == 'h' ? 2 * c : 2 * c + 1;
			// not v1 or not v2
			addEdge(v1, v2);
		}
		E[0].push_back(1);

		if (solve(n)){
			for (int i = 1; i < n; i++){
				if (i > 1)putchar(' ');
				if (sat[2 * i] == sat[0])
					printf("%d%c", i, 'w');
				else
					printf("%d%c", i, 'h');
			}
			putchar('\n');
		}
		else
			puts("bad luck");
	}
	return 0;
}
/*


Problem E: Wedding

Up to thirty couples will attend a wedding feast, at which they will be seated on either side of a long table. The bride and groom sit at one end, opposite each other, and the bride wears an elaborate headdress that keeps her from seeing people on the same side as her. It is considered bad luck to have a husband and wife seated on the same side of the table. Additionally, there are several pairs of people conducting adulterous relationships (both different-sex and same-sex relationships are possible), and it is bad luck for the bride to see both members of such a pair. Your job is to arrange people at the table so as to avoid any bad luck.
The input consists of a number of test cases, followed by a line containing 0 0. Each test case gives n, the number of couples, followed by the number of adulterous pairs, followed by the pairs, in the form "4h 2w" (husband from couple 4, wife from couple 2), or "10w 4w", or "3h 1h". Couples are numbered from 0 to n-1 with the bride and groom being 0w and 0h. For each case, output a single line containing a list of the people that should be seated on the same side as the bride. If there are several solutions, any one will do. If there is no solution, output a line containing "bad luck".

Sample Input

10 6
3h 7h
5w 3w
7h 6w
8w 3w
7h 3w
2w 5h
0 0
Possible Output for Sample Input

1h 2h 3w 4h 5h 6h 7h 8h 9h
Prabhakar Ragde

*/