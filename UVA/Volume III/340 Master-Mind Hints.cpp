/* 340 Master-Mind Hints Accepted C++ 0.028 2011-02-12 08:39:24 */
#include<stdio.h>
void check(int pass[],int guess[],int n){
	int i,j;
	int a,b;
	int used_p[1000]={false};
	int used_g[1000]={false};
	for(i=a=0;i<n;i++)
		if(pass[i]==guess[i]){
			a++;
			used_p[i]=used_g[i]=true;}
	for(b=i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(!used_p[i]&&!used_g[j])
				if(pass[i]==guess[j]){
					b++;
					used_p[i]=used_g[j]=true;}
	printf("    (%d,%d)\n",a,b);
}
int main(){
	int n;
	int count=1;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int password[1000];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&password[i]);
		printf("Game %d:\n",count++);
		while(true){
			int guess[1000];
			for(i=0;i<n;i++)
				scanf("%d",&guess[i]);
			if(guess[0]==0) break;
			check(password,guess,n);
		}
	}
	return 0;
}
/*

Master-Mind是一種2個人的遊戲。其實就是學生常玩的幾A幾B的遊戲（規則或許有些許不同）。其中一個人擔任出題者，他選一串1到9數字當作密碼（可以重複）。另一個人為解題者，他要去猜密碼為何。解題者每次猜測後，出題者以某種格式回答他這次猜的結果。

在遊戲開始之前，雙方先協議密碼的長度，假設是n。在出題者設定密碼（s1,s2,...sn）後，由解題者來猜（g1,g2,...gn）。如果同樣位置gi=si，那解題者得到一個A。如果gi=sj，但i不等於j，那解題者得到一個B。請注意：不管是得A或得B，每個gi最多只能對應到一個sj，而且得A比得B優先。舉例說明：密碼為1 2 3 4，若猜題者猜1 1 5 6，那出題者應該回答1A0B，而不是0A1B。

如果某個猜測得到 nA0B，那就代表猜題者完全猜中密碼了。

Input

輸入含有多組測試資料。每組測試資料的第一列含有1個正整數N，代表密碼的長度。第二列有N個1到9的數字，代表密碼。接下來有數量不等的猜測，每個一列，亦含有N個1到9的數字。若此猜測的N個數字均為0，代表此組測試資料結束。

N=0代表整個輸入結束。請參考Sample Input。

Output

對每一組測試資料，輸出這是第幾組。然後輸出出題者回答猜題者各個猜測的結果是幾A幾B，以（A,B）的形式表示。請參考Sample Output。

Sample Input

4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0

Sample Output

Game 1:
    (1,1)
    (2,0)
    (1,2)
    (1,2)
    (4,0)
Game 2:
    (2,4)
    (3,2)
    (5,0)
    (7,0)

*/