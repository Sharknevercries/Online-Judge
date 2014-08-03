/* 5368384	 Dec 7, 2013 11:22:42 AM	Shark	 370B - Berland Bingo	 GNU C++	Accepted	 15 ms	 200 KB */
#include<stdio.h>
#include<vector>
#include<algorithm>
std::vector<int> S[100];
bool contain(int a,int b){
	int i, j;
	for (i = 0, j = 0; i < S[a].size() && j < S[b].size();){
		if (S[a][i] == S[b][j])
			i++, j++;
		else
			i++;
	}
	if (j >= S[b].size())
		return true;
	else
		return false;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++){
			S[i].clear();
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++){
				int tmp;
				scanf("%d", &tmp);
				S[i].push_back(tmp);
			}
			std::sort(S[i].begin(), S[i].end());
		}
		for (int i = 0; i < n; i++){
			bool ans = true;
			for (int j = 0; j < n; j++){
				if (i != j && contain(i, j))
					ans = false;
			}
			if (ans)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
/*

B. Berland Bingo
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lately, a national version of a bingo game has become very popular in Berland. There are n players playing the game, each player has a card with numbers. The numbers on each card are distinct, but distinct cards can have equal numbers. The card of the i-th player contains mi numbers.

During the game the host takes numbered balls one by one from a bag. He reads the number aloud in a high and clear voice and then puts the ball away. All participants cross out the number if it occurs on their cards. The person who crosses out all numbers from his card first, wins. If multiple people cross out all numbers from their cards at the same time, there are no winners in the game. At the beginning of the game the bag contains 100 balls numbered 1 through 100, the numbers of all balls are distinct.

You are given the cards for each player. Write a program that determines whether a player can win the game at the most favorable for him scenario or not.

Input
The first line of the input contains integer n (1 ≤ n ≤ 100) — the number of the players. Then follow n lines, each line describes a player's card. The line that describes a card starts from integer mi (1 ≤ mi ≤ 100) that shows how many numbers the i-th player's card has. Then follows a sequence of integers ai, 1, ai, 2, ..., ai, mi (1 ≤ ai, k ≤ 100) — the numbers on the i-th player's card. The numbers in the lines are separated by single spaces.

It is guaranteed that all the numbers on each card are distinct.

Output
Print n lines, the i-th line must contain word "YES" (without the quotes), if the i-th player can win, and "NO" (without the quotes) otherwise.

Sample test(s)
input
3
1 1
3 2 4 1
2 10 11
output
YES
NO
YES
input
2
1 1
1 1
output
NO
NO

*/