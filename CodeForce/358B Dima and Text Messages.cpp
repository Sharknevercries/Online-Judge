/* 4904701	 Oct 26, 2013 5:08:58 PM	Shark	 358B - Dima and Text Messages	 GNU C++	Accepted	 15 ms	 1400 KB */
#include<stdio.h>
char S[1000000];
char C[500000];
char word[10000];
int ptr;
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int i,j;
		ptr=0;
		S[ptr++]='<';
		S[ptr++]='3';
		for(i=0;i<n;i++){
			scanf("%s",word);
			for(j=0;word[j]!='\0';)
				S[ptr++]=word[j++];
			S[ptr++]='<';
			S[ptr++]='3';
		}
		scanf("%s",C);
		for(i=j=0;i<ptr&&C[j]!='\0';)
			if( S[i]==C[j] )
				i++,j++;
			else
				j++;

		if( i>=ptr )
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
/*

B. Dima and Text Messages
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Seryozha has a very changeable character. This time he refused to leave the room to Dima and his girlfriend (her hame is Inna, by the way). However, the two lovebirds can always find a way to communicate. Today they are writing text messages to each other.

Dima and Inna are using a secret code in their text messages. When Dima wants to send Inna some sentence, he writes out all words, inserting a heart before each word and after the last word. A heart is a sequence of two characters: the "less" characters (<) and the digit three (3). After applying the code, a test message looks like that: <3word1<3word2<3 ... wordn<3.

Encoding doesn't end here. Then Dima inserts a random number of small English characters, digits, signs "more" and "less" into any places of the message.

Inna knows Dima perfectly well, so she knows what phrase Dima is going to send her beforehand. Inna has just got a text message. Help her find out if Dima encoded the message correctly. In other words, find out if a text message could have been received by encoding in the manner that is described above.

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of words in Dima's message. Next n lines contain non-empty words, one word per line. The words only consist of small English letters. The total length of all words doesn't exceed 105.

The last line contains non-empty text message that Inna has got. The number of characters in the text message doesn't exceed 105. A text message can contain only small English letters, digits and signs more and less.

Output
In a single line, print "yes" (without the quotes), if Dima decoded the text message correctly, and "no" (without the quotes) otherwise.

Sample test(s)
input
3
i
love
you
<3i<3love<23you<3
output
yes
input
7
i
am
not
main
in
the
family
<3i<>3am<3the<3<main<3in<3the<3><3family<3
output
no
Note
Please note that Dima got a good old kick in the pants for the second sample from the statement.

*/