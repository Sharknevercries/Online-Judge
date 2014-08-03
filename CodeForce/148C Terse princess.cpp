/* 5002147	 Nov 6, 2013 1:44:03 PM	Shark	 C - Terse princess	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define LIMIT 50000
int main(){
	int n,a,b;
	while( scanf("%d%d%d",&n,&a,&b)==3 ){
		if( n==1 )
			puts("1");
		else if( a==n-1&&b==0 )
			puts("-1");
		else{
			int A[101],sum=0,max=0;
			bool legal=true;
			if( b==0 ){
				A[1]=A[2]=1,max=1;
				for(int i=3;i<=2+a;i++)
					A[i]=max+1,max=A[i];
				for(int i=2+a+1;i<=n;i++)
					A[i]=max;
			}
			else{
				A[1]=1,max=1,sum=1;
				for(int i=2;i<=1+b;i++)
					A[i]=sum+1,sum+=A[i],max=A[i];
				for(int i=1+b+1;i<=1+a+b;i++)
					A[i]=max+1,max=A[i];
				for(int i=1+a+b+1;i<=n;i++)
					A[i]=max;
			}
			for(int i=1;i<=n;i++)
				if( A[i]>LIMIT )
					legal=false;
			if( legal ){
				printf("%d",A[1]);
				for(int i=2;i<=n;i++)
					printf(" %d",A[i]);
				putchar('\n');
			}
			else
				puts("-1");
		}
	}
	return 0;
}
/*

C. Terse princess
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
«Next please», — the princess called and cast an estimating glance at the next groom.

The princess intends to choose the most worthy groom, this is, the richest one. Whenever she sees a groom who is more rich than each of the previous ones, she says a measured «Oh...». Whenever the groom is richer than all previous ones added together, she exclaims «Wow!» (no «Oh...» in this case). At the sight of the first groom the princess stays calm and says nothing.

The fortune of each groom is described with an integer between 1 and 50000. You know that during the day the princess saw n grooms, said «Oh...» exactly a times and exclaimed «Wow!» exactly b times. Your task is to output a sequence of n integers t1, t2, ..., tn, where ti describes the fortune of i-th groom. If several sequences are possible, output any of them. If no sequence exists that would satisfy all the requirements, output a single number -1.

Input
The only line of input data contains three integer numbers n, a and b (1 ≤ n ≤ 100, 0 ≤ a, b ≤ 15, n > a + b), separated with single spaces.

Output
Output any sequence of integers t1, t2, ..., tn, where ti (1 ≤ ti ≤ 50000) is the fortune of i-th groom, that satisfies the given constraints. If no sequence exists that would satisfy all the requirements, output a single number -1.

Sample test(s)
input
10 2 3
output
5 1 3 6 16 35 46 4 200 99
input
5 0 0
output
10 10 6 6 5
Note
Let's have a closer look at the answer for the first sample test.

The princess said «Oh...» (highlighted in bold): 5 1 3 6 16 35 46 4 200 99.
The princess exclaimed «Wow!» (highlighted in bold): 5 1 3 6 16 35 46 4 200 99

*/