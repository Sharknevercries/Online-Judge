/* 13058376	12646	Zero or One	Accepted	C++	0.019	2014-01-30 17:49:33 */
#include<cstdio>
int main(){
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3){
		int count = a + b + c;
		if (count == 1 || count == 2){
			if (a == b)
				puts("C");
			else if (a == c)
				puts("B");
			else
				puts("A");
		}
		else
			puts("*");
	}
	return 0;
}
/*

Everyone probably knows the game Zero or One (in some regions in Brazil also known as Two or
One), used to determine a winner among three or more players. For those unfamiliar, the game works
as follows. Each player chooses a value between zero or one; prompted by a command (usually one of
the contestants announces \Zero or... One!"), all participants show the value chosen using a hand: if
the value chosen is one, the contestant shows a hand with an extended index nger; if the value chosen
is zero, the contestant shows a hand with all ngers closed. The winner is the one who has chosen
a value dierent from all others. If there is no player with a value dierent from all others (e.g. all
players choose zero, or some players choose zero and some players choose one), there is no winner.
Alice, Bob and Clara are great friends and play Zerinho all the time: to determine who will buy
popcorn during the movie session, who will enter the swimming pool rst, etc.. They play so much that
they decided make a plugin to play Zerinho on Facebook. But since the don't know how to program
computers, they divided the tasks among friends who do know, including you.
Given the three values chosen by Alice, Bob and Clara, each value zero or one, write a program
that determines if there is a winner, and in that case determines who is the winner.
Input
The input contains several test cases. Each test case contains a single line, with three integers A, B
and C, indicating respectively the values chosen by Alice, Beto and Clara.
Output
For each test case your program must output a single line, containing a single character. If Alice is the
winner the character must be `A', if Beto is the winner the character must be `B', if Clara is the winner
the character must be `C', and if there is no winner the character must be `*' (asterisc).
Restrictions
 A;B;C 2 f0; 1g
Sample Input
1 1 0
0 0 0
1 0 0
Sample Output
C
*
A

*/