/* 694 The Collatz Sequence Accepted C++ 0.032 2011-02-22 13:46:10 */
#include<stdio.h>
int main(){
	int r=1;
	long long a,l;
	while(scanf("%lld%lld",&a,&l)==2){
		if(a<0&&l<0) break;
		int count;
		unsigned long long t;
		t=a;
		count=1;
		while(t!=1){
			if((t&1)==0)
				t/=2;
			else{
				if(3*t+1>l)
					break;
				t=3*t+1;
			}
			count++;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",r++,a,l,count);
	}
	return 0;
}
/*

以下這個由Lothar Collatz定義的演算法可以產生一連串數列：

Step１: 
任選一個正整數Ａ作為這個數列的第一項。 
Step２: 
如果Ａ＝１則停止。 
Step３: 
如果Ａ為偶數，則Ａ＝Ａ／２然後重新回到Step２。 
Step４: 
如果Ａ為奇數，則Ａ＝３*Ａ＋１然後重新回到Step２。
這個演算法已經被證明當首項小於等於 109時這個數列最終都會在Step２停止，但是有些Ａ值在這個數列中會超出許多電腦的整數上限。在這個問題中我們想要計算這個數列的長度，而數列的終止有兩種情況：1.最終會在Step２停止或是 2.某一項會在Step４超出一個特定的上限。

Input

輸入包含許多組待測資料，每一列代表一組待測資料，每組待測資料包含兩個正整數，第一個數為首項Ａ，第二個數為這個數列的上限Ｌ，無論Ａ或Ｌ都不會大於2,147,483,647（32位元有號整數的最大值），且首項Ａ總是小於上限Ｌ。當輸入為兩個負數時代表輸入結束。

Output

對每組待測資料必須輸出它為第幾組（從１開始），一個冒號，首項Ａ的值，上限Ｌ的值，以及此一數列的項數。（請參考sample output）

Sample Input

3 100
34 100
75 250
27 2147483647
101 304
101 303
-1 -1

Sample Output

 Case 1: A = 3, limit = 100, number of terms = 8
 Case 2: A = 34, limit = 100, number of terms = 14
 Case 3: A = 75, limit = 250, number of terms = 3
 Case 4: A = 27, limit = 2147483647, number of terms = 112
 Case 5: A = 101, limit = 304, number of terms = 26
 Case 6: A = 101, limit = 303, number of terms = 1

*/