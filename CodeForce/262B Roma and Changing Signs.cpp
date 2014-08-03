/* 4803044	 Oct 16, 2013 10:37:31 AM	Shark	 262B - Roma and Changing Signs	 GNU C++	Accepted	62 ms	400 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n,k;
	while( scanf("%d%d",&n,&k)==2 ){
		int M[100000],ans,count;
		ans=count=0;
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		std::sort(M,M+n);
		for(int i=0;i<n&&count<k;i++)
			if( M[i]<0 )
				M[i]*=-1,count++;
		std::sort(M,M+n);
		if( k-count>0&&(k-count)%2!=0 )
			M[0]*=-1;
		for(int i=0;i<n;i++)
			ans+=M[i];
		printf("%d\n",ans);
	}
	return 0;
}
/*

B. Roma and Changing Signs
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Roma works in a company that sells TVs. Now he has to prepare a report for the last year.

Roma has got a list of the company's incomes. The list is a sequence that consists of n integers. The total income of the company is the sum of all integers in sequence. Roma decided to perform exactly k changes of signs of several numbers in the sequence. He can also change the sign of a number one, two or more times.

The operation of changing a number's sign is the operation of multiplying this number by -1.

Help Roma perform the changes so as to make the total income of the company (the sum of numbers in the resulting sequence) maximum. Note that Roma should perform exactly k changes.

Input
The first line contains two integers n and k (1 ≤ n, k ≤ 105), showing, how many numbers are in the sequence and how many swaps are to be made.

The second line contains a non-decreasing sequence, consisting of n integers ai (|ai| ≤ 104).

The numbers in the lines are separated by single spaces. Please note that the given sequence is sorted in non-decreasing order.

Output
In the single line print the answer to the problem — the maximum total income that we can obtain after exactly k changes.

Sample test(s)
input
3 2
-1 -1 1
output
3
input
3 1
-1 -1 1
output
1
Note
In the first sample we can get sequence [1, 1, 1], thus the total income equals 3.

In the second test, the optimal strategy is to get sequence [-1, 1, 1], thus the total income equals 1.

*/