#include<stdio.h>
#include<string.h>
#include<queue>
#define MAX 300
int C[MAX][MAX],F[MAX][MAX],R[MAX][MAX]; // 0 Source 1~m own_stickers
int flow[MAX]; // m+1~m+n-1 another m+n~m+n+m*n-1 another_stickers
//m+n  ~m+n+n-1
//m+n+n~m+n+n+n-1
int path[MAX]; // n+m+m Sink 
bool visit[MAX];
int n,m;
/*
m*(n-1)
每個其他人 -> 每種火柴    容量是那個人擁有的那種火柴數量-1  當那個人有那種火柴且(>2隻)
每種火柴 -> 匯點   容量是1

然後最大流過去ˊˇˋ

*/
int BFS(int s,int t){
	memset(visit,false,sizeof(visit));
	std::queue<int> Q;
	visit[s]=true;
	flow[s]=2e9;
	path[s]=s;
	Q.push(s);
	while(!Q.empty()){
		int i=Q.front(); Q.pop();
		for(int j=0;j<=n+m+m;j++)
			if(!visit[j]&&R[i][j]>0){
				if( flow[i]>R[i][j] )
					flow[j]=R[i][j];
				else
					flow[j]=flow[i];
				visit[j]=true;
				path[j]=i;
				if(j==t)
					return flow[t];
				Q.push(j);
			}
	}
	return 0;
}
int Edmonds_Karp(int s,int t){
	memset(F,0,sizeof(F));
	memcpy(R,C,sizeof(C));
	int max_f,f;
	for(max_f=0;f=BFS(s,t);max_f+=f)
		for(int i=path[t],j=t;i!=j;j=i,i=path[i]){
			F[i][j]+=f;
			F[j][i]-=F[i][j];
			R[i][j]=C[i][j]-F[i][j];
			R[j][i]=C[j][i]-F[j][i];
		}
	return max_f;
}
int main(){	
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(C,0,sizeof(C));
		scanf("%d%d",&n,&m);

		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){ // Source to Own_stickers
			int a;
			scanf("%d",&a);
			C[0][a]++;
		}
		for(int j=0;j<n-1;j++){ // another to another_stickers
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				int a;
				scanf("%d",&a);
				C[m+1+j][n+m+m*j+a-1]++;
			}
		}
		for(int j=0;j<m;j++) // Own_stickers to another
			for(int k=0;k<n-1;k++)
				if(C[m+1+k][n+m+m*j+k]==0&&C[0][j]>0)
					C[j+1][m+1+k]=1;
		for(int j=0;j<m;j++)
			C[m+n+j][m+m+n]=1;
		int ans=Edmonds_Karp(0,m+m+n);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}