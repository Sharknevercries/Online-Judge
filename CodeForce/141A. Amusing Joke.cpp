/* 1214316	 Feb 21, 2012 5:17:36 PM	Shark	 141A - Amusing Joke	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str1[1000],str2[1000],str3[1000];
	while(scanf("%s%s%s",str1,str2,str3)==3){
		int C[26]={0};
		for(int i=0;str1[i]!='\0';i++)
			C[str1[i]-'A']++;
		for(int i=0;str2[i]!='\0';i++)
			C[str2[i]-'A']++;
		for(int i=0;str3[i]!='\0';i++)
			C[str3[i]-'A']--;

		bool T=true;
		for(int i=0;i<26;i++)
			if(C[i]!=0)
				T=false;
		if(T)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

So, the New Year holidays are over. Santa Claus and his colleagues can take a rest and have guests at last. When two "New Year and Christmas Men" meet, thear assistants cut out of cardboard the letters from the guest's name and the host's name in honor of this event. Then the hung the letters above the main entrance. One night, when everyone went to bed, someone took all the letters of our characters' names. Then he may have shuffled the letters and put them in one pile in front of the door.

The next morning it was impossible to find the culprit who had made the disorder. But everybody wondered whether it is possible to restore the names of the host and his guests from the letters lying at the door? That is, we need to verify that there are no extra letters, and that nobody will need to cut more letters.

Help the "New Year and Christmas Men" and their friends to cope with this problem. You are given both inscriptions that hung over the front door the previous night, and a pile of letters that were found at the front door next morning.

Input

The input file consists of three lines: the first line contains the guest's name, the second line contains the name of the residence host and the third line contains letters in a pile that were found at the door in the morning. All lines are not empty and contain only uppercase Latin letters. The length of each line does not exceed 100.

Output

Print "YES" without the quotes, if the letters in the pile could be permuted to make the names of the "New Year and Christmas Men". Otherwise, print "NO" without the quotes.

input

SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
PAPAINOEL
JOULUPUKKI
JOULNAPAOILELUPUKKI
BABBONATALE
FATHERCHRISTMAS
BABCHRISTMASBONATALLEFATHER

output

YES
NO
NO

Note

In the first sample the letters written in the last line can be used to write the names and there won't be any extra letters left.

In the second sample letter "P" is missing from the pile and there's an extra letter "L".

In the third sample there's an extra letter "L".

*/