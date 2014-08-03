/* 9038399 706 LCD Display Accepted C++ 0.024 2011-07-11 08:57:09 */
#include<stdio.h>
#define MAX 1000
void print(char table[][MAX],char c,int s,int x){
	int row,cul;	
	// ªì©l¤Æ
	for(cul=x;cul<=x+s+1;cul++)
		for(row=0;row<=2*s+2;row++)
			if(cul==x||cul==x+s+1)
				if((row>=1&&row<=s)||(row>=s+2&&row<=2*s+1))
					table[row][cul]='|';
				else
					table[row][cul]=' ';
			else
				if((row>=1&&row<=s)||(row>=s+2&&row<=2*s+1))
					table[row][cul]=' ';
				else
					table[row][cul]='-';
	switch(c){
	case '0':
		for(cul=x+1;cul<=x+s;cul++)
			table[s+1][cul]=' ';
		break;
	case '1':
		for(row=1;row<=2*s+2;row++)
			table[row][x]=' ';
		for(cul=x+1;cul<=x+s;cul++)
			table[0][cul]=table[s+1][cul]=table[2*s+2][cul]=' ';
		break;
	case '2':
		for(row=1;row<=s;row++)
			table[row][x]=' ';
		for(row=s+2;row<=2*s+1;row++)
			table[row][x+s+1]=' ';
		break;
	case '3':
		for(row=1;row<=2*s+1;row++)
			table[row][x]=' ';
		break;
	case '4':
		for(cul=x;cul<=x+s+1;cul++)
			table[0][cul]=table[2*s+2][cul]=' ';
		for(row=s+2;row<=2*s+1;row++)
			table[row][x]=' ';
		break;
	case '5':
		for(row=1;row<=s;row++)
			table[row][x+s+1]=' ';
		for(row=s+2;row<=2*s+1;row++)
			table[row][x]=' ';
		break;
	case '6':
		for(row=1;row<=s;row++)
			table[row][x+s+1]=' ';
		break;
	case '7':
		for(row=1;row<=2*s+1;row++)
			table[row][x]=' ';
		for(cul=x+1;cul<=x+s;cul++)
			table[s+1][cul]=table[2*s+2][cul]=' ';
		break;
	case '8':
		break;
	case '9':
		for(row=s+2;row<=2*s+1;row++)
			table[row][x]=' ';
		break;
	}
	for(row=0;row<=2*s+2;row++)
		table[row][x+s+2]=' ';
}
int main(){
	int s;
	char str[100];
	while(scanf("%d%s",&s,str)==2){
		if(s==0&&(str[0]=='0'&&str[1]=='\0'))
			break;
		char table[30][MAX];
		int row,cul=0;
		for(int i=0;str[i]!='\0';i++){
			print(table,str[i],s,cul);
			cul+=s+3;
		}
		for(row=0,cul--;row<=2*s+2;row++)
			table[row][cul]='\0';
		for(int i=0;i<=2*s+2;i++)
			printf("%s\n",table[i]);
		putchar('\n');
	}
	return 0;
}
/*

A friend of you has just bought a new computer. Until now, the most powerful computer he ever used has been a pocket calculator. Now, looking at his new computer, he is a bit disappointed, because he liked the LC-display of his calculator so much. So you decide to write a program that displays numbers in an LC-display-like style on his computer.
 
Input  

The input file contains several lines, one for each number to be displayed. Each line contains two integers s, n ( ), where n is the number to be displayed and s is the size in which it shall be displayed.
 
The input file will be terminated by a line containing two zeros. This line should not be processed.
 
Output  

Output the numbers given in the input file in an LC-display-style using s ``-'' signs for the horizontal segments and s ``|'' signs for the vertical ones. Each digit occupies exactly s+2 columns and 2s+3 rows. (Be sure to fill all the white space occupied by the digits with blanks, also for the last digit.) There has to be exactly one column of blanks between two digits.
 
Output a blank line after each number. (You will find a sample of each digit in the sample output.)
 
Sample Input  

2 12345
3 67890
0 0

 Sample Output 

      --   --        -- 
   |    |    | |  | |   
   |    |    | |  | |   
      --   --   --   -- 
   | |       |    |    |
   | |       |    |    |
      --   --        -- 

 ---   ---   ---   ---   --- 
|         | |   | |   | |   |
|         | |   | |   | |   |
|         | |   | |   | |   |
 ---         ---   ---       
|   |     | |   |     | |   |
|   |     | |   |     | |   |
|   |     | |   |     | |   |
 ---         ---   ---   --- 

--------------------------------------------------------------------------------

Miguel A. Revilla 
2000-02-09 

*/