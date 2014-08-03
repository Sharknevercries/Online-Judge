/* 439 Knight Moves Accepted C++ 0.028 2011-02-26 11:03:38 */
#include<stdio.h>
struct quene{
	int x;
	int y;
	int count;
};
int front;
int behind;
bool been[8][8];
struct quene s[1000];
void initial(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			been[i][j]=false;
	front=-1;
	behind=-1;
}
void push(int x,int y,int count){
	s[++front].x=x;
	s[front].y=y;
	s[front].count=count;
}
int BFS(int x,int y){
	int xx,yy;
	int count=0;
	while(front>behind){
		xx=s[++behind].x;
		yy=s[behind].y;
		count=s[behind].count;
		been[xx][yy]=true;
		if(xx==x&&yy==y)
			return count;
		else{
			if(xx+2<8&&yy+1<8&&!been[xx+2][yy+1]) push(xx+2,yy+1,count+1);
			if(xx+2<8&&yy-1>=0&&!been[xx+2][yy-1]) push(xx+2,yy-1,count+1);
			if(xx+1<8&&yy+2<8&&!been[xx+1][yy+2]) push(xx+1,yy+2,count+1);
			if(xx+1<8&&yy-2>=0&&!been[xx+1][yy-2]) push(xx+1,yy-2,count+1);
			if(xx-2>=0&&yy+1<8&&!been[xx-2][yy+1]) push(xx-2,yy+1,count+1);	
			if(xx-2>=0&&yy-1>=0&&!been[xx-2][yy-1]) push(xx-2,yy-1,count+1);
			if(xx-1>=0&&yy+2<8&&!been[xx-1][yy+2]) push(xx-1,yy+2,count+1);	
			if(xx-1>=0&&yy-2>=0&&!been[xx-1][yy-2]) push(xx-1,yy-2,count+1);	
		}
	}	
}
int main(){
	char str[6];
	char start_c,end_c;
	int start_i,end_i;
	while(gets(str)){
		start_c=str[0];	start_i=str[1]-'0';	end_c=str[3];	end_i=str[4]-'0';
		initial();
		push((int)start_c-'a',start_i-1,0);
		printf("To get from %c%d to %c%d takes %d knight moves.\n",start_c,start_i,end_c,end_i,BFS((int)end_c-'a',end_i-1));
	}
	return 0;
}
/*

A friend of you is doing research on the Traveling Knight Problem (TKP) where you are to find the shortest closed tour of knight moves that visits each square of a given set of n squares on a chessboard exactly once. He thinks that the most difficult part of the problem is determining the smallest number of knight moves between two given squares and that, once you have accomplished this, finding the tour would be easy. 

Of course you know that it is vice versa. So you offer him to write a program that solves the "difficult" part. 

Your job is to write a program that takes two squares a and b as input and then determines the number of knight moves on a shortest route from a to b. 

Input Specification

The input file will contain one or more test cases. Each test case consists of one line containing two squares separated by one space. A square is a string consisting of a letter (a-h) representing the column and a digit (1-8) representing the row on the chessboard. 

Output Specification

For each test case, print one line saying "To get from xx to yy takes n knight moves.". 

Sample Input

e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output

To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

*/