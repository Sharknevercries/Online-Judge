/* 1294305	 Mar 6, 2012 5:40:04 PM	Shark	 106A - Card Game	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int point(char c){
	switch(c){
	case '6':	return 6;
	case '7':	return 7;
	case '8':	return 8;
	case '9':	return 9;
	case 'T':	return 10;
	case 'J':	return 11;
	case 'Q':	return 12;
	case 'K':	return 13;
	case 'A':	return 14;
	}
}
bool cmp(char card1[],char card2[],char trump[]){
	if(card1[1]==card2[1])
		if(point(card1[0])>point(card2[0]))
			return true;
		else
			return false;
	else if(trump[0]==card1[1]||trump[0]==card2[1])
		if(trump[0]==card1[1])
			return true;
		else
			return false;
	else
		return false;
}
int main(){
	char trump[5];
	while(scanf("%s",trump)==1){
		char card1[10],card2[10];
		scanf("%s%s",card1,card2);
		if(cmp(card1,card2,trump))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

There is a card game called "Durak", which means "Fool" in Russian. The game is quite popular in the countries that used to form USSR. The problem does not state all the game's rules explicitly ¡X you can find them later yourselves if you want.

To play durak you need a pack of 36 cards. Each card has a suit ("S", "H", "D" and "C") and a rank (in the increasing order "6", "7", "8", "9", "T", "J", "Q", "K" and "A"). At the beginning of the game one suit is arbitrarily chosen as trump.

The players move like that: one player puts one or several of his cards on the table and the other one should beat each of them with his cards.

A card beats another one if both cards have similar suits and the first card has a higher rank then the second one. Besides, a trump card can beat any non-trump card whatever the cards¡¦ ranks are. In all other cases you can not beat the second card with the first one.

You are given the trump suit and two different cards. Determine whether the first one beats the second one or not.

Input

The first line contains the tramp suit. It is "S", "H", "D" or "C".

The second line contains the description of the two different cards. Each card is described by one word consisting of two symbols. The first symbol stands for the rank ("6", "7", "8", "9", "T", "J", "Q", "K" and "A"), and the second one stands for the suit ("S", "H", "D" and "C").

Output

Print "YES" (without the quotes) if the first cards beats the second one. Otherwise, print "NO" (also without the quotes).

input

H
QH 9S
S
8D 6D
C
7H AS

output

YES
YES
NO

*/