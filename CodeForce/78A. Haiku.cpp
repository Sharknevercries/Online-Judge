/* 1273438	 Mar 4, 2012 12:36:46 PM	Shark	 78A - Haiku	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str1[105],str2[105],str3[105];
	while(gets(str1)){
		gets(str2);
		gets(str3);
		int count1,count2,count3,i;
		for(i=count1=0;str1[i]!='\0';i++)
			if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
				count1++;
		for(i=count2=0;str2[i]!='\0';i++)
			if(str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u')
				count2++;
		for(i=count3=0;str3[i]!='\0';i++)
			if(str3[i]=='a'||str3[i]=='e'||str3[i]=='i'||str3[i]=='o'||str3[i]=='u')
				count3++;
		if(count1==5&&count2==7&&count3==5)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Haiku is a genre of Japanese traditional poetry.

A haiku poem consists of 17 syllables split into three phrases, containing 5, 7 and 5 syllables correspondingly (the first phrase should contain exactly 5 syllables, the second phrase should contain exactly 7 syllables, and the third phrase should contain exactly 5 syllables). A haiku masterpiece contains a description of a moment in those three phrases. Every word is important in a small poem, which is why haiku are rich with symbols. Each word has a special meaning, a special role. The main principle of haiku is to say much using a few words.

To simplify the matter, in the given problem we will consider that the number of syllable in the phrase is equal to the number of vowel letters there. Only the following letters are regarded as vowel letters: "a", "e", "i", "o" and "u".

Three phases from a certain poem are given. Determine whether it is haiku or not.

Input

The input data consists of three lines. The length of each line is between 1 and 100, inclusive. The i-th line contains the i-th phrase of the poem. Each phrase consists of one or more words, which are separated by one or more spaces. A word is a non-empty sequence of lowercase Latin letters. Leading and/or trailing spaces in phrases are allowed. Every phrase has at least one non-space character. See the example for clarification.

Output

Print "YES" (without the quotes) if the poem is a haiku. Otherwise, print "NO" (also without the quotes).

input

on  codeforces 
beta round is running
   a rustling of keys 
how many gallons
of edo s rain did you drink
                                cuckoo

output

YES
NO

*/