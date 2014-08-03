/* 1128749 Jan 31, 2012 3:59:36 PM	Shark A - Theater Square GNU C++ Accepted 30 ms 1300 KB */
#include<stdio.h>
#include<string.h>
void mul(int a,int b){
	char str1[100],str2[100],str3[100];
	int len1,len2,len3;
	int carry,temp,i,j;
	sprintf(str1,"%d",a);
	sprintf(str2,"%d",b);
	len1=strlen(str1);
	len2=strlen(str2);
	len3=len1+len2;

	for(i=0;i<len3;i++)
		str3[i]='0';
	str3[i]='\0';
	for(i=len1-1;i>=0;i--){
		for(j=len2-1,carry=0;j>=0;j--){
			temp=(str1[i]-'0')*(str2[j]-'0')+carry+str3[i+j+1]-'0';
			carry=temp/10;
			str3[i+j+1]=temp%10+'0';
		}
		str3[i]+=carry;
	}
	if(str3[0]=='0')
		memmove(str3,str3+1,sizeof(char)*len3);
	printf("%s\n",str3);
}
int main(){
	int n,m,a;
	while(scanf("%d%d%d",&n,&m,&a)==3){
		if( n%a==0 && m%a==0 )
			mul((n/a),(m/a));
		else if( n%a==0 )
			mul((n/a),(m/a+1));
		else if( m%a==0 )
			mul((n/a+1),(m/a));
		else
			mul((n/a+1),(m/a+1));
	}
	return 0;
}
/*

Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

Input

The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).

Output

Write the needed number of flagstones.

Sample test(s)
input
6 6 4
output
4

*/