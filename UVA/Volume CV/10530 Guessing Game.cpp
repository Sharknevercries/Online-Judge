/* 8877142 10530 Guessing Game Accepted C++ 0.008 2011-05-23 13:35:05 */
#include<stdio.h>
#include<string.h>
int main(){
	int i,n;
	char str[10];
	bool m[11]={false};
	while(scanf("%d",&n)==1){
		if(n==0) break;
		(void) getchar();
		gets(str);
		if(strcmp(str,"right on")==0){
			if(!m[n])
				puts("Stan may be honest");
			else
				puts("Stan is dishonest");
			for(i=1;i<11;i++) // reset
				m[i]=false;
		}
		else if(strcmp(str,"too low")==0){
			for(i=n;i>0;i--)
				if(!m[i])
					m[i]=true;				
		}
		else
			for(i=n;i<11;i++)
				if(!m[i])
					m[i]=true;
	}
	return 0;
}
/*

 Stan and Ollie are playing a guessing game. Stan thinks of a number between 1 and 10 and Ollie guesses what the number might be. After each guess, Stan indicates whether Ollie's guess is too high, too low, or right on.
 After playing several rounds, Ollie has become suspicious that Stan cheats; that is, that he changes the number between Ollie's guesses. To prepare his case against Stan, Ollie has recorded a transcript of several games. You are to determine whether or not each transcript proves that Stan is cheating.
 
Standard input consists of several transcripts. Each transcript consists of a number of paired guesses and responses. A guess is a line containing single integer between 1 and 10, and a response is a line containing "too high", "too low", or "right on". Each game ends with "right on". A line containing 0 follows the last transcript.
 
For each game, output a line "Stan is dishonest" if Stan's responses are inconsistent with the final guess and response. Otherwise, print "Stan may be honest".
 
Sample Input

10
too high
3
too low
4
too high
2
right on
5
too low
7
too high
6
right on
0
 
Output for Sample Input

Stan is dishonest
Stan may be honest
 
--------------------------------------------------------------------------------
G. Cormack 

*/