/* 11172 Relational Operator Accepted C++ 0.012 2011-01-31 07:39:58 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		for(i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a-b>0)
				puts(">");
			else if(a-b==0)
				puts("=");
			else
				puts("<");
		}
	}
	return 0;
}
/*

有些運算子（operator）是用來檢查兩個數值之間的關係，這種運算子稱為關係運算子（relational operators）。 給你兩個數值你的工作就是要找出它們之間的關係是(1)第一個大於第二個 (2)第二個小於第一個 (3)兩個一樣大。 

Input

輸入的第一列有一個整數代表共有多少組測試資料。

接下來每列有兩個整數 a 和 b （ |a|,|b| < 1000000001）。 

Output

對於每組測試資料，輸出，">", "<" 或 "="，代表該二數字的關係。

Sample Input  

3
10 20
20 10
10 10

Sample Output

<
>
=
 
*/