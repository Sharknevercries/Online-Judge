/* 13984094	11729	Commando War	Accepted	C++	0.019	2014-08-03 10:46:04 */
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
#define MAX_N 10000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int A[MAX_N];
int B[MAX_N];
bool cmpL(int a, int b){ return B[a] > B[b]; }
int main(){
	int n, c = 1;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%d%d", A + i, B + i);
		vector<int> L;
		for (int i = 0; i < n; i++)
			L.push_back(i);
		sort(L.begin(), L.end(), cmpL);
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++){
			t1 += A[L[i]];
			t2 = max(t1 + B[L[i]], t2);
		}
		printf("Case %d: %d\n", c++, t2);
	}
	return 0;
}
/*

G
Commando War
Input: Standard Input
Output: Standard Output

¡§Waiting for orders we held in the wood, word from the front never came
By evening the sound of the gunfire was miles away
Ah softly we moved through the shadows, slip away through the trees
Crossing their lines in the mists in the fields on our hands and our knees
And all that I ever, was able to see
The fire in the air, glowing red, silhouetting the smoke on the breeze¡¨

There is a war and it doesn't look very promising for your country. Now it's time to act. You have a commando squad at your disposal and planning an ambush on an important enemy camp located nearby. You have N soldiers in your squad. In your master-plan, every single soldier has a unique responsibility and you don't want any of your soldier to know the plan for other soldiers so that everyone can focus on his task only. In order to enforce this, you brief every individual soldier about his tasks separately and just before sending him to the battlefield. You know that every single soldier needs a certain amount of time to execute his job. You also know very clearly how much time you need to brief every single soldier. Being anxious to finish the total operation as soon as possible, you need to find an order of briefing your soldiers that will minimize the time necessary for all the soldiers to complete their tasks. You may assume that, no soldier has a plan that depends on the tasks of his fellows. In other words, once a soldier  begins a task, he can finish it without the necessity of pausing in between.

Input

There will be multiple test cases in the input file. Every test case starts with an integer N (1<=N<=1000), denoting the number of soldiers. Each of the following N lines describe a soldier with two integers B (1<=B<=10000) & J (1<=J<=10000). B seconds are needed to brief the soldier while completing his job needs J seconds. The end of input will be denoted by a case with N =0 . This case should not be processed.

Output

For each test case, print a line in the format, ¡§Case X: Y¡¨, where X is the case number & Y is the total number of seconds counted from the start of your first briefing till the completion of all jobs.

Sample Input                                               Output for Sample Input
3
2 5
3 2
2 1
3
3 3
4 4
5 5
0
Case 1: 8
Case 2: 15

Problem Setter: Mohammad Mahmudur Rahman, Special Thanks: Manzurur Rahman Khan

*/