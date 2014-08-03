/* 10035 Primary Arithmetic Accepted C++ 0.020 2011-01-05 14:52:10 */
#include<stdio.h>
#include<string.h>
int main(){
	char str1[20],str2[20];
	while(scanf("%s%s",str1,str2)==2&&(str1[0]!='0'||str2[0]!='0')){
		int len1,len2,count;
		int i,j,k,carry;
		len1=strlen(str1)-1;
		len2=strlen(str2)-1;
		if(len2>len1){
			char temp[11];
			int t=len1;
			len1=len2;
			len2=t;
			strcpy(temp,str1);
			strcpy(str1,str2);
			strcpy(str2,temp);
		}
		for(carry=count=0,i=len1,j=len2;i>=0;i--,j--){	
			k=i;
			if(j>=0)
				str1[i]+=str2[j]-'0'+carry;
			else
				str1[i]+=carry;
			carry=0;
			while(str1[k]>'9'){
				count++;
				str1[k]-=10;
				carry=1;
			}
		}
		if(count==0)
			printf("No carry operation.\n");
		else if(count==1)
			printf("%d carry operation.\n",count);
		else
			printf("%d carry operations.\n",count);		
	}
	return 0;
}