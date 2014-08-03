/* 8872038 10491 Cows and Cars Accepted C++ 0.060 2011-05-22 04:02:29 */
#include<stdio.h>
#include<math.h>
int main(){
	int m,n;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0) break;
		if(n==1) // ¯S®í´ú¸ê
			if(m==1)
				printf("%d %d Multiple\n",n,m);
			else
				printf("%d %d Impossible\n",n,m);
		else{
			double z=(double)(m-1)/(n-1);
			if(z!=ceil(z))
				printf("%d %d Impossible\n",n,m);
			else
				printf("%d %d %d\n",n,m,(int)z*n+1);	
		}
	}
	return 0;
}
/*

--------------------------------------------------------------------------------

A cat wears a hat if and only if it has N cats in it's hat. There is exactly one cat that is not inside any other cat's hat. If there are M cats without hats, how many cats are there? 

Input

Input consists of several test cases. For each case, there would be two integers, N and M, where 1<=N<100000 and 1<=M<100000. The input ends with a case where N=0. You must not process this test case.

Output

For each test case, print N and M. Then if the total number of cats can be expressible uniquely in an integer, print the number. If the case is impossible print the word "Impossible" without quotes. If there are multiple answers, print the word "Multiple" without the quotes.
 
Sample Input

 2 5
 3 4
 3 3
 0 0 
 
Sample Output

 2 5 9
 3 4 Impossible
 3 3 4 
 
--------------------------------------------------------------------------------

Problemsetter: K M Hasan, Member of Elite Problemsetters' Panel
   
*/