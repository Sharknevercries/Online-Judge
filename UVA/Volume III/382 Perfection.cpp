/* 382 Perfection Accepted C++ 0.024 2011-02-13 07:23:24 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	puts("PERFECTION OUTPUT");
	int temp;	
	while(scanf("%d",&temp)){			
		if(temp==0)
			break;
		int sum;
		int i;
		for(i=1,sum=0;i*i<temp;i++)
			if(temp%i==0)
				sum+=i+(temp/i);
		if(i*i==temp)
			sum+=i;
		sum-=temp;
		if(sum==temp)
			printf("%5d  PERFECT\n",temp);
		else if(sum>temp)
			printf("%5d  ABUNDANT\n",temp);
		else
			printf("%5d  DEFICIENT\n",temp);		
	}
	puts("END OF OUTPUT");
	return  0;
}
/*

一個整數b如果可以被另一個整數a整除（在這裡a>b），我們稱b是a的一個因數。
Perfect Number是一個正整數並且等於其所有因數的和。例如：6和28都是perfect number。因為6=1+2+3，28=1+2+4+7+14。如果一個正整數不是perfect，那他就是deficient或者是abundant，根據其所有因數的和是小於或大於這個數本身。因此，9是deficient因為1+3<9。而12是abundant因為1+2+3+4+6>12。
請寫一個程式求出某一個數是perfect, deficient 或者abundant。

Input

有一連串（不會超過100個）的正整數n（1 <= n < 60000）,n=0代表輸入結束。

Output

請參考 Sample Output。

數字部分佔5個字元長度，靠右對齊。與後方的敘述間空2個空白格。

Sample Input

15 28 6 56 60000 22 496 0

Sample Output

PERFECTION OUTPUT
   15  DEFICIENT
   28  PERFECT
    6  PERFECT
   56  ABUNDANT
60000  ABUNDANT
   22  DEFICIENT
  496  PERFECT
END OF OUTPUT
　
*/