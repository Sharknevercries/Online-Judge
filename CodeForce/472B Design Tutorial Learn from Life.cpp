/* 7999469	2014-09-28 19:47:22	Shark	472B - Design Tutorial: Learn from Life	GNU C++	Accepted	31 ms	0 KB */
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
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n, k, S[MAX_N];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", S + i);
	sort(S, S + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i += k)
		ans += 2 * (S[i] - 1);
	printf("%d\n", ans);
	return 0;
}
/*

B. Design Tutorial: Learn from Life
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One way to create a task is to learn from life. You can choose some experience in real life, formalize it and then you will get a new task.

Let's think about a scene in real life: there are lots of people waiting in front of the elevator, each person wants to go to a certain floor. We can formalize it in the following way. We have n people standing on the first floor, the i-th person wants to go to the fi-th floor. Unfortunately, there is only one elevator and its capacity equal to k (that is at most k people can use it simultaneously). Initially the elevator is located on the first floor. The elevator needs |a - b| seconds to move from the a-th floor to the b-th floor (we don't count the time the people need to get on and off the elevator).

What is the minimal number of seconds that is needed to transport all the people to the corresponding floors and then return the elevator to the first floor?

Input
The first line contains two integers n and k (1 ≤ n, k ≤ 2000) — the number of people and the maximal capacity of the elevator.

The next line contains n integers: f1, f2, ..., fn (2 ≤ fi ≤ 2000), where fi denotes the target floor of the i-th person.

Output
Output a single integer — the minimal time needed to achieve the goal.

Sample test(s)
input
3 2
2 3 4
output
8
input
4 2
50 100 50 100
output
296
input
10 3
2 2 2 2 2 2 2 2 2 2
output
8
Note
In first sample, an optimal solution is:

The elevator takes up person #1 and person #2.
It goes to the 2nd floor.
Both people go out of the elevator.
The elevator goes back to the 1st floor.
Then the elevator takes up person #3.
And it goes to the 2nd floor.
It picks up person #2.
Then it goes to the 3rd floor.
Person #2 goes out.
Then it goes to the 4th floor, where person #3 goes out.
The elevator goes back to the 1st floor.

*/