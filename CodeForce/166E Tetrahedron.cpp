/* 4681142	 Oct 5, 2013 5:20:39 PM	Shark	 166E - Tetrahedron	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define MOD 1000000007
long long int M[4]={2,1,3,0};
void calculate(long long int ans[],int n){
	if( n==1 )
		ans[0]=2,ans[1]=1,ans[2]=3,ans[3]=0;
	else if( (n&1)==0 ){
		long long int tmp[4];
		calculate(tmp,n>>1);
		ans[0]=(tmp[0]*tmp[0]+tmp[1]*tmp[2])%MOD;
		ans[1]=(tmp[0]*tmp[1]+tmp[1]*tmp[3])%MOD;
		ans[2]=(tmp[2]*tmp[0]+tmp[3]*tmp[2])%MOD;
		ans[3]=(tmp[2]*tmp[1]+tmp[3]*tmp[3])%MOD;
	}
	else{
		long long int tmp[4];
		calculate(tmp,n-1);
		ans[0]=(tmp[0]*M[0]+tmp[1]*M[2])%MOD;
		ans[1]=(tmp[0]*M[1]+tmp[1]*M[3])%MOD;
		ans[2]=(tmp[2]*M[0]+tmp[3]*M[2])%MOD;
		ans[3]=(tmp[2]*M[1]+tmp[3]*M[3])%MOD;
	}
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		if( n>1 ){
			long long int ans[4];
			calculate(ans,n-1);
			printf("%lld\n",ans[2]);
		}
		else
			puts("0");
	}
	return 0;
}
/*

E. Tetrahedron
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.


An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. The ant just can't stand on one place.

You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (109 + 7).

Input
The first line contains the only integer n (1 ≤ n ≤ 107) — the required length of the cyclic path.

Output
Print the only integer — the required number of ways modulo 1000000007 (109 + 7).

Sample test(s)
input
2
output
3
input
4
output
21
Note
The required paths in the first sample are:

D - A - D
D - B - D
D - C - D

*/