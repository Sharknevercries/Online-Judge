/* 9120622 884 Factorial Factors Accepted C++ 1.200 2011-08-06 14:53:03 */
#include<stdio.h>
#include<math.h>
int m[1000001];
int main(){
	int i,j,temp;
	m[1]=0;
	m[2]=1;

	for(i=3;i<=1000000;i++){
		m[i]=m[i-1];
		for(temp=i,j=2;temp>1&&j<=sqrt((double)temp);j++)
			if(temp%j==0){
				m[i]+=(m[temp/j]-m[temp/j-1]);
				temp=j;
			}
		if(temp>1)
			m[i]++;
	}

	int n;
	while(scanf("%d",&n)==1){
		printf("%d\n",m[n]);
	}
	return 0;
}
/*

The factorial function, n! = 1 . 2 . ... . n, has many interesting properties. In this problem, we want to determine the maximum number of integer terms (excluding 1) that can be used to express n!. For example:
 
8! = 1 . 2 . 3 . 4 . 5 . 6 . 7 . 8 = 2 . 3 . 2 . 2 . 5 . 3 . 2 . 7 . 2 . 2 . 2 = 27 . 32 . 5 . 7
 
By inspection, it is clear that the maximum number of terms (excluding 1) that can be multiplied together to produce 8! is 11.
 
Input 

The input for your program consists of a series of test cases on separate lines, ended by end-of-file. Each line contains one number, n, 2n1000000.
 
Output 

For each test case, print the maximum number of factors (excluding 1) that can be multiplied together to produce n!. Put the output from each test case on a separate line, starting in the first column.
 
Sample Input 

2
1000000
1996
5
8
123456

 Sample Output 

1
3626619
5957
5
11
426566

--------------------------------------------------------------------------------

Miguel Revilla 2004-09-16 

*/