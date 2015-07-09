/* 14016156	11695	Flight Planning	Accepted	C++	5.635	2014-08-10 06:17:42 */
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
#define MAX_N 2505
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
int n;
int cutA, cutB;
int conA, conB;
int minDist;
int p[MAX_N];
int h1[MAX_N], h2[MAX_N];
int s1[MAX_N], s2[MAX_N];
bool V[MAX_N];
void record(int x, int h, int child){
	if (h > h1[x]){
		h2[x] = h1[x], s2[x] = s1[x];
		h1[x] = h, s1[x] = child;
	}
	else if (h > h2[x])
		h2[x] = h, s2[x] = child;
}
void DFS1(int x){
	V[x] = true;
	for (int i = 0; i < E[x].size(); i++){
		int target = E[x][i];
		if (target != p[x]){
			p[target] = x;
			DFS1(target);
			record(x, h1[target] + 1, target);
		}
	}
}
void DFS2(int x, bool isRoot){
	V[x] = true;
	if (!isRoot){
		int target = p[x];
		if (s1[target] == x)
			record(x, h2[target] + 1, target);
		else
			record(x, h1[target] + 1, target);
	}
	for (int i = 0; i < E[x].size(); i++){
		int target = E[x][i];
		if (target != p[x])
			DFS2(target, false);
	}
}
void remove(int a, int b){
	memset(h1, 0, sizeof(h1));
	memset(h2, 0, sizeof(h2));
	memset(p, NONE, sizeof(p));
	memset(V, false, sizeof(V));
	int rootA = 0, rootB = 0, dist = 0;
	h1[0] = h2[0] = INF;
	p[a] = b;
	DFS1(a);
	DFS2(a, true);
	for (int i = 1; i <= n; i++)
		if (V[i] && h1[rootA] > h1[i])
			rootA = i;
	memset(V, false, sizeof(V));
	p[b] = a;
	DFS1(b);
	DFS2(b, true);
	for (int i = 1; i <= n; i++)
		if (V[i] && h1[rootB] > h1[i])
			rootB = i;
	dist = max(dist, h1[rootA] + h1[rootB] + 1);
	dist = max(dist, h1[rootA] + h2[rootA]);
	dist = max(dist, h1[rootB] + h2[rootB]);
	if (dist < minDist)
		minDist = dist, cutA = a, cutB = b, conA = rootA, conB = rootB;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		for (int i = 1; i <= n; i++)
			E[i].clear();
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		minDist = INF;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < E[i].size(); j++)
				if (i < E[i][j])
					remove(i, E[i][j]);
		printf("%d\n", minDist);
		printf("%d %d\n", cutA, cutB);
		printf("%d %d\n", conA, conB);
	}
	return 0;
}
/*

Problem G - Flight Planning

Time limit: X seconds

The airline company NCPC Airways has flights to and from n cities, numbered from 1 to n, around the entire world. However, they only have n - 1 different flights (operating in both directions), so in order to travel between any two cities you might have to take several flights. In fact, since the management has made sure that it's possible to travel between any pair of cities, there is exactly one set of flights a passenger have to take in order to travel between two cities (assuming you want to use the same airline).

Recently many of NCPC Airways frequent flyers have complained that they have had to change flights too often to get to their final destination. Since NCPC Airways doesn't want to loose their customers to other airline companies, but still keep the nice property of their flights, they have decided to cancel one of their current flights and replace it with another flight. Help the company by writing a program which finds the best flight to cancel and the best new flight to add so that the maximum number of flight changes a passenger might have to make when travelling between any pair of cities in which NCPC Airways operates is minimized.

The input will be constructed so that it is always possible to improve the maximum number of flight changes needed.

Input

The first line of the input file contains an integer N (N<20) which denotes the total number of test cases. The description of each test case is given below:

The first line of input for each test case contains the integer n (4 ≤ n ≤ 2500), the number of cities NCPC Airways operates in. Then follow n - 1 lines specifying the flights. Each flight is given as a pair of cities a and b (1 ≤ a, b ≤ n).

Output

For each test case print three lines of output. The first line should contain an integer, the minimum number of flights needed to take when travelling between any pair of cities after changing one of the flights. The second line should contain two integers, specifying the two cities between which the flight should be canceled. The third line should contain two integers, specifying the two cities where a new flight should be added.

If there are more than one optimal solution, any one of them will be accepted.

Sample Input

2
4
1 2
2 3
3 4
14
1 2
1 8
2 3
2 4
8 9
8 10
8 11
4 5
4 6
4 7
10 12
10 13
13 14
Sample Output

2
3 4
2 4
5
1 8
2 10
The 2009 ACM Nordic Collegiate Programming Contest

*/