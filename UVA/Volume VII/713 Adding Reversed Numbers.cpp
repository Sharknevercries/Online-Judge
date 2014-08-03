/* 9092493 713 Adding Reversed Numbers Accepted C++ 0.008 2011-07-29 09:11:34 */
#include<stdio.h>
#include<string.h>
#define SWAP(x,y) { char c=x; x=y; y=c; }
void rotate(char str[]){
	int i,j;
	for(i=0,j=strlen(str)-1;j>i;i++,j--)
		SWAP(str[i],str[j]);
	for(i=0;str[i]=='0';i++);
	memmove(str,&str[i],sizeof(char)*(strlen(str)-i+1));
}
void plus(char str1[],char str2[],char result[]){
	int i,j,k,carry,temp;
	int len_1=strlen(str1);
	int len_2=strlen(str2);
	int result_len=(len_1>len_2)?len_1+1:len_2+1;	
	for(i=0;i<result_len;i++)
		result[i]='0';
	result[i]='\0';
	for(i=len_1-1,j=len_2-1,k=result_len-1,carry=0;i>=0||j>=0;){
		if(i>=0&&j>=0)
			temp=str1[i--]-'0'+str2[j--]-'0'+carry;		
		else if(i>=0)
			temp=str1[i--]-'0'+carry;
		else 
			temp=str2[j--]-'0'+carry;
		carry=temp/10;
		temp%=10;
		result[k--]='0'+temp;
	}
	result[k]='0'+carry;
	if(result[0]=='0')
		memmove(result,&result[1],sizeof(char)*result_len);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		char str1[500],str2[500],result[500];
		scanf("%s%s",str1,str2);
		rotate(str1);
		rotate(str2);
		plus(str1,str2,result);
		rotate(result);
		printf("%s\n",result);
	}
	return 0;
}
/*

The Antique Comedians of Malidinesia prefer comedies to tragedies. Unfortunately, most of the ancient plays are tragedies. Therefore the dramatic advisor of ACM has decided to transfigure some tragedies into comedies. Obviously, this work is very hard because the basic sense of the play must be kept intact, although all the things change to their opposites. For example the numbers: if any number appears in the tragedy, it must be converted to its reversed form before being accepted into the comedy play.
 
Reversed number is a number written in arabic numerals but the order of digits is reversed. The first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed number never has any trailing zeros.
 
ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and output their reversed sum. Of course, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12).
 
Input  

The input consists of N cases. The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly one line with two positive integers separated by space. These are the reversed numbers you are to add. Numbers will be at most 200 characters long.
 
Output  

For each case, print exactly one line containing only one integer - the reversed sum of two reversed numbers. Omit any leading zeros in the output.
 
Sample Input 

3
24 1
4358 754
305 794

 Sample Output  

34
1998
1

--------------------------------------------------------------------------------

Miguel A. Revilla 
2000-02-15 

*/