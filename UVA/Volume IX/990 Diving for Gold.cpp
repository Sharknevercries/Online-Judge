/* 13892929	990	Diving for Gold	Accepted	C++	0.009	2014-07-16 15:46:53 */
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
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 1001
#define MAX_M 30
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int DP[MAX_N];
int D[MAX_M];
int W[MAX_M];
int P[MAX_M];
bool record[MAX_M][MAX_N];
int main(){
	int t, w, n;
	bool first = true;
	while (scanf("%d%d", &t, &w) == 2){
		memset(DP, 0, sizeof(DP));
		memset(record, false, sizeof(record));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", D + i, W + i), P[i] = 3 * w * D[i];
		for (int i = 0; i < n; i++)
			for (int j = t; j >= P[i]; j--)
				if (DP[j] < DP[j - P[i]] + W[i])
					DP[j] = DP[j - P[i]] + W[i], record[i][j] = true;
		int max = -1, pos = -1;
		for (int i = 1; i <= t; i++)
			if (DP[i] > max)
				max = DP[i], pos = i;
		vector<int> ans;
		for (int i = n - 1, j = pos; i >= 0; i--){
			if (record[i][j])
				ans.push_back(i), j -= P[i];
		}
		if (!first)
			putchar('\n');
		printf("%d\n", max);
		printf("%d\n", ans.size());
		for (int i = ans.size() - 1; i >= 0; i--)
			printf("%d %d\n", D[ans[i]], W[ans[i]]);
		first = false;
	}
	return 0;
}
/*

Diving for gold

Problem

John is a diver and a treasure hunter. He has just found the location of a pirate ship full of treasures. The sofisticated sonar system on board his ship allows him to identify the location, depth and quantity of gold in each suken treasure. Unfortunatelly, John forgot to bring a GPS device and the chances of ever finding this location again are very slim so he has to grab the gold now. To make the situation worse, John has only one compressed air bottle.

John wants to dive with the compressed air bottle to recover as much gold as possible from the wreck. Write a program John can use to select which treasures he should pick to maximize the quantity of gold recovered.

The problem has the following restrictions:

There are n treasures {(d1,v1), (d2,v2), ... (dn,vn)} represented by the pair (depth, quantity of gold). There are at most 30 treasures.
The air bottle only allows for t seconds under water. t is at most 1000 seconds.
In each dive, John can bring the maximum of one treasure at a time.
The descent time is tdi=w*di, where w is an integer constant.
The ascent time is tai=2w*di, where w is an integer constant.
Due to instrument limitations, all parameters are integer.
Input

The input to this program consists of a sequence of integer values. Input contains several test cases. The first line of each dataset should contain the values t and w. The second line contains the number of treasures. Each of the following lines contains the depth di and quantity of gold vi of a different treasure.

A blank line separates each test case.

Output

The first line of the output for each dataset should contain the maximum amount of gold that John can recover from the wreck. The second line should contain the number of recovered treasures. Each of the following lines should contain the depth and amount of gold of each recovered treasure. Treasures should be presented in the same order as the input file.

Print a blank line between outputs for different datasets.

Sample input

210 4
3
10 5
10 1
7 2
In this sample input, the bottle of compressed air has a capacity of 200 seconds, the constant w has the value 4 and there are 3 treasures, the first one at a depth of 10 meters and worth 5 coins of gold, the second one at a depth of 10 meters and worth 1 coin of gold, and the third one at 7 meters and worth 2 coins of gold.

Sample output

7
2
10 5
7 2

*/