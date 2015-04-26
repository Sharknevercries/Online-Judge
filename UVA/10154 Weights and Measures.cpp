/* 15384717	10154	Weights and Measures	Accepted	C++	0.045	2015-04-25 17:06:36 */
#include<bits\stdc++.h>
using namespace std;
struct Turtle{
	int w, c;
};
Turtle T[10005];
bool cmp(Turtle A, Turtle B){
	return A.c  <  B.c ;
}
int main(){
	freopen("input.txt", "r", stdin);
	int n = 1;
	while (scanf("%d%d", &T[n].w, &T[n].c) == 2)
		n++;
	sort(T, T + n, cmp);
	int DP[10005];
	for (int i = 0; i <= n; i++)
		DP[i] = 1e9;
	DP[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j > 0; j--)
			if (DP[j - 1] <= T[i].c - T[i].w)
				DP[j] = min(DP[j], DP[j - 1] + T[i].w);
	int ans = n;
	while (DP[ans] == 1e9) ans--;
	printf("%d\n", ans);
	return 0;
}
/*

I know, up on top you are seeing great sights,
But down at the bottom, we, too, should have rights.
We turtles can¡¦t stand it. Our shells will all crack!
Besides, we need food. We are starving!¡¨ groaned Mack.
Mack, in an effort to avoid being cracked, has enlisted your advice as to the order in which turtles
should be dispatched to form Yertle¡¦s throne. Each of the five thousand, six hundred and seven turtles
ordered by Yertle has a different weight and strength. Your task is to build the largest stack of turtles
possible.
Input
Standard input consists of several lines, each containing a pair of integers separated by one or more
space characters, specifying the weight and strength of a turtle. The weight of the turtle is in grams.
The strength, also in grams, is the turtle¡¦s overall carrying capacity, including its own weight. That is,
a turtle weighing 300g with a strength of 1000g could carry 700g of turtles on its back. There are at
most 5,607 turtles.
Output
Your output is a single integer indicating the maximum number of turtles that can be stacked without
exceeding the strength of any one.
Sample Input
300 1000
1000 1200
200 600
100 101
Sample Output
3

*/