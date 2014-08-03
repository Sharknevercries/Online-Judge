/* 727 Equation Accepted C++ 0.036 2011-02-22 15:30:30 */
#include<stdio.h>
static char stack[1000000];
static int index;
void initial(){
	stack[0]='\0';
	index=1;
}
void push(char c){
	stack[index++]=c;
}
char top(){
	return stack[index-1];
}
char pop(){
	return stack[--index];
}
int priority(char c){
	switch(c){
	case '\0':
		return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		(void)getchar(); // 測資量的換行
		(void)getchar(); // 運算子之前的換行
		while(n--){
			char c;	
			while(c=getchar()){
				if(c=='\n'||c==EOF)
					break;
				if(c>='0'&&c<='9')
					printf("%c",c);
				else if(c=='(')
					push(c);
				else if(c==')'){
					while(stack[index-1]!='(')
						printf("%c",pop());
					(void) pop();}
				else{
					while(top()!='\0'&&priority(top())>=priority(c))
						printf("%c",pop());
					push(c);}
				c=getchar();}
			while(top()!='\0')
				printf("%c",pop());
			putchar('\n');
			if(n>0)
				putchar('\n');
		}
	}
	return 0;
}
/*

 輸入與輸出 Input and Output
根據下列的規定寫一個程式將中置運算式改成後置運算式。

1. 輸入的中置運算式每行一個字元，最多50行。例如，(3+2)*5 將以下列形式出現：
 
(
3
+
2
)
*
5
2. 輸入檔第一行會有一個數字表示測試資料的筆數。接下來會有好幾個運算式，每個運算式之前會有一個空行。 

3. 本程式僅處理 +, -, *, / 等二元運算子。

4. 運算元為一位數數字。

5. * 和 / 運算子優先順序最高。+ 和 – 運算子則為最低。相同優先順序的運算子則由左至右運算。括號則是用來改變優先順序的群組符號。 

6. 每個後置運算式輸出成一行。每個運算式之間要有一個空行。 

7. 每筆測試資料均為合法的運算式。

範例輸入
 
1
 
(
3
+
2
)
*
5

範例輸出
 
32+5*

--------------------------------------------------------------------------------

Miguel Revilla 
2000-08-31 
郭兆平譯 
2007-05-25 

 */