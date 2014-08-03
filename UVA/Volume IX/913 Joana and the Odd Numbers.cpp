/* 913 Joana and the Odd Numbers Accepted C++ 0.012 2011-01-26 09:53:46 */
#include<stdio.h>
int main(){
	unsigned long long n;
	while(scanf("%llu",&n)==1){
		unsigned long long sum=(n*n+n*2-5)/2*3;
		printf("%llu\n",sum);
	}
	return 0;
}
/*

Joana喜歡玩關於奇數的遊戲。有一天，她開始寫，每列都是奇數，如下表。 

 13 5 79 11 13 15 1719 21 23 25 27 29 31...在某一列Joana寫下了55個奇數數字，你可以看出該列最後3個數字的和嗎？給你一個數字N，代表某一列有N個奇數數字，你的任務是把該列最後三個數加起來。輸入說明 ：

輸入含有多組測試資料。

每組測試資料一列，有一個數字 N，表示某一列有 N 個奇數數字（1 < N < 1000000000）。 

輸出說明 ：

對每組測試資料，輸出該列的最後三個數字的和。本問題中保證三個數字的和一定小於263。

範例輸入 ： 

3
5
7

範例輸出 ：

15
45
87

提示 ：

* 中文翻譯：Lucky 貓

出處 ：

Uva ACM 913 (作者：MAPLEWING) 

*/