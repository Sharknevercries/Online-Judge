/* 13005438	2015-03-01 14:57:26	Accepted	4842	15MS	1160K	1623 B	G++	Shark */
#include<bits\stdc++.h>
using namespace std;
int L, s, t, n;
int rock[105];
int DP[105][15];
bool V[105];
bool arrive(int x){
	if (x < 0)	return false;
	if (x >= s*(s - 1))	return true;
	return V[x];
}
int main(){
	bool first = true;
	while (scanf("%d%d%d%d", &L, &s, &t, &n) == 4){
		for (int i = 1; i <= n; i++)
			scanf("%d", rock + i);
		memset(DP, 0, sizeof(DP));
		memset(V, false, sizeof(V));
		sort(rock + 1, rock + 1 + n);
		while (rock[n] > L)
			n--;
		int ans = 0;
		if (s == t){
			for (int i = 1; i <= n; i++)
				if (rock[i] % s == 0)
					ans++;
		}
		else{
			V[0] = true;
			for (int i = 1; i <= 90; i++)
				for (int j = s; j <= t; j++)
					V[i] |= V[i - j];
			for (int i = 0; i <= n; i++)
				for (int j = 0; j < t; j++)
					DP[i][j] = n + 1;
			rock[0] = 0, DP[0][0] = 0;
			for (int i = 1; i <= n; i++){
				for (int j = 0; j < t; j++){
					if (rock[i] - j <= rock[i - 1])
						DP[i][j] = DP[i - 1][j - rock[i] + rock[i - 1]];
					else{
						for (int k = 0; k < t; k++)
							if (arrive(rock[i] - j - rock[i - 1] + k))
								DP[i][j] = min(DP[i][j], DP[i - 1][k]);
						if (j == 0)
							DP[i][j]++;
					}
				}
			}
			ans = n + 1;
			for (int i = 0; i < t; i++)
				ans = min(ans, DP[n][i]);
		}
		if (!first)	putchar('\n');
		first = false;
		printf("%d", ans);
	}
	return 0;
}
/*

过河

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65535/32768 K (Java/Others)
Total Submission(s): 224    Accepted Submission(s): 12


Problem Description
　　在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧。在桥上有一些石子，青蛙很讨厌踩在这些石子上。由于桥的长度和青蛙一次跳过的距离都是正整数，我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。青蛙从桥的起点开始，不停的向终点方向跳跃。一次跳跃的距离是S到T之间的任意正整数（包括S,T）。当青蛙跳到或跳过坐标为L的点时，就算青蛙已经跳出了独木桥。
题目给出独木桥的长度L，青蛙跳跃的距离范围S,T，桥上石子的位置。你的任务是确定青蛙要想过河，最少需要踩到的石子数。


Input
  　　本题有多组数据。对于每一组数据来说：第一行有一个正整数L（1 <= L <= 109），表示独木桥的长度。第二行有三个正整数S，T，M，分别表示青蛙一次跳跃的最小距离，最大距离，及桥上石子的个数，其中1 <= S <= T <= 10，1 <= M <= 100。第三行有M个不同的正整数分别表示这M个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。


Output
	　　对于每一组数据，单独输出一行，只包括一个整数，表示青蛙过河最少需要踩到的石子数。(输出的最后没有多余的换行)


Sample Input
10
2 3 5
2 3 5 6 7


Sample Output
2


Source
NOIP2005


Recommend
We have carefully selected several similar problems for you:  5181 5180 5179 5178 5177
	  
	  
*/