/* 9117868 147 Dollars Accepted C++ 0.020 2011-08-05 16:17:44 */
#include<stdio.h>
typedef unsigned long long int64;
int main(){
	int size[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
	int n=sizeof(size)/sizeof(int);
	int64 money[30001]={0};
	int i,j;
	money[0]=1;

	for(i=0;i<n;i++)
		for(j=size[i];j<=30000;j+=5)
			money[j]+=money[j-size[i]];
	
	double t;
	while(scanf("%lf",&t)&&t!=0){		
		int m=(int)(t*1000);
		if(m%10>=5)
			m+=10;
		m/=10;
		printf("%6.2lf%17llu\n",t,money[m]);
	}
	return 0;
}
/*

New Zealand currency consists of $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c coins. Write a program that will determine, for any given amount, in how many ways that amount may be made up. Changing the order of listing does not increase the count. Thus 20c may be made up in 4 ways: 1 20c, 2 10c, 10c+2 5c, and 4 5c.
 
Input
 
Input will consist of a series of real numbers no greater than $300.00 each on a separate line. Each amount will be valid, that is will be a multiple of 5c. The file will be terminated by a line containing zero (0.00).
 
Output
 
Output will consist of a line for each of the amounts in the input, each line consisting of the amount of money (with two decimal places and right justified in a field of width 6), followed by the number of ways in which that amount may be made up, right justified in a field of width 17.
  
Sample input 

0.20
2.00
0.00 

Sample output 

  0.20                4
  2.00              293 

*/