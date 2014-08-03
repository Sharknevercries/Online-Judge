/* 4817997	 Oct 18, 2013 11:48:44 AM	Shark	 289B - Polo the Penguin and Matrix	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<algorithm>
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
int main(){
	int n,m,d;
	while( scanf("%d%d%d",&n,&m,&d)==3 ){
		int S[10000];
		int min=2e9;
		bool flag;
		for(int i=0;i<n*m;i++){
			scanf("%d",&S[i]);
			if( min>S[i] )
				min=S[i];
		}

		flag=true;
		for(int i=0;i<n*m&&flag;i++){
			S[i]-=min;
			if( S[i]%d!=0 )
				flag=false;
			else
				S[i]/=d;
		}
		if( !flag )
			puts("-1");
		else{
			std::sort(S,S+n*m);
			int mid=n*m/2;
			int ans=0;
			for(int i=0;i<m*n;i++)
				ans+=ABS(S[i]-S[mid]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*

B. Polo the Penguin and Matrix
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little penguin Polo has an n × m matrix, consisting of integers. Let's index the matrix rows from 1 to n from top to bottom and let's index the columns from 1 to m from left to right. Let's represent the matrix element on the intersection of row i and column j as aij.

In one move the penguin can add or subtract number d from some matrix element. Find the minimum number of moves needed to make all matrix elements equal. If the described plan is impossible to carry out, say so.

Input
The first line contains three integers n, m and d (1 ≤ n, m ≤ 100, 1 ≤ d ≤ 104) — the matrix sizes and the d parameter. Next n lines contain the matrix: the j-th integer in the i-th row is the matrix element aij (1 ≤ aij ≤ 104).

Output
In a single line print a single integer — the minimum number of moves the penguin needs to make all matrix elements equal. If that is impossible, print "-1" (without the quotes).

Sample test(s)
input
2 2 2
2 4
6 8
output
4
input
1 2 7
6 7
output
-1

*/