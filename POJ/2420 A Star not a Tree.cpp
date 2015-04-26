/* 14117335	840502	2420	Accepted	688K	16MS	G++	1174B	2015-04-22 19:15:27 */
#include<bits\stdc++.h>
using namespace std; 
struct Point{
	double x, y;
};
int n;
Point P[105];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
double dist(Point A, Point B){
	double dx = A.x - B.x;
	double dy = A.y - B.y;
	return sqrt(dx*dx + dy*dy);
}
double calDist(Point p){
	double res = 0;
	for (int i = 0; i < n; i++)
		res += dist(P[i], p);
	return res;
}
int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		Point p = P[0];
		double ans = calDist(p), d = 100;
		while (d > 0.2){
			bool flag;
			do{
				flag = false;
				for (int i = 0; i < 4; i++){
					Point q = p;
					double tmp;
					q.x += mx[i] * d, q.y += my[i] * d;
					if ((tmp = calDist(q)) < ans)
						p = q, ans = tmp, flag = true;
				}
			} while (flag);
			d /= 2;
		}
		printf("%d\n", (int)(ans + 0.5) * 100 / 100);
	}
	return 0;
}
/*

A Star not a Tree?
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 4046		Accepted: 1994
Description

Luke wants to upgrade his home computer network from 10mbs to 100mbs. His existing network uses 10base2 (coaxial) cables that allow you to connect any number of computers together in a linear arrangement. Luke is particulary proud that he solved a nasty NP-complete problem in order to minimize the total cable length.
Unfortunately, Luke cannot use his existing cabling. The 100mbs system uses 100baseT (twisted pair) cables. Each 100baseT cable connects only two devices: either two network cards or a network card and a hub. (A hub is an electronic device that interconnects several cables.) Luke has a choice: He can buy 2N-2 network cards and connect his N computers together by inserting one or more cards into each computer and connecting them all together. Or he can buy N network cards and a hub and connect each of his N computers to the hub. The first approach would require that Luke configure his operating system to forward network traffic. However, with the installation of Winux 2007.2, Luke discovered that network forwarding no longer worked. He couldn't figure out how to re-enable forwarding, and he had never heard of Prim or Kruskal, so he settled on the second approach: N network cards and a hub.

Luke lives in a loft and so is prepared to run the cables and place the hub anywhere. But he won't move his computers. He wants to minimize the total length of cable he must buy.
Input

The first line of input contains a positive integer N <= 100, the number of computers. N lines follow; each gives the (x,y) coordinates (in mm.) of a computer within the room. All coordinates are integers between 0 and 10,000.
Output

Output consists of one number, the total length of the cable segments, rounded to the nearest mm.
Sample Input

4
0 0
0 10000
10000 10000
10000 0
Sample Output

28284
Source

Waterloo Local 2002.01.26

*/