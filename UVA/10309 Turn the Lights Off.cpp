/* 14162020	10309	Turn the Lights Off	Accepted	C++	0.049	2014-09-07 08:35:44 */
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
#define MAX_N 1000
#define MAX_M 15
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
int minAns, ans;
char T[MAX_M][MAX_M];
void change(char &c){
	c = (c == '#') ? 'O' : '#';
}
void click(int row, int col){
	change(T[row][col]);
	for (int i = 0; i < 4; i++){
		int x = col + mx[i], y = row + my[i];
		if (x >= 10 || y >= 10 || x < 0 || y < 0)continue;
		change(T[y][x]);
	}
}
void DFS(int row){
	if (row == 10){
		bool res = false;
		for (int i = 0; i < 10; i++)
			res |= T[row - 1][i] == 'O';
		if (!res)
			minAns = min(minAns, ans);
		return;
	}
	if (ans > 100)return;
	int com = 0;
	for (int i = 9; i >= 0; i--, com <<= 1)
		if (T[row - 1][i] == 'O')
			com |= 1, ans++;
	com >>= 1;
	for (int j = com, k = 0; j > 0; j >>= 1, k++)
		if (j & 1)
			click(row, k);
	DFS(row + 1);
	for (int j = com, k = 0; j > 0; j >>= 1, k++)
		if (j & 1)
			click(row, k);
}
int main(){
	char str[MAX_N];
	while (scanf("%s", str) == 1){
		if (strcmp("end", str) == 0)break;
		for (int i = 0; i < 10; i++)
			scanf("%s", T[i]);
		minAns = INF;
		for (int i = 0; i < 1024; i++){
			ans = 0;
			for (int j = i, k = 0; j > 0; j >>= 1, k++)
				if (j & 1)
					click(0, k), ans++;
			DFS(1);
			for (int j = i, k = 0; j > 0; j >>= 1, k++)
				if (j & 1)
					click(0, k);
		}
		if (minAns > 100)
			puts("-1");
		else
			printf("%s %d\n", str, minAns);
	}
	return 0;
}
/*

Problem J
Turn the Lights Off
Input: standard input
Output: standard output
Time Limit: 3 seconds
Memory Limit: 32 MB

Since we all rely on mother earth, it's our duty to save her. Therefore, you're now asked to save energy by switching lights off.

A friend of yours has the following problem in his job. There's a grid of size 10x10, where each square has a light bulb and a light switch attached to it. Unfortunately, these lights don't work as they are supposed to. Whenever a switch is pressed, not only its own bulb is switched, but also the ones left, right, above and under it. Of course if a bulb is on the edge of the grid, there are fewer bulbs switched.

When a light switches it means it's now on if it was off before and it's now off if it was on before. Look at the following examples, which show only a small part of the whole grid. They show what happens if the middle switch is pressed. "O" stands for a light that's on, "#" stands for a light that's off.

###      #O#
###  ->  OOO
###      #O#

###      #O#
OOO  ->  ###
###      #O#
Your friend loves to save energy and asks you to write a program that finds out if it is possible to turn all the lights off and if possible then how many times he has to press switches in order to turn all the lights off.

Input
There are several test cases in the input. Each test case is preceded by a single word that gives a name for the test case. After that name there follow 10 lines, each of which contains a 10-letter string consisting of "#" and "O". The end of the input is reached when the name string is "end".
Output
For every test case, print one line that consists of the test case name, a single space character and the minimum number of times your friend has to press a switch. If it is not possible to switch off all the lights or requires more than 100 presses then the case name should be followed by space and then a -1.

Sample Input
all_off
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
all_on
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
simple
#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
########O#
#######OOO
########O#
end

Sample Output
all_off 0
all_on 44
simple 4
(The Joint Effort Contest, Problem setter: Stefan Pochmann)

*/