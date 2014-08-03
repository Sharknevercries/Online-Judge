/* 4700747	 Oct 7, 2013 2:18:46 PM	Shark	 284A - Cows and Primitive Roots	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
int main(){
	int p;
	while( scanf("%d",&p)==1 ){
		int ans=0;
		for(int i=1;i<p;i++){
			bool IS=true;
			int S=1;
			for(int j=1;j<=p-1;j++){
				S*=i,S%=p;
				if( j==p-1 ){
					if( S!=1 ){
						IS=false;
						break;
					}
				}
				else if( S==1 ){
					IS=false;
					break;
				}
			}
			if( IS )
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Cows and Primitive Roots
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The cows have just learned what a primitive root is! Given a prime p, a primitive root  is an integer x (1 ≤ x < p) such that none of integers x - 1, x2 - 1, ..., xp - 2 - 1 are divisible by p, but xp - 1 - 1 is.

Unfortunately, computing primitive roots can be time consuming, so the cows need your help. Given a prime p, help the cows find the number of primitive roots .

Input
The input contains a single line containing an integer p (2 ≤ p < 2000). It is guaranteed that p is a prime.

Output
Output on a single line the number of primitive roots .

Sample test(s)
input
3
output
1
input
5
output
2
Note
The only primitive root  is 2.

The primitive roots  are 2 and 3.

*/