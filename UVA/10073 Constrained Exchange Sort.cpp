/* 15419156	10073	Constrained Exchange Sort	Accepted	C++	0.263	2015-05-02 08:24:00 */
#include<bits\stdc++.h>
#define INF 1e9
using namespace std;
int mx[] = { 1, -1, 0, 0, 0, 0 };
int my[] = { 0, 0, 1, -1, 0, 0 };
int mz[] = { 0, 0, 0, 0, 1, -1 };
int prevMove[] = { 1, 0, 3, 2, 5, 4 };
int correctPos[13][3] = {
	{ 0, 0, 0 },
	{ 0, 0, 0 }, { 0, 1, 0 }, { 0, 2, 0 },
	{ 1, 0, 0 }, { 1, 1, 0 }, { 1, 2, 0 },
	{ 0, 0, 1 }, { 0, 1, 1 }, { 0, 2, 1 },
	{ 1, 0, 1 }, { 1, 1, 1 }
};
int board[2][3][2];
char ans[55];
int dist(int x1, int y1, int z1, int x2, int y2, int z2){
	return abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
}
int F(int board[2][3][2]){
	int cost1 = 0, cost2 = 0;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){
				if (board[i][j][k] && board[i][j][k] != i * 3 + j + k * 6 + 1)
					cost1++;
				if (board[i][j][k])
					cost2 += dist(i, j, k,
					correctPos[board[i][j][k]][0],
					correctPos[board[i][j][k]][1],
					correctPos[board[i][j][k]][2]
					);
			}
		}
	}
	return max(cost1, cost2);
}
int IDAstar(int x, int y, int z, int step, int prev, int &bound, bool &found){
	int f = F(board);
	if (step + f > bound)	return step + f;
	if (f == 0)	{	found = true;	return step;}
	int nextBound = 1e9;
	for (int i = 0; i < 6; i++){
		if (prevMove[i] == prev)	continue;
		int nextX = x + mx[i];
		int nextY = y + my[i];
		int nextZ = z + mz[i];
		if (nextX < 0 || nextX >= 2 || nextY < 0 || nextY >= 3 || nextZ < 0 || nextZ >= 2)	continue;
		ans[step] = board[nextX][nextY][nextZ] + 'A' - 1;
		swap(board[x][y][z], board[nextX][nextY][nextZ]);
		int v = IDAstar(nextX, nextY, nextZ, step + 1, i, bound, found);
		if (found)
			return v;
		nextBound = min(nextBound, v);
		swap(board[x][y][z], board[nextX][nextY][nextZ]);
	}
	return nextBound;
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t,c=1;
	scanf("%d", &t);
	while (t--){
		char str[100];
		scanf("%s", str);
		int sx, sy, sz;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 2; k++){
					board[i][j][k] = str[i * 3 + j + k * 6] - 'A' + 1;
					if (board[i][j][k] == 12)
						sx = i, sy = j, sz = k, board[i][j][k] = 0;
				}
			}
		}
		int minStep = 0;
		bool found = false;
		while (!found && minStep <= 50)
			minStep = IDAstar(sx, sy, sz, 0, -1, minStep, found);
		ans[minStep] = '\0';
		printf("Permutation #%d\n", c++);
		printf("%s\n", ans);
		putchar('\n');
	}
	return 0;
}
/*

Given a permutation of 12 letters ‘A’-‘L’, you are invited to write a program to sort them in ascending
order under the following set of constraints:
• The only allowed operation is the exchange of letters between two locations (locations are numbered
from 1 to 12).
• The letter ‘L’ must be involved in each operation.
• The letter ‘L’ at location l1 can be swapped with the letter at location l2 provided l1 l2 = di and
floor((l1 − 1)/di+1) = floor((l2 − 1)/di+1)
for i = 1, 2, 3, where (d1, d2, d3, d4) = (1, 3, 6, 12).
• You must use the minimum number of exchange operations possible.
Input
The first line of the input file contains an integer representing the number of test cases to follow. Each
test case contains a permutation of the letters ‘A’-‘L’ on a line by itself. It is guaranteed that the given
permutation can be sorted in ascending order under the given set of constraints.
Output
For each test case first output the permutation number on a line by itself. The next line will contain a
sequence of letters where the letter at location i represents the letter with which ‘L’ is swapped in the
i-th exchange during the sorting process. Output an empty line after each test case.
Sample Input
2
BKLAIGFHEDCJ
LIFDHJAKEGCB
Sample Output
Permutation #1
EHCJGIKCJGIECBADFJGFJGHIFKEF
Permutation #2
AKIHCBJCBJEFCEFIKGJKHBEF

*/