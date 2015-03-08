/* 13931633	840502	2759	Accepted	948K	2579MS	G++	1513B	2015-03-05 20:49:25 */
#include<bits\stdc++.h>
using namespace std;
int n, m;
int w[2][10005];
int DP[10005];
int mark[3][20005];
bool judge(int s){
	for (int i = 0, sum, p; i < 3; i++){
		sum = p = 0;
		for (int j = 1; j <= n; j++){
			if (i == 2)
				sum += w[0][j] + w[1][j];
			else
				sum += w[i][j];
			while (sum > s && p != j){
				p++;
				if (i == 2)
					sum -= w[0][p] + w[1][p];
				else
					sum -= w[i][p];
			}
			mark[i][j] = p;
			if (i != 2 && p == j)	return false;
		}
	}
	DP[0] = 0;
	for (int i = 1; i <= n; i++){
		DP[i] = 2e9;
		if (mark[2][i] != i)
			DP[i] = min(DP[i], DP[mark[2][i]] + 1);
		int a, b, c;
		a = b = i, c = 0;
		while (a || b){
			c++;
			if (a > b)
				a = mark[0][a];
			else
				b = mark[1][b];
			if (a > b)
				DP[i] = min(DP[i], DP[a] + c);
			else
				DP[i] = min(DP[i], DP[b] + c);
		}
		if (DP[i] > m)	return false;
	}
	return true;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		int L = 0, R = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &w[i][j]), R += w[i][j], L = max(L, w[i][j]);
		while (R > L){
			int mid = (L + R) / 2;
			if (judge(mid))
				R = mid;
			else
				L = mid + 1;
		}
		printf("%d\n", L);

	}
	return 0;
}
/*

Distributing tasks
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 1264		Accepted: 294
Description

One day, Jiajia and Wind went out to plant trees with their m-2 children. They believe that trees should be in couples, just like human beings, so they decided to plant an even number of trees, say, 2n trees, in two rows, with n trees in each row. Planting some trees are more difficult than planting some others, so Jiajia carefully measured the difficulty value of each tree and wants to divide the trees into m sets, one for each of the m people to work with.

Each of the m people should plant all the trees in a rectangular with sides parallel to the axis. The difficulty value of a person is the sum of difficulty values of all trees he plants. Since Jiajia should always take the heaviest job (no, he can't leave the most difficult task to his honey, Wind, or their lovely children), Jiajia would like to make his own life easier by minimizing the maximal difficulty value over all the m tasks.

The figure of sample input is below. Different colors represent different jobs. There are only 3 people (Jiajia, Wind and Autumn) in this sample, but your program should be able to handle more complex situations, in which Jiajia and Wind have a loooooot of chilren :)


Input

The first line of input contains two integers n and m, the following two lines contain n integers each, representing the difficulty values of each tree, from left to right. You may assume that n<10001, m<=min{2*n,1000}. The sum of all difficulty values would not exceed 230.
Output

The output should contain a single integer, the minimized difficulty value of Jiajia's task.
Sample Input

3 3
1 2 6
2 1 6
Sample Output

6
Source

POJ Monthly--2006.02.26,zgl & twb

*/