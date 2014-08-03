/*10071 Back to High School Physics Accepted C++ 0.024 2010-12-08 14:31:11*/ 
#include<stdio.h>
int main(){
	int v,t;
	while(scanf("%d%d",&v,&t)==2){
		printf("%d\n",2*v*t);
	}
	return 0;
}
/*
某一個粒子有一初速度和等加速度。假設在 t 秒後此粒子的速度為 v ，請問這個粒子在 2t 秒後所經過的距離是多少。

Input

每組測試資料1列，有2個整數，分別代表 v（-100 <= v <=100）和 t（0 <= t <= 200）。

Output

對每組測試資料請輸出這個粒子在 2t 秒後所經過的距離是多少。

Sample input

0 0
5 12
Sample Output

0
120
*/