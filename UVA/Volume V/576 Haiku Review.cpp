/* 576 Haiku Review Accepted C++ 0.016 2011-02-03 06:59:50 */
#include<stdio.h>
#include<string.h>
int main(){
	char str[205];
	while(gets(str)){
		if(strcmp(str,"e/o/i")==0)
			break;
		int i,j,k;
		int base[]={5,7,5};
		bool YES;
		bool dou; 
		for(i=1,j=0,k=0,YES=true;i<=3;i++,j++,k=0){
			dou=false;
			for(;str[j]!='/'&&str[j]!='\0';j++){
				if(str[j]!='a'&&str[j]!='e'&&str[j]!='i'&&str[j]!='o'&&str[j]!='u'&&str[j]!='y')
					dou=false;
				else if(str[j]!=' '){
					if(!dou)
						k++,dou=true;}
				else
					dou=false;}
			if(k!=base[i-1]){
				printf("%d\n",i);
				YES=false;
				break;}
		}
		if(YES)
			puts("Y");
	}
	return 0;
}
/*

Haiku（俳句）是日本古代的一種詩詞。他是由五音節、七音節、五音節之三句共17音節所組成之短詩。Haiku不需要押韻。以下是一個例子，句子間以斜線分開：

Computer programs/The bugs try to eat my code/I must not let them.

你的任務是寫一個程式，讀進一首haiku，並檢查其音節。

輸入說明 ：

每組測試資料一列Haiku，一定含有3個句子，每個句子至少含有1個字，字與字間以一空白字元或斜線分隔。斜線也是用來分隔句子的，所以一列中一定含有2個斜線。Haiku只含有小寫的英文字母（a~z），斜線，空白字元。每列的長度不會超過200個字元。

輸入列為e/o/i代表輸入結束。請參考Sample Input。

你的認識是判斷每個句子是否有正確的音節（5/7/5）。在本問題中，一個音節指的是連續的母音字母形成的字元序列。母音字母包含a,e,i,o,u,y。每個字至少包含一音節。

注意：在這裡算音節的方式跟英文念法並不一致。例如在以下第2個sample input中，code這個字在本程式中應該算為2個音節，因為o和e並不連續。然而，若以英文念code這個字其實只有一個音節。

輸出說明 ：

對每一組測試資料，如果此Haiku不正確，請輸出第一個含有不對音節個數的句子是哪一個。（也就是說：若第一個句子的音節個數不對，請輸出1。否則，若 第二個句子的音節個數不對，請輸出2。否則，若第三個句子的音節個數不對，請輸出3。）若三個句子音節的個數全對則請輸出Y。

範例輸入 ： 

happy purple frog/eating bugs in the marshes/get indigestion
computer programs/the bugs try to eat my code/i will not let them
a e i o u/this is seven syllables/a e i o u y
e/o/i

範例輸出 ：

Y
2
3

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 576 

*/