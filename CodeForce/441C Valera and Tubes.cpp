/* 6844399	 2014-06-08 20:21:54	Shark	 C - Valera and Tubes	 GNU C++	Accepted	 46 ms	 3000 KB */
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
vector<int> X[45001];
vector<int> Y[45001];
int n, m, k;
int x, y, state;
void draw(int limit, int num){
	int count = 0;
	while (true){
		if (y >= n)
			return;
		count++;
		X[num].push_back(x);
		Y[num].push_back(y);
		if (state == 0){	//RIGHT
			if (x + 1 < m)
				x++;
			else
				y++, state = 1;
		}
		else if (state == 1){
			if (x - 1 >= 0)
				x--;
			else
				y++, state = 0;
		}
		if (count >= limit)
			return;
	}
}
int main(){
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 0; i < k; i++){
			X[i].clear();
			Y[i].clear();
		}
		x = y = state = 0;
		for (int i = 0; i < k; i++){
			if (i == k - 1)
				draw(9000000, i);
			else
				draw(2, i);
		}
		for (int i = 0; i < k; i++){
			printf("%d", X[i].size());
			for (int j = 0; j < X[i].size(); j++)
				printf(" %d %d", Y[i][j] + 1, X[i][j] + 1);
			putchar('\n');
		}
	}
	return 0;
}
/*

C. Valera and Tubes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valera has got a rectangle table consisting of n rows and m columns. Valera numbered the table rows starting from one, from top to bottom and the columns – starting from one, from left to right. We will represent cell that is on the intersection of row x and column y by a pair of integers (x, y).

Valera wants to place exactly k tubes on his rectangle table. A tube is such sequence of table cells (x1, y1), (x2, y2), ..., (xr, yr), that:

r ≥ 2;
for any integer i (1 ≤ i ≤ r - 1) the following equation |xi - xi + 1| + |yi - yi + 1| = 1 holds;
each table cell, which belongs to the tube, must occur exactly once in the sequence.
Valera thinks that the tubes are arranged in a fancy manner if the following conditions are fulfilled:

no pair of tubes has common cells;
each cell of the table belongs to some tube.
Help Valera to arrange k tubes on his rectangle table in a fancy manner.

Input
The first line contains three space-separated integers n, m, k (2 ≤ n, m ≤ 300; 2 ≤ 2k ≤ n·m) — the number of rows, the number of columns and the number of tubes, correspondingly.

Output
Print k lines. In the i-th line print the description of the i-th tube: first print integer ri (the number of tube cells), then print 2ri integers xi1, yi1, xi2, yi2, ..., xiri, yiri (the sequence of table cells).

If there are multiple solutions, you can print any of them. It is guaranteed that at least one solution exists.

Sample test(s)
input
3 3 3
output
3 1 1 1 2 1 3
3 2 1 2 2 2 3
3 3 1 3 2 3 3
input
2 3 1
output
6 1 1 1 2 1 3 2 3 2 2 2 1
Note
Picture for the first sample:

Picture for the second sample:

*/