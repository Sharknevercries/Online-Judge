/* 10209 Is This Integration ? Accepted C++ 0.048 2011-01-25 05:59:39 */
#include<stdio.h>
#include<math.h>
int main(){
	double a;
	while(scanf("%lf",&a)==1){
		const double PI=2.0*acos(0.0);
		printf("%.3lf ",a*a*(1-sqrt(3.0)+PI/3));
		printf("%.3lf ",a*a*(1-(1-sqrt(3.0)+PI/3)-(4-sqrt(3.0)-2.0/3*PI)));
		printf("%.3lf\n",a*a*(4-sqrt(3.0)-2.0/3*PI));    
	}
	return 0;
}
/*

Input

輸入的每一行測試資料有1個浮點數 a（ 0 <= a <= 10000），代表正方形的邊長。

Output

對每一個輸入a，輸出3個不同花紋區域的面積，請輸出到小數點以下3位。第一個數為條狀區域的面積（中間那一塊），第2個數為點狀區域的面積（4個有點像正三角形的區域），第3個為格子狀區域的面積。

Sample input

0.1
0.2
0.3

Sample Output

0.003 0.005 0.002
0.013 0.020 0.007
0.028 0.046 0.016

Attention

使用PI=3.14159可能不夠精確，請用2.0*acos(0.0)作為PI的值。

*/