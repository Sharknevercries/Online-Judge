/* 13999606	556	Amazing	Accepted	C++	0.032	2014-08-06 15:48:02 */
/* Template By Shark */
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
#define MAX_N 1005
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
const double PI = 2.0 * acos(0.0);
// main
int n, m;
char T[MAX_N][MAX_N];
int S[MAX_N][MAX_N];
int mx[][4] = { { 1, 0, -1, 0 }, { 0, 1, 0, -1 }, { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
int my[][4] = { { 0, -1, 0, 1 }, { 1, 0, -1, 0 }, { 0, 1, 0, -1 }, { -1, 0, 1, 0 } };
int main(){
	while (scanf("%d%d", &n, &m) == 2 && n && m){
		memset(S, 0, sizeof(S));
		for (int i = 0; i < n; i++)
			scanf("%s", T + i);
		int x = 0, y = n - 1, dir = RIGHT;
		do{
			for (int i = 0; i < 4; i++){
				int next_x = x + mx[dir][i];
				int next_y = y + my[dir][i];
				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || T[next_y][next_x] == '1')
					continue;
				x = next_x, y = next_y;
				S[y][x]++;
				switch (i){
				case 0:	dir += 1;	break;
				case 1:				break;
				case 2:	dir += 3;	break;
				case 3:	dir += 2;	break;
				}
				dir %= 4;
				break;
			}
		} while (!(x == 0 && y == n - 1));
		int ans[MAX_N] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == '0')
					ans[S[i][j]]++;
		for (int i = 0; i < 5; i++)
			printf("%3d", ans[i]);
		putchar('\n');
	}
	return 0;
}
/*

Amazing
One of the apparently intelligent tricks that enthousiastic psychologists persuade mice to perform is solving a maze. There is still some controversy as to the exact strategies employed by the mice when engaged in such a task, but it has been claimed that the animal keepers eavesdropping on conversations between the mice have heard them say things like "I have finally got Dr. Schmidt trained. Everytime I get through the maze he gives me food".

Thus when autonomous robots were first being built, it was decided that solving such mazes would be a good test of the 'intelligence' built into such machines by their designers. However, to their chagrin, the first contest was won by a robot that placed a sensor on the right-hand wall of the maze and sped through the maze maintaining contact with the right-hand wall at all times. This led to a change in the design of mazes, and also to the interest in the behaviour of such robots. To test this behaviour the mazes were modified to become closed boxes with internal walls. The robot was placed in the south west corner and set of pointing east. The robot then moved through the maze, keeping a wall on its right at all times. If it can not proceed, it will turn left until it can proceed. All turns are exact right angles. The robot stops when it returns to the starting square. The mazes were always set up so that the robot could move to at least one other square before returning. The researchers then determined how many squares were not visited and how many were visited one, twice, thrice and four times. A square is visited if a robot moves into and out of it. Thus for the following maze, the values (in order) are: 2, 3, 5, 1, 0.

Write a program to simulate the behaviour of such a robot and collect the desired values.

Input

Input will consist of a series of maze descriptions. Each maze description will start with a line containing the size of the maze (b and w), This will be followed by b lines, each consisting of w characters, either '0' or '1'. Ones represent closed squares, zeroes represent open squares. Since the maze is enclosed, the outer wall is not specified. The file will be terminated by a line containing two zeroes.
Output

Output will consist of a series of lines, one for each maze. Each line will consist of 5 integer values representing the desired values, each value right justified in a field of width 3.
Sample Input

3 5
01010
01010
00000
0 0
Sample Output

2  3  5  1  0

Miguel A. Revilla
1998-03-10

*/