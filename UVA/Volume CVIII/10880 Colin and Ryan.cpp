/* 8935450 10880 Colin and Ryan Accepted C++ 0.080 2011-06-10 11:35:11 */
#include<stdio.h>
#include<math.h>
int main(){
	int n;	
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int C,R;
		scanf("%d%d",&C,&R);
		int amount=C-R;		
		int i,index,m[10000]={0};
		int sq=sqrt((double)amount);
		index=0;
		printf("Case #%d:",t);
		for(i=1;i<=sq;i++)
			if(amount%i==0){
				if(i>R)
					printf(" %d",i);
				if(amount/i>R)
					m[index++]=amount/i;
			}
		if(m[index-1]*m[index-1]==amount)
			i=index-1-1;
		else
			i=index-1;
		for(;i>=0;i--)
			printf(" %d",m[i]);
		if(C==R)
			printf(" 0"); 
		putchar('\n');
	}
	return 0;
}
/*

Ryan: "As a special bonus, if they order
by midnight, what would they receive?
 Colin: They'd receive it earlier than if
they'd ordered it later. 

Songs of the Butcher 

Colin and Ryan had a party. They baked C cookies and invited G guests. Each guest ate Q cookies, and R cookies were left (R<Q).
 
Input

 The first line of input gives the number of cases, N. N test cases follow. Each one is a line containing C and R (at most 2000000000).
 
Output

 For each test case, output one line containing "Case #x:" followed by Q - the number of cookies each guest ate. If there are multiple answers, print them in increasing order, separated by spaces. Do not print trailing spaces. Print a 0 in the case when C = R.
 
Sample Input 

4
10 0
13 2
300 98
1000 997

 Sample Output 

Case #1: 1 2 5 10
Case #2: 11
Case #3: 101 202
Case #4:

--------------------------------------------------------------------------------
Problemsetter: Igor Naverniouk
 Alternate solutions: Frank Pok Man Chu and Yury Kholondyrev 

*/