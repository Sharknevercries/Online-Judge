/* 541 Error Correction Accepted C++ 0.012 2011-02-17 12:34:41 */
#include<stdio.h>
int main(){
	int m[100][100];
	int n;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int i,j;
		int x,y;
		int sum;
		bool found_row,found_col;
		bool corrupt=false;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&m[i][j]);
		for(i=0,found_row=false;i<n&&!corrupt;i++){
			for(j=sum=0;j<n;j++) sum+=m[i][j];
			if((sum&1)==1)
				if(!found_row){	found_row=true;	x=i+1;}
				else 
					corrupt=true;}
		for(i=0,found_col=false;i<n&&!corrupt;i++){
			for(j=sum=0;j<n;j++) sum+=m[j][i];
			if((sum&1)==1)
				if(!found_col){	found_col=true;	y=i+1;}
				else	
					corrupt=true;}
		if(corrupt)
			puts("Corrupt");
		else if(found_row&&found_col)
			printf("Change bit (%d,%d)\n",x,y);
		else if(!found_row&&!found_col)
			puts("OK");
		else
			puts("Corrupt");
	}
	return 0;
}
/*

當一個布林矩陣每一行的和與每一列的和都是偶數的時候，我們稱這種性質為等價。

例如，下面是一個 4x4 的一個等價短陣。 

1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1

每一列的和分別是2,0,4,2；而每一行的和分別是2,2,2,2。

你的工作即是要寫個程式讀入矩陣且檢查他有沒有等價。如果沒有，你得檢查能不能在只改變一個位元的狀況下使他等價，如果不行，那這個矩陣就得歸類為損毀（corrupt）。

Input

輸入包含一或數個測資。
每個測資的第一列是一個整數 n ( n < 100 )，代表矩陣的大小；接下來的 n 列，每行有 n 個數字，即為矩陣。在矩陣中只會出現 0 及 1。當 n=0 時代表輸入結束。

Output

對於每一個矩陣請輸出一列。
如果該矩陣已經是等價的，請輸出OK；
如果經由改變第 i 列第 j 行的位元即可成為等價，請輸出Change bit (i,j)；
否則請輸出Corrupt。 

Sample Input

4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
0

Sample Output

OK
Change bit (2,3)
Corrupt

*/