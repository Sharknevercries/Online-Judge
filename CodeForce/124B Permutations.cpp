/* 4933234	 Oct 30, 2013 1:48:46 PM	Shark	 124B - Permutations	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
#define SWAP(x,y) { int tmp=x;	x=y;	y=tmp; }
char num[8][9];
char C[8][9];
int S[8];
int findMax(int n,int k){
	int ans=-1;
	for(int i=0;i<n;i++){
		int tmp=0;
		for(int j=0;j<k;j++)
			tmp=tmp*10+C[i][j]-'0';
		if( ans<tmp )
			ans=tmp;
	}
	return ans;
}
int findMin(int n,int k){
	int ans=2e9;
	for(int i=0;i<n;i++){
		int tmp=0;
		for(int j=0;j<k;j++)
			tmp=tmp*10+C[i][j]-'0';
		if( ans>tmp )
			ans=tmp;
	}
	return ans;
}
int main(){
	int n,k;
	while( scanf("%d%d",&n,&k)==2 ){
		int ans=2e9;
		for(int i=0;i<n;i++)
			scanf("%s",num[i]);
		for(int i=0;i<k;i++)
			S[i]=i;

		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++)
				C[i][j]=num[i][S[j]];
			C[i][k]='\0';
		}
		int max=findMax(n,k);
		int min=findMin(n,k);
		if( ans>max-min )
			ans=max-min;
		while( true ){
			int i,j;
			for(i=k-2;i>=0&&S[i]>S[i+1];i--);
			if( i<0 )
				break;
			for(j=k-1;j>i&&S[i]>S[j];j--);
			SWAP(S[i],S[j]);
			for(i++,j=k-1;i<j;i++,j--)
				SWAP(S[i],S[j]);
			for(int i=0;i<n;i++){
				for(int j=0;j<k;j++)
					C[i][j]=num[i][S[j]];
				C[i][k]='\0';
			}
			int max=findMax(n,k);
			int min=findMin(n,k);
			if( ans>max-min )
				ans=max-min;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

B. Permutations
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n k-digit integers. You have to rearrange the digits in the integers so that the difference between the largest and the smallest number was minimum. Digits should be rearranged by the same rule in all integers.

Input
The first line contains integers n and k — the number and digit capacity of numbers correspondingly (1 ≤ n, k ≤ 8). Next n lines contain k-digit positive integers. Leading zeroes are allowed both in the initial integers and the integers resulting from the rearranging of digits.

Output
Print a single number: the minimally possible difference between the largest and the smallest number after the digits are rearranged in all integers by the same rule.

Sample test(s)
input
6 4
5237
2753
7523
5723
5327
2537
output
2700
input
3 3
010
909
012
output
3
input
7 5
50808
36603
37198
44911
29994
42543
50156
output
20522
Note
In the first sample, if we rearrange the digits in numbers as (3,1,4,2), then the 2-nd and the 4-th numbers will equal 5237 and 2537 correspondingly (they will be maximum and minimum for such order of digits).

In the second sample, if we swap the second digits and the first ones, we get integers 100, 99 and 102.

*/