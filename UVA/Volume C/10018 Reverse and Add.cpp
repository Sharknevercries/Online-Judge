/* 10018 Reverse and Add Accepted C++ 0.012 2011-01-05 14:06:34 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d ",&n)==1){
		for(int i=1;i<=n;i++){
			char str1[11],str2[11],str3[11];
			int count=0;
			for(int k=0;k<11;k++)
				str1[k]=str2[k]=str3[k]='0';
			gets(str1);
			while(true){
				int p_str,carry=0;	
				bool right=false,to=false;
				for(p_str=0;str1[p_str]!='\0';p_str++);
				p_str-=1;
				for(int k=p_str;k>=0;k--)
					str2[p_str-k]=str1[k];
				for(int k=p_str,i=0;k>=0;k--,i++){
					str3[i]=str1[k]+str2[k]-'0'+carry;
					carry=0;
					while(str3[i]>'9'){	
						if(k==0)
							to=true;
						str3[i]-=10;
						carry=1;}}
				if(to)
					p_str++;
				if(carry)
					str3[p_str]++;
				for(int k=0;k<=p_str+1;k++)
					str1[k]=str3[p_str-k];
				
				str1[p_str+1]='\0';
				count++;
				for(int k=0,j=p_str;j>=k;k++,j--)
					if(str1[k]==str1[j]){
						if(k==j-1||k==j)
							right=true;
						continue;}
					else
						break;
				if(right)
					break;
				
			}
				printf("%d %s\n",count,str1);
		}
	}
	return 0;
}
/*

把一個數字反轉並相加的方法很簡單：就是把數字反轉並加上原來的數字。假如這個和不是一個迴文（指這個數字從左到右和從右到左都相同），就一直重複這個程序。舉例說明：

195 開始的數字
591
-----
786
687
-----
1473
3741
-----
5214
4125
-----
9339 迴文出現了

在這個例子中，經過了4次相加後得到了迴文9339。幾乎對所有的整數這個方法都會得到迴文，但是也有有趣的例外。196是第1個用這個方法找不到迴文的數字，然而並沒有證明該迴文不存在。

現在給你一個開始的數字，你的任務就是求出經過多少次相加後，會產生哪一個迴文。對所有的測試資料，你可以假設：1. 都會有1個答案。2. 在1000個相加內都會得到答案。 3. 產生的迴文不會大於4294967295.

Input

第1列有一個整數N（0 < N <= 100），代表以下有幾組測試資料。每筆測試資料一列，各有1個整數 P，就是開始的數字。

Output

對每一測試資料，請輸出2個數字：得到迴文所需的最少次數的相加，以及該迴文。

Sample Input

5
195
265
750
2
99

Sample Output

4 9339
5 45254
3 6666
1 4
6 79497
*/