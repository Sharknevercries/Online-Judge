/* 6962504	 2014-06-26 13:50:41	Shark	 442C - Artem and Array	 GNU C++	Accepted	 109 ms	 3900 KB */
#include<cstdio>
#include<algorithm>
#define MIN(x,y) ( (x) >= (y) ? (y) : (x) )
using namespace std;
int M[500000];
int S[500000], ptr;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		long long int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		ptr = 0;
		for (int i = 0; i < n; i++){ // H L H
			while (ptr >= 2 && S[ptr - 1] <= S[ptr - 2] && M[i] >= S[ptr - 1]){
				ans += MIN(S[ptr - 2], M[i]);
				ptr--;
			}
			S[ptr++] = M[i];
		}
		sort(S, S + ptr);
		for (int i = 0; i < ptr - 2; i++)
			ans += S[i];
		printf("%lld\n", ans);
	}
	return 0;
}
/*

C. Artem and Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Artem has an array of n positive integers. Artem decided to play with it. The game consists of n moves. Each move goes like this. Artem chooses some element of the array and removes it. For that, he gets min(a, b) points, where a and b are numbers that were adjacent with the removed number. If the number doesn't have an adjacent number to the left or right, Artem doesn't get any points.

After the element is removed, the two parts of the array glue together resulting in the new array that Artem continues playing with. Borya wondered what maximum total number of points Artem can get as he plays this game.

Input
The first line contains a single integer n (1 ≤ n ≤ 5·105) — the number of elements in the array. The next line contains n integers ai (1 ≤ ai ≤ 106) — the values of the array elements.

Output
In a single line print a single integer — the maximum number of points Artem can get.

Sample test(s)
input
5
3 1 5 2 6
output
11
input
5
1 2 3 4 5
output
6
input
5
1 100 101 100 1
output
102

*/