/* 8876918 10500 Robot maps Accepted C++ 0.008 2011-05-23 12:41:25 */
#include<stdio.h>
void judge(char input[][10],char result[][10],int x,int y,int row,int cul){
	if(x-1>=0)
		if(input[y][x-1]=='0')
			result[y][x-1]='0';
		else
			result[y][x-1]='X';
	if(y-1>=0)
		if(input[y-1][x]=='0')
			result[y-1][x]='0';
		else
			result[y-1][x]='X';
	if(x+1<cul)
		if(input[y][x+1]=='0')
			result[y][x+1]='0';
		else
			result[y][x+1]='X';
	if(y+1<row)
		if(input[y+1][x]=='0')
			result[y+1][x]='0';
		else
			result[y+1][x]='X';	
}
int main(){
	int row,cul;
	while(scanf("%d%d",&row,&cul)==2){
		if(row==0&&cul==0) break;
		char input[10][10];
		char result[10][10];
		bool been[10][10]={false};
		int x,y,cost,pre_x,pre_y;
		int i,j;
		scanf("%d%d",&y,&x);
		x--,y--;
		pre_x=pre_y=-1;
		(void) getchar();
		for(i=0;i<row;i++)
			for(j=0;j<cul;j++){
				scanf("%c ",&input[i][j]);
				result[i][j]='?';
			}
		result[y][x]='0';
		been[y][x]=true;
		cost=0;
		while(true){
			judge(input,result,x,y,row,cul);
			if(y-1>=0&&input[y-1][x]=='0'&&!been[y-1][x]){
				been[y-1][x]=true;			
				y--,cost++;
			}				
			else if(x+1<cul&&input[y][x+1]=='0'&&!been[y][x+1]){
				been[y][x+1]=true;
				x++,cost++;
			}
			else if(y+1<row&&input[y+1][x]=='0'&&!been[y+1][x]){
				been[y+1][x]=true;
				y++,cost++;
			}
			else if(x-1>=0&&input[y][x-1]=='0'&&!been[y][x-1]){
				been[y][x-1]=true;
				x--,cost++;
			}
			else
				break;
		}
		putchar('\n');
		for(i=0;i<=row*2;i++){
			for(j=0;j<=cul*4;j++)
				if(j%4==0)
					putchar('|');
				else if(i%2==0)	
					putchar('-');
				else if(j%2==0)
					printf("%c",result[(i-1)/2][(j-2)/4]);
				else
					putchar(' ');
			putchar('\n');
		}		
		putchar('\n');
		printf("NUMBER OF MOVEMENTS: %d\n",cost);
	}
	return 0;
}
/*

The ACM factory produces and stores very dangerous products. This is why no human operator is allowed to enter the store room and only specialised robots can access the place to store new products or to retrieve them for their sell. The ACM factory is testing a movil robot which is able to build a partial map of the continuously changing environment of the store. 

The robot can be initially placed at any position of the store. Before starting moving, the robot initialises every cell of its map as a ‘?’, which means “unknown cell”. In the beginning, the robot knows that its starting cell is empty and records this information into its map. Then, the robot reads its four sensors, which will return the state (‘X’ if occupied, ‘0’ if empty) of the four cells around it: NORTH, EAST, SOUTH, WEST. This information is properly recorded in the robot’s map. Then it will move to the first* unvisited free cell and repeat the process until it can not move any further because all the cells around it are occupied or have already been visited. Then the robot outputs its partial map of the store. 

(*) The order used by the robot to select its movements is clockwise, starting from the North orientation.

The Input

The input file consists of a series of sets each containig 2+N lines. First line specifies the size of the map, i.e. two integers  N and M  separated by one space, where  0 < N <= 10 and  0 < M <= 10. The second line specifies the starting point of the robot in the map, i.e. two integers  x_ini and y_ini separated by one space, where  1 <= x_ini  <= N and 1 <= y_ini <= M . In each of the next N lines there must be M characters ‘X’ or ‘0’ separated by one space, where ‘X’ represents obstacles and ‘0’ represents empty squares. The map must be a correct one, which means the initial position of the robot must be always an empty cell. The end of the file is reached the size of the next map is N=0 and M=0.

The Output

The  application outputs an empty line, followed by the robot map, an empty line, and a line containing a message of the movements needed to reach that map.

The robot map must be  shown using the next format:

|---|---| … M … |---|
| s | s | … M … | s |
|---|---| … M … |---|
| s | s | … M … | s |
|---|---| … M … |---|        s Î {‘X’, ‘0’, ‘?’}

… N …

|---|---| … M … |---|
| s | s | … M … | s |
|---|---| … M … |---|

Sample Input 

5 5
1 3
X X 0 0 X
X X 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X
5 5
1 1
0 0 X X X
X X 0 0 X
X 0 0 0 X
X 0 0 0 X
X X X X X
0 0

Sample Output

|---|---|---|---|---|
| ? | X | 0 | 0 | X |
|---|---|---|---|---|
| ? | X | 0 | 0 | X |
|---|---|---|---|---|
| X | 0 | X | 0 | X |
|---|---|---|---|---|
| X | 0 | 0 | 0 | X |
|---|---|---|---|---|
| ? | X | X | X | ? |
|---|---|---|---|---|

NUMBER OF MOVEMENTS: 7

|---|---|---|---|---|
| 0 | 0 | X | ? | ? |
|---|---|---|---|---|
| X | X | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|

NUMBER OF MOVEMENTS: 1

*/