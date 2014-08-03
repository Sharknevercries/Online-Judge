/* 5003444	 Nov 6, 2013 4:34:19 PM	Shark	 16B - Burglar and Matches	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
#include<algorithm>
struct match{
	int box;
	int count;
};
bool cmp(struct match A,struct match B){
	return A.count>B.count;
}
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		struct match M[20];
		unsigned long long ans=0;
		unsigned long long count=0;
		for(int i=0;i<m;i++)
			scanf("%d%d",&M[i].box,&M[i].count);
		std::sort(M,M+m,cmp);
		for(int i=0;i<m;i++)
			if( count+M[i].box<n )
				count+=M[i].box,ans+=M[i].box*M[i].count;
			else{
				ans+=(n-count)*M[i].count;
				break;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
/*

B. Burglar and Matches
time limit per test0.5 second
memory limit per test64 megabytes
inputstandard input
outputstandard output
A burglar got into a matches warehouse and wants to steal as many matches as possible. In the warehouse there are m containers, in the i-th container there are ai matchboxes, and each matchbox contains bi matches. All the matchboxes are of the same size. The burglar's rucksack can hold n matchboxes exactly. Your task is to find out the maximum amount of matches that a burglar can carry away. He has no time to rearrange matches in the matchboxes, that's why he just chooses not more than n matchboxes so that the total amount of matches in them is maximal.

Input
The first line of the input contains integer n (1 ≤ n ≤ 2·108) and integer m (1 ≤ m ≤ 20). The i + 1-th line contains a pair of numbers ai and bi (1 ≤ ai ≤ 108, 1 ≤ bi ≤ 10). All the input numbers are integer.

Output
Output the only number — answer to the problem.

Sample test(s)
input
7 3
5 10
2 5
3 6
output
62
input
3 3
1 3
2 2
3 1
output
7

*/