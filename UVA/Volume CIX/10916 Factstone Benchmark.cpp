/* 9376680 10916 Factstone Benchmark Accepted C++ 0.340 2011-10-16 09:24:15 */
#include<stdio.h>
#include<math.h>
#define log2 log(2.0)
int DP[30];
int main(){
	int i,j,k;
	double value;
	int exp;

	for(i=0,exp=4,j=0,value=0;i<=25;i++,exp<<=1){ // log(n!) = log1 + log2 + ... + logn
		for( ; value<exp*log2 ; ++j , value+=log((double)j) );
		DP[i]=j-1;
	}
	int n;
	while(scanf("%d",&n)==1){
		if(n==0)
			break;
		printf("%d\n",DP[(n-1960)/10]);
	}
	return 0;
}
/*

 Amtel has announced that it will release a 128-bit computer chip by 2010, a 256-bit computer by 2020, and so on, continuing its strategy of doubling the word-size every ten years. (Amtel released a 64-bit computer in 2000, a 32-bit computer in 1990, a 16-bit computer in 1980, an 8-bit computer in 1970, and a 4-bit computer, its first, in 1960.)
 Amtel will use a new benchmark - the Factstone - to advertise the vastly improved capacity of its new chips. The Factstone rating is defined to be the largest integer n such that n! can be represented as an unsigned integer in a computer word.
 
Given a year 1960 ≤ y ≤ 2160, what will be the Factstone rating of Amtel's most recently released chip?
 
There are several test cases. For each test case, there is one line of input containing y. A line containing 0 follows the last test case. For each test case, output a line giving the Factstone rating.
 
Sample Input
1960
1981
0
 
Output for Sample Input

3
8
 
--------------------------------------------------------------------------------
Charles L. A. Clarke and Gordon V. Cormack 

*/