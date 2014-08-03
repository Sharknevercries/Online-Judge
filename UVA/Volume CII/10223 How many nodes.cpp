/* 8846131 10223 How many nodes ? Accepted C++ 0.036 2011-05-15 05:07:30 */
#include<stdio.h>
int main(){
	int m[200]={0};
	int i,j;
	for(i=m[0]=1;i<=100;i++)
		for(j=0;j<i;j++)
			m[i]+=m[j]*m[i-j-1]; // ³W«ß
	unsigned long long n;
	while(scanf("%llu",&n)==1){
		for(i=1;;i++)
			if(m[i]==n)
				break;
		printf("%d\n",i);

	}
	return 0;
}
/*

The Problem
 
One of the most popular topic of Data Structures is Rooted Binary Tree. If you are given some nodes you can definitely able to make the maximum number of trees with them. But if you are given the maximum number of trees built upon a few nodes, Can you find out how many nodes built those trees?
 
The Input
 
The input file will contain one or more test cases. 

Each test case consists of an integer n (n<=4,294,967,295). Here n is the maximum number of trees.
 
The Output
 
For each test case, print one line containing the actual number of nodes.
 
Sample Input

 5
14
42 

Sample Output

3
4
5 

--------------------------------------------------------------------------------------------------------------------------
 
"When I came to you, you pushed me away! Because that was your time. Now, you are calling me back, (However, now it is my time!) should I look behind?"
 
Ahmed Shamsul Arefin 

*/