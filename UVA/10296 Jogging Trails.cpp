/* 13871474	10296	Jogging Trails	Accepted	C++	0.023	2014-07-12 10:55:28 */
/*

Template By Shark

*/
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
#define MAX_N 20
#define MAX_M 1000
#define INF 1e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
int DP[1 << MAX_N];
bool V[1 << MAX_N];
int dist[MAX_N][MAX_N];
int degree[MAX_N];
int odd[MAX_N], oddCount;
int n, m, sum;
void Floyd(){
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int MCM(int s){
	if (s == 0)	return 0;
	if (V[s])	return DP[s];
	for (int i = 0; i < oddCount; i++){
		if (s & (1 << i)){
			for (int j = i + 1; j < oddCount; j++){
				if (s & (1 << j)){
					int prev = s ^ (1 << i) ^ (1 << j);
					DP[s] = min(DP[s], MCM(prev) + dist[odd[i]][odd[j]]);
				}
			}
		}
	}
	V[s] = true;
	return DP[s];
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		scanf("%d", &m);
		memset(degree, 0, sizeof(degree));
		sum = oddCount = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = INF;
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			a--, b--;
			dist[a][b] = min(dist[a][b], w);
			dist[b][a] = min(dist[b][a], w);
			degree[a]++, degree[b]++;
			sum += w;
		}
		for (int i = 0; i < n; i++)
			if ((degree[i] & 1) == 1)
				odd[oddCount++] = i;
		for (int i = 0; i < (1 << oddCount); i++)
			DP[i] = INF;
		memset(V, false, sizeof(V));
		Floyd();
		printf("%d\n", sum + MCM((1 << oddCount) - 1));
	}
	return 0;
}
/*

Problem B: Jogging Trails

Gord is training for a marathon. Behind his house is a park with a large network of jogging trails connecting water stations. Gord wants to find the shortest jogging route that travels along every trail at least once.
Input consists of several test cases. The first line of input for each case contains two positive integers: n <= 15, the number of water stations, and m < 1000, the number of trails. For each trail, there is one subsequent line of input containing three positive integers: the first two, between 1 and n, indicating the water stations at the end points of the trail; the third indicates the length of the trail, in cubits. There may be more than one trail between any two stations; each different trail is given only once in the input; each trail can be travelled in either direction. It is possible to reach any trail from any other trail by visiting a sequence of water stations connected by trails. Gord's route may start at any water station, and must end at the same station. A single line containing 0 follows the last test case.

For each case, there should be one line of output giving the length of Gord's jogging route.

Sample Input

4 5
1 2 3
2 3 4
3 4 5
1 4 10
1 3 12
0
Output for Sample Input

41

*/