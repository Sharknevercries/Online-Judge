/* 482 Permutation Arrays Accepted C++ 0.012 2011-02-16 11:48:35 */
#include<stdio.h>
char m[100000][100];
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		bool first=true;
		for(i=1;i<=n;i++){
			if(!first)
				putchar('\n');
			else first=false;			
			int temp[10000]={0};
			int j,max;
			char c;
			max=j=0;
			while(scanf("%d%c",&temp[j++],&c)==2){
				if(max<temp[j-1])
					max=temp[j-1];
				if(c=='\n') break;}
			j=0;
			while(scanf("%s%c",&m[temp[j++]-1],&c)==2)
				if(c=='\n')	break;
			for(j=0;j<max;j++)
				printf("%s\n",m[j]);
		}
	}
	return 0;
}
/*

在很多電腦問題中，常常會把一個陣列的資料做一些搬動。也就是說陣列中的資料被重新排列。有一個排列陣列資料的方法是用另一個稱為索引陣列（index array）來完成的。假設x是要被重新排列的陣列，而x'是重新排列後的陣列，那麼應該有一個關係存在於x和x'之間，使得x'i=xpi，而索引陣列就是記載這個關係用的。

為了避免誤解題意，以第一組Sample Input, Sample Output說明：索引陣列為3 1 2，代表接下來的浮點數應該分別輸出於第3列、第1列、第2列。

Input

輸入的第一列有一個整數，代表以下有幾組測試資料。每組測試資料2列，第1列為索引陣列，包含了 1~n 的整數（以某一種排列方式出現），在這裡n就是陣列中資料的數目。第2列則包含了n個浮點數。測試資料間空一列。請參考Sample Input

Output

對每一組測試資料根據索引陣列的順序輸出浮點數，每一個浮點數一列，且浮點數的樣式必須和輸入的一樣。測試資料間亦請空一列。

Sample Input

2

3 1 2
32.0 54.7 -2

3 2 1
32.0 54.7 -2

Sample Output

54.7
-2
32.0

-2
54.7
32.0

*/