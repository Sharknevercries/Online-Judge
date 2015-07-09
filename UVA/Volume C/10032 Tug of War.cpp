/* 15148672	10032	Tug of War	Accepted	C++	0.119	2015-03-15 08:03:11 */
#include<bits\stdc++.h>
using namespace std;
long long int DP[45005];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, w[105], sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", w + i), sum += w[i];
		memset(DP, 0, sizeof(DP));
		DP[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = sum / 2 + 1; j >= w[i]; j--)
				DP[j] |= DP[j - w[i]] << 1LL;
		int ans = sum / 2;
		if (n % 2 == 0)
			while (ans > 0 && !(DP[ans] & (1LL << (n / 2))))
				ans--;
		else
			while (ans > 0 && !(DP[ans] & (1LL << (n / 2))) && !(DP[ans] & (1LL << (n / 2 + 1))))
				ans--;
		printf("%d %d\n", ans, sum - ans);
		if (t)	putchar('\n');
	}
	return 0;
}
/*

A tug of war is to be arranged at the local office picnic. For the tug of war, the picnickers must be
divided into two teams. Each person must be on one team or the other; the number of people on the
two teams must not differ by more than 1; the total weight of the people on each team should be as
nearly equal as possible.
Input
The input begins with a single positive integer on a line by itself indicating the number
of the cases following, each of them as described below. This line is followed by a blank
line, and there is also a blank line between two consecutive inputs.
The first line of input contains n the number of people at the picnic. n lines follow. The first line
gives the weight of person 1; the second the weight of person 2; and so on. Each weight is an integer
between 1 and 450. There are at most 100 people at the picnic.
Output
For each test case, the output must follow the description below. The outputs of two
consecutive cases will be separated by a blank line.
Your output will be a single line containing 2 numbers: the total weight of the people on one team,
and the total weight of the people on the other team. If these numbers differ, give the lesser first.
Sample Input
1
3
100
90
200
Sample Output
190 200

*/