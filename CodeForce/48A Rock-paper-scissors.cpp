/* 5361011	 Dec 6, 2013 6:15:00 PM	Shark	 48A - Rock-paper-scissors	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
#include<string.h>
int main(){
	char A[10], B[10], C[10];
	while (scanf("%s%s%s", A, B, C) == 3){
		if (strcmp(A, "paper") == 0){
			if (strcmp(B, "paper") == 0){
				if (strcmp(C, "scissors") == 0)
					puts("S");
				else
					puts("?");
			}
			else if (strcmp(B, "scissors") == 0){
				if (strcmp(C, "paper") == 0)
					puts("M");
				else
					puts("?");
			}
			else{
				if (strcmp(C, "rock") == 0)
					puts("F");
				else
					puts("?");
			}
		}
		else if (strcmp(A, "scissors") == 0){
			if (strcmp(B, "paper") == 0){
				if (strcmp(C, "paper") == 0)
					puts("F");
				else
					puts("?");
			}
			else if (strcmp(B, "scissors") == 0){
				if (strcmp(C, "rock") == 0)
					puts("S");
				else
					puts("?");
			}
			else{
				if (strcmp(C, "scissors") == 0)
					puts("M");
				else
					puts("?");
			}
		}
		else{
			if (strcmp(B, "paper") == 0){
				if (strcmp(C, "rock") == 0)
					puts("M");
				else
					puts("?");
			}
			else if (strcmp(B, "scissors") == 0){
				if (strcmp(C, "scissors") == 0)
					puts("F");
				else
					puts("?");
			}
			else{
				if (strcmp(C, "paper") == 0)
					puts("S");
				else
					puts("?");
			}
		}
			
	}
	return 0;
}
/*

A. Rock-paper-scissors
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Uncle Fyodor, Matroskin the Cat and Sharic the Dog live their simple but happy lives in Prostokvashino. Sometimes they receive parcels from Uncle Fyodor¡¦s parents and sometimes from anonymous benefactors, in which case it is hard to determine to which one of them the package has been sent. A photographic rifle is obviously for Sharic who loves hunting and fish is for Matroskin, but for whom was a new video game console meant? Every one of the three friends claimed that the present is for him and nearly quarreled. Uncle Fyodor had an idea how to solve the problem justly: they should suppose that the console was sent to all three of them and play it in turns. Everybody got relieved but then yet another burning problem popped up ¡X who will play first? This time Matroskin came up with a brilliant solution, suggesting the most fair way to find it out: play rock-paper-scissors together. The rules of the game are very simple. On the count of three every player shows a combination with his hand (or paw). The combination corresponds to one of three things: a rock, scissors or paper. Some of the gestures win over some other ones according to well-known rules: the rock breaks the scissors, the scissors cut the paper, and the paper gets wrapped over the stone. Usually there are two players. Yet there are three friends, that¡¦s why they decided to choose the winner like that: If someone shows the gesture that wins over the other two players, then that player wins. Otherwise, another game round is required. Write a program that will determine the winner by the gestures they have shown.

Input
The first input line contains the name of the gesture that Uncle Fyodor showed, the second line shows which gesture Matroskin showed and the third line shows Sharic¡¦s gesture.

Output
Print "F" (without quotes) if Uncle Fyodor wins. Print "M" if Matroskin wins and "S" if Sharic wins. If it is impossible to find the winner, print "?".

Sample test(s)
input
rock
rock
rock
output
?
input
paper
rock
rock
output
F
input
scissors
rock
rock
output
?
input
scissors
paper
rock
output
?

*/