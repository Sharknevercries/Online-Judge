/* 9343587 481 What Goes Up Accepted C++ 1.016 2011-10-07 12:27:53 */
#include<stdio.h>
int m[100000];
int LIS[100000];
int p[100000]; 
int s[100000]; // 記錄LIS[i]的值在m[]的足碼
int result[100000];

int main(){
	
	int i,j,ptr,count;
	int n;

	count=ptr=0;	
	while(scanf("%d",&n)==1){
		for(j=0;j<ptr;j++) // 判斷此n是否可以延長LIS
			if(LIS[j]>=n)
				break;
		if(j>=ptr){ // 可以接在目前LIS的最後面
			p[count]=ptr;
			s[ptr]=count;
			LIS[ptr++]=n;				
		}
		else{
			for(i=count-1;i>=0;i--)
				if(m[i]==LIS[j])
					break;
			LIS[j]=n;
			p[count]=p[s[j]];	
			s[j]=count;								
		}
		m[count++]=n;
	}
	printf("%d\n",ptr);
	puts("-");
	for(i=ptr-1,j=count-1;i>=0;i--){
		while(p[j]!=i)
			j--;
		result[i]=m[j];
	}
	for(i=0;i<ptr;i++)
		printf("%d\n",result[i]);
	return 0;
}