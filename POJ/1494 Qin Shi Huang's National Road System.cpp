/* 14833277	1494	Qin Shi Huang's National Road System	Accepted	C++	0.442	2015-01-21 06:45:08 */
#include<bits\stdc++.h>
#define NONE -1
#define INF 2e9
using namespace std;
struct city{
	int x, y, p;
}C[1005];
double DP[1005];
int pre[1005];
bool V[1005];
double D[1005][1005];
double total;
int n;
double dist(city A, city B){
	return sqrt((double)(A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void prim(){
	memset(pre, NONE, sizeof(pre));
	memset(V, false, sizeof(V));
	for (int i = 0; i < n; i++)
		DP[i] = INF;
	DP[0] = 0;
	total = 0;
	for (int i = 0; i < n; i++){
		double MIN = INF;
		int k = -1;
		for (int j = 0; j < n; j++)
			if (!V[j] && DP[j] < MIN)
				MIN = DP[j], k = j;
		if (MIN == 2e9) break;
		V[k] = true;
		total += MIN;
		for (int j = 0; j < n; j++)
			if (!V[j] && DP[j] > D[k][j])
				DP[j] = D[k][j], pre[j] = k;
	}
}
void DFS(int u){
	V[u] = true;
	for (int i = 0; i < n; i++)
		if (!V[i] && pre[i] == u)
			DFS(i);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &C[i].x, &C[i].y, &C[i].p);
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				D[i][j] = D[j][i] = dist(C[i], C[j]);
		prim();
		double ans = -2e9;
		for (int i = 0; i < n; i++){
			if (pre[i] == NONE)	continue;
			double tmp = total - D[i][pre[i]];
			int a = NONE, b = NONE;
			memset(V, false, sizeof(V));
			DFS(i);
			for (int j = 0; j < n; j++)
				if (V[j])
					a = max(a, C[j].p);
				else
					b = max(b, C[j].p);
			ans = max(ans, (a + b) / tmp);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
/*

Problem Description
During the Warring States Period of ancient China(476 BC to 221 BC), there were seven kingdoms in China ---- they were Qi, Chu, Yan, Han, Zhao, Wei and Qin. Ying Zheng was the king of the kingdom Qin. Through 9 years of wars, he finally conquered all six other kingdoms and became the first emperor of a unified China in 221 BC. That was Qin dynasty ---- the first imperial dynasty of China(not to be confused with the Qing Dynasty, the last dynasty of China). So Ying Zheng named himself "Qin Shi Huang" because "Shi Huang" means "the first emperor" in Chinese.


Qin Shi Huang undertook gigantic projects, including the first version of the Great Wall of China, the now famous city-sized mausoleum guarded by a life-sized Terracotta Army, and a massive national road system. There is a story about the road system:
There were n cities in China and Qin Shi Huang wanted them all be connected by n-1 roads, in order that he could go to every city from the capital city Xianyang.
Although Qin Shi Huang was a tyrant, he wanted the total length of all roads to be minimum,so that the road system may not cost too many people's life. A daoshi (some kind of monk) named Xu Fu told Qin Shi Huang that he could build a road by magic and that magic road would cost no money and no labor. But Xu Fu could only build ONE magic road for Qin Shi Huang. So Qin Shi Huang had to decide where to build the magic road. Qin Shi Huang wanted the total length of all none magic roads to be as small as possible, but Xu Fu wanted the magic road to benefit as many people as possible ---- So Qin Shi Huang decided that the value of A/B (the ratio of A to B) must be the maximum, which A is the total population of the two cites connected by the magic road, and B is the total length of none magic roads.
Would you help Qin Shi Huang?
A city can be considered as a point, and a road can be considered as a line segment connecting two points.
 

Input
The first line contains an integer t meaning that there are t test cases(t <= 10).
For each test case:
The first line is an integer n meaning that there are n cities(2 < n <= 1000).
Then n lines follow. Each line contains three integers X, Y and P ( 0 <= X, Y <= 1000, 0 < P < 100000). (X, Y) is the coordinate of a city and P is the population of that city.
It is guaranteed that each city has a distinct location.
 

Output
For each test case, print a line indicating the above mentioned maximum ratio A/B. The result should be rounded to 2 digits after decimal point.
 

Sample Input
2
4
1 1 20
1 2 30
200 2 80
200 1 100
3
1 1 20
1 2 30
2 2 40
 

Sample Output
65.00
70.00
 

Source
2011 Asia Beijing Regional Contest


*/