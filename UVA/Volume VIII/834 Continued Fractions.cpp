/* 834 Continued Fractions Accepted C++ 0.012 2011-02-24 13:41:47 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2){ // 注意到因為分母為大於一而分子為一，故而會一定小於一
		double t;                  // 故右式之值會為整數值加上分數，而整數值可直接求出
		t=(double)a/b;
		printf("[%d;",(int)t);
		a=a-(int)t*b;
		SWAP(a,b);
		t=(double)a/b;
		printf("%d",(int)t);
		a=a-(int)t*b;
		while(a!=0){
			SWAP(a,b);
			t=(double)a/b;
			printf(",%d",(int)t);
			a=a-(int)t*b;}
		printf("]\n");
	}
	return 0;
}
/*

Let b0, b1, b2,..., bn be integers with bk > 0 for k > 0. The continued fraction of order n with coeficients b1, b2,..., bn and the initial term b0 is defined by the following expression 

which can be abbreviated as [b0;b1,..., bn]. 
An example of a continued fraction of order n = 3 is [2;3, 1, 4]. This is equivalent to 

Write a program that determines the expansion of a given rational number as a continued fraction. To ensure uniqueness, make bn > 1. 

Input  

The input consists of an undetermined number of rational numbers. Each rational number is defined by two integers, numerator and denominator. 

Output  

For each rational number given in the input, you should output the corresponding continued fraction. 

Sample Input  

43 19
1 2

Sample Output  

[2;3,1,4]
[0;2]

--------------------------------------------------------------------------------

Fernando Silva, ACM-UP'2001 

*/