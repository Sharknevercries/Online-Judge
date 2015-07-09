/* 15424874	229	Scanner	Accepted	C++	0.015	2015-05-03 09:48:08 */
#include<bits\stdc++.h>
#define N 10
#define M 15
#define UNKNOWN 0
#define BLACK 1
#define WHITE 2
using namespace std;
int T[N][M + 1];
int found;
int a[4][N + M];
int limit[] = { N, N + M - 1, M, N + M - 1 };
bool va[4][N + M];
int mx[] = { 0, -1, -1, -1 };
int my[] = { 1, 1, 0, -1 };
void findSP(int &sx, int &sy, int i, int type){
	switch (type){
	case 0:
		sx = i, sy = 0;	break;
	case 1: 
		if (i >= N - 1)
			sx = N - 1, sy = i - 9;
		else
			sx = i, sy = 0;
		break;
	case 2:
		sx = N - 1, sy = i;	break;
	case 3:
		if (i >= M - 1)
			sx = N - 1 - i + M - 1, sy = M - 1;
		else
			sx = N - 1, sy = i;
		break;
	}
}
bool scan(int type){
	bool res = false;
	for (int i = 0; i < limit[type]; i++){
		if (va[type][i])	continue;
		int count1 = 0, count2 = 0;
		bool fix = false;
		int sx, sy, x, y;
		findSP(sx, sy, i, type);
		x = sx, y = sy;
		while (x >= 0 && x < N && y >= 0 && y < M)count1 += T[x][y] == BLACK, count2 += T[x][y] == UNKNOWN, x += mx[type], y += my[type];
		x = sx, y = sy;
		if (count1 == a[type][i]){
			while (x >= 0 && x < N && y >= 0 && y < M) T[x][y] = T[x][y] == UNKNOWN ? WHITE : T[x][y], x += mx[type], y += my[type];
			fix = true;
		}
		else if (count1 + count2 == a[type][i]){
			while (x >= 0 && x < N && y >= 0 && y < M) T[x][y] = T[x][y] == UNKNOWN ? BLACK : T[x][y], x += mx[type], y += my[type];
			fix = true;
		}
		if (fix)
			va[type][i] = res = true;
	}
	return res;
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t, ct = 1;
	scanf("%d", &t);
	while (t--){
		for (int i = 0; i < N; i++)
			scanf("%d", &a[0][i]);
		for (int i = 0; i < N + M - 1; i++)
			scanf("%d", &a[1][i]);
		for (int i = 0; i < M; i++)
			scanf("%d", &a[2][i]);
		for (int i = 0; i < N + M - 1; i++)
			scanf("%d", &a[3][i]);
		memset(va, false, sizeof(va));
		memset(T, UNKNOWN, sizeof(T));
		bool modify = false;
		do{
			modify = false;
			for (int i = 0; i < 4; i++)
				modify |= scan(i);
		} while (modify);
		if (ct > 1)	putchar('\n');
		bool flag = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				flag |= T[i][j] == UNKNOWN;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < limit[i]; j++)
				flag |= va[i][j] == false;
		if (flag)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					T[i][j] = WHITE;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (T[i][j] == WHITE)	putchar('.');
				if (T[i][j] == BLACK)	putchar('#');
			}
			putchar('\n');
		}
		ct++;
	}
	return 0;
}
/*


Scanner
A body scanner works by scanning a succession of horizontal slices through the body; the slices are imaged one at a time. The image slices can be reassembled to form a three dimensional model of the object. Write a program to construct a two dimensional image slice using data captured during the scan.

\epsfbox{p229.eps}
The scanner consists of four arrays of sensors arranged around a 10กั15 matrix. Array 1 consists of 10 sensors pointing to the right, array 2 has 24 sensors pointing diagonally to the top right, array 3 has 15 sensors pointing to the top and array 4 has 24 sensors pointing to the top left. Each sensor records the thickness of that portion of the object directly in front of that sensor.

Readings from the arrays of sensors are recorded in counterclockwise order. Within an array of sensors, data are also recorded counterclockwise. A complete scan consists of 73 readings.

Input

The input file begins with a line with an integer indicating the number of image slices to follow. For each image slice, there are separate lines with 10, 24, 15, and 24 integers representing sensor data from sensor arrays 1 through 4 respectively. The order of the readings is indicated in the diagram.
Output

For each slice, your program should print 10 lines of 15 cells. To indicate that the cell represents a part of the object, print a hash character (#) for the cell; to indicate that the cell is not a part of the object, print a period (.). Between successive output image slices, print a blank line.
It is possible for the result of a scan to be ambiguous, in that case you will have to output a blank picture as shown in the sample output.

Sample Input (First one describing object above)

2
10 10 6 4 6 8 13 15 11 6
0 1 2 2 2 2 4 5 5 6 7 6 5 6 6 5 5 6 6 3 2 2 1 0
2 4 5 5 7 6 7 10 10 10 7 3 3 5 5
0 0 1 3 4 4 4 4 3 4 5 7 8 8 9 9 6 4 4 2 0 0 0 0
10 10 6 4 6 8 13 15 11 6
0 1 2 2 2 2 4 5 5 6 7 6 5 6 6 5 5 6 6 3 2 2 1 0
2 4 5 5 7 6 7 10 10 10 7 3 3 5 5
0 0 1 3 4 4 4 4 3 2 5 7 8 8 9 9 6 4 4 2 0 0 0 0
Sample Output

.##########....
.##########....
....######.....
......####.....
.......####..##
.......########
#####..########
###############
..#########..##
....######.....

...............
...............
...............
...............
...............
...............
...............
...............
...............
...............


Miguel Revilla 2002-07-02

*/