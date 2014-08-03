/* 13870977	10911	Forming Quiz Teams	Accepted	C++	0.385	2014-07-12 08:26:04 */
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
#define INF 2e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
struct point{
	int x, y;
};
point pos[MAX_N];
double dist[MAX_N][MAX_N];
double DP[1 << MAX_N];
bool V[1 << MAX_N];
int n, c = 1;
double distance(point A, point B){
	return sqrt((double)(A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
double MCM(int s){
	if (s == 0)	return 0;
	if (V[s])	return DP[s];
	for (int i = 0; i < 2 * n; i++){
		if (s & (1 << i)){
			for (int j = i + 1; j < 2 * n; j++){
				if (s & (1 << j)){
					int prev = s ^ (1 << i) ^ (1 << j);
					DP[s] = min(DP[s], MCM(prev) + dist[i][j]);
				}
			}
		}
	}
	V[s] = true;
	return DP[s];
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		memset(V, false, sizeof(V));
		for (int i = 0; i < (1 << (2 * n)); i++)
			DP[i] = INF;
		for (int i = 0; i < 2 * n; i++){
			char T[1000];
			scanf("%s%d%d", T, &pos[i].x, &pos[i].y);
		}
		for (int i = 0; i < 2 * n; i++)
			for (int j = 0; j < 2 * n; j++)
				dist[i][j] = ::distance(pos[i], pos[j]);

		printf("Case %d: %.2lf\n", c++, MCM((1 << (2 * n)) - 1));
	}
	return 0;
}
/*

4th IIUC Inter-University Programming Contest, 2005

G

Forming Quiz Teams

Input: standard input
Output: standard output

Problemsetter: Sohel Hafiz

You have been given the job of forming the quiz teams for the next ‘MCA CPCI Quiz Championship’. There are 2*N students interested to participate and you have to form N teams, each team consisting of two members. Since the members have to practice together, all the students want their member’s house as near as possible. Let x1 be the distance between the houses of group 1, x2 be the distance between the houses of group 2 and so on. You have to make sure the summation (x1 + x2 + x3 + …. + xn) is minimized.

Input

There will be many cases in the input file. Each case starts with an integer N (N ≤ 8). The next 2*N lines will given the information of the students. Each line starts with the student’s name, followed by the x coordinate and then the y coordinate. Both x, y are integers in the range 0 to 1000. Students name will consist of lowercase letters only and the length will be at most 20.

Input is terminated by a case where N is equal to 0.

Output

For each case, output the case number followed by the summation of the distances, rounded to 2 decimal places. Follow the sample for exact format.

Sample Input

Output for Sample Input

5
sohel 10 10
mahmud 20 10
sanny 5 5
prince 1 1
per 120 3
mf 6 6
kugel 50 60
joey 3 24
limon 6 9
manzoor 0 0
1
derek 9 9
jimmy 10 10
0

Case 1: 118.40
Case 2: 1.41

*/