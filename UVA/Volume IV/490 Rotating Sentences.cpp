/* 490 Rotating Sentences Accepted C++ 0.016 2011-02-16 12:35:25 */
#include<stdio.h>
int check(bool eof[],int max){
	int i;
	for(i=0;i<max&&eof[i];i++);
	if(i>=max)
		return false;
	else
		return true;
}
int main(){
	char str[100][101];
	bool eof[100]={false};
	int i,j,max;
	i=0;
	while(gets(str[i++]));
	max=i-1;
	for(i=0;check(eof,max)==1;i++){
		for(j=max-1;j>=0;j--){			
			if(eof[j])
				putchar(' ');
			else
				printf("%c",str[j][i]);
			if(str[j][i+1]=='\0')
				eof[j]=true;}
		putchar('\n');}
	return 0;
}
/*

在這個問題中你必須將數列文字往順時針方向旋轉90度。也就是說將原本由左到右，由上到下的句子輸出成由上到下，由右到左。

Input and Output

輸入最多不會超過100列，每列最多不會超過100個字元。
合法的字元包括：換行，空白，所有的標點符號，數字，以及大小寫字母。（注意：Tabs並不算是合法字元。）

最後一列輸入必須垂直輸出在最左邊一行，輸入的第一列必須垂直輸出在最右邊一行。

請參考sample intput/output。

Sample Input

Rene Decartes once said,"I think, therefore I am."

Sample Output

"RIe nteh iDnekc,a rttheesr eofnocree  sIa iadm,. "

*/