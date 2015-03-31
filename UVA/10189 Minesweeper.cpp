/* 15250161	10189	Minesweeper	Accepted	C++	0.009	2015-03-31 16:58:52
 */
#include<bits\stdc++.h>
using namespace std;
int mx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int my[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
int main(){
	int n, m, c = 0;
	char T[105][105];
	char ans[105][105];
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; i++)
			scanf("%s", T + i);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				ans[i][j] = '0';
			ans[i][m] = '\0';
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == '*'){
					ans[i][j] = '*';
					for (int k = 0; k < 8; k++){
						int p = i + mx[k], q = j + my[k];
						if (p < 0 || q < 0 || p >= n || q >= m || T[p][q] == '*')	continue;
						ans[p][q]++;
					}
				}
		if (c)	putchar('\n');
		printf("Field #%d:\n", ++c);
		for (int i = 0; i < n; i++)
			printf("%s\n", ans[i]);
	}
	return 0;
}
/*

Have you ever played Minesweeper? It’s a cute little game which comes within a certain Operating
System which name we can’t really remember. Well, the goal of the game is to find where are all the
mines within a M × N field. To help you, the game shows a number in a square which tells you how
many mines there are adjacent to that square. For instance, supose the following 4 × 4 field with 2
mines (which are represented by an ‘*’ character):
*...
....
.*..
....
If we would represent the same field placing the hint numbers described above, we would end up
with:
*100
2210
1*10
1110
As you may have already noticed, each square may have at most 8 adjacent squares.
Input
The input will consist of an arbitrary number of fields. The first line of each field contains two integers
n and m (0 < n, m ≤ 100) which stands for the number of lines and columns of the field respectively.
The next n lines contains exactly m characters and represent the field.
Each safe square is represented by an ‘.’ character (without the quotes) and each mine square
is represented by an ‘*’ character (also without the quotes). The first field line where n = m = 0
represents the end of input and should not be processed.
Output
For each field, you must print the following message in a line alone:
Field #x:
Where x stands for the number of the field (starting from 1). The next n lines should contain the
field with the ‘.’ characters replaced by the number of adjacent mines to that square. There must be
an empty line between field outputs.
Sample Input
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
Sample Output
Field #1:
*100
2210
1*10
1110
Field #2:
**100
33200
1*100

*/