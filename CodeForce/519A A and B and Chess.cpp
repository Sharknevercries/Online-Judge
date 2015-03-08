/* 10064446	2015-02-28 16:05:34	Shark	519A - A and B and Chess	GNU C++	Accepted	30 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
char board[50][50];
int white, black;
int convert(char c){
	if (c == 'Q' || c == 'q')
		return 9;
	if (c == 'R' || c == 'r')
		return 5;
	if (c == 'B' || c == 'b')
		return 3;
	if (c == 'N' || c == 'n')
		return 3;
	if (c == 'P' || c == 'p')
		return 1;
	return 0;
}
int main(){
	white = black = 0;
	for (int i = 0; i < 8; i++)
		scanf("%s", board + i);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] != '.')
				if (board[i][j] >= 'A' && board[i][j] <= 'Z')
					white += convert(board[i][j]);
				else
					black += convert(board[i][j]);
	if (white > black)
		puts("White");
	else if (white == black)
		puts("Draw");
	else
		puts("Black");
	return 0;
}
/*

A. A and B and Chess
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A and B are preparing themselves for programming contests.

To train their logical thinking and solve problems better, A and B decided to play chess. During the game A wondered whose position is now stronger.

For each chess piece we know its weight:

the queen's weight is 9,
the rook's weight is 5,
the bishop's weight is 3,
the knight's weight is 3,
the pawn's weight is 1,
the king's weight isn't considered in evaluating position.
The player's weight equals to the sum of weights of all his pieces on the board.

As A doesn't like counting, he asked you to help him determine which player has the larger position weight.

Input
The input contains eight lines, eight characters each ¡X the board's description.

The white pieces on the board are marked with uppercase letters, the black pieces are marked with lowercase letters.

The white pieces are denoted as follows: the queen is represented is 'Q', the rook ¡X as 'R', the bishop ¡X as'B', the knight ¡X as 'N', the pawn ¡X as 'P', the king ¡X as 'K'.

The black pieces are denoted as 'q', 'r', 'b', 'n', 'p', 'k', respectively.

An empty square of the board is marked as '.' (a dot).

It is not guaranteed that the given chess position can be achieved in a real game. Specifically, there can be an arbitrary (possibly zero) number pieces of each type, the king may be under attack and so on.

Output
Print "White" (without quotes) if the weight of the position of the white pieces is more than the weight of the position of the black pieces, print "Black" if the weight of the black pieces is more than the weight of the white pieces and print "Draw" if the weights of the white and black pieces are equal.

Sample test(s)
input
...QK...
........
........
........
........
........
........
...rk...
output
White
input
rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR
output
Draw
input
rppppppr
...k....
........
........
........
........
K...Q...
........
output
Black
Note
In the first test sample the weight of the position of the white pieces equals to 9, the weight of the position of the black pieces equals 5.

In the second test sample the weights of the positions of the black and the white pieces are equal to 39.

In the third test sample the weight of the position of the white pieces equals to 9, the weight of the position of the black pieces equals to 16.

*/