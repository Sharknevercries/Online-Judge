/* 4875809	 Oct 25, 2013 12:44:17 PM	Shark	 216B - Forming Teams	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
#define WHITE 0
#define BLACK 1
#define RED 2
#define DEL 3
bool M[101][101]={false};
int C[101]={WHITE};
int ans;
void DFS(int s,int color,int n){
	bool OK=true;
	for(int i=1;i<=n;i++)
		if( M[s][i]&&C[i]==color )
			OK=false;
	if( OK ){
		C[s]=color;
		for(int i=1;i<=n;i++)
			if( M[s][i]&&C[i]==WHITE )
				DFS(i,color==BLACK?RED:BLACK,n);
	}
	else
		ans++,C[s]=DEL;
}
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		memset(C,0,sizeof(C));
		memset(M,false,sizeof(M));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			M[a][b]=M[b][a]=true;
		}

		ans=0;
		for(int i=1;i<=n;i++)
			if( C[i]==WHITE )
				DFS(i,BLACK,n);
		if( (n-ans)%2==0 )
			printf("%d\n",ans);
		else
			printf("%d\n",ans+1);
	}
	return 0;
}
/*

B. Forming Teams
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day n students come to the stadium. They want to play football, and for that they need to split into teams, the teams must have an equal number of people.

We know that this group of people has archenemies. Each student has at most two archenemies. Besides, if student A is an archenemy to student B, then student B is an archenemy to student A.

The students want to split so as no two archenemies were in one team. If splitting in the required manner is impossible, some students will have to sit on the bench.

Determine the minimum number of students you will have to send to the bench in order to form the two teams in the described manner and begin the game at last.

Input
The first line contains two integers n and m (2 ≤ n ≤ 100, 1 ≤ m ≤ 100) — the number of students and the number of pairs of archenemies correspondingly.

Next m lines describe enmity between students. Each enmity is described as two numbers ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — the indexes of the students who are enemies to each other. Each enmity occurs in the list exactly once. It is guaranteed that each student has no more than two archenemies.

You can consider the students indexed in some manner with distinct integers from 1 to n.

Output
Print a single integer — the minimum number of students you will have to send to the bench in order to start the game.

Sample test(s)
input
5 4
1 2
2 4
5 3
1 4
output
1
input
6 2
1 4
3 4
output
0
input
6 6
1 2
2 3
3 1
4 5
5 6
6 4
output
2

*/