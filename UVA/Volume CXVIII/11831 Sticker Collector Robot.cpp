/* 14012447	11831	Sticker Collector Robot	Accepted	C++	0.025	2014-08-09 08:48:18 */
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
#define MAX_N 105
#define MAX_M 60000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
// main
char T[MAX_N][MAX_N];
char order[MAX_M];
int mx[] = { 0, 1, 0, -1 };
int my[] = { -1, 0, 1, 0 };
int n, m, k;
int travel(){
	int x, y, way, count = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (T[i][j] == 'N')
				x = j, y = i, way = NORTH;
			else if (T[i][j] == 'O')
				x = j, y = i, way = WEST;
			else if (T[i][j] == 'L')
				x = j, y = i, way = EAST;
			else if (T[i][j] == 'S')
				x = j, y = i, way = SOUTH;
		}
	}
	for (int i = 0; i < k; i++){
		if (order[i] == 'D')
			way = (way + 1) % 4;
		else if (order[i] == 'E')
			way = way - 1 >= 0 ? way - 1 : 3;
		else{
			int nextX = x + mx[way], nextY = y + my[way];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || T[nextY][nextX] == '#')
				continue;
			if (T[nextY][nextX] == '*')
				count++, T[nextY][nextX] = '.';
			x = nextX, y = nextY;
		}
	}
	return count;
}
int main(){
	while (scanf("%d%d%d", &n, &m, &k) == 3 && n && m && k){
		for (int i = 0; i < n; i++)
			scanf("%s", T + i);
		scanf("%s", order);
		printf("%d\n", travel());
	}
	return 0;
}
/*


Sticker Collector Robots
One of the favorite sports in RoboLand is the Robots Rally. This rally is practiced in a giant rectangular arena of square cells with dimensions N rows by M columns. Some cells are empty, some contain a sticker for the World Footbal Cup Album (much appreciated by artificial intelligences in RoboLand) and some are occupied by pillars which support the roof of the arena. During the rally the robots can occupy any cell in the arena, except those containing pillars, since they block the robot movement. The path of the robot in the arena during the rally is determined by a sequence of instructions. Each instruction is represented by one of the following characters: `D', `E' and `F', meaning, respectively, ``turn 90 degrees to the right", ``turn 90 degrees to the left" and ``move forward one cell". Robots start the rally in some initial position in the arena and follow closely the sequence of instructions given (after all, they are robots!). Whenever a robot occupies a cell that contains a Cup sticker he collects it. Stickers are not replaced, that is, each scticker can be collected only once. When a robot tries to move into a cell which contains a pillar he stalls, remaining in the cell where he was, with the same orientation. The same happens when a robot tries to leave the arena.
Given the map of the arena, describing the position of pillars and sctickers, and the sequence of instructions of a robot, you must write a program to determine the number of stickers collected by the robot.

Input

The input contains several test cases. The first line of a test case contains three integers N, M and S ( 1$ \le$N, M$ \le$100, 1$ \le$S$ \le$5 x 104), separated by white spaces, indicating respectively the number of rows, the number of columns of the arena and the number of instructions to the robot. Each of the following N lines describes a cell line of the arena and contains a string with M characters. The first line to appear in the description of the arena is the one more to the North, the first column to appear in description of a cell line of the arena is the one more to the West.
Each cell in the arena is described by one of the following characters:

`.' -- normal cell;
`*' -- cell which contains a sticker;
`#' -- cell which contains a pillar;
`N', `S', `L', `O' -- cell where the robot starts the rally (only one in the arena). The letter represents the initial robot orientation (North, South, East and West, respectively).
The last line in the input contains a sequence of S characters among `D', `E' and `F', representing the instructions to the robot.

The last test case is followed by a line which contains only three numbers zero separated by a blank space.

Output

For each rally described in the input your program must print a single line containing a single integer indicating the number of stickers that the robot collected during the rally.
Sample Input

3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0
Sample Output

0
1
3

*/