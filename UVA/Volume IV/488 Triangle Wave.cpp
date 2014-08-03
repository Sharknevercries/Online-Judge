/* 488 Triangle Wave Accepted C++ 0.332 2011-01-26 12:25:58 */
#include<stdio.h>
int main(){
	int n;	
	bool first;
	first=true;
	while(scanf("%d",&n)==1){
		if(!first)
			putchar('\n');
		first=false;
		int i,j,k,m;		
		bool data_first;
		data_first=true;		
		for(i=1;i<=n;i++){
			int a,f;			
			scanf("%d%d",&a,&f);
			for(j=1;j<=f;j++){
				if(!data_first)
					putchar('\n');
				data_first=false;
				for(k=1;k<=a;k++){
					for(m=1;m<=k;m++)
						printf("%d",k);
					putchar('\n');
				}
				for(k=a-1;k>=1;k--){
					for(m=1;m<=k;m++)
						printf("%d",k);
					putchar('\n');
				}	
			}
		}
	}
	return 0;
}
/*

在這個問題中，根據所給的振幅(Amplitude)及頻率(Frequency)，你的程式要產生這樣的波。

輸入說明 ：

輸入的第一列有一個整數n，代表有幾組測試資料。接下來每組測試資料有2列，各有1個正整數（A、F），A代表振幅（A<=9），F代表頻率。 第一列以及各組測試資料間皆有一空白行。請參考Sample input。

輸出說明 ：

每組測試資料請輸出F個波，每個波振幅的水平高度為A。波本身是以其"高度"的內容所組成。每個波之間以一空白行分隔開來。 測試資料間也以一空白行分開。 請參考sample output。

範例輸入 ： 

2

3
2
5
3

範例輸出 ：

1
22
333
22
1

1
22
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 488

*/