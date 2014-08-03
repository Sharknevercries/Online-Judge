/* 4685010	 Oct 6, 2013 8:44:50 AM	Shark	 272B - Dima and Sequence	 GNU C++	Accepted	62 ms	800 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int S[100000];
		int count[100000];
		long long int ans=0;
		bool visited[100000]={false};

		for(int i=0;i<n;i++)
			scanf("%d",&S[i]);
		for(int i=0;i<n;i++){
			int tmp=S[i],digit=0;
			while( tmp>0 ){
				if( (tmp&1)==1 )
					digit++;
				tmp>>=1;
			}
			count[i]=digit;
		}
		for(int i=0;i<n;i++)
			if( !visited[i] ){
				long long int tmp=1;
				visited[i]=true;
				for(int j=i+1;j<n;j++)
					if( count[i]==count[j] )
						tmp++,visited[j]=true;
				ans+=(tmp-1)*tmp/2;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

B. Dima and Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima got into number sequences. Now he's got sequence a1, a2, ..., an, consisting of n positive integers. Also, Dima has got a function f(x), which can be defined with the following recurrence:

f(0) = 0;
f(2·x) = f(x);
f(2·x + 1) = f(x) + 1.
Dima wonders, how many pairs of indexes (i, j) (1 ≤ i < j ≤ n) are there, such that f(ai) = f(aj). Help him, count the number of such pairs.

Input
The first line contains integer n (1 ≤ n ≤ 105). The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

The numbers in the lines are separated by single spaces.

Output
In a single line print the answer to the problem.

Please, don't use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

Sample test(s)
input
3
1 2 4
output
3
input
3
5 3 1
output
1
Note
In the first sample any pair (i, j) will do, so the answer is 3.

In the second sample only pair (1, 2) will do.

*/