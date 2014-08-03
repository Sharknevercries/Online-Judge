/* 10106 Product Accepted C++ 0.016 2011-02-28 13:18:26 */
#include<stdio.h>
#include<string.h>
void multiply(char str1[],char str2[],char result[]){
	int len_1,len_2;
	int i,j,temp,carry;
	len_1=strlen(str1);
	len_2=strlen(str2);
	for(i=0;i<len_1+len_2;i++)
		result[i]='0';
	result[i]='\0';
	for(i=len_1-1;i>=0;i--){
		for(j=len_2-1,carry=0;j>=0;j--){
			temp=(str1[i]-'0')*(str2[j]-'0')+result[i+j+1]-'0'+carry;
			carry=temp/10;
			result[i+j+1]=(temp%10)+'0';
		}
		result[i]=carry+'0';
	}
	for(j=0;result[j]=='0';j++);
	if(j>=len_1+len_2)
		result[1]='\0';
	else
		for(i=0;result[i]!='\0';i++)
			result[i]=result[i+j];
}
int main(){
	char str1[100000];
	char str2[100000];
	char result[100000];
	while(gets(str1)){
		gets(str2);
		multiply(str1,str2,result);
		printf("%s\n",result);
	}
	return 0;
}
/*

The problem is to multiply two integers X, Y. (0<=X,Y<10250) 

The Input

The input will consist of a set of pairs of lines. Each line in pair contains one multiplyer. 

The Output

For each input pair of lines the output line should consist one integer the product. 

Sample Input

12
12
2
222222222222222222222222

Sample Output

144
444444444444444444444444

*/