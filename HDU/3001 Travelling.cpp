/* 13277798	2015-03-29 01:40:10	Accepted	3001	1887MS	6508K	1659 B	G++	Shark */
#include<bits\stdc++.h>
using namespace std;
int n, m;
int dist[15][15];
int DP[80000][15];
int pow3[15] = { 1 };
int ans;
inline int getHash(int state, int i){
	return (state / pow3[i]) % 3;
}
inline int setHash(int state, int i, int value){
	return state - (getHash(state, i)) * pow3[i] + value * pow3[i];
}
bool check(int state){
	bool res = true;
	for (int i = 0; i < n; i++)
		res &= getHash(state, i) > 0;
	return res;
}
int DFS(int state, int start){
	if (check(state))	return 0;
	if (DP[state][start] != -1)	return DP[state][start];
	int &res = DP[state][start];
	res = 1e9;
	for (int i = 0; i < n; i++){
		if (i == start)	continue;
		int time = getHash(state, i);
		if (time == 2)	continue;
		if (dist[start][i] == 1e9)	continue;
		res = min(res, dist[start][i] + DFS(setHash(state, i, time + 1), i));
	}
	return res;
}
int main(){
	for (int i = 1; i <= 12; i++)
		pow3[i] = pow3[i - 1] * 3;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = 1e9;
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			a--, b--;
			dist[a][b] = min(dist[a][b], w);
			dist[b][a] = min(dist[b][a], w);
		};
		memset(DP, -1, sizeof(DP));
		ans = 1e9;
		for (int i = 0; i < n; i++)
			ans = min(ans, DFS(pow3[i], i));
		printf("%d\n", ans == 1e9 ? -1 : ans);
	}
	return 0;
}
/*

Travelling

Time Limit: 6000/3000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 4684    Accepted Submission(s): 1545

Problem Description
After coding so many days,Mr Acmer wants to have a good rest.So travelling is the best choice!He has decided to visit n cities(he insists on seeing all the cities!And he does not mind which city being his start station because superman can bring him to any city at first but only once.), and of course there are m roads here,following a fee as usual.But Mr Acmer gets bored so easily that he doesn't want to visit a city more than twice!And he is so mean that he wants to minimize the total fee!He is lazy you see.So he turns to you for help.

Input
There are several test cases,the first line is two intergers n(1<=n<=10) and m,which means he needs to visit n cities and there are m roads he can choose,then m lines follow,each line will include three intergers a,b and c(1<=a,b<=n),means there is a road between a and b and the cost is of course c.Input to the End Of File.

Output
Output the minimum fee that he should pay,or -1 if he can't find such a route.

Sample Input
2 1
1 2 100
3 2
1 2 40
2 3 50
3 3
1 2 3
1 3 4
2 3 10

Sample Output
100
90
7

Source
2009 Multi-University Training Contest 11 - Host by HRBEU

Recommend
gaojie   |   We have carefully selected several similar problems for you:  3004 3002 3006 3007 3003

*/