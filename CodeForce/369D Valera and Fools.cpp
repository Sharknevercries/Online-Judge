/* 5398626	 Dec 9, 2013 8:56:36 PM	Shark	 369D - Valera and Fools	 GNU C++	Accepted	93 ms	35500 KB */
#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
int record[3011][3011];
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int P[3000] = { 0 };
		int AP[3000] = { 0 }; // for all j, AP[j] = 1, where P[i] = 100, i<=j
		int BP[3000] = { 0 }; // for all j, AP[j] = 1, where P[i] > 0, i<=j
		memset(record, 0, sizeof(record));
		for (int i = 0; i < n; i++)
			scanf("%d", &P[i]);
		for (int i = n - 1; i >= 0; i--){
			if (i != n - 1){
				AP[i] = AP[i + 1];
				BP[i] = BP[i + 1];
			}
			AP[i] |= (P[i] == 100);
			BP[i] |= (P[i] > 0);
		}
		std::queue<std::pair<int, int> > Q;
		record[0][1] = 1;
		Q.push(std::make_pair(0, 1));
		int ans = 1;
		while (!Q.empty()){
			std::pair<int, int> tmp = Q.front();
			Q.pop();
			int A = tmp.first;
			int B = tmp.second;
			if (record[A][B] > k || A >= n || B >= n)
				continue;
			if (P[A] > 0 && BP[B] == 1 && record[B + 1][B + 2] == 0){ // A,B are killed
				ans++;
				record[B + 1][B + 2] = record[A][B] + 1;
				Q.push(std::make_pair(B + 1, B + 2));
			}
			if (P[A] > 0 && AP[B] == 0 && record[A][B + 1] == 0){ // B is killed
				ans++;
				record[A][B + 1] = record[A][B] + 1;
				Q.push(std::make_pair(A, B + 1));
			}
			if (P[A] != 100 && BP[B] == 1 && record[B][B + 1] == 0){ // A is killed
				ans++;
				record[B][B + 1] = record[A][B] + 1;
				Q.push(std::make_pair(B, B + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

D. Valera and Fools
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One fine morning, n fools lined up in a row. After that, they numbered each other with numbers from 1 to n, inclusive. Each fool got a unique number. The fools decided not to change their numbers before the end of the fun.

Every fool has exactly k bullets and a pistol. In addition, the fool number i has probability of pi (in percent) that he kills the fool he shoots at.

The fools decided to have several rounds of the fun. Each round of the fun looks like this: each currently living fool shoots at another living fool with the smallest number (a fool is not stupid enough to shoot at himself). All shots of the round are perfomed at one time (simultaneously). If there is exactly one living fool, he does not shoot.

Let's define a situation as the set of numbers of all the living fools at the some time. We say that a situation is possible if for some integer number j (0 ≤ j ≤ k) there is a nonzero probability that after j rounds of the fun this situation will occur.

Valera knows numbers p1, p2, ..., pn and k. Help Valera determine the number of distinct possible situations.

Input
The first line contains two integers n, k (1 ≤ n, k ≤ 3000) — the initial number of fools and the number of bullets for each fool.

The second line contains n integers p1, p2, ..., pn (0 ≤ pi ≤ 100) — the given probabilities (in percent).

Output
Print a single number — the answer to the problem.

Sample test(s)
input
3 3
50 50 50
output
7
input
1 1
100
output
1
input
2 1
100 100
output
2
input
3 3
0 0 0
output
1
Note
In the first sample, any situation is possible, except for situation {1, 2}.

In the second sample there is exactly one fool, so he does not make shots.

In the third sample the possible situations are {1, 2} (after zero rounds) and the "empty" situation {} (after one round).

In the fourth sample, the only possible situation is {1, 2, 3}.

*/