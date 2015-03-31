/* 14015116	840502	1185	Accepted	2720K	282MS	G++	1813B	2015-03-27 19:55:39 */
#include<bits\stdc++.h>
using namespace std;
int n, m;
int T[105];
int DP[105][70][70];
int state[70], digit[70],  ptr;
bool check1(int state1){
	if (state1 & (state1 << 1))	return false;
	if (state1 & (state1 << 2))	return false;
	return true;
}
bool check2(int state1, int row){
	if (state1 & T[row])
		return false;
	return true;
}
int countDigit(int s){
	int res = 0;
	for (; s > 0; s >>= 1)
		res += (s & 1);
	return res;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		memset(T, 0, sizeof(T));
		char str[100];
		for (int i = 0; i < n; i++){
			scanf("%s", str);
			for (int j = 0; j < m; j++)
				if (str[j] == 'H')
					T[i] += (1 << j);
		}
		ptr = 0;
		for (int i = 0; i < (1 << m); i++)
			if (check1(i))
				state[ptr++] = i;
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < ptr; i++)
			digit[i] = countDigit(state[i]);
		for (int i = 0; i < ptr; i++)
			if (check2(state[i], 0))
				DP[0][i][0] = digit[i];
		for (int i = 1; i < n; i++){
			for (int j = 0; j < ptr; j++){
				if (!check2(state[j], i))	continue;
				for (int k = 0; k < ptr; k++){
					if (state[j] & state[k])	continue;
					for (int t = 0; t < ptr; t++){
						if (state[j] & state[t])	continue;
						if (DP[i - 1][k][t] == -1)	continue;
						DP[i][j][k] = max(DP[i][j][k], DP[i - 1][k][t] + digit[j]);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < ptr; j++)
				for (int k = 0; k < ptr;k++)
					ans = max(ans, DP[i][j][k]);
		printf("%d\n", ans);
	}
	return 0;
}
/*

炮兵阵地
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 20659		Accepted: 7994
Description

司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：


如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
Input

第一行包含两个由空格分割开的正整数，分别表示N和M；
接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。N <= 100；M <= 10。
Output

仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
Sample Input

5 4
PHPP
PPHH
PPPP
PHPP
PHHP
Sample Output

6
Source

Noi 01

*/