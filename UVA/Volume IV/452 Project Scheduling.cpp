/* 14031423	452	Project Scheduling	Accepted	C++11	0.049	2014-08-13 06:28:53 */
/* Template By Shark */
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
#include<tuple>
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
#define MAX_N 30
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
vector<int> E[MAX_N];
bool used[MAX_N];
bool V[MAX_N];
int in[MAX_N];
int T[MAX_N];
int W[MAX_N];
int BFS(){
	memset(W, 0, sizeof(W));
	memset(V, false, sizeof(V));
	queue<int> Q;
	for (int i = 0; i < MAX_N; i++)
		if (in[i] == 0 && used[i])
			Q.push(i), V[i] = true, W[i] = T[i];
	while (!Q.empty()){
		int cur = Q.front();	Q.pop();
		for (int i = 0; i < E[cur].size(); i++){
			int target = E[cur][i];
			if (!V[target])
				in[target]--, W[target] = max(W[target], W[cur] + T[target]);
			if (in[target] == 0)
				Q.push(target), V[target] = true;
		}
	}
	int res = 0;
	for (int i = 0; i < MAX_N; i++)
		res = max(res, W[i]);
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	(void)getchar();
	(void)getchar();
	while (t--){
		for (int i = 0; i < MAX_N; i++)
			E[i].clear();
		memset(in, 0, sizeof(in));
		memset(used, false, sizeof(used));
		char S[1000];
		while (gets(S) && S[0] != '\0'){
			int a = S[0] - 'A', b, tmp;
			for (b = 2, tmp = 0; S[b] != ' ' && S[b] != '\0'; b++)
				tmp = tmp * 10 + S[b] - '0';
			T[a] = tmp, used[a] = true;
			for (b++; b < strlen(S); b++)
				E[S[b] - 'A'].push_back(a), in[a]++, used[S[b] - 'A'] = true;
		}
		printf("%d\n", BFS());
		if (t)	putchar('\n');
	}
	return 0;
}
/*

Project Scheduling

A project management technique called Pert involves breaking a large project into a number of tasks, estimating the time required to perform each task, and determining which tasks can not be started until others have been completed. The project is then summarized in chart form. For example, the chart (which corresponds to the sample input below)

indicates that tasks A, B, C, D, E and F each take 5, 3, 2, 2, 4, and 2 days respectively, that task E cannot complete until C and D are both completed, but that D can be performed in parallel with B and C.

Write a program that accepts a Pert chart and computes the amount of time required to complete a project.

Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.

Input will be from 1 to 27 lines, each corresponding to a different task. Each line will contain:

A single upper case letter serving as the name of a task.
An integer indicating the number of days required to complete that task.
0-26 additional uppercase letters, each indicating another task that must complete before this one can begin.
Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.

The output is a single integer indicating the amount of time that will pass before all tasks can complete.

Sample Input

2

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC
Sample Output

16

16

*/