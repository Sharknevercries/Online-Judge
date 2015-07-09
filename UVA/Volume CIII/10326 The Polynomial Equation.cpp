/* 8867134 10326 The Polynomial Equation Accepted C++ 0.008 2011-05-20 13:30:18 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		long long int result[52]={0};
		int m[52]={0};
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d",&m[i]);
			m[i]*=-1;
		}
		if(n==1)
			if(m[1]>=0)
				printf("x + %d = 0\n",m[1]);
			else
				printf("x - %d = 0\n",-m[1]);
		else{
			result[2]=m[1];
			result[1]=1;
			for(i=2;i<=n;i++)
				for(j=i+1;j>=2;j--)
					result[j]+=result[j-1]*m[i];
			printf("x^%d",n);
			for(i=2;i<=n;i++){
				if(result[i]==0)
					continue;
				else if(result[i]==1||result[i]==-1)
					if(n-i+1==1)
						if(result[i]==1)
							printf(" + x");
						else
							printf(" - x");
					else
						if(result[i]==1)
							printf(" + x^%d",n-i+1);
						else
							printf(" - x^%d",n-i+1);
				else
					if(n-i+1==1)
						if(result[i]>0)
							printf(" + %lldx",result[i]);
						else
							printf(" - %lldx",-result[i]);
					else
						if(result[i]>0)
							printf(" + %lldx^%d",result[i],n-i+1);
						else
							printf(" - %lldx^%d",-result[i],n-i+1);
			}
			if(result[n+1]>=0)
				printf(" + %d = 0\n",result[n+1]);
			else
				printf(" - %d = 0\n",-result[n+1]);
		}
	}
	return 0;
}
/*
 
A Polynomial equation of degree n is defined as follows :
              
			 C + Sum (Ci*x^i) = 0.  for i=1 to n. 

 A polynomial equation of n degree can have at most n distinct roots which may be both real or complex. Such as a quadratic equation : 

              x^2 - 5x + 6 = 0  has two roots 2 and 3. In this problem you have to generate such a polynomial equation whose roots are already given.
 
The Input
 
The input will start with a positive integer N indicating the number of roots of the polynomial equation. The next line will contain the roots each of which is an integer. N will not exceed 50. Input is terminated by EOF.
 
The Output
 
You have to show the polynomial using x as a variable. If coeffecient of any term x^i (i > 0) becomes zero then you need not show that term. In case of coeffecient being 1 only print x^i(i > 0). Again if the constant term is zero always use + 0. See sample output for more clarification. 

You can be sure that no coeffecient will exceed 10^15. 

Sample Input
 
2
2 3
2
-2 -3
3
0 1 -1

Sample Output 

x^2 - 5x + 6 = 0
x^2 + 5x + 6 = 0
x^3 - x + 0 = 0

 --------------------------------------------------------------------------------
Md. Kamruzzaman

*/