/* 14188702	840502	1696	Accepted	160K	0MS	C++	2046B	2015-05-12 23:29:37 */
#include<bits\stdc++.h>
using namespace std;
// Vector
struct Vector{
	int id;
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	Vector operator + (const Vector &a) {
		return Vector(x + a.x, y + a.y);
	}
	Vector operator - (const Vector &a) {
		return Vector(x - a.x, y - a.y);
	}
	double operator * (const Vector &a) {
		return x * a.y - y * a.x;
	}
	Vector operator * (const double &a){
		return Vector(x*a, y*a);
	}
	double operator % (const Vector &a) {
		return x * a.x + y * a.y;
	}
	Vector operator / (double a){
		return Vector(x / a, y / a);
	}
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
};
Vector P[105], CH[105];
bool V[105];
int n, st;
bool cmp(Vector a, Vector b){
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%lf%lf", &P[i].id, &P[i].x, &P[i].y);
		memset(V, false, sizeof(V));
		int m = 0;
		sort(P, P + n, cmp);
		CH[m++] = Vector(-100, P[0].y);
		CH[m++] = P[0];
		V[P[0].id] = true;
		bool found;
		do{
			found = false;
			for (int i = 0; i < n; i++){
				if (!V[P[i].id]){
					while (m >= 2 && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
						V[CH[--m].id] = false;
					found = V[P[i].id] = true;
					CH[m++] = P[i];
				}
			}
			for (int i = n - 2, p = m + 1; i >= 0; i--){
				if (!V[P[i].id]){
					while (m >= p && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
						V[CH[--m].id] = false;
					found = V[P[i].id] = true;
					CH[m++] = P[i];
				}
			}
		} while (found);
		printf("%d", m - 1);
		for (int i = 1; i < m; i++)
			printf(" %d", CH[i].id);
		putchar('\n');
	}
	return 0;
}
/*

Space Ant
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 3333		Accepted: 2130
Description

The most exciting space discovery occurred at the end of the 20th century. In 1999, scientists traced down an ant-like creature in the planet Y1999 and called it M11. It has only one eye on the left side of its head and just three feet all on the right side of its body and suffers from three walking limitations:
It can not turn right due to its special body structure.
It leaves a red path while walking.
It hates to pass over a previously red colored path, and never does that.

The pictures transmitted by the Discovery space ship depicts that plants in the Y1999 grow in special points on the planet. Analysis of several thousands of the pictures have resulted in discovering a magic coordinate system governing the grow points of the plants. In this coordinate system with x and y axes, no two plants share the same x or y.
An M11 needs to eat exactly one plant in each day to stay alive. When it eats one plant, it remains there for the rest of the day with no move. Next day, it looks for another plant to go there and eat it. If it can not reach any other plant it dies by the end of the day. Notice that it can reach a plant in any distance.
The problem is to find a path for an M11 to let it live longest.
Input is a set of (x, y) coordinates of plants. Suppose A with the coordinates (xA, yA) is the plant with the least y-coordinate. M11 starts from point (0,yA) heading towards plant A. Notice that the solution path should not cross itself and all of the turns should be counter-clockwise. Also note that the solution may visit more than two plants located on a same straight line.

Input

The first line of the input is M, the number of test cases to be solved (1 <= M <= 10). For each test case, the first line is N, the number of plants in that test case (1 <= N <= 50), followed by N lines for each plant data. Each plant data consists of three integers: the first number is the unique plant index (1..N), followed by two positive integers x and y representing the coordinates of the plant. Plants are sorted by the increasing order on their indices in the input file. Suppose that the values of coordinates are at most 100.
Output

Output should have one separate line for the solution of each test case. A solution is the number of plants on the solution path, followed by the indices of visiting plants in the path in the order of their visits.
Sample Input

2
10
1 4 5
2 9 8
3 5 9
4 1 7
5 3 2
6 6 3
7 10 10
8 8 1
9 2 4
10 7 6
14
1 6 11
2 11 9
3 8 7
4 12 8
5 9 20
6 3 2
7 1 6
8 2 13
9 15 1
10 14 17
11 13 19
12 5 18
13 7 3
14 10 16
Sample Output

10 8 7 3 4 9 5 6 2 1 10
14 9 10 11 5 12 8 7 6 13 4 14 1 3 2
Source

Tehran 1999

*/