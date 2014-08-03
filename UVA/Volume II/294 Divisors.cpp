/* 294 Divisors Accepted C++ 0.236 2011-02-12 08:04:39 */
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		for(i=1;i<=n;i++){
			int a,b,k;
			int m,max;
			int count;
			scanf("%d%d",&a,&b);
			for(k=a,max=0;k<=b;k++){
				int j;
				for(j=1,count=0;j<=sqrt((double)k);j++)
					if(k%j==0)
						count+=2;
				for(j=1;j<=sqrt((double)k);j++)
					if(k==j*j)
						count--;
				if(count>max){
					max=count;
					m=k;}}
			printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,m,max);
		}
	}
	return 0;
}
/*

給你一個範圍的數，請你寫一個程式找出在這個範圍內的數，哪一個數有最多的除數（就是小於等於這個數，且可以被這個數除盡的數。例如：6有4個除數，分別是1,2,3,6）。數的大小很大，範圍也不小，所以你的程式必須有效率，否則可能無法在幾秒內跑完。

Input

輸入的第一列有一個正整數N，代表以下有幾組測試資料。每組測試資料一列，含有2個正整數L，U，代表某一範圍的數中最小及最大的數。並且 1 <= L <= U <= 1000000000，0 <= U-L <= 10000

Output

對每一組測試資料，找出在範圍內有最多除數的數P（如果有不止一個數有最多除數，請找最小的那個），以及他有多少個除數D。然後依這樣的格式輸出：'Between L and H, P has a maximum of D divisors.。請參考Sample Output。

Sample Input

3
1 10
1000 1000
999999900 1000000000

Sample Output

Between 1 and 10, 6 has a maximum of 4 divisors.
Between 1000 and 1000, 1000 has a maximum of 16 divisors.
Between 999999900 and 1000000000, 999999924 has a maximum of 192 divisors.

*/