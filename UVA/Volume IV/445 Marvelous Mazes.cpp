/* 445 Marvelous Mazes Accepted C++ 0.016 2011-02-15 11:35:14 */
#include<stdio.h>
int main(){
	char str[150];
	while(gets(str)){
		int i,j;
		int temp;
		for(i=temp=0;str[i]!='\0';i++){
			if(str[i]>='0'&&str[i]<='9')
				temp+=str[i]-'0';
			if(str[i]>='A'&&str[i]<='Z'){
				for(j=1;j<=temp;j++)
					printf("%c",str[i]);
				temp=0;}
			if(str[i]=='b'){
				for(j=1;j<=temp;j++)
					putchar(' ');
				temp=0;}
			if(str[i]=='*'){
				for(j=1;j<=temp;j++)
					putchar('*');
				temp=0;}
			if(str[i]=='!')
				putchar('\n');}
		putchar('\n');
	}
	return 0;
}
/*

本題中你的任務是寫一支可以畫迷宮的程式，這個迷宮將由Ａ－Ｚ26個字母及*（星號）和空白字元組成。

Input and Output

你的程式必須從input讀入迷宮的資訊，輸入將包含數列字元，你的程式必須依照指示畫出迷宮。迷宮的每一列都會藉由一系列的數字和字元來表達，數字代表這個字元被使用多少次。如果數字超過一位數則這個字元重複出現的次數為每一位數相加的總合。

在input中小寫的"b"代表空白字元，驚嘆號（!）以及換行都代表結束一列。

迷宮的列數並沒有限制，但是每一列不會超過132個字元。

Sample Input

1T1b5T!1T2b1T1b2T!1T1b1T2b2T!1T3b1T1b1T!3T3b1T!1T3b1T1b1T!5T1*1T
 
11X21b1X
4X1b1X
Sample Output

T TTTTT
T  T TT
T T  TT
T   T T
TTT   T
T   T T
TTTTT*T
 
XX   X
XXXX X

*/