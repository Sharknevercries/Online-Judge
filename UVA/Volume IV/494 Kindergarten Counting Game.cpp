/*494 Kindergarten Counting Game Accepted C++ 0.008 2010-12-14 14:34:53 */
#include<stdio.h>
int main(){	
	char str[1000];
	int flag,count,i;
	while(gets(str)){
		for(i=0,count=0,flag=0;str[i]!='\0';i++)
			if((('A'<=str[i]&&str[i]<='Z')||('a'<=str[i]&&str[i]<='z'))){
				if(flag==0)
					count++;
				flag=1;				
			}
			else
				flag=0;
		printf("%d\n",count);
	}
	return 0;
}
/*
算一算每行有幾個字（word）。
Word的定義是連續的字元（letter: A~Z a~z）所組成的字。

Input

測試資料每筆一行，每行至少有一個字。

Output

輸出每一行的word數。

Sample input

Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...
Sample Output

2
7
10
9
*/