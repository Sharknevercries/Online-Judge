/* 9346511 10801 Lift Hopping Accepted C++ 0.008 2011-10-08 07:00:09 */
/* °Ñ¬Ý http://www.cppblog.com/syhd142/articles/126601.html */
#include<stdio.h>
#include<string.h>
#define MAX 100
int m[5][MAX];
int s[5][MAX];
int ptr[5];
bool visited[MAX][MAX];
int table[5][MAX][MAX];
int d[MAX][MAX];
int time[5];
void analyze(char str[],int pos,int num){
	int i,j,k,temp;
	ptr[num]=0;
	for(i=temp=0;str[i]!='\0';i++){
		if(str[i]>='0'&&str[i]<='9')
			temp=temp*10+str[i]-'0';
		else
			m[num][temp]=1,s[num][ptr[num]++]=temp,temp=0;
	}

	m[num][temp]=1,s[num][ptr[num]++]=temp,temp=0;
	for(i=0;i<ptr[num];i++)
		for(j=i+1;j<ptr[num];j++){
			int a=s[num][i],b=s[num][j];
			table[num][a][b]=table[num][b][a]=(b-a)*time[num];
		}
}
int dijkstra(int n,int end){ // ¤Gºûdijkstra
	int i,j,k,min,a,b,cur;
	memset(visited,false,sizeof(visited));
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			d[i][j]=1e9;
	for(k=0;k<n;k++)
		if(m[k][0])
			d[k][0]=0;
	
	while(true){
		a=b=-1,min=1e9;
		for(i=0;i<n;i++)
			for(j=0;j<MAX;j++)
				if(!visited[i][j]&&d[i][j]<min){
					min=d[i][j];
					cur=i;
					a=j;
				}
		if(a==end)
			return min;
		if(a==-1)
			return 1e9;
		visited[cur][a]=true;
		for(i=0;i<n;i++)
			for(j=0;j<MAX;j++)
				if(!visited[i][j]&&m[i][j]){
					int temp=d[cur][a]+table[i][a][j];
					if(i==cur){
						if(temp<d[i][j])
							d[i][j]=temp;
					}
					else if(a==j){
						if(temp+60<d[i][j])
							d[i][j]=temp+60;
					}
				}
	}
}
int main(){	
	int n,t;
	while(scanf("%d%d",&n,&t)==2){
		int i,j,k;
		for(k=0;k<n;k++)
			for(i=0;i<MAX;i++){
				for(j=0;j<MAX;j++)
					table[k][i][j]=1e9;
				table[k][i][i]=0;
			}
		memset(m,0,sizeof(m));
		for(i=0;i<n;i++)
			scanf("%d",&time[i]);

		(void)getchar();
		for(i=0;i<n;i++){
			char str[10000];
			gets(str);
			analyze(str,0,i);
		}

		int result=dijkstra(n,t);		
		if(result==1e9)
			puts("IMPOSSIBLE");
		else
			printf("%d\n",result);
	}
	return 0;
}
/*

A skyscraper has no more than 100 floors, numbered from 0 to 99. It has n (1<=n<=5) elevators which travel up and down at (possibly) different speeds. For each i in {1, 2,... n}, elevator number i takes Ti (1<=Ti<=100) seconds to travel between any two adjacent floors (going up or down). Elevators do not necessarily stop at every floor. What's worse, not every floor is necessarily accessible by an elevator.
 
You are on floor 0 and would like to get to floor k as quickly as possible. Assume that you do not need to wait to board the first elevator you step into and (for simplicity) the operation of switching an elevator on some floor always takes exactly a minute. Of course, both elevators have to stop at that floor. You are forbiden from using the staircase. No one else is in the elevator with you, so you don't have to stop if you don't want to. Calculate the minimum number of seconds required to get from floor 0 to floor k (passing floor k while inside an elevator that does not stop there does not count as "getting to floor k").
 
Input

The input will consist of a number of test cases. Each test case will begin with two numbers, n and k, on a line. The next line will contain the numbers T1, T2,... Tn. Finally, the next n lines will contain sorted lists of integers - the first line will list the floors visited by elevator number 1, the next one will list the floors visited by elevator number 2, etc.
 
Output 

For each test case, output one number on a line by itself - the minimum number of seconds required to get to floor k from floor 0. If it is impossible to do, print "IMPOSSIBLE" instead.
 
Sample Input 

2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
  
Sample Output 

275
285
3920
IMPOSSIBLE
 
Explanation of examples
 
In the first example, take elevator 1 to floor 13 (130 seconds), wait 60 seconds to switch to elevator 2 and ride it to floor 30 (85 seconds) for a total of 275 seconds.
 
In the second example, take elevator 1 to floor 10, switch to elevator 2 and ride it until floor 25. There, switch back to elevator 1 and get off at the 30'th floor. The total time is
 10*10 + 60 + 15*1 + 60 + 5*10 = 285 seconds. 

In example 3, take elevator 1 to floor 30, then elevator 2 to floor 20 and then elevator 3 to floor 50.
 
In the last example, the one elevator does not stop at floor 1. 

--------------------------------------------------------------------------------
Problemsetter: Igor Naverniouk
 Alternate solutions: Stefan Pochmann, Frank Pok Man Chu 

 */