/* 10696 f91 Accepted C++ 0.176 2011-01-26 06:32:16 */
#include<stdio.h>
unsigned long long f91(unsigned long long n){
	if(n>100)
		return (n-10);
	else
		return f91(f91(n+11));
}
int main(){
	unsigned long long n;
	while(scanf("%llu",&n)==1&&n!=0){
		printf("f91(%llu) = %llu\n",n,f91(n));
	}
	return 0;
}
/*

McCarthy是一個有名的資訊專家。他定義了一個遞迴的函數叫做 f91 。它輸入一個正整數N並且依據以下的規則傳回一個正整數：

. 如果 N <= 100, 那麼 f91(N) = f91( f91( N+11) )

. 如果 N >= 101, 那麼 f91(N) = N-10

請你寫一個程式來計算 f91

Input

每組測試資料一列。含有1個正整數 N（ N <= 1000000）。輸入最多有250000組測試資料。

若 N=0 代表輸入結束。

Output

對每組測試資料輸出一列 f91(N)，。輸出格式請參考Sample Output。

Sample Input 
500
91
0 

Sample Output 

f91(500) = 490
f91(91) = 91

*/