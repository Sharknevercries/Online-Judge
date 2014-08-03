/* 1157931	 Feb 8, 2012 7:05:59 PM	Shark	 118A - String Task	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[300],ans[300];
	while(scanf("%s",str)==1){
		int ptr=0;
		for(int i=0;str[i]!='\0';i++)
			if( str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y'||
				str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y' )
				continue;
			else{
				ans[ptr++]='.';
				if(str[i]>='A'&&str[i]<='Z')
					ans[ptr++]=str[i]+32;
				else
					ans[ptr++]=str[i];
			}
		ans[ptr]='\0';
		printf("%s\n",ans);
	}
	return 0;	
}
/*

Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.

Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input

The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output

Print the resulting string. It is guaranteed that this string is not empty.

Sample test(s)

input

tour
Codeforces
aBAcAba

output

.t.r
.c.d.f.r.c.s
.b.c.b

*/