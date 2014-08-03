/* 253 Cube painting Accepted C++ 0.012 2011-02-12 06:09:33 */
#include<stdio.h>
#include<string.h>
void rotate1(char c[]){
	char temp;
	temp=c[2];
	c[2]=c[1];
	c[1]=c[3];
	c[3]=c[4];
	c[4]=temp;
}
void rotate2(char c[]){
	char temp;
	temp=c[0];
	c[0]=c[1];
	c[1]=c[5];
	c[5]=c[4];
	c[4]=temp;
}
void rotate3(char c[]){
	char temp;
	temp=c[0];
	c[0]=c[2];
	c[2]=c[5];
	c[5]=c[3];
	c[3]=temp;
}
int main(){
	char str[13];
	while(gets(str)){
		char c1[7],c2[7];
		bool found=false;
		strncpy(c1,str,6);
		strncpy(c2,str+6,6);
		c1[6]=c2[6]='\0';
		int i,j,k;
		for(i=1;i<=4&&!found;i++){
			for(j=1;j<=4&&!found;j++){
				for(k=1;k<=4&&!found;k++){
					if(strcmp(c1,c2)==0)
						found=true;
					rotate1(c1);}
				rotate2(c1);}
			rotate3(c1);}
		if(found)
			puts("TRUE");
		else
			puts("FALSE");
	}
	return 0;
}
/*

我們想要為方塊塗上顏色，我們有三種顏色：藍色、紅色、綠色。方塊的每一面塗上其中一種顏色。現在，我們把方塊的6個面以1~6來編號，如下圖Figure 1:

因為一個方塊有6面，所以我們有36=729種不同的方式來圖方塊。然而當我們忽略面上的編號時，不同塗方塊的方式就會少很多，那是因為方塊可以旋轉的緣故。請看以下的例子：我們以6個字元來表達一個方塊6個面上塗的顏色（字元為b,r,g其中之一，分別代表blue, red, green）。第i個字元代表第i面上的顏色，例如下圖Figure 2就是rbgggr的圖，Figure 3就是rggbgr的圖。請注意：Figure 2 和 Figure 3其實塗色的方式是一樣的，如果我們把Figure 2的方塊繞垂直方向向右轉90度，就變成Figure 3中的方塊了。

Input

每組測試資料一列。每列有12個字元。前6個字元代表一個方塊，後6個字元代表另一個方塊。你的程式必須判斷這2個方塊是否塗色的方式是一樣的，也就是說，是否可以經由旋轉的方式，使一個方塊變成另一個。

Output

對每組測試資料輸出一列。如果第一個方塊可以旋轉而變成第二個方塊，則輸出TRUE，否則輸出FALSE。

Sample Input

rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg

Sample Output

TRUE
FALSE
FALSE

*/