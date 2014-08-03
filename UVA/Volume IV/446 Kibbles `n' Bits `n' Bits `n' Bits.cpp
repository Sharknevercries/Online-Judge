/* 446 Kibbles "n" Bits "n" Bits "n" Bits Accepted C++ 0.012 2011-02-15 12:09:57 */
#include<stdio.h>
int change1(char c){
	if(c>='0'&&c<='9')
		return c-'0';
	else
		return c-'A'+10;
}
char change2(int n){
	if(n>=0&&n<=9)
		return n+'0';
	else
		return n-10+'A';
}
void two_digit(int a,char s[]){
	int i,j;
	for(i=j=1;j<=13;i<<=1,j++);
	for(j=0;i>1;i/=2,j++){
		if(i/2<=a){
			s[j]='1';
			a-=i/2;}
		else
			s[j]='0';}
	s[j]='\0';
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		char c=getchar();
		int i;
		char str[100];
		for(i=1;i<=n;i++){			
			gets(str);
			int a,b;			
			int j;
			char s1[100];
			char s2[100];
			char result[100];
			bool plus;
			for(j=a=0;str[j]!=' ';j++)
				a=a*16+change1(str[j]);
			if(str[++j]=='+')
				plus=true;
			else
				plus=false;
			for(j+=2,b=0;str[j]!='\0';j++)
				b=b*16+change1(str[j]);
			two_digit(a,s1);
			two_digit(b,s2);			
			if(plus)
				printf("%s + %s = %d\n",s1,s2,a+b);
			else
				printf("%s - %s = %d\n",s1,s2,a-b);
		}
	}
	return 0;
}
/*

一個很疲倦的程式設計師正在設計一支程式可以同時讀入兩個十六進位的數字，將它們相加或相減後以十進位表示法輸出。同時，這兩個十六進位數字的二進位表示法也必須輸出，就像下面sample output的格式一樣。

這位程式設計師很樂意自己完成這個普通的小程式，但是當他試著做基底2的轉換時，他卻突然感染了麻疹。所以如果你願意幫他完成這支小程式，他會非常地感謝你。

你可以假設以下條件總是成立：

在讀入的十六進位數字中最大不超過FFF。

執行減法運算時第二個數字永遠比第一個數小，也就是說，運算結果不會是負的。

空白字元在整個輸入檔中會以統一格式出現，也就是說每行的開頭不會有空白字元，在個數字及運算元之間會有一空白字元。（請參考sample input）
Input

這個題目的輸入來自一個由下列格式組成的檔案： 


N （代表有N個運算式要計算） 

十六進位1 (+ 或 -) 十六進位2 （第一個運算式)） 

. 

. 

. 

十六進位1 (+ 或 -) 十六進位2 （第 N 個運算式） 

Output

輸出檔必須遵守以下格式： 


二進位1 (+ 或 -) 二進位2 = 十進位 （第一個運算結果） 

. 

. 

. 

二進位1 (+ 或 -) 二進位2 = 十進位 （第 N 個運算結果 ） 

Sample Input

2
A + 3
AAA + BBB
Sample Output

0000000001010 + 0000000000011 = 13
0101010101010 + 0101110111011 = 5733

*/