/* 13983753	11269	Setting Problems	Accepted	C++	0.015	2014-08-03 08:51:28 */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int A[MAX_N];
int B[MAX_N];
bool LAcmp(int a, int b){ return A[a] < A[b]; }
bool LBcmp(int a, int b){ return B[a] > B[b]; }
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++)
			scanf("%d", A + i);
		for (int i = 0; i < n; i++)
			scanf("%d", B + i);
		vector<int> LA, LB;
		for (int i = 0; i < n; i++){
			if (A[i] < B[i])
				LA.push_back(i);
			else
				LB.push_back(i);
		}
		sort(LA.begin(), LA.end(), LAcmp);
		sort(LB.begin(), LB.end(), LBcmp);
		vector<int> L;
		for (int i = 0; i < LA.size(); i++)	L.push_back(LA[i]);
		for (int i = 0; i < LB.size(); i++)	L.push_back(LB[i]);
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++)
			t1 += A[L[i]], t2 = max(t1, t2) + B[L[i]];
		printf("%d\n", t2);
	}
	return 0;
}
/*

Problem J
Setting Problems
Input: Standard Input
Output: Standard Output

As you see, setting problems for a programming contest is a tough job. There are so many things to do like creating problems, solutions, data files, verification of problem statements, writing alternate judge solutions etc. etc. Given the responsibility of creating the problemset for ¡¥If you can not crash judges by solutions, crash contestants by problems¡¦ programming contest, Sultan & GolapiBaba have realized that to the backbone. Finally they agree that they will set N problems for the contest. For each of the problems, first Sultan will create the problem statement, solution & i/o data. After he finishes his work, GolapiBaba does the verification & alternate solution writing part for that particular problem. Each of them needs a particular amount of time to complete their tasks for a certain problem. Also, none of them works on more than one problem at a time. Note that, GolapiBaba can start working on a problem immediately after Sultan finishes that problem or he may wish to start that problem later.

You will be given the times that Sultan & GolapiBaba requires to complete their respective tasks for every single problem. Determine the minimum possible time required to complete the whole problemset.

Input

There are around 50 test cases. Each test case starts with a single integer N (1<=N<=20), the number of problems in the contest. The next line contains N integers Si (1<=Si<=100, 1<=i<=N) where Si denotes the time required for Sultan to complete his tasks for problem i. The next line has N more integers Gi (1<=Gi<=100, 1<=i<=N) where Gi denotes the time required for Golapibaba to complete his tasks on problem i.

Output

For each test case, print the minimum time required to complete the problemset.

Sample Input
Sample Output
3
8 1 6
1 6 3
3
4 5 6
1 1 6

16
16

Problemsetter: Mohammad Mahmudur Rahman
Special Thanks To: Abdullah Al Mahmud

*/