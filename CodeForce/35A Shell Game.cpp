/* 5205708	 Nov 24, 2013 8:18:14 AM	Shark	 35A - Shell Game	 GNU C++	Accepted	62 ms	200 KB */
#include<stdio.h>
#define SWAP(x,y){	bool tmp=x;	x=y; y=tmp; }
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1){
		bool S[3] = { false };
		S[n - 1] = true;
		for (int i = 0; i < 3; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			SWAP(S[a - 1], S[b - 1]);
		}
		for (int i = 0; i < 3;i++)
			if (S[i])
				printf("%d\n", i + 1);
	}
	return 0;
}
/*

A. Shell Game
time limit per test2 seconds
memory limit per test64 megabytes
inputinput.txt
outputoutput.txt
Today the «Z» city residents enjoy a shell game competition. The residents are gathered on the main square to watch the breath-taking performance. The performer puts 3 non-transparent cups upside down in a row. Then he openly puts a small ball under one of the cups and starts to shuffle the cups around very quickly so that on the whole he makes exactly 3 shuffles. After that the spectators have exactly one attempt to guess in which cup they think the ball is and if the answer is correct they get a prize. Maybe you can try to find the ball too?

Input
The first input line contains an integer from 1 to 3 — index of the cup which covers the ball before the shuffles. The following three lines describe the shuffles. Each description of a shuffle contains two distinct integers from 1 to 3 — indexes of the cups which the performer shuffled this time. The cups are numbered from left to right and are renumbered after each shuffle from left to right again. In other words, the cup on the left always has index 1, the one in the middle — index 2 and the one on the right — index 3.

Output
In the first line output an integer from 1 to 3 — index of the cup which will have the ball after all the shuffles.

Sample test(s)
input
1
1 2
2 1
2 1
output
2
input
1
2 1
3 1
1 3
output
2

*/