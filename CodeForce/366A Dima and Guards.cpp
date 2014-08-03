/* 5218643	 Nov 24, 2013 8:30:29 PM	Shark	 366A - Dima and Guards	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
#define MIN(x,y) ( (x) >= (y) ? (y) : (x) )
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[4][4];
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++)
				scanf("%d", &M[i][j]);
		}

		int ptr;
		bool found = false;
		for (ptr = 0; ptr < 4 && !found; ptr++){
			if (M[ptr][0] + M[ptr][2] <= n){
				printf("%d %d %d\n", ptr + 1, M[ptr][0], n - M[ptr][0]);
				found = true;
			}
			else if (M[ptr][0] + M[ptr][3] <= n){
				printf("%d %d %d\n", ptr + 1, M[ptr][0], n - M[ptr][0]);
				found = true;
			}
			else if (M[ptr][1] + M[ptr][2] <= n){
				printf("%d %d %d\n", ptr + 1, M[ptr][1], n - M[ptr][1]);
				found = true;
			}
			else if (M[ptr][1] + M[ptr][3] <= n){
				printf("%d %d %d\n", ptr + 1, M[ptr][1], n - M[ptr][1]);
				found = true;
			}
		}
		if (!found)
			puts("-1");
	}
	return 0;
}
/*

A. Dima and Guards
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nothing has changed since the last round. Dima and Inna still love each other and want to be together. They've made a deal with Seryozha and now they need to make a deal with the dorm guards...

There are four guardposts in Dima's dorm. Each post contains two guards (in Russia they are usually elderly women). You can bribe a guard by a chocolate bar or a box of juice. For each guard you know the minimum price of the chocolate bar she can accept as a gift and the minimum price of the box of juice she can accept as a gift. If a chocolate bar for some guard costs less than the minimum chocolate bar price for this guard is, or if a box of juice for some guard costs less than the minimum box of juice price for this guard is, then the guard doesn't accept such a gift.

In order to pass through a guardpost, one needs to bribe both guards.

The shop has an unlimited amount of juice and chocolate of any price starting with 1. Dima wants to choose some guardpost, buy one gift for each guard from the guardpost and spend exactly n rubles on it.

Help him choose a post through which he can safely sneak Inna or otherwise say that this is impossible. Mind you, Inna would be very sorry to hear that!

Input
The first line of the input contains integer n (1 ≤ n ≤ 105) — the money Dima wants to spend. Then follow four lines describing the guardposts. Each line contains four integers a, b, c, d (1 ≤ a, b, c, d ≤ 105) — the minimum price of the chocolate and the minimum price of the juice for the first guard and the minimum price of the chocolate and the minimum price of the juice for the second guard, correspondingly.

Output
In a single line of the output print three space-separated integers: the number of the guardpost, the cost of the first present and the cost of the second present. If there is no guardpost Dima can sneak Inna through at such conditions, print -1 in a single line.

The guardposts are numbered from 1 to 4 according to the order given in the input.

If there are multiple solutions, you can print any of them.

Sample test(s)
input
10
5 6 5 6
6 6 7 7
5 8 6 6
9 9 9 9
output
1 5 5
input
10
6 6 6 6
7 7 7 7
4 4 4 4
8 8 8 8
output
3 4 6
input
5
3 3 3 3
3 3 3 3
3 3 3 3
3 3 3 3
output
-1
Note
Explanation of the first example.

The only way to spend 10 rubles to buy the gifts that won't be less than the minimum prices is to buy two 5 ruble chocolates to both guards from the first guardpost.

Explanation of the second example.

Dima needs 12 rubles for the first guardpost, 14 for the second one, 16 for the fourth one. So the only guardpost we can sneak through is the third one. So, Dima can buy 4 ruble chocolate for the first guard and 6 ruble juice of the second guard.

*/