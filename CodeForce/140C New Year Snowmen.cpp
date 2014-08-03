/* 4967670	 Nov 2, 2013 1:59:19 PM	Shark	 C - New Year Snowmen	 GNU C++	Accepted	 624 ms	 4200 KB */
#include<stdio.h>
#include<algorithm>
#include<map>
#define SWAP(x,y) { int tmp=x; x=y; y=tmp; }
struct data{
	int L,M,S;
};
std::map<int,int> S;
std::map<int,int>::iterator iter;
int tmp[100000];
struct data ans[40000];
bool cmp(int A,int B){
	return A>B;
}
bool check(int K){
	int ptr=0;
	for(iter=S.begin();iter!=S.end();iter++)
		if( iter->second>=K )
			for(int i=1;i<=K;i++)
				tmp[ptr++]=iter->first;
		else
			for(int i=1;i<=iter->second;i++)
				tmp[ptr++]=iter->first;
	if( ptr/3<K )
		return false;
	std::sort(tmp,tmp+ptr,cmp);
	for(int i=0;i<K;i++){
		ans[i].L=tmp[i];
		ans[i].M=tmp[i+K];
		ans[i].S=tmp[i+K+K];
	}
	return true;
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int A,L,R,M;
		S.clear();
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			S[tmp]++;
		}
		L=0,R=n/3;
		while( R>=L ){
			M=(L+R)/2;
			if( check(M) )
				A=M,L=M+1;
			else
				R=M-1;
		}
		
		printf("%d\n",A);
		for(int i=0;i<A;i++)
			printf("%d %d %d\n",ans[i].L,ans[i].M,ans[i].S);

	}
	return 0;
}
/*

C. New Year Snowmen
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
As meticulous Gerald sets the table and caring Alexander sends the postcards, Sergey makes snowmen. Each showman should consist of three snowballs: a big one, a medium one and a small one. Sergey's twins help him: they've already made n snowballs with radii equal to r1, r2, ..., rn. To make a snowman, one needs any three snowballs whose radii are pairwise different. For example, the balls with radii 1, 2 and 3 can be used to make a snowman but 2, 2, 3 or 2, 2, 2 cannot. Help Sergey and his twins to determine what maximum number of snowmen they can make from those snowballs.

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of snowballs. The next line contains n integers — the balls' radii r1, r2, ..., rn (1 ≤ ri ≤ 109). The balls' radii can coincide.

Output
Print on the first line a single number k — the maximum number of the snowmen. Next k lines should contain the snowmen's descriptions. The description of each snowman should consist of three space-separated numbers — the big ball's radius, the medium ball's radius and the small ball's radius. It is allowed to print the snowmen in any order. If there are several solutions, print any of them.

Sample test(s)
input
7
1 2 3 4 5 6 7
output
2
3 2 1
6 5 4
input
3
2 2 3
output
0

*/