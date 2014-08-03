/* 10783 Odd Sum Accepted C++ 0.016 2011-01-26 06:38:29 */
#include<stdio.h>
int main(){
	int t;
	int count;
	count=1;
	while(scanf("%d",&t)==1){
		int i;
		for(i=1;i<=t;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if((a&1)==0)
				a++;
			if((b&1)==0)
				b--;
			printf("Case %d: %d\n",count++,((a+b)*((b-a)/2+1))/2);

		}
	}
	return 0;
}
/*

給你一個範圍 a 到 b ，請你找出 a 與 b 之間所有奇數的和。

例如：範圍 [3, 9] 中所有奇數的和就是 3 + 5 + 7 + 9 = 24 。

Input

輸入的第一列有一個整數 T （1≦T≦100），代表以下有多少組測試資料。

每組測試資料為兩列，包含兩個數 a 與 b （0≦a≦b≦100）。

Output

每組測試資料輸出一列，內容為 a 及 b 間所有奇數的和。

Sample Input

2
1
5
3
5

Sample Output

Case 1: 9
Case 2: 8

*/