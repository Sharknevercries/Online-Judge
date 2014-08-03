/* 10667 Largest Block Accepted C++ 0.016 2011-03-05 13:14:42 */
#include<stdio.h>
#define INT_MAX 2147483647
#define MAX(x,y) (x>=y?x:y)
#define MIN(x,y) (x>=y?y:x)
void search_width(int width[][100],int map[][100],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(map[i][j]==1)
				width[i][j]=0;
			else if(j==0)
				width[i][j]=1;
			else
				width[i][j]=width[i][j-1]+1;
}
int max_area(int width[][100],int n){
	int i,j;
	int area;
	int h,w;
	area=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			w=INT_MAX;
			for(h=0;i-h>=0;h++){
				if(width[i-h][j]==0) break;
				w=MIN(w,width[i-h][j]);
				area=MAX(area,w*(h+1));
			}
		}
	return area;
}
int main(){
	int t;
	while(scanf("%d",&t)==1)
		while(t--){
			int width[100][100];
			int map[100][100]={0};
			int n,s;
			int i,r1,c1,r2,c2;
			scanf("%d",&n);
			scanf("%d",&s);
			for(i=1;i<=s;i++){
				scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
				for(int j=r1-1;j<=r2-1;j++)
					for(int k=c1-1;k<=c2-1;k++)
						map[j][k]=1;}
			search_width(width,map,n);
			printf("%d\n",max_area(width,n));
		}
	return 0;
}
/*

The Problem

Consider a n x n chessboard. The term block(r1,c1,r2,c2) denotes the rectangular subset of squares defined by the intersection of rows {r1,r1+1,...,r2} and columns {c1,c1+1,...,c2}.

There are several occupied blocks on the board. We are interested in the largest block (in the sense of maximum area) that can be placed in the free space remaining in the board.

For example, in a chessboard of size 10, if block(2,2,5,3), block(8,3,9,7), and block(3,6,3,8) represent occupied space, then the largest block that can be placed in free space has area 28. This can be visually checked in the following figure:

We are interested only in the area of the largest free block, and not in its particular location. Therefore, each instance of the problem has a unique solution.

The Input

The program first reads the number p of instances of the problem. Each instance is described by the size s of the board, the number b of blocks of occupied space, and the vertices r1,c1,r2,c2, of each block:

p number of problem instances in the file 
s (board size) instance #1 
b (number of blocks) 
r1 c1 r2 c2 (first block) 
r1 c1 r2 c2 (second block) 
... ... 
r1 c1 r2 c2 (n-th block) 
s (board size) instance #2 
b (number of blocks) 
r1 c1 r2 c2 (first block) 
r1 c1 r2 c2 (second block) 
... ... 
r1 c1 r2 c2 (n-th block) 
... ... instance #p 

Assumptions:

1 <= s <= 100 
0 <= b <= 100 
1 <= r1 <= r2 <=s 
1 <= c1 <= c2 <=s 
Occupied blocks may overlap. 

The Output

For each test case the output consists of a integer indicating the area of the largest block that can be located in the available free squares.

Sample 

3
10
3
2 2 5 3
8 3 9 7
3 6 3 8
20
1
1 1 1 1
10
2
5 1 5 10
1 5 10 5

Sample Output

28
380

*/