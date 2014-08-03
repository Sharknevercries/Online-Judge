/* 389 Basically Speaking Accepted C++ 0.080 2011-02-14 11:33:38 */
#include<stdio.h>
int change1(char c){
	if(c>='0'&&c<='9')
		return c-'0';
	else
		return c-'A'+10;
}
char change2(int n){
	if(n>=0&&n<=9)
		return n+'0';
	else
		return n-10+'A';
}
int main(){
	char s[100];
	char result[100];
	int a,b;
	while(scanf("%s%d%d",s,&a,&b)==3){		
		char c=getchar();
		int sum;
		int i,j;
		for(i=0;i<100;i++)
			result[i]='\0';
		for(i=sum=0;s[i]!='\0';i++){
			sum*=a;
			sum+=change1(s[i]);}
		if(sum==0){
			printf("%7d\n",0);
			continue;}
		for(j=1,i=0;j<=sum;j*=b,i++);
		if(i>7){
			puts("  ERROR");
			continue;}
		for(j/=b,i=0;j>0;j/=b,i++){
			result[i]=change2(sum/j);
			sum%=j;}
		result[i]='\0';
		printf("%7s\n",result);
		
	}
	return 0;
}
/*

有一家製造計算機的公司請你幫忙設計新型的計算機。這台計算機必須可以做不同數字系統的轉換（例如：將一個2進位的數字轉換成10進位的數字）。這台計算機還必須有下列的特性：

有 7-digit 的顯示 
除了有 0 ～ 9 的按鈕之外，還有 A ～ F 的按鈕 
支援 2 進位到 16 進位 
Input

輸入含有多組測試資料。

每組測試資料一列，含有 3 個數字。第一個數字為你所要轉換的數字。第二個數字為要轉換的數字為多少進位。第三個數字為要將這個數字轉成多少進位的數。在這3個數前後可能有一或多個空白字元存在。

以Sample Input 第一組測試資料為例：將 1111000 從 2 進位 轉換成 10 進位。

Output

對每組測試資料輸出一列 ，輸出轉換後出現在計算機顯示器上的數字。這些數字長度為 7，靠右對齊。如果這個數字太大無法以計算機顯示器顯示，則輸出 "ERROR"。輸出格式請參考 Sample Output。

Sample Input 
1111000  2 10
  1111000  2  16  
2102101    3  10
2102101  3 15
  12312  4  2
     1A 15  2
1234567 10 16
   ABCD 16 15
   0 10 2
 000234 10 10  
   F00000 16 10

Sample Output 

    120
     78
   1765
    7CA
  ERROR
  11001
 12D687
   D071
      0
    234
  ERROR
 
*/