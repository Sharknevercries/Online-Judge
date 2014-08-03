/* 5838116	 Jan 30, 2014 3:40:48 PM	Shark	 383B - Volcanoes	 GNU C++	Accepted	46 ms	2300 KB */
#include<cstdio>
#include<algorithm>
#define max(x,y) ( (x) >= (y) ? (x) : (y) )
#define MAX 100000
#define INF 2e9
using namespace std;
struct range{
	int L, R;
};
struct block{
	int x, y;
};
bool cmp(struct block A, struct block B){
	return  A.x < B.x || (A.x == B.x&&A.y < B.y);
}
struct range pre[MAX + 10], cur[MAX + 10];
struct block B[MAX + 1];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i < m; i++)
			scanf("%d%d", &B[i].x, &B[i].y);
		sort(B, B + m, cmp);
		int cntPre = 1, cntCur = 0;
		pre[0].L = pre[0].R = 1;
		
		for (int i = 0; i < m; ){
			if ((i == 0 && B[i].x != 1) || (i - 1 >= 0 && B[i].x != B[i - 1].x + 1)){
				cntPre = 1;
				pre[0].R = n;
			}

			int end;
			for (end = i; B[end].x == B[i].x&&end < m; end++);
			cntCur = 0;
			int L = 1;
			for (int j = i; j < end; j++){ // find current line range
				if (B[j].y - 1 >= L){
					cur[cntCur].L = L;
					cur[cntCur++].R = B[j].y - 1;
				}
				L = B[j].y + 1;
			}
			if (L <= n){
				cur[cntCur].L = L;
				cur[cntCur++].R = n;
			}

			for (int j = 0; j < cntCur; j++){ // compare cur with prev
				int Left, Right, boundry;
				Left = 0, Right = cntPre - 1, boundry = -1;
				while (Left <= Right){
					int Mid = (Left + Right) / 2;
					if (pre[Mid].R >= cur[j].L){
						boundry = pre[Mid].L;
						Right = Mid - 1;
					}
					else
						Left = Mid + 1;
				}
				if (boundry == -1 || boundry > cur[j].R)
					cur[j].L = cur[j].R = INF;
				else
					cur[j].L = max(cur[j].L, boundry);
			}
			cntPre = 0;
			for (int j = 0; j < cntCur; j++){
				if (cur[j].L != INF&&cur[j].R != INF)
					pre[cntPre++] = cur[j];
			}
			if (cntPre == 0){
				puts("-1");
				return 0;
			}
			i = end;
		}
		if (B[m - 1].x != n){
			cntPre = 1;
			pre[0].R = n;
		}
		if (pre[cntPre - 1].R == n)
			printf("%d\n", 2 * (n - 1));
		else
			puts("-1");
	}
	return 0;
}
/*

B. Volcanoes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Iahub got lost in a very big desert. The desert can be represented as a n × n square matrix, where each cell is a zone of the desert. The cell (i, j) represents the cell at row i and column j (1 ≤ i, j ≤ n). Iahub can go from one cell (i, j) only down or right, that is to cells (i + 1, j) or (i, j + 1).

Also, there are m cells that are occupied by volcanoes, which Iahub cannot enter.

Iahub is initially at cell (1, 1) and he needs to travel to cell (n, n). Knowing that Iahub needs 1 second to travel from one cell to another, find the minimum time in which he can arrive in cell (n, n).

Input
The first line contains two integers n (1 ≤ n ≤ 109) and m (1 ≤ m ≤ 105). Each of the next m lines contains a pair of integers, x and y (1 ≤ x, y ≤ n), representing the coordinates of the volcanoes.

Consider matrix rows are numbered from 1 to n from top to bottom, and matrix columns are numbered from 1 to n from left to right. There is no volcano in cell (1, 1). No two volcanoes occupy the same location.

Output
Print one integer, the minimum time in which Iahub can arrive at cell (n, n). If no solution exists (there is no path to the final cell), print -1.

Sample test(s)
input
4 2
1 3
1 4
output
6
input
7 8
1 6
2 6
3 5
3 6
4 3
5 1
5 2
5 3
output
12
input
2 2
1 2
2 1
output
-1
Note
Consider the first sample. A possible road is: (1, 1)  →  (1, 2)  →  (2, 2)  →  (2, 3)  →  (3, 3)  →  (3, 4)  →  (4, 4).

*/