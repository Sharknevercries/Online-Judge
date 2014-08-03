/* 10010 Where's Waldorf? Accepted C++ 0.016 2011-02-25 15:27:22 */
#include<stdio.h>
#include<string.h>
int ROW(char str[][51],char temp[],int m,int n,int row,int cul){	
	int i,k;
	for(i=cul,k=0;i<n&&temp[k]!='\0';i++,k++)
		if(str[row][i]!=temp[k])	break;
	if(temp[k]=='\0')
		return true;
	for(i=cul,k=0;i>=0&&temp[k]!='\0';i--,k++)
		if(str[row][i]!=temp[k])	break;
	if(temp[k]=='\0')
		return true;	
	return false;
}
int CUL(char str[][51],char temp[],int m,int n,int row,int cul){
	int i,k;
	for(i=row,k=0;i<m&&temp[k]!='\0';i++,k++)
		if(str[i][cul]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;
	for(i=row,k=0;i>=0&&temp[k]!='\0';i--,k++)
		if(str[i][cul]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;	
	return false;
}
int UL_to_DR(char str[][51],char temp[],int m,int n,int row,int cul){	
	int i,j,k;
	for(i=row,j=cul,k=0;i<m&&j<n&&temp[k]!='\0';i++,j++,k++)
		if(str[i][j]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;
	for(i=row,j=cul,k=0;i>=0&&j>=0&&temp[k]!='\0';i--,j--,k++)
		if(str[i][j]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;
	return false;
}
int UR_to_DL(char str[][51],char temp[],int m,int n,int row,int cul){	
	int i,j,k;
	for(i=row,j=cul,k=0;i<m&&j>=0&&temp[k]!='\0';i++,j--,k++)
		if(str[i][j]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;
	for(i=row,j=cul,k=0;i>=0&&j<n&&temp[k]!='\0';i--,j++,k++)
		if(str[i][j]!=temp[k]) break;
	if(temp[k]=='\0')
		return true;
	return false;
}
void to_big(char str[]){
	int i;
	for(i=0;str[i]!='\0';i++)
		str[i]=(str[i]>='a')?str[i]-32:str[i];
}
int main(){
	int t;
	while(scanf("%d",&t)==1)
		while(t--){
			int row,cul,k;
			int n,m;
			char str[50][51];
			char temp[51],temp_B[51];
			scanf("%d%d",&m,&n);
			for(row=0;row<m;row++){
				scanf("%s",str[row]);
				to_big(str[row]);}
			scanf("%d",&k);
			while(k--){
				bool found=false;
				scanf("%s",temp);
				strcpy(temp_B,temp);
				to_big(temp_B);
				for(row=0;row<m&&!found;row++)
					for(cul=0;cul<n&&!found;cul++){
						if(ROW(str,temp_B,m,n,row,cul)){found=true;break;}
						if(CUL(str,temp_B,m,n,row,cul)){found=true;break;}
						if(UL_to_DR(str,temp_B,m,n,row,cul)){found=true;break;}
						if(UR_to_DL(str,temp_B,m,n,row,cul)){found=true;break;}
					}
				printf("%d %d\n",row,cul+1);
			}
			if(t>0)
				putchar('\n');
		}
	return 0;
}
/*

Given a m by n grid of letters, ( ), and a list of words, find the location in the grid at which the word can be found. A word matches a straight, uninterrupted line of letters in the grid. A word can match the letters in the grid regardless of case (i.e. upper and lower case letters are to be treated as the same). The matching can be done in any of the eight directions either horizontally, vertically or diagonally through the grid. 

Input  

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 

The input begins with a pair of integers, m followed by n,  in decimal notation on a single line. The next m lines contain n letters each; this is the grid of letters in which the words of the list must be found. The letters in the grid may be in upper or lower case. Following the grid of letters, another integer k appears on a line by itself ( ). The next k lines of input contain the list of words to search for, one word per line. These words may contain upper and lower case letters only (no spaces, hyphens or other non-alphabetic characters). 

Output  

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 

For each word in the word list, a pair of integers representing the location of the corresponding word in the grid must be output. The integers must be separated by a single space. The first integer is the line in the grid where the first letter of the given word can be found (1 represents the topmost line in the grid, and m represents the bottommost line). The second integer is the column in the grid where the first letter of the given word can be found (1 represents the leftmost column in the grid, and n represents the rightmost column in the grid). If a word can be found more than once in the grid, then the location which is output should correspond to the uppermost occurence of the word (i.e. the occurence which places the first letter of the word closest to the top of the grid). If two or more words are uppermost, the output should correspond to the leftmost of these occurences. All words can be found at least once in the grid. 

Sample Input

1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert

Sample Output  

2 5
2 3
1 2
7 8

--------------------------------------------------------------------------------

Miguel Revilla 
2000-08-22 

*/