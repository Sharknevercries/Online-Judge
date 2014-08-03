/* 926 Walking Around Wisely Accepted C++ 0.012 2011-03-03 14:20:29 */
#include<stdio.h>
int main(){
	int t;
	while(scanf("%d",&t)==1)
		while(t--){
			unsigned long long way[31][31]={0}; // 請使用 64-int 整數
			bool block_row[31][31]={false};
			bool block_cul[31][31]={false};
			int n,e;
			int x_start,y_start,x_end,y_end;
			int i,j;
			scanf("%d",&n);
			scanf("%d%d%d%d",&x_start,&y_start,&x_end,&y_end);
			scanf("%d",&e);
			for(i=1;i<=e;i++){
				int temp_x,temp_y;
				char temp_c;
				scanf("%d%d %c",&temp_x,&temp_y,&temp_c);
				if(temp_c=='S')
					block_cul[temp_x][temp_y-1]=true;
				if(temp_c=='N')					
					block_cul[temp_x][temp_y]=true;
				if(temp_c=='W')
					block_row[temp_x-1][temp_y]=true;
				if(temp_c=='E')
					block_row[temp_x][temp_y]=true;}
			/* DP */
			way[x_start][y_start]=1;
			for(i=x_start;i<=x_end;i++)
				for(j=y_start;j<=y_end;j++){
					if(!block_row[i-1][j])
						way[i][j]+=way[i-1][j];
					if(!block_cul[i][j-1])
						way[i][j]+=way[i][j-1];
				}
			/* Dp */
			printf("%llu\n",way[x_end][y_end]);
		}
	return 0;
}
/*

 Imagine you are in a well planned city in which a very large area has all streets or avenues set nicely in a perpendicular way resembling a grid. For a real example consider Downtown Manhattan in New York. Obviously, there may be cases in which a street or avenue is suddenly discontinued. For you, streets or avenues are the same and to simplify we call them roads. You can always walk in any direction along a road (either North/South or East/West). 

We have a small challenge for you. As illustrated in the figure, we want you to determine in how many ways can you go from a start position A to an end position B. By position we mean a crossing between two roads. There is a small catch, you are not allowed to travel South or West. 

Problem

Given a grid of NxN roads, a starting position A=(Ax,Ay) and a ending position B=(Bx,By), your task is to count in how many ways can you go from A to B without ever travelling South or West. You can assume that there will always be at least one valid path between the start and the end positions. 

Input

The first line of input contains C (0 < C < 1000), the number of test cases that follows. 

Each test case starts with a line containing the number N (1 < N <= 30) of vertical and horizontal roads, followed by two lines containing the start position and the end position. Each position is defined by two integer coordinates separated by a single space. 

The next line contains the number of places, W (limited by the size of the grid), where the roads are discontinued. The following W lines, describe such places. Each place is defined by two integer coordinates Px and Py (road numbers between 1 and N) followed by a symbol D (D in {N,E,S,W}) indicating that there are men working in the direction D with respect to junction (Px,Py). The three values that characterize a place are separated by a single space. 

Output

For each input case your program must output a line indicating the number of ways you can go from the start to the end point, given that you are not allowed to travel South or West. 

The first test case illustrates the figure.

Sample Input

2
3
1 1
3 3
2
2 3 S
2 2 W
3
1 1
3 3
0

Sample Output

3
6

--------------------------------------------------------------------------------

MIUP�2004: Fourth Portuguese National Programming Contest 

--------------------------------------------------------------------------------
Problem setter: Fernando Silva 

*/