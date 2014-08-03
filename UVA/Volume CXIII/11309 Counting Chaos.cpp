/* 9045106 11309 Counting Chaos Accepted C++ 0.020 2011-07-13 09:52:21 */
#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	(void) getchar();
	for(int t=1;t<=n;t++){	
		int i,j;
		char str[10];
		gets(str);
		int h,m,time;
		for(i=h=0;str[i]!=':';i++)
			h=h*10+str[i]-'0';
		for(i++,m=0;str[i]!='\0';i++)
			m=m*10+str[i]-'0';
		m++;
		while(true){
			if(m>=60)
				h++,m=0;
			if(h>=24)
				h=0;
			time=h*100+m;
			sprintf(str,"%d",time);
			for(i=0,j=strlen(str)-1;j>i;i++,j--)
				if(str[i]!=str[j])
					break;
			if(j<=i)
				break;
			m++;
		}
		if(h>=10)
			if(m>=10)
				printf("%d:%d\n",h,m);
			else
				printf("%d:0%d\n",h,m);
		else
			if(m>=10)
				printf("0%d:%d\n",h,m);
			else
				printf("0%d:0%d\n",h,m);			
	}
	return 0;
}
/*

Wolfgang Puck's rival, Emeril Lagasse ("BAM!"), recently set the world culinary record in the category of smallest souffl� measuring in at a mere 2 cm! Wolfgang, not to be outdone, decided that he would set a culinary record of his own: the most symmetric marble cake in the world. This is clearly not an easy feat!

As we all know from Wolfgang's bestselling biography, he is a very superstitious chef. In his attempts to create the symmetric cake, he has vowed to remove the cake from the oven only at a palindromic time, i.e., a time that reads the same when read from left-to-right as right-to-left. Not including the current time, when is the next opportunity for Wolfgang to remove his cake?

Input
 
On the first line of the input you are given n, the number of attempts Wolfgang makes to make his symmetric cake. The following n lines contain a string formatted as "HH:MM" indicating the current time on a twenty-four hour clock. (So 0 ≤ HH ≤ 23 and 0 ≤ MM ≤ 59 and "00:00" follows "23:59")

Output
 
For each attempt, output a string indicating the next palindromic time (not including the current time) on a single line formatted as "hh:mm". When determining if HH:MM is palindromic, ignore all leading zeroes in HH. If HH is zero then ignore all leading zeroes in MM.

Sample Input
3
00:00
23:30
14:59

 Output for the Sample Input
00:01
23:32
15:51

--------------------------------------------------------------------------------
 Sean McIntyre
 Calgary Collegiate Programming Contest 2007
 
 */