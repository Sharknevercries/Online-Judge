/* 7271677	2014-07-28 00:32:51	Shark	452A - Eevee	GNU C++	Accepted	15 ms	0 KB */
/*

Template By Shark

*/
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
char S[10][15] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int pos = -1;
		char Q[10];
		scanf("%s", Q);
		for (int i = 0, j; i < 8; i++){
			if (strlen(S[i]) != n)	continue;
			for (j = 0; j < n; j++){
				if (Q[j] == S[i][j] || Q[j] == '.')
					;
				else
					break;
			}
			if (j >= n)
				pos = i;
		}
		printf("%s\n", S[pos]);
	}
	return 0;
}
/*

A. Eevee
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are solving the crossword problem K from IPSC 2014. You solved all the clues except for one: who does Eevee evolve into? You are not very into pokemons, but quick googling helped you find out, that Eevee can evolve into eight different pokemons: Vaporeon, Jolteon, Flareon, Espeon, Umbreon, Leafeon, Glaceon, and Sylveon.

You know the length of the word in the crossword, and you already know some letters. Designers of the crossword made sure that the answer is unambiguous, so you can assume that exactly one pokemon out of the 8 that Eevee evolves into fits the length and the letters given. Your task is to find it.

Input
First line contains an integer n (6 ≤ n ≤ 8) – the length of the string.

Next line contains a string consisting of n characters, each of which is either a lower case english letter (indicating a known letter) or a dot character (indicating an empty cell in the crossword).

Output
Print a name of the pokemon that Eevee can evolve into that matches the pattern in the input. Use lower case letters only to print the name (in particular, do not capitalize the first letter).

Sample test(s)
input
7
j......
output
jolteon
input
7
...feon
output
leafeon
input
7
.l.r.o.
output
flareon
Note
Here's a set of names in a form you can paste into your solution:

["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"}

*/