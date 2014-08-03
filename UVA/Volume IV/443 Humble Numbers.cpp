/* 9020563 443 Humble Numbers Accepted C++ 0.140 2011-07-06 07:54:17 */
#include<stdio.h>
#include<math.h>
#define SWAP(x,y) { int t=x; x=y; y=t; }
int m[10000];
int index=0;
void Humble(){
	int i,j,k,l;
	int temp;
	for(i=0;i<=11;i++)
		for(j=0;j<=13;j++)
			for(k=0;k<=19;k++)
				for(l=0;l<=30;l++){
					temp=pow(2.0,l)*pow(3.0,k)*pow(5.0,j)*pow(7.0,i);
					if(temp>0) // 採int 型別 故溢位時會成負號
						m[index++]=temp;
				}
	for(i=0;i<index;i++)
		for(j=i+1;j<index;j++)
			if(m[i]>m[j])
				SWAP(m[i],m[j]);
}
int main(){
	Humble();
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		int judge=n%100;
		if(judge>=10&&judge<=20)
			printf("The %dth humble number is %d.\n",n,m[n-1]);
		else if(judge%10==1)
			printf("The %dst humble number is %d.\n",n,m[n-1]);
		else if(judge%10==2)
			printf("The %dnd humble number is %d.\n",n,m[n-1]);
		else if(judge%10==3)
			printf("The %drd humble number is %d.\n",n,m[n-1]);
		else
			printf("The %dth humble number is %d.\n",n,m[n-1]);
	}
	return 0;
}
/*

A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.
 
Write a program to find and print the nth element in this sequence. 

Input Specification
 
The input consists of one or more test cases. Each test case consists of one integer n with . Input is terminated by a value of zero (0) for n.
 
Output Specification
 
For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.
 
Sample Input
 
1
2
3
4
11
12
13
21
22
23
100
1000
5842
0 

Sample Output 

The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000. 

*/