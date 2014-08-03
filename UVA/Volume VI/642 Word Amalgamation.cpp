/* 642 Word Amalgamation Accepted C++ 0.016 2011-02-23 12:46:47 */
#include<stdio.h>
#include<string.h>
#define reset() { for(k=0;k<15;k++) used[k]=false; NOT=false; }
void SWAP(char str1[],char str2[]){
	char temp[15];
	strcpy(temp,str1);	
	strcpy(str1,str2);	
	strcpy(str2,temp);
}
void arrange(char str[][15],int n){ // 將字串按字母順序排列
	int i,j,k,l;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			for(k=l=0;str[i][k]!='\0'&&str[j][l]!='\0';k++,l++)
				if(str[i][k]>str[j][l]){
					SWAP(str[i],str[j]);
					break;}
				else if(str[i][k]<str[j][l])
					break;
			if(str[j][l]=='\0')
				SWAP(str[i],str[j]);
		}
}
int main(){
	char str[100][15];
	char temp[15];
	int i,j,k,n;
	n=0;
	while(scanf("%s",temp)==1){
		if(strcmp(temp,"XXXXXX")==0)
			break;
		strcpy(str[n++],temp);}
	arrange(str,n);
	while(scanf("%s",temp)==1){
		if(strcmp(temp,"XXXXXX")==0)
			break;
		int len;
		bool has_one=false;
		bool used[15]={false};
		bool NOT=false;
		for(i=0;i<n;i++){
			len=strlen(str[i]);
			for(j=k=0;temp[j]!='\0';j++,k=0){
				while(str[i][k]!='\0')
					if(used[k]) // 不重複使用字元
						k++;
					else if(temp[j]==str[i][k])
						break;
					else
						k++;
				if(str[i][k]=='\0'){
					NOT=true; 
					break;}
				else
					used[k]=true;}
			for(j=0;j<len&&used[j];j++);
			if(!NOT&&j>=len){
				has_one=true;
				printf("%s\n",str[i]);}
			reset();
		}
		if(!has_one)
			puts("NOT A VALID WORD");
		puts("******");
	}
	return 0;
}
/*

In millions of newspapers across the United States there is a word game called Jumble. The object of this game is to solve a riddle, but in order to find the letters that appear in the answer it is necessary to unscramble four words. Your task is to write a program that can unscramble words. 

Input  

The input file contains four parts: 

1. a dictionary, which consists of at least one and at most 100 words, one per line; 
2. a line containing XXXXXX, which signals the end of the dictionary; 
3. one or more scrambled `words' that you must unscramble, each on a line by itself; and 
4. another line containing XXXXXX, which signals the end of the file. 
All words, including both dictionary words and scrambled words, consist only of lowercase English letters and will be at least one and at most six characters long. (Note that the sentinel XXXXXX contains uppercase X's.) The dictionary is not necessarily in sorted order, but each word in the dictionary is unique. 

Output  

For each scrambled word in the input, output an alphabetical list of all dictionary words that can be formed by rearranging the letters in the scrambled word. Each word in this list must appear on a line by itself. If the list is empty (because no dictionary words can be formed), output the line ``NOT A VALID WORD" instead. In either case, output a line containing six asterisks to signal the end of the list. 

Sample Input  

tarp
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco
nfudre
aptr
sett
oresuc
XXXXXX

Sample Output  

score
******
refund
******
part
tarp
trap
******
NOT A VALID WORD
******
course
******

--------------------------------------------------------------------------------

Miguel A. Revilla 
2000-01-17 

*/