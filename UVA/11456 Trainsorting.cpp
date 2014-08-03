/* 12413601	11456	Trainsorting	Accepted	C++	0.022	2013-09-28 13:29:52 */
// http://blog.csdn.net/shuangde800/article/details/11271011
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
int main(){
	int t;
	scanf("%d",&t);
	for(int T=0;T<t;T++){
		int n;
		int max=0;
		int S[2000];
		std::vector<int > LIS,LDS;
		std::vector<int>::iterator Q;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&S[i]);

		for(int i=n-1;i>=0;i--){ // 找出各位置開頭的LIS,LDS長度
			int len1,len2;
			
			Q=std::lower_bound(LDS.begin(),LDS.end(),S[i]);
			if( Q==LDS.end() )
				LDS.push_back(S[i]),len2=LDS.size();
			else
				*Q=S[i],len2=Q-LDS.begin()+1;

			Q=std::lower_bound(LIS.begin(),LIS.end(),-S[i]);
			if(  Q==LIS.end() )
				LIS.push_back(-S[i]),len1=LIS.size();
			else
				*Q=-S[i],len1=Q-LIS.begin()+1;
			max=MAX(max,len1+len2-1);
		}
		
		printf("%d\n",max);
	}
	return 0;
}
/*

Problem A: Trainsorting

Erin is an engineer. She drives trains. She also arranges the cars within each train. She prefers to put the cars in decreasing order of weight, with the heaviest car at the front of the train.
Unfortunately, sorting train cars is not easy. One cannot simply pick up a car and place it somewhere else. It is impractical to insert a car within an existing train. A car may only be added to the beginning and end of the train.

Cars arrive at the train station in a predetermined order. When each car arrives, Erin can add it to the beginning or end of her train, or refuse to add it at all. The resulting train should be as long as possible, but the cars within it must be ordered by weight.

Given the weights of the cars in the order in which they arrive, what is the longest train that Erin can make?

Input Specification

The first line is the number of test cases to follow. The test cases follow, one after another; the format of each test case is the following:
The first line contains an integer 0 <= n <= 2000, the number of cars. Each of the following n lines contains a non-negative integer giving the weight of a car. No two cars have the same weight.

Sample Input

1
3
1
2
3
Output Specification

Output a single integer giving the number of cars in the longest train that can be made with the given restrictions.
Output for Sample Input

3
Ondřej Lhoták

*/