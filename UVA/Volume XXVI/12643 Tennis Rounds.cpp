/* 13062165	12643	Tennis Rounds	Accepted	C++	0.015	2014-01-31 14:06:41 */
#include<cstdio>
int main(){
	int n, a, b;
	while (scanf("%d%d%d", &n, &a, &b) == 3){
		int ans = 1;
		int mask = (n - 1) << 1;
		while (true){
			a++, b++;
			a >>= 1, b >>= 1;
			if (a == b)
				break;
			else
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

In an N-rounds tennis tournament a group of 2N players is seeded dening the rst round to be played.
Seeding means that each player is assigned a number between 1 and 2N, and this assignment denes
the round's draw as it establishes the matches that will be played among the players. In particular,
the rst round matches are numbered 1, 2, ..., 2N-1 match k will have player 2*k-1 vs player 2*k, for
1<=k<=2N-1

The winner of a match in the rst round advances to the second round and the loser is eliminated.
Consequently, the second round has exactly half the players of the rst round. Moreover, if the winner
of the rst round match k would be reassigned the number k, then the second round's draw may be
dened exactly as already explained for the rst round. This assignment process could be repeated
over and over again until there is exactly one player remaining, who happens to be the tournament's
champion:

It is clear that the seeding process and the subsequent draws make it possible for any two players
to eventually face each other in some round. For example, for N = 3, players 2 and 5 could play at
round 3 (the nal), and players 5 and 7 could play at round 2 (one of the seminals).
The tennis tournament organization is developing an online portal featuring many services. You
have been hired to implement one of such services: given the seeding numbers of two players (i.e., their
place in the rst round ordering), the service should compute the round number in which these two
players could eventually have a match against other.
Input
The input consists of several test cases, each one dened by a line containing three blank-separated
integers N, i, and j, where N indicates the total number of rounds in the tournament (1  N  20),
and i, j represent two seeding numbers at the rst round (1  i  2
N, 1  j  2
N, i ̸= j).
Output
For each test case, output a line with one integer indicating the round number in which players i and
j may have a match in a tournament with N rounds.
Sample Input
3 2 5
3 5 7
2 1 2
2 2 1
Sample Output
3
2
1
1

*/