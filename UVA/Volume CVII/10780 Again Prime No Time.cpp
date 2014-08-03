/* 9134158 10780 Again Prime? No Time. Accepted C++ 0.104 2011-08-10 11:11:38 */
#include<stdio.h>
#include<math.h>
#define INT_MAX 2147483647
// 記憶體花好大... 其它神人不知道怎麼做的...
int factor[10001][1300]={0};
int factor_index[10001]={0};
int prime[1300];
int p_index;
void make_prime(){
	int i,j,gap;
	prime[0]=2;
	prime[1]=3;
	p_index=2;

	for(i=5,gap=2;i<=5000;i+=gap,gap=6-gap){
		for(j=0;j<p_index&&i%prime[j]!=0;j++);
		if(j>=p_index)
			prime[p_index++]=i;
	}
}
void make_factor(){
	int i,j,k;
	factor[2][0]=1;
	factor_index[2]=1;
	for(i=3;i<=10000;i++){
		for(j=0;j<factor_index[i-1];j++)
			factor[i][j]=factor[i-1][j];
		factor_index[i]=factor_index[i-1];
		for(j=i,k=0;j>1&&prime[k]<=j&&k<p_index;k++)
			while(j%prime[k]==0){
				factor[i][k]++;
				j/=prime[k];
			}
		if(k>factor_index[i])
			factor_index[i]=k;
	}
}
void fac(int m[],int n){
	int i;
	for(i=0;i<p_index;i++)
		m[i]=0;
	for(i=0;i<p_index&&n>1;i++)		
		while(n%prime[i]==0){
			m[i]++;
			n/=prime[i];
		}
}
int main(){	
	make_prime();
	make_factor();
	int t;
	scanf("%d",&t);
	for(int count=1;count<=t;count++){
		int i;
		int m_fac[1300];				
		int m,n;			
		scanf("%d%d",&m,&n);						
		
		fac(m_fac,m);
		int min=INT_MAX;
		for(i=0;i<factor_index[m];i++)
			if(m_fac[i]>0){
				int temp=factor[n][i]/m_fac[i];
				if(temp<min)
					min=temp;
			}
			
		printf("Case %d:\n",count);
		if(min==0)
			puts("Impossible to divide");
		else
			printf("%d\n",min);
	}	
	return 0;
}
/*

The problem statement is very easy. Given a number n you have to determine the largest power of m, not necessarily prime, that divides n!.
 
Input
 
The input file consists of several test cases. The first line in the file is the number of cases to handle. The following lines are the cases each of which contains two integers m (1<m<5000) and n (0<n<10000). The integers are separated by an space. There will be no invalid cases given and there are not more that 500 test cases.
 
Output
 
For each case in the input, print the case number and result in separate lines. The result is either an integer if m divides n! or a line "Impossible to divide" (without the quotes). Check the sample input and output format.
  
Sample Input

2
2 10
2 100
 
Sample Output

Case 1:
8
Case 2:
97
 
--------------------------------------------------------------------------------

Problem setter: Anupam Bhattacharjee, CSE, BUET Thanks to Shabuj for checking and Adrian for alternate solution. 
  
"~~ Algorithms are the rhythms of Computer Science ~~" 
 
 */