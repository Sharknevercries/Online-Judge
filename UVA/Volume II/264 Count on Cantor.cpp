/* 264 Count on Cantor Accepted C++ 0.024 2011-02-12 07:33:22 */
#include<stdio.h>
int main(){
	unsigned long long n;
	while(scanf("%llu",&n)==1){
		if(n==1){
			puts("TERM 1 IS 1/1");
			continue;}
		unsigned long long i,j;
		for(i=2,j=(i+1)*i/2;j<n;i++,j=(i+1)*i/2);
		if((i&1)==0)
			printf("TERM %llu IS %llu/%llu\n",n,i+n-j,j-n+1);
		else
			printf("TERM %llu IS %llu/%llu\n",n,j-n+1,i+n-j);
	}
	return 0;
}
/*

現代數學中有一個有名的證明（由Georg Cantor所提出的）：有理數是可數的。他使用一個圖表（Cantor's 列舉）列舉出有理數，如下圖所示：  
 
在此圖中，第一項是1/1,第2項是1/2,第三項是2/1,第四項是3/1,第五項是2/2,以下依此類推。 

Input and Output

輸入每筆資料1行，含有1個正整數n (1<=n<=107)。
對每行輸入，輸出在Cantor's 列舉圖中的第n項。 

Sample Iutput

3
14
7

Sample Output

TERM 3 IS 2/1
TERM 14 IS 2/4
TERM 7 IS 1/4

*/