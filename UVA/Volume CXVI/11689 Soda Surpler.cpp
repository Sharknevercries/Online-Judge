/* 11689 Soda Surpler Accepted C++ 0.016 2011-01-31 09:04:25 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		for(i=1;i<=n;i++){
			int e,f,c;
			unsigned long long total=0;
			scanf("%d%d%d",&e,&f,&c);
			e+=f;
			while(true){
				if(e/c==0)
					break;
				total+=e/c;
				f=e/c;
				e%=c;
				e+=f;}
			printf("%llu\n",total);
		}
	}
	return 0;
}
/*

Tim 是一個非常愛喝汽水的人。由於他沒有錢，所以他要喝汽水的唯一方法就是收集空汽水瓶子，然後拿去回收換取錢再去買新汽水來喝。除了他自己喝完的空瓶子，Tim也會到街上去收集別人喝完的空瓶子。有一天，他非常的渴，他要盡可能的喝汽水，直到他得不到任何一瓶為止。

Input

輸入的第1列有一個整數N，代表以下有多少組測試資料。

每組測試資料1列，含有 3 個整數  e,f,c 。e（0 <=  e < 1000）代表Tim一開始擁有的空瓶子數目，f（0 <=  f < 1000）代表Tim在這一天他在街上收集到的空瓶子數目，c（1 <  c < 2000）代表多少個空瓶子可以換一瓶新的汽水。

請參考Sample Input。

Output

對每一組測試資料輸出一列，代表公路上餐廳和藥局間最短的距離。

Sample Input 

2
9 0 3
5 5 2

Sample Output 

4
9
 
*/