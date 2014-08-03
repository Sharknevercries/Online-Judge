/* 700 Date Bugs Accepted C++ 0.012 2011-02-22 14:20:25 */
#include<stdio.h>
int main(){
	int k=1;
	int n;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int y[20],a[20],b[20];
		int i,j,gap,year,temp;
		bool found=false,wrong=false;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&y[i],&a[i],&b[i]);
		for(year=y[0],gap=b[0]-a[0];year<10000&&!found;year+=gap){
			wrong=false;
			for(j=1;j<n&&!wrong;j++){
				if(year<a[j])
					break;
				temp=year;
				while(!(temp>=a[j]&&temp<b[j])) // temp<b[j] 特別注意
					temp=temp-(b[j]-a[j]);
				if(temp!=y[j])
					wrong=true;}
			if(j>=n&&!wrong)
				break;}
		printf("Case #%d:\n",k++);
		if(year>=10000)
			puts("Unknown bugs detected.");
		else
			printf("The actual year is %d.\n",year);
		putchar('\n');
	}
	return 0;
}
/*

據說在公元2000年的時候許多電腦會有麻煩。這是因為這些電腦只用兩個數字紀錄年份，所以年份會從1999突然變成1900。事實上，有許多類似的狀況發生：某些系統使用32位元的整數儲存從某個特定日期到目前為止的秒數。以這樣的情形來看，2^32秒(大約136年)之後，日期將會跳回原本某個特定的日期。

想像一下你有兩台電腦C1和C2，而且這兩台電腦有不同的問題：一台有Y2K-Bug(也就是說 
b1:=2000 將會還原為 a1:=1900) 而另一台電腦在 b2:=2040的時候還原到 a2:=1904。假設電腦C1顯示的年份為 y1:=1941，C2顯示了 y2:=2005。那麼你可以推出以下結論(在沒有其他問題的狀況下)：真實年份顯然不可能是1941，因為如果是1941年的話照理來說兩台電腦應該要顯示一樣的年份。而若真實年份為2005，那麼C1應該要顯示1905，也不對。如果只觀察C1，我們知道真實年份應該是下列其中之一：1941, 2041, 2141...。這些年份如果在C2上顯示，應該會是：1941, 1905, 2005...。所以，事實上，實際的年份為2141。

手算實際年份是一個很麻煩的工作(相信你也不希望在你忘記真實年份的時候每次都要這樣算。)所以，你的工作就是寫一個程式，告訴你某些電腦顯示的年份以及每台電腦各自的問題(例如把bi年顯示成ai年)，找出第一個可能的實際年份。由於在電腦發明以後才有這樣的問題出現，所以你要找的實際年份應該在所有的ai之後。

Input

輸入檔案中包含了許多測試資料。每筆測試資料第一列包含了一個整數 n(1<=n<=20)，代表電腦的數量。接下來每列都顯示了一台電腦的資料，依序是yi,ai,bi (0<=ai<=yi<bi<10000)。yi是電腦顯示的年份，bi是會出現問題的第一年，而這年所顯示的年份回到了ai。 

Output

對於每筆測試資料，輸出一列 "Case #k:"，k代表第幾筆測試資料。接下來輸出一列``The actual year is z.''，z代表最小的可能實際年份(滿足所有電腦並且大於或等於 u = max{ai}。)如果不存在小於10000的可能年份，輸出``Unknown bugs detected.''。並且在每筆測試資料之後輸出一個空白列。請參考Sample Output。

Sample Input  

2
1941 1900 2000
2005 1904 2040
2
1998 1900 2000
1999 1900 2000
0

Sample Output

Case #1:
The actual year is 2141.

Case #2:
Unknown bugs detected.

--------------------------------------------------------------------------------

Translated by tmt

*/