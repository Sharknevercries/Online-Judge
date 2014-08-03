/* 8859894 10196 Check The Check Accepted C++ 0.024 2011-05-18 14:15:19 */
#include<stdio.h>
#define WHITE_UNDER_ATTACKED 0
#define BLACK_UNDER_ATTACKED 1 
#define NOTHING 2
int table_judge(char table[][8]){
	int row,cul;
	int temp_row,temp_cul;
	for(row=0;row<8;row++)
		for(cul=0;cul<8;cul++)
			if(table[row][cul]!='.'){
				switch(table[row][cul]){
				case 'p': // 黑卒
					if(row+1<8&&cul-1>=0&&table[row+1][cul-1]=='K') return WHITE_UNDER_ATTACKED;
					if(row+1<8&&cul+1<8&&table[row+1][cul+1]=='K') return WHITE_UNDER_ATTACKED;
					break;
				case 'P': // 白卒
					if(row-1>=0&&cul-1>=0&&table[row-1][cul-1]=='k') return BLACK_UNDER_ATTACKED;
					if(row-1>=0&&cul+1<8&&table[row-1][cul+1]=='k') return BLACK_UNDER_ATTACKED;
					break;				
				case 'n': // 黑騎士
					if(row-2>=0&&cul-1>=0&&table[row-2][cul-1]=='K') return WHITE_UNDER_ATTACKED;
					if(row-2>=0&&cul+1<8&&table[row-2][cul+1]=='K') return WHITE_UNDER_ATTACKED;
					if(row-1>=0&&cul-2>=0&&table[row-1][cul-2]=='K') return WHITE_UNDER_ATTACKED;
					if(row-1>=0&&cul+2<8&&table[row-1][cul+2]=='K') return WHITE_UNDER_ATTACKED;
					if(row+1<8&&cul-2>=0&&table[row+1][cul-2]=='K') return WHITE_UNDER_ATTACKED;
					if(row+1<8&&cul+2<8&&table[row+1][cul+2]=='K') return WHITE_UNDER_ATTACKED;
					if(row+2<8&&cul-1>=0&&table[row+2][cul-1]=='K') return WHITE_UNDER_ATTACKED;
					if(row+2<8&&cul+1<8&&table[row+2][cul+1]=='K') return WHITE_UNDER_ATTACKED;
					break;				
				case 'N': // 白騎士
					if(row-2>=0&&cul-1>=0&&table[row-2][cul-1]=='k') return BLACK_UNDER_ATTACKED;
					if(row-2>=0&&cul+1<8&&table[row-2][cul+1]=='k') return BLACK_UNDER_ATTACKED;
					if(row-1>=0&&cul-2>=0&&table[row-1][cul-2]=='k') return BLACK_UNDER_ATTACKED;
					if(row-1>=0&&cul+2<8&&table[row-1][cul+2]=='k') return BLACK_UNDER_ATTACKED;
					if(row+1<8&&cul-2>=0&&table[row+1][cul-2]=='k') return BLACK_UNDER_ATTACKED;
					if(row+1<8&&cul+2<8&&table[row+1][cul+2]=='k') return BLACK_UNDER_ATTACKED;
					if(row+2<8&&cul-1>=0&&table[row+2][cul-1]=='k') return BLACK_UNDER_ATTACKED;
					if(row+2<8&&cul+1<8&&table[row+2][cul+1]=='k') return BLACK_UNDER_ATTACKED;
					break;
				case 'b': // 黑主教
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='.';row--,cul--);
					if(row>=0&&cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='.';row--,cul++);
					if(row>=0&&cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='.';row++,cul--);
					if(row<8&&cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='.';row++,cul++);
					if(row<8&&cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					break;
				case 'B': // 白主教		
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='.';row--,cul--);
					if(row>=0&&cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='.';row--,cul++);
					if(row>=0&&cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='.';row++,cul--);
					if(row<8&&cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='.';row++,cul++);
					if(row<8&&cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					break;				
				case 'r': // 黑城堡
					temp_row=row,temp_cul=cul;
					for(row-=1;row>=0&&table[row][cul]=='.';row--);
					if(row>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='.';row++);
					if(row<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='.';cul--);
					if(cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='.';cul++);
					if(cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					break;
				case 'R': // 白城堡
					temp_row=row,temp_cul=cul;
					for(row-=1;row>=0&&table[row][cul]=='.';row--);
					if(row>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='.';row++);
					if(row<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='.';cul--);
					if(cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='.';cul++);
					if(cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					break;
				case 'q': // 黑皇后
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='.';row--,cul--);
					if(row>=0&&cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='.';row--,cul++);
					if(row>=0&&cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='.';row++,cul--);
					if(row<8&&cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='.';row++,cul++);
					if(row<8&&cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1;row>=0&&table[row][cul]=='.';row--);
					if(row>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='.';row++);
					if(row<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='.';cul--);
					if(cul>=0&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='.';cul++);
					if(cul<8&&table[row][cul]=='K') return WHITE_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;					
					break;		
				case 'Q': // 白皇后									
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='.';row--,cul--);
					if(row>=0&&cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='.';row--,cul++);
					if(row>=0&&cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='.';row++,cul--);
					if(row<8&&cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='.';row++,cul++);
					if(row<8&&cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row-=1;row>=0&&table[row][cul]=='.';row--);
					if(row>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='.';row++);
					if(row<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='.';cul--);
					if(cul>=0&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='.';cul++);
					if(cul<8&&table[row][cul]=='k') return BLACK_UNDER_ATTACKED;
					row=temp_row,cul=temp_cul;					
					break;			
				
				}
			}	
	return NOTHING;
}
int main(){
	int count=1;
	char table[8][8];
	while(scanf("%s",table[0])==1){
		bool END=true;
		int row,cul,judge;
		for(row=1;row<8;row++)
			scanf("%s",table[row]);
		for(row=0;row<8;row++)
			for(cul=0;cul<8;cul++)
				if(table[row][cul]!='.')
					END=false;
		if(END)
			break;
		else{
			judge=table_judge(table);
			if(judge==BLACK_UNDER_ATTACKED)
				printf("Game #%d: black king is in check.\n",count++);
			else if(judge==WHITE_UNDER_ATTACKED)
				printf("Game #%d: white king is in check.\n",count++);
			else
				printf("Game #%d: no king is in check.\n",count++);
		}
	}
	return 0;
}
/*

The Problem
 
Your task is to write a program that reads a chess board configuration and answers if there's a king under attack (i.e. "in check"). A king is in check if it's in a square which is attacked by an oponnet's piece (i.e. it's in square which can be taken by an oponnet's piece in his next move).
 
White pieces will be represented by uppercase letters whereas black pieces will be represented by lowercase letters. White side will always be on the bottom of the board and black side will always be on the top of the board.
 
For those unfamiliar with chess, here are the movements of each piece: 

Pawn (p or P): can only move straight ahead, one square at a time. But it takes pieces diagonally (and that's what concerns to you in this problem).
 Knight (n or N): have a special movement and it's the only piece that can jump over other pieces. The knight movement can be viewed as an "L". See the example bellow.
 Bishop (b or B): can move any number of squares diagonally (forward or backward).
 Rook (r or R): can move any number of squares vertically or horizontally (forward or backward).
 Queen (q or Q): can move any number of squares in any direction (diagonally, horizontally or vertically, forward or backward).
 King (k or K): can move one square at a time, in any direction (diagonally, horizontally or vertically, forward or backward).
 
Movements examples ('*' indicates where the piece can take another pieces): 

Pawn
........
........
........
........
...p....
..*.*...
........
........
 
Rook
...*....
...*....
...*....
...*....
***r****
...*....
...*....
...*....
 
Bishop
.......*
*.....*.
.*...*..
..*.*...
...b....
..*.*...
.*...*..
*.....*.
 
Queen
...*...*
*..*..*.
.*.*.*..
..***...
***q****
..***...
.*.*.*..
*..*..*.
 
King
........
........
........
..***...
..*k*...
..***...
........
........
 
Knight
........
........
..*.*...
.*...*..
...n....
.*...*..
..*.*...
........

Remember that the knight is the only piece that can jumper over other pieces. The pawn movement will depend on its side. If it's a black pawn, it can only move one square diagonally down the board. If it's a white pawn, it can only move one square diagonally up the board. The example above is a black pawn as it's a lowercase p (we say "move" meaning the squares where the pawn can move to when it takes another piece).
 
 The Input
 
There will be an arbitrary number of board configurations on the input. Each board will consist of 8 lines of 8 characters each. A '.' character will represent an empty square. Upper and lower case letters (as defined above) will represent the pieces. There will be no invalid characters (i.e. pieces) and there won't be a configuration where both kings are in check. You must read until you find an empty board (i.e. a board that is formed only of '.' characters) which should not be processed. There will be an empty line between each pair of board configurations. In all boards (except the last one which is empty) will appear both the white king and the black king (one, and only one of each).
 
The Output
 
For each board configuration read you must output one of the following answers: 

Game #d: white king is in check.
Game #d: black king is in check.
Game #d: no king is in check.
 
Where d stands for the game number (starting from 1). 

Sample Input

..k.....
ppp.pppp
........
.R...B..
........
........
PPPPPPPP
K.......

rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR

rnbqk.nr
ppp..ppp
....p...
...p....
.bPP....
.....N..
PP..PPPP
RNBQKB.R

........
........
........
........
........
........
........
........

 Sample Output 

Game #1: black king is in check.
Game #2: no king is in check.
Game #3: white king is in check.

--------------------------------------------------------------------------------
 © 2001 Universidade do Brasil (UFRJ). Internal Contest 2001. 

 */