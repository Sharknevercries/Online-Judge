/* 5568892	 Dec 30, 2013 4:31:02 PM	Shark	 377A - Maze	 GNU C++	Accepted	15 ms	700 KB */
#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
char T[500][501];
bool M[500][501];
bool P[500][501];
queue< pair<int, int> >Q;
int n, m, k, space;
void push(int x, int y){
	if (x >= 0 && y >= 0 && x < n&&y < m&&!M[x][y]&&T[x][y]=='.'){
		Q.push(make_pair(x, y));
		M[x][y] = true;
	}	
}
void BFS(int x, int y){
	int count = 0;
	while (!Q.empty())	Q.pop();
	M[x][y] = true;
	Q.push(make_pair(x, y));
	while (count < space - k){
		pair<int, int> cur = Q.front();
		Q.pop();
		push(cur.first - 1, cur.second);
		push(cur.first + 1, cur.second);
		push(cur.first, cur.second - 1);
		push(cur.first, cur.second + 1);
		count++;
		P[cur.first][cur.second] = true;
	}
}
void solve(){
	memset(M, false, sizeof(M));
	memset(P, false, sizeof(P));
	bool found = false;
	space = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (T[i][j] == '.')
				space++;
		}
	}
	for (int i = 0; i < n && !found; i++){
		for (int j = 0; j < m && !found; j++){
			if (T[i][j] == '.'){
				BFS(i, j);
				found = true;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (T[i][j] == '.'&&!P[i][j])
				T[i][j] = 'X';
		}
	}
}
int main(){
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		solve();
		for (int i = 0; i < n; i++)
			printf("%s\n", T[i]);
	}
	return 0;
}
/*

A. Maze
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pavel loves grid mazes. A grid maze is an n × m rectangle maze where each cell is either empty, or is a wall. You can go from one cell to another only if both cells are empty and have a common side.

Pavel drew a grid maze with all empty cells forming a connected area. That is, you can go from any empty cell to any other one. Pavel doesn't like it when his maze has too little walls. He wants to turn exactly k empty cells into walls so that all the remaining cells still formed a connected area. Help him.

Input
The first line contains three integers n, m, k (1 ≤ n, m ≤ 500, 0 ≤ k < s), where n and m are the maze's height and width, correspondingly, k is the number of walls Pavel wants to add and letter s represents the number of empty cells in the original maze.

Each of the next n lines contains m characters. They describe the original maze. If a character on a line equals ".", then the corresponding cell is empty and if the character equals "#", then the cell is a wall.

Output
Print n lines containing m characters each: the new maze that fits Pavel's requirements. Mark the empty cells that you transformed into walls as "X", the other cells must be left without changes (that is, "." and "#").

It is guaranteed that a solution exists. If there are multiple solutions you can output any of them.

Sample test(s)
input
3 4 2
#..#
..#.
#...
output
#.X#
X.#.
#...
input
5 4 5
#...
#.#.
.#..
...#
.#.#
output
#XXX
#X#.
X#..
...#
.#.#

*/