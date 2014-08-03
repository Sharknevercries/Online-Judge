/* 350 Pseudo-Random Numbers Accepted C++ 1.420 2011-02-12 09:55:44 */
#include<stdio.h>
int main(){
	int z,i,m,l;
	int count=1;
	while(scanf("%d%d%d%d",&z,&i,&m,&l)==4){
		if(z==0&&i==0&&m==0&&l==0)
			break;
		int index[10000]={0};
		int len[10000]={0};
		bool app[10000]={false};
		int max=0;
		while(true){
			if(!app[l]){
				index[max++]=l;
				app[l]=true;}
			else
				break;		
			for(int j=0;j<max;j++)
				if(app[index[j]])
					len[index[j]]++;			
			l=(z*l+i)%m;}
		printf("Case %d: %d\n",count++,len[l]);
	}
	return 0;
}
/*

電腦無法產生真正的亂數（Random numbers），但是經由某些程序電腦可以產生虛擬亂數（pseudo-random numbers）。亂數被使用在很多應用上，像是模擬等。

有一種常用的虛擬亂數產生方法：如果上一個亂數是L，那下一個亂數產生的方法是
(Z*L+I) mod M，在這裡Z、I、M都是常數。例如：假設Z=7 I=5 M=12。如果第一個亂數（通常叫做 seed）是 4 , 那我們可以產生以下幾個虛擬亂數:



我們可以發現，經過6個數字後，虛擬亂數的序列重複了，也就是說cycle length=6。
在這個問題中，你將會被給Z、I、M還有L（就是seed）的值（全部不大於9999）,對每一組Z、I、M、L，要請你輸出所產生的虛擬亂數的cycle length。
請注意：cycle並不一定從seed開始。

Input

輸入的每一行有4個整數,依序為Z, I, M, L。（L一定比M小）
輸入的最後一行為4個0，代表輸入結束。

Output

對每一行輸入，輸出這是第幾組測試資料（連續數字，從1開始）和所產生的虛擬亂數的cycle length。

Sample Input

7 5 12 4
5173 3849 3279 1511
9111 5309 6000 1234
1079 2136 9999 1237
0 0 0 0

Sample Output

Case 1: 6
Case 2: 546
Case 3: 500
Case 4: 220

*/