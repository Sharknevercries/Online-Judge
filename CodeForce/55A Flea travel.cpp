/* 5528659	 Dec 27, 2013 11:06:12 AM	Shark	 55A - Flea travel	 GNU C++	Accepted	30 ms	0 KB */
#include<cstdio.>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		bool visited[1000] = { false };
		int count = 0, pos = 0;
		for (int k = 0; k < 100000; k++){
			pos = (pos + k) % n;
			if (!visited[pos])
				count++;
			visited[pos] = true;
		}
		if (count == n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

A. Flea travel
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A flea is sitting at one of the n hassocks, arranged in a circle, at the moment. After minute number k the flea jumps through k - 1 hassoсks (clockwise). For example, after the first minute the flea jumps to the neighboring hassock. You should answer: will the flea visit all the hassocks or not. We assume that flea has infinitely much time for this jumping.

Input
The only line contains single integer: 1 ≤ n ≤ 1000 — number of hassocks.

Output
Output "YES" if all the hassocks will be visited and "NO" otherwise.

Sample test(s)
input
1
output
YES
input
3
output
NO

*/