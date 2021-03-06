/* 101 The Blocks Problem Accepted C++ 0.012 2011-02-01 15:49:27 */
#include<stdio.h>
#include<string.h>
void move_onto(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,k;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos
	for(;index[pos[a]]-1>ap;index[pos[a]]--){
		k=m[pos[a]][index[pos[a]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos
	for(;index[pos[b]]-1>bp;index[pos[b]]--){
		k=m[pos[b]][index[pos[b]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	m[pos[b]][index[pos[b]]++]=m[pos[a]][--index[pos[a]]];
	pos[a]=pos[b];
}
void move_over(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,k;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos
	for(;index[pos[a]]-1>ap;index[pos[a]]--){
		k=m[pos[a]][index[pos[a]]-1];
		pos[k]=k;
		m[k][index[k]++]=k;}
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos	
	m[pos[b]][index[pos[b]]++]=m[pos[a]][--index[pos[a]]];	
	pos[a]=pos[b];
}
void pile_onto(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,j,k;
	int line;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos	
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos
	for(;index[pos[b]]-1>bp;index[pos[b]]--){
		k=m[pos[b]][index[pos[b]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	for(i=index[pos[a]],j=ap,line=pos[a];i>j;j++){
		k=m[line][j];
		m[pos[b]][index[pos[b]]++]=k;
		pos[k]=pos[b];
		index[line]--;}
}
void pile_over(int a,int b,int m[][25],int index[],int pos[]){
	int ap;
	int i,j,k;
	int line;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos		
	for(i=index[pos[a]],j=ap,line=pos[a];i>j;j++){
		k=m[line][j];
		m[pos[b]][index[pos[b]]++]=k;
		pos[k]=pos[b];
		index[line]--;}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		char str1[10],str2[10];
		int pos[25];
		int m[25][25];
		int index[25];
		int a,b;
		int i,j;
		for(i=0;i<n;i++){
			index[i]=1;
			m[i][0]=i;
			pos[i]=i;}
		while(scanf("%s",str1)==1&&strcmp(str1,"quit")!=0){
			scanf("%d %s%d",&a,str2,&b);
			if(pos[a]==pos[b])
				continue;
			if(strcmp(str1,"move")==0)
				if(strcmp(str2,"onto")==0)
					move_onto(a,b,m,index,pos);
				else
					move_over(a,b,m,index,pos);
			else
				if(strcmp(str2,"onto")==0)
					pile_onto(a,b,m,index,pos);
				else
					pile_over(a,b,m,index,pos);}
		for(i=0;i<n;i++){
			printf("%d:",i);
			for(j=0;j<index[i];j++)
				printf(" %d",m[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
/*

在早期人工智慧的領域中常常會用到機器人，在這個問題中有一支機器手臂接受指令來搬動積木，而你的任務就是輸出最後積木的情形。

一開始在一平坦的桌面上有n塊積木（編號從0到n-1）0號積木放在0號位置上，1號積木放在1號位置上，依此類推，如下圖。

機器手臂有以下幾種合法搬積木的方式（a和b是積木的編號）：

•move a onto b
在將a搬到b上之前，先將a和b上的積木放回原來的位置（例如：1就放回1的最開始位罝）
•move a over b
在將a搬到b所在的那堆積木之上之前，先將a上的積木放回原來的位罝（b所在的那堆積木不動）
•pile a onto b
將a本身和其上的積木一起放到b上，在搬之前b上方的積木放回原位
•pile a over b
將a本身和其上的積木一起搬到到b所在的那堆積木之上
•quit
動作結束
前四個動作中若a=b，或者a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略，也就是對各積木均無改變。

輸入說明 ：

輸入含有多組測試資料，每組測試資料的第一列有一個正整數n（0 < n < 25），代表積木的數目（編號從0到n-1）。接下來為機器手臂的動作，每個動作一列。如果此動作為 quit ，代表此組測試資料輸入結束。你可以假設所有的動作都符合上述的樣式。請參考Sample Input。

輸出說明 ：

每組測試資料輸出桌面上各位置積木的情形（每個位置一列，也就是共有n列），格式請參考Sample Output。

範例輸入 ： 

10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
4
pile 0 over 1
pile 2 over 3
move 1 onto 3
quit

範例輸出 ：

0: 0
1: 1 9 2 4
2:
3: 3
4:
5: 5 8 7 6
6:
7:
8:
9:
0: 0
1:
2: 2
3: 3 1

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 101 

*/