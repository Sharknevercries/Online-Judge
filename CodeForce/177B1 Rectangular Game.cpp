/* 5190381	 Nov 22, 2013 12:56:22 PM	Shark	 177B1 - Rectangular Game	 GNU C++	Accepted	30 ms	200 KB */
#include<stdio.h>
#include<math.h>
#include<algorithm>
int DFS(int n){
	if (n == 1)
		return 0;

	int T[10000];
	int ptr = 0;
	int ans = 0;
	for (int i = 1; i <= sqrt((double)n); i++){
		if (n%i == 0 && i != n){
			ans = DFS(i) + i;
			if ( i*i!=n )
				T[ptr++] = n / i;
		}
	}
	for (int i = 0; i < ptr; i++){
		if (T[i] != n){
			int tmp = DFS(T[i]);
			if (ans < tmp + T[i])
				ans = tmp + T[i];
		}
	}
	return ans;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		printf("%d\n", DFS(n) + n);
	}
	return 0;
}
/*

B1. Rectangular Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Smart Beaver from ABBYY decided to have a day off. But doing nothing the whole day turned out to be too boring, and he decided to play a game with pebbles. Initially, the Beaver has n pebbles. He arranges them in a equal rows, each row has b pebbles (a > 1). Note that the Beaver must use all the pebbles he has, i. e. n = a·b.

10 pebbles are arranged in two rows, each row has 5 pebbles
Once the Smart Beaver has arranged the pebbles, he takes back any of the resulting rows (that is, b pebbles) and discards all other pebbles. Then he arranges all his pebbles again (possibly choosing other values of a and b) and takes back one row, and so on. The game continues until at some point the Beaver ends up with exactly one pebble.

The game process can be represented as a finite sequence of integers c1, ..., ck, where:

c1 = n
ci + 1 is the number of pebbles that the Beaver ends up with after the i-th move, that is, the number of pebbles in a row after some arrangement of ci pebbles (1 ≤ i < k). Note that ci > ci + 1.
ck = 1
The result of the game is the sum of numbers ci. You are given n. Find the maximum possible result of the game.

Input
The single line of the input contains a single integer n — the initial number of pebbles the Smart Beaver has.

The input limitations for getting 30 points are:

2 ≤ n ≤ 50
The input limitations for getting 100 points are:

2 ≤ n ≤ 109
Output
Print a single number — the maximum possible result of the game.

Sample test(s)
input
10
output
16
input
8
output
15
Note
Consider the first example (c1 = 10). The possible options for the game development are:

Arrange the pebbles in 10 rows, one pebble per row. Then c2 = 1, and the game ends after the first move with the result of 11.
Arrange the pebbles in 5 rows, two pebbles per row. Then c2 = 2, and the game continues. During the second move we have two pebbles which can be arranged in a unique way (remember that you are not allowed to put all the pebbles in the same row!) — 2 rows, one pebble per row. c3 = 1, and the game ends with the result of 13.
Finally, arrange the pebbles in two rows, five pebbles per row. The same logic leads us to c2 = 5, c3 = 1, and the game ends with the result of 16 — the maximum possible result.

*/