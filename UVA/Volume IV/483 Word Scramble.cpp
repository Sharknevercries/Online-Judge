/* 483 Word Scramble Accepted C++ 0.012 2011-02-16 11:58:01 */
#include<stdio.h>
#define SWAP(x,y) { char temp=x; x=y; y=temp; }
int main(){
	char str[100000];
	while(gets(str)){
		int i,j,k;		
		for(i=0;str[i]!='\0';i++){
			if(str[i]==' ')				
				continue;
			for(j=i+1;str[j]!=' '&&str[j]!='\0';j++);
			k=(--j);
			for(;j>i;i++,j--)
				SWAP(str[i],str[j]);
			i=k;
		}
		printf("%s\n",str);
	}
	return 0;
}
/*

寫一支程式可以將每一個單字按照每個字母出現的順序反序排列。

Input

輸入檔包含數列，每列各有數個單字。單字與單字間由空白字元分隔開來。

Output

輸出的列數與字數必須與輸入一樣。但是每個單字中的字母必須反序排列。

Sample Input

I love you.
You love me.
We're a happy family.

Sample Output

I evol .uoy
uoY evol .em
er'eW a yppah .ylimaf

*/