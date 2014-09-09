/* 14058953	10731	Test	Accepted	C++	0.025	2014-08-18 08:14:58 */
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 30
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int V[MAX_N], low[MAX_N], t;
int stack[MAX_N], top;
int G[MAX_N];
bool instack[MAX_N];
bool used[MAX_N];
bool print[MAX_N];
vector<int> E[MAX_N];
int n;
void DFS(int i){
	V[i] = low[i] = t++;
	stack[top++] = i;
	instack[i] = true;
	for (int j = 0; j < E[i].size(); j++){
		int target = E[i][j];
		if (V[target] == NONE)
			DFS(target);
		if (instack[target])
			low[i] = min(low[i], low[target]);
	}
	if (V[i] == low[i]){
		int j;
		do{
			j = stack[--top];
			G[j] = i;
			instack[j] = false;
		} while (j != i);
	}
}
int main(){
	int n, c = 0;;
	while (scanf("%d", &n) == 1 && n){
		if (c++ > 0)	putchar('\n');
		memset(used, false, sizeof(used));
		for (int i = 0; i < MAX_N; i++)
			E[i].clear();
		for (int i = 0; i < n; i++){
			char a, b[5];
			for (int j = 0; j < 5; j++)
				scanf(" %c", b + j), used[b[j] - 'A'] = true;
			scanf(" %c", &a);
			for (int j = 0; j < 5; j++)
				if (a != b[j])
					E[a - 'A'].push_back(b[j] - 'A');
		}
		for (int i = 0; i < MAX_N; i++)
			G[i] = i;
		memset(V, NONE, sizeof(V));
		memset(instack, false, sizeof(instack));
		t = top = 0;
		for (int i = 0; i < MAX_N; i++)
			if (V[i] == NONE && used[i])
				DFS(i);
		memset(print, false, sizeof(print));
		for (int i = 0; i < MAX_N; i++){
			if (used[i] && !print[i]){
				for (int j = 0, k = 0; j < MAX_N; j++){
					if (used[j] && !print[j] && G[i] == G[j]){
						if (k > 0)	putchar(' ');
						printf("%c", 'A' + j), print[j] = true;
						k++;
					}
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
/*

Problem E: Test

A vocational preference test, unlike an aptitude test, seeks to identify careers that the candidate might find satisfying. Based on the answers to a slew of seemingly inane multiple-choice questions like the one below, the test determines which occupations suit the candidate's personality.
Which would you rather spend an afternoon doing?

(a) feeding chickens
(b) driving a race car
(c) watching The Simpsons on TV
(d) suntanning
(e) building a dog house
Each question asks the candidate to express a preference from among five activities, selected from a common larger set. That is, activities like feeding chickens or suntanning are likely to appear in several different questions.
If a candidate answers A in a question containing A, B, C, D, E as alternatives, this choice indicates a preference for A over each of B, C, D, E. Also, if one answer indicates a preference for X over Y and one or more other answers indicate a preference for Y over Z, the combined set of answers indicates a preference for X over Z.

The candidate may provide contradictory answers; that is, the answers may indicate a preference for X over Y and also for Y over X. These contradictions indicate inconsistency, a personalitiy attribute that may suggest a career in politics or used auto sales.

Given a set of answers to a vocational preference test, you are to partition the activities into the minimal number of sets such that, for each pair within a given set, the answers indicate a contradictory preference.

The input contains several test cases followed by a line containing 0. Each case begins with n, the number of questions in the test. n lines follow, each containing the names of five distinct activities, followed by the candidate's answer - one of the five alternatives. Each activity is named by a single upper case letter.

For each test case, output the sets, one per line. Output the elements of each set in alphabetical order, and output the sets in alphabetical order by their least element. The sets should together contain exactly the set of activities that appear in the input. Leave an empty line between test cases.

Sample Input

4
A B C D E C
F C H I J J
K B H I F I
K C E B J K
0
Output for Sample Input

A
B
C
D
E
F
H
I J K
Gordon V. Cormack

*/