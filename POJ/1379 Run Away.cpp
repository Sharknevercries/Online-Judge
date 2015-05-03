/* 14069143	840502	1379	Accepted	216K	750MS	C++	1847B	2015-04-10 18:54:54 */
#include<bits\stdc++.h>
#define PI acos(-1.0)
using namespace std;
struct Point{
	double x, y;
};
Point P[1005];
Point ans[25];
double dist[25];
const int candidate = 20;
int n, m, p;
inline double calDist(Point a, Point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
double minDist(Point s){
	double res = 2e9;
	for (int i = 0; i < p; i++)
		res = min(res, calDist(s, P[i]));
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	srand(time(0));
	while (t--){
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 0; i < p; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		double d = max(n, m) / sqrt((double)p);
		double fix = 0.9;
		for (int i = 0; i < candidate; i++){
			ans[i].x = (rand() % 1000 + 1) / 1000. * n;
			ans[i].y = (rand() % 1000 + 1) / 1000. * m;
			dist[i] = minDist(ans[i]);
		}
		while (d > 0.01){
			for (int i = 0; i < candidate; i++){
				for (int j = 0; j < 30; j++){
					Point tmp = ans[i];
					double angle = rand() % 1000 / 1000. * PI * 2;
					tmp.x += d * cos(angle) * (rand() % 1000 / 1000.);
					tmp.y += d * sin(angle) * (rand() % 1000 / 1000.);
					if (tmp.x < 0 || tmp.y < 0 || tmp.x > n || tmp.y > m)	continue;
					double tmpDist = minDist(tmp);
					if (tmpDist > dist[i])
						ans[i] = tmp, dist[i] = tmpDist;
				}
			}
			d *= 0.9;
		}
		double maxDist = dist[0];
		int mi = 0;
		for (int i = 1; i < candidate; i++)
			if (maxDist < dist[i])
				mi = i, maxDist = dist[i];
		printf("The safest point is (%.1lf, %.1lf).\n", ans[mi].x, ans[mi].y);
	}
	return 0;
}
/*

Run Away
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 6710		Accepted: 2068
Description

One of the traps we will encounter in the Pyramid is located in the Large Room. A lot of small holes are drilled into the floor. They look completely harmless at the first sight. But when activated, they start to throw out very hot java, uh ... pardon, lava. Unfortunately, all known paths to the Center Room (where the Sarcophagus is) contain a trigger that activates the trap. The ACM were not able to avoid that. But they have carefully monitored the positions of all the holes. So it is important to find the place in the Large Room that has the maximal distance from all the holes. This place is the safest in the entire room and the archaeologist has to hide there.
Input

The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing three integers X, Y, M separated by space. The numbers satisfy conditions: 1 <= X,Y <=10000, 1 <= M <= 1000. The numbers X and Yindicate the dimensions of the Large Room which has a rectangular shape. The number M stands for the number of holes. Then exactly M lines follow, each containing two integer numbers Ui and Vi (0 <= Ui <= X, 0 <= Vi <= Y) indicating the coordinates of one hole. There may be several holes at the same position.
Output

Print exactly one line for each test case. The line should contain the sentence "The safest point is (P, Q)." where P and Qare the coordinates of the point in the room that has the maximum distance from the nearest hole, rounded to the nearest number with exactly one digit after the decimal point (0.05 rounds up to 0.1).
Sample Input

3
1000 50 1
10 10
100 100 4
10 10
10 90
90 10
90 90
3000 3000 4
1200 85
63 2500
2700 2650
2990 100
Sample Output

The safest point is (1000.0, 50.0).
The safest point is (50.0, 50.0).
The safest point is (1433.0, 1669.8).
Source

Central Europe 1999

*/