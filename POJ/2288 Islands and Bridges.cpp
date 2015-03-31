/* 14024845	840502	2288	Accepted	35904K	829MS	G++	2254B	2015-03-29 23:30:59 */
#include<bits\stdc++.h>
using namespace std;
int q, n, m;
int w[15];
long long DP[10000][15][15];
long long way[10000][15][15];
bool c[15][15];
int main(){
	scanf("%d", &q);
	while (q--){
		memset(DP, -1, sizeof(DP));
		memset(way, 0, sizeof(way));
		memset(c, false, sizeof(c));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", w + i);
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			c[a][b] = c[b][a] = true;
		}
		if (n == 1){
			printf("%d %d\n", w[0], 1);
			continue;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j || !c[i][j])	continue;
				int state = (1 << i) + (1 << j);
				DP[state][i][j] = w[j] + w[i] + w[i] * w[j], way[state][i][j] = 1;
			}
		}
		for (int state = 0; state < (1 << n); state++){
			for (int i = 0; i < n; i++){
				if (!(state & (1 << i)))	continue;
				for (int j = 0; j < n; j++){
					if (!(state & (1 << j)) || i == j || !c[i][j])	continue;
					for (int k = 0; k < n; k++){
						if (!(state & (1 << k)) || i == k || j == k || !c[j][k])	continue;
						int prevState = state ^ (1 << i);
						if (DP[prevState][j][k] == -1)	continue;
						int value = DP[prevState][j][k] + w[i] + w[i] * w[j];
						if (c[i][k])	value += w[i] * w[j] * w[k];
						if (DP[state][i][j] < value){
							DP[state][i][j] = value;
							way[state][i][j] = way[prevState][j][k];
						}
						else if (DP[state][i][j] == value)
							way[state][i][j] += way[prevState][j][k];
					}
				}
			}
		}
		long long ans = -1, count = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j)	continue;
				if (DP[(1 << n) - 1][i][j] > ans){
					ans = DP[(1 << n) - 1][i][j];
					count = way[(1 << n) - 1][i][j];
				}
				else if (DP[(1 << n) - 1][i][j] == ans)
					count += way[(1 << n) - 1][i][j];
			}
		}
		if (ans == -1)
			ans = count = 0;
		printf("%lld %lld\n", ans, count / 2);
	}
	return 0;
}
/*

Islands and Bridges
Time Limit: 4000MS		Memory Limit: 65536K
Total Submissions: 9352		Accepted: 2434
Description

Given a map of islands and bridges that connect these islands, a Hamilton path, as we all know, is a path along the bridges such that it visits each island exactly once. On our map, there is also a positive integer value associated with each island. We call a Hamilton path the best triangular Hamilton path if it maximizes the value described below.

Suppose there are n islands. The value of a Hamilton path C1C2...Cn is calculated as the sum of three parts. Let Vi be the value for the island Ci. As the first part, we sum over all the Vi values for each island in the path. For the second part, for each edge CiCi+1 in the path, we add the product Vi*Vi+1. And for the third part, whenever three consecutive islands CiCi+1Ci+2 in the path forms a triangle in the map, i.e. there is a bridge between Ci and Ci+2, we add the product Vi*Vi+1*Vi+2.

Most likely but not necessarily, the best triangular Hamilton path you are going to find contains many triangles. It is quite possible that there might be more than one best triangular Hamilton paths; your second task is to find the number of such paths.

Input

The input file starts with a number q (q<=20) on the first line, which is the number of test cases. Each test case starts with a line with two integers n and m, which are the number of islands and the number of bridges in the map, respectively. The next line contains n positive integers, the i-th number being the Vi value of island i. Each value is no more than 100. The following m lines are in the form x y, which indicates there is a (two way) bridge between island x and island y. Islands are numbered from 1 to n. You may assume there will be no more than 13 islands.
Output

For each test case, output a line with two numbers, separated by a space. The first number is the maximum value of a best triangular Hamilton path; the second number should be the number of different best triangular Hamilton paths. If the test case does not contain a Hamilton path, the output must be `0 0'.

Note: A path may be written down in the reversed order. We still think it is the same path.
Sample Input

2
3 3
2 2 2
1 2
2 3
3 1
4 6
1 2 3 4
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output

22 3
69 1
Source

Shanghai 2004

*/