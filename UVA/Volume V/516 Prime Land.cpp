/* 516 Prime Land Accepted C++ 0.052 2011-02-17 12:19:07 */
#include<stdio.h>
#define INT_MAX 2147483647
static int prime[10000];
static int index;
int power(int x,int y){
	int temp;
	if(x==1||y==0)
		return 1;
	else if(y==1)
		return x;
	else if((y&1)==0){
		temp=power(x,y/2);
		return temp*temp;}
	else
		return x*power(x,y-1);
}
void make_prime(){
	int i,j;
	prime[0]=2;
	index=1;
	for(i=3;i<=32767;i+=2){
		for(j=0;j<index&&i%prime[j]!=0;j++);
		if(j>=index) prime[index++]=i;
	}
}
int main(){
	make_prime();
	int s,m;
	char c;
	int sum=1;
	while(scanf("%d",&s)==1){
		if(s==0) break;
		scanf("%d",&m);
		c=getchar();
		sum*=power(s,m);
		if(c=='\n'){
			int min=INT_MAX;
			int i,max;
			int count[10000]={0};
			for(i=max=0,sum-=1;sum>1;i++,max++)
				while(sum%prime[i]==0){					
					count[i]++;
					sum/=prime[i];}
			for(i=0;min>prime[i];i++)
				if(count[i]>0)	
					min=prime[i];
			for(i=max-1;i>=0;i--)
				if(count[i]>0)
					if(min==prime[i])
						printf("%d %d\n",prime[i],count[i]);
					else
						printf("%d %d ",prime[i],count[i]);}
	}
	return 0;
}
/*

在質數國中人們使用以質數為基底的數字系統來表達一個整數。若以我們的觀點來看的話，就是每一個大於1的整數X都用唯一的因數分解的形式來表現。即 

X = Pkex * ...... * P1e1 * P0e0 

例如：我們的整數40在質數國中以：5 1 2 3來表示。（表示5的1次方乘以2的3次方） 

這樣的系統對我們來說實在是不尋常，或者說，有點難。事實上，在質數國中的小朋友需要花好幾年來學習加法和減法，但另一方面，乘法及除法對他們來說卻是很容易的。現在你的任務就是幫質數國的人寫一個程式對一個數做"減1"的動作，然後輸出結果。當然，輸入輸出都是以質數國的數字系統來表示（對我們來說也就是因數分解的形式）。 

Input

每組測試資料一列，每列有一個X（2 < X <= 32767）的因數分解式。最後一列僅有一個0，代表輸入結束，此列不需輸出。

Output

對每組測試資料輸出一列 X-1 的因數分解式，數字間均有一空白。請參考Sample Output。

Sample Input

17 1
5 1 2 1
509 1 59 1
0

Sample Output

2 4
3 2
13 1 11 1 7 1 5 1 3 1 2 1

*/