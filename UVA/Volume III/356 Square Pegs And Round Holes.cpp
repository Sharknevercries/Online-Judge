/* 356 Square Pegs And Round Holes Accepted C++ 0.016 2011-02-13 06:06:31 */
#include<stdio.h>
#include<math.h>
int judge(int x,int y,double r){
	if(x*x+y*y<=r*r)
		return true;
	else 
		return false;
}
void in(int x,int y,int high[],double r){
	if(y==0)
		;
	else if(judge(x+1,y,r))
		in(x+1,y,high,r);
	else{
		for(int i=0;i<x;i++)
			high[i]++;
		in(x,y-1,high,r);}
}
void out(int x,int y,int high[],double r){
	if(y==0)
		;
	else if(judge(x,y-1,r))	
		out(x+1,y,high,r);
	else{
		for(int i=0;i<(int)x;i++)
			high[i]++;
		out(x,y-1,high,r);}	
}

int main(){
	int n;
	bool first=true;
	while(scanf("%d",&n)==1){		
		int inside;
		int outside;
		int high[200]={0};
		inside=outside=0;
		in(0,n-1,high,n-0.5);
		for(int i=0;i<n-1;i++){
			inside+=high[i];
			high[i]=0;}
		out(0,n,high,n-0.5);
		for(int i=0;i<n;i++){
			outside+=high[i];
			high[i]=0;}
		outside-=inside;
		inside*=4;
		outside*=4;
		if(!first)
			putchar('\n');
		else first=false;
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,outside);
		printf("There are %d cells completely contained in the circle.\n",inside);

	}
	return 0;
}
/*

在一個邊長為2n的正方形棋盤中央畫一個直徑為2n-1的圓，以下的圖為n=3 

 寫一個程式判斷有多少個格子是一部份在圓中，以及有多少個格子是完全被包含在圓當中。 

Input

輸入包含好幾行測試資料，每行有一個正整數n（n<=150）

Output

對每一行輸入資料，輸出2行，第一行為部分被包含在圓中的個子數。第二行為完全被包含在圓中的格子數。對每一個數入資料，輸出資料間要空一行。請參考Sample output

Sample Iutput

3
4 

Sample Output

In the case n = 3, 20 cells contain segments of the circle.
There are 12 cells completely contained in the circle.

In the case n = 4, 28 cells contain segments of the circle.
There are 24 cells completely contained in the circle.

*/