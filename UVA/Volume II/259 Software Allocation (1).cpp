#include<stdio.h>
#include<string.h>
typedef struct com MAKE;
struct com{
	char alpha;
	int cost;
};
MAKE Com[20];
bool work[30][30];
int C[30];
char ans[30];
int sum;
int n;
bool DFS(int K,int count){	
	if(count==sum){
		for(int i=0;i<10;i++)
			putchar(ans[i]);
		putchar('\n');
		return true;
	}
	if(K>=10)
		return false;
	for(int i=0;i<n;i++)
		if( work[i][K] && C[i]!=Com[i].cost ){
			C[i]++;
			ans[K]=Com[i].alpha;
			if( DFS(K+1,count+1) )
				return true;
			ans[K]='_';
			C[i]--;
		}
	if( DFS(K+1,count) )
		return true;
	return false;
}
void initial(){
	for(int i=0;i<=10;i++)
		ans[i]='_';
	ans[11]='\0';
	memset(work,false,sizeof(work));
	memset(C,0,sizeof(C));
}
int main(){
	char str[100];
	n=0;
	initial();
	while(gets(str)){
		if(str[0]!='\0'){
			Com[n].alpha=str[0];
			Com[n].cost=str[1]-'0';			
			for(int i=3;str[i]!=';';i++)
				work[n][str[i]-'0']=true;
			n++;
		}
		else{			
			for(int i=0;i<n;i++)
				sum+=Com[i].cost;
			if(sum>10 || !DFS(0,0))
				puts("!");			
			n=0;
			initial();
		}
	}
	for(int i=0;i<n;i++)
		sum+=Com[i].cost;
	if(sum>10 || !DFS(0,0))
		puts("!");
	return 0;
}