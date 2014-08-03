/* 6967701	 2014-06-27 11:39:23	Shark	 442D - Adam and Tree	 GNU C++	Accepted	 405 ms	 15600 KB */
#include<cstdio>
struct node{
	int m1, m2;
	int parent;
	int pre;
};
node S[1000010];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i <= n; i++)
			S[i].m1 = S[i].m2 = S[i].pre = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &S[i].parent);
			S[i].parent--;
		}
		for (int i = 1; i <= n; i++){
			int cur = i;
			int ans = 1;
			while (cur != 0 && S[cur].pre != ans){
				S[cur].pre = ans;
				cur = S[cur].parent;
				if (ans > S[cur].m1)
					S[cur].m2 = S[cur].m1, S[cur].m1 = ans;
				else if (ans > S[cur].m2)
					S[cur].m2 = ans;
				ans = S[cur].m1 > S[cur].m2 + 1 ? S[cur].m1 : S[cur].m2 + 1;
			}
			if (i != 1)
				putchar(' ');
			printf("%d", S[0].m1);
		}
		putchar('\n');
	}
	return 0;
}
/*

D. Adam and Tree
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
When Adam gets a rooted tree (connected non-directed graph without cycles), he immediately starts coloring it. More formally, he assigns a color to each edge of the tree so that it meets the following two conditions:

There is no vertex that has more than two incident edges painted the same color.
For any two vertexes that have incident edges painted the same color (say, c), the path between them consists of the edges of the color c.
Not all tree paintings are equally good for Adam. Let's consider the path from some vertex to the root. Let's call the number of distinct colors on this path the cost of the vertex. The cost of the tree's coloring will be the maximum cost among all the vertexes. Help Adam determine the minimum possible cost of painting the tree.

Initially, Adam's tree consists of a single vertex that has number one and is the root. In one move Adam adds a new vertex to the already existing one, the new vertex gets the number equal to the minimum positive available integer. After each operation you need to calculate the minimum cost of coloring the resulting tree.

Input
The first line contains integer n (1 ≤ n ≤ 106) — the number of times a new vertex is added. The second line contains n numbers pi (1 ≤ pi ≤ i) — the numbers of the vertexes to which we add another vertex.

Output
Print n integers — the minimum costs of the tree painting after each addition.

Sample test(s)
input
11
1 1 1 3 4 4 7 3 7 6 6
output
1 1 1 1 1 2 2 2 2 2 3
Note
The figure below shows one of the possible variants to paint a tree from the sample at the last moment. The cost of the vertexes with numbers 11 and 12 equals 3.

*/