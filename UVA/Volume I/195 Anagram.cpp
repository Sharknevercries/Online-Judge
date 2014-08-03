/* 9199020 195 Anagram Accepted C++ 0.048 2011-08-28 13:07:46 */
#include<stdio.h>
#include<string.h>
#define SWAP(x,y) {	char temp=x; x=y; y=temp;	}
char str[1000];
char result[1000];
bool used[1000];
void print(int n,int len){
	if(n==len)
		printf("%s\n",result);
	else{
		char pre='\0';
		for(int i=0;i<len;i++)
			if(!used[i]&&str[i]!=pre){
				used[i]=true;
				pre=result[n]=str[i];
				print(n+1,len);
				used[i]=false;
			}
	}
}
void qsort(int left,int right){
	if(right>left){
		int a,b;
		int split,next;
		split=left;
		a = (str[left]>='a'&&str[left]<='z') ? str[left]-32 : str[left] ;
		for(next=split+1;next<=right;next++){
			b = (str[next]>='a'&&str[next]<='z') ? str[next]-32 : str[next] ;
			if(a>b||(a==b&&str[left]>str[next])){
				split++;
				SWAP(str[split],str[next]);
			}
		}
		SWAP(str[split],str[left]);
		qsort(left,split-1);
		qsort(split+1,right);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	(void)getchar();
	for(int t=0;t<n;t++){
		gets(str);
		int len=strlen(str);
		result[len]='\0';
		qsort(0,len-1);
		
		for(int i=0;i<len;i++)
			used[i]=false;
		print(0,len);
	}
	return 0;
}
/*

You are to write a program that has to generate all possible words from a given set of letters.
 
Example: Given the word "abc", your program should - by exploring all different combination of the three letters - output the words "abc", "acb", "bac", "bca", "cab" and "cba".
  
In the word taken from the input file, some letters may appear more than once. For a given word, your program should not produce the same word more than once, and the words should be output in alphabetically ascending order.
 
Input
 
The input file consists of several words. The first line contains a number giving the number of words to follow. Each following line contains one word. A word consists of uppercase or lowercase letters from A to Z. Uppercase and lowercase letters are to be considered different.
 
Output
 
For each word in the input file, the output file should contain all different words that can be generated with the letters of the given word. The words generated from the same input word should be output in alphabetically ascending order. An upper case letter goes before the corresponding lower case letter.
 
Sample Input
 
3
aAb
abc
acba 

Sample Output
 
Aab
Aba
aAb
abA
bAa
baA
abc
acb
bac
bca
cab
cba
aabc
aacb
abac
abca
acab
acba
baac
baca
bcaa
caab
caba
cbaa 

*/