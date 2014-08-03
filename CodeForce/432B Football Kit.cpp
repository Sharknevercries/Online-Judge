/* 6624689	 May 15, 2014 7:52:17 PM	Shark	 B - Football Kit	 GNU C++	Accepted	 93 ms	 1500 KB */
#include<cstdio>
#include<string.h>
int M[100000][2];
int S[100001][2];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(M, 0, sizeof(M));
		memset(S, 0, sizeof(S));
		for (int i = 0; i < n; i++)
			scanf("%d%d", &M[i][0], &M[i][1]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++)
				S[M[i][j]][j]++;
		for (int i = 0; i < n; i++)
			printf("%d %d\n", n - 1 + S[M[i][1]][0], n - 1 - S[M[i][1]][0]);
	}
	return 0;
}
/*

B. Football Kit
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider a football tournament where n teams participate. Each team has two football kits: for home games, and for away games. The kit for home games of the i-th team has color xi and the kit for away games of this team has color yi (xi ≠ yi).

In the tournament, each team plays exactly one home game and exactly one away game with each other team (n(n - 1) games in total). The team, that plays the home game, traditionally plays in its home kit. The team that plays an away game plays in its away kit. However, if two teams has the kits of the same color, they cannot be distinguished. In this case the away team plays in its home kit.

Calculate how many games in the described tournament each team plays in its home kit and how many games it plays in its away kit.

Input
The first line contains a single integer n (2 ≤ n ≤ 105) — the number of teams. Next n lines contain the description of the teams. The i-th line contains two space-separated numbers xi, yi (1 ≤ xi, yi ≤ 105; xi ≠ yi) — the color numbers for the home and away kits of the i-th team.

Output
For each team, print on a single line two space-separated integers — the number of games this team is going to play in home and away kits, correspondingly. Print the answers for the teams in the order they appeared in the input.

Sample test(s)
input
2
1 2
2 1
output
2 0
2 0
input
3
1 2
2 1
1 3
output
3 1
4 0
2 2

*/