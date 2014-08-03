/* 9575065 670 The dog task Accepted C++ 0.012 2011-12-19 14:26:20 */
#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct dot MAKE;
struct dot{
	int x,y;
};
MAKE xx[201],yy[201];
bool con[200][200];
bool visit[200];
int mx[200],my[200];
int n,m;
void initial(){
	memset(con,false,sizeof(con));
	for(int i=0;i<n-1;i++) // n-1 line
		mx[i]=-1;
	for(int i=0;i<m;i++)
		my[i]=-1;
}
double DIST(MAKE a,MAKE b){
	return sqrt((double) (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
bool DFS(int x){
	for(int y=0;y<m;y++)
		if(!visit[y]&&con[x][y]){
			visit[y]=true;
			if(my[y]==-1||DFS(my[y])){
				my[y]=x,mx[x]=y;
				return true;
			}
		}
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int s=1;s<=t;s++){	
		if(s!=1)
			putchar('\n');
		scanf("%d%d",&n,&m);
		initial();
		for(int i=0;i<n;i++)
			scanf("%d%d",&xx[i].x,&xx[i].y);
		for(int i=0;i<m;i++)
			scanf("%d%d",&yy[i].x,&yy[i].y);
		for(int i=0;i<n-1;i++){
			double dist1=DIST(xx[i],xx[i+1])*2;
			for(int j=0;j<m;j++){				
				double dist2=(DIST(xx[i],yy[j])+DIST(xx[i+1],yy[j]));
				if(dist2<=dist1)
					con[i][j]=true;
			}
		}
		int ans=0;
		for(int i=0;i<n-1;i++)
			if(mx[i]==-1){
				memset(visit,false,sizeof(visit));
				if(DFS(i))
					ans++;
			}
		printf("%d\n",ans+n);
		printf("%d %d",xx[0].x,xx[0].y);
		for(int i=1;i<n;i++){
			if(mx[i-1]!=-1)
				printf(" %d %d",yy[mx[i-1]].x,yy[mx[i-1]].y);
			printf(" %d %d",xx[i].x,xx[i].y);
		}
		putchar('\n');
	}
	return 0;
}
/*

Hunter Bob often walks with his dog Ralph. Bob walks with a constant speed and his route is a polygonal line (possibly self- intersecting) whose vertices are specified by N pairs of integers (Xi, Yi) - their Cartesian coordinates.
 
Ralph walks on his own way but always meets his master at the specified N points. The dog starts his journey simultaneously with Bob at the point (X1, Y1) and finishes it also simultaneously with Bob at the point (XN , YN).
 
Ralph can travel at a speed that is up to two times greater than his master's speed. While Bob travels in a straight line from one point to another the cheerful dog seeks trees, bushes, hummocks and all other kinds of interesting places of the local landscape which are specified by M pairs of integers (X'j,Y'j). However, after leaving his master at the point (Xi , Yi) (where ) the dog visits at most one interesting place before meeting his master again at the point ( Xi+1 , Yi+1).
 
Your task is to find the dog's route, which meets the above requirements and allows him to visit the maximal possible number of interesting places. The answer should be presented as a polygonal line that represents Ralph's route. The vertices of this route should be all points (Xi , Yi) and the maximal number of interesting places ( X'j, Y'jX). The latter should be visited (i.e. listed in the route description) at most once.
 
An example of Bob's route (solid line), a set of interesting places (dots) and one of the best Ralph's routes (dotted line) are presented in the following picture:
 
Input 

The first line of the input is an integer L, then a blank line followed by L datasets. There is a blank line between datasets.
 The first line of each dataset contains two integers N and M, separated by a space ( ). The second line contains N pairs of integers , separated by spaces, that represent Bob's route. The third line contains M pairs of integers , separated by spaces, that represent interesting places.
 
All points in the input file are different and their coordinates are integers not greater than 1000 by the absolute value.
 
Output  

The first line of each dataset should contain the single integer K - the number of vertices of the best dog's route. The second line should contain K pairs of coordinates , separated by spaces, that represent this route. If there are several such routes, then you may write any of them.
 Print a blank line between datasets. 
 
Sample Input  

1

4 5
1 4 5 7 5 2 -2 4
-4 -2 3 9 1 2 -1 3 8 -3

 Sample Output 

6
1 4 3 9 5 7 5 2 1 2 -2 4

--------------------------------------------------------------------------------

Miguel Revilla 
2000-05-22 

*/