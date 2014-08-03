/* 665 False coin Accepted C++ 0.012 2011-02-21 14:10:21 */
#include<stdio.h>
#define HEAVY 'H'
#define LIGHT 'L'
int main(){	
	int m;
	while(scanf("%d",&m)==1){
		int i;
		bool first=true;
		for(i=1;i<=m;i++){
			char alpha;
			char record[100][100];
			bool ac[100]={false}; // 為真的硬幣
			bool found=false;
			bool no_answer=false;
			int temp[100]={0}; // 暫存輸入之硬幣
			int index[100]={0}; // record某硬幣之結果
			int result;
			int n,k;
			int max; // 記錄index最高值
			scanf("%d%d",&n,&k);
			int j,pi,t,e;
			for(j=1;j<=k;j++){
				scanf("%d",&pi);
				for(t=0;t<pi*2;t++)
					scanf("%d",&temp[t]);
				alpha=getchar();
				scanf("%c",&alpha);
				if(alpha=='=')
					for(t=0;t<pi*2;t++)
						ac[temp[t]-1]=true;
				else if(alpha=='<'){
					for(t=0;t<pi;t++)
						record[temp[t]-1][index[temp[t]-1]++]=LIGHT;
					for(;t<2*pi;t++)
						record[temp[t]-1][index[temp[t]-1]++]=HEAVY;}
				else{
					for(t=0;t<pi;t++)
						record[temp[t]-1][index[temp[t]-1]++]=HEAVY;
					for(;t<2*pi;t++)
						record[temp[t]-1][index[temp[t]-1]++]=LIGHT;}
			}
			for(j=max=0;j<n;j++)
				if(max<index[j])
					max=index[j];
			for(j=t=0;j<n;j++) 
				if(!ac[j]){
					t++; e=j;}
			if(t==1){ // 若僅有一個不確定，則即是該硬幣
				found=true;
				result=e+1;}
			for(j=max;j>=0&&!no_answer;j--) // 自次數最高開始查起
				for(t=0;t<n&&!no_answer;t++)
					if(index[t]==j&&!ac[t]){ // 只比較未確認之硬幣且次數符合j
						for(e=1;e<index[t]&&record[t][0]==record[t][e];e++) // 若該硬幣所有結果為一致
						if(e>=index[t]) // 則該硬幣即是所求
							if(!found){ // 若有兩個皆為如此，則無解
								result=t+1;
								found=true;}
							else
								no_answer=true;}
			if(!first)
				putchar('\n');
			else first=false;
			if(no_answer||!found)
				puts("0");
			else
				printf("%d\n",result);

		}
	}
	return 0;
}
/*

「金條」銀行根據可靠消息，他們的最後一批（有N個）硬幣裡有一個是假的，而且它的重量和真的不同（每個真的硬幣都一樣重）。在金融危機之後，他們只剩下如上圖的天平。那個天平能用來確定左邊盤子裡的東西比右邊的重、輕、還是一樣。

為了找出假幣，銀行職員把所有的硬幣編號（從 1 到 N ），然後他們就開始秤重了。他們每次都把左右放一樣多的硬幣，然後記錄硬幣的編號以及秤重結果。

你要寫一個程式幫他們找出假的硬幣。
 
輸入說明 ：

輸入的第一列有一個整數 M，代表以下有幾組測試資料。

每組測試資料的第一列有2個整數 N 和 K。N 代表硬幣的數量（1 <= N <= 100），K 是秤重的次數（1 <= K <= 100）。接下來的 2K 列描述秤重，每連續的2列是一次秤重。前一列開始有一個數Pi（1 <= Pi <= N/2），代表這次秤重每邊放的硬幣個數，接下來的前 Pi個數字是左邊的硬幣號碼，後 Pi 個數字是右邊的硬幣號碼。後一列用 <, >, 或 = 表示秤重的結果。

•< 表示左邊比右邊的輕
•> 表示左邊比右邊的重
•= 表示兩邊一樣重
輸入的第一列與第一組測試資料，以及各組測試資料間均有一空白列。請參考Sample Input。

輸出說明 ：

對每一組測試資料輸出哪一個硬幣是假的。如果秤重的結果無法找出假幣，請輸出 0。

測試資料間亦請輸出一空白列，請參考Sample Output。

範例輸入 ： 

2

5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=

4 2
1 1 2
<
1 3 4
=

範例輸出 ：

3

0

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 665 

*/