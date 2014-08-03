/* 10903 Rock-Paper-Scissors Tournament Accepted C++ 0.184 2011-01-31 05:06:31 */
#include<stdio.h>
#include<string.h>
int main(){
	int n,k;
	bool first;
	first=true;
	while(scanf("%d%d",&n,&k)==2){		
		if(n==0)
			break;
		if(!first)
			putchar('\n');
		else first=false;
		char c=getchar();
		int total=k*n*(n-1)/2;
		int i;
		int win[1000]={0};
		int lose[1000]={0};
		int m1,m2;
		char p1[10],p2[10];	
		for(i=1;i<=total;i++){
			scanf("%d%s%d%s",&m1,p1,&m2,p2);
			if(strcmp(p1,p2)==0)
				continue;
			else 
				switch(p1[0]){
				case 'r':
					switch(p2[0]){
					case 'p': win[m2]++,lose[m1]++; break;
					case 's': win[m1]++,lose[m2]++; break;}
					break;
				case 'p':
					switch(p2[0]){
					case 'r': win[m1]++,lose[m2]++; break;
					case 's': win[m2]++,lose[m1]++; break;}
					break;
				case 's':
					switch(p2[0]){
					case 'r': win[m2]++,lose[m1]++; break;
					case 'p': win[m1]++,lose[m2]++; break;}
					break;}}
		for(i=1;i<=n;i++)
			if(win[i]+lose[i]==0)
				puts("-");
			else
				printf("%.3lf\n",(double)win[i]/(win[i]+lose[i]));
	}
	return 0;
}
/*

剪刀石頭布是個 2 個人玩的遊戲，玩家各選剪刀、石頭、布其中之ㄧ，剪刀贏布，布贏石頭，石頭贏剪刀，一樣就算平手。

現在總共有 n 個玩家，每個玩家要與其他人比賽 k 場，總共也就是 k*n*(n-1)/2 場比賽，你的任務就是計算每個玩家的勝率，勝率的定義是 w/(w+l)，w 是勝場數，l 是敗場數。

Input

輸入含有多組測試資料，每組測試資料的第1列包含2個整數 n和 k（ 1<= n,k <= 100），n, k如上面的定義，下面的 k*n*(n-1)/2 列，每一列代表一場比賽，包含了p1 ,m1, p2, m2，1<= p1,p2 <= n （p1, p2 代表玩家號碼，p1不會等於 p2），m1, m2各代表 p1, p2 出的拳 （"rock", "scissors",或 "paper"）。

當 n=0 代表輸入結束。請參考Sample Input。

Output

輸出每個玩家的勝率（四捨五入到小數點下3位），1人1列，如果勝率無意義，輸出 "-"。測試資料間請空一列。

Sample Input  
2 4
1 rock 2 paper
1 scissors 2 paper
1 rock 2 rock
2 rock 1 scissors
2 1
1 rock 2 paper
3 1
1 rock 3 rock
2 paper 1 scissors
2 paper 3 paper
0

Sample Output

0.333
0.667

0.000
1.000

1.000
0.000
-

*/