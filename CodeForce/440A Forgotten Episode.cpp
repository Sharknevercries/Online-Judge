/* 6958841	 2014-06-25 20:06:50	Shark	 440A - Forgotten Episode	 GNU C++	Accepted	 46 ms	 100 KB */
#include<cstdio>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		bool S[100000] = { false };
		for (int i = 0; i < n - 1; i++){
			int a;
			scanf("%d", &a);
			S[a - 1] = true;
		}
		for (int i = 0; i < n; i++)
			if (!S[i])
				printf("%d\n", i + 1);
	}
	return 0;
}
/*

A. Forgotten Episode
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus adores TV series. Right now he is ready to finish watching a season of a popular sitcom "Graph Theory". In total, the season has n episodes, numbered with integers from 1 to n.

Polycarpus watches episodes not one by one but in a random order. He has already watched all the episodes except for one. Which episode has Polycaprus forgotten to watch?

Input
The first line of the input contains integer n (2 ≤ n ≤ 100000) — the number of episodes in a season. Assume that the episodes are numbered by integers from 1 to n.

The second line contains n - 1 integer a1, a2, ..., an (1 ≤ ai ≤ n) — the numbers of episodes that Polycarpus has watched. All values of ai are distinct.

Output
Print the number of the episode that Polycarpus hasn't watched.

Sample test(s)
input
10
3 8 10 1 7 9 6 5 2
output
4

*/