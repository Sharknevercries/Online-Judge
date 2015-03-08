/* 9835408	2015-02-14 19:50:50	Shark	514B - Han Solo and Lazer Gun	GNU C++	Accepted	30 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
struct Point{
	int x, y;
	bool check;
};
Point P[1005];
int main(){
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &P[i].x, &P[i].y), P[i].check = false;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (P[i].check)	continue;
		ans++;
		for (int j = 0; j < n; j++){
			if (P[j].check || i == j)	continue;
			if ((P[i].x - x)*(P[j].y - y) == (P[j].x - x)*(P[i].y - y))
				P[j].check = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*

B. Han Solo and Lazer Gun
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n Imperial stormtroopers on the field. The battle field is a plane with Cartesian coordinate system. Each stormtrooper is associated with his coordinates (x, y) on this plane.

Han Solo has the newest duplex lazer gun to fight these stormtroopers. It is situated at the point (x0, y0). In one shot it can can destroy all the stormtroopers, situated on some line that crosses point (x0, y0).

Your task is to determine what minimum number of shots Han Solo needs to defeat all the stormtroopers.

The gun is the newest invention, it shoots very quickly and even after a very large number of shots the stormtroopers don't have enough time to realize what's happening and change their location.

Input
The first line contains three integers n, x0 и y0 (1 ≤ n ≤ 1000,  - 104 ≤ x0, y0 ≤ 104) — the number of stormtroopers on the battle field and the coordinates of your gun.

Next n lines contain two integers each xi, yi ( - 104 ≤ xi, yi ≤ 104) — the coordinates of the stormtroopers on the battlefield. It is guaranteed that no stormtrooper stands at the same point with the gun. Multiple stormtroopers can stand at the same point.

Output
Print a single integer — the minimum number of shots Han Solo needs to destroy all the stormtroopers.

Sample test(s)
input
4 0 0
1 1
2 2
2 0
-1 -1
output
2
input
2 1 2
1 1
1 0
output
1
Note
Explanation to the first and second samples from the statement, respectively:

*/