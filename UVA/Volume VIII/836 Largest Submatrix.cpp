/* 9354728 836 Largest Submatrix Accepted C++ 0.008 2011-10-10 10:37:10 */
#include<stdio.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
int max_rec(int len[][30],int n){
	int i,j,k;
	int H,L;
	int max_area=0;

	for(i=0;i<n;i++) // 窮舉每個點
		for(j=0;j<n;j++)
			if(len[i][j]>0)
				for(L=len[i][j],H=1,k=i;k>=0&&L>0;k--,H++){ // 窮舉高度
					if(len[k][j]<L)
						L=len[k][j];
					max_area=MAX(max_area,L*H);
				}
	return max_area;
}
int main(){
	int t;
	scanf("%d",&t);
	(void) getchar();
	(void) getchar();
	for(int s=1;s<=t;s++){
		char table[30][30];
		int len[30][30];
		int i,j,n;

		if(s!=1)
			putchar('\n');
		n=0;
		
		
		while(gets(table[n])){
			if(table[n][0]=='\0')
				break;
			n++;
		}

		for(i=0;i<n;i++){
			len[i][0] = table[i][0]=='1' ? 1 : 0 ;
			for(j=1;j<n;j++)
				if(table[i][j]=='1')
					len[i][j]=len[i][j-1]+1;
				else
					len[i][j]=0;
		}
		printf("%d\n",max_rec(len,n));				
	}
	return 0;
}
/*

Let A be an N×N matrix of zeros and ones. A submatrix S of A is any group of contiguous entries that forms a square or a rectangle.
 
Write a program that determines the number of elements of the largest submatrix of ones in A. Largest here is measured by area.
 
Input  

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
 
The matrix is given line by line. Each line consists of 0's and 1's. The order of the matrix is also the number of lines input and 1 N 25.
 
Output 

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
 
The output is the number of elements of the largest submatrix found. 

Sample Input  

1
10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110

 Sample Output  
 
16

--------------------------------------------------------------------------------

Fernando Silva, ACM-UP'2001 

*/