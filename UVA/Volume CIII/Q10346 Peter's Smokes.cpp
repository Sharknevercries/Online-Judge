/* 8867310 10346 Peter's Smokes Accepted C++ 0.012 2011-05-20 14:13:45 */
#include<stdio.h>
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		unsigned long long sum,own;
		sum=n;
		own=n; // ¾Ö¦³µÒ§¾ªÑ
		while(own>=k){
			sum+=own/k;
			own=own/k+own%k;
		}
		printf("%llu\n",sum);
	}
	return 0;
}
/*

Peter has n cigarettes. He smokes them one by one keeping all the butts. Out of k > 1 butts he can roll a new cigarette. 

How many cigarettes can Peter have? 

Input

Input is a sequence of lines. Each line contains two integer numbers giving the values of n and k. The input is terminated by end of file.

Output

For each line of input, output one integer number on a separate line giving the maximum number of cigarettes that Peter can have. 

Sample Input

4 3
10 
3
100 5

Sample Output

514124

--------------------------------------------------------------------------------

Source: University of Alberta Local Contest

*/