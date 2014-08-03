/* 591 Box of Bricks Accepted C++ 0.012 2011-01-26 11:46:01 */
#include<stdio.h>
int main(){	
	int n,data;	
	data=1;
	while(scanf("%d",&n)==1&&n!=0){
		int i,sum,total;
		int m[50];
		for(i=sum=0;i<n;i++){
			scanf("%d",&m[i]);
			sum+=m[i];
		}		
		sum/=n;			
		for(i=total=0;i<n;i++)
			if(sum>m[i])
				total+=sum-m[i];
			else
				total+=m[i]-sum;
		total/=2;
		printf("Set #%d\n",data++);
		printf("The minimum number of moves is %d.\n",total);
		putchar('\n');		
	}
	return 0;
}
/*

3歲的小明喜歡玩他的方塊積木，他總是把方塊疊在一起形成高度不一的方塊堆。然後他說：這是一面牆。5歲的姊姊小美聽到了就跟小明說：真正的牆高度應該要一樣才行。小明聽了覺得有道理於是決定要搬動一些方塊使所有方塊堆的高度一樣。如下圖。由於小明是個懶惰的小孩，他想要搬動最小數目的方塊以達成這個目的，你能幫助他嗎？

Input

輸入包含好幾組資料，每組資料有2行，第一行有一個數字n，代表有幾堆方塊。第二行有n個數字分別代表這n堆方塊的高度hi。你可以假設1<=n<=50  1<=hi<=100
方塊的總數一定可以整除堆數n，也就是說一定可以使所有的方塊堆同樣高度。
如果輸入的n=0，代表輸入結束。  

Output

對每一組輸入資料，首先輸出一行這是第幾組測試資料，下一行為"The minimum number of moves is k." k在這裡就是需搬動方塊最小的數目以使所有的方塊堆同一高度。每組測試資料後亦請空一行。請參考Sample Output.  

Sample Iutput

6
5 2 4 1 7 5
3
1 1 1
0

Sample Output

Set #1
The minimum number of moves is 5.

Set #2
The minimum number of moves is 0.

*/
