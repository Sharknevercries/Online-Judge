/* 9250892 572 Oil Deposits Accepted C++ 0.008 2011-09-12 06:33:24 */
#include<stdio.h>
#include<string.h>
char table[100][101];
bool been[100][100];
int n,m;
void DFS(int row,int cul){
	been[row][cul]=true;
	if( row-1>=0 && cul-1>=0 && table[row-1][cul-1]=='@' && !been[row-1][cul-1] )
		DFS(row-1,cul-1);
	if( row-1>=0 && table[row-1][cul]=='@' && !been[row-1][cul] )
		DFS(row-1,cul);
	if( row-1>=0 && cul+1<m && table[row-1][cul+1]=='@' && !been[row-1][cul+1] )
		DFS(row-1,cul+1);
	if( cul-1>=0 && table[row][cul-1]=='@' && !been[row][cul-1] )
		DFS(row,cul-1);
	if( cul+1<m && table[row][cul+1]=='@' && !been[row][cul+1] )
		DFS(row,cul+1);
	if( row+1<n && cul-1>=0 && table[row+1][cul-1]=='@' && !been[row+1][cul-1] )
		DFS(row+1,cul-1);
	if( row+1<n && table[row+1][cul]=='@' && !been[row+1][cul] )
		DFS(row+1,cul);
	if( row+1<n && cul+1<m && table[row+1][cul+1]=='@' && !been[row+1][cul+1] )
		DFS(row+1,cul+1);
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
			break;

		(void)getchar();
		for(int i=0;i<n;i++)
			gets(table[i]);
		memset(been,false,sizeof(been));
		
		int count=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(table[i][j]=='@'&&!been[i][j]){
					count++;
					DFS(i,j);
				}
		printf("%d\n",count);
	}
	return 0;
}
/*

The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil.
 
A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
 
Input

The input file contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise and . Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket.
 
Output  

For each grid, output the number of distinct oil deposits. Two different pockets are part of the same oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.
 
Sample Input 

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

 Sample Output  

0
1
2
2

--------------------------------------------------------------------------------

Miguel A. Revilla 
1998-03-10 

*/