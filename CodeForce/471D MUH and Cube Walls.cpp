/* 7969139	2014-09-26 20:47:53	* Shark	471D - MUH and Cube Walls	GNU C++	Accepted	77 ms	3900 KB */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 200005
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
int A[MAX_N], B[MAX_N];
int T[MAX_N], P[MAX_N];
int F[MAX_N];
int n, m;
int MP(){
	if (m > n)	return 0;
	if (m == 1)	return n;
	int ans = 0;
	for (int i = 1, j = F[0] = -1; i < m - 1; i++){
		while (j >= 0 && P[j + 1] != P[i])
			j = F[j];
		if (P[j + 1] == P[i])	j++;
		F[i] = j;
	}
	for (int i = 0, j = -1; i < n - 1; i++){
		while (j >= 0 && P[j + 1] != T[i])
			j = F[j];
		if (P[j + 1] == T[i])	j++;
		if (j == m - 2)
			ans++, j = F[j];
	}
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", A + i);
	for (int i = 0; i < m; i++)
		scanf("%d", B + i);
	for (int i = 1; i < n; i++)
		T[i - 1] = A[i] - A[i - 1];
	for (int i = 1; i < m; i++)
		P[i - 1] = B[i] - B[i - 1];
	printf("%d\n", MP());
	return 0;
}
/*

D. MUH and Cube Walls
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polar bears Menshykov and Uslada from the zoo of St. Petersburg and elephant Horace from the zoo of Kiev got hold of lots of wooden cubes somewhere. They started making cube towers by placing the cubes one on top of the other. They defined multiple towers standing in a line as a wall. A wall can consist of towers of different heights.

Horace was the first to finish making his wall. He called his wall an elephant. The wall consists of w towers. The bears also finished making their wall but they didn't give it a name. Their wall consists of n towers. Horace looked at the bears' tower and wondered: in how many parts of the wall can he "see an elephant"? He can "see an elephant" on a segment of w contiguous towers if the heights of the towers on the segment match as a sequence the heights of the towers in Horace's wall. In order to see as many elephants as possible, Horace can raise and lower his wall. He even can lower the wall below the ground level (see the pictures to the samples for clarification).

Your task is to count the number of segments where Horace can "see an elephant".

Input
The first line contains two integers n and w (1 ≤ n, w ≤ 2·105) — the number of towers in the bears' and the elephant's walls correspondingly. The second line contains n integers ai (1 ≤ ai ≤ 109) — the heights of the towers in the bears' wall. The third line contains w integers bi (1 ≤ bi ≤ 109) — the heights of the towers in the elephant's wall.

Output
Print the number of segments in the bears' wall where Horace can "see an elephant".

Sample test(s)
input
13 5
2 4 5 5 4 3 2 2 2 3 3 2 1
3 4 4 3 2
output
2
Note
The picture to the left shows Horace's wall from the sample, the picture to the right shows the bears' wall. The segments where Horace can "see an elephant" are in gray.

*/