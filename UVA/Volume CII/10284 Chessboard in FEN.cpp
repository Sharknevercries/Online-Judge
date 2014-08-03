/* 8859610 10284 Chessboard in FEN Accepted C++ 0.020 2011-05-18 13:19:05 */
#include<stdio.h>
int judge(char table[][8],bool table_judge[][8]){
	int row,cul;
	int temp_row,temp_cul;
	for(row=0;row<8;row++)
		for(cul=0;cul<8;cul++)
			if(table[row][cul]!='-'){
				switch(table[row][cul]){
				case 'p': // 黑卒
					if(row+1<8&&cul-1>=0) table_judge[row+1][cul-1]=true;
					if(row+1<8&&cul+1<8) table_judge[row+1][cul+1]=true;
					break;
				case 'P': // 白卒
					if(row-1>=0&&cul-1>=0) table_judge[row-1][cul-1]=true;
					if(row-1>=0&&cul+1<8) table_judge[row-1][cul+1]=true;
					break;
				case 'N': // 騎士
				case 'n':
					if(row-2>=0&&cul-1>=0) table_judge[row-2][cul-1]=true;
					if(row-2>=0&&cul+1<8) table_judge[row-2][cul+1]=true;
					if(row-1>=0&&cul-2>=0) table_judge[row-1][cul-2]=true;
					if(row-1>=0&&cul+2<8) table_judge[row-1][cul+2]=true;
					if(row+1<8&&cul-2>=0) table_judge[row+1][cul-2]=true;
					if(row+1<8&&cul+2<8) table_judge[row+1][cul+2]=true;
					if(row+2<8&&cul-1>=0) table_judge[row+2][cul-1]=true;
					if(row+2<8&&cul+1<8) table_judge[row+2][cul+1]=true;
					break;				
				case 'b': // 主教
				case 'B':					
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='-';row--,cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='-';row--,cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='-';row++,cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='-';row++,cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					break;
				case 'R': // 城堡
				case 'r':
					temp_row=row,temp_cul=cul;
					for(row-=1;row>=0&&table[row][cul]=='-';row--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='-';row++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='-';cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='-';cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					break;
				case 'Q': // 皇后
				case 'q':					
					temp_row=row,temp_cul=cul;
					for(row-=1,cul-=1;row>=0&&cul>=0&&table[row][cul]=='-';row--,cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row-=1,cul+=1;row>=0&&cul<8&&table[row][cul]=='-';row--,cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul-=1;row<8&&cul>=0&&table[row][cul]=='-';row++,cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1,cul+=1;row<8&&cul<8&&table[row][cul]=='-';row++,cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row-=1;row>=0&&table[row][cul]=='-';row--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(row+=1;row<8&&table[row][cul]=='-';row++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(cul-=1;cul>=0&&table[row][cul]=='-';cul--)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;
					for(cul+=1;cul<8&&table[row][cul]=='-';cul++)
						table_judge[row][cul]=true;
					row=temp_row,cul=temp_cul;					
					break;				
				case 'K': // 國王
				case 'k':
					if(row-1>=0&&cul-1>=0) table_judge[row-1][cul-1]=true;
					if(row-1>=0) table_judge[row-1][cul]=true;
					if(row-1>=0&&cul+1<8) table_judge[row-1][cul+1]=true;
					if(cul-1>=0) table_judge[row][cul-1]=true;					
					if(cul+1<8) table_judge[row][cul+1]=true;
					if(row+1<8&&cul-1>=0) table_judge[row+1][cul-1]=true;
					if(row+1<8) table_judge[row+1][cul]=true;
					if(row+1<8&&cul+1<8) table_judge[row+1][cul+1]=true;
					break;
				}
			}
	int count=0;
	for(row=0;row<8;row++)
		for(cul=0;cul<8;cul++)
			if(table_judge[row][cul]==false)
				count++;
	return count;
}
int main(){
	char str[80];
	while(gets(str)){
		bool table_judge[8][8]={false};
		char table[8][8];
		int row,cul;	
		int i,j;
		for(i=row=cul=0;str[i]!='\0';i++){
			if(str[i]=='/'){	row++;	cul=0; }
			else if(str[i]>='0'&&str[i]<='9')
				for(j=1;j<=str[i]-'0';j++)
					table[row][cul++]='-';
					
			else{				
				table[row][cul]=str[i];
				table_judge[row][cul++]=true;
			}
		}
		printf("%d\n",judge(table,table_judge));
	}
	return 0;
}
/*

In the FEN (Forsyth-Edwards Notation), a chessboard is described as follows: 
•The Board-Content is specified starting with the top row and ending with the bottom row. 
•Character / is used to separate data of adjacent rows. 
•Each row is specified from left to right. 
•White pieces are identified by uppercase piece letters: PNBRQK. 
•Black pieces are identified by lowercase piece letters: pnbrqk. 
•Empty squares are represented by the numbers one through eight. 
•A number used represents the count of contiguous empty squares along a row. 
•Each row's sum of numbers and characters must equal 8.
 
As for example: 

5k1r/2q3p1/p3p2p/1B3p1Q/n4P2/6P1/bbP2N1P/1K1RR3, is the FEN notation description of the following chessboard: 

The chessboard of the beginning of a chess game is described in FEN as: 

rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

Your task is simple: given a chessboard description in a FEN notation you are asked to compute the number of unoccupied squares on the board which are not attacked by any piece.
 
Input

Input is a sequence of lines, each line containing a FEN description of a chessboard. Note that the description does not necessarily give a legal chess position. Input lines do not contain white space.

Output

For each line of input, output one line containing an integer which gives the number of unoccupied squares which are not attacked.

Sample Input

5k1r/2q3p1/p3p2p/1B3p1Q/n4P2/6P1/bbP2N1P/1K1RR3
rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR 

Sample Output

316

--------------------------------------------------------------------------------

(Math Lovers’ Contest, Source: University of Alberta Local Contest)
   
*/