/* 10576179	2015-04-04 19:41:19	Shark	526A - King of Thieves	GNU C++	Accepted	15 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int n;
char str[150];
bool solve(){
	for (int i = 0; i < n; i++){
		for (int j = 1; i + j * 4 < n; j++){
			int k;
			for (k = 0; i + j * k < n && k < 5; k++){
				if (str[i + j * k] == '.')
					break;
			}
			if (k >= 5)
				return true;
		}
	}
	return false;
}
int main(){

	scanf("%d%s", &n, str);
	if (solve())
		puts("yes");
	else
		puts("no");

	return 0;
}
/*

A. King of Thieves
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
In this problem you will meet the simplified model of game King of Thieves.

In a new ZeptoLab game called "King of Thieves" your aim is to reach a chest with gold by controlling your character, avoiding traps and obstacles on your way.


An interesting feature of the game is that you can design your own levels that will be available to other players. Let's consider the following simple design of a level.

A dungeon consists of n segments located at a same vertical level, each segment is either a platform that character can stand on, or a pit with a trap that makes player lose if he falls into it. All segments have the same length, platforms on the scheme of the level are represented as '*' and pits are represented as '.'.

One of things that affects speedrun characteristics of the level is a possibility to perform a series of consecutive jumps of the same length. More formally, when the character is on the platform number i1, he can make a sequence of jumps through the platforms i1 < i2 < ... < ik, if i2 - i1 = i3 - i2 = ... = ik - ik - 1. Of course, all segments i1, i2, ... ik should be exactly the platforms, not pits.

Let's call a level to be good if you can perform a sequence of four jumps of the same length or in the other words there must be a sequence i1, i2, ..., i5, consisting of five platforms so that the intervals between consecutive platforms are of the same length. Given the scheme of the level, check if it is good.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of segments on the level.

Next line contains the scheme of the level represented as a string of n characters '*' and '.'.

Output
If the level is good, print the word "yes" (without the quotes), otherwise print the word "no" (without the quotes).

Sample test(s)
input
16
.**.*..*.***.**.
output
yes
input
11
.*.*...*.*.
output
no
Note
In the first sample test you may perform a sequence of jumps through platforms 2, 5, 8, 11, 14.

*/