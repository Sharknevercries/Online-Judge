/* 485 Pascal's Triangle of Death Accepted C++ 0.024 2011-03-04 12:48:43 */
#include<stdio.h>
#include<string.h>
char DP[2][1000][1000];
int compare(char str1[],char str2[]){
	int len_1=strlen(str1);
	int len_2=strlen(str2);
	if(len_1>len_2)
		return true;
	else if(len_2>len_1)
		return false;
	else{
		int i;
		for(i=len_1-1;i>=0;i--)
			if(str1[i]>str2[i])
				return true;
			else if(str2[i]>str1[i])
				return false;
		return true; // equal
	}
}
void plus(char str1[],char str2[],char result[]){
	char temp[10000];	
	bool change=false;
	if(!compare(str1,str2)){ // 防止因為交換後而使 pascal triangel 毀容,在後面再交換一次
		strcpy(temp,str1);
		strcpy(str1,str2);
		strcpy(str2,temp);
		change=true;
	}
	int len_1=strlen(str1);
	int len_2=strlen(str2);
	int i,j,k,carry;
	for(i=0;i<len_1+1;i++)
		result[i]='0';
	result[len_1+1]='\0';
	for(i=len_1-1,j=len_2-1,k=len_1,carry=0;i>=0;i--,k--){
		if(j>=0)
			result[k]=str1[i]-'0'+str2[j--]-'0'+result[k]+carry;			
		else
			result[k]=str1[i]-'0'+result[k]+carry;
		carry=(result[k]-'0')/10;
		result[k]=(result[k]-'0')%10+'0';		
	}
	result[0]=carry+'0';
	if(result[0]=='0')
		for(i=0;i<len_1+1;i++)
			result[i]=result[i+1];
	if(change){
		strcpy(temp,str1);
		strcpy(str1,str2);
		strcpy(str2,temp);
	}	
}
int main(){	
	char limit[]="1000000000000000000000000000000000000000000000000000000000000";
	int i,j,row;
	puts("1");
	puts("1 1");
	sprintf(DP[0][0],"%d",1); // initail
	sprintf(DP[0][1],"%d",1);
	for(i=1,row=3;;i++,row++){
		for(j=0;j<row;j++){
			if(j==0||j==row-1)
				sprintf(DP[i%2][j],"%d",1);
			else 
				plus(DP[(i-1)%2][j],DP[(i-1)%2][j-1],DP[i%2][j]); // Big Nnuber , double 會有誤差
		}
		printf("%s",DP[i%2][0]);
		for(int k=1;k<row;k++)
			printf(" %s",DP[i%2][k]);
		putchar('\n');
		if(compare(DP[i%2][row/2],limit))
			break;
	}		
	return 0;
}
/*

In this problem, you are asked to generate Pascal's Triangle. Pascal's Triangle is useful in many areas from probability to polynomials to programming contests. It is a triangle of integers with ``1'' on top and down the sides. Any number in the interior equals the sum of the two numbers above it. For example, here are the first 5 rows of the triangle. 

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 

In ``Pascal's Triangle of Death,'' you are to generate a left justified Pascal's Triangle. When any number in the triangle is exceeds or equals 1060, your program should finish printing the current row and exit. The output should have each row of the triangle on a separate line with one space between each element. 

The final element of each line should be directly followed by a newline. There is no space after the last number on each line. 

Sample Input

There is no input for this problem. 

Sample Output

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
.
.
.
etc.

*/