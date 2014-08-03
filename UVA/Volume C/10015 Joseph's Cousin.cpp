/* 10015 Joseph's Cousin Accepted C++ 0.148 2011-02-27 11:31:43 */
#include<stdio.h>
static int prime[3502];
static int index;
void make_prime(){
	int i,j;
	prime[0]=2;
	index=1;
	for(i=3;i<=32625;i+=2){
		for(j=0;j<index&&i%prime[j]!=0;j++);
		if(j>=index) prime[index++]=i;
	}
}
int main(){
	int n;
	make_prime();
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int alive;
		int i,j,k,pre;
		int m[3502];
		for(i=0;i<n;i++)
			m[i]=i+1;
		m[n-1]=0;
		alive=n;
		i=j=0; 
		pre=n-1;
		while(alive>1){
			for(k=1;k<prime[i];k++,pre=j,j=m[j]); // i 第i個被吃的人
			m[pre]=m[j]; // j 目前數到的人
			j=m[j]; // k 已經數了k個人
			alive--,i++;
		}
		printf("%d\n",m[j]+1);
	}
	return 0;
}
/*

The Problem


The Joseph’s problem is notoriously known. For those who are not familiar with the problem, among n people numbered 1,2…n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give the message about the incident. 

Although many good programmers have been saved since Joseph spread out this information, Joseph’s Cousin introduced a new variant of the malignant game. This insane character is known for its barbarian ideas and wishes to clean up the world from silly programmers. We had to infiltrate some the agents of the ACM in order to know the process in this new mortal game. 

In order to save yourself from this evil practice, you must develop a tool capable of predicting which person will be saved. 

The Destructive Process 

The persons are eliminated in a very peculiar order; m is a dynamical variable, which each time takes a different value corresponding to the prime numbers’ succession (2,3,5,7…). So in order to kill the ith person, Joseph’s cousin counts up to the ith prime. 

NOTE: This problem may have a runtime of up to 4 minutes. 
  

The Input

It consists of separate lines containing n [1..3501], and finishes with a 0. 

The Output

The output will consist in separate lines containing the position of the person which life will be saved. 

Sample Input

6 
0 

Sample Output

4 

*/