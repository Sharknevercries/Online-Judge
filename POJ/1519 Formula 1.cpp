/* 6166624	20:06:06 20 Mar 2015	Shark	1519. Formula 1	Visual C++ 2010	Accepted	0.156	6 392 KB */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	int status;
	long long way;
};
Node Q[2][20000];
int tail[2], pos[2][1600000];
int mask[20] = { 1 };
int n, m, last;
int scroll;
char T[15][15];
inline int getHash(int x, int y){ return x / mask[y] % 3; }
inline int setHash(int x, int y, int value){ return x + (-getHash(x, y) + value) * mask[y]; }
int change1(int status, int j){
	for (int stack = 0; j < m; j++){
		int tmp = getHash(status, j);
		if (tmp == 1)	stack++;
		if (tmp == 2)	stack--;
		if (stack == 0)
			return setHash(status, j, 1);
	}
	return -1;
}
int change2(int opt, int j)
{
	for (int stack = 0; j >= 0; --j)
	{
		int tmp = getHash(opt, j);
		if (tmp == 2) ++stack;
		if (tmp == 1) --stack;
		if (stack == 0)
			return setHash(opt, j, 2);
	}
	return -1;
}
void enqueue(int status, long long way, int j){
	if (j == m - 1 && getHash(status, m))	return;
	int &index = pos[scroll][status];
	if (index)
		Q[scroll][index].way += way;
	else{
		index = ++tail[scroll];
		Q[scroll][index].status = status;
		Q[scroll][index].way = way;
	}
}
int main(){
	for (int i = 1; i <= 12; i++)
		mask[i] = mask[i - 1] * 3;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", T + i);
		for (int j = 0; j < m; j++)
			if (T[i][j] == '.')
				last = i*m + j;
	}
	enqueue(0, 1, 0);
	scroll = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int head = 1, end = tail[scroll ^ 1]; head <= end; head++){
				int status = Q[scroll ^ 1][head].status;
				long long int way = Q[scroll ^ 1][head].way;
				int left = getHash(status, m), up = getHash(status, j);
				if (T[i][j] == '*'){
					if (left == 0 && up == 0)
						enqueue(status, way, j);
					continue;
				}
				if (left == 0 && up == 0)
					enqueue(setHash(setHash(status, m, 2), j, 1), way, j);
				else if (left == 2 && up == 1)
					enqueue(setHash(setHash(status, m, 0), j, 0), way, j);
				else if (left == 0 || up == 0){
					enqueue(setHash(setHash(status, m, 0), j, left + up), way, j);
					enqueue(setHash(setHash(status, j, 0), m, left + up), way, j);
				}
				else if (left == 1 && up == 1){
					int tmp = change1(status, j);
					enqueue(setHash(setHash(tmp, m, 0), j, 0), way, j);
				}
				else if (left == 2 && up == 2){
					int tmp = change2(status, j);
					enqueue(setHash(setHash(tmp, m, 0), j, 0), way, j);
				}
				else if (left == 1 && up == 2){
					if (i * m + j == last)
						enqueue(setHash(setHash(status, m, 0), j, 0), way, j);
				}
			}
			scroll ^= 1;
			for (int head = 1, end = tail[scroll]; head <= end; head++)
				pos[scroll][Q[scroll][head].status] = 0;
			tail[scroll] = 0;
		}
	}
	printf("%lld\n", Q[scroll ^ 1][pos[scroll ^ 1][0]].way);
	return 0;
}
/*

1519. Formula 1
Time limit: 1.0 second
Memory limit: 64 MB
Background
Regardless of the fact, that Vologda could not get rights to hold the Winter Olympic games of 20**, it is well-known, that the city will conduct one of the Formula 1 events. Surely, for such an important thing a new race circuit should be built as well as hotels, restaurants, international airport - everything for Formula 1 fans, who will flood the city soon. But when all the hotels and a half of the restaurants were built, it appeared, that at the site for the future circuit a lot of gophers lived in their holes. Since we like animals very much, ecologists will never allow to build the race circuit over the holes. So now the mayor is sitting sadly in his office and looking at the map of the circuit with all the holes plotted on it.
Problem
Who will be smart enough to draw a plan of the circuit and keep the city from inevitable disgrace? Of course, only true professionals - battle-hardened programmers from the first team of local technical university!.. But our heroes were not looking for easy life and set much more difficult problem: "Certainly, our mayor will be glad, if we find how many ways of building the circuit are there!" - they said.
It should be said, that the circuit in Vologda is going to be rather simple. It will be a rectangle N*M cells in size with a single circuit segment built through each cell. Each segment should be parallel to one of rectangle's sides, so only right-angled bends may be on the circuit. At the picture below two samples are given for N = M = 4 (gray squares mean gopher holes, and the bold black line means the race circuit). There are no other ways to build the circuit here.
Problem illustration
Input
The first line contains the integer numbers N and M (2 ≤ N, M ≤ 12). Each of the next N lines contains M characters, which are the corresponding cells of the rectangle. Character "." (full stop) means a cell, where a segment of the race circuit should be built, and character "*" (asterisk) - a cell, where a gopher hole is located.
Output
You should output the desired number of ways. It is guaranteed, that it does not exceed 263-1.
Samples
input	output
4 4
**..
....
....
....
2
4 4
....
....
....
....
6
Problem Author: Nikita Rybak, Ilya Grebnov, Dmitry Kovalioff
Problem Source: Timus Top Coders: Third Challenge
Tags: none  (hide tags for unsolved problems)

*/