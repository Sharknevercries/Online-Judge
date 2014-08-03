/* 729 The Hamming Distance Problem Accepted C++ 0.024 2011-02-23 13:31:28 */
#include<stdio.h>
#define SWAP(x,y) {char temp=x; x=y; y=temp; }
int main(){
	int t;
	while(scanf("%d",&t)==1){
		while(t--){
			int i,j,count;
			int n,s;
			char m[16];
			scanf("%d%d",&n,&s);
			for(i=0;i<n;i++)
				if(i<n-s)
					m[i]='0';
				else
					m[i]='1';
			m[i]='\0';			
			while(true){
				printf("%s\n",m);
				for(i=n-1;m[i]!='1'&&i>=0;i--);
				for(j=i-1;m[j]!='0'&&j>=0;j--);
				if(i<0||j<0)
					break;
				SWAP(m[i],m[j]);
				for(i=n-1,j=j+1;i>j;i--,j++)
					SWAP(m[i],m[j]);
			}
			if(t>0)
				putchar('\n');
		}
	}
	return 0;
}