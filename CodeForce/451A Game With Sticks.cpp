/* 7248310	2014-07-26 12:44:44	Shark	451A - Game With Sticks	GNU C++	Accepted	15 ms	0 KB */
/*

Template By Shark

*/
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int k = min(n, m);
		printf("%s\n", k & 1 ? "Akshat" : "Malvika");
	}
	return 0;
}
/*

A. Game With Sticks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
After winning gold and silver in IOI 2014, Akshat and Malvika want to have some fun. Now they are playing a game on a grid made of n horizontal and m vertical sticks.

An intersection point is any point on the grid which is formed by the intersection of one horizontal stick and one vertical stick.

In the grid shown below, n = 3 and m = 3. There are n + m = 6 sticks in total (horizontal sticks are shown in red and vertical sticks are shown in green). There are n·m = 9 intersection points, numbered from 1 to 9.

The rules of the game are very simple. The players move in turns. Akshat won gold, so he makes the first move. During his/her move, a player must choose any remaining intersection point and remove from the grid all sticks which pass through this point. A player will lose the game if he/she cannot make a move (i.e. there are no intersection points remaining on the grid at his/her move).

Assume that both players play optimally. Who will win the game?

Input
The first line of input contains two space-separated integers, n and m (1 ≤ n, m ≤ 100).

Output
Print a single line containing "Akshat" or "Malvika" (without the quotes), depending on the winner of the game.

Sample test(s)
input
2 2
output
Malvika
input
2 3
output
Malvika
input
3 3
output
Akshat
Note
Explanation of the first sample:

The grid has four intersection points, numbered from 1 to 4.

If Akshat chooses intersection point 1, then he will remove two sticks (1 - 2 and 1 - 3). The resulting grid will look like this.

Now there is only one remaining intersection point (i.e. 4). Malvika must choose it and remove both remaining sticks. After her move the grid will be empty.

In the empty grid, Akshat cannot make any move, hence he will lose.

Since all 4 intersection points of the grid are equivalent, Akshat will lose no matter which one he picks.

*/