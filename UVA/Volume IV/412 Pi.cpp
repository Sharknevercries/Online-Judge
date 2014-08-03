/*  412 Pi Accepted C++ 0.108 2011-02-15 14:36:11 */
#include<stdio.h>
#include<math.h>
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
int main(){
	int n;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int m[50];
		int total,count;
		int i,j,k;
		int a,b,c;
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(m[i]>m[j])
					SWAP(m[i],m[j]);
		for(i=count=0;i<n;i++)
			for(j=i+1;j<n;j++){ // 原本式建質數表去求，沒想到輾轉比較快，還快的好多...
				a=m[j];
				b=m[i];
				do{
					c=a%b;
					a=b;
					b=c;
				}while(c!=0);
				if(a==1)
					count++;}
		total=n*(n-1)/2;
		double pi=sqrt((double)total*6/count);
		if(count==0)
			puts("No estimate for this data set.");
		else
			printf("%.6lf\n",pi);
	}
	return 0;
}
/*

英國一個大學教授Robert A.J. Matthews根據夜空中劃過天際的星星的位置，讓人驚訝的推論出關於Pi（原週率）的準確度。當然，這牽扯到數論的理論及應用。在此，我們沒有夜空，但是我們要用相同的理論來估計Pi的值：

從一個數量龐大的數的集合中隨機的取2個數，這2個數互質（就是沒有比1大的公因數）的機率是:

例如：假設一個數的集合為{2,3,4,5,6}，可以形成10對數。其中(2,3), (2,5), (3,4), (3,5), (4,5), (5,6)這6對數互質。所以我們可以推出：

在這個問題中，給你一些數，要請你估計出Pi的值。

Input

輸入包含多組測試資料。每組測試資料的第一列有一個正整數N（1 < N < 50），代表集合中元素的個數。接下來的N列每列各有一個正整數，代表此集合中的數。這些數都大於0，並且小於32768。

N=0代表輸入結束。請參考Sample Input。

Output

對每一組測試資料，輸出你所估計Pi的值，四捨五入到小數點後6位。如果沒有任何一對數互質，請輸出No estimate for this data set.

請參考Sample Output。

Sample Input

5
2
3
4
5
6
2
13
39
0

Sample Output

3.162278
No estimate for this data set.

*/