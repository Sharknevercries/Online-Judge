/*8382459	458	The Decoder	Accepted	C++	0.040	2010-11-08 12:03:23*/
#include<stdio.h>
int main(){	
	char str[1000];
	while(gets(str)!=NULL){
		for(int i=0;str[i]!='\0';i++)
			printf("%c",str[i]-7);
		for(int i=0;i<1000;i++)
			str[i]='\0';
		printf("\n");
	}
	return 0;
}
/*
在密碼學裡面有一種很簡單的加密方式，就是把明碼的每個字元加上某一個整數K而得到密碼的字元（明碼及密碼字元一定都在ASCII碼中可列印的範圍內）。例如若K=2，那麼apple經過加密後就變成crrng了。解密則是反過來做。這個問題是給你一個密碼字串，請你依照上述的解密方式輸出明碼。

至於在本任務中K到底是多少，請自行參照Sample Input及Sample Output推出來吧！相當簡單的。

Input

每筆測試資料一列。每列有1個字串，就是需要解密的明碼。

Output

對每一測試資料，請輸出解密後的密碼。

Sample Input

1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5
Sample Output

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.
*/