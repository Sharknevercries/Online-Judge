/* 14004079	183	Bit Maps	Accepted	C++	0.016	2014-08-07 14:23:21 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 600
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
// main
struct rectangle{
	int L, T;
	int R, D;
	rectangle(int a, int b, int c, int d){
		L = a, T = b, R = c, D = d;
	}
	rectangle leftTop(){ return rectangle(L, T, (L + R) / 2, (T + D) / 2); }
	rectangle rightTop(){ return rectangle((L + R) / 2 + 1, T, R, (T + D) / 2); }
	rectangle leftDown(){ return rectangle(L, (T + D) / 2 + 1, (L + R) / 2, D); }
	rectangle rightDown(){ return rectangle((L + R) / 2 + 1, (T + D) / 2 + 1, R, D); }
};
int n, m;
char str[MAX_N * MAX_N];
char res2[MAX_N * MAX_N];
char res1[MAX_N][MAX_N];
int ptr1, ptr2;
void DFS1(rectangle r){
	if (r.L > r.R || r.T > r.D || r.L >= m || r.R >= m || r.D >= n || r.T >= n)	return;
	if (str[ptr1] == 'D'){
		ptr1++;
		DFS1(r.leftTop());
		DFS1(r.rightTop());
		DFS1(r.leftDown());
		DFS1(r.rightDown());
	}
	else{
		for (int i = r.L; i <= r.R; i++)
			for (int j = r.T; j <= r.D; j++)
				res1[j][i] = str[ptr1];
		ptr1++;
	}
}
void DFS2(rectangle r, char T[][MAX_N + 5]){
	if (r.L > r.R || r.T > r.D || r.L >= m || r.R >= m || r.D >= n || r.T >= n)	return;
	bool same = true;
	for (int i = r.T; i <= r.D && same; i++)
		for (int j = r.L; j <= r.R && same; j++)
			if (T[i][j] != T[r.T][r.L])
				same = false;
	if (same)
		res2[ptr2++] = T[r.T][r.L];
	else{
		res2[ptr2++] = 'D';
		DFS2(r.leftTop(), T);
		DFS2(r.rightTop(), T);
		DFS2(r.leftDown(), T);
		DFS2(r.rightDown(), T);
	}
}
int main(){
	char S[MAX_N], c;
	gets(S);
	while (sscanf(S, "%c%d%d", &c, &n, &m) == 3){
		printf("%c%4d%4d\n",c == 'D' ? 'B' : 'D', n, m);
		if (n == 0 && m == 0){ puts(""); gets(S); continue; }
		str[0] = '\0';
		while (gets(S)){
			int len = strlen(S), re = 0;
			for (int i = 0; i < len; i++)
				if (S[i] == ' ')
					re = 1;
			if (re == 1)    break;
			strcat(str, S);
		}
		if (c == 'D'){
			ptr1 = 0;
			DFS1(rectangle(0, 0, m - 1, n - 1));
			for (int i = 0, k = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if ((++k) == 51)
						putchar('\n'), k = 1;
					putchar(res1[i][j]);
				}
			}
			putchar('\n');
		}
		else{
			char T[MAX_N + 5][MAX_N + 5];
			ptr2 = 0;
			for (int i = 0, k = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					T[i][j] = str[k++];
			DFS2(rectangle(0, 0, m - 1, n - 1), T);
			for (int i = 0, k = 0; i < ptr2; i++){
				if ((++k) == 51)
					putchar('\n'), k = 1;
				putchar(res2[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}
/*

Bit Maps

The bitmap is a data structure that arises in many areas of computing. In the area of graphics, for example, a bitmap can represent an image by having a 1 represent a black pixel and a 0 represent a white pixel.

Consider the following two ways of representing a rectangular bit map. In the first, it is simply represented as a two dimensional array of 1s and 0s. The second is based on a decomposition technique. First, the entire bit map is considered. If all bits within it are 1, a 1 is output. If all bits within it are 0, a 0 is output. Otherwise, a D is output, the bit map is divided into quarters (as described below), and each of those is processed in the same way as the original bit map. The quarters are processed in top left, top right, bottom left, bottom right order. Where a bit map being divided has an even number of rows and an even number of columns, all quarters have the same dimensions. Where the number of columns is odd, the left quarters have one more column than the right. Where the number of rows is odd the top quarters have one more row than the bottom. Note that if a region having only one row or one column is divided then two halves result, with the top half processed before the bottom where a single column is divided, and the left half before the right if a single row is divided.

Write a program that will read in bitmaps of either form and transform them to the other form.

Input

Input will consist of a series of bit maps. Each bit map begins with a line giving its format (``B'' or ``D'') and its dimensions (rows and columns). Neither dimension will be greater than 200. There will be at least one space between each of the items of information. Following this line will be one or more lines containing the sequence of ``1'', ``0'' and ``D'' characters that represent the bit map, with no intervening spaces. Each line (except the last, which may be shorter) will contain 50 characters. A ``B'' type bitmap will be written left to right, top to bottom. The file will be terminated by a line consisting of a single #.

Output

Output will consist of a series of bitmaps, one for each bit map of the input. Output of each bit map begins on a new line and will be in the same format as the input. The width and height are to be output right justified in fields of width four.

Sample input

B 3  4
001000011011
D  2   3
DD10111
#
Sample output

D   3   4
D0D1001D101
B   2   3
101111

*/