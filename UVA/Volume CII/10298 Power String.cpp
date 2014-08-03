/* 8866250 10298 Power Strings Accepted C++ 0.464 2011-05-20 08:51:43 */
#include<stdio.h>
#include<string.h>
int main(){
	char str[1000001];
	while(gets(str)){
		if(str[0]=='.'&&str[1]=='\0')
			break;
		int i,j;
		int max_s;
		int str_len=strlen(str);
		int s;
		int length;		
		for(max_s=0,length=1;length<=str_len;length++)
			if(str_len%length==0){
				for(i=0,s=1,j=length;str[j]!='\0';i++,j++){
					if(i==length){	i=0; s++; }
					if(str[i]!=str[j])
						break;
				}
				if(i==length){	i=0; s++; }
				if(str[j]=='\0')
					if(s>max_s)
						max_s=s;
			}
		printf("%d\n",max_s);
	}
	return 0;
}
/*

 Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).
 Each test case is a line of input representing s, a string of printable characters. For each s you should print the largest n such that s = a^n for some string a. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.
 
Sample Input

abcd
aaaa
ababab
.
 
Output for Sample Input

1
4
3

 */