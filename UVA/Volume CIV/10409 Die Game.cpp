/* 8869917 10409 Die Game Accepted C++ 0.028 2011-05-21 09:49:14 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		char str[6];
		int U,D,E,W,S,N,temp,t;
		U=1,D=6,N=2,S=5,W=3,E=4;
		(void) getchar();
		for(t=1;t<=n;t++){
			gets(str);
			switch(str[0]){
			case 'n':
				temp=U; U=S; S=D; D=N; N=temp;	break;
			case 'e':
				temp=U; U=W; W=D; D=E; E=temp;	break;
			case 's':
				temp=U; U=N; N=D; D=S; S=temp;	break;
			case 'w':
				temp=U; U=E; E=D; D=W; W=temp;	break;
			}
		}
		printf("%d\n",U);
	}
	return 0;
}
/*

Life is not easy. Sometimes it is beyond your control. Now, as contestants of ACM ICPC, you might be just tasting the bitter of life. But don't worry! Do not look only on the dark side of life, but look also on the bright side. Life may be an enjoyable game of chance, like throwing dice. Do or die! Then, at last, you might be able to find the route to victory.
 
This problem comes from a game using a die. By the way, do you know a die? It has nothing to do with "death." A die is a cubic object with six faces, each of which represents a different number from one to six and is marked with the corresponding number of spots. Since it is usually used in pair, "a die" is a rarely used word. You might have heard a famous phrase "the die is cast," though.
 
When a game starts, a die stands still on a flat table. During the game, the die is tumbled in all directions by the dealer. You will win the game if you can predict the number seen on the top face at the time when the die stops tumbling.
 
Now you are requested to write a program that simulates the rolling of a die. For simplicity, we assume that the die neither slips nor jumps but just rolls on the table in four directions, that is, north, east, south, and west. At the beginning of every game, the dealer puts the die at the center of the table and adjusts its direction so that the numbers one, two, and three are seen on the top, north, and west faces, respectively. For the other three faces, we do not explicitly specify anything but tell you the golden rule: the sum of the numbers on any pair of opposite faces is always seven.
 
Your program should accept a sequence of commands, each of which is either "north", "east", "south", or "west". A "north" command tumbles the die down to north, that is, the top face becomes the new north, the north becomes the new bottom, and so on. More precisely, the die is rotated around its north bottom edge to the north direction and the rotation angle is 90 degrees. Other commands also tumble the die accordingly to their own directions. Your program should calculate the number finally shown on the top after performing the commands in the sequence. Note that the table is sufficiently large and the die never falls off during the game.

Input
 
The input consists of one or more command sequences, each of which corresponds to a single game. The first line of a command sequence contains a positive integer, representing the number of the following command lines in the sequence. You may assume that this number is less than or equal to 1024. A line containing a zero indicates the end of the input. Each command line includes a command that is one of north, east, south, and west. You may assume that no white space occurs in any lines.
 
Output
 
For each command sequence, output one line containing solely the number on the top face at the time when the game is finished.
 
Sample Input

1
north
3
north
east
south
0

 Output for the Sample Input

5
1
 
--------------------------------------------------------------------------------

Problem Source: Kyoto'99 

*/