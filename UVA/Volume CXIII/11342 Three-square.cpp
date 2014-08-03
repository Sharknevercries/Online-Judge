/* 9060719 11342 Three-square Accepted C++ 0.188 2011-07-19 06:49:57 */
#include<stdio.h>
#include<math.h>
#define SWAP(x,y) { int tmp=x; x=y; y=tmp; }
void print(int j,int a,int b){
	if(j>a)
		SWAP(j,a);
	if(j>b)
		SWAP(j,b);
	if(a>b)
		SWAP(a,b);
	printf("%d %d %d\n",j,a,b);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		bool found=false;
		int a,b,j;
		int n;
		scanf("%d",&n);
		for(j=0;j*j<=n;j++){
			int temp=n-j*j;
			a=sqrt((double)temp);
			b=0;
			while(b<=a)
				if(a*a+b*b==temp){
					print(j,a,b);
					found=true;
					break;
				}
				else if(a*a+b*b>temp)
					a--;
				else
					b++;
			if(found)
				break;
		}
		if(!found)
			puts("-1");
	}
	return 0;
}
/*

Lagrange's four-square theorem states that every positive integer can be expressed as the sum of four squares of integers. For example:
 3 = 12 + 12 + 12 + 02
 31 = 52 + 22 + 12 + 12

However some positive integers can be expressed even as the sum of three squares of non-negative integers. For example:
 3 = 12 + 12 + 12
 17 = 02 + 12 + 42

In this problem you have to find expression of given integer K as the sum of three squares, or state that it is impossible.

INPUT:

 The first line contains integer N (0 < N <= 10000), it is number of tests. Each of the next N lines contains a positive integers K (0 < K <= 50000).
 
OUTPUT:

 For each test case print a line formatted like this: "a b c". Where a <= b <= c and K = a2 + b2 + c2. If there is more than one possible answer, print the one that comes first lexicographically. If expression in three squares of non-negative integers do not exist print "-1" (see examples).
 
SAMPLE INPUT:

 3
13
15
17

 SAMPLE OUTPUT:

 0 2 3
-1
0 1 4

--------------------------------------------------------------------------------

 Problem setters: Aleksej Viktorchik, Leonid Shishlo. 
Huge Easy Contest #1

 */