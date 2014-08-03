/* 6969580	 2014-06-27 16:22:07	Shark	 436B - Om Nom and Spiders	 GNU C++	Accepted	 77 ms	 3900 KB */
#include<cstdio>
char T[2000][2001];
int main(){
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		int count[2000] = { 0 };
		for (int i = 1; i < n; i++){
			for (int j = 0; j < m; j++){
				if (T[i][j] == 'D')
					continue;
				if (T[i][j] == 'U' && i % 2 == 0)
					count[j]++;
				if (T[i][j] == 'L'&&j - i >= 0)
					count[j - i]++;
				if (T[i][j] == 'R'&&j + i < m)
					count[j + i]++;
			}
		}
		printf("%d", count[0]);
		for (int i = 1; i < m; i++)
			printf(" %d", count[i]);
		putchar('\n');
	}
	return 0;
}
/*

B. Om Nom and Spiders
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Om Nom really likes candies and doesn't like spiders as they frequently steal candies. One day Om Nom fancied a walk in a park. Unfortunately, the park has some spiders and Om Nom doesn't want to see them at all.

The park can be represented as a rectangular n × m field. The park has k spiders, each spider at time 0 is at some cell of the field. The spiders move all the time, and each spider always moves in one of the four directions (left, right, down, up). In a unit of time, a spider crawls from his cell to the side-adjacent cell in the corresponding direction. If there is no cell in the given direction, then the spider leaves the park. The spiders do not interfere with each other as they move. Specifically, one cell can have multiple spiders at the same time.

Om Nom isn't yet sure where to start his walk from but he definitely wants:

to start walking at time 0 at an upper row cell of the field (it is guaranteed that the cells in this row do not contain any spiders);
to walk by moving down the field towards the lowest row (the walk ends when Om Nom leaves the boundaries of the park).
We know that Om Nom moves by jumping. One jump takes one time unit and transports the little monster from his cell to either a side-adjacent cell on the lower row or outside the park boundaries.

Each time Om Nom lands in a cell he sees all the spiders that have come to that cell at this moment of time. Om Nom wants to choose the optimal cell to start the walk from. That's why he wonders: for each possible starting cell, how many spiders will he see during the walk if he starts from this cell? Help him and calculate the required value for each possible starting cell.

Input
The first line contains three integers n, m, k (2 ≤ n, m ≤ 2000; 0 ≤ k ≤ m(n - 1)).

Each of the next n lines contains m characters — the description of the park. The characters in the i-th line describe the i-th row of the park field. If the character in the line equals ".", that means that the corresponding cell of the field is empty; otherwise, the character in the line will equal one of the four characters: "L" (meaning that this cell has a spider at time 0, moving left), "R" (a spider moving right), "U" (a spider moving up), "D" (a spider moving down).

It is guaranteed that the first row doesn't contain any spiders. It is guaranteed that the description of the field contains no extra characters. It is guaranteed that at time 0 the field contains exactly k spiders.

Output
Print m integers: the j-th integer must show the number of spiders Om Nom will see if he starts his walk from the j-th cell of the first row. The cells in any row of the field are numbered from left to right.

Sample test(s)
input
3 3 4
...
R.L
R.U
output
0 2 2
input
2 2 2
..
RL
output
1 1
input
2 2 2
..
LR
output
0 0
input
3 4 8
....
RRLL
UUUU
output
1 3 3 1
input
2 2 2
..
UU
output
0 0
Note
Consider the first sample. The notes below show how the spider arrangement changes on the field over time:

...        ...        ..U       ...
R.L   ->   .*U   ->   L.R   ->  ...
R.U        .R.        ..R       ...

Character "*" represents a cell that contains two spiders at the same time.

If Om Nom starts from the first cell of the first row, he won't see any spiders.
If he starts from the second cell, he will see two spiders at time 1.
If he starts from the third cell, he will see two spiders: one at time 1, the other one at time 2.

*/