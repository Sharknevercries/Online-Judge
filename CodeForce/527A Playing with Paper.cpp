/* 10312791	2015-03-17 19:48:33	Shark	527A - Playing with Paper	GNU C++	Accepted	31 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	long long a, b, ans = 0;
	scanf("%lld%lld", &a, &b);
	if (a < b)	swap(a, b);
	while (b != 0){
		ans += a / b;
		a %= b;
		swap(a, b);
	}
	printf("%lld\n", ans);
	return 0;
}
/*

A. Playing with Paper
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya was sitting on a not so interesting Maths lesson and making an origami from a rectangular a mm  ×  b mm sheet of paper (a > b). Usually the first step in making an origami is making a square piece of paper from the rectangular sheet by folding the sheet along the bisector of the right angle, and cutting the excess part.

After making a paper ship from the square piece, Vasya looked on the remaining (a - b) mm  ×  b mm strip of paper. He got the idea to use this strip of paper in the same way to make an origami, and then use the remainder (if it exists) and so on. At the moment when he is left with a square piece of paper, he will make the last ship from it and stop.

Can you determine how many ships Vasya will make during the lesson?

Input
The first line of the input contains two integers a, b (1 ≤ b < a ≤ 1012) — the sizes of the original sheet of paper.

Output
Print a single integer — the number of ships that Vasya will make.

Sample test(s)
input
2 1
output
2
input
10 7
output
6
input
1000000000000 1
output
1000000000000
Note
Pictures to the first and second sample test.

*/