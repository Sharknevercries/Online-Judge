/* 392 Polynomial Showdown Accepted C++ 0.096 2011-02-14 12:05:14 */
#include<stdio.h>
int main(){
	int m[9];
	while(scanf("%d",&m[0])==1){
		int i;
		bool first=true;
		for(i=1;i<9;i++)
			scanf("%d",&m[i]);
		for(i=0;i<7;i++)
			if(m[i]!=0)
				if(first){
					if(m[i]==1)
						printf("x^%d",8-i);
					else if(m[i]==-1)
						printf("-x^%d",8-i);
					else
						printf("%dx^%d",m[i],8-i);
					first=false;}
				else if(m[i]==1)
					printf(" + x^%d",8-i);
				else if(m[i]>1)
					printf(" + %dx^%d",m[i],8-i);
				else if(m[i]==-1)
					printf(" - x^%d",8-i);
				else
					printf(" - %dx^%d",-m[i],8-i);
				
		if(m[i]!=0)
			if(first){
				if(m[i]==1)
					printf("x");
				else if(m[i]==-1)
					printf("-x");
				else
					printf("%dx",m[i]);
				first=false;}
			else if(m[i]==1)
				printf(" + x");
			else if(m[i]>1)
				printf(" + %dx",m[i]);
			else if(m[i]==-1)
				printf(" - x");
			else
				printf(" - %dx",-m[i]);		
		i++;
		if(first)
			printf("%d",m[i]);
		else if(m[i]!=0)
			if(m[i]>0)
				printf(" + %d",m[i]);
			else
				printf(" - %d",-m[i]);
		putchar('\n');
	}
	return 0;
}
/*

給你一個數學多項式的係數，從8次方到0次方。你的任務是把一些不需要的項次拿掉，然後以易讀的格式來輸出。例如：給你 0, 0, 0, 1, 22, -333, 0, 1,  -1這9個係數，你應該要產生這樣的輸出： x^5 + 22x^4 - 333x^3 + x - 1

以下是詳細格式的規則：

項次必須按降冪出現。 
指數部分出現在^符號之後。 
常數項只要出現常數部分就好了，不需有x^0。 
只有係數非0的項次才需出現。如果所有的係數都是0，那只要輸出常數項就可以了。 
介於項次之間的+號和-號兩邊各有一空白字元。 
假如第一項的係數是正的，那麼該係數不需要符號。如果第一項的係數是負的，那該係數必須有-這個符號。例如：-7x^2 + 30x + 66 
若係數為負，則以減一個正數來表示（除了上面第6條所提到的第一項之外），而非以加一個負數來表示。例如：x^2 + -3x 這樣的表示法是錯誤的，應該是：x^2 - 3x才對。 
1或-1，除了常數項之外都不應該出現。例如：-1x^3 + 1x^2 + 3x^1 - 1 這樣的表示法是錯誤的，應該是：-x^3 + x^2 + 3x - 1 才對。 
Input

每組測試資料一列，含有9個整數（絕對值都小於1000）。

Output

對每一組測試資料，按照上面的規則輸出多項式。請參考Sample Output。

Sample Input

0    0    0    1   22 -333    0    1   -1
0    0    0    0    0    0  -55    5    0

Sample Output

x^5 + 22x^4 - 333x^3 + x - 1
-55x^2 + 5x

*/