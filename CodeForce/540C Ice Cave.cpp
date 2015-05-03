/* 10953717	2015-04-30 21:53:31	Shark	540C - Ice Cave	GNU C++	Accepted	31 ms	10300 KB */
#include<bits\stdc++.h>
using namespace std;
char T[505][505];
bool V[505][505];
int xx1, yy1, x2, y2;
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
int n, m;
bool DFS(int x, int y){
	if (x == x2 && y == y2)	return true;
	if (T[x][y] == 'X')	return false;
	for (int i = 0; i < 4; i++){
		int nextX = x + mx[i];
		int nextY = y + my[i];
		if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m || V[nextX][nextY])	continue;
		V[nextX][nextY] = true;
		if (DFS(nextX, nextY))
			return true;
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", T + i);
	scanf("%d%d%d%d", &xx1, &yy1, &x2, &y2);
	xx1--, yy1--, x2--, y2--;
	bool flag = false;
	for (int i = 0; i < 4 && !flag; i++){
		int nextX = xx1 + mx[i];
		int nextY = yy1 + my[i];
		if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)	continue;
		V[nextX][nextY] = true;
		if (DFS(nextX, nextY))
			flag = true;
	}
	if (flag){
		int count = 0;
		for (int i = 0; i < 4; i++){
			int nextX = x2 + mx[i];
			int nextY = y2 + my[i];
			if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)	continue;
			if (xx1 == nextX && yy1 == nextY)
				count++;
			else if (T[nextX][nextY] == '.')
				count++;
		}
		if (T[x2][y2] == 'X')
			puts("YES");
		else
			puts(count >= 2 ? "YES" : "NO");
	}
	else
		puts("NO");
	return 0;
}
/*

C. Ice Cave
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You play a computer game. Your character stands on some level of a multilevel ice cave. In order to move on forward, you need to descend one level lower and the only way to do this is to fall through the ice.

The level of the cave where you are is a rectangular square grid of n rows and m columns. Each cell consists either from intact or from cracked ice. From each cell you can move to cells that are side-adjacent with yours (due to some limitations of the game engine you cannot make jumps on the same place, i.e. jump from a cell to itself). If you move to the cell with cracked ice, then your character falls down through it and if you move to the cell with intact ice, then the ice on this cell becomes cracked.

Let's number the rows with integers from 1 to n from top to bottom and the columns with integers from 1 to m from left to right. Let's denote a cell on the intersection of the r-th row and the c-th column as (r, c).

You are staying in the cell (r1, c1) and this cell is cracked because you've just fallen here from a higher level. You need to fall down through the cell (r2, c2) since the exit to the next level is there. Can you do this?

Input
The first line contains two integers, n and m (1 ≤ n, m ≤ 500) — the number of rows and columns in the cave description.

Each of the next n lines describes the initial state of the level of the cave, each line consists of m characters "." (that is, intact ice) and "X" (cracked ice).

The next line contains two integers, r1 and c1 (1 ≤ r1 ≤ n, 1 ≤ c1 ≤ m) — your initial coordinates. It is guaranteed that the description of the cave contains character 'X' in cell (r1, c1), that is, the ice on the starting cell is initially cracked.

The next line contains two integers r2 and c2 (1 ≤ r2 ≤ n, 1 ≤ c2 ≤ m) — the coordinates of the cell through which you need to fall. The final cell may coincide with the starting one.

Output
If you can reach the destination, print 'YES', otherwise print 'NO'.

Sample test(s)
input
4 6
X...XX
...XX.
.X..X.
......
1 6
2 2
output
YES
input
5 4
.X..
...X
X.X.
....
.XX.
5 3
1 1
output
NO
input
4 7
..X.XX.
.XX..X.
X...X..
X......
2 2
1 6
output
YES
Note
In the first sample test one possible path is:



After the first visit of cell (2, 2) the ice on it cracks and when you step there for the second time, your character falls through the ice as intended.

*/