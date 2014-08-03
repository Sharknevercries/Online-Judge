/* 9249128 167 The Sultan's Successors Accepted C++ 0.008 2011-09-11 16:42:46 */
#include<stdio.h>
#define IS_SAFE(r,c) ( row[r]==SAFE && dig[r+c]==SAFE && back_dig[7-(c-r)]==SAFE )
#define SET(r,c) { row[r]=c;	dig[r+c]=back_dig[7-(c-r)]=UNSAFE;	}
#define REMOVE(r,c) {  row[r]=dig[r+c]=back_dig[7-(c-r)]=SAFE;	}
#define SAFE -1
#define UNSAFE 0
int row[8];
int dig[15];
int back_dig[15];
int table[8][8];
int max;
void initial(){
	int i;
	for(i=0;i<15;i++)
		row[i]=dig[i]=back_dig[i]=SAFE;
	max=0;
}
void get_result(){
	int i,sum;
	for(i=sum=0;i<8;i++)
		sum+=table[i][row[i]];
	if(sum>max)
		max=sum;	
}
void try_(int cul){
	int i;
	for(i=0;i<8;i++)
		if(IS_SAFE(i,cul)){
			SET(i,cul);
			if(cul==7)
				get_result();
			else
				try_(cul+1);
			REMOVE(i,cul);
		}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int i,j;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				scanf("%d",&table[i][j]);
		initial();
		try_(0);
		printf("%5d\n",max);
	}
	return 0;
}
/*

The Sultan of Nubia has no children, so she has decided that the country will be split into up to k separate parts on her death and each part will be inherited by whoever performs best at some test. It is possible for any individual to inherit more than one or indeed all of the portions. To ensure that only highly intelligent people eventually become her successors, the Sultan has devised an ingenious test. In a large hall filled with the splash of fountains and the delicate scent of incense have been placed k chessboards. Each chessboard has numbers in the range 1 to 99 written on each square and is supplied with 8 jewelled chess queens. The task facing each potential successor is to place the 8 queens on the chess board in such a way that no queen threatens another one, and so that the numbers on the squares thus selected sum to a number at least as high as one already chosen by the Sultan. (For those unfamiliar with the rules of chess, this implies that each row and column of the board contains exactly one queen, and each diagonal contains no more than one.) 

Write a program that will read in the number and details of the chessboards and determine the highest scores possible for each board under these conditions. (You know that the Sultan is both a good chess player and a good mathematician and you suspect that her score is the best attainable.)
 
Input
 
Input will consist of k (the number of boards), on a line by itself, followed by k sets of 64 numbers, each set consisting of eight lines of eight numbers. Each number will be a positive integer less than 100. There will never be more than 20 boards.
 
Output
 
Output will consist of k numbers consisting of your k scores, each score on a line by itself and right justified in a field 5 characters wide.
 
Sample input
 
1
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64 

Sample output
 
  260 

*/