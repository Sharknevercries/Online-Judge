/* 14021597	314	Robot	Accepted	C++11	0.032	2014-08-11 11:27:27 */
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
#include<tuple>
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
#define MAX_N 60
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
#define SPACE 0
#define OBSTACAL 1
int T[MAX_N][MAX_N];
int V[MAX_N][MAX_N][4];
int startX, startY, startFace;
int destX, destY;
int n, m;
int BFS(){
	memset(V, NONE, sizeof(V));
	queue< tuple<int, int, int> > Q;
	Q.push(make_tuple(startX, startY, startFace));
	V[startY][startX][startFace] = 0;
	while (!Q.empty()){
		tuple<int, int, int> it = Q.front(); Q.pop();
		int curX = get<0>(it), curY = get<1>(it), curFace = get<2>(it);
		if (curX == destX && curY == destY)
			return V[curY][curX][curFace];
		for (int step = 1; step <= 3; step++){
			int nextX = curX + mx[curFace] * step, nextY = curY + my[curFace] * step;
			if (nextX <= 0 || nextX >= m || nextY <= 0 || nextY >= n || T[nextY][nextX] == OBSTACAL)
				break;
			if (V[nextY][nextX][curFace] != NONE)	continue;
			V[nextY][nextX][curFace] = V[curY][curX][curFace] + 1;
			Q.push(make_tuple(nextX, nextY, curFace));
		}
		int leftFace = (curFace + 3) % 4;
		if (V[curY][curX][leftFace] == NONE){
			V[curY][curX][leftFace] = V[curY][curX][curFace] + 1;
			Q.push(make_tuple(curX, curY, leftFace));
		}
		int rightFace = (curFace + 1) % 4;
		if (V[curY][curX][rightFace] == NONE){
			V[curY][curX][rightFace] = V[curY][curX][curFace] + 1;
			Q.push(make_tuple(curX, curY, rightFace));
		}
	}
	return NONE;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)break;
		char str[100];
		memset(T, SPACE, sizeof(T));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int tmp;
				scanf("%d", &tmp);
				if (tmp == OBSTACAL)
					T[i][j] = T[i + 1][j] = T[i][j + 1] = T[i + 1][j + 1] = OBSTACAL;
			}
		}
		scanf("%d%d%d%d%s", &startY, &startX, &destY, &destX, str);
		if (strcmp(str, "south") == 0)	startFace = SOUTH;
		else if (strcmp(str, "east") == 0)startFace = EAST;
		else if (strcmp(str, "west") == 0)startFace = WEST;
		else startFace = NORTH;
		printf("%d\n", BFS());
	}
	return 0;
}
/*

Robot

The Robot Moving Institute is using a robot in their local store to transport different items. Of course the robot should spend only the minimum time necessary when travelling from one place in the store to another. The robot can move only along a straight line (track). All tracks form a rectangular grid. Neighbouring tracks are one meter apart. The store is a rectangle  tex2html_wrap_inline41 meters and it is entirely covered by this grid. The distance of the track closest to the side of the store is exactly one meter. The robot has a circular shape with diameter equal to 1.6 meter. The track goes through the center of the robot. The robot always faces north, south, west or east. The tracks are in the south-north and in the west-east directions. The robot can move only in the direction it faces. The direction in which it faces can be changed at each track crossing. Initially the robot stands at a track crossing. The obstacles in the store are formed from pieces occupying  tex2html_wrap_inline43 on the ground. Each obstacle is within a  tex2html_wrap_inline45 square formed by the tracks. The movement of the robot is controlled by two commands. These commands are GO and TURN.

The GO command has one integer parameter  tex2html_wrap_inline47 {1,2,3}. After receiving this command the robot moves n meters in the direction it faces.

The TURN command has one parameter which is either left or right. After receiving this command the robot changes its orientation by 90o in the direction indicated by the parameter.

The execution of each command lasts one second.

Help researchers of RMI to write a program which will determine the minimal time in which the robot can move from a given starting point to a given destination.

Input

The input file consists of blocks of lines. The first line of each block contains two integers  tex2html_wrap_inline53 and tex2html_wrap_inline55 separated by one space. In each of the next M lines there are N numbers one or zero separated by one space. One represents obstacles and zero represents empty squares. (The tracks are between the squares.) The block is terminated by a line containing four positive integers  tex2html_wrap_inline61 each followed by one space and the word indicating the orientation of the robot at the starting point.  tex2html_wrap_inline63 ,  tex2html_wrap_inline65 are the coordinates of the square in the north-west corner of which the robot is placed (starting point).  tex2html_wrap_inline67 ,  tex2html_wrap_inline69 are the coordinates of square to the north-west corner of which the robot should move (destination point). The orientation of the robot when it has reached the destination point is not prescribed. We use (row, column)-type coordinates, i.e. the coordinates of the upper left (the most north-west) square in the store are 0,0 and the lower right (the most south-east) square are M - 1, N - 1. The orientation is given by the words north or west or south or east. The last block contains only one line with N = 0 and M = 0.

Output

The output file contains one line for each block except the last block in the input file. The lines are in the order corresponding to the blocks in the input file. The line contains minimal number of seconds in which the robot can reach the destination point from the starting point. If there does not exist any path from the starting point to the destination point the line will contain -1.

Example

Sample Input

9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 south
0 0
Sample Output

12

*/