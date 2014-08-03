/* 5419476	 Dec 13, 2013 1:22:56 PM	Shark	 38B - Chess	 GNU C++	Accepted	30 ms	0 KB */
#include<cstdio>
void change(int &x, int &y, char S[]){
	x = S[0] - 'a' + 1;
	y = S[1] - '0';
}
void place_knight(int x, int y, bool B[][9]){
	B[y][x] = true;
	if (x - 2 >= 1 && y - 1 >= 1)	B[y - 1][x - 2] = true;
	if (x - 2 >= 1 && y + 1 <= 8)	B[y + 1][x - 2] = true;
	if (x - 1 >= 1 && y - 2 >= 1)	B[y - 2][x - 1] = true;
	if (x - 1 >= 1 && y + 2 <= 8)	B[y + 2][x - 1] = true;
	if (x + 1 <= 8 && y - 2 >= 1)	B[y - 2][x + 1] = true;
	if (x + 1 <= 8 && y + 2 <= 8)	B[y + 2][x + 1] = true;
	if (x + 2 <= 8 && y - 1 >= 1)	B[y - 1][x + 2] = true;
	if (x + 2 <= 8 && y + 1 <= 8)	B[y + 1][x + 2] = true;
}
void place_rook(int x, int y, bool B[][9]){
	for (int i = 1; i <= 8; i++)
		B[i][x] = B[y][i] = true;
}
int main(){
	char A[3], B[3];
	while (scanf("%s%s", A, B) == 2){
		int x1, x2, y1, y2;
		bool board[9][9] = { false };
		int ans = 0;
		change(x1, y1, A);
		change(x2, y2, B);
		place_rook(x1, y1, board);
		place_knight(x1, y1, board);
		place_knight(x2, y2, board);
		for (int i = 1; i <= 8; i++){
			for (int j = 1; j <= 8; j++){
				if (!board[i][j])
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. Chess
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Two chess pieces, a rook and a knight, stand on a standard chessboard 8 × 8 in size. The positions in which they are situated are known. It is guaranteed that none of them beats the other one.

Your task is to find the number of ways to place another knight on the board so that none of the three pieces on the board beat another one. A new piece can only be placed on an empty square.

Input
The first input line contains the description of the rook's position on the board. This description is a line which is 2 in length. Its first symbol is a lower-case Latin letter from a to h, and its second symbol is a number from 1 to 8. The second line contains the description of the knight's position in a similar way. It is guaranteed that their positions do not coincide.

Output
Print a single number which is the required number of ways.

Sample test(s)
input
a1
b2
output
44
input
a8
d4
output
38

*/