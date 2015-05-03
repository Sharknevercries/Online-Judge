/* 15418862	10068	The Treasure Hunt	Accepted	C++	0.042	2015-05-02 06:34:30 */
#include<bits\stdc++.h>
#define INF 1e9
using namespace std;
struct Treasure{
	int x, y;
	int pick, carry;
};
int n, m, t;
char T[25][25];
Treasure trea[15];
int stepCost;
int sx, sy, tx, ty;
long long DP[5050][15];
int record[5050][15];
long long dist[15][15];
int level[25][25];
bool V[25][25];
char road[15][15][405];
long long carryState[5050];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
void backTrack(int s, int t){
	int ptr = dist[s][t];
	road[s][t][ptr] = '\0';
	int x = trea[t].x, y = trea[t].y;
	while (ptr > 0){
		for (int i = 0; i < 4; i++){
			int nextX = x + mx[i];
			int nextY = y + my[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || level[nextX][nextY] != ptr - 1)	continue;
			x = nextX, y = nextY;
			if (i == 0) road[s][t][--ptr] = 'N';
			if (i == 1) road[s][t][--ptr] = 'S';
			if (i == 2) road[s][t][--ptr] = 'W';
			if (i == 3) road[s][t][--ptr] = 'E';
			break;
		}
	}
}
void BFS(int s){
	queue< pair<int, int> > Q; 
	Q.push(make_pair(trea[s].x, trea[s].y));
	memset(level, -1, sizeof(level));
	memset(V, false, sizeof(V));
	V[trea[s].x][trea[s].y] = true;
	level[trea[s].x][trea[s].y] = 0;
	while (!Q.empty()){
		pair<int, int> cur = Q.front();	Q.pop();
		if (T[cur.first][cur.second] != '.')
			for (int i = 0; i < t; i++)
				if (cur.first == trea[i].x && cur.second == trea[i].y)
					dist[s][i] = level[cur.first][cur.second], backTrack(s, i);
		for (int i = 0; i < 4; i++){
			int nextX = cur.first + mx[i];
			int nextY = cur.second + my[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || level[nextX][nextY] != -1 || T[nextX][nextY] == '#')	continue;
			level[nextX][nextY] = level[cur.first][cur.second] + 1;
			Q.push(make_pair(nextX, nextY));
		}
	}
}
long long DFS(int state, int end){
	if (DP[state][end] != -1)	return DP[state][end];
	if (state == 0){
		if (end == 0)
			return 0;
		return INF;
	}
	if (!(state & 1))	return INF;
	long long &res = DP[state][end];
	res = INF;
	for (int i = 0; i < t; i++){
		if (state & (1 << i)){
			int nextState = state ^ (1 << end);
			if (res > DFS(nextState, i) + dist[end][i] * (carryState[nextState] + stepCost) + trea[end].pick)
				res = DFS(nextState, i) + dist[end][i] * (carryState[nextState] + stepCost) + trea[end].pick, record[state][end] = i;
		}
	}
	return res;
}
void printPath(){
	int path[15];
	path[0] = (t - 1);
	for (int i = 1, j = (1 << t) - 1; j != 0; i++)
		path[i] = record[j][path[i - 1]], j ^= (1 << path[i - 1]);
	for (int i = t - 1; i > 0; i--){
		printf("%s", road[path[i]][path[i - 1]]);
		if (i != 1)	putchar('P');
	}
	putchar('\n');
}
int main(){
	//freopen("input.txt", "r", stdin);
	int c = 1;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		bool flag = true;
		for (int i = 0; i < n; i++)
			scanf("%s", T + i);
		scanf("%d", &stepCost);
		t = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				switch (T[i][j]){
				case 'T':	tx = i, ty = j;	break;
				case 'S':	sx = i, sy = j;	break;
				case '*':	trea[t].x = i, trea[t++].y = j;	break;
			}
		trea[0].x = sx, trea[0].y = sy, trea[0].carry = 0, trea[0].pick = 0;
		for (int i = 1; i < t; i++)
			scanf("%d%d", &trea[i].pick, &trea[i].carry);
		trea[t].x = tx, trea[t].y = ty, trea[t].carry = 0, trea[t].pick = 0;
		t++;
		for (int i = 0; i < t; i++)
			for (int j = 0; j < t; j++)
				dist[i][j] = INF;
		for (int i = 0; i < t; i++)
			BFS(i);
		for (int i = 0; i < t; i++)
			for (int j = 0; j < t; j++)
				if (dist[i][j] == INF)
					flag = false;
		memset(carryState, 0, sizeof(carryState));
		for (int i = 0; i < (1 << t); i++)
			for (int j = i, k = 0; j > 0; j >>= 1, k++)
				if (j & 1)
					carryState[i] += trea[k].carry;
		if (c > 1)	putchar('\n');
		printf("Hunt #%d\n", c++);
		if (flag){
			memset(DP, -1, sizeof(DP));
			memset(record, -1, sizeof(record));
			DFS((1 << t) - 1, t - 1); // all clear, and stand on t - 1
			printf("Minimum energy required = %lld cal\n", DP[(1 << t) - 1][t - 1]);
			printPath();
		}
		else
			puts("The hunt is impossible.");
	}
	return 0;
}
/*

In this problem you will be given a map of a rectangular maze with square blocks. From each block
you can move in four directions (N, E, W, S) and you lose some energy for every walk from one block
to an adjacent one. Some blocks of the maze are really blocked - that is you cannot move to those
blocks. Some other blocks contain some treasures that you will have to collect. Each treasure has a
particular pickup cost and carrying cost associated with it. The pickup cost is the energy required to
pick up the treasure from the floor and the carrying cost is the energy required to carry the treasure
from one block to an adjacent one.
Now given a starting and ending location in the maze you will have to plan a single walk from the
starting location to collect and carry all the treasures to the ending location at the expense of minimum
energy.
Input
The first line of the input contains two integers R and C (each ≤ 20) describing the dimensions of the
maze. Then follows R lines of C characters each representing the map of the maze. Each character
corresponds to a square block and represents its property (‘.’ : an empty block, ‘#’ : a blocked block,
‘*’ : a block containing a treasure, ‘S’ : the starting block, ‘T’ : the ending block).
The next line contains an integer representing the energy required in calories for a walk from a block
to an adjacent one.
The next line contains pairs of integers (Pi
, Ci) representing the pickup and carrying cost in calories
for the treasures given in the map from top to bottom and for the same row from left to right. There
will be at most 10 treasures in the maze.
The input may contain multiple test cases and ends with two zeros for R and C.
Output
For each test case first output the hunt number. In the next line print the minimum energy required for
the hunt. The third line will contain the description of the hunt as a sequence of characters containing
‘N’, ‘E’, ‘W’, ‘S’ and ‘P’. ‘N’, ‘E’, ‘W’ and ‘S’ represent a walk to the north, east, west and south respectively
and ‘P’ means that the treasure is picked up from the current location. If the hunt is impossible just
output the sentence ‘The hunt is impossible.’ in a line by itself.
Each test case output must be followed by a blank line.
Sample Input
5 8
#......T
..#*..#.
..######
...*...#
####S.#*
5
10 50 50 100 30 80
10 10
#........*
..#*..#...
..######..
.......#..
####S..##.
.*.#...#..
.......#..
.##.#....#
.*.....#.#
....*..#.T
10
100 400 20 50 150 250 30 70 4 5
0 0
Sample Output
Hunt #1
The hunt is impossible.
Hunt #2
Minimum energy required = 17539 cal
NWWWNNNEESPNWWSSSEEESSSWSSESPWWWNPWNNENPESEEESEEENENNNNNNPSSSSSWSSSSE

*/