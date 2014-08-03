/* 9117570 11827 Maximum GCD Accepted C++ 0.008 2011-08-05 15:06:17 */
#include<stdio.h>
typedef unsigned long long int64;
int64 GCD(int64 a,int64 b){
	int64 r;
	if(a==0||b==0)
		return a>0?b:a;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main(){
	int n;
	scanf("%d",&n);
	(void) getchar();
	for(int t=1;t<=n;t++){		
		char str[100000];		
		int index=0;
		int i,j;
		unsigned long long temp,m[1000];

		gets(str);
		for(i=temp=0;;i++)
			if(str[i]>='0'&&str[i]<='9')
				temp=temp*10+str[i]-'0';
			else{
				m[index++]=temp;
				temp=0;
				if(str[i]=='\0')
					break;
			}		
		int64 max=0;
		for(i=0;i<index;i++)
			for(j=i+1;j<index;j++){
				int64 gcd=GCD(m[i],m[j]);
				if(gcd>max)
					max=gcd;
			}
		printf("%llu\n",max);
	}
	return 0;
}
/*

Given the N integers, you have to find the maximum GCD(greatest common divisor) of every possible pair of these integers.

Input

The first line of input is an integer N(1<N<100) that determines the number of test cases.

The following N lines are the N test cases. Each test case contains M (1<M<100) positive integers that you have to find the maximum of GCD. 

Output 

For each test case show the maximum GCD of every possible pair.

Sample Input
 
3
10 20 30 40
7  5 12 
125 15 25

Output for Sample Input

20
1
25
 
--------------------------------------------------------------------------------

Problemsetter: Amarin Deemagarn

*/