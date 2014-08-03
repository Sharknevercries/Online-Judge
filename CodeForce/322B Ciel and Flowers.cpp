/* 4685667	 Oct 6, 2013 11:42:54 AM	Shark	 322B - Ciel and Flowers	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define MAX(x,y) ( (x)>=(y) ? (x) : (y) )
void calculate(int *ans,int *n){
	if( (*n)>6 ){
		(*ans)+=(*n)/3,(*n)%=3;
		while( (*n)+3<=6 )
			(*ans)--,(*n)+=3;
	}
}
int main(){
	int table[7][7][7]={0};
	for(int i=0;i<=6;i++)
		for(int j=0;j<=6;j++)
			for(int k=0;k<=6;k++){
				if( i-3>=0 )
					table[i][j][k]=MAX(table[i-3][j][k]+1,table[i][j][k]);
				if( j-3>=0 )
					table[i][j][k]=MAX(table[i][j-3][k]+1,table[i][j][k]);
				if( k-3>=0 )
					table[i][j][k]=MAX(table[i][j][k-3]+1,table[i][j][k]);
				if( i-1>=0&&j-1>=0&&k-1>=0 )
					table[i][j][k]=MAX(table[i-1][j-1][k-1]+1,table[i][j][k]);
			}

	int a,b,c;
	while( scanf("%d%d%d",&a,&b,&c)==3 ){
		
		int ans=0;
		calculate(&ans,&a);
		calculate(&ans,&b);
		calculate(&ans,&c);
		printf("%d\n",ans+table[a][b][c]);
	}
	return 0;
}
/*

B. Ciel and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel has some flowers: r red flowers, g green flowers and b blue flowers. She wants to use these flowers to make several bouquets. There are 4 types of bouquets:

To make a "red bouquet", it needs 3 red flowers.
To make a "green bouquet", it needs 3 green flowers.
To make a "blue bouquet", it needs 3 blue flowers.
To make a "mixing bouquet", it needs 1 red, 1 green and 1 blue flower.
Help Fox Ciel to find the maximal number of bouquets she can make.

Input
The first line contains three integers r, g and b (0 ≤ r, g, b ≤ 109) — the number of red, green and blue flowers.

Output
Print the maximal number of bouquets Fox Ciel can make.

Sample test(s)
input
3 6 9
output
6
input
4 4 4
output
4
input
0 0 0
output
0
Note
In test case 1, we can make 1 red bouquet, 2 green bouquets and 3 blue bouquets.

In test case 2, we can make 1 red, 1 green, 1 blue and 1 mixing bouquet.

*/