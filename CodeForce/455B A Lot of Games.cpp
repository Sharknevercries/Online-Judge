/* 7452200	2014-08-15 14:09:17	Shark	B - A Lot of Games	GNU C++	Accepted	46 ms	10500 KB */
/* Template By Shark */
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
#define MAX_N 100005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int tri[MAX_N][26];
int size, root;
bool win[MAX_N], lose[MAX_N];
int newTree(){
	return ++size;
}
void addTrie(char s[]){
	int v = root;
	for (int i = 0; s[i] != '\0'; i++){
		int c = s[i] - 'a';
		if (tri[v][c] == NONE)
			tri[v][c] = newTree();
		v = tri[v][c];
	}
}
void DFS(int v){
	bool isLeaf = true;
	for (int i = 0; i < 26; i++){
		int target = tri[v][i];
		if (target != NONE){
			isLeaf = false;
			DFS(target);
			win[v] |= !win[target];
			lose[v] |= !lose[target];
		}
	}
	if (isLeaf)
		lose[v] = true;
}
void print(bool res){
	puts(res ? "First" : "Second");
}
int main(){
	int n, k;
	while (scanf("%d%d",&n,&k) == 2){
		memset(tri, NONE, sizeof(tri));
		size = 0, root = newTree();
		for (int i = 0; i < n; i++){
			char S[MAX_N];
			scanf("%s", S);
			addTrie(S);
		}
		memset(win, false, sizeof(win));
		memset(lose, false, sizeof(lose));
		DFS(root);
		if (k == 1)	print(win[root]);
		else if (!win[root])	print(win[root]);
		else if (lose[root])	print(win[root]);
		else if (k % 2 == 1)	print(win[root]);
		else print(!win[root]);
	}
	return 0;
}
/*

B. A Lot of Games
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Andrew, Fedor and Alex are inventive guys. Now they invent the game with strings for two players.

Given a group of n non-empty strings. During the game two players build the word together, initially the word is empty. The players move in turns. On his step player must add a single letter in the end of the word, the resulting word must be prefix of at least one string from the group. A player loses if he cannot move.

Andrew and Alex decided to play this game k times. The player who is the loser of the i-th game makes the first move in the (i + 1)-th game. Guys decided that the winner of all games is the player who wins the last (k-th) game. Andrew and Alex already started the game. Fedor wants to know who wins the game if both players will play optimally. Help him.

Input
The first line contains two integers, n and k (1 ≤ n ≤ 105; 1 ≤ k ≤ 109).

Each of the next n lines contains a single non-empty string from the given group. The total length of all strings from the group doesn't exceed 105. Each string of the group consists only of lowercase English letters.

Output
If the player who moves first wins, print "First", otherwise print "Second" (without the quotes).

Sample test(s)
input
2 3
a
b
output
First
input
3 1
a
b
c
output
First
input
1 2
ab
output
Second

*/