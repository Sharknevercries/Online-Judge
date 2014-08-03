/* 113 Power of Cryptography Accepted C++ 0.020 2011-02-09 06:44:37 */
#include<stdio.h>
#include<math.h>
int main(){
	double p;
	int n;
	while(scanf("%d%lf",&n,&p)==2){		
		printf("%.0lf\n",pow(p,(double)1/n));
	}
	return 0;
}
/*

給你兩個整數 n（n >= 1）和 p（p >=1），你必須寫一個程式來計算出 p 的正 n 次方根。在這個問題裡，p 皆可表成 kn 的形式，其中 k 為整數。（k也就是你的程式所要求的）

Input

每組測試資料2列，第1列有1個整數 n（1 <= n <= 200），第2列有1個整數 p（1 <= p <= 10101）。 並且存在一個整數 k，（1 <= k <= 109），使得 kn=p。

Output

每組測試資料請輸出 k。

Sample Input

2
16
3
27
7
4357186184021382204544

Sample Output

4
3
1234

*/