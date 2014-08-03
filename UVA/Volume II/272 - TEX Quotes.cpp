/*8382415	272	TEX Quotes	Accepted	C++	0.008	2010-11-08 11:45:57*/
#include<stdio.h>

int main(){
	char m[500];
	int flag=0;
	while(fgets(m,500,stdin)!=NULL){		
		for(int i=0;m[i]!='\0';i++)
			if(m[i]=='"')
				if(flag==0){
					printf("``");
					flag=1;}
				else{
					printf("''");
					flag=0;}
			else
				printf("%c",m[i]);				
	}
	return 0;
}