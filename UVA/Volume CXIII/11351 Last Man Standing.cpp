/* 9061105 11351 Last Man Standing Accepted C++ 0.056 2011-07-19 11:08:09 */
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,k;
		scanf("%d%d",&n,&k);
		int DP[100001];
		DP[1]=0; // http://blog.pchome.com.tw/iustlovefish/forward/1312684306
		for(int j=2;j<=n;j++) // f(n¡Ak) = (f(n-1¡Ak) + k) % n¡Af(1¡Ak) = 0
			DP[j]=(DP[j-1]+k)%j;
		printf("Case %d: %d\n",i,DP[n]+1);
	}
	return 0;
}
/*

There are n people standing in a circle waiting to be executed. Starting from the first man, k - 1 people are skipped and the k-th man is executed. Then again, k - 1 people are skipped and the k-th man is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last man remains.

You are given number of people standing in the circle, and number k. You must find the number of last man, who standing in the circle.

INPUT:

The first line contains integer k (0 < k <= 100), it is the number of tests. On each of next k lines there are 2 integers n (0 < n <= 105) and k (0 < k <= 109).

OUTPUT:

For each test case out line formatter like this: "Case i: a". Where "i" is a test number, and "a" is the last man standing in the circle (see examples).

SAMPLE INPUT:

4
6 3
8 6
11 99
23 13

SAMPLE OUTPUT:

Case 1: 1
Case 2: 1
Case 3: 5
Case 4: 12

Problem setters: Aleksej Viktorchik, Leonid Shishlo.
Huge Easy Contest #1

*/