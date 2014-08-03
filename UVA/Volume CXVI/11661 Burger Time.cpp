/* 11661 Burger Time? Accepted C++ 0.056 2011-01-31 08:56:06 */
#include<stdio.h>
char str[2000005];
int r[1000000];
int d[1000000];
int abs(int a){
	if(a<0)
		return -a;
	return a;
}
int main(){
	int l;
	while(scanf("%d",&l)==1){
		if(l==0)
			break;
		char c=getchar();
		int i,j;
		int len=2147483647;		
		int r_p,d_p;
		gets(str);
		for(i=r_p=d_p=0;str[i]!='\0';i++){
			if(str[i]=='R')
				r[r_p++]=i;
			if(str[i]=='D')
				d[d_p++]=i;
			if(str[i]=='Z'){
				len=0;
				break;}}
		if(len==0){
			puts("0");
			continue;}
		for(i=j=0;i<r_p&&j<d_p;){
			if(abs(r[i]-d[j])<len)
				len=abs(r[i]-d[j]);
			if(r[i]<d[j])
				i++;
			else
				j++;}
		printf("%d\n",len);
	}
	return 0;
}
/*

大家都知道，在重要的公路旁都會有速食餐廳。你可以在那裡買到漢堡、熱狗、披薩、三明治等等。

但有很多時候問題不是找不到餐廳，而是找不到藥局。在你吃了許多速食後，需要一間藥局也是平常的，因為你的胃可能開始疼痛了。

給你餐廳和藥局的在公路的位置，請你找出某間餐廳和藥局間最短的距離。

Input

輸入含有多組測試資料。每組測試資料2列，第一列含有 1 個正整數  L （ 1 <= n <= 2000000）代表公路的長度。

第二列為長度L的字串，顯示沿著公路的餐廳及藥房的位置。字串的內容為下列之一：

R代表這個位置有餐廳 
D代表這個位置有藥局 
Z代表這個位置同時有餐廳及藥局 
. 代表空的位置 
你可以假設每組測試資料中至少有一間餐廳和一間藥局。

當 L 為 0 時，代表輸入結束。請參考Sample Input。

Output

對每一組測試資料輸出一列，代表公路上餐廳和藥局間最短的距離。

Sample Input  

2
RD
5
..Z..
10
.R......D.
10
.R..Z...D.
10
...D..R...
25
..D...R.RR...DD...D.R...R

Sample Output

0
1
0
7
0
3
2　
 
*/