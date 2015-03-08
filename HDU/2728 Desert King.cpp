/* 13799861	840502	2728	Accepted	8048K	2391MS	C++	1493B	2015-01-21 15:34:39 */
#include<bits\stdc++.h>
#define INF 2e9
#define NONE -1
using namespace std;
struct town{
	int x, y, z;
};
town T[1005];
double D[1005][1005];
double DP[1005];
bool V[1005];
int n;
double dist(town A, town B){
	return sqrt((double)(A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
double prim(){
	memset(V, false, sizeof(V));
	for (int i = 0; i < n; i++)
		DP[i] = INF;
	DP[0] = 0;
	double res = 0;
	for (int i = 0; i < n; i++){
		double MIN = INF;
		int k = NONE;
		for (int j = 0; j < n; j++)
			if (!V[j] && MIN > DP[j])
				MIN = DP[j], k = j;
		V[k] = true, res += MIN;
		for (int j = 0; j < n; j++)
			if (!V[j] && DP[j] > D[k][j])
				DP[j] = D[k][j];
	}
	return res;
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &T[i].x, &T[i].y, &T[i].z);
		double L = 0, R = 100, mid;
		while (L <= R){
			mid = (L + R) / 2;
			for (int i = 0; i < n; i++)
				for (int j = i; j < n; j++)
					D[i][j] = D[j][i] = fabs((double)T[i].z - T[j].z) - mid * dist(T[i], T[j]);
			double res = prim();
			if (fabs(res) <= 0.0005)
				break;
			else if (res > 0.0005)
				L = mid;
			else
				R = mid;
		}
		printf("%.3lf\n", mid);
	}
	return 0;
}
/*

Desert King
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 21362		Accepted: 5975
Description

David the Great has just become the king of a desert country. To win the respect of his people, he decided to build channels all over his country to bring water to every village. Villages which are connected to his capital village will be watered. As the dominate ruler and the symbol of wisdom in the country, he needs to build the channels in a most elegant way.

After days of study, he finally figured his plan out. He wanted the average cost of each mile of the channels to be minimized. In other words, the ratio of the overall cost of the channels to the total length must be minimized. He just needs to build the necessary channels to bring water to all the villages, which means there will be only one way to connect each village to the capital.

His engineers surveyed the country and recorded the position and altitude of each village. All the channels must go straight between two villages and be built horizontally. Since every two villages are at different altitudes, they concluded that each channel between two villages needed a vertical water lifter, which can lift water up or let water flow down. The length of the channel is the horizontal distance between the two villages. The cost of the channel is the height of the lifter. You should notice that each village is at a different altitude, and different channels can't share a lifter. Channels can intersect safely and no three villages are on the same line.

As King David's prime scientist and programmer, you are asked to find out the best solution to build the channels.
Input

There are several test cases. Each test case starts with a line containing a number N (2 <= N <= 1000), which is the number of villages. Each of the following N lines contains three integers, x, y and z (0 <= x, y < 10000, 0 <= z < 10000000). (x, y) is the position of the village and z is the altitude. The first village is the capital. A test case with N = 0 ends the input, and should not be processed.
Output

For each test case, output one line containing a decimal number, which is the minimum ratio of overall cost of the channels to the total length. This number should be rounded three digits after the decimal point.
Sample Input

4
0 0 0
0 1 1
1 1 2
1 0 3
0
Sample Output

1.000
Source

Beijing 2005

*/