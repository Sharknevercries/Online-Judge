/* 9695856	2015-02-03 08:25:32	Shark	510D - Fox And Jumping	GNU C++	Accepted	93 ms	1000 KB */
#include<bits\stdc++.h>
using namespace std; 
struct card{
	int L, C;
};
card T[500];
int DP[500][1 << 9];
int m[1 << 9];
vector<int> prime;
int n, ans;
int DFS(int cur, int mask){
	if (cur == n + 1){
		if (mask == (1 << prime.size()) - 1)
			return 0;
		else
			return 1e9;
	}
	else{
		int &res = DP[cur][mask];
		if (res != -1)	return res;
		res = 1e9;
		res = min(res, DFS(cur + 1, mask));
		res = min(res, DFS(cur + 1, mask | m[cur]) + T[cur].C);
		return res;
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &T[i].L); 
	for (int i = 1; i <= n; i++)
		scanf("%d", &T[i].C);
	ans = 1e9;
	for (int i = 1; i <= n; i++){
		prime.clear();
		int tmp = T[i].L;
		for (int j = 2; j*j <= tmp; j++){
			if (tmp % j == 0){
				prime.push_back(j);
				while (tmp % j == 0)
					tmp /= j;
			}
		}
		if (tmp > 1)
			prime.push_back(tmp);
		memset(m, 0, sizeof(m));
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < prime.size(); k++){
				if (T[j].L % prime[k] != 0)
					m[j] |= (1 << k);
			}
		}
		memset(DP, -1, sizeof(DP));
		ans = min(ans, T[i].C + DFS(1, 0));
	}
	if (ans == 1e9)
		ans = -1;
	printf("%d\n", ans);

	return 0;
}
/*

D. Fox And Jumping
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel is playing a game. In this game there is an infinite long tape with cells indexed by integers (positive, negative and zero). At the beginning she is standing at the cell 0.

There are also n cards, each card has 2 attributes: length li and cost ci. If she pays ci dollars then she can apply i-th card. After applying i-th card she becomes able to make jumps of length li, i. e. from cell x to cell (x - li) or cell (x + li).

She wants to be able to jump to any cell on the tape (possibly, visiting some intermediate cells). For achieving this goal, she wants to buy some cards, paying as little money as possible.

If this is possible, calculate the minimal cost.

Input
The first line contains an integer n (1 ≤ n ≤ 300), number of cards.

The second line contains n numbers li (1 ≤ li ≤ 109), the jump lengths of cards.

The third line contains n numbers ci (1 ≤ ci ≤ 105), the costs of cards.

Output
If it is impossible to buy some cards and become able to jump to any cell, output -1. Otherwise output the minimal cost of buying such set of cards.

Sample test(s)
input
3
100 99 9900
1 1 1
output
2
input
5
10 20 30 40 50
1 1 1 1 1
output
-1
input
7
15015 10010 6006 4290 2730 2310 1
1 1 1 1 1 1 10
output
6
input
8
4264 4921 6321 6984 2316 8432 6120 1026
4264 4921 6321 6984 2316 8432 6120 1026
output
7237
Note
In first sample test, buying one card is not enough: for example, if you buy a card with length 100, you can't jump to any cell whose index is not a multiple of 100. The best way is to buy first and second card, that will make you be able to jump to any cell.

In the second sample test, even if you buy all cards, you can't jump to any cell whose index is not a multiple of 10, so you should output -1.

*/