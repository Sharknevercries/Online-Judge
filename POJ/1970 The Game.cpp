/* 12998560	840502	1970	Accepted	136K	0MS	C++	1713B	2014-06-25 22:54:55 */
#include<cstdio>
int T[19][19];
bool check(int row, int col){
	bool res = false;
	int color = T[row][col], count;
	if (color == 0)
		return false;

	count = 0;
	for (int i = 0; row + i < 19; i++)
		if (T[row + i][col] == color)
			count++;
		else
			break;
	for (int i = 0; row - i >= 0; i++)
		if (T[row - i][col] == color)
			count++;
		else
			break;
	count--;
	res |= (count == 5);

	count = 0;
	for (int i = 0; col + i < 19; i++)
		if (T[row][col + i] == color)
			count++;
		else
			break;
	for (int i = 0; col - i >= 0; i++)
		if (T[row][col - i] == color)
			count++;
		else
			break;
	count--;
	res |= (count == 5);

	count = 0;
	for (int i = 0; i + row < 19 && col + i < 19; i++)
		if (T[row + i][col + i] == color)
			count++;
		else
			break;
	for (int i = 0; row - i >= 0 && col - i >= 0; i++)
		if (T[row - i][col - i] == color)
			count++;
		else
			break;
	count--;
	res |= (count == 5);

	count = 0;
	for (int i = 0; row + i < 19 && col - i >= 0; i++)
		if (T[row + i][col - i] == color)
			count++;
		else
			break;
	for (int i = 0; row - i >= 0 && col + i < 19; i++)
		if (T[row - i][col + i] == color)
			count++;
		else
			break;
	count--;
	res |= (count == 5);

	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		bool found = false;
		for (int i = 0; i < 19; i++)
			for (int j = 0; j < 19; j++)
				scanf("%d", &T[i][j]);
		for (int i = 0; i < 19 && !found; i++){
			for (int j = 0; j < 19 && !found; j++){
				if (check(j, i)){
					found = true;
					printf("%d\n", T[j][i]);
					printf("%d %d\n", j + 1, i + 1);
				}
			}
		}
		if (!found)
			printf("%d\n", 0);
	}
	return 0;
}
/*

Description

A game of Renju is played on a 19*19 board by two players. One player uses black stones and the other uses white stones. The game begins in an empty board and two players alternate in placing black stones and white stones. Black always goes first. There are 19 horizontal lines and 19 vertical lines in the board and the stones are placed on the intersections of the lines.

Horizontal lines are marked 1, 2, ..., 19 from up to down and vertical lines are marked 1, 2, ..., 19 from left to right.

The objective of this game is to put five stones of the same color consecutively along a horizontal, vertical, or diagonal line. So, black wins in the above figure. But, a player does not win the game if more than five stones of the same color were put consecutively.

Given a configuration of the game, write a program to determine whether white has won or black has won or nobody has won yet. There will be no input data where the black and the white both win at the same time. Also there will be no input data where the white or the black wins in more than one place.
Input

The first line of the input contains a single integer t (1 <= t <= 11), the number of test cases, followed by the input data for each test case. Each test case consists of 19 lines, each having 19 numbers. A black stone is denoted by 1, a white stone is denoted by 2, and 0 denotes no stone.
Output

There should be one or two line(s) per test case. In the first line of the test case output, you should print 1 if black wins, 2 if white wins, and 0 if nobody wins yet. If black or white won, print in the second line the horizontal line number and the vertical line number of the left-most stone among the five consecutive stones. (Select the upper-most stone if the five consecutive stones are located vertically.)
Sample Input

1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Sample Output

1
3 2
Source

Tehran Sharif 2004 Preliminary

*/