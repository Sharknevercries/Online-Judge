/* 10220 I Love Big Numbers ! Accepted C++ 0.056 2011-02-03 09:00:24 */
#include<stdio.h>
#include<string.h>
char str1[9999];
char str2[6];
char result[9999];
void mul(){
	int i,j,k,m,carry;
	int len_1,len_2;
	len_1=strlen(str1);
	len_2=strlen(str2);
	for(i=0;i<len_1+len_2+1;i++)
		result[i]='0';
	for(i=len_1-1;i>=0;i--)
		for(j=len_2-1;j>=0;j--){
			m=i+j+1;
			k=(str1[i]-'0')*(str2[j]-'0');
			carry=k/10;
			result[m]+=k%10;
			if(result[m]>'9'){
				carry++;
				result[m]-=10;}
			while(carry>0){
				result[m-1]+=carry;
				carry=0;
				if(result[m-1]>'9'){
					carry=(result[m-1]-'0')/10;
					result[m-1]=((result[m-1]-'0')%10+'0');}
				m--;
			}
		}
	result[len_1+len_2]='\0';
	if(result[0]=='0')
		for(i=0;result[i]!='\0';i++)
			result[i]=result[i+1];	
	strcpy(str1,result);		
}
int main(){
	int i,j;
	int sum;
	int p[1001];
	str1[0]='1';
	str1[1]='\0';		
	for(i=1;i<=1001;i++){
		for(j=sum=0;str1[j]!='\0';j++)
			sum+=str1[j]-'0';
		p[i-1]=sum;
		sprintf(str2,"%d",i);
		mul();}		
	int n;
	while(scanf("%d",&n)==1){
		printf("%d\n",p[n]);
	}
	return 0;
}
/*

有一個年輕的女孩走進一家科技中心，在那裡她遇到一個叫做阿強1號的機器人。這個女孩想要作弄一下機器人，就問他：「你會數學嗎？」『Yes，我愛數學』機器人回答。

「Okey! 那我就給你一個數，你要算出這個數的階層，然後告訴我所有數字的和是多少！假設這個數是5，你首先要計算5!=120，然後算出數字的和 1+2+0=3 。你能做到嗎？」

『Yes，我可以做到。』

「假設這個數是100，答案是多少？」這個時候機器人就開始思考和計算。經過幾分鐘後只看到阿強1號頭冒白煙，並大叫：『時間爆掉了！』

那女孩笑著對阿強1號說：答案是648. 說完後收起她的筆記型電腦揚長而去，留下阿強1號一臉的茫然。

你的任務就是要幫助阿強1號解決這個問題。

輸入說明 ：

輸入的每一行測試資料有1個整數 n（ a <= 1000）。

輸出說明 ：


對每一個輸入n，輸出n!的個數字總和。這個數一定小於231-1。

範例輸入 ： 

5
60
100
範例輸出 ：

3
288
648

提示 ：

* Luck 貓翻譯

出處 ：

ACM 10220 

*/