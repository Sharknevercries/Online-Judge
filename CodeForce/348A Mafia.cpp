/* 5518962	 Dec 25, 2013 4:58:21 PM	Shark	 A - Mafia	 GNU C++	Accepted	62 ms	0 KB */
#include<cstdio>
#include<cmath>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		long long int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			if (ans < tmp)
				ans = tmp;
			sum += tmp;
		}
		if (ceil((double)sum / (n - 1) < ans))
			printf("%d\n", ans);
		else
			printf("%d\n", (int)ceil((double)sum / (n - 1)));
	}
	return 0;
}
/*

A. Mafia
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day n friends gathered together to play "Mafia". During each round of the game some player must be the supervisor and other n - 1 people take part in the game. For each person we know in how many rounds he wants to be a player, not the supervisor: the i-th person wants to play ai rounds. What is the minimum number of rounds of the "Mafia" game they need to play to let each person play at least as many rounds as they want?

Input
The first line contains integer n (3 ≤ n ≤ 105). The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the i-th number in the list is the number of rounds the i-th person wants to play.

Output
In a single line print a single integer — the minimum number of game rounds the friends need to let the i-th person play at least ai rounds.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Sample test(s)
input
3
3 2 2
output
4
input
4
2 2 2 2
output
3
Note
You don't need to know the rules of "Mafia" to solve this problem. If you're curious, it's a game Russia got from the Soviet times: http://en.wikipedia.org/wiki/Mafia_(party_game).

*/