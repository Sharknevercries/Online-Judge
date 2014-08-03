/* 10107 What is the Median? Accepted C++ 0.028 2011-01-07 12:01:32 */
#include<stdio.h>
int main(){
	int s[10001]={0};
	int n;//s[0] empty
	int len=0;
	int i;
	while(scanf("%d",&n)==1){		
		for(i=len;n<s[i];i--)
			s[i+1]=s[i];
		s[i+1]=n;
		len++;
		if((len&1)==0)
			printf("%d\n",(s[len/2]+s[len/2+1])/2);
		else
			printf("%d\n",s[len/2+1]);
	}
	return 0;
}
/*

在統計學的世界中，中間數（median）扮演一個重要的角色。 根據定義：中間數就是在一連串已由小到大排序的數字中，排在中間的那一個數。例如：在{1,3,4,9,11}中4就是中間數。萬一有偶數個數字，我們定義中間數就是位於中間的那2個數的和除以2（而且只取整數部分）。例如：在{1,2,3,6,7,8}中{3,6}是位於中間的2個數，所以中間數就是(3+6)/2=4。 

Input

輸入包含了N個（N<10000）的整數。  

Output

對每一個輸入，請輸出到現在為止已輸入的數的中間數。  

Sample Iutput

1
3
4
60
70
50
2 

Sample Output

1
2
3
3
4
27
4

*/