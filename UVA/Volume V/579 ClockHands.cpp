/* 579 ClockHands Accepted C++ 0.036 2010-12-15 14:34:52 */
#include<stdio.h>
int main(){		
	while(1){
	double h=0,m=0;
	char s[10];
	gets(s);
	int flag=0;	
	for(int i=0;s[i]!='\0';i++)
		if(s[i]==':'){
			flag=1;
			continue;}
		else if(flag==0)
			h=h*10+(s[i]-'0');
		else
			m=m*10+(s[i]-'0');
	if(h==0&&m==0)
		break;
	h=h*30+m/2;
	m=6*m;
	double result;
	if(m>h)
		result=m-h;
	else
		result=h-m;	
	if(result>180)
		result=360-result;
	printf("%.3f\n",result);  		
	}
	
	return 0;
}