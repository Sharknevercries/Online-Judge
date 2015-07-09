/* 14292013	11859	Division Game	Accepted	C++	0.122	2014-10-01 15:30:34 */
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
#define MAX_N 10005
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
int primeFactor(int x){
	int res = 0;
	for (int i = 2; i <= x; i++)
		while (x%i == 0)
			res++, x /= i;
	if (x > 1)
		res++;
	return res;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		int n, m, k, res = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++){
			k = 0;
			for (int j = 0; j < m; j++){
				int tmp;
				scanf("%d", &tmp);
				k += primeFactor(tmp);
			}
			res ^= k;
		}
		printf("Case #%d: ", c++);
		puts(res == 0 ? "NO" : "YES");
	}
	return 0;
}
/*

A
Division Game
Input: Standard Input
Output: Standard Output

Division game is a 2-player game. In this game, there is a matrix of positive integers with N rows and M columns. Players make their moves in turns. In each step, the current player selects a row. If the row contains all 1s, the player looses. Otherwise, the player can select any number of integers (but at least 1 and each of them should be greater than 1) from that row and then divides each of the selected integers with any divisor other than 1.  For example, 6 can be divided by 2, 3 and 6, but cannot be divided by 1, 4 and 5. The player who first makes the matrix all 1s wins. In other words, if in his/her move, player gets the matrix with all 1s, then he/she looses. Given the matrix, your task is to determine whether the first player wins or not. Assume that both of the players will play perfectly to win.

Input
The first line has a positive integer T, T <= 50, denoting the number of test cases. This is followed by each test case per line.

Each test case starts with a line containing 2 integers N and M representing the number of rows and columns respectively. Both N and M are between 1 and 50 inclusive. Each of the next N line each contains M integers. All these integers are between 2 and 10000 inclusive.


Output
For each test case, the output contains a line in the format Case #x: M, where x is the case number (starting from 1) and M is ¡§YES¡¨ when the first player has a winning strategy  and ¡§NO¡¨ otherwise.


Sample Input                              Output for Sample Input
5
2 2
2 3
2 3
2 2
4 9
8 5
3 3
2 3 5
3 9 2
8 8 3
3 3
3 4 5
4 5 6
5 6 7
2 3
4 5 6
7 8 9
Case #1: NO
Case #2: NO
Case #3: NO
Case #4: YES
Case #5: YES

Problemsetter: Abdullah-al-Mahmud, Special Thanks: Manzurur Rahman Khan

*/