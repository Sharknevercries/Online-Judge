/* 1219660	 Feb 23, 2012 7:06:31 PM	Shark	 59A - Word	 GNU C++	Accepted	 30 ms	 1400 KB */
#include<stdio.h>
int main(){
	char str[10000];
	while(scanf("%s",str)==1){
		int lower=0,upper=0;
		for(int i=0;str[i]!='\0';i++)
			if(str[i]>='a'&&str[i]<='z')
				lower++;
			else
				upper++;
		if(upper>lower){
			for(int i=0;str[i]!='\0';i++)
				if(str[i]>='a'&&str[i]<='z')
					str[i]-=32;
		}
		else
			for(int i=0;str[i]!='\0';i++)
				if(str[i]>='A'&&str[i]<='Z')
					str[i]+=32;
		printf("%s\n",str);

	}
	return 0;
}
/*

Vasya is very upset that many people on the Net mix uppercase and lowercase letters in one word. That's why he decided to invent an extension for his favorite browser that would change the letters' register in every word so that it either only consisted of lowercase letters or, vice versa, only of uppercase ones. At that as little as possible letters should be changed in the word. For example, the word HoUse must be replaced with house, and the word ViP ¡X with VIP. If a word contains an equal number of uppercase and lowercase letters, you should replace all the letters with lowercase ones. For example, maTRIx should be replaced by matrix. Your task is to use the given method on one given word.

Input

The first line contains a word s ¡X it consists of uppercase and lowercase Latin letters and possesses the length from 1 to 100.

Output

Print the corrected word s. If the given word s has strictly more uppercase letters, make the word written in the uppercase register, otherwise - in the lowercase one.

input

HoUse
ViP
maTRIx

output

house
VIP
matrix

*/