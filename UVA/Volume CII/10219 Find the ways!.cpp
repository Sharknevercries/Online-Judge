/* 8846022 10219 Find the ways ! Accepted C++ 0.008 2011-05-15 04:23:49 */
#include<stdio.h>
#include<math.h>
int main(){
	unsigned long long  n,k;
	while(scanf("%llu%llu",&n,&k)==2){
		double sum;
		if(n<2*k)
			k=n-k;
		int a,b;
		for(a=n,b=1,sum=0;k!=0&&b<=k;a--,b++)
			sum+=log10((double)a)-log10((double)b); // 真數不得為零
		printf("%d\n",(int)floor(sum)+1);
	}
	return 0;
}
/*

The Problem
 
An American, a Frenchman and an Englishwoman had been to Dhaka, the capital of Bangladesh. They went sight-seeing in a taxi. The three tourists were talking about the sites in the city. The American was very proud of tall buildings in New York. He boasted to his friends, "Do you know that the Empire State Building was built in three months?"
 
"Really?" replied the Frenchman. "The Eiffel Tower in Paris was built in only one month! (However, The truth is, the construction of the Tower began in January 1887. Forty Engineers and designers under Eiffel's direction worked for two years. The tower was completed in March 1889.)
 
"How interesting!" said the Englishwoman. "Buckingham Palace in London was built in only two weeks!!"
 
At that moment the taxi passed a big slum ( However, in Bangladesh we call it "Bostii"). "What was that? When it was built ?" The Englishwomen asked the driver who was a Bangladeshi.
 
"I don't know!" , answered the driver. "It wasn't there yesterday!"
 
However in Bangladesh, illegal establishment of slums is a big time problem. Government is trying to destroy these slums and remove the peoples living there to a far place, formally in a planned village outside the city. But they can't find any ways, how to destroy all these slums!
 
Now, can you imagine yourself as a slum destroyer? In how many ways you can destroy k slums out of n slums ! Suppose there are 10 slums and you are given the permission of destroying 5 slums, surly you can do it in 252 ways, which is only a 3 digit number, Your task is to find out the digits in ways you can destroy the slums !
   
The Input
 
The input file will contain one or more test cases. 

Each test case consists of one line containing two integers n (n>=1) and k (1<=<k=<n).
 
The Output
 
For each test case, print one line containing the required number. This number will always fit into an integer, i.e. it will be less than 2^31-1.
 
Sample Input

20 5
100 10
200 15 

Sample Output

5
14
23 

--------------------------------------------------------------------------------------------------------------------
 
Ahmed Shamsul Arefin 
 
*/