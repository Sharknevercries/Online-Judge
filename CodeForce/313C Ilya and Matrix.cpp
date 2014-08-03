/* 4826052	 Oct 19, 2013 8:12:30 PM	Shark	 313C - Ilya and Matrix	 GNU C++	Accepted	686 ms	7800 KB */
#include<stdio.h>
#include<algorithm>
int M[2000000];
bool cmp(const int &A,const int &B){
	return A>B;
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		long long int ans=0;
		int s=1;
		for(int i=1;i<n;i<<=2,s++);
		for(int i=1;i<=n;i++)
			scanf("%d",&M[i]);
		std::sort(M+1,M+1+n,cmp);
		for(int i=0;i<s;i++) // this code can be inplemented more efficiently 
			for(int j=1;j<=(1<<(2*i));j++)
				ans+=M[j];
		printf("%lld\n",ans);
	}
	return 0;
}
/*

C. Ilya and Matrix
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ilya is a very good-natured lion. He likes maths. Of all mathematical objects, his favourite one is matrices. Now he's faced a complicated matrix problem he needs to solve.

He's got a square 2n × 2n-sized matrix and 4n integers. You need to arrange all these numbers in the matrix (put each number in a single individual cell) so that the beauty of the resulting matrix with numbers is maximum.

The beauty of a 2n × 2n-sized matrix is an integer, obtained by the following algorithm:

Find the maximum element in the matrix. Let's denote it as m.
If n = 0, then the beauty of the matrix equals m. Otherwise, a matrix can be split into 4 non-intersecting 2n - 1 × 2n - 1-sized submatrices, then the beauty of the matrix equals the sum of number m and other four beauties of the described submatrices.
As you can see, the algorithm is recursive.

Help Ilya, solve the problem and print the resulting maximum beauty of the matrix.

Input
The first line contains integer 4n (1 ≤ 4n ≤ 2·106). The next line contains 4n integers ai (1 ≤ ai ≤ 109) — the numbers you need to arrange in the 2n × 2n-sized matrix.

Output
On a single line print the maximum value of the beauty of the described matrix.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Sample test(s)
input
1
13
output
13
input
4
1 2 3 4
output
14
Note
Consider the second sample. You need to arrange the numbers in the matrix as follows:

1 2
3 4
Then the beauty of the matrix will equal: 4 + 1 + 2 + 3 + 4 = 14.

*/