/* 6926248	 2014-06-20 12:20:25	Shark	 442A - Borya and Hanabi	 GNU C++	Accepted	 15 ms	 0 KB */
#include<cstdio>
#include<string.h>
bool T[5][5];
int convert(char c){
	switch (c){
	case 'R':	return 0;
	case 'G':	return 1;
	case 'B':	return 2;
	case 'Y':	return 3;
	case 'W':	return 4;
	default:	return (int)(c - '1');
	}
}
bool check(int t){
	int C[5][5] = { 0 };
	bool tmp[5][5] = { false };
	bool line[10] = { false };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = T[i][j];
	for (int i = t, j = 0; i > 0; i >>= 1, j++){
		if (i % 2 == 0)	continue;
		line[j] = true;
		if (j < 5)
			for (int k = 0; k < 5; k++)
				C[j][k]++;
		else
			for (int k = 0; k < 5; k++)
				C[k][j - 5]++;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (C[i][j] == 2)
				tmp[i][j] = false;
	while (true){
		bool fix = false;
		for (int i = 0; i < 5; i++){
			int count1 = 0, count2 = 0;
			for (int j = 0; j < 5; j++){
				if (tmp[i][j])
					count1++;
				if (tmp[j][i])
					count2++;
			}
			if (count1 == 1 && line[i]){
				fix = true;
				for (int j = 0; j < 5; j++)
					tmp[i][j] = false;
			}
			if (count2 == 1 && line[i + 5]){
				fix = true;
				for (int j = 0; j < 5; j++)
					tmp[j][i] = false;
			}
		}
		if (!fix)
			break;
	}
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (tmp[i][j])
				count++;
	if (count <= 1)
		return true;
	else
		return false;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(T, false, sizeof(T));
		for (int i = 0; i < n; i++){
			char color, value;
			scanf(" %c%c", &color, &value);
			T[convert(color)][convert(value)] = true;
		}
		int ans = 10;
		for (int i = 0; i < 1024; i++){ // RGBYW12345
			if (check(i)){
				int k = 0;
				for (int j = i; j > 0; j >>= 1)
					if (j % 2 == 1)
						k++;
				if (ans > k)
					ans = k;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
/*

A. Borya and Hanabi
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Have you ever played Hanabi? If not, then you've got to try it out! This problem deals with a simplified version of the game.

Overall, the game has 25 types of cards (5 distinct colors and 5 distinct values). Borya is holding n cards. The game is somewhat complicated by the fact that everybody sees Borya's cards except for Borya himself. Borya knows which cards he has but he knows nothing about the order they lie in. Note that Borya can have multiple identical cards (and for each of the 25 types of cards he knows exactly how many cards of this type he has).

The aim of the other players is to achieve the state when Borya knows the color and number value of each of his cards. For that, other players can give him hints. The hints can be of two types: color hints and value hints.

A color hint goes like that: a player names some color and points at all the cards of this color.

Similarly goes the value hint. A player names some value and points at all the cards that contain the value.

Determine what minimum number of hints the other players should make for Borya to be certain about each card's color and value.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of Borya's cards. The next line contains the descriptions of n cards. The description of each card consists of exactly two characters. The first character shows the color (overall this position can contain five distinct letters — R, G, B, Y, W). The second character shows the card's value (a digit from 1 to 5). Borya doesn't know exact order of the cards they lie in.

Output
Print a single integer — the minimum number of hints that the other players should make.

Sample test(s)
input
2
G3 G3
output
0
input
4
G4 R4 R3 B3
output
2
input
5
B1 Y1 W1 G1 R1
output
4
Note
In the first sample Borya already knows for each card that it is a green three.

In the second sample we can show all fours and all red cards.

In the third sample you need to make hints about any four colors.

*/