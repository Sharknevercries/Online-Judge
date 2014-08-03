#include<stdio.h>
int m[1048576];
int main(){
	int t;
	while(scanf("%d",&t)==1){		
		while(t--){
			int d,r;
			int i,j,k;			
			m[1]=1;
			scanf("%d%d",&d,&r);
			for(i=j=1;i<d;i++,j*=2){
				for(k=1;k<=j;k++)
					m[k]*=2;
				for(;k<=j*2;k++)
					m[k]=m[k-j]+1;}
			if(r>j)
				r=r%j+1;			
			printf("%d\n",m[r]);
		}		
	}	
	return 0;
}