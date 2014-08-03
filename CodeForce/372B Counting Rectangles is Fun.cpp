/* 5433339	 Dec 13, 2013 9:17:30 PM	Shark	 372B - Counting Rectangles is Fun	 GNU C++	Accepted	 1092 ms	 10000 KB */
#include<cstdio>
#include<string.h>
int A[40][40][40][40];
int main(){
	int n, m, q;
	while (scanf("%d%d%d", &n, &m, &q) == 3){
		for (int i = 0; i < 40; i++){
			for (int j = 0; j < 40; j++){
				for (int k = 0; k < 40; k++){
					for (int p = 0; p < 40; p++){
						A[i][j][k][p] = -1;
					}
				}
			}
		}
		char T[40][41];
		int H[40][40] = { 0 };
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (T[i][j] == '0'){
					if (i - 1 >= 0)
						H[i][j] = H[i - 1][j] + 1;
					else
						H[i][j] = 1;
				}
				else
					H[i][j] = 0;
			}
		}
		for (int i = 0; i < q; i++){
			int x1, x2, y1, y2, ans = 0;
			scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
			x1--, x2--, y1--, y2--;
			if (A[y1][x1][y2][x2] != -1){
				printf("%d\n", A[y1][x1][y2][x2]);
				continue;
			}
			for (int p = y1; p <= y2; p++){
				for (int q = x1; q <= x2; q++){
					for (int k = q, h = p - y1 + 1; k >= x1; k--){
						if (h > H[p][k])
							h = H[p][k];
						if (h == 0)
							break;
						ans += h;
					}
				}
			}
			A[y1][x1][y2][x2] = ans;
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*

D. Counting Rectangles is Fun
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is an n × m rectangular grid, each cell of the grid contains a single integer: zero or one. Let's call the cell on the i-th row and the j-th column as (i, j).

Let's define a "rectangle" as four integers a, b, c, d (1 ≤ a ≤ c ≤ n; 1 ≤ b ≤ d ≤ m). Rectangle denotes a set of cells of the grid {(x, y) :  a ≤ x ≤ c, b ≤ y ≤ d}. Let's define a "good rectangle" as a rectangle that includes only the cells with zeros.

You should answer the following q queries: calculate the number of good rectangles all of which cells are in the given rectangle.

Input
There are three integers in the first line: n, m and q (1 ≤ n, m ≤ 40, 1 ≤ q ≤ 3·105). Each of the next n lines contains m characters — the grid. Consider grid rows are numbered from top to bottom, and grid columns are numbered from left to right. Both columns and rows are numbered starting from 1.

Each of the next q lines contains a query — four integers that describe the current rectangle, a, b, c, d (1 ≤ a ≤ c ≤ n; 1 ≤ b ≤ d ≤ m).

Output
For each query output an answer — a single integer in a separate line.

Sample test(s)
input
5 5 5
00101
00000
00001
01000
00001
1 2 2 4
4 5 4 5
1 2 5 2
2 2 4 5
4 2 5 3
output
10
1
7
34
5
input
4 7 5
0000100
0000010
0011000
0000000
1 7 2 7
3 1 3 1
2 3 4 5
1 2 2 7
2 2 4 7
output
3
1
16
27
52
Note
For the first example, there is a 5 × 5 rectangular grid, and the first, the second, and the third queries are represented in the following image.


For the first query, there are 10 good rectangles, five 1 × 1, two 2 × 1, two 1 × 2, and one 1 × 3.
For the second query, there is only one 1 × 1 good rectangle.
For the third query, there are 7 good rectangles, four 1 × 1, two 2 × 1, and one 3 × 1.

*/