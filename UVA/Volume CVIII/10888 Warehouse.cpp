/* 13867703	10888	Warehouse	Accepted	C++	0.023	2014-07-11 15:41:00 */
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
#define MAX_M 45
#define INF 2e8
#define NONE -1
const double PI = 2.0 * acos(0.0);
int n, m;
int desCount, boxCount;
int DP[1 << MAX_N];
int B[MAX_N][MAX_N];
int D[MAX_M][MAX_M];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
char T[MAX_M][MAX_M];
void BFS(int num, int y, int x){
	int C[MAX_M][MAX_M];
	queue< pair<int, int> > Q;
	Q.push(make_pair(x, y));
	memset(C, NONE, sizeof(C));
	C[y][x] = 0;
	while (!Q.empty()){
		pair<int, int> pos = Q.front();
		Q.pop();
		if (T[pos.second][pos.first] == 'X')
			B[num][D[pos.second][pos.first]] = C[pos.second][pos.first];
		for (int i = 0; i < 4; i++){
			int nextX = pos.first + mx[i];
			int nextY = pos.second + my[i];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
				continue;
			if (T[nextY][nextX] == '#')
				continue;
			if (C[nextY][nextX] == NONE){
				C[nextY][nextX] = C[pos.second][pos.first] + 1;
				Q.push(make_pair(nextX, nextY));
			}
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		boxCount = desCount = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				B[i][j] = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == 'X')
					D[i][j] = desCount++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == 'B')
					BFS(boxCount++, i, j);

		int maxState = (1 << boxCount);
		for (int i = 0; i < maxState; i++)
			DP[i] = INF;
		DP[0] = 0;
		vector<int> S[MAX_N];
		for (int i = 0; i < maxState; i++){
			int digit = __builtin_popcount(i);
			S[digit].push_back(i);
		}
		for (int i = 0; i < boxCount; i++){
			for (int j = 0; j < S[i].size(); j++){
				int ori = S[i][j];
				for (int k = 0; k < desCount; k++)
					if ((ori&(1 << k)) == 0)
						DP[ori | (1 << k)] = min(DP[ori | (1 << k)], DP[ori] + B[i][k]);
			}
		}
		printf("%d\n", DP[maxState - 1]);
	}
	return 0;
}
/*

Problem B
Warehouse
Input: Standard Input
Output: Standard Output

A number of boxes is to be moved in a warehouse. The warehouse can be modeled as a grid where each square is the equal to the size of a box. Consider the model below: (‘B’ = box to be moved, ‘.’ = empty square, ‘X’ = position a box should occupy after the move, ‘#’ = obstacle)

BBBB....
.###...X
.XX#...X
...#....
........
A box may be moved to any of its four neighboring squares, assuming this square is empty (that is, not occupied by another box or an obstacle). To move a box takes one unit of time, and only one box may be moved per time unit. Your task is to determine the least amount of time to move all boxes to their destination squares. You may assume that a solution exists. Number of boxes will be no more than 15.

Input
The first line in the input contains the number of test cases (at most 20). Each case starts with a line containing two integers, the height (1 ≤ h ≤ 40) and width (1 ≤ w ≤ 40) of the grid. Then follows h lines, each containing w characters, describing the grid in the format above.

Output
For each test case, output a line containing a single integer: the minimum number of time units to move all boxes.

Sample Input                               Output for Sample Input
1
5 8
BBBB....
.###...X
.XX#...X
...#....
........

20
Problem setter: Jimmy Mårdell
Special Thanks: Mohammad Sajjad Hossain

*/