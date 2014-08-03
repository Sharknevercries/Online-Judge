/*476 Points in Figures: Rectangles Compiling C++ 0.000 2010-12-10 12:21:35*/
#include<stdio.h>
int main(){
	double m[100][4];
	double n[2];
	char a;
	int count_r=0,count=0;	
	while(scanf(" %c",&a)==1)
		if(a=='r'){
			scanf("%lf%lf%lf%lf",&m[count_r][0],&m[count_r][1],&m[count_r][2],&m[count_r][3]);
			count_r++;}
		else 
			break;
	while(scanf("%lf%lf",&n[0],&n[1])==2&&(n[0]!=9999.9&&n[1]!=9999.9)){
		int flag=0;
		for(int i=0;i<count_r;i++)			
			if((m[i][0]<=n[0] && m[i][2]>=n[0]) && (m[i][1]>=n[1] && m[i][3]<=n[1])){
				flag=1;
				printf("Point %d is contained in figure %d\n",count+1,i+1);}
		
		if(flag==0)
			printf("Point %d is not contained in any figure\n",count+1);
		count++;
	}
	return 0;
}
/*
在x-y平面上，給你一些矩形和一些點，請你回答這些點落在哪些矩形內（如果有的話）。另外，在這個問題中，剛好落在邊上的點不視為落在該矩形內。

Input

首先是矩形的資料，每個矩形一列，第1個字元代表圖形的類別（r 代表矩形），接下來有4個數值分別代表該矩形左上角及右下角的座標。矩形的個數不會超過10個。

以一列僅含有一個*代表矩形資料結束。

接下來的每列為一個點的座標，也就是要測試的點。若點座標為9999.9 9999.9代表輸入結束（此點不需輸出）

Output

對每一個測試的點，若其落在某矩形內，則輸出下列格式的訊息：

Point i is contained in figure j
如果某個點沒有落在任何矩形內，則輸出：

Point i is not contained in any figure
請注意：點和矩形的編號是按照他們出現在input的順序。請參考Sample Output

Sample Input

r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
Sample Output

Point 1 is contained in figure 2
Point 2 is contained in figure 2
Point 2 is contained in figure 3
Point 3 is contained in figure 3
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 6 is not contained in any figure
*/