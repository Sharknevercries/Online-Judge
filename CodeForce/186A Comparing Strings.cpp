/* 4685063	 Oct 6, 2013 8:55:51 AM	Shark	 186A - Comparing Strings	 GNU C++	Accepted	30 ms	200 KB */
#include<stdio.h>
#include<string.h>
int main(){
	char str1[100005],str2[100005];
	while( scanf("%s%s",str1,str2)==2 ){
		int Alpha1[26]={0};
		int Alpha2[26]={0};
		int len1=strlen(str1);
		int len2=strlen(str2);
		bool Fail=false;

		for(int i=0;str1[i]!='\0';i++)
			Alpha1[str1[i]-'a']++;
		for(int i=0;str2[i]!='\0';i++)
			Alpha2[str2[i]-'a']++;
		for(int i=0;i<26;i++)
			if( Alpha1[i]!=Alpha2[i] )
				Fail=true;

		if( !Fail&&len1==len2 ){
			int Difference=0;
			for(int i=0;str1[i]!='\0';i++)
				if( str1[i]!=str2[i] )
					Difference++;
			if( Difference==0||Difference==2 )
				puts("YES");
			else
				puts("NO");
		}
		else
			puts("NO");
	}
	return 0;
}
/*

A. Comparing Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Some dwarves that are finishing the StUDY (State University for Dwarven Youngsters) Bachelor courses, have been told "no genome, no degree". That means that all dwarves should write a thesis on genome. Dwarven genome is far from simple. It is represented by a string that consists of lowercase Latin letters.

Dwarf Misha has already chosen the subject for his thesis: determining by two dwarven genomes, whether they belong to the same race. Two dwarves belong to the same race if we can swap two characters in the first dwarf's genome and get the second dwarf's genome as a result. Help Dwarf Misha and find out whether two gnomes belong to the same race or not.

Input
The first line contains the first dwarf's genome: a non-empty string, consisting of lowercase Latin letters.

The second line contains the second dwarf's genome: a non-empty string, consisting of lowercase Latin letters.

The number of letters in each genome doesn't exceed 105. It is guaranteed that the strings that correspond to the genomes are different. The given genomes may have different length.

Output
Print "YES", if the dwarves belong to the same race. Otherwise, print "NO".

Sample test(s)
input
ab
ba
output
YES
input
aa
ab
output
NO
Note
First example: you can simply swap two letters in string "ab". So we get "ba".
Second example: we can't change string "aa" into string "ab", because "aa" does not contain letter "b".

*/