/* 8881045 10591 Happy Number Accepted C++ 0.008 2011-05-24 14:05:49 */
#include<stdio.h>
int main(){
	int count;
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=count=1;i<=n;i++){
		bool circulation[10000]={false};
		unsigned long long int s,temp,origin;
		scanf("%llu",&s);
		origin=s;
		while(true){
			for(j=1,temp=0;j<=s;j*=10)
				temp+=((s%(j*10))/j)*((s%(j*10))/j);
			if(temp==1){
				printf("Case #%d: %llu is a Happy number.\n",count++,origin);
				break;
			}
			else if(!circulation[temp])
				circulation[temp]=true;
			else{
				printf("Case #%d: %llu is an Unhappy number.\n",count++,origin);
				break;
			}
			s=temp;
		}
	}
	return 0;
}
/*

Let the sum of the square of the digits of a positive integer S0 be represented by S1. In a similar way, let the sum of the squares of the digits of S1 be represented by S2 and so on. If Si = 1 for some i ³ 1, then the original integer S0 is said to be Happy number. A number, which is not happy, is called Unhappy number. For example 7 is a Happy number since 7 -> 49 -> 97 -> 130 -> 10 -> 1 and 4 is an Unhappy number since 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4.

Input

The input consists of several test cases, the number of which you are given in the first line of the input. Each test case consists of one line containing a single positive integer N smaller than 109.

Output

For each test case, you must print one of the following messages: 

Case #p: N is a Happy number.

Case #p: N is an Unhappy number. 

Here p stands for the case number (starting from 1). You should print the first message if the number N is a happy number. Otherwise, print the second line.

Sample Input

3
7
4
13

Output for Sample Input

Case #1: 7 is a Happy number.
Case #2: 4 is an Unhappy number.
Case #3: 13 is a Happy number.
 
Problemsetter: Mohammed Shamsul Alam
International Islamic University Chittagong
Special thanks to Muhammad Abul Hasan

*/