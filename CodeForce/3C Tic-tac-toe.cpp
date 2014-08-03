#include<stdio.h>
#define CROSS_WIN 1
#define NOUGHT_WIN 2
#define ILLEGAL 3
#define ONE 4
#define SEC 5
int line(char board[][3],char c,int value){
	int count=0;
	for(int i=0;i<3;i++)
		if(	board[i][0]=='X'&&board[i][1]=='X'&&board[i][2]=='X' )
			count++;
	for(int i=0;i<3;i++)
		if(	board[0][i]=='X'&&board[1][i]=='X'&&board[2][i]=='X' )
			count++;
	if(	board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X' )
		count++;
	if(	board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X' )
		count++;
	if( count==0 )
		return 0;
	else if( count==0return CROSS_WIN;
}
bool check(char board[][3]){
	int cross,nought;
	cross=nought=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if( board[i][j]=='X' )
				cross++;
			else if( board[i][j]=='0' )
				nought++;
	if( cross-nought<0||cross-nought>1 )
		return ILLEGAL;
	
	
}
int main(){
	char board[3][4];
	while( scanf("%s",board[0])==1 ){
		for(int i=1;i<3;i++)
			scanf("%s",board[i]);
		
		switch( check(board) ){
		case 1:
		case 2:
		case 3:
		}

	}
	return 0;
}