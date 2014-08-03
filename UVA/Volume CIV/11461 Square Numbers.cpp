/* 9060555 11461 Square Numbers Accepted C++ 0.056 2011-07-19 05:17:20 */
#include<stdio.h>
#include<math.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2&&a!=0&&b!=0){
		int count;
		int i;
		for(i=a,count=0;i<=b;i++){
			if((int)sqrt((double)i)==(double)sqrt((double)i))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
/*

Square Numbers

Input: Standard Input

Output: Standard Output
 
A square number is an integer number whose square root is also an integer. For example 1, 4, 81 are some square numbers. Given two numbers a and b you will have to find out how many square numbers are there between a and b (inclusive).

Input

The input file contains at most 201 lines of inputs. Each line contains two integers a and b (0<a≤b≤100000). Input is terminated by a line containing two zeroes. This line should not be processed. 

Output 

For each line of input produce one line of output. This line contains an integer which denotes how many square numbers are there between a and b (inclusive).

Sample Input                             

1 4
1 10
0 0 

Output for Sample Input

2
3

--------------------------------------------------------------------------------

Problem Setter: Shahriar Manzoor

*/