/* 127 "Accordian" Patience Accepted C++ 0.300 2011-02-09 09:02:41 */
#include<stdio.h>
#define COPY(x,y) { x=y; }
struct card{
	char flower;
	char point;
};
static struct card table[52][52];
static int top[52]; // table 的某一疊之最上層
void initial(char str1[],char str2[]){ // 將輸入轉換成 table 上的原始狀態
	int i,j;
	for(i=j=0;str1[i]!='\0'&&j<26;i++,j++){
		if(str1[i]==' ') i++;
		table[j][0].point=str1[i++];
		table[j][0].flower=str1[i++];		
		top[j]=0;}
	for(i=0;str2[i]!='\0'&&j<52;i++,j++){
		if(str2[i]==' ') i++;
		table[j][0].point=str2[i++];
		table[j][0].flower=str2[i++];		
		top[j]=0;}
}
void copy(struct card *x,struct card *y){
	(*x).flower=(*y).flower;
	(*x).point=(*y).point;
}
void move(int n,int *quantity){
	int i,j;
	for(i=n;i+1<*quantity;i++){
		for(j=0;j<=top[i+1];j++)
			copy(&table[i][j],&table[i+1][j]);
		top[i]=top[i+1];
	}
	(*quantity)--;
}

int main(){
	char str1[100];
	char str2[100];
	int result[52];
	int count=0;
	int index=0;
	while(gets(str1)){		
		if(str1[0]=='#') break;
		gets(str2);
		int i,j;
		int quantity;
		initial(str1,str2);
		for(i=1,quantity=52;i<quantity;){			
			if((j=i-3)>=0&&(table[i][top[i]].flower==table[j][top[j]].flower||table[i][top[i]].point==table[j][top[j]].point)){
				copy(&table[j][++top[j]],&table[i][top[i]--]);
				if(top[i]==-1) move(i,&quantity); // 該疊牌已空 左移
				i=j;}
			else if((j=i-1)>=0&&(table[i][top[i]].flower==table[j][top[j]].flower||table[i][top[i]].point==table[j][top[j]].point)){				
				copy(&table[j][++top[j]],&table[i][top[i]--]);
				if(top[i]==-1) move(i,&quantity);
				i=j;}
			else i++;}
		for(j=0;j<quantity;j++)
			result[index++]=top[j]+1;	
		if(index==1)
			printf("%d pile remaining:",index);
		else
			printf("%d piles remaining:",index);
		for(i=0;i<index;i++)
			printf(" %d",result[i]);
		putchar('\n');
		index=0; // 重置 index			
		
	}
	return 0;
}
/*

你的任務是模擬一種叫「Accordian」的紙牌遊戲，他的遊戲規則如下：

一副撲克牌有52張牌，首先把紙牌一張一張由左到右排好（不能有重疊，所以共有52堆牌，每堆一張），當某一張牌與他左邊那張牌或者左邊的第三張牌有「Match」的時候，就把這張牌移到那張牌上面去。在這裡兩張牌「Match」指的是這兩張牌的花色（suit）或者點數（rank）一樣。當你做了一個移動之後，要察看是否還可以做其他的移動。在任何時間，只有最上面那張牌可以被移動。如果因為移動一張牌使得產生一個空格（也就是被移動的那堆牌只有一張牌），你必須把右邊所有的牌堆往左移一格。如此不斷的尋找可移動的牌，直到沒有一張牌可以移動遊戲就結束了。

在選擇可以移動的牌的時候可能有些狀況會發生。如果有兩張牌都可以移動，你應該要移動最左邊的那張牌。當一張牌可以被移動到左邊一格，或左邊三格的時候，你必須移動到左邊三格。

Input

輸入包含多組測試資料。每組測試資料兩列，每列有26張牌的資料。每張牌以2個字元代表。第一個字元代表牌的點數（A=Ace, 2~9, T=10, J=Jack, Q=Queen, K=King），第二個字元代表牌的花色（C=Clubs, D=Diamonds, H=Hearts, S=Spades）

若遇到僅含#的一列代表輸入結束。請參考Sample Input。

Output

對每組測試資料輸出遊戲結束時剩下幾堆牌，以及每堆牌有多少張牌。請注意如果只有1堆牌，pile後沒有加s，請參考Sample Output。

Sample input

QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S
8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C
AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AD 2D 3D 4D 5D 6D 7D 8D TD 9D JD QD KD
AH 2H 3H 4H 5H 6H 7H 8H 9H KH 6S QH TH AS 2S 3S 4S 5S JH 7S 8S 9S TS JS QS KS
#

Sample Output

6 piles remaining: 40 8 1 1 1 1
1 pile remaining: 52

*/