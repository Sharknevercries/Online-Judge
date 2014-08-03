/* 1214331	 Feb 21, 2012 5:22:53 PM	Shark	 58A - Chat room	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[1000];
	char HELLO[]="hello";
	while(scanf("%s",str)==1){
		int i,j;
		for(i=0,j=0;str[i]!='\0'&&HELLO[j]!='\0';i++)
			if(str[i]==HELLO[j])
				j++;
		if(HELLO[j]=='\0')
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody. Vasya typed the word s. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that it resulted in the word "hello". For example, if Vasya types the word "ahhellllloou", it will be considered that he said hello, and if he types "hlelo", it will be considered that Vasya got misunderstood and he didn't manage to say hello. Determine whether Vasya managed to say hello by the given word s.

Input

The first and only line contains the word s, which Vasya typed. This word consisits of small Latin letters, its length is no less that 1 and no more than 100 letters.

Output

If Vasya managed to say hello, print "YES", otherwise print "NO".

input

ahhellllloou
hlelo

output

YES
NO

*/