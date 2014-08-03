/* 130 Roman Roulette Accepted C++ 0.016 2011-02-09 11:48:17 */
#include<stdio.h>
void initial(int m[],int p[],int n){
	int i;
	for(i=0;i<n-1;i++)
		p[i]=m[i]=i+1;
	m[n-1]=0;
	p[n-1]=n;
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		if(n==0&&k==0)
			break;
		int i,j,e,count,t;
		int pre_e,pre_j;
		int total;
		int p[100]; //  人的編號
		int m[100]; //  環狀鍵結
		bool killed=false; // No.1 被殺?		
		i=0;
		while(true){
			total=n; // 總人數
			if(total==1) break;
			initial(m,p,n);			
			j=i;
			e=(i-1>=0)?i-1:n-1;
			while(!killed){
				for(pre_j=e,j=m[e],count=1;count!=k;pre_j=j,j=m[j],count++); // 找出下一個要被殺的人
				for(pre_e=j,e=m[j],count=1;count!=k;pre_e=e,e=m[e],e!=j?count++:0); // 找出埋葬者
				if(p[j]==1){ killed=true; break; }
				total--;
				if(total==1) break;
				m[pre_j]=m[pre_e]; // 被殺之人的前一個之鍵結接到埋葬者
				m[pre_e]=m[e]; // 埋葬者的前一個之鍵結接到埋葬者的下一個人
				m[e]=m[j]; // 埋葬者之鍵結接到被殺之人的鍵結
			}
			if(!killed)			
				break;	
			i++;
			killed=false;
		}
		printf("%d\n",i+1);
	}
	return 0;
}
/*

西元67年，在羅馬和猶太人的衝突中，史學家 Josephus 和其他40個人被關在一個洞穴中。羅馬人知道 Josephus 的下落後希望他能投效羅馬帝國。但是他的同伴們卻不允許他投降。所以Josephus 建議他們彼此殺害，一個接一個，被殺的順序就由命運決定。傳統上他們決定命運的方式為：大家圍成一個圓圈，從某個人開始算起，每算到 3 個人那個人就被殺掉，如此不斷下去，直到只剩一個人。後來 Josephus 成為唯一的存活者並投降羅馬。我們有興趣的是：Josephus 如何剛好是那個存活者？真的是運氣好，還是他事先在暗地裡用 41 顆石頭練習過，或者他有一個數學的方法可以知道要站在哪一個位置才能成為最後的存活者？

聽過這個故事後，你相當的憂心要是將來某一天你也面臨同樣的情況要怎麼辦。所以你決定用你的手上型電腦寫一個程式算出應該從那個人開始算起，你才可以成為那個最後唯一存活的人。

在這個問題中，你的程式必須能解決 Josephus 描述的另一種變形。有 n 個人排成一個圓圈，面向內，依順時鐘方向編號從 1 到 n。你的位置在 1 。殺人程序由編號 i 的人開始算起（順時鐘方向），直到算到第 k 個人，那個人立刻被殺掉。然後從這個被殺的人左邊的那個人再順時鐘方向算 k 個人，那個人必須負責埋葬剛才被殺的那個人，然後回去站在剛才被殺的那個人的位置。接下來從這個人的左邊那個人算起，第 k 個人又被殺掉，如此一直下去直到只剩下一個人為止。

例如：當 n=5, k=2, i=1, 那麼被殺的順序為 2, 5, 3, 1，存活者為4。

Input

輸入含有多組測試資料。

每組測試資料有2個整數 n, k 。你可以假設最多只有 100 個人。

若 n =  k = 0 時代表輸入結束。請參考Sample Input。

Output

對每組測試資料輸出一開始時應該從哪一個人算起（也就是 i），才能確保你是最後唯一的存活者。請記住：你的位置在 1。以上述的例子來看，必須由第 3 個人算起，最後存活的人才能是 1 。

Sample Input 

1 1
1 5
5 2
5 4
7 3
100 53
100 2
11 93
0 0

Sample Output 

1
1
3
5
1
13
83
2

*/