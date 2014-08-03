/* 10502 Counting Rectangles Accepted C++ 0.016 2011-03-05 12:49:57 */
#include<stdio.h>
#define INT_MAX 2147483647;
#define MIN(x,y) ( x>=y?y:x )
void search_width(int width[][150],char map[][150],int x,int y){ // 對於每一個點所能向左延伸之長度(Include itself)
	int i,j;
	for(i=0;i<y;i++)
		for(j=0;j<x;j++)
			if(map[i][j]=='0')
				width[i][j]=0;
			else if(j==0)
				width[i][j]=1;
			else
				width[i][j]=width[i][j-1]+1;
}
void count_rec(int width[][150],int x,int y,int *count){
	int i,j,k;
	int w;
	*count=0;
	for(i=0;i<y;i++) // 頂點 y 座標
		for(j=0;j<x;j++){ // 頂點 x 座標
			w=INT_MAX;
			for(k=0;i-k>=0;k++){ // 對於每一個頂點向上延伸所能畫出之矩形
				if(width[i-k][j]==0) break;
				w=MIN(w,width[i-k][j]);
				*count+=w;
			}
		}
}
int main(){
	int x,y;
	while(scanf("%d%d",&y,&x)==2){
		int width[150][150]={0};
		char map[150][150];
		int i,j;
		int count;
		(void) getchar();
		for(i=0;i<y;i++){
			for(j=0;j<x;j++)
				scanf("%c",&map[i][j]);
			(void) getchar();}
		search_width(width,map,x,y);
		count_rec(width,x,y,&count);
		printf("%d\n",count);
	}
	return 0;
}
/*

In some tests there appears the problem of finding the number of rectangles (or circles, or triangles, ...) of different sizes in a figure. We consider the problem of counting rectangles (including squares) in a rectangular board. 

Given a rectangular board with n rows and m columns, with valid possitions marked with 1 and non valid possitions marked with 0,  we want to count the number of rectangles (including squares) in the board formed by squares marked with 1.

The Input

The input will consist of a series of problems, with each problem in a serie of lines. In the first and second lines the rows (n) and columns (m) of the board are indicated, in the next n lines the board in represented, with a row of the board in each line, and m 0 or 1 (without spaces) in each line. When the input of a problem finishes the next problem begins in the next line. The input finishes when 0 appears as the dimension of the board. Both dimensions of the board are less than or equal to 100. 

The Output

The solution of each problem appears in a line, without separation between lines. For example, in the board 

11
01

the rectangles are: 

1-
--  

-1
--  

-- 
-1 

11
-- 

-1 
-1 

Sample Input

2 
2 
11
01 
4 
3 
110
101
111
011  
0

Sample Output

5 
22 
 
*/