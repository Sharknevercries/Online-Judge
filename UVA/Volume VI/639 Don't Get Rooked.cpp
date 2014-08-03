/* 9030944 639 Don't Get Rooked	Accepted C++ 0.120 2011-07-09 05:41:31 */
#include<stdio.h>
#define CASTLE '#'
#define MAX 5
void rejudge(char table[][MAX],bool taken[][MAX],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			taken[i][j]=false;
	for(int row=0;row<n;row++)
		for(int cul=0;cul<n;cul++)
			if(table[row][cul]==CASTLE){
				taken[row][cul]=true;
				for(i=row+1,j=cul;i<n;i++)
					if(table[i][j]=='X')
						break;
					else
						taken[i][j]=true;
				for(i=row-1,j=cul;i>=0;i--)
					if(table[i][j]=='X')
						break;
					else
						taken[i][j]=true;
				for(i=row,j=cul+1;j<n;j++)
					if(table[i][j]=='X')
						break;
					else
						taken[i][j]=true;
				for(i=row,j=cul-1;j>=0;j--)
					if(table[i][j]=='X')
						break;
					else
						taken[i][j]=true;
			}
			else if(table[row][cul]=='X')
				taken[row][cul]=true;
}
void DFS(char table[][MAX],bool taken[][MAX],int n,int *max,int count){	
	int row,cul;		
	for(row=0;row<n;row++)
		for(cul=0;cul<n;cul++)
			if(!taken[row][cul]){				
				count++;
				if(*max<count)
					*max=count;
				table[row][cul]=CASTLE;
				rejudge(table,taken,n);
				DFS(table,taken,n,max,count);
				table[row][cul]='.';
				rejudge(table,taken,n);
				count--;
			}
}
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		(void) getchar();
		char table[MAX][MAX];
		bool taken[MAX][MAX]={false};
		int row,cul,max;
		for(row=0;row<n;row++)
			gets(table[row]);
		for(row=0;row<n;row++)
			for(cul=0;cul<n;cul++)
				if(table[row][cul]=='X')
					taken[row][cul]=true;
		max=0;
		DFS(table,taken,n,&max,0);
		printf("%d\n",max);
	}
	return 0;
}
/*

In chess, the rook is a piece that can move any number of squares vertically or horizontally. In this problem we will consider small chess boards (at most 44) that can also contain walls through which rooks cannot move. The goal is to place as many rooks on a board as possible so that no two can capture each other. A configuration of rooks is legal provided that no two rooks are on the same horizontal row or vertical column unless there is at least one wall separating them.

The following image shows five pictures of the same board. The first picture is the empty board, the second and third pictures show legal configurations, and the fourth and fifth pictures show illegal configurations. For this board, the maximum number of rooks in a legal configuration is 5; the second picture shows one way to do it, but there are several other ways.


Your task is to write a program that, given a description of a board, calculates the maximum number of rooks that can be placed on the board in a legal configuration.

Input 

The input file contains one or more board descriptions, followed by a line containing the number 0 that signals the end of the file. Each board description begins with a line containing a positive integer n that is the size of the board; n will be at most 4. The next n lines each describe one row of the board, with a `.' indicating an open space and an uppercase `X' indicating a wall. There are no spaces in the input file.

Output 

For each test case, output one line containing the maximum number of rooks that can be placed on the board in a legal configuration.

Sample Input 

4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0

Sample Output 

5
1
5
2
4

Miguel A. Revilla 
2000-01-17

*/