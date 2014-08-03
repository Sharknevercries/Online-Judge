/* 5389765	 Dec 8, 2013 4:27:17 PM	Shark	 B - Fox Dividing Cheese	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
int GCD(int a, int b){
	int r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int main(){
	int a, b;
	while (scanf("%d%d", &a, &b) == 2){
		int gcd = GCD(a, b);
		int ans = 0;
		a /= gcd;
		b /= gcd;
		while (a % 2 == 0)	a /= 2, ans++;
		while (a % 3 == 0)	a /= 3, ans++;
		while (a % 5 == 0)	a /= 5, ans++;
		while (b % 2 == 0)	b /= 2, ans++;
		while (b % 3 == 0)	b /= 3, ans++;
		while (b % 5 == 0)	b /= 5, ans++;
		if (a == 1 && b == 1)
			printf("%d\n", ans);
		else
			puts("-1");
	}
	return 0;
}
/*

B. Fox Dividing Cheese
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Two little greedy bears have found two pieces of cheese in the forest of weight a and b grams, correspondingly. The bears are so greedy that they are ready to fight for the larger piece. That's where the fox comes in and starts the dialog: "Little bears, wait a little, I want to make your pieces equal" "Come off it fox, how are you going to do that?", the curious bears asked. "It's easy", said the fox. "If the mass of a certain piece is divisible by two, then I can eat exactly a half of the piece. If the mass of a certain piece is divisible by three, then I can eat exactly two-thirds, and if the mass is divisible by five, then I can eat four-fifths. I'll eat a little here and there and make the pieces equal".

The little bears realize that the fox's proposal contains a catch. But at the same time they realize that they can not make the two pieces equal themselves. So they agreed to her proposal, but on one condition: the fox should make the pieces equal as quickly as possible. Find the minimum number of operations the fox needs to make pieces equal.

Input
The first line contains two space-separated integers a and b (1 ≤ a, b ≤ 109).

Output
If the fox is lying to the little bears and it is impossible to make the pieces equal, print -1. Otherwise, print the required minimum number of operations. If the pieces of the cheese are initially equal, the required number is 0.

Sample test(s)
input
15 20
output
3
input
14 8
output
-1
input
6 6
output
0

*/