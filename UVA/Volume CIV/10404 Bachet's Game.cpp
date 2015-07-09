/* 14294247	10404	Bachet's Game	Accepted	C++	0.712	2014-10-02 02:34:47 */
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
#define MAX_N 1000005
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
int S[MAX_N];
bool T[15];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int Q[15];
		for (int i = 0; i < m; i++)
			scanf("%d", Q + i);
		S[0] = 0;
		for (int i = 1, j; i <= n; i++){
			memset(T, false, sizeof(T));
			for (j = 0; j < m; j++)
				if (i - Q[j] >= 0)
					T[S[i - Q[j]]] = true;
			for (j = 0; T[j]; j++);
			S[i] = j;
		}
		puts(S[n] == 0 ? "Ollie wins" : "Stan wins");
	}
	return 0;
}
/*

Problem B: Bachet's Game

Bachet's game is probably known to all but probably not by this name. Initially there are n stones on the table. There are two players Stan and Ollie, who move alternately. Stan always starts. The legal moves consist in removing at least one but not more than k stones from the table. The winner is the one to take the last stone.
Here we consider a variation of this game. The number of stones that can be removed in a single move must be a member of a certain set of m numbers. Among the m numbers there is always 1 and thus the game never stalls.

Input

The input consists of a number of lines. Each line describes one game by a sequence of positive numbers. The first number is n <= 1000000 the number of stones on the table; the second number is m <= 10 giving the number of numbers that follow; the last m numbers on the line specify how many stones can be removed from the table in a single move.
Input

For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly.
Sample input

20 3 1 3 8
21 3 1 3 8
22 3 1 3 8
23 3 1 3 8
1000000 10 1 23 38 11 7 5 4 8 3 13
999996 10 1 23 38 11 7 5 4 8 3 13
Output for sample input

Stan wins
Stan wins
Ollie wins
Stan wins
Stan wins
Ollie wins
Problem Setter: Piotr Rudnicki

*/