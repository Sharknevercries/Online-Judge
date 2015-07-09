/* 13862299	10934	Dropping water balloons	Accepted	C++	0.015	2014-07-10 16:32:40 */
/*

Template By Shark

*/

// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
#define MAX_N 101
#define MAX_M 65
const double PI = 2.0 * acos(0.0);
lli DP[MAX_N][MAX_M];
int main(){
	for (int i = 1; i < 64; i++)
		for (int j = 1; j < 64; j++)
			DP[i][j] = DP[i - 1][j - 1] + 1 + DP[i][j - 1];
	lli k, n;
	while (scanf("%lld%lld", &k, &n) == 2 && k && n){
		if (k >= 64)	k = 63;
		int res = lower_bound(DP[k], DP[k] + MAX_M, n) - DP[k];
		if (res < 64)
			printf("%d\n", res);
		else
			puts("More than 63 trials needed.");
	}
	return 0;
}
/*

Problem A: Dropping water balloons

It's frosh week, and this year your friends have decided that they would initiate the new computer science students by dropping water balloons on them. They've filled up a large crate of identical water balloons, ready for the event. But as fate would have it, the balloons turned out to be rather tough, and can be dropped from a height of several stories without bursting!
So your friends have sought you out for help. They plan to drop the balloons from a tall building on campus, but would like to spend as little effort as possible hauling their balloons up the stairs, so they would like to know the lowest floor from which they can drop the balloons so that they do burst.

You know the building has n floors, and your friends have given you k identical balloons which you may use (and break) during your trials to find their answer. Since you are also lazy, you would like to determine the minimum number of trials you must conduct in order to determine with absolute certainty the lowest floor from which you can drop a balloon so that it bursts (or in the worst case, that the balloons will not burst even when dropped from the top floor). A trial consists of dropping a balloon from a certain floor. If a balloon fails to burst for a trial, you can fetch it and use it again for another trial.

The input consists of a number of test cases, one case per line. The data for one test case consists of two numbers k and n, 1≤k≤100 and a positive n that fits into a 64 bit integer (yes, it's a very tall building). The last case has k=0 and should not be processed.

For each case of the input, print one line of output giving the minimum number of trials needed to solve the problem. If more than 63 trials are needed then print More than 63 trials needed. instead of the number.

Sample input

2 100
10 786599
4 786599
60 1844674407370955161
63 9223372036854775807
0 0
Output for sample input

14
21
More than 63 trials needed.
61
63
Piotr Rudnicki

*/