/* 6970438	 2014-06-27 19:03:55	Shark	 436C - Dungeons and Candies	 GNU C++	Accepted	 156 ms	 100 KB */
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
char T[1000][10][10];
int E[1000];
int F[1000];
vector < pair<int, int> > A;
bool V[1000];
int n, m, k, w;
int differ(int i, int j){
	int dif = 0;
	for (int p = 0; p < n; p++)
		for (int q = 0; q < m; q++)
			if (T[i][p][q] != T[j][p][q])
				dif++;
	return dif;
}
int main(){
	while (scanf("%d%d%d%d", &n, &m, &k, &w) == 4){
		A.clear();
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++)
				scanf("%s", T[i][j]);
		for (int i = 0; i < k; i++)
			E[i] = n*m, F[i] = 0;
		memset(V, false, sizeof(V));
		int ans = 0;
		for (int i = 0; i < k; i++){
			int min = 2000, pos = -1;
			for (int j = 0; j < k; j++)
				if (!V[j] && (pos == -1 || E[j] < min))
					min = E[j], pos = j;
			A.push_back(make_pair(pos + 1, F[pos]));
			V[pos] = true;
			ans += E[pos];
			for (int j = 0; j < k; j++){
				if (!V[j]){
					int cost = differ(pos, j)*w;
					if (cost < E[j]){
						E[j] = cost;
						F[j] = pos + 1;
					}
				}
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < A.size(); i++)
			printf("%d %d\n", A[i].first, A[i].second);
	}
	return 0;
}
/*

C. Dungeons and Candies
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
During the loading of the game "Dungeons and Candies" you are required to get descriptions of k levels from the server. Each description is a map of an n × m checkered rectangular field. Some cells of the field contain candies (each cell has at most one candy). An empty cell is denoted as "." on the map, but if a cell has a candy, it is denoted as a letter of the English alphabet. A level may contain identical candies, in this case the letters in the corresponding cells of the map will be the same.

When you transmit information via a network, you want to minimize traffic — the total size of the transferred data. The levels can be transmitted in any order. There are two ways to transmit the current level A:

You can transmit the whole level A. Then you need to transmit n·m bytes via the network.
You can transmit the difference between level A and some previously transmitted level B (if it exists); this operation requires to transmit dA, B·w bytes, where dA, B is the number of cells of the field that are different for A and B, and w is a constant. Note, that you should compare only the corresponding cells of levels A and B to calculate dA, B. You cannot transform the maps of levels, i.e. rotate or shift them relatively to each other.
Your task is to find a way to transfer all the k levels and minimize the traffic.

Input
The first line contains four integers n, m, k, w (1 ≤ n, m ≤ 10; 1 ≤ k, w ≤ 1000). Then follows the description of k levels. Each level is described by n lines, each line contains m characters. Each character is either a letter of the English alphabet or a dot ("."). Please note that the case of the letters matters.

Output
In the first line print the required minimum number of transferred bytes.

Then print k pairs of integers x1, y1, x2, y2, ..., xk, yk, describing the way to transfer levels. Pair xi, yi means that level xi needs to be transferred by way yi. If yi equals 0, that means that the level must be transferred using the first way, otherwise yi must be equal to the number of a previously transferred level. It means that you will transfer the difference between levels yi and xi to transfer level xi. Print the pairs in the order of transferring levels. The levels are numbered 1 through k in the order they follow in the input.

If there are multiple optimal solutions, you can print any of them.

Sample test(s)
input
2 3 3 2
A.A
...
A.a
..C
X.Y
...
output
14
1 0
2 1
3 1
input
1 1 4 1
A
.
B
.
output
3
1 0
2 0
4 2
3 0
input
1 3 5 2
ABA
BBB
BBA
BAB
ABB
output
11
1 0
3 1
2 3
4 2
5 1

*/