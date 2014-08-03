/* 11185 Ternary Accepted C++ 0.016 2011-01-31 08:14:12 */
#include<stdio.h>
int main(){
	long long n;
	char str[50];
	while(scanf("%llu",&n)==1){
		if(n<0)
			break;
		if(n==0){
			puts("0");
			continue;}			
		int index,len;
		unsigned long long k;
		for(k=1,index=0;k<=n;k*=3,index++);
		str[len=index]='\0';
		for(index=0;index<len;index++)
			str[index]='0';
		for(k/=3,index=0;n>0;k/=3,index++)
			while(n>=k){
				str[index]++;
				n-=k;}
		printf("%s\n",str);
	}
	return 0;
}
/*

給你十進位的數字 N，請你把他轉換成 3 進位。

Input

輸入包含多組測試資料。每組測試資料一列有1個整數 N（0 <= N < 1000000001）

當 N<0 時，代表輸入結束。

Output

每組測試資料輸出一列，輸出 N 的 3 進位表示。

Sample Input 
0
1
2
3
10
100
1000
-9

Sample Output 

0
1
2
10
101
10201
1101001
 
*/