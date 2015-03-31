/* 13940041	840502	2057	Accepted	764K	32MS	G++	1467B	2015-03-08 15:11:27 */
#include<bits\stdc++.h>
using namespace std;
int n;
vector<int> G[1005];
double leave[1005];
bool worm[1005];
double DP[2][1005];
bool cmp(int a, int b){
	double ab = leave[a] + DP[0][a] + (DP[1][a] + 3)*leave[b] + DP[0][b];
	double ba = leave[b] + DP[0][b] + (DP[1][b] + 3)*leave[a] + DP[0][a];
	return ab < ba;
}
void solve(int x){
	DP[0][x] = DP[1][x] = 0;
	if (G[x].size() == 0)
		leave[x] = 1;
	else{
		int S[20];
		leave[x] = 0;
		for (int i = 0; i < G[x].size(); i++){
			int next = G[x][i];
			solve(next);
			S[i] = next;
			leave[x] += leave[next];
		}
		sort(S, S + G[x].size(), cmp);
		for (int i = 0; i < G[x].size(); i++){
			DP[0][x] += (DP[1][x] + 1)*leave[S[i]] + DP[0][S[i]];
			DP[1][x] += DP[1][S[i]] + 2;
		}
		if (worm[x])	DP[1][x] = 0;

	}
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++)
			G[i].clear();
		memset(worm, false, sizeof(worm));
		for (int i = 1; i <= n; i++){
			int prev;
			char s[10];
			scanf("%d%s", &prev, s);
			if (prev != -1)
				G[prev].push_back(i);
			if (s[0] == 'Y')
				worm[i] = true;
		}
		solve(1);
		printf("%.4lf\n", DP[0][1] / leave[1]);
	}
	return 0;
}
/*

The Lost House
Time Limit: 3000MS		Memory Limit: 30000K
Total Submissions: 2291		Accepted: 937
Description

One day a snail climbed up to a big tree and finally came to the end of a branch. What a different feeling to look down from such a high place he had never been to before! However, he was very tired due to the long time of climbing, and fell asleep. An unbelievable thing happened when he woke up ---- he found himself lying in a meadow and his house originally on his back disappeared! Immediately he realized that he fell off the branch when he was sleeping! He was sure that his house must still be on the branch he had been sleeping on. The snail began to climb the tree again, since he could not live without his house.

When reaching the first fork of the tree, he sadly found that he could not remember the route that he climbed before. In order to find his lovely house, the snail decided to go to the end of every branch. It was dangerous to walk without the protection of the house, so he wished to search the tree in the best way.

Fortunately, there lived many warm-hearted worms in the tree that could accurately tell the snail whether he had ever passed their places or not before he fell off.

Now our job is to help the snail. We pay most of our attention to two parts of the tree ---- the forks of the branches and the ends of the branches, which we call them key points because key events always happen there, such as choosing a path, getting the help from a worm and arriving at the house he is searching for.

Assume all worms live at key points, and all the branches between two neighboring key points have the same distance of 1. The snail is now at the first fork of the tree.

Our purpose is to find a proper route along which he can find his house as soon as possible, through the analysis of the structure of the tree and the locations of the worms. The only restriction on the route is that he must not go down from a fork until he has reached all the ends grown from this fork.

The house may be left at the end of any branches in an equal probability. We focus on the mathematical expectation of the distance the snail has to cover before arriving his house. We wish the value to be as small as possible.

As illustrated in Figure-1, the snail is at the key point 1 and his house is at a certain point among 2, 4 and 5. A worm lives at point 3, who can tell the snail whether his house is at one of point 4 and 5 or not. Therefore, the snail can choose two strategies. He can go to point 2 first. If he cannot find the house there, he should go back to point 1, and then reaches point 4 (or 5) by point 3. If still not, he has to return point 3, then go to point 5 (or 4), where he will undoubtedly find his house. In this choice, the snail covers distances of 1, 4, 6 corresponding to the circumstances under which the house is located at point 2, 4 (or 5), 5 (or 4) respectively. So the expectation value is (1 + 4 + 6) / 3 = 11 / 3. Obviously, this strategy does not make full use of the information from the worm. If the snail goes to point 3 and gets useful information from the worm first, and then chooses to go back to point 1 then towards point 2, or go to point 4 or 5 to take his chance, the distances he covers will be 2, 3, 4 corresponding to the different locations of the house. In such a strategy, the mathematical expectation will be (2 + 3 + 4) / 3 = 3, and it is the very route along which the snail should search the tree.


Input

The input contains several sets of test data. Each set begins with a line containing one integer N, no more than 1000, which indicates the number of key points in the tree. Then follow N lines describing the N key points. For convenience, we number all the key points from 1 to N. The key point numbered with 1 is always the first fork of the tree. Other numbers may be any key points in the tree except the first fork. The i-th line in these N lines describes the key point with number i. Each line consists of one integer and one uppercase character 'Y' or 'N' separated by a single space, which represents the number of the previous key point and whether there lives a worm ('Y' means lives and 'N' means not). The previous key point means the neighboring key point in the shortest path between this key point and the key point numbered 1. In the above illustration, the previous key point of point 2 or 3 is point 1, while the previous key point of point 4 or 5 is point 3. This integer is -1 for the key point 1, means it has no previous key point. You can assume a fork has at most eight branches. The first set in the sample input describes the above illustration.

A test case of N = 0 indicates the end of input, and should not be processed.
Output

Output one line for each set of input data. The line contains one float number with exactly four digits after the decimal point, which is the mathematical expectation value.
Sample Input

5
-1 N
1 N
1 Y
3 N
3 N
10
-1 N
1 Y
1 N
2 N
2 N
2 N
3 N
3 Y
8 N
8 N
6
-1 N
1 N
1 Y
1 N
3 N
3 N
0
Sample Output

3.0000
5.0000
3.5000
Source

Beijing 2004

*/