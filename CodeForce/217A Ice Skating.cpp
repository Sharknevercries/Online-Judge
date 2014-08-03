/* 5021917	 Nov 7, 2013 2:33:23 PM	Shark	 A - Ice Skating	 GNU C++	Accepted	62 ms	 */
#include<stdio.h>
struct point{
	int x,y;
};
void search(int start,struct point P[],bool visited[],int n){
	for(int i=0;i<n;i++)
		if( !visited[i]&&(P[i].x==P[start].x||P[i].y==P[start].y) )
			visited[i]=true,search(i,P,visited,n);
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int ans;
		struct point P[100];
		bool visited[100]={false};
		for(int i=0;i<n;i++)
			scanf("%d%d",&P[i].x,&P[i].y);

		ans=0;
		for(int i=0;i<n;i++){
			if( !visited[i] )
				ans++;
			visited[i]=true;
			search(i,P,visited,n);
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
/*

A. Ice Skating
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bajtek is learning to skate on ice. He's a beginner, so his only mode of transportation is pushing off from a snow drift to the north, east, south or west and sliding until he lands in another snow drift. He has noticed that in this way it's impossible to get from some snow drifts to some other by any sequence of moves. He now wants to heap up some additional snow drifts, so that he can get from any snow drift to any other one. He asked you to find the minimal number of snow drifts that need to be created.

We assume that Bajtek can only heap up snow drifts at integer coordinates.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 100) — the number of snow drifts. Each of the following n lines contains two integers xi and yi (1 ≤ xi, yi ≤ 1000) — the coordinates of the i-th snow drift.

Note that the north direction coinсides with the direction of Oy axis, so the east direction coinсides with the direction of the Ox axis. All snow drift's locations are distinct.

Output
Output the minimal number of snow drifts that need to be created in order for Bajtek to be able to reach any snow drift from any other one.

Sample test(s)
input
2
2 1
1 2
output
1
input
2
2 1
4 1
output
0

*/