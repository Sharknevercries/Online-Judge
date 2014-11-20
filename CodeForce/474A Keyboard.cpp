/* 8124432	2014-10-07 05:26:53	Shark	474A - Keyboard	GNU C++	Accepted	15 ms	0 KB */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
char T[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main(){
	int fix = 0;
	char c, S[MAX_N];
	scanf("%c %s", &c, S);
	if (c == 'R')
		fix = -1;
	else
		fix = 1;
	for (int i = 0, j; S[i] != '\0'; i++){
		for (j = 0; T[j] != '\0'; j++){
			if (S[i] == T[j])
				break;
		}
		printf("%c", T[j + fix]);
	}
	putchar('\n');
	return 0;
}
/*

A. Keyboard
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Our good friend Mole is trying to code a big message. He is typing on an unusual keyboard with characters arranged in following way:


qwertyuiop
asdfghjkl;
zxcvbnm,./
Unfortunately Mole is blind, so sometimes it is problem for him to put his hands accurately. He accidentally moved both his hands with one position to the left or to the right. That means that now he presses not a button he wants, but one neighboring button (left or right, as specified in input).

We have a sequence of characters he has typed and we want to find the original message.

Input
First line of the input contains one letter describing direction of shifting ('L' or 'R' respectively for left or right).

Second line contains a sequence of characters written by Mole. The size of this sequence will be no more than 100. Sequence contains only symbols that appear on Mole's keyboard. It doesn't contain spaces as there is no space on Mole's keyboard.

It is guaranteed that even though Mole hands are moved, he is still pressing buttons on keyboard and not hitting outside it.

Output
Print a line that contains the original message.

Sample test(s)
input
R
s;;upimrrfod;pbr
output
allyouneedislove

*/