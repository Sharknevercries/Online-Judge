/* 9574882 10080 Gopher II Accepted C++ 0.020 2011-12-19 13:21:47 */
#include<stdio.h>
#include<string.h>
typedef struct dot MAKE;
struct dot{
	double x,y;
};
int n,m,s,v;
MAKE xx[100],yy[100];
bool con[100][100];
int mx[100],my[100];
bool visit[100];
void initial(){
	memset(con,false,sizeof(con));
	for(int i=0;i<n;i++)
		mx[i]=-1;
	for(int i=0;i<m;i++)
		my[i]=-1;
}
bool DFS(int x){
	for(int y=0;y<m;y++)
		if(con[x][y]&&!visit[y]){
			visit[y]=true;
			if(my[y]==-1||DFS(my[y])){
				my[y]=x,mx[x]=y;
				return true;
			}
		}
	return false;
}
int main(){
	while(scanf("%d%d%d%d",&n,&m,&s,&v)==4){
		initial();		
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&xx[i].x,&xx[i].y);
		for(int i=0;i<m;i++)
			scanf("%lf%lf",&yy[i].x,&yy[i].y);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				double _x=xx[i].x-yy[j].x;
				double _y=xx[i].y-yy[j].y;
				if( _x*_x+_y*_y <= s*s*v*v )
					con[i][j]=true;
			}
		int ans=0;
		for(int i=0;i<n;i++)
			if(mx[i]==-1){
				memset(visit,false,sizeof(visit));
				if(DFS(i))
					ans++;
			}
		printf("%d\n",n-ans);
	}
	return 0;
}
/*

The gopher family, having averted the canine threat, must face a new predator. 

The are n gophers and m gopher holes, each at distinct (x, y) coordinates. A hawk arrives and if a gopher does not reach a hole in s seconds it is vulnerable to being eaten. A hole can save at most one gopher. All the gophers run at the same velocity v. The gopher family needs an escape strategy that minimizes the number of vulnerable gophers.
 
The input contains several cases. The first line of each case contains four positive integers less than 100: n, m, s, and v. The next n lines give the coordinates of the gophers; the following m lines give the coordinates of the gopher holes. All distances are in metres; all times are in seconds; all velocities are in metres per second.
 
Output consists of a single line for each case, giving the number of vulnerable gophers.
 
Sample Input

2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0
 
Output for Sample Input

1
 
*/