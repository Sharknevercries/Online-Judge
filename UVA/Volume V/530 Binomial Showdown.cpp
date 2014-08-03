/* 530 Binomial Showdown Accepted C++ 0.012 2011-01-30 15:13:48 */
#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
			break;
		unsigned long long sum;
		unsigned long long i,j;
		if(m>n-m)
			m=n-m;
		for(i=sum=1,j=n;i<=m;i++,j--)
			sum*=j,sum/=i;
		printf("%llu\n",sum);
	}
	return 0;
}
/*

從N個東西中取出M個東西的方法數（不管排列的順序）是：


請你寫一個程式算出C。你可以假設你的答案C不會超出 int 的範圍，也就是一定小於231。

輸入說明 ：

每組測試資料一列，有2個正整數 N,M（N >= 1, 0 <= M <= N）。 

N=0，M=0代表輸入結束。

輸出說明 ：

輸出C

範例輸入 ： 

4 2
10 5
49 6
0 0

範例輸出 ：

6
252
13983816

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 530 

*/