/* 484 The Department of Redundancy Department Accepted C++ 0.040 2011-02-16 12:13:20 */
#include<stdio.h>
int main(){
	int x;
	int i;
	int count[100000];
	int m[10000];
	int max=0;
	while(scanf("%d",&x)==1){
		for(i=0;i<max;i++)
			if(m[i]==x){
				count[i]++;
				break;}
		if(i>=max){
			m[max]=x;
			count[max++]=1;}
	}
	for(i=0;i<max;i++)
		printf("%d %d\n",m[i],count[i]);
	return 0;
}
/*

寫一個程式來計算在一串數字中，每個數字出現的次數。 

Input

輸入包含了一連串的整數（可能有非常多個）。  

Output

對每一個不同的輸入數字，請輸出該數字及其出現的次數，中間以一個空格分開。輸出的數字順序需和輸入的數字出現的順序相同。請參考Sample Output 

Sample Iutput

3 1 2 2 1 3 5 3 3 2 

Sample Output

3 4
1 2
2 3
5 1

*/