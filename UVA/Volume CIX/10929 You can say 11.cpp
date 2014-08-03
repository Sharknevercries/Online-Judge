/* 10929 You can say 11 Accepted C++ 0.024 2011-01-31 05:18:06 */
#include<stdio.h>
#include<string.h>
int main(){
	char str[10000];
	bool even;
	while(gets(str)){
		if(strcmp(str,"0")==0)
			break;
		int i;
		int len=strlen(str);
		int even_count,odd_count;
		for(i=len-1,even=true,even_count=odd_count=0;i>=0;i--,even=!even)
			if(even)
				even_count+=str[i]-'0';
			else
				odd_count+=str[i]-'0';
		if((even_count-odd_count)%11==0)
			printf("%s is a multiple of 11.\n",str);
		else
			printf("%s is not a multiple of 11.\n",str);
	}
	return 0;
}
/*

你的任務是，給你一個正整數 N，判定它是否是 11 的倍數。

Input

每列資料有一個正整數N，N 最大可能到 1000 位數。

若 N = 0 代表輸入結束。

Output

對每個輸入的數，輸出是否為 11 的倍數。輸出格式請參考 Sample Output。

Sample Input  
112233
30800
2937
323455693
5038297
112234
0

Sample Output

112233 is a multiple of 11.
30800 is a multiple of 11.
2937 is a multiple of 11.
323455693 is a multiple of 11.
5038297 is a multiple of 11.
112234 is not a multiple of 11.

*/