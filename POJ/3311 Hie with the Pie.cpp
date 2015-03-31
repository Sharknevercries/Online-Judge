/* 14015594	840502	3311	Accepted	824K	16MS	G++	1153B	2015-03-27 21:07:53 */
#include<bits\stdc++.h>
using namespace std;
int n;
int dist[15][15];
int DP[2050][15];
int DFS(int start, int state){
	if (DP[state][start] != 1e9)	return DP[state][start];
	if (state & 1)	return 1e9;
	for (int i = 0; i < n; i++){
		if (state & (1 << i))	continue;
		int nextState = state | (1 << i);
		DP[state][start] = min(DP[state][start], dist[start][i] + DFS(i, nextState));
	}
	return DP[state][start];
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		n++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &dist[i][j]);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				DP[i][j] = 1e9;
		DP[(1 << n) - 1][0] = 0;
		printf("%d\n", DFS(0, 0));
	}
	return 0;
}
/*

Hie with the Pie
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 5104		Accepted: 2723
Description

The Pizazz Pizzeria prides itself in delivering pizzas to its customers as fast as possible. Unfortunately, due to cutbacks, they can afford to hire only one driver to do the deliveries. He will wait for 1 or more (up to 10) orders to be processed before he starts any deliveries. Needless to say, he would like to take the shortest route in delivering these goodies and returning to the pizzeria, even if it means passing the same location(s) or the pizzeria more than once on the way. He has commissioned you to write a program to help him.

Input

Input will consist of multiple test cases. The first line will contain a single integer n indicating the number of orders to deliver, where 1 ≤ n ≤ 10. After this will be n + 1 lines each containing n + 1 integers indicating the times to travel between the pizzeria (numbered 0) and the n locations (numbers 1 to n). The jth value on the ith line indicates the time to go directly from location i to location j without visiting any other locations along the way. Note that there may be quicker ways to go from i to j via other locations, due to different speed limits, traffic lights, etc. Also, the time values may not be symmetric, i.e., the time to go directly from location i to j may not be the same as the time to go directly from location j to i. An input value of n = 0 will terminate input.

Output

For each test case, you should output a single number indicating the minimum time to deliver all of the pizzas and return to the pizzeria.

Sample Input

3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
Sample Output

8
Source

East Central North America 2006

*/