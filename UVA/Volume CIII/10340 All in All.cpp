/* 10340 All in All Accepted C++ 0.012 2011-01-07 15:00:15 */
#include<stdio.h>
char s[1000000],t[1000000];
int main(){	
	while(scanf("%s%s",s,t)==2){	
		bool YES=true;
		int i,j;
		for(i=j=0;YES&&s[i]!='\0';i++,j++){
			while(s[i]!=t[j]){
				if(t[j]=='\0'){
					YES=false;
					break;
				}
				j++;
			}
			if(!YES)
				break;
		}
		if(s[i]=='\0'&&YES)
			puts("Yes");
		else
			puts("No");
			
	}
	return 0;
}
/*

給你2個字串s,t，請你寫一個程式判斷是否s是t的子字串。也就是說當你移走t字串中的某些字元後，剩下的字串就是s。

Input

每筆測試資料一列。每列有2個字串，s及t，以空白分隔。

Output

對每一列輸入，請輸出是否s是t的子字串。

Sample Input

abc abc
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
Sample Output

Yes
Yes
No
Yes
No

*/