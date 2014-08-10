/* 13881322	10944	Nuts for nuts..	Accepted	C++	0.145	2014-07-14 10:15:35 */
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
#define MAX_N 18
#define MAX_M 30
#define INF 2e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
char T[MAX_M][MAX_M];
int N[MAX_M][MAX_M];
int W[MAX_N][MAX_N];
int mx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int my[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DP[1 << MAX_N][MAX_N];
int nut;
int n, m;
int convert(char c, int y, int x){
	if (c == '#')	return N[y][x];
	if (c == 'L')	return 0;
	return -1;
}
int query(int s, int last){
	if (s == 0)	return DP[s][last];
	if (DP[s][last] != INF)	return DP[s][last];
	DP[s][last]--; // record visited
	for (int i = 0; i < nut; i++){
		if (s & (1 << i)){
			int p = s ^ (1 << i);
			DP[s][last] = min(DP[s][last], query(p, i) + W[i][last]);
		}
	}
	return DP[s][last];
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		nut = 0;
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == '#')
					N[i][j] = ++nut;
		memset(W, 0, sizeof(W));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == '#' || T[i][j] == 'L')
					for (int p = 0; p < n; p++)
						for (int q = 0; q < m; q++)
							if (T[p][q] == '#' || T[p][q] == 'L')
								W[convert(T[i][j], i, j)][convert(T[p][q], p, q)] = max(abs(i - p), abs(j - q));
		nut++;
		for (int i = 0; i < (1 << nut); i++)
			for (int j = 0; j < nut; j++)
				DP[i][j] = INF;
		DP[0][0] = 0;
		printf("%d\n", query((1 << nut) - 1, 0));
	}
	return 0;
}
/*

Problem B: Nuts for nuts..

So as Ryan and Larry decided that they don't really taste so good, they realized that there are some nuts located in certain places of the island.. and they love them! Since they're lazy, but greedy, they want to know the shortest tour that they can use to gather every single nut!

Can you help them?

Input

You'll be given x, and y, both less than 20, followed by x lines of y characters each as a map of the area, consisting sorely of ".", "#", and "L". Larry and Ryan are currently located in "L", and the nuts are represented by "#". They can travel in all 8 adjacent direction in one step. See below for an example. There will be at most 15 places where there are nuts, and "L" will only appear once.
Output

On each line, output the minimum amount of steps starting from "L", gather all the nuts, and back to "L".

Sample Input

5 5
L....
#....
#....
.....
#....
5 5
L....
#....
#....
.....
#....
Sample Output

8
8
Larry and Ryan will go south for a nut, then south again for another nut, then south twice for another nut, and then back where they are.

*/