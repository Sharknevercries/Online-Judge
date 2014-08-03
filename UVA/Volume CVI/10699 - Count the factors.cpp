/* 10699 Count the factors Accepted C++ 0.208 2011-01-28 15:15:42 */
#include<stdio.h>
int prime[100000];
int total;
void make_prime(){
	int i,j;
	bool IS;
	prime[0]=2;
	total=1;
	for(i=3,IS=true;i<100000;i+=2,IS=true){
		for(j=0;j<total;j++)
			if(i%prime[j]==0){
				IS=false;
				break;}
		if(IS)
			prime[total++]=i;
	}
}
int main(){
	make_prime();
	int n;
	while(scanf("%d",&n)==1){
		
		if(n==0)
			break;
		int i;
		int temp;
		int count;
		for(i=count=0,temp=n;i<total&&prime[i]<=temp;i++)
			if(temp%prime[i]==0){
				temp/=prime[i];
				while(temp%prime[i]==0)
					temp/=prime[i];
				count++;}
		if(temp!=1)
			count++;
		printf("%d : %d\n",n,count);
	}
	return 0;
}
/*

寫一個程式算出一個正整數有多少個不同的質因數。例如：45=3*3*5，所以45有2個質因數（3和5）。

輸入說明 ：

每組測試資料一列。含有1個正整數 n（ 1 < n <= 1000000）。

若 n=0 代表輸入結束。

輸出說明 ：

對每組測試資料輸出一列，n有多少個不同的質因數。輸出格式請參考Sample Output。

範例輸入 ： 

7
8
45
289384
930887
692778
636916
747794
238336
885387
760493
516650
641422
0

範例輸出 ：

7 : 1
8 : 1
45 : 2
289384 : 3
930887 : 2
692778 : 5
636916 : 4
747794 : 3
238336 : 3
885387 : 2
760493 : 2
516650 : 3
641422 : 3

提示 ：

Lucky 貓 英 中

出處 ：

UVa ACM 10699 (作者：snail) 

*/