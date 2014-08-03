/* 5413183	 Dec 12, 2013 10:15:42 AM	Shark	 366E - Dima and Magic Guitar	 GNU C++	Accepted	530 ms	100 KB */
#include<cstdio>
#include<vector>
#include<map>
#define abs(x) ( (x) >= 0 ? (x) : -(x) )
using namespace std;
struct point{
	int x, y;
};
vector<struct point> Q[10][4]; // record point
int dist[10][4]; // record max distance
void insert(int tone, int dis, int way,struct point P){
	if (dis > dist[tone][way]){
		Q[tone][way].clear();
		Q[tone][way].push_back(P);
		dist[tone][way] = dis;
	}
	else if (dis == dist[tone][way])
		Q[tone][way].push_back(P);
}
int main(){
	int n, m, k, s;
	while (scanf("%d%d%d%d", &n, &m, &k, &s) == 4){
		for (int i = 0; i <= k; i++){
			for (int j = 0; j < 4; j++){
				Q[i][j].clear();
				dist[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int tone;
				struct point P;
				P.x = j, P.y = i;
				scanf("%d", &tone);
				insert(tone, n - 1 - i + m - 1 - j, 0, P); // Left Top
				insert(tone, n - 1 - i + j, 1, P); // Right Top
				insert(tone, i + m - 1 - j, 2, P); // Left Down
				insert(tone, i + j, 3, P); // Right Down
			}
		}
		int record[10][10] = { 0 };
		for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++)
				record[i][j] = -1;
		}
		for (int i = 1; i <= k; i++){ // select every point and compute the distance
			for (int j = i; j <= k; j++){
				for (int p = 0; p < 4; p++){
					for (int q = 0; q < 4; q++){
						for (int a = 0; a < Q[i][p].size(); a++){
							for (int b = 0; b < Q[j][q].size(); b++){
								int x1 = Q[i][p][a].x, x2 = Q[j][q][b].x;
								int y1 = Q[i][p][a].y, y2 = Q[j][q][b].y;
								if (abs(x1 - x2) + abs(y1 - y2) > record[i][j])
									record[j][i] = record[i][j] = abs(x1 - x2) + abs(y1 - y2);
							}
						}
					}
				}
			}
		}
		int p, q, ans = -1;
		scanf("%d", &p);
		for (int i = 1; i < s; i++){
			scanf("%d", &q);
			if (record[p][q]>ans)
				ans = record[p][q];
			p = q;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

E. Dima and Magic Guitar
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima loves Inna very much. He decided to write a song for her. Dima has a magic guitar with n strings and m frets. Dima makes the guitar produce sounds like that: to play a note, he needs to hold one of the strings on one of the frets and then pull the string. When Dima pulls the i-th string holding it on the j-th fret the guitar produces a note, let's denote it as aij. We know that Dima's guitar can produce k distinct notes. It is possible that some notes can be produced in multiple ways. In other words, it is possible that aij = apq at (i, j) ≠ (p, q).

Dima has already written a song — a sequence of s notes. In order to play the song, you need to consecutively produce the notes from the song on the guitar. You can produce each note in any available way. Dima understood that there are many ways to play a song and he wants to play it so as to make the song look as complicated as possible (try to act like Cobein).

We'll represent a way to play a song as a sequence of pairs (xi, yi) (1 ≤ i ≤ s), such that the xi-th string on the yi-th fret produces the i-th note from the song. The complexity of moving between pairs (x1, y1) and (x2, y2) equals  + . The complexity of a way to play a song is the maximum of complexities of moving between adjacent pairs.

Help Dima determine the maximum complexity of the way to play his song! The guy's gotta look cool!

Input
The first line of the input contains four integers n, m, k and s (1 ≤ n, m ≤ 2000, 1 ≤ k ≤ 9, 2 ≤ s ≤ 105).

Then follow n lines, each containing m integers aij (1 ≤ aij ≤ k). The number in the i-th row and the j-th column (aij) means a note that the guitar produces on the i-th string and the j-th fret.

The last line of the input contains s integers qi (1 ≤ qi ≤ k) — the sequence of notes of the song.

Output
In a single line print a single number — the maximum possible complexity of the song.

Sample test(s)
input
4 6 5 7
3 1 2 2 3 1
3 2 2 2 5 5
4 2 2 2 5 3
3 2 2 1 4 3
2 3 1 4 1 5 1
output
8
input
4 4 9 5
4 7 9 5
1 2 1 7
8 3 4 9
5 7 7 2
7 1 9 2 5
output
4

*/