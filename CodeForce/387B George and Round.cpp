/* 5868508	 Feb 2, 2014 3:44:27 PM	Shark	 387B - George and Round	 GNU C++	Accepted	15 ms	0 KB */
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int A[3000], B[3000];
		int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", A + i);
		for (int i = 0; i < m; i++)
			scanf("%d", B + i);
		sort(A, A + n, cmp);
		sort(B, B + m, cmp);
		for (int i = 0, j = 0; i < n; i++){
			if (j >= m)
				ans++;
			else if (B[j] < A[i])
				ans++;
			else
				j++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. George and Round
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
George decided to prepare a Codesecrof round, so he has prepared m problems for the round. Let's number the problems with integers 1 through m. George estimates the i-th problem's complexity by integer bi.

To make the round good, he needs to put at least n problems there. Besides, he needs to have at least one problem with complexity exactly a1, at least one with complexity exactly a2, ..., and at least one with complexity exactly an. Of course, the round can also have problems with other complexities.

George has a poor imagination. It's easier for him to make some already prepared problem simpler than to come up with a new one and prepare it. George is magnificent at simplifying problems. He can simplify any already prepared problem with complexity c to any positive integer complexity d (c ≥ d), by changing limits on the input data.

However, nothing is so simple. George understood that even if he simplifies some problems, he can run out of problems for a good round. That's why he decided to find out the minimum number of problems he needs to come up with in addition to the m he's prepared in order to make a good round. Note that George can come up with a new problem of any complexity.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 3000) — the minimal number of problems in a good round and the number of problems George's prepared. The second line contains space-separated integers a1, a2, ..., an (1 ≤ a1 < a2 < ... < an ≤ 106) — the requirements for the complexity of the problems in a good round. The third line contains space-separated integers b1, b2, ..., bm (1 ≤ b1 ≤ b2... ≤ bm ≤ 106) — the complexities of the problems prepared by George.

Output
Print a single integer — the answer to the problem.

Sample test(s)
input
3 5
1 2 3
1 2 2 3 3
output
0
input
3 5
1 2 3
1 1 1 1 1
output
2
input
3 1
2 3 4
1
output
3
Note
In the first sample the set of the prepared problems meets the requirements for a good round.

In the second sample, it is enough to come up with and prepare two problems with complexities 2 and 3 to get a good round.

In the third sample it is very easy to get a good round if come up with and prepare extra problems with complexities: 2, 3, 4.

*/