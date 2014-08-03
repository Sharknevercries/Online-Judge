/* 8873029 10443 Rock Accepted C++ 0.564 2011-05-22 10:18:18 */
#include<stdio.h>
#define WIN 1
#define LOSE 2
#define DRAW 3
int judge(char a,char b){
	switch(a){
	case 'S':
		if(b=='S')	return DRAW;
		if(b=='P')	return WIN;
		if(b=='R')	return LOSE;
	case 'P':
		if(b=='S')	return LOSE;
		if(b=='P')	return DRAW;
		if(b=='R')	return WIN;
	case 'R':
		if(b=='S')	return WIN;
		if(b=='P')	return LOSE;
		if(b=='R')	return DRAW;
	}
}
int main(){
	int i,j,k,d;
	int t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		char table[2][100][101];
		int row,cul,day;
		scanf("%d%d%d",&row,&cul,&day);
		(void) getchar();
		for(j=0;j<row;j++){
			gets(table[0][j]);
			table[0][j][cul]=table[1][j][cul]='\0';
		}		
		for(d=1;d<=day;d++)
			for(j=0;j<row;j++)
				for(k=0;k<cul;k++){
					int p;
					if(k-1>=0)
						if(p=judge(table[(d-1)%2][j][k],table[(d-1)%2][j][k-1])==LOSE){
							table[d%2][j][k]=table[(d-1)%2][j][k-1];
							continue;
						}
					if(k+1<cul)
						if(p=judge(table[(d-1)%2][j][k],table[(d-1)%2][j][k+1])==LOSE){
							table[d%2][j][k]=table[(d-1)%2][j][k+1];
							continue;
						}
					if(j-1>=0)
						if(p=judge(table[(d-1)%2][j][k],table[(d-1)%2][j-1][k])==LOSE){
							table[d%2][j][k]=table[(d-1)%2][j-1][k];
							continue;
						}
					if(j+1<row)
						if(p=judge(table[(d-1)%2][j][k],table[(d-1)%2][j+1][k])==LOSE){
							table[d%2][j][k]=table[(d-1)%2][j+1][k];
							continue;
						}
					table[d%2][j][k]=table[(d-1)%2][j][k];
				}
		
		for(j=0;j<row;j++)
			printf("%s\n",table[day%2][j]);
		if(t!=i)
			putchar('\n');
	}
	return 0;
}
/*

 Bart's sister Lisa has created a new civilization on a two-dimensional grid. At the outset each grid location may be occupied by one of three life forms: Rocks, Scissors, or Papers. Each day, differing life forms occupying horizontally or vertically adjacent grid locations wage war. In each war, Rocks always defeat Scissors, Scissors always defeat Papers, and Papers always defeat Rocks. At the end of the day, the victor expands its territory to include the loser's grid position. The loser vacates the position.
 Your job is to determine the territory occupied by each life form after n days. The first line of input contains t, the number of test cases. Each test case begins with three integers not greater than 100: r and c, the number of rows and columns in the grid, and n. The grid is represented by the r lines that follow, each with c characters. Each character in the grid is R, S, or P, indicating that it is occupied by Rocks, Scissors, or Papers respectively.
 
For each test case, print the grid as it appears at the end of the nth day. Leave an empty line between the output for successive test cases.
 
Sample Input

2
3 3 1
RRR
RSR
RRR
3 4 2
RSPR
SPRS
PRSP
 
Output for Sample Input

RRR
RRR
RRR

RRRS
RRSP
RSPR

*/