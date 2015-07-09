/* 8867304 10327 Flip Sort Accepted C++ 0.064 2011-05-20 14:11:10 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
#define INT_MAX 2147483647
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int m[1001];
		int operation;
		int i,j;		
		for(i=0;i<n;i++)
			scanf("%lld",&m[i]);
		for(i=1,operation=0;i<=n;i++){
			int min=INT_MAX;
			for(j=i-1;j<n;j++) // 找出在m[i-1]之後最小之數
				if(min>m[j])
					min=m[j];
			for(j=i-1;m[j]!=min;j++);
			for(;j>=i;j--){
				SWAP(m[j],m[j-1]);
				operation++;
			}
		}
		printf("Minimum exchange operations : %lld\n",operation);
	}
	return 0;
}
/*

Sorting in computer science is an important part. Almost every problem can be solved effeciently if sorted data are found. There are some excellent sorting algorithm which has already acheived the lower bound nlgn. In this problem we will also discuss about a new sorting approach. In this approach only one operation ( Flip ) is available and that is you can exchange two adjacent terms. If you think a while, you will see that it is always possible to sort a set of numbers in this way.
 
The Problem
 
A set of integers will be given. Now using the above approach we want to sort the numbers in ascending order. You have to find out the minimum number of flips required. Such as to sort "1 2 3" we need no flip operation whether to sort "2 3 1" we need at least 2 flip operations.
 
The Input
 
The input will start with a positive integer N ( N<=1000 ). In next few lines there will be N integers. Input will be terminated by EOF.
 
The Output
 
For each data set print "Minimum exchange operations : M" where M is the minimum flip operations required to perform sorting. Use a seperate line for each case.
 
Sample Input
 
3 
1 2 3
3
2 3 1

Sample Output 

Minimum exchange operations : 0
Minimum exchange operations : 2

--------------------------------------------------------------------------------
Md. Kamruzzaman

*/