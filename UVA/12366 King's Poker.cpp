/* 13066036	12366	King's Poker	Accepted	C++	0.029	2014-02-01 08:07:59 */
#include<cstdio>
#include<algorithm>
using namespace std;
int ans[3];
void print(){
	sort(ans, ans + 3);
	if (ans[0] == 14)
		puts("*");
	else
		printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}
int main(){
	int A, B, C;
	while (scanf("%d%d%d", &A, &B, &C) == 3){
		if (A == 0 && B == 0 && C == 0)
			break;
		if (A != B&&B != C&&A != C)
			ans[0] = 1, ans[1] = 1, ans[2] = 2;
		else if (A == B&&B == C){
			if (A == 13)
				ans[0] = ans[1] = ans[2] = 14;
			else
				ans[0] = A + 1, ans[1] = B + 1, ans[2] = C + 1;
		}
		else{
			int pair, unpair;
			if (A == B)	pair = A, unpair = C;
			if (B == C) pair = B, unpair = A;
			if (A == C)	pair = A, unpair = B;
			unpair++;
			if (unpair == pair)
				unpair++;
			if (unpair > 13)
				pair++, unpair = 1;
			if (pair > 13)
				ans[0] = ans[1] = ans[2] = 1;
			else
				ans[0] = ans[1] = pair, ans[2] = unpair;
		}
		print();
	}
	return 0;
}
/*

King's Poker
Poker is one of the most widely played card games, and King's Poker is one of its variations. The game is played with a normal deck of 52 cards. Each card has one of 4 suits and one of 13 ranks. However, in King's Poker card suits are not relevant, while ranks are Ace (rank 1), 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack (rank 11), Queen (rank 12) and King (rank 13). The name of the game comes from the fact that in King's Poker, the King is the highest ranked card. But this is not the only difference between regular Poker and King's Poker. Players of King's Poker are dealt a hand of just three cards. There are three types of hands:

A set, made of three cards of the same rank.
A pair, which contains two cards of the same rank, with the other card unmatched.
A no-pair, where no two cards have the same rank.
Hands are ranked using the following rules:

Any set defeats any pair and any no-pair.
Any pair defeats any no-pair.
A set formed with higher ranked cards defeats any set formed with lower ranked cards.
If the matched cards of two pairs have different ranks, then the pair with the higher ranked matched cards defeats the pair with the lower ranked matched cards.
If the matched cards of two pairs have the same rank, then the unmatched card of both hands are compared; the pair with the higher ranked unmatched card defeats the pair with the lower ranked unmatched card, unless both unmatched cards have the same rank, in which case there is a tie.
A new software house wants to offer King's Poker games in its on-line playing site, and needs a piece of software that, given a hand of King's Poker, determines the set or pair with the lowest rank that beats the given hand. Can you code it?

Input

Each test case is described using a single line. The line contains three integers A, B, and C representing the ranks of the cards dealt in a hand ( 1$ \le$A, B, C$ \le$13).

The last test case is followed by a line containing three zeros.

Output

For each test case output a single line. If there exists a set or a pair that beats the given hand, write the lowest ranked such a hand. The beating hand must be written by specifying the ranks of their cards, in non-decreasing order. If no set or pair beats the given hand, write the character `*' (asterisk).

Sample Input

1 1 1
1 1 12
1 1 13
1 13 1
10 13 10
1 2 2
13 13 13
13 12 13
12 12 12
3 1 4
1 5 9
0 0 0
Sample Output

2 2 2
1 1 13
1 2 2
1 2 2
1 11 11
2 2 3
*
1 1 1
13 13 13
1 1 2
1 1 2

*/