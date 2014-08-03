/* 9053084 357 Let Me Count The Ways Accepted C++ 0.012 2011-07-16 07:54:59 */
#include<stdio.h>
int main(){
	int money[]={1,5,10,25,50};
	unsigned long long result[30001]={0};
	int i,j,t;
	int n=sizeof(money)/sizeof(int);
	result[0]=1;
	for(i=0;i<n;i++)
		for(j=money[i];j<=30000;j++)
			result[j]+=result[j-money[i]];
	while(scanf("%d",&t)==1){
		if(result[t]==1)
			 printf("There is only %llu way to produce %d cents change.\n",result[t],t);
		else
			printf("There are %llu ways to produce %d cents change.\n",result[t],t);
	}
	return 0;
}
/*

After making a purchase at a large department store, Mel's change was 17 cents. He received 1 dime, 1 nickel, and 2 pennies. Later that day, he was shopping at a convenience store. Again his change was 17 cents. This time he received 2 nickels and 7 pennies. He began to wonder ' "How many stores can I shop in and receive 17 cents change in a different configuration of coins? After a suitable mental struggle, he decided the answer was 6. He then challenged you to consider the general problem.
 
Write a program which will determine the number of different combinations of US coins (penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50c) which may be used to produce a given amount of money.
 
Input
 
The input will consist of a set of numbers between 0 and 30000 inclusive, one per line in the input file.
 
Output
 
The output will consist of the appropriate statement from the selection below on a single line in the output file for each input value. The number m is the number your program computes, n is the input value.
 
There are m ways to produce n cents change. 

There is only 1 way to produce n cents change. 

Sample input
 
17 
11
4 

Sample output

There are 6 ways to produce 17 cents change. 
There are 4 ways to produce 11 cents change. 
There is only 1 way to produce 4 cents change. 

*/