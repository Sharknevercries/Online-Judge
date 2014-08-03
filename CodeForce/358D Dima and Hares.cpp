/* 4911891	 Oct 27, 2013 2:57:38 PM	Shark	 358D - Dima and Hares	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int A[3001],B[3001],C[3001];
		int DP[2][3001];
		for(int i=0;i<n;i++)	scanf("%d",&A[i]);
		for(int i=0;i<n;i++)	scanf("%d",&B[i]);
		for(int i=0;i<n;i++)	scanf("%d",&C[i]);
		DP[0][n-1]=A[n-1];
		DP[1][n-1]=B[n-1];
		for(int i=n-2;i>=0;i--){
			DP[0][i]=MAX(B[i]+DP[0][i+1],A[i]+DP[1][i+1]);
			DP[1][i]=MAX(C[i]+DP[0][i+1],B[i]+DP[1][i+1]);
		}
		printf("%d\n",DP[0][0]);
	}
	return 0;
}
/*

D. Dima and Hares
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima liked the present he got from Inna very much. He liked the present he got from Seryozha even more.

Dima felt so grateful to Inna about the present that he decided to buy her n hares. Inna was very happy. She lined up the hares in a row, numbered them from 1 to n from left to right and started feeding them with carrots. Inna was determined to feed each hare exactly once. But in what order should she feed them?

Inna noticed that each hare radiates joy when she feeds it. And the joy of the specific hare depends on whether Inna fed its adjacent hares before feeding it. Inna knows how much joy a hare radiates if it eats when either both of his adjacent hares are hungry, or one of the adjacent hares is full (that is, has been fed), or both of the adjacent hares are full. Please note that hares number 1 and n don't have a left and a right-adjacent hare correspondingly, so they can never have two full adjacent hares.

Help Inna maximize the total joy the hares radiate. :)

Input
The first line of the input contains integer n (1 ≤ n ≤ 3000) — the number of hares. Then three lines follow, each line has n integers. The first line contains integers a1 a2 ... an. The second line contains b1, b2, ..., bn. The third line contains c1, c2, ..., cn. The following limits are fulfilled: 0 ≤ ai, bi, ci ≤ 105.

Number ai in the first line shows the joy that hare number i gets if his adjacent hares are both hungry. Number bi in the second line shows the joy that hare number i radiates if he has exactly one full adjacent hare. Number сi in the third line shows the joy that hare number i radiates if both his adjacent hares are full.

Output
In a single line, print the maximum possible total joy of the hares Inna can get by feeding them.

Sample test(s)
input
4
1 2 3 4
4 3 2 1
0 1 1 0
output
13
input
7
8 5 7 6 1 8 9
2 7 9 5 4 3 1
2 3 3 4 1 1 3
output
44
input
3
1 1 1
1 2 1
1 1 1
output
4

*/