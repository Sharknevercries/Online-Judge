/* 145 Gondwanaland Telecom Accepted C++ 0.016 2011-02-09 12:49:13 */
#include<stdio.h>
void initial(double *day,double *eve,double *nig,char c){
	switch(c){
		case 'A':*day=0.1; *eve=0.06; *nig=0.02; break;
		case 'B':*day=0.25; *eve=0.15; *nig=0.05; break;
		case 'C':*day=0.53; *eve=0.33; *nig=0.13; break;
		case 'D':*day=0.87; *eve=0.47; *nig=0.17; break;
		case 'E':*day=1.44; *eve=0.80; *nig=0.30; break;}
}
int main(){
	char type;
	char phone[9];
	int h1,h2,m1,m2;
	while(scanf("%c",&type)==1){
		if(type=='#') break;
		scanf("%s%d%d%d%d",phone,&h1,&m1,&h2,&m2);
		int temp;
		int t1,t2,t3; // t1 day t2 eve t3 nig
		double total=0;
		double day;
		double eve;
		double nig;
		int now_type;
		initial(&day,&eve,&nig,type);
		if(h1>=8&&h1<18)
			now_type=1; // day
		else if(h1>=18&&h1<22)
			now_type=2; // eve
		else
			now_type=3; // nig
		t1=t2=t3=temp=0;
		do{
			m1++; temp++;
			if(m1==60){
				m1=0; h1++;					
				switch(now_type){
					case 1: total+=day*temp; t1+=temp; break;
					case 2: total+=eve*temp; t2+=temp; break;
					case 3: total+=nig*temp; t3+=temp; break;}
				temp=0;
				if(h1>=8&&h1<18)	now_type=1; // day
				else if(h1>=18&&h1<22)
					now_type=2; // eve
				else now_type=3; // nig
			}
			if(h1==24) h1=0;
		}while(h1!=h2||m1!=m2);
		switch(now_type){
			case 1: total+=day*temp; t1+=temp; break;
			case 2: total+=eve*temp; t2+=temp; break;
			case 3: total+=nig*temp; t3+=temp; break;}
		printf("%10s%6d%6d%6d%3c%8.2lf\n",phone,t1,t2,t3,type,total);
		type=getchar();
	}
	return 0;
}
/*

Gondwanaland Telecom這家電話公司收費的標準是以所撥電話的距離及時段來訂定的，如下表。在這裡charging step就是指不同的距離。

所有的收費是根據該通電話每一分鐘多少錢來計算的，所以若有某通電話有跨時段，則按時段不同的收費標準分別計算在加總。例如：有一通電話從5:58pm開始到6:04pm結束，那前2分鐘是按白天（Day）的標準計費，而後4分鐘則按傍晚（Evening）的標準計費。

所有小於一分鐘的電話不列入計費，而且沒有一通電話會持續超過24小時。

Input

每筆測試資料一列，代表某通電話的通話記錄。每列輸入資料包含6個部分，第一個部分為charging step（大寫字母A~E）。第二個部分為所撥的電話號碼（為7個數字及一個"-"的字串），第三、四個部分代表通話開始的時間：時及分。第五、六個部分代表通話結束的時間：時及分（均以24小時的時鐘來看，時、分均以2個數字來表現）。

若輸入列的第一個字為#，代表輸入結束。請參考Sample Input

Output

對每一筆測試資料輸出一列，也包含6個部分。

第一個部分為所撥的電話號碼。第二、三、四部分分別代表這通電話所用各時段（Day,Evening,Night）的分鐘數，第五個部分為charging setp，第六個部分為這通電話總共計費多少錢。

各部分輸出於一定位置，以靠右對其來說，分別在10,16,22,28,31,39的位置。請參考Sample Output

Sample Input

C 765-7457 10 41 04 29
B 207-0225 21 28 07 53
B 316-0414 16 43 09 37
C 463-1401 19 28 00 33
D 514-9373 01 20 09 08
#

Sample Output

  765-7457   439   240   389  C  362.44
  207-0225     0    32   593  B   34.45
  316-0414   174   240   600  B  109.50
  463-1401     0   152   153  C   70.05
  514-9373    68     0   400  D  127.16

*/