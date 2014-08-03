/*477 Points in Figures: Rectangles and Circles Accepted C++ 0.024 2010-12-10 14:47:42 */
#include<stdio.h>
#include<math.h>
#define R 1
#define C 2
int main(){
	double m[100][4];
	int type[100]={0};              //1 r 2 c
	double n[2];
	char a;
	int count_r=0,count=0;		
	while(scanf(" %c",&a)==1)
		if(a=='r'){
			scanf("%lf%lf%lf%lf",&m[count_r][0],&m[count_r][1],&m[count_r][2],&m[count_r][3]);
			type[count_r]=R;
			count_r++;}
		else if(a=='c'){
			scanf("%lf%lf%lf%",&m[count_r][0],&m[count_r][1],&m[count_r][2]);
			type[count_r]=C;
			count_r++;}
		else
			break;
	while(scanf("%lf%lf",&n[0],&n[1])==2&&(n[0]!=9999.9&&n[1]!=9999.9)){
		int flag=0;
		for(int i=0;i<count_r;i++)
			if(type[i]==R){
				if((m[i][0]<=n[0] && m[i][2]>=n[0]) && (m[i][1]>=n[1] && m[i][3]<=n[1])){
					flag=1;
					printf("Point %d is contained in figure %d\n",count+1,i+1);}}
			else{
				double temp1=n[0]-m[i][0];
				double temp2=n[1]-m[i][1];
				if((double)sqrt(temp1*temp1+temp2*temp2)<m[i][2]){
					flag=1;
					printf("Point %d is contained in figure %d\n",count+1,i+1);}}
		if(flag==0)
			printf("Point %d is not contained in any figure\n",count+1);
		count++;
	}
	return 0;
}
/*
在x-y平面上，給你一些圖形（矩形、圓形）和一些點，請你回答這些點落在哪些圖形內（如果有的話）。另外，在這個問題中，剛好落在邊上的點不視為落在該圖形內。

Input

首先是圖形的資料，每個圖形一列，第1個字元代表圖形的類別（r 代表矩形，c 代表圓形），如果該圖是矩形，接下來會有4個數值分別代表該矩形左上角及右下角的座標。如果該圖是圓形，接下來會有3個數值分別代表該圓的圓心座標及半徑。圖形的個數不會超過10個。

以一列僅含有一個*代表圖形資料結束。

接下來的每列為一個點的座標，也就是要測試的點。若點座標為9999.9 9999.9代表輸入結束（此點不需輸出）。請參考Sample Input。

Output

對每一個測試的點，若其落在某圖形內，則輸出下列格式的訊息：

Point i is contained in figure j
如果某個點沒有落在任何圖形內，則輸出：

Point i is not contained in any figure
請注意：點和矩形的編號是按照他們出現在input的順序。請參考Sample Output

Sample Input

r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
Sample Output

Point 1 is contained in figure 3
Point 2 is contained in figure 3
Point 2 is contained in figure 5
Point 3 is contained in figure 5
Point 3 is contained in figure 6
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 5 is contained in figure 2
Point 6 is contained in figure 4
*/