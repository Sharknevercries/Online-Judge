/* 13987391	840502	1739	Accepted	18280K	641MS	G++	2870B	2015-03-21 01:47:55 */
#include<bits\stdc++.h>
using namespace std;
int r, c;
int pow3[15] = { 1 };
char T[15][15];
int DP[15][15][20005];
inline int getHash(int x, int y){ return x / pow3[y] % 3; }
inline int setHash(int x, int y, int value){ return x + (-getHash(x, y) + value) * pow3[y]; }
int change1(int status, int j){
	for (int stack = 0; j <= c; j++){
		int tmp = getHash(status, j);
		if (tmp == 1)	stack++;
		if (tmp == 2){
			if (stack == 0)
				return setHash(status, j, 1);
			stack--;
		}
	}
	return -1;
}
int change2(int status, int j){
	for (int stack = 0; j >= 0; j--){
		int tmp = getHash(status, j);
		if (tmp == 2)	stack++;
		if (tmp == 1){
			if (stack == 0)
				return setHash(status, j, 2);
			stack--;
		}
	}
	return -1;
}
int main(){
	for (int i = 1; i <= 12; i++)
		pow3[i] = pow3[i - 1] * 3;
	while (scanf("%d%d", &r, &c) == 2){
		if (r == 0 && c == 0)	break;
		for (int i = 0; i < r; i++)
			scanf("%s", T + i);
		// only one line
		memset(DP, 0, sizeof(DP));
		DP[0][0][0] = 1;
		for (int i = 0; i < r; i++){
			for (int j = 0; j <= c; j++){
				if (i == r - 1 && j == c)	break;
				for (int status = 0; status < pow3[c + 1]; status++){
					if (DP[i][j][status] == 0)	continue;
					if (j == c){
						if (getHash(status, j) == 0)
							DP[i + 1][0][status * 3] += DP[i][j][status];
					}
					else{
						int left = getHash(status, j), up = getHash(status, j + 1);
						if (T[i][j] == '#'){
							if (left == 0 && up == 0)
								DP[i][j + 1][status] += DP[i][j][status];
						}
						else{
							if (left == 0 && up == 0)
								DP[i][j + 1][setHash(setHash(status, j, 1), j + 1, 2)] += DP[i][j][status];
							else if (left == 0 || up == 0){
								DP[i][j + 1][setHash(setHash(status, j + 1, 0), j, left + up)] += DP[i][j][status];
								DP[i][j + 1][setHash(setHash(status, j, 0), j + 1, left + up)] += DP[i][j][status];
							}
							else if (left == 1 && up == 2)
								continue;
							else if (left == 2 && up == 1)
								DP[i][j + 1][setHash(setHash(status, j, 0), j + 1, 0)] += DP[i][j][status];
							else if (left == 1 && up == 1){
								int tmp = change1(status, j + 2);
								if (tmp == -1)	continue;
								DP[i][j + 1][setHash(setHash(tmp, j, 0), j + 1, 0)] += DP[i][j][status];
							}
							else if (left == 2 && up == 2){
								int tmp = change2(status, j - 1);
								if (tmp == -1)	continue;
								DP[i][j + 1][setHash(setHash(tmp, j, 0), j + 1, 0)] += DP[i][j][status];
							}
						}
					}
				}
			}
		}
		printf("%d\n", DP[r - 1][c][1 + 2 * pow3[c]]);
	}
	return 0;
}
/*

Tony's Tour
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 3538		Accepted: 1646
Description

A square township has been divided up into n*m(n rows and m columns) square plots (1<=N,M<=8),some of them are blocked, others are unblocked. The Farm is located in the lower left plot and the Market is located in the lower right plot. Tony takes her tour of the township going from Farm to Market by walking through every unblocked plot exactly once.
Write a program that will count how many unique tours Betsy can take in going from Farm to Market.
Input

The input contains several test cases. The first line of each test case contain two integer numbers n,m, denoting the number of rows and columns of the farm. The following n lines each contains m characters, describe the farm. A '#' means a blocked square, a '.' means a unblocked square.
The last test case is followed by two zeros.
Output

For each test case output the answer on a single line.
Sample Input

2 2
..
..
2 3
#..
...
3 4
....
....
....
0 0
Sample Output

1
1
4
Source

LouTiancheng@POJ

*/