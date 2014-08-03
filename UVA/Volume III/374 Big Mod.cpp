/* 9069494 374 Big Mod Accepted C++ 0.008 2011-07-22 08:12:40 */
#include<stdio.h>
unsigned long long result(int B,int P,int M){
	if(P==0)
		return 1;
	if(P==1)
		return B%M;
	if((P&1)==0){
		unsigned long long temp=result(B,P/2,M);
		return temp*temp%M;
	}
	else
		return B*result(B,P-1,M)%M;	
}
int main(){
	int B,P,M;
	while(scanf("%d%d%d",&B,&P,&M)==3){
		printf("%llu\n",result(B%M,P,M));
	}
	return 0;
}
/*

Calculate 

for large values of B, P, and M using an efficient algorithm. (That's right, this problem has a time dependency !!!.)
 
Input
 
Three integer values (in the order B, P, M) will be read one number per line. B and P are integers in the range 0 to 2147483647 inclusive. M is an integer in the range 1 to 46340 inclusive.
 
Output
 
The result of the computation. A single integer. 

Sample Input
 
3
18132
17

17
1765
3

2374859
3029382
36123 

Sample Output
 
13
2
13195 

*/