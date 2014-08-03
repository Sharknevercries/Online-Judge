/* 10038 Jolly Jumpers Accepted C++ 0.008 2011-01-10 13:26:02 */
#include<stdio.h>
bool distance(int x,int y,int n,bool once[]){
	int temp=x-y>=0?x-y:y-x;
	if(temp>=1&&temp<=n-1)
		if(!once[temp]){
			once[temp]=true;
			return true;
		}	
	return false;
}
int main(){
	int table[3000];
	int n,i;
	while(scanf("%d",&n)==1){
		bool YES;
		bool once[3000]={0};
		for(i=0;i<n;i++)
			scanf("%d",&table[i]);
		for(i=0,YES=true;i<n-1&&YES;i++)
			if(!distance(table[i],table[i+1],n,once))
				YES=false;
		if(YES)
			puts("Jolly");
		else
			puts("Not jolly");
	}
	return 0;
}
/*

有n個整數的序列我們稱為jolly jumper，如果相鄰的2個數其差的絕對值恰好為1到n-1。例如：

1 4 2 3

就是jolly jumper（n=4）。因為相鄰2數的差的絕對值為3,2,1，就是1到n-1。但是

1 4 2 -1 6 

不是jolly jumper（n=5）。因為相鄰2數的差的絕對值為3,2,3,7，並非1到n-1。

你的任務是寫一個程式來判斷一個整數序列是否為jolly jumper。

Input

每組測試資料一列，第一個正整數為 n（n < 3000），代表此整數序列的長度。接下來有n個整數，代表此整數序列。

Output

對每一組測試資料，輸出此整數序列是否為jolly jumper。

Sample Input

4 1 4 2 3
5 1 4 2 -1 6

Sample Output

Jolly
Not jolly

*/