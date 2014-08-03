/* 10924 Prime Words Accepted C++ 0.012 2011-01-28 13:11:23 */
#include<stdio.h>
int prime[500];
int total;
void make_prime(){
	int i,j;	
	bool IS;
	prime[0]=1;
	prime[1]=2;
	total=2;
	for(i=3,IS=true;i<1040;i+=2,IS=true){
		for(j=1;j<total;j++)
			if(i%prime[j]==0){
				IS=false;
				break;}
		if(IS)
			prime[total++]=i;
	}
}
int main(){
	make_prime();
	char str[25];
	while(gets(str)){
		int i;
		int sum;
		bool found;
		for(sum=i=0;str[i]!='\0';i++)
			if(str[i]>='a'&&str[i]<='z')
				sum+=str[i]-'a'+1;
			else
				sum+=str[i]-'A'+27;
		for(i=0,found=false;i<total;i++)
			if(prime[i]==sum){
				puts("It is a prime word.");
				found=true;
				break;}
		if(!found)
			puts("It is not a prime word.");
	}
	return 0;
}
/*

質數就是一個數字只有兩個因數：1和自己，例如：1,2,3,5,17,101和10007都是質數。

在這問題中你需要讀入一組文字，每個字是由 a-z 和 A-Z 組成，每個字母都有他的值，字母 a 值 1，字母 b 值 2 ... 到字母 z 值 26，同樣的字母 A 值 27，B 值 28， Z 值 52。

你應該要寫個程式來檢查這組字是不是prime word，如果這組文字的字母值總和為質數的話，他就是 prime word。

輸入說明 ：

輸入含有多組測試資料，每組一列，且有 L （1 <= L <= 20）個字母。請參考Sample Input。

輸出說明 ：

對每一組字，如果它是 prime word 的話，輸出 "It is a prime word."。否則，請輸出 "It is not a prime word."。

範例輸入 ： 

UFRN
contest
AcM
a
A

範例輸出 ：

It is a prime word.
It is not a prime word.
It is not a prime word.
It is a prime word.
It is not a prime word.

提示 ：

Lucky 貓 英 中

出處 ：

UVa ACM 10924 (作者：snail) 

*/