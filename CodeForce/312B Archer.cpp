/* 4817656	 Oct 18, 2013 10:04:29 AM	Shark	 312B - Archer	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int a,b,c,d;
	while( scanf("%d%d%d%d",&a,&b,&c,&d)==4 ){
		double ans=0;
		double tmp=1;
		for(int i=1;i<=10000;i++){
			ans+=tmp*(double)a/b;
			tmp*=(1-(double)a/b)*(1-(double)c/d);
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}
/*

B. Archer
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
SmallR is an archer. SmallR is taking a match of archer with Zanoes. They try to shoot in the target in turns, and SmallR shoots first. The probability of shooting the target each time is  for SmallR while  for Zanoes. The one who shoots in the target first should be the winner.

Output the probability that SmallR will win the match.

Input
A single line contains four integers .

Output
Print a single real number, the probability that SmallR will win the match.

The answer will be considered correct if the absolute or relative error doesn't exceed 10 - 6.

Sample test(s)
input
1 2 1 2
output
0.666666666667

*/