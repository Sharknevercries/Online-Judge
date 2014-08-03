/* 343 What Base Is This? Accepted C++ 0.020 2011-02-12 09:21:54 */
#include<stdio.h>
#include<string.h>
int change(char c){
	if(c>='0'&&c<='9')
		return (int)c-'0';
	if(c>='A'&&c<='Z')
		return (int)c-'A'+10;
}
int compare(char s1[],int digit_a,char s2[],int digit_b){
	int a,b;
	int i;
	for(i=a=0;s1[i]!='\0';i++){
		a*=digit_a;
		a+=change(s1[i]);}
	for(i=b=0;s2[i]!='\0';i++){
		b*=digit_b;
		b+=change(s2[i]);}
	if(a==b)
		return true;
	else
		return false;
}
int main(){
	char str1[100];
	char str2[100];
	while(scanf("%s%s",str1,str2)==2){		
		int temp,min_a,min_b;
		int i,j;
		bool found=false;
		for(min_a=i=temp=0;str1[i]!='\0';i++){			
			j=change(str1[i]);			
			if(min_a<j+1)
				min_a=j+1;}		
		for(min_b=i=temp=0;str2[i]!='\0';i++){			
			j=change(str2[i]);			
			if(min_b<j+1)
				min_b=j+1;}	
		for(i=(min_a>2)?min_a:2;i<=36&&!found;i++)
			for(j=(min_b>2)?min_b:2;j<=36&&!found;j++)
				if(compare(str1,i,str2,j))
					found=true;	
		if(found)
			printf("%s (base %d) = %s (base %d)\n",str1,i-1,str2,j-1);
		else
			printf("%s is not equal to %s in any base 2..36\n",str1,str2);
	}
	return 0;
}
/*

我們知道在一個數字中不同的位置其權重（weight）是不同的。例如10進位的數字362中，2的權重是100，6的權重是101，3的權重是102。所以這個數10進位的值=3*102+6*101+2*100。同樣的機制也適用於其他的進位制。然而362這個數字在9進位制或14進位制中所代表的值是和10進位制的362不同的。

在本問題中，給你2個數字（以X、Y代表），請你寫一個程式找出X最小是多少進位制，且Y最小是多少進位制，才能使X，Y代表相同的值。例如：給你12和5。若用10進位來看的話，這2個數明顯是不同的。但是假如你用3進位來看12,用6進位來看5呢？12(3進位)=1*31+2*30=5(10進位)，而5(6進位)=5(10進位)。所以如果你選對進位制的話，12和5是可以代表相同的值的。 

Input

每組測試資料一列，包含2個數字X、Y。X、Y可以2進位制到36進位制來看待。在表達上，0～9就代表0～9，A,B,C,......,Z則分別代表10,11,12,......,35 

Output

每組測試資料輸出的一列，格式請參考Sample Output。請注意X、Y有可能在2進位制到36進位制中均無法使之相等。 

Sample Input

12   5
    10     A
12 34
  123   456
  1    2
  10   2
0 0

Sample Output

12 (base 3) = 5 (base 6)
10 (base 10) = A (base 11)
12 (base 17) = 34 (base 5)
123 is not equal to 456 in any base 2..36
1 is not equal to 2 in any base 2..36
10 (base 2) = 2 (base 3)
0 (base 2) = 0 (base 2)

*/