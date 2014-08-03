/* 4719420	 Oct 9, 2013 9:03:47 PM	Shark	 302B - Eugeny and Play List	 GNU C++	Accepted	156 ms	800 KB */
#include<stdio.h>
struct Song{
	int LTime;
	int RTime;
};
struct Song M[100000];
int ptr;
int Query(int target){
	int L=0;
	int R=ptr-1;
	while( true ){
		int MID=(L+R)/2;
		if( target>=M[MID].LTime&&target<=M[MID].RTime )
			return MID+1;
		else if( target>M[MID].RTime )
			L=MID+1;
		else
			R=MID;
	}
}
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		int cur=1;
		ptr=0;
		for(int i=0;i<n;i++){
			int c,t;
			scanf("%d%d",&c,&t);
			M[ptr].LTime=cur;
			M[ptr].RTime=cur+c*t-1;
			cur=M[ptr].RTime+1;
			ptr++;
		}
		for(int i=0;i<m;i++){
			int T;
			scanf("%d",&T);
			printf("%d\n",Query(T));
		}
	}
	return 0;
}
/*

B. Eugeny and Play List
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Eugeny loves listening to music. He has n songs in his play list. We know that song number i has the duration of ti minutes. Eugeny listens to each song, perhaps more than once. He listens to song number i ci times. Eugeny's play list is organized as follows: first song number 1 plays c1 times, then song number 2 plays c2 times, ..., in the end the song number n plays cn times.

Eugeny took a piece of paper and wrote out m moments of time when he liked a song. Now for each such moment he wants to know the number of the song that played at that moment. The moment x means that Eugeny wants to know which song was playing during the x-th minute of his listening to the play list.

Help Eugeny and calculate the required numbers of songs.

Input
The first line contains two integers n, m (1 ≤ n, m ≤ 105). The next n lines contain pairs of integers. The i-th line contains integers ci, ti (1 ≤ ci, ti ≤ 109) — the description of the play list. It is guaranteed that the play list's total duration doesn't exceed 109 .

The next line contains m positive integers v1, v2, ..., vm, that describe the moments Eugeny has written out. It is guaranteed that there isn't such moment of time vi, when the music doesn't play any longer. It is guaranteed that vi < vi + 1 (i < m).

The moment of time vi means that Eugeny wants to know which song was playing during the vi-th munite from the start of listening to the playlist.

Output
Print m integers — the i-th number must equal the number of the song that was playing during the vi-th minute after Eugeny started listening to the play list.

Sample test(s)
input
1 2
2 8
1 16
output
1
1
input
4 9
1 2
2 1
1 1
2 2
1 2 3 4 5 6 7 8 9
output
1
1
2
2
3
4
4
4
4

*/