/* 846 Steps Accepted C++ 0.028 2011-02-25 11:30:15 */
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		long long int k,a,b,count;
		scanf("%d%d",&a,&b);
		for(count=-1,k=0;k*k+1<=b-a;k++){ // 每 k^2、k*(k+1) 之後，步數都會加一
			count++;
			if(k*(k+1)+1<=b-a)
				count++;
		}
		if(b-a==0)
			count=0;
		printf("%d\n",count);
	}
	return 0;
}
/*

One steps through integer points of the straight line. The length of a step must be nonnegative and can be by one bigger than, equal to, or by one smaller than the length of the previous step. 

What is the minimum number of steps in order to get from x to y? The length of the first and the last step must be 1. 

Input and Output  
Input consists of a line containing n, the number of test cases. For each test case, a line follows with two integers: 0xy < 231. For each test case, print a line giving the minimum number of steps to get from x to y. 

Sample Input  

3
45 48
45 49
45 50

Sample Output  

3
3
4

--------------------------------------------------------------------------------

Miguel Revilla 2002-06-15 

*/