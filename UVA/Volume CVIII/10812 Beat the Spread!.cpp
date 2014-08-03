/* 10812 Beat the Spread! Accepted C++ 0.016 2011-01-26 08:31:35 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		for(i=1;i<=n;i++){
			int s,d;
			int x,y;
			scanf("%d%d",&s,&d);
			if(((s+d)&1)!=0){
				puts("impossible");
				continue;}
			x=(s+d)/2;
			y=s-x;			
			if(x<0||y<0)
				puts("impossible");
			else
				printf("%d %d\n",x,y);
		}
	}
	return 0;
}
/*

超級盃又來了，為了打發中場休息時間，大家就來下注最後的結果會如何。大家下注的目標為兩隊最後的分數和，或者兩隊最後分數差的絕對值。 
給你這2個值，你能推出這2隊最後的得分是多少嗎？

Input

輸入的第一列有一個整數，代表以下有多少組測試資料。

每組測試資料一列，有2個大於等於 0 的整數 s, d，s 代表比賽結束時2隊分數的總和， d 代表比賽結束時2隊分數差的絕對值。

Output

對每組測試資料輸出一列，包含2個整數代表比賽結束時這2隊的分數，分數大的在前。如果沒有這樣的分數，請輸出「impossible」。 

請記得：美式足球的分數一定是大於等於 0 的整數。

Sample Input  

4
40 20
20 40
5 1
100 1

Sample Output

30 10
impossible
3 2
impossible
 
*/