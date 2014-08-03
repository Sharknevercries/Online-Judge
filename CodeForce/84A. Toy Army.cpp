/* 1214471	 Feb 21, 2012 6:06:55 PM	Shark	 84A - Toy Army	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		printf("%d\n",n/2*3);
	}
	return 0;
}
/*

The hero of our story, Valera, and his best friend Arcady are still in school, and therefore they spend all the free time playing turn-based strategy "GAGA: Go And Go Again". The gameplay is as follows.

There are two armies on the playing field each of which consists of n men (n is always even). The current player specifies for each of her soldiers an enemy's soldier he will shoot (a target) and then all the player's soldiers shot simultaneously. This is a game world, and so each soldier shoots perfectly, that is he absolutely always hits the specified target. If an enemy soldier is hit, he will surely die. It may happen that several soldiers had been indicated the same target. Killed soldiers do not participate in the game anymore.

The game "GAGA" consists of three steps: first Valera makes a move, then Arcady, then Valera again and the game ends.

You are asked to calculate the maximum total number of soldiers that may be killed during the game.

Input

The input data consist of a single integer n (2 ≤ n ≤ 108, n is even). Please note that before the game starts there are 2n soldiers on the fields.

Output

Print a single number — a maximum total number of soldiers that could be killed in the course of the game in three turns.

input

2
4

output

3
6

Note

The first sample test:

1) Valera's soldiers 1 and 2 shoot at Arcady's soldier 1.

2) Arcady's soldier 2 shoots at Valera's soldier 1.

3) Valera's soldier 1 shoots at Arcady's soldier 2.

There are 3 soldiers killed in total: Valera's soldier 1 and Arcady's soldiers 1 and 2.

*/