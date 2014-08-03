/* 1151379 Feb 5, 2012 6:37:06 PM Shark 1B - Spreadsheet GNU C++ Accepted 170 ms 1300 KB */
#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int t=0;t<n;t++){
		char str[1000];
		scanf("%s",str);

		char r1,c1;
		int r2,c2;
		if(sscanf(str," %c%d%c%d",&r1,&r2,&c1,&c2)==4){
			char temp[1000];
			int ptr=0;
			for(int i=c2;i>0;i=(i-1)/26)
				temp[ptr++]='A'+(i-1)%26;
			temp[ptr]='\0';
			for(int i=0,j=strlen(temp)-1;j>i;i++,j--){
				char o=temp[i];
				temp[i]=temp[j];
				temp[j]=o;
			}
			printf("%s%d\n",temp,r2);
		}
		else{
			int i=0,j=0,ptr;
			for(ptr=0;str[ptr]>='A'&&str[ptr]<='Z';ptr++)
				i=i*26+str[ptr]-'A'+1;
			for(;str[ptr]!='\0';ptr++)
				j=j*10+str[ptr]-'0';
			printf("R%dC%d\n",j,i);
		}
	}
	return 0;
}
/*

In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.

Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.

Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.

Input

The first line of the input contains integer number n (1 ≤ n ≤ 105), the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .

Output

Write n lines, each line should contain a cell coordinates in the other numeration system.

input

2
R23C55
BC23

output

BC23
R23C55

*/