/* 10074 Take the Land Accepted C++ 0.024 2011-03-05 11:56:18 */
#include<stdio.h>
#define INT_MAX 2147483647
#define MAX(x,y) ( x>=y?x:y )
#define MIN(x,y) ( x>=y?y:x ) 
void search_width(int width[][100],int map[][100],int x,int y){ // 對於每一個空間可以水平向左伸展之格數(Include itself)
	int i,j;
	for(i=0;i<y;i++)
		for(j=0;j<x;j++)			
			if(map[i][j]==1)
				width[i][j]=0;
			else if(j==0)
				width[i][j]=1;
			else
				width[i][j]=width[i][j-1]+1;
}
int max_area(int width[][100],int x,int y){
	int area;
	int w,h;
	int i,j;
	area=0;	
	for(i=0;i<y;i++) // 頂點 y 座標
		for(j=0;j<x;j++){ // 頂點 x 座標
			w=INT_MAX;
			for(h=0;i-h>=0;h++){ // 對於每一個頂點座標向上延伸形成之矩形作比較
				if(width[i-h][j]==0) break; // 無法形成矩形
				w=MIN(w,width[i-h][j]);
				area=MAX(area,w*(h+1));
			}
		}
	return area;
}
int main(){
	int x,y;
	while(scanf("%d%d",&y,&x)==2){
		if(x==0&&y==0) break;
		int map[100][100];
		int width[100][100]={0};
		int i,j;
		for(i=0;i<y;i++)
			for(j=0;j<x;j++)
				scanf("%d",&map[i][j]);
		search_width(width,map,x,y);
		printf("%d\n",max_area(width,x,y));
	}
	return 0;
}
/*

The poor man went to the King and said, “Lord, I cannot maintain my family. Please give me some wealth so that I can survive with my wife and children.” The King replied, “I shall grant you a piece of land so that you can cultivate and grow food for your family. In the southern part of the Kingdom there is a rectangular forest. Trees have been planted there at regular intervals. Some of the trees have been cut for use. You are allowed to take any rectangular piece of land that does not contain any tree. You need not go to the forest to select the piece of land. I have a map containing 1s at places where there is a tree and 0s at points where the tree has been cut.”

Help the poor man to find out the largest piece of land. Area of the land is measured in units of number of trees that were there. Your program should take a matrix of 1s and 0s as input and output the area of the largest rectangular piece of land that contain no tree. Be careful about the efficiency of your program.

Input

The input file may contain multiple test cases. The first line of each test case contains two integers M and N  (1<=M,N<=100) giving the number of rows and columns in the matrix that follows. Each of the next M lines contains N symbols (either 0 or 1). Two consecutive symbols in a line will be separated by a single space. The input terminates with two zeros for M and N. 

Output

For each test case in the input print a line giving the area (in terms of the number of trees were there) of the largest rectangular piece of land containing no tree. 

Sample Input

6 7
0 1 1 0 1 1 0
0 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 1
1 1 0 0 0 1 0
1 1 0 1 1 0 0
0 0

Sample Output

12

______________________________________________________________________________________
Rezaul Alam Chowdhury 

*/