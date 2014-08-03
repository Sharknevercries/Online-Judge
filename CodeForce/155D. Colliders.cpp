#include<stdio.h>
#include<string.h>
bool used[100001]={false};
int Q[100001];
int ptr=0;
int GCD(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
void PLUS(int a){
	if(used[a])
		puts("Already on");
	else{
		for(int i=0;i<ptr;i++)
			if(GCD(a,Q[i])!=1){
				printf("Conflict with %d\n",Q[i]);
				return ;
			}
		Q[ptr++]=a;
		used[a]=true;
		puts("Success");
	}
}
void MINUS(int a){
	if(!used[a])
		puts("Already off");
	else{
		for(int i=0;i<ptr;i++)
			if(Q[i]==a){
				memmove(&Q[i],&Q[i+1],sizeof(int)*(ptr-i-1));
				break;
			}
		ptr--;
		used[a]=false;
		puts("Success");
	}

}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		for(int i=0;i<m;i++){
			char c;	int a;
			scanf(" %c%d",&c,&a);
			if(c=='+')
				PLUS(a);
			else
				MINUS(a);
		}
	}
	return 0;
}