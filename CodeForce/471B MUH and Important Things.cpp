/* 7962064	2014-09-26 19:52:27	* Shark	471B - MUH and Important Things	GNU C++	Accepted	31 ms	200 KB */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 2005
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
struct data{
	int value, pos;
	bool used;
};
bool cmp(data A, data B){
	return A.value < B.value;
}
vector<int> tmp;
vector< vector<int> > ans;
data S[MAX_N];
void DFS(int cnt, int n){
	if (ans.size() >= 3)	return;
	if (cnt == n){
		ans.push_back(tmp);
		return;
	}
	for (int j = 0; j < n && S[cnt].value >= S[j].value; j++){
		if (!S[j].used && S[j].value == S[cnt].value){
			S[j].used = true;
			tmp.push_back(S[j].pos);
			DFS(cnt + 1, n);
			tmp.pop_back();
			S[j].used = false;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &S[i].value), S[i].pos = i, S[i].used = false;
	sort(S, S + n, cmp);
	DFS(0, n);
	if (ans.size() >= 3){
		puts("YES");
		for (int i = 0; i < ans.size(); i++){
			for (int j = 0; j < ans[i].size(); j++){
				if (j > 0)putchar(' ');
				printf("%d", ans[i][j] + 1);
			}
			putchar('\n');
		}
	}
	else
		puts("NO");
	return 0;
}
/*

B. MUH and Important Things
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
It's time polar bears Menshykov and Uslada from the zoo of St. Petersburg and elephant Horace from the zoo of Kiev got down to business. In total, there are n tasks for the day and each animal should do each of these tasks. For each task, they have evaluated its difficulty. Also animals decided to do the tasks in order of their difficulty. Unfortunately, some tasks can have the same difficulty, so the order in which one can perform the tasks may vary.

Menshykov, Uslada and Horace ask you to deal with this nuisance and come up with individual plans for each of them. The plan is a sequence describing the order in which an animal should do all the n tasks. Besides, each of them wants to have its own unique plan. Therefore three plans must form three different sequences. You are to find the required plans, or otherwise deliver the sad news to them by stating that it is impossible to come up with three distinct plans for the given tasks.

Input
The first line contains integer n (1 ≤ n ≤ 2000) — the number of tasks. The second line contains n integers h1, h2, ..., hn (1 ≤ hi ≤ 2000), where hi is the difficulty of the i-th task. The larger number hi is, the more difficult the i-th task is.

Output
In the first line print "YES" (without the quotes), if it is possible to come up with three distinct plans of doing the tasks. Otherwise print in the first line "NO" (without the quotes). If three desired plans do exist, print in the second line n distinct integers that represent the numbers of the tasks in the order they are done according to the first plan. In the third and fourth line print two remaining plans in the same form.

If there are multiple possible answers, you can print any of them.

Sample test(s)
input
4
1 3 3 1
output
YES
1 4 2 3
4 1 2 3
4 1 3 2
input
5
2 4 1 4 8
output
NO
Note
In the first sample the difficulty of the tasks sets one limit: tasks 1 and 4 must be done before tasks 2 and 3. That gives the total of four possible sequences of doing tasks : [1, 4, 2, 3], [4, 1, 2, 3], [1, 4, 3, 2], [4, 1, 3, 2]. You can print any three of them in the answer.

In the second sample there are only two sequences of tasks that meet the conditions — [3, 1, 2, 4, 5] and [3, 1, 4, 2, 5]. Consequently, it is impossible to make three distinct sequences of tasks.

*/