/* 4811626	 Oct 17, 2013 10:06:30 AM	Shark	 357A - Group of Students	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
int main(){
	int m;
	while( scanf("%d",&m)==1 ){
		int S[100];
		int x,y,ans,count,amount;
		bool found=false;
		amount=0;
		for(int i=0;i<m;i++){
			scanf("%d",&S[i]);
			amount+=S[i];
		}
		scanf("%d%d",&x,&y);
		
		ans=count=0;
		for(ans=0;ans<m;ans++){
			count+=S[ans];
			if( count>=x&&count<=y&&amount-count>=x&&amount-count<=y ){
				printf("%d\n",ans+2);
				found=true;
				break;
			}
		}
		if( !found )
			printf("%d\n",0);

	}
	return 0;
}
/*

A. Group of Students
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
At the beginning of the school year Berland State University starts two city school programming groups, for beginners and for intermediate coders. The children were tested in order to sort them into groups. According to the results, each student got some score from 1 to m points. We know that c1 schoolchildren got 1 point, c2 children got 2 points, ..., cm children got m points. Now you need to set the passing rate k (integer from 1 to m): all schoolchildren who got less than k points go to the beginner group and those who get at strictly least k points go to the intermediate group. We know that if the size of a group is more than y, then the university won't find a room for them. We also know that if a group has less than x schoolchildren, then it is too small and there's no point in having classes with it. So, you need to split all schoolchildren into two groups so that the size of each group was from x to y, inclusive.

Help the university pick the passing rate in a way that meets these requirements.

Input
The first line contains integer m (2 ≤ m ≤ 100). The second line contains m integers c1, c2, ..., cm, separated by single spaces (0 ≤ ci ≤ 100). The third line contains two space-separated integers x and y (1 ≤ x ≤ y ≤ 10000). At least one ci is greater than 0.

Output
If it is impossible to pick a passing rate in a way that makes the size of each resulting groups at least x and at most y, print 0. Otherwise, print an integer from 1 to m — the passing rate you'd like to suggest. If there are multiple possible answers, print any of them.

Sample test(s)
input
5
3 4 3 2 1
6 8
output
3
input
5
0 3 3 4 2
3 10
output
4
input
2
2 5
3 6
output
0
Note
In the first sample the beginner group has 7 students, the intermediate group has 6 of them.

In the second sample another correct answer is 3.

*/