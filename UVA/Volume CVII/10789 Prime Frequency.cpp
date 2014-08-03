/* 10789 Prime Frequency Accepted C++ 0.020 2011-01-26 07:40:44 */
#include<stdio.h>
int prime[1000];
int count;
void make_prime(){
	int i,j;	
	bool found;
	prime[0]=2;
	for(i=3,count=1;i<2001;i+=2){
		found=false;
		for(j=0;j<count&&!found;j++)
			if(i%prime[j]==0){
				found=true;
				break;}
		if(!found)
			prime[count++]=i;
	}		
}
int main(){
	make_prime();
	int t;
	while(scanf("%d",&t)==1){
		char c=getchar();
		bool empty;
		int i,k;		
		char str[2001];
		for(i=1;i<=t;i++){
			int j;
			int m[150]={0};			
			gets(str);
			for(j=0;str[j]!='\0';j++)
				m[str[j]]++;
			printf("Case %d: ",i);
			for(j=0,empty=true;j<150;j++)
				if(m[j]>0)
					for(k=0;k<count;k++)
						if(prime[k]==m[j]){
							empty=false;
							printf("%c",j);
						}
			if(empty)
				printf("empty");
			putchar('\n');
		}
	}
	return 0;
}
/*

給你一個只有數字及英文字母（0-9、A-Z及a-z）的字串，你需要計算每一個字元出現的頻率，並且判斷哪一個字元出現的頻率是質數。所謂的質數是指可以被 1 和自己整除的數，例如：2、3、5、7、11…等。

Input

輸入的第一列有一個整數 T （1＜T＜201），代表以下有多少組測試資料。

每組測試資料一列。每組測試資料只有數字及英文字母，測試資料的長度大於 0 且小於 2001 。

Output

對於每組測資請輸出一列，內容是出現頻率是質數的字元；輸出的順序必需依照 ASCII 值由小到大排列。請參考 sample input 及 sample output。

如果沒有任何字元的出現頻率是質數，請輸出 empty 。

Sample Input

3
ABCC
AABBBBDDDDD
ABCDFFFF

Sample Output

Case 1: C
Case 2: AD
Case 3: empty

*/