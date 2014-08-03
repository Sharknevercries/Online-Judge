/* 498 Polly the Polynomial Accepted C++ 0.308 2011-02-17 11:35:48 */
#include<stdio.h>
long long int power(long long int x,int y){
	long long int temp;
	if(x==1||y==0)
		return 1;
	else if(y==1)
		return x;
	else if((y&1)==0){
		temp=power(x,y/2);
		return temp*temp;}
	else
		return x*power(x,y-1);
}
int main(){
	char c;
	long long int m[1000];
	long long int s;
	int max=0;
	while(scanf("%lld%c",&m[max++],&c)==2){		
		if(c=='\n'){	
			while(scanf("%lld%c",&s,&c)==2){
				int i,y;
				long long int sum;
				for(sum=i=0,y=max-1;i<max;y--,i++)
					sum+=m[i]*power(s,y);
				printf("%lld%c",sum,c);
				if(c=='\n')	break;}
			max=0;}
	}
	return 0;
}
/*

還記得代數（algebra）嗎？這個問題是給你一x多項式及x的值，請你算出多項式的值。

Input

每組測試資料2列，第一列的內容為{c0, c1, c2, ......, cn}，分別代表多項式各項的係數。如下所示：

c0xn + c1xn-1 + c2xn-2 +...... + cnx0

第二列的內容包含了數個x的值，{x0, x1, x2, ......, xm}

Output

對每組測試資料輸出一列，含有m個整數。也就是對每個x的值，算出其多項式的值。

Sample Input

-2
5 0 1 6
1 -1
7 6 -1
Sample Output

-2 -2 -2 -2
6 5 -2

*/