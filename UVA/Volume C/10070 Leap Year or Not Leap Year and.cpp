/* 9045036 10070 Leap Year or Not Leap Year and ... Accepted C++ 0.008 2011-07-13 09:13:07 */
#include<stdio.h>
#include<string.h>
int main(){
	bool first=true;
	char str[100000];
	while(gets(str)){
		if(!first)
			putchar('\n');
		first=false;
		bool normal=true;
		bool leap=false;
		int i;
		int temp,tempex;
		i=strlen(str)>=5?strlen(str)-5:0;
		for(temp=0;str[i]!='\0';i++)
			temp=temp*10+str[i]-'0';
		if(temp%400==0||(temp%4==0&&temp%100!=0)){
			puts("This is leap year.");
			normal=false;
			leap=true;
		}
		for(i=0,temp=0;str[i]!='\0';i++)
			temp+=str[i]-'0';
		i=strlen(str)-1;
		if(temp%3==0&&(str[i]=='0'||str[i]=='5')){
			puts("This is huluculu festival year.");
			normal=false;
		}
		if(leap){
			for(i=temp=tempex=0;str[i]!='\0';i++)
				if(i%2==0)
					temp+=str[i]-'0';
				else
					tempex+=str[i]-'0';
			i=strlen(str)-1;
			if((temp-tempex>0?(temp-tempex)%11==0:(tempex-temp)%11==0)&&(str[i]=='0'||str[i]=='5')){
				puts("This is bulukulu festival year.");
				normal=false;
			}
		}
		if(normal)
			puts("This is an ordinary year.");
	}
	return 0;
}
/*

The ancient race of Gulamatu is very advanced in their year calculation scheme. They understand what leap year is (A year that is divisible by 4 and not divisible by 100 with the exception that years that are divisible by 400 are also leap year.) and they have also similar festival years. One is the Huluculu festival (happens on years divisible by 15) and the Bulukulu festival (Happens on years divisible by 55 provided that is also a leap year). Given an year you will have to state what properties these years have. If the year is not leap year nor festival year, then print the line 'This is an ordinary year.' The order of printing (if present) the properties is leapyear-->huluculu-->bulukulu.

Input

Input will contain several years as input. Each year will be in separate lines. Input is terminated by end of file. All the years will not be less than 2000 (to avoid the earlier different rules for leap years). Please don¡¦t assume anything else.

Output

For each input, output the different properties of the years in different lines according to previous description and sample output. A blank line should separate the output for each line of input. Note that there are four different properties. 

Sample Input
 2000
 3600
 4515
 2001

Sample Output
 This is leap year.

 This is leap year.
 This is huluculu festival year.

 This is huluculu festival year.

 This is an ordinary year.
 _____________________________________________________________________________________
 Shahriar Manzoor

*/

