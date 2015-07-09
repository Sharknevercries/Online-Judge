/* 15416514	10890	Maze	Accepted	C++	2.582	2015-05-01 17:15:41 */
#include<bits\stdc++.h>
using namespace std;
struct Treasure{
	int x, y;
};
Treasure T[35];
int dist[35][35];
bool V[35];
int n, s, t;
int ans;
void DFS(int count, int pos, int cost){
	if (count == 0){
		ans = min(ans, cost + T[pos].x + T[pos].y);
		return;
	}
	if (ans <= cost)	return;
	for (int i = 0; i < t; i++){
		if (V[i])	continue;
		V[i] = true;
		DFS(count - 1, i, cost + dist[pos][i]);
		V[i] = false;
	}
}
int main(){
	int c = 1;
	while (scanf("%d%d%d", &n, &t, &s) == 3){
		if (n == 0 && t == 0 && s == 0)	break;
		for (int i = 0; i < t; i++)
			scanf("%d%d", &T[i].x, &T[i].y);
		T[t].x = T[t].y = n - 1;
		for (int i = 0; i <= t; i++)
			for (int j = 0; j <= t; j++)
				dist[i][j] = abs(T[i].x - T[j].x) + abs(T[i].y - T[j].y);
		memset(V, false, sizeof(V));
		V[t] = true, ans = 1e9;
		DFS(s, t, 0);
		printf("Case %d: %d\n", c++, ans);
	}
	return 0;
}
/*

Problem D
Maze
Input File: d.in
Output: Standard Output

In this problem you are given a square maze of dimension N with N*N blocks. Each block is numbered as follows:

N-1, 0
N-1, 1
…
…
N-1, N-1
…
…
…
…
…
2, 0
2, 1
2, 2
…
…
1, 0
1, 1
1, 2
…
…
0, 0
0, 1
0, 2
…
0, N-1


The maze has only one entry which is at (0, 0) and only one exit which is at (N-1, N-1). From each block you can move in four directions (N, E, W, S) and the cost is 1 for each movement among the maze but collecting treasure does not require any cost.. Some blocks contain treasures that you will have to collect. Suppose there are T treasures in the maze and you have to collect at least S (S ≤ T) treasures from them. In this problem, you are requested to find an optimal way from starting location to ending location and take at least S treasures from the maze. Remember that, you can visit a block more than once if you want.

Input
The first line of the input contains three integers N (N ≤ 30), T (T ≤ 30) and S (S ≤ 10 and S ≤ T) describing the dimension of the maze, number of treasures in the maze and number of treasures that you can take. After that, there are T lines. Each line contains two numbers representing the position of the treasure in the maze. The input may contain multiple test cases and ends with three zeros for N, T and S.

Output
Each test case produces one line of output. This line should contain the output serial no as shown in the sample output and a number representing the minimum cost which is required to collect the treasures.

Sample Input                                 Output for Sample Input
4 4 4
2 0
2 1
2 2
0 2
4 4 2
2 0
2 1
2 2
0 2
0 0 0

Case 1: 10
Case 2: 6
Problem setter: Syed Monowar Hossain
Special Thanks: Derek Kisman

*/