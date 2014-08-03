/* 5420155	 Dec 13, 2013 4:06:24 PM	Shark	 356A - Knight Tournament	 GNU C++	Accepted	 202 ms	 7000 KB */
#include<cstdio>
int P[300001];
int M[300001];
int n, m;
int Next(int x, int W){
	if (x == n + 1)
		return n + 1;
	else if (W == x)
		return x;
	else
		return M[x] == 0 ? x : P[x] = Next(P[x], W);
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i <= n; i++)
			P[i] = i + 1, M[i] = 0;
		for (int i = 0; i < m; i++){
			int L, R, W;
			scanf("%d%d%d", &L, &R, &W);
			while ( true ){
				if (W == L)
					L = Next(P[L], W);
				else
					L = Next(L, W);
				if (L <= R){
					if (L != W)
						M[L] = W;
				}
				else
					break;
			}
		}
		printf("%d", M[1]);
		for (int i = 2; i <= n; i++)
			printf(" %d", M[i]);
		putchar('\n');
	}
	return 0;
}
/*

A. Knight Tournament
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Hooray! Berl II, the king of Berland is making a knight tournament. The king has already sent the message to all knights in the kingdom and they in turn agreed to participate in this grand event.

As for you, you're just a simple peasant. There's no surprise that you slept in this morning and were late for the tournament (it was a weekend, after all). Now you are really curious about the results of the tournament. This time the tournament in Berland went as follows:

There are n knights participating in the tournament. Each knight was assigned his unique number — an integer from 1 to n.
The tournament consisted of m fights, in the i-th fight the knights that were still in the game with numbers at least li and at most ri have fought for the right to continue taking part in the tournament.
After the i-th fight among all participants of the fight only one knight won — the knight number xi, he continued participating in the tournament. Other knights left the tournament.
The winner of the last (the m-th) fight (the knight number xm) became the winner of the tournament.
You fished out all the information about the fights from your friends. Now for each knight you want to know the name of the knight he was conquered by. We think that the knight number b was conquered by the knight number a, if there was a fight with both of these knights present and the winner was the knight number a.

Write the code that calculates for each knight, the name of the knight that beat him.

Input
The first line contains two integers n, m (2 ≤ n ≤ 3·105; 1 ≤ m ≤ 3·105) — the number of knights and the number of fights. Each of the following m lines contains three integers li, ri, xi (1 ≤ li < ri ≤ n; li ≤ xi ≤ ri) — the description of the i-th fight.

It is guaranteed that the input is correct and matches the problem statement. It is guaranteed that at least two knights took part in each battle.

Output
Print n integers. If the i-th knight lost, then the i-th number should equal the number of the knight that beat the knight number i. If the i-th knight is the winner, then the i-th number must equal 0.

Sample test(s)
input
4 3
1 2 1
1 3 3
1 4 4
output
3 1 4 0
input
8 4
3 5 4
3 7 6
2 8 8
1 8 1
output
0 8 4 6 4 8 6 1
Note
Consider the first test case. Knights 1 and 2 fought the first fight and knight 1 won. Knights 1 and 3 fought the second fight and knight 3 won. The last fight was between knights 3 and 4, knight 4 won.

*/