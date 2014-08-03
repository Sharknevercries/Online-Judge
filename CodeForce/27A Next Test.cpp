/* 4803288	 Oct 16, 2013 11:14:39 AM	Shark	 27A - Next Test	 GNU C++	Accepted	0 ms	0 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[3001];
		for(int i=1;i<=n;i++)
			scanf("%d",&M[i]);
		std::sort(M+1,M+n+1);

		int ans;
		for(ans=1;ans<=n;ans++)
			if( M[ans]!=ans )
				break;
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Next Test
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
«Polygon» is a system which allows to create programming tasks in a simple and professional way. When you add a test to the problem, the corresponding form asks you for the test index. As in most cases it is clear which index the next test will have, the system suggests the default value of the index. It is calculated as the smallest positive integer which is not used as an index for some previously added test.

You are to implement this feature. Create a program which determines the default index of the next test, given the indexes of the previously added tests.

Input
The first line contains one integer n (1 ≤ n ≤ 3000) — the amount of previously added tests. The second line contains n distinct integers a1, a2, ..., an (1 ≤ ai ≤ 3000) — indexes of these tests.

Output
Output the required default value for the next test index.

Sample test(s)
input
3
1 7 2
output
3

*/