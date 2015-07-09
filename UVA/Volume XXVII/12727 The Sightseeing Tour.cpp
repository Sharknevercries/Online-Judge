/* 15357327	12727	The Sightseeing Tour	Accepted	C++	0.269	2015-04-20 18:17:31 */
#include<bits\stdc++.h>
using namespace std;
struct Segment{
	int L, R, cost;
};
Segment S[35];
bool V[505];
int n, m, k;
bool sortBySegment(Segment A, Segment B){
	return A.R < B.R;
}
void DFS(int L, int R, int cost, int start){
	if (R == n)	V[cost] = true;
	for (int i = start; i < m; i++)
		if (S[i].R > R && (S[i].L == R + 1 || S[i].L > L && S[i].L <= R))
			DFS(R + 1, S[i].R, cost + S[i].cost, i + 1);
}
long long solve(int L, int R){
	long long res = 0;
	for (int i = 305; i >= 1; i--){
		if (V[i] && R >= L && R >= i){
			if (L <= i)
				res += 1LL * i * (R - i + 1);
			else
				res += 1LL * i * (R - L + 1);
			R = i - 1;
		}
	}
	return res;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &S[i].L, &S[i].R, &S[i].cost);
		sort(S, S + m, sortBySegment);
		memset(V, false, sizeof(V));
		DFS(0, 0, 0, 0);
		long long res = 0;
		for (int i = 0; i < k; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			res += solve(a, b);
		}
		printf("Case #%d: %lld\n", c++, res);
	}
	return 0;
}
/*

Skyrk is now living in an old town, full of ancient tales and wonders to behold. No surprise this town
became one of the biggest tourist attractions in the world. Unfortunately, it is rather difficult to move
around the town, since it is very old and surrounded by mountains, its streets are narrow, full of turns
and ups and downs. But this was rather fortunate for Skyrk. He thought a lot of tourists would rather
see the touristic places looking from the top of the mountains instead of adventuring in the old town.
He decided to set sightseeing binoculars on some spots of the biggest mountain near the town, and of
course, charge for their use.
The town has N touristic places, looking from the mountain, they seem to line up from left to right.
Skyrk set up M sightseeing binoculars, each can cover the view from touristic place A up to B and cost
C coins to use. A group of tourists arrived to do a sightseeing tour, and they want to see all touristic
places paying the minimum price. Skyrk knows in advance the price each tourist is willing to pay for
the tour. In order to maximize his profit, he will tell the tourist that only a subset of binoculars are
working, so that when the tourist choose the ones he wants, he ends up paying more.
Input
The first line contains T (T ≤ 100) — the number of test cases, after this line T test cases follows. Each
test case starts with a line with three integers N, M, K (1 ≤ N ≤ 109
; 1 ≤ M ≤ 30; 1 ≤ K ≤ 104
) —
the number of touristic places, sightseeing binoculars and groups of tourists, respectively. Then there
will be M lines with three integers A, B, C (1 ≤ A ≤ B ≤ N; 1 ≤ C ≤ 10) — the first and last touristic
place the binocular can see and its price, respectively. Then there are K lines with two integers X, Y
(1 ≤ X ≤ Y ≤ 109
) — there will be a group of tourists where the first is willing to pay X, the second
X + 1, the third X + 2 and so on until the last one who is willing to pay Y . Every touristic place can
be seen by at least one binocular.
Output
For each test case print a line containing ‘Case #X: Y ’, where X is the case number, starting at 1,
and Y is the maximum profit Skyrk can get.
Note:
Consider the first test case, there are 3 touristic places, 4 binoculars and 2 groups of tourists. The
first group of tourists go as follows: The first tourist can pay at most 1 coin. There is no subset Skyrk
can choose that satisfy the tourist, so the tourist don’t take the tour and pays nothing. The second
tourist can pay at most 2 coins, the only choice Skyrk has is to put the binoculars 2 and 4 on the
subset, the tourist then chooses binoculars 2 and 4 and pays 2 coins. The third tourist can pay at most
3 coins. Skyrk can put binoculars 1, 2 and 3 on the subset, the tourist then chooses binoculars 2 and
3 and pays 3 coins. The second group of tourists go as follows: The first tourist can pay at most 10
coins. Skyrk can put binoculars 1 and 3 on the subset, the tourist then chooses binoculars 1 and 3 and
pays 6 coins. The maximum profit Skyrk can get is 2+3+6 = 11 coins.
Sample Input
2
3 4 2
1 1 4
1 2 1
2 3 2
3 3 1
1 3
10 10
5 6 2
1 2 5
2 2 1
3 5 10
3 4 10
4 5 10
5 5 5
12 17
23 26
Sample Output
Case #1: 11
Case #2: 135

*/