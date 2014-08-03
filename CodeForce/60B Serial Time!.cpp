/* 4941054	 Oct 31, 2013 10:19:12 AM	Shark	 60B - Serial Time!	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
char F[10][10][11];
bool V[10][10][11];
int k,n,m,x,y;
int ans;
void DFS(int f,int x,int y){
	ans++;
	V[f][x][y]=true;
	if( f-1>=0&&F[f-1][x][y]=='.'&&!V[f-1][x][y] )
		DFS(f-1,x,y);
	if( f+1<k&&F[f+1][x][y]=='.'&&!V[f+1][x][y] )
		DFS(f+1,x,y);
	if( x-1>=0&&F[f][x-1][y]=='.'&&!V[f][x-1][y] )
		DFS(f,x-1,y);
	if( x+1<n&&F[f][x+1][y]=='.'&&!V[f][x+1][y] )
		DFS(f,x+1,y);
	if( y-1>=0&&F[f][x][y-1]=='.'&&!V[f][x][y-1] )
		DFS(f,x,y-1);
	if( y+1<m&&F[f][x][y+1]=='.'&&!V[f][x][y+1] )
		DFS(f,x,y+1);
}
int main(){
	while( scanf("%d%d%d",&k,&n,&m)==3 ){
		for(int i=0;i<k;i++)
			for(int j=0;j<n;j++)
				scanf("%s",F[i][j]);
		scanf("%d%d",&x,&y);
		memset(V,false,sizeof(V));
		ans=0;
		if( F[0][x-1][y-1]=='.' )
			DFS(0,x-1,y-1);
		printf("%d\n",ans);
	}
	return 0;
}
/*

B. Serial Time!
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Cereal Guy's friend Serial Guy likes to watch soap operas. An episode is about to start, and he hasn't washed his plate yet. But he decided to at least put in under the tap to be filled with water. The plate can be represented by a parallelepiped k × n × m, that is, it has k layers (the first layer is the upper one), each of which is a rectangle n × m with empty squares ('.') and obstacles ('#'). The water can only be present in the empty squares. The tap is positioned above the square (x, y) of the first layer, it is guaranteed that this square is empty. Every minute a cubical unit of water falls into the plate. Find out in how many minutes the Serial Guy should unglue himself from the soap opera and turn the water off for it not to overfill the plate. That is, you should find the moment of time when the plate is absolutely full and is going to be overfilled in the next moment.

Note: the water fills all the area within reach (see sample 4). Water flows in each of the 6 directions, through faces of 1 × 1 × 1 cubes.

Input
The first line contains three numbers k, n, m (1 ≤ k, n, m ≤ 10) which are the sizes of the plate. Then follow k rectangles consisting of n lines each containing m characters '.' or '#', which represents the "layers" of the plate in the order from the top to the bottom. The rectangles are separated by empty lines (see the samples). The last line contains x and y (1 ≤ x ≤ n, 1 ≤ y ≤ m) which are the tap's coordinates. x is the number of the line and y is the number of the column. Lines of each layer are numbered from left to right by the integers from 1 to n, columns of each layer are numbered from top to bottom by the integers from 1 to m.

Output
The answer should contain a single number, showing in how many minutes the plate will be filled.

Sample test(s)
input
1 1 1

.

1 1
output
1
input
2 1 1

.

#

1 1
output
1
input
2 2 2

.#
##

..
..

1 1
output
5
input
3 2 2

#.
##

#.
.#

..
..

1 2
output
7
input
3 3 3

.#.
###
##.

.##
###
##.

...
...
...

1 1
output
13

*/