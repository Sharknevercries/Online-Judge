/* 6983615	 2014-06-30 08:33:34	Shark	 208A - Dubstep	 GNU C++	Accepted	 62 ms	 0 KB */
#include<cstdio>
#include<string.h>
int main(){
	char S[1000], T[1000];
	while (scanf("%s", S) == 1){
		int len = strlen(S), ptr = 0;
		bool found = false;
		for (int i = 0; i < len; i++){
			if (i + 2 < len&&S[i] == 'W'&&S[i + 1] == 'U'&&S[i + 2] == 'B'){
				i += 2;
				if (found)
					T[ptr++] = ' ', found = false;
			}
			else{
				T[ptr++] = S[i];
				found = true;
			}
		}
		if (found)
			T[ptr++] = ' ', found = false;
		if (ptr - 1 >= 0)
			T[--ptr] = '\0';
		else
			T[ptr] = '\0';
		printf("%s\n", T);
	}
	return 0;
}
/*

A. Dubstep
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya works as a DJ in the best Berland nightclub, and he often uses dubstep music in his performance. Recently, he has decided to take a couple of old songs and make dubstep remixes from them.

Let's assume that a song consists of some number of words. To make the dubstep remix of this song, Vasya inserts a certain number of words "WUB" before the first word of the song (the number may be zero), after the last word (the number may be zero), and between words (at least one between any pair of neighbouring words), and then the boy glues together all the words, including "WUB", in one string and plays the song at the club.

For example, a song with words "I AM X" can transform into a dubstep remix as "WUBWUBIWUBAMWUBWUBX" and cannot transform into "WUBWUBIAMWUBX".

Recently, Petya has heard Vasya's new dubstep track, but since he isn't into modern music, he decided to find out what was the initial song that Vasya remixed. Help Petya restore the original song.

Input
The input consists of a single non-empty string, consisting only of uppercase English letters, the string's length doesn't exceed 200 characters. It is guaranteed that before Vasya remixed the song, no word contained substring "WUB" in it; Vasya didn't change the word order. It is also guaranteed that initially the song had at least one word.

Output
Print the words of the initial song that Vasya used to make a dubsteb remix. Separate the words with a space.

Sample test(s)
input
WUBWUBABCWUB
output
ABC
input
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
output
WE ARE THE CHAMPIONS MY FRIEND
Note
In the first sample: "WUBWUBABCWUB" = "WUB" + "WUB" + "ABC" + "WUB". That means that the song originally consisted of a single word "ABC", and all words "WUB" were added by Vasya.

In the second sample Vasya added a single word "WUB" between all neighbouring words, in the beginning and in the end, except for words "ARE" and "THE" — between them Vasya added two "WUB".

*/