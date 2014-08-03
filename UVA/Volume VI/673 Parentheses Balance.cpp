/* 673 Parentheses Balance Accepted C++ 0.032 2011-01-10 15:15:40 */
#include<stdio.h>
#define MAX 200
int top=-1;
char stack[MAX];
bool push(char c){
	if(top<MAX-1){
		if(c=='(')
			stack[++top]='(';
		else if(c=='[')
			stack[++top]='[';		
	}
	else
		return false; 
	return true;	
}
bool pop(char c){
	if(c==')')
		c='(';
	else
		c='[';	
	if(top==-1)
		return false;
	else
		if(stack[top]==c){
			stack[top--];
			return true;
		}
		else
			return false;
	
}
int main(){	
	char str[200];
	int n;
	gets(str);
	while(sscanf(str,"%d",&n)){
		for(int i=1;i<=n;i++){			
			bool YES=true;			
			gets(str);
			for(int j=0;str[j]!='\0'&&YES;j++)
				if(str[j]=='('||str[j]=='['){
					if(!push(str[j]))
						YES=false;}
				else if(str[j]==')'||str[j]==']')
					if(!pop(str[j]))
						YES=false;
			if(top!=-1)
				YES=false;
			if(YES)
				puts("Yes");
			else
				puts("No");
			top=-1;
		}
	}
	return 0;
}