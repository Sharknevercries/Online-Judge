/* 587 There's treasure everywhere! Accepted C++ 0.012 2011-02-21 10:42:10 */
#include<stdio.h>
#include<math.h>
int main(){
	int count=1;
	char str[300];
	while(gets(str)){
		if(str[0]=='E') break;
		int i;
		int temp;
		double x,y;
		for(i=temp=x=y=0;str[i]!='\0';i++){
			if(str[i]==','||str[i]=='.'){
				temp=0;
				continue;}
			while(str[i]>='0'&&str[i]<='9')
				temp=temp*10+str[i++]-'0';
			if(str[i]=='N'){				
				if(str[i+1]=='E'){
					x+=sqrt((double)temp*temp/2);
					y+=sqrt((double)temp*temp/2);
					i++;}
				else if(str[i+1]=='W'){
					x-=sqrt((double)temp*temp/2);
					y+=sqrt((double)temp*temp/2);
					i++;}
				else
					y+=temp;}
			else if(str[i]=='E')
				x+=temp;
			else if(str[i]=='W')
				x-=temp;
			else{
				if(str[i+1]=='E'){
					x+=sqrt((double)temp*temp/2);
					y-=sqrt((double)temp*temp/2);
					i++;}
				else if(str[i+1]=='W'){
					x-=sqrt((double)temp*temp/2);
					y-=sqrt((double)temp*temp/2);
					i++;}
				else
					y-=temp;	}			
		}
		printf("Map #%d\n",count++);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n",sqrt(x*x+y*y));
		putchar('\n');
	}
	return 0;
}
/*

尋寶是簡單的，只要你有地圖的話。在迦勒比海的海盜就是以寶藏及藏寶圖出名的。藏寶圖通常讀起來像這樣：「從棕欖樹開始，往森林的方向走3步，再往小噴泉走11步，......，最後往大岩石走6步，在那裡就可以挖出埋藏的寶藏了。」這樣的藏寶圖找起來相當有趣，但是如果你很急，你或許會想到先計算一下寶藏的位置，然後直接走到該處挖寶。例如在下方右邊的藏寶圖中，告訴你向北走3步，向東走1步，再向北走1步，再向東走3步，再向南走2步，最後向西走1步就可到達藏寶地點了。你可以不需真的去走這條路線（實線），而是經過計算出藏寶位置後直接走到該處（虛線路徑）。

你的任務就是，給你一張「傳統」的地圖，請你寫一個程式算出藏寶的地點以及距離。地圖中的方向有8個，如下方左邊的圖所示。

Input

每組測試資料（地圖）一列，最多200個字元的長度。內容為藏寶地點的提示。例如：3W代表向西走3步，17NE代表向東北走17步。各提示之間以逗號分隔，每列的最後以.做結束。在每列中間不會有空白出現。請參考Sample Input。

最後一列的內容為END，代表輸入結束。

Output

每組測試資料輸出這是第幾張地圖，藏寶地點(x,y)，以及從出發點（座標：0,0）到藏寶地點的距離d是多少。x,y,d輸出到小數點後3位。

每組測試資料後請空一列。請參考Sample Output。

Sample Input

3N,1E,1N,3E,2S,1W.
10NW.
END

Sample Output

Map #1
The treasure is located at (3.000,2.000).
The distance to the treasure is 3.606.

Map #2
The treasure is located at (-7.071,7.071).
The distance to the treasure is 10.000.　

*/