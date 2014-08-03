/* 9060885 11352 Crazy King Accepted C++ 0.016 2011-07-19 09:20:02 */
#include<stdio.h>
#define NOT -1
struct Q{
	int x;
	int y;
	int step;
};
static struct Q quene[50000];
static int head,tail;
void initial(){
	head=tail=0;
}
void push(int x,int y,int step){
	quene[head].step=step;
	quene[head].x=x;
	quene[head].y=y;
	head++;
}
void pop(int *x,int *y,int *step){
	*x=quene[tail].x;
	*y=quene[tail].y;
	*step=quene[tail].step;
	tail++;
}
int BFS(char table[][101],bool unsafe[][100],bool marked[][100],int row,int cul){
	int x,y,step;
	while(head>tail){
		pop(&x,&y,&step);
		if(table[y][x]=='B')
			return step;
		if(x+1<cul&&!marked[y][x+1]&&(!unsafe[y][x+1]||table[y][x+1]=='B')){	push(x+1,y,step+1);	marked[y][x+1]=true;	}
		if(x+1<cul&&y+1<row&&!marked[y+1][x+1]&&(!unsafe[y+1][x+1]||table[y+1][x+1]=='B')){	push(x+1,y+1,step+1);	marked[y+1][x+1]=true;	}
		if(x+1<cul&&y-1>=0&&!marked[y-1][x+1]&&(!unsafe[y-1][x+1]||table[y-1][x+1]=='B')){	push(x+1,y-1,step+1);	marked[y-1][x+1]=true;	}
		if(y+1<row&&!marked[y+1][x]&&(!unsafe[y+1][x]||table[y+1][x]=='B')){	push(x,y+1,step+1);	marked[y+1][x]=true;	}
		if(y-1>=0&&!marked[y-1][x]&&(!unsafe[y-1][x]||table[y-1][x]=='B')){	push(x,y-1,step+1);	marked[y-1][x]=true;		}
		if(x-1>=0&&!marked[y][x-1]&&(!unsafe[y][x-1]||table[y][x-1]=='B')){	push(x-1,y,step+1);	marked[y][x-1]=true;	}
		if(x-1>=0&&y-1>=0&&!marked[y-1][x-1]&&(!unsafe[y-1][x-1]||table[y-1][x-1]=='B')){	push(x-1,y-1,step+1);	marked[y-1][x-1]=true;	}
	    if(x-1>=0&&y+1<row&&!marked[y+1][x-1]&&(!unsafe[y+1][x-1]||table[y+1][x-1]=='B')){	push(x-1,y+1,step+1);	marked[y+1][x-1]=true;	}
	}
	return NOT;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		initial();
		int row,cul;
		char table[100][101];
		bool marked[100][100]={false};
		bool unsafe[100][100]={false};
		scanf("%d%d",&row,&cul);
		(void) getchar();
		for(int j=0;j<row;j++)
			gets(table[j]);
		for(int j=0;j<row;j++)
			for(int k=0;k<cul;k++)
				if(table[j][k]=='Z'){
					unsafe[j][k]=true;
					if(k+2<cul&&j+1<row)	unsafe[j+1][k+2]=true;
					if(k+2<cul&&j-1>=0)		unsafe[j-1][k+2]=true;
					if(k+1<cul&&j+2<row)	unsafe[j+2][k+1]=true;
					if(k+1<cul&&j-2>=0)		unsafe[j-2][k+1]=true;
					if(k-1>=0&&j+2<row)		unsafe[j+2][k-1]=true;
					if(k-1>=0&&j-2>=0)		unsafe[j-2][k-1]=true;
					if(k-2>=0&&j+1<row)		unsafe[j+1][k-2]=true;
					if(k-2>=0&&j-1>=0)		unsafe[j-1][k-2]=true;
				}
				else if(table[j][k]=='A'){
					push(k,j,0);
					marked[j][k]=true;
				}
		int result=BFS(table,unsafe,marked,row,cul);
		if(result>0)
			printf("Minimal possible length of a trip is %d\n",result);
		else
			puts("King Peter, you can't go now!");
	}
	return 0;
}
/*

King Peter lives in kingdom A, and his daughter in kingdom B. King recieved a letter telling that her daughter gave birth to a child. King is incredibly curious to see his grandchild! Unfortunately that`s not gonna be that easy.

Kingdoms A and B are separated by a forest. There are lots of enemies in the forest, and King is not that curious to see them. If they attack king on his way to kingdom B, then he will never ever see his grandchild and daughter again because of lethal consequences.

Security Council of the King disposes information about location of the enemies, which makes the things easier for king. For some unknown reason a forest is M x N chessboard. (M is the number of rows, and N is the number of columns). N, M <= 100 are positive integers.

Enemies of the King can ride horses as showed in the picture. Usually horses ride (or jump) that way in Chess. Unfortunately king can't take an airplane from point A to point B because it is not invented yet. So he moves the same way as chess-king does (refer to picture for details).

King can`t move to a square X, if a horse of the enemy is on that square. While the king is moving horses are not, but if at least one horse can reach square X in one move, then king can't move to that square (except for the case when square X is either kingdom A or B).

You are the chief of Electronic Intelligence dapartment of kingdom A (by the way the computers are already invented). And you`re asked to find the length of the shortest route L from kingdom A to B, as king can`t wait any longer.

INPUT:

The first line of input contains the number of tests T <= 100. The first line of each test contains 2 numbers M and N. Then M lines follow each containing N symbols from the set S = {'.', 'Z', 'A', 'B'}. '.' means that square is not occupied. 'Z' Ä horse occupies that square. 'A' - kingdom A, 'B' - kingdom B. Each test contains exactly one kingdom A and B.

OUTPUT:

Find number L for each test and print line "Minimal possible length of a trip is L" if King can reach kingdom B. Replace "L" with corresponding number. If King can`t safely reach the kingdom B print line "King Peter, you can't go now!".

SAMPLE INPUT:

4
5 5
.Z..B
..Z..
Z...Z
.Z...
A....
3 2
ZB
.Z
AZ
6 5
....B
.....
.....
..Z..
.....
A..Z.
3 3
ZZ.
...
AB.

SAMPLE OUTPUT:

King Peter, you can't go now!
Minimal possible length of a trip is 2
King Peter, you can't go now!
Minimal possible length of a trip is 1

Problem setters: Aleksej Viktorchik, Leonid Shishlo.
Huge Easy Contest #1

*/