/* 612 DNA Sorting Accepted C++ 0.136 2011-02-21 11:01:07 */
#include<stdio.h>
#include<string.h>
int main(){
	int d,n,m;
	while(scanf("%d",&d)==1){
		int t;
		bool first=true;
		for(t=1;t<=d;t++){
			scanf("%d%d",&n,&m);
			int count[100]={0};
			char str[100][51];
			int i,j,k,max;
			for(i=0;i<m;i++)
				scanf("%s",str[i]);
			for(i=max=0;i<m;i++)
				for(j=0;str[i][j]!='\0';j++){
					if(str[i][j]=='A') continue;
					for(k=j+1;str[i][k]!='\0';k++)
						if(str[i][j]>str[i][k]){
							count[i]++;
							if(count[i]>max)
								max=count[i];}
				}
			if(!first)
				putchar('\n');
			else first=false;
			for(i=0;i<=max;i++)
				for(j=0;j<m;j++)
					if(count[j]==i)
						printf("%s\n",str[j]);
		}
	}
	return 0;
}
/*

在一個字串中，「未排序」的程度是以各字元間彼此的大小關係來計算的。例如在字串 DAABEC中，「未排序」的程度為 5，因為D比它右邊的4個字元大，E比它右邊的1個字元大。而字串AACEDGG「未排序」的程度為 1（幾乎是快排序好的，唯一的未排序發生在E和D之間），字串ZYXW「未排序」的程度為 6（剛好是完全排序的相反）。

現在你的任務是為許多的DNA字串來做排序。每個字串中僅含有A,C,G和T這4種字元。排序的原則是根據各字串「未排序」的程度，由小到大輸出。在這裡每個字串的長度均相同。

Input

輸入的第一列有一個整數代表以下有幾組測試資料。每組測試資料的第一列含有2個正整數 n（0 < n <= 50）和 m（0 < m <= 100），n 代表字串的長度，m 代表字串的數目。接下來的 m 列，每列有一個長度為 n 的字串。

第一列及第一組測試資料，以及各組測試資料間均有一空白列。請參考Sample Input。

Output

對每組測試資料按照「未排序」的程度，由小到大輸出各字串。假如有不只2個字串「未排序」的程度相同，則按照它們在輸入中的順序輸出。

各組測試資料之間請輸出一空白列，輸出格式請參考Sample Output。

Sample Input  

2

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

2 3
TC
TT
TA

Sample Output

CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

TT
TC
TA
 
*/