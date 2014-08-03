/* 9018206 348 Optimal Array Multiplication Sequence Accepted C++ 0.072 2011-07-05 08:46:15 */
#include<stdio.h>
#define INT_MAX 2147483647
#define MAX 20
void show_order(int factor[][MAX],int start,int end){
	int mid;
	if(start==end)
		printf("A%d",start+1);
	else{
		putchar('(');
		mid=factor[start][end];
		show_order(factor,start,mid);
		printf(" x ");
		show_order(factor,mid+1,end);
		putchar(')');
	}
}
void display(int factor[][MAX],int n){
	show_order(factor,0,n-1);
}
int main(){
	int count=1;
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		int cost[MAX][MAX];
		int factor[MAX][MAX];
		int dim[MAX];
		int pre,this_one;
		int i,j,k,x,y;
		for(i=j=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(i==n-1)
				dim[j++]=x,dim[j++]=y;
			else
				dim[j++]=x;
		}
		for(i=0;i<n;i++)
			cost[i][i]=0;
		for(j=1;j<n;j++)
			for(i=j-1;i>=0;i--){
				int min=INT_MAX;
				int pos=-1;
				for(k=i;k<j;k++){
					pre=cost[i][k]+cost[k+1][j];
					this_one=dim[i]*dim[k+1]*dim[j+1];
					if(min>pre+this_one)
						min=pre+this_one,pos=k;
				}
				cost[i][j]=min;
				factor[i][j]=pos;
			}
		printf("Case %d: ",count++);
		display(factor,n);
		putchar('\n');
		
	}
	return 0;
}
/*
  
Given two arrays A and B, we can determine the array C = A B using the standard definition of matrix multiplication:
  
The number of columns in the A array must be the same as the number of rows in the B array. Notationally, let's say that rows(A) and columns(A) are the number of rows and columns, respectively, in the A array. The number of individual multiplications required to compute the entire C array (which will have the same number of rows as A and the same number of columns as B) is then rows(A) columns(B) columns(A). For example, if A is a array, and B is a array, it will take , or 3000 multiplications to compute the C array.
 
To perform multiplication of more than two arrays we have a choice of how to proceed. For example, if X, Y, and Z are arrays, then to compute X Y Z we could either compute (X Y) Z or X (Y Z). Suppose X is a array, Y is a array, and Z is a array. Let's look at the number of multiplications required to compute the product using the two different sequences:
 
(X Y) Z 

• multiplications to determine the product (X Y), a array.
• Then multiplications to determine the final result.
• Total multiplications: 4500. 

X (Y Z) 

• multiplications to determine the product (Y Z), a array.
• Then multiplications to determine the final result.
• Total multiplications: 8750. 

Clearly we'll be able to compute (X Y) Z using fewer individual multiplications.
 
Given the size of each array in a sequence of arrays to be multiplied, you are to determine an optimal computational sequence. Optimality, for this problem, is relative to the number of individual multiplications required.
 
Input
 
For each array in the multiple sequences of arrays to be multiplied you will be given only the dimensions of the array. Each sequence will consist of an integer N which indicates the number of arrays to be multiplied, and then N pairs of integers, each pair giving the number of rows and columns in an array; the order in which the dimensions are given is the same as the order in which the arrays are to be multiplied. A value of zero for N indicates the end of the input. N will be no larger than 10.
  
Output
 
Assume the arrays are named . Your output for each input case is to be a line containing a parenthesized expression clearly indicating the order in which the arrays are to be multiplied. Prefix the output for each case with the case number (they are sequentially numbered, starting with 1). Your output should strongly resemble that shown in the samples shown below. If, by chance, there are multiple correct sequences, any of these will be accepted as a valid answer.
 
Sample Input
 
3
1 5
5 20
20 1
3
5 10
10 20
20 35
6
30 35
35 15
15 5
5 10
10 20
20 25
0 

Sample Output 

Case 1: (A1 x (A2 x A3))
Case 2: ((A1 x A2) x A3)
Case 3: ((A1 x (A2 x A3)) x ((A4 x A5) x A6)) 

*/