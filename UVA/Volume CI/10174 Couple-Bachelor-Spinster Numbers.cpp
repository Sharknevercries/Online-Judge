#include<stdio.h>
int main(){
	char str[100];
	while(gets(str)){
		long long int n;
		int i;
		sscanf(str,"%lld",&n);
		for(i=0;str[i]!=' '&&str[i]!='\0';i++);		
		long long int a,b;
		long long int result[2]={0};
		if(str[i]=='\0'){
			bool negative=false;
			if(n<0)
				negative=true;
			if(negative)
				n*=-1;
			if(n%4==2)
				puts("Bachelor Number.");
			else{
				if(n%4==0)
					a=n/4+1,b=n/4-1;
				else
					a=(n-1)/2+1,b=(n-1)/2;
				if(negative)
					printf("%lld %lld\n",b,a);
				else
					printf("%lld %lld\n",a,b);
			}			
		}
		else{
			long long m;
			sscanf(str+i,"%lld",&m);	
			for(i=0;(n+i)%4!=2&&(n+i)%4!=-2;i++);	n+=i;
			for(i=0;(m-i)%4!=2&&(m-i)%4!=-2;i++); 	m-=i;
			printf("%lld\n",(m-n)>0?(m-n)/4+1:(n-m)/4+1);
		}
	}
	return 0;
}