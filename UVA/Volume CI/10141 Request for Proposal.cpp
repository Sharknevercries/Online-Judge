/* 10141 Request for Proposal Accepted C++ 0.016 2011-01-22 07:46:31 */
#include<stdio.h>
#include<string.h>
int main(){
	int n,p,count;
	char b;
	bool first;
	count=1;
	first=true;
	while(scanf("%d%d",&n,&p)==2&&(n!=0&&p!=0)){		
		char temp[100];
		char company[100];
		int max_supply,temp_supply;
		double min_price,temp_price;

		int i,j;
		b=getchar();
		for(i=1;i<=n;i++)
			gets(temp);		
		for(min_price=max_supply=0,i=1;i<=p;i++){
			gets(temp);			
			scanf("%lf%d",&temp_price,&temp_supply);
			if(temp_supply>max_supply){
				max_supply=temp_supply;
				min_price=temp_price;
				strcpy(company,temp);}
			else if(temp_supply==max_supply)
				if(temp_price<min_price){		
					max_supply=temp_supply;
					min_price=temp_price;
					strcpy(company,temp);}
			b=getchar();
			for(j=1;j<=temp_supply;j++)
				gets(temp);
		}
		if(!first)
			putchar('\n');
		first=false;
		printf("RFP #%d\n",count++);
		printf("%s\n",company);
	}
	return 0;
}
/*

當政府機關或企業在需要採購時，他們會列一張採購需求表（Request for Proposal, RFP）。在上面會列出他們需要的東西。各廠商會提出自己的報價單（上面有能提供的需求項目及報價）以爭取訂單。

政府機關或企業會有一評估者來評估誰會得標。評估的方式是他對每家廠商做一張評估表，上面有採購需求表的各項需求。如果這廠商能提供某一項需求，就在該需求上面打一個勾。打勾勾的數目代表此家廠商能滿足採購需求表的程度。評估者最後會選出打勾勾數目最多的廠商來給予訂單。如果有多家廠商打勾勾的數目一樣多的話，就選報價最低的那家。如果連報價都一樣，就選輸入較前面的那家。

Input

每組測試資料的第一列有2個整數 n 和 p。n（0 < n <= 1000）代表採購需求表上面需求的項目數目，p代表投標廠商的數目。（若n=0,p=0代表輸入結束。）

接下來的n列為採購需求表的需求項目，每列最多不會超過80個字元，大小寫視為不同的字元。

再接下來有這p家廠商的報價單資料。每家廠商資料的第一列為這家廠商的名字。接下來的一列有一個浮點數 d 及一個整數  r（0 <= r <= n），d代表報價多少，r代表評估者打勾勾的數目，也就是符合採購需求表項目的數目。再接下來的r列每列有一項需求項目，每一項都會在採購需求表上，並且不會有重複的出現。

請參考Sample Input。

Output

對每組測試資料請輸出這是第幾組測試資料以及得標廠商的名字。

測試資料間請空一列，請參考Sample Output。

Sample Input

6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
tires
brakes
Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine
Hyundai
10000.00 3
engine
tires
ashtray
Lada
6000.00 1
tires
1 1
coffee
Starbucks
1.50 1
coffee
0 0

Sample Output

RFP #1
Cadillac

RFP #2
Starbucks
 
*/