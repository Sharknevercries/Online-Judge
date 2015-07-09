/* 8869863 10377 Maze Traversal Accepted C++ 0.024 2011-05-21 09:27:45 */
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		char table[60][61];
		char command[100];
		int i,row,cul;
		int x,y;
		char face;
		scanf("%d%d",&row,&cul);
		(void) getchar();
		for(i=0;i<row;i++)
			gets(table[i]);		
		scanf("%d%d",&y,&x);
		x--,y--;
		face='N';
		while(true){
			gets(command);
			for(i=0;command[i]!='\0';i++){
				if(command[i]=='R')
					switch(face){
					case 'N':	face='E';	break;
					case 'E':	face='S';	break;
					case 'S':	face='W';	break;
					case 'W':	face='N';	break;
				}
				else if(command[i]=='L')
					switch(face){						
					case 'N':	face='W';	break;
					case 'W':	face='S';	break;
					case 'S':	face='E';	break;
					case 'E':	face='N';	break;
				}
				else if(command[i]=='F')
					switch(face){
					case 'N':	if(table[y-1][x]==' ')	y--;		break;
					case 'E':	if(table[y][x+1]==' ')	x++;	break;
					case 'S':	if(table[y+1][x]==' ')	y++;	break;
					case 'W':	if(table[y][x-1]==' ')	x--;		break;
				}
				else if(command[i]=='Q')
					break;
			}
			if(command[i]=='Q')
				break;
		}
		printf("%d %d %c\n",y+1,x+1,face);
		if(t!=n)
			putchar('\n');
	}
	return 0;
}
/*

 A common problem in artificial intelligence is negotiation of a maze. A maze has corridors and walls. The robot can proceed along corridors, but cannot go through walls.
 
Input

 The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 
 
For this problem, you will input the dimensions of a maze, as two integer values on the first line. Of the two numbers, the first is the number of rows and the second is the number of columns. Neither the number of rows nor columns will exceed 60.
 
Following these numbers will be a number of rows, as specified previously. In each row there will be a character for each column, with the row terminated by the end of line. Blank spaces are corridors, asterisks are walls. There needn't be any exits from the maze.
 
Following the maze, will be an initial row and column specified as two integers on one line. This gives the initial position of the robot. Initially the robot will be facing North (toward the first row).
 
The remaining input will consist of commands to the robot, with any amount of interspersed white-space. The valid commands are:

R rotate the robot 90 degrees clockwise (to the right) L rotate the robot 90 degrees counter-clockwise (to the left) F move the robot forward, unless a wall prevents this, in which case do nothing Q quit the program, printing out the current robot row, column and orientation 

Output

 For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 
 
 The final row and column must be integers separated by a space. The orientation must be one of N,W,S,E and separated from the column by a space.
 
Sample Input

1

7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ

 Sample Output

5 6 W
--------------------------------------------------------------------------------

University of Porto ACM Programming Contest / Round 1 / 2002/05/22 

*/