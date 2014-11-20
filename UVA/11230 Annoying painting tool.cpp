/* 14240155	11230	Annoying painting tool	Accepted	C++	0.066	2014-09-21 08:12:23 */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 105
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
void flip(char &c){
	if (c == '0')
		c = '1';
	else
		c = '0';
}
int main(){
	int n, m, r, c;
	while (scanf("%d%d%d%d", &n, &m, &r, &c) == 4){
		if (n == 0 && m == 0 && r == 0 && c == 0)	break;
		char S[MAX_N][MAX_N], T[MAX_N][MAX_N];
		for (int i = 0; i < n; i++)
			scanf("%s", S + i);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				T[i][j] = '0';
		int ans = 0;
		for (int i = 0; i < n - r + 1; i++){
			for (int j = 0; j < m - c + 1; j++){
				if (S[i][j] != T[i][j]){
					for (int p = 0; p < r; p++)
						for (int q = 0; q < c; q++)
							flip(T[i + p][j + q]);
					ans++;
				}
			}
		}
		bool res = true;
		for (int i = 0; i < n&&res; i++)
			for (int j = 0; j < m&&res; j++)
				if (S[i][j] != T[i][j])
					res = false;
		if (res)
			printf("%d\n", ans);
		else
			printf("%d\n", -1);
	}
	return 0;
}
/*

2007/2008 ACM International Collegiate Programming Contest
University of Ulm Local Contest
Problem A: Annoying painting tool

Maybe you wonder what an annoying painting tool is? First of all, the painting tool we speak of supports only black and white. Therefore, a picture consists of a rectangular area of pixels, which are either black or white. Second, there is only one operation how to change the colour of pixels:

Select a rectangular area of r rows and c columns of pixels, which is completely inside the picture. As a result of the operation, each pixel inside the selected rectangle changes its colour (from black to white, or from white to black).

Initially, all pixels are white. To create a picture, the operation described above can be applied several times. Can you paint a certain picture which you have in mind?

Input Specification

The input contains several test cases. Each test case starts with one line containing four integers n, m, r and c. (1 ≤ r ≤ n ≤ 100, 1 ≤ c ≤ m ≤ 100), The following n lines each describe one row of pixels of the painting you want to create. The ith line consists of m characters describing the desired pixel values of the ith row in the finished painting ('0' indicates white, '1' indicates black).

The last test case is followed by a line containing four zeros.

Output Specification

For each test case, print the minimum number of operations needed to create the painting, or -1 if it is impossible.

Sample Input

3 3 1 1
010
101
010
4 3 2 1
011
110
011
110
3 4 2 2
0110
0111
0000
0 0 0 0
Sample Output

4
6
-1

*/