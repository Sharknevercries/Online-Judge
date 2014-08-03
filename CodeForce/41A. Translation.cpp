/* 1219474	 Feb 23, 2012 5:52:43 PM	Shark	 41A - Translation	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<string.h>
int main(){
	char str1[1000],str2[1000];
	while(scanf("%s%s",str1,str2)==2){
		int i,j;
		for(i=0,j=strlen(str2)-1;str1[i]!='\0'&&j>=0;i++,j--)
			if(str1[i]!=str2[j])
				break;
		if(str1[i]=='\0'&&j<0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

The translation from the Berland language into the Birland language is not an easy task. Those languages are very similar: a berlandish word differs from a birlandish word with the same meaning a little: it is spelled (and pronounced) reversely. For example, a Berlandish word code corresponds to a Birlandish word edoc. However, it's easy to make a mistake during the «translation». Vasya translated word s from Berlandish into Birlandish as t. Help him: find out if he translated the word correctly.

Input

The first line contains word s, the second line contains word t. The words consist of lowercase Latin letters. The input data do not consist unnecessary spaces. The words are not empty and their lengths do not exceed 100 symbols.

Output

If the word t is a word s, written reversely, print YES, otherwise print NO.

input

code
edoc
abb
aba
code
code

output

YES
NO
NO

*/