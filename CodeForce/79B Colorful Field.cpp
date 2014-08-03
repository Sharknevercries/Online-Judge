/* 5189748	 Nov 22, 2013 11:13:24 AM	Shark	 79B - Colorful Field	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
struct point{
	int x, y;
};
int main(){
	int n, m, k, t;
	while (scanf("%d%d%d%d", &n, &m, &k, &t) == 4){
		struct point B[1000];
		for (int i = 0; i < k; i++)
			scanf("%d%d", &B[i].y, &B[i].x);
		for (int i = 0; i < t; i++){
			struct point Q;
			int pos;
			bool block = false;
			scanf("%d%d", &Q.y, &Q.x);
			pos = (Q.y - 1)*m + Q.x;
			for (int j = 0; j < k; j++){
				if (Q.y > B[j].y || (Q.y == B[j].y&&Q.x > B[j].x)){
					pos--;
				}
				if (Q.x == B[j].x&&Q.y == B[j].y){
					block = true;
					break;
				}
			}
			if (block){
				puts("Waste");
			}
			else{
				switch (pos % 3){
				case 0:	puts("Grapes");	break;
				case 1:	puts("Carrots");	break;
				case 2:	puts("Kiwis");	break;
				}
			}
		}
	}
	return 0;
}
/*

B. Colorful Field
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel saw a large field while she was on a bus. The field was a n × m rectangle divided into 1 × 1 cells. Some cells were wasteland, and other each cell contained crop plants: either carrots or kiwis or grapes.

After seeing the field carefully, Ciel found that the crop plants of each cell were planted in following procedure:

Assume that the rows are numbered 1 to n from top to bottom and the columns are numbered 1 to m from left to right, and a cell in row i and column j is represented as (i, j).
First, each field is either cultivated or waste. Crop plants will be planted in the cultivated cells in the order of (1, 1) → ... → (1, m) → (2, 1) → ... → (2, m) → ... → (n, 1) → ... → (n, m). Waste cells will be ignored.
Crop plants (either carrots or kiwis or grapes) will be planted in each cell one after another cyclically. Carrots will be planted in the first cell, then kiwis in the second one, grapes in the third one, carrots in the forth one, kiwis in the fifth one, and so on.
The following figure will show you the example of this procedure. Here, a white square represents a cultivated cell, and a black square represents a waste cell.


Now she is wondering how to determine the crop plants in some certain cells.

Input
In the first line there are four positive integers n, m, k, t (1 ≤ n ≤ 4·104, 1 ≤ m ≤ 4·104, 1 ≤ k ≤ 103, 1 ≤ t ≤ 103), each of which represents the height of the field, the width of the field, the number of waste cells and the number of queries that ask the kind of crop plants in a certain cell.

Following each k lines contains two integers a, b (1 ≤ a ≤ n, 1 ≤ b ≤ m), which denotes a cell (a, b) is waste. It is guaranteed that the same cell will not appear twice in this section.

Following each t lines contains two integers i, j (1 ≤ i ≤ n, 1 ≤ j ≤ m), which is a query that asks you the kind of crop plants of a cell (i, j).

Output
For each query, if the cell is waste, print Waste. Otherwise, print the name of crop plants in the cell: either Carrots or Kiwis or Grapes.

Sample test(s)
input
4 5 5 6
4 3
1 3
3 3
2 5
3 2
1 3
1 4
2 3
2 4
1 1
1 1
output
Waste
Grapes
Carrots
Kiwis
Carrots
Carrots
Note
The sample corresponds to the figure in the statement.

*/