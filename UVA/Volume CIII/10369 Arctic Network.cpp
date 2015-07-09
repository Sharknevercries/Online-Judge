/* 14020821	10369	Arctic Network	Accepted	C++	0.019	2014-08-11 08:05:51 */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct point{
	int x, y;
};
point D[MAX_N];
int dist[MAX_N];
bool V[MAX_N];
vector<int> E;
int distanceOf(int a, int b){
	return (D[a].x - D[b].x)*(D[a].x - D[b].x) + (D[a].y - D[b].y)*(D[a].y - D[b].y);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int S, P;
		scanf("%d%d", &S, &P);
		for (int i = 0; i < P; i++)
			scanf("%d%d", &D[i].x, &D[i].y);
		E.clear();
		memset(V, false, sizeof(V));
		for (int i = 0; i < P; i++)
			dist[i] = INF;
		dist[0] = 0;
		for (int i = 0; i < P; i++){
			int minDist = INF, minP = -1;
			for (int j = 0; j < P; j++)
				if (!V[j] && minDist > dist[j])
					minDist = dist[j], minP = j;
			V[minP] = true;
			E.push_back(minDist);
			for (int j = 0; j < P; j++)
				if (!V[j])
					dist[j] = min(dist[j], distanceOf(minP, j));
		}
		sort(E.begin(), E.end());
		printf("%.2lf\n", sqrt((double)E[P - S]));
	}
	return 0;
}
/*


Problem C: Arctic Network

The Department of National Defence (DND) wishes to connect several northern outposts by a wireless network. Two different communication technologies are to be used in establishing the network: every outpost will have a radio transceiver and some outposts will in addition have a satellite channel.
Any two outposts with a satellite channel can communicate via the satellite, regardless of their location. Otherwise, two outposts can communicate by radio only if the distance between them does not exceed D, which depends of the power of the transceivers. Higher power yields higher D but costs more. Due to purchasing and maintenance considerations, the transceivers at the outposts must be identical; that is, the value of D is the same for every pair of outposts.

Your job is to determine the minimum D required for the transceivers. There must be at least one communication path (direct or indirect) between every pair of outposts.

The first line of input contains N, the number of test cases. The first line of each test case contains 1 <= S <= 100, the number of satellite channels, and S < P <= 500, the number of outposts. P lines follow, giving the (x,y) coordinates of each outpost in km (coordinates are integers between 0 and 10,000). For each case, output should consist of a single line giving the minimum D required to connect the network. Output should be specified to 2 decimal points.

Sample Input

1
2 4
0 100
0 300
0 600
150 750
Sample Output

212.13

*/