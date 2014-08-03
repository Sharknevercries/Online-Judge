/* 6700359	 May 24, 2014 12:49:29 PM	Shark	 434A - Ryouko's Memory Note	 GNU C++	Accepted	 62 ms	 3400 KB */
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int S[100001];
vector<int> Q[100001];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		unsigned long long sum = 0;
		unsigned long long ans = 4e10;
		for (int i = 0; i < n; i++)
			Q[i].clear();

		int pre = -1;
		for (int i = 0; i < m; i++){
			scanf("%d", S + i);
			if (pre != -1){
				sum += abs(S[i] - pre);
				if (pre != S[i]){
					Q[S[i]].push_back(S[i - 1]);
					Q[S[i - 1]].push_back(S[i]);
				}
			}
			pre = S[i];
		}
		for (int i = 1; i <= n; i++)
			sort(Q[i].begin(), Q[i].end());
		for (int i = 1; i <= n; i++){
			unsigned long long res = 0, ori = 0;
			int len = Q[i].size(), mid;
			if (len > 0)
				mid = Q[i][len / 2];
			for (int j = 0; j < len; j++){
				ori += abs(Q[i][j] - i);
				res += abs(Q[i][j] - mid);
			}
			if (sum - ori + res < ans)
				ans = sum - ori + res;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
/*

A. Ryouko's Memory Note
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ryouko is an extremely forgetful girl, she could even forget something that has just happened. So in order to remember, she takes a notebook with her, called Ryouko's Memory Note. She writes what she sees and what she hears on the notebook, and the notebook became her memory.

Though Ryouko is forgetful, she is also born with superb analyzing abilities. However, analyzing depends greatly on gathered information, in other words, memory. So she has to shuffle through her notebook whenever she needs to analyze, which is tough work.

Ryouko's notebook consists of n pages, numbered from 1 to n. To make life (and this problem) easier, we consider that to turn from page x to page y, |x - y| pages should be turned. During analyzing, Ryouko needs m pieces of information, the i-th piece of information is on page ai. Information must be read from the notebook in order, so the total number of pages that Ryouko needs to turn is .

Ryouko wants to decrease the number of pages that need to be turned. In order to achieve this, she can merge two pages of her notebook. If Ryouko merges page x to page y, she would copy all the information on page x to y (1 ≤ x, y ≤ n), and consequently, all elements in sequence a that was x would become y. Note that x can be equal to y, in which case no changes take place.

Please tell Ryouko the minimum number of pages that she needs to turn. Note she can apply the described operation at most once before the reading. Note that the answer can exceed 32-bit integers.

Input
The first line of input contains two integers n and m (1 ≤ n, m ≤ 105).

The next line contains m integers separated by spaces: a1, a2, ..., am (1 ≤ ai ≤ n).

Output
Print a single integer — the minimum number of pages Ryouko needs to turn.

Sample test(s)
input
4 6
1 2 3 4 3 2
output
3
input
10 5
9 4 3 8 8
output
6
Note
In the first sample, the optimal solution is to merge page 4 to 3, after merging sequence a becomes {1, 2, 3, 3, 3, 2}, so the number of pages Ryouko needs to turn is |1 - 2| + |2 - 3| + |3 - 3| + |3 - 3| + |3 - 2| = 3.

In the second sample, optimal solution is achieved by merging page 9 to 4.

*/