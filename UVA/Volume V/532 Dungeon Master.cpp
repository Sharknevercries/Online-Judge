/* 532 Dungeon Master Accepted C++ 0.016 2011-02-26 13:30:53 */
#include<stdio.h>
struct quene{
	int x;
	int y;
	int z;
	int count;
};
struct quene s[100000];
int front,behind;
bool been[31][31][31];
void initial(){
	for(int i=0;i<31;i++)
		for(int j=0;j<31;j++)
			for(int k=0;k<31;k++)
				been[i][j][k]=false;
	front=behind=-1;
}
void push(int x,int y,int z,int count){
	s[++front].x=x;
	s[front].y=y;
	s[front].z=z;
	s[front].count=count;
}
int BFS(int L,int R,int C,char str[][31][31]){
	int x,y,z;
	int count;
	while(behind<front){
		x=s[++behind].x;
		y=s[behind].y;
		z=s[behind].z;
		count=s[behind].count;
		if(str[z][y][x]=='E')
			return count;
		else{
			if(x+1<C&&str[z][y][x+1]!='#'&&!been[z][y][x+1]){ push(x+1,y,z,count+1); been[z][y][x+1]=true; }
			if(x-1>=0&&str[z][y][x-1]!='#'&&!been[z][y][x-1]){ push(x-1,y,z,count+1); been[z][y][x-1]=true; }
			if(y+1<R&&str[z][y+1][x]!='#'&&!been[z][y+1][x]){ push(x,y+1,z,count+1); been[z][y+1][x]=true; }
			if(y-1>=0&&str[z][y-1][x]!='#'&&!been[z][y-1][x]){ push(x,y-1,z,count+1); been[z][y-1][x]=true; }
			if(z+1<L&&str[z+1][y][x]!='#'&&!been[z+1][y][x]){ push(x,y,z+1,count+1); been[z+1][y][x]=true; }
			if(z-1>=0&&str[z-1][y][x]!='#'&&!been[z-1][y][x]){ push(x,y,z-1,count+1); been[z-1][y][x]=true; }
		}
	}
	return -1; // NOT FOUND
}
int main(){
	int L,R,C;
	char str[31][31][31];
	while(scanf("%d%d%d",&L,&R,&C)==3){
		if(L==0&&R==0&&C==0) break;
		int i,j,k,ptr;
		bool found=false;
		initial();
		for(i=0;i<L;i++)
			for(j=0;j<R;j++){
				scanf("%s",str[i][j]);
				if(!found)
					for(k=0;str[i][j][k]!='\0';k++)
						if(str[i][j][k]=='S'){
							push(k,j,i,0);
							found=true;}
			}
		ptr=BFS(L,R,C,str);
		if(ptr==-1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n",ptr);
	}
	return 0;
}
/*

You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides. 

Is an escape possible? If yes, how long will it take? 

Input Specification  

The input file consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size). 

L is the number of levels making up the dungeon. 

R and C are the number of rows and columns making up the plan of each level. 

Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a `#' and empty cells are represented by a `.'. Your starting position is indicated by `S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C. 

Output Specification  

Each maze generates one line of output. If it is possible to reach the exit, print a line of the form 

Escaped in x minute(s). 

where x is replaced by the shortest time it takes to escape. 

If it is not possible to escape, print the line Trapped! 

Sample Input 

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

Sample Output  

Escaped in 11 minute(s).
Trapped!

*/