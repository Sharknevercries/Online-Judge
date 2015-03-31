/* 3903400	2015-03-30 15:15:24	Accepted	3471	C++	90	292	840502 */
#include<bits\stdc++.h>
using namespace std;
int n;
long long DP[2050];
long long w[15][15];
bool check(int state){
	int tmp = ((1 << n) - 1) - state;
	int res = 0;
	for (; tmp > 0; tmp >>= 1)
		res += tmp & 1;
	return res == 1;
}
long long DFS(int state){
	if (check(state))	return 0;
	if (DP[state] != -1)	return DP[state];
	long long &res = DP[state];
	for (int i = 0; i < n; i++){
		if (state & (1 << i))	continue;
		for (int j = 0; j < n; j++){
			if ((state & (1 << j)) || i == j) continue;
			long long res1 = DFS(state | (1 << i)) + w[j][i];
			long long res2 = DFS(state | (1 << j)) + w[i][j];
			res = max(res, max(res1, res2));
		}
	}
	return res;
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &w[i][j]);
		printf("%lld\n", DFS(0));
	}
	return 0;
}
/*

Most Powerful
Time Limit: 2 Seconds      Memory Limit: 65536 KB
Recently, researchers on Mars have discovered N powerful atoms. All of them are different. These atoms have some properties. When two of these atoms collide, one of them disappears and a lot of power is produced. Researchers know the way every two atoms perform when collided and the power every two atoms can produce.

You are to write a program to make it most powerful, which means that the sum of power produced during all the collides is maximal.

Input

There are multiple cases. The first line of each case has an integer N (2 <= N <= 10), which means there are N atoms: A1, A2, ... , AN. Then N lines follow. There are N integers in each line. The j-th integer on the i-th line is the power produced when Ai and Aj collide with Aj gone. All integers are positive and not larger than 10000.

The last case is followed by a 0 in one line.

There will be no more than 500 cases including no more than 50 large cases that N is 10.

Output

Output the maximal power these N atoms can produce in a line for each case.

Sample Input

2
0 4
1 0
3
0 20 1
12 0 1
1 10 0
0

Sample Output

4
22
Author: GAO, Yuan
Contest: ZOJ Monthly, February 2011

*/