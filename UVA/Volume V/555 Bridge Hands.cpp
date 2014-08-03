/* 555 Bridge Hands Accepted C++ 0.092 2011-02-18 12:31:10 */
#include<stdio.h>
struct card{
	char patten;
	char point;
};
static struct card hand[4][13]; // [0] S [1] W [2] N [3] E 由左往右 由小變大
void initial(char str1[],char str2[],char c){
	int i,j,k,count;
	switch(c){
		case 'S': i=1; break;
		case 'W': i=2; break;
		case 'N': i=3; break;
		case 'E': i=0; break;}
	for(j=k=count=0;str1[j]!='\0';i++,count++){
		if(i==4) i=0;
		if(count==4){ k++,count=0;}
		hand[i][k].patten=str1[j++];		
		hand[i][k].point=str1[j++];}
	for(j=0;str2[j]!='\0';i++,count++){
		if(i==4) i=0;
		if(count==4) { k++,count=0; }
		hand[i][k].patten=str2[j++];
		hand[i][k].point=str2[j++];}
}
void swap(card *x,card *y){
	card temp;
	temp.patten=(*x).patten;
	temp.point=(*x).point;
	(*x).patten=(*y).patten;
	(*x).point=(*y).point;
	(*y).patten=temp.patten;
	(*y).point=temp.point;
}
int compare(card x,card y){
	if(x.patten==y.patten)
		if(x.point=='A')
			return true; 
		else if(y.point=='A')
			return false; // Do not swap.
		else if(x.point=='K')
			return true;
		else if(y.point=='K')
			return false;
		else if(x.point=='Q')
			return true;
		else if(y.point=='Q')
			return false;
		else if(x.point=='J')
			return true;
		else if(y.point=='J')
			return false;
		else if(x.point=='T')
			return true;
		else if(y.point=='T')
			return false;
		else if(x.point>y.point) // 剩下的為2~9
			return true;
		else
			return false;
	else{
		if(x.patten=='H')
			return true;
		else if(y.patten=='H')
			return false;
		else if(x.patten=='S')
			return true;
		else if(y.patten=='S')
			return false;
		else if(x.patten=='D')
			return true;
		else if(y.patten=='D')
			return false;}
}
int main(){
	char c;
	while(scanf("%c",&c)==1){
		if(c=='#') break;
		char temp=getchar();
		int i,j,k;
		char str1[100];
		char str2[100];
		gets(str1);
		gets(str2);
		initial(str1,str2,c);
		for(i=0;i<4;i++)
			for(j=0;j<13;j++)
				for(k=j+1;k<13;k++)
					if(compare(hand[i][j],hand[i][k]))
						swap(&hand[i][j],&hand[i][k]);
		for(i=0;i<4;i++){
			switch(i){ 
				case 0: printf("S:"); break;
				case 1: printf("W:"); break; 
				case 2: printf("N:"); break; 
				case 3: printf("E:"); break;}
			for(j=0;j<13;j++)
				printf(" %c%c",hand[i][j].patten,hand[i][j].point);
			putchar('\n');}
	}
	return 0;
}
/*

很多撲克牌遊戲，例如橋牌，都必須把52張牌輪流發給4個玩家。所以每個玩家有13張牌。厲害的玩家拿到牌就可以直接玩了，但是一般的玩家通常需要先把牌按照花色及點數排序一下。

在這個問題裡面，我們定義花色大小的順序為：CLUBS<DIAMONDS<SPADES<HEARTS（我們從現在起分別以C、D、S、H來代表以上四個花色）。至於點數方面，我們定義大小的順序為：2<3<4<5<6<7<8<9<T<J<Q<K<A（T代表10，J代表Jack，Q代表Queen，K代表King，A代表Ace）。

四個玩家分別坐在東南西北四個位置。其中一個被指定為發牌者，當他發牌的時候是從他左邊那一位開始依順時鐘方向發起，直到把最後一張牌發給自己。請參考下圖。本問題就是請你寫一個程式來模擬發牌及排序的過程。

Input

輸入包含好幾組測試資料，每組測試資料3列。第一列有一個字元代表發牌者（N,E,S,W其中之一，若此字元為#代表輸入結束），接下來的2列為牌的內容，每列26張牌。這52張牌就是發牌者要依序發給各家的牌（每2個字元代表一張牌，例如：CQ代表此張牌花色為CLUB且點數為Q）。請參考Sample Input。

Output

每組輸入資料請輸出四列，每位玩家一列，並且按照S,W,N,E的順序輸出。請注意：玩家手上的牌需經過排序。輸出格式請參考Sample Output

Sample Input

N
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3
DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
#

Sample Output

S: C3 C5 C7 CT CJ D9 DT DJ S3 SK H2 H9 HT
W: C2 C4 CK D4 D5 D6 DQ DA S4 S8 ST SJ H8
N: C6 C8 C9 CA D8 S9 SA H4 H5 H6 H7 HJ HA
E: CQ D2 D3 D7 DK S2 S5 S6 S7 SQ H3 HQ HK

*/