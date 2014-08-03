#include<stdio.h>
#include<string.h>
inline int min(int x,int y)	{	return ( (x) >= (y) ? (y) : (x) );	}	
int A1[1000000]={0},B1[1000000]={0};
int A2[1000]={0},B2[1000]={0};
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		memset(A1,0,sizeof(A1));
		memset(B1,0,sizeof(B1));
		memset(A2,0,sizeof(A2));
		memset(B2,0,sizeof(B2));
		int a,b;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			A1[(a-1)*1000+b-1]++;
			A2[b-1]++;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			B1[(a-1)*1000+b-1]++;
			B2[b-1]++;
		}

		int max,perfect;
		max=perfect=0;
		for(int i=0;i<1000000;i++)
			if(A1[i]>0&&B1[i]>0){
				int temp=min(A1[i],B1[i]);
				perfect+=temp,max+=temp;
				A1[i]-=temp,B1[i]-=temp;
				A2[i%1000]-=temp;
				B2[i%1000]-=temp;
			}
		for(int i=0;i<1000;i++)
			if(A2[i]>0&&B2[i])
				max+=min(A2[i],B2[i]);
		printf("%d %d\n",max,perfect);

	}
	return 0;
}