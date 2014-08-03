/* 10055 Hashmat the Brave Warrior Accepted C++ 0.080 2011-01-10 14:58:47 */
#include<stdio.h>
int main(){
	unsigned long long a,b;
	while(scanf("%llu%llu",&a,&b)==2){		
		if(a>=b)
			printf("%llu\n",a-b);
		else
			printf("%llu\n",b-a);
	}
	return 0;
}
/*

Hashmat是一個勇敢的將領，他帶著年輕的士兵從這個城市移動到另一個城市與敵人對抗。在打仗之前他會計算己方與敵方士兵的數目差距，來決定是要開打或不開打。Hashmat的士兵數絕不會比敵人的士兵數大。

Input

每組測試資料1列，有2個整數，代表Hashmat及敵人的士兵數或反之。這些數不會超過232。

Output

對每組測試資料請輸出Hashmat與敵人士兵數目的差（正數）。

Sample input

10 12
14 10
100 200

Sample Output

2
4
100

*/