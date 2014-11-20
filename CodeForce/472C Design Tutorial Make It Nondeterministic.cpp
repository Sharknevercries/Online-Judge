/* 8005774	2014-09-28 20:24:48	Shark	472C - Design Tutorial: Make It Nondeterministic	GNU C++	Accepted	889 ms	19100 KB */
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
#define MAX_N 100005
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

struct name{
	string T[2];
};
name M[MAX_N];
int order[MAX_N], mirror[MAX_N];
map<string, int> S[2];
bool compare(string a, string b){
	for (int i = 0; i < a.length() && i < b.length(); i++){
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	}
	if (a.length() <= b.length())
		return true;
	else
		return false;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> M[i].T[0] >> M[i].T[1];
	for (int i = 1; i <= n; i++)
		scanf("%d", order + i);
	string cur;
	for (int i = 1; i <= n; i++){
		int target = order[i];
		sort(M[target].T, M[target].T + 2);
		if (compare(cur, M[target].T[0]))
			cur = M[target].T[0];
		else if (compare(cur, M[target].T[1]))
			cur = M[target].T[1];
		else{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
/*

C. Design Tutorial: Make It Nondeterministic
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A way to make a new task is to make it nondeterministic or probabilistic. For example, the hard task of Topcoder SRM 595, Constellation, is the probabilistic version of a convex hull.

Let's try to make a new task. Firstly we will use the following task. There are n people, sort them by their name. It is just an ordinary sorting problem, but we can make it more interesting by adding nondeterministic element. There are n people, each person will use either his/her first name or last name as a handle. Can the lexicographical order of the handles be exactly equal to the given permutation p?

More formally, if we denote the handle of the i-th person as hi, then the following condition must hold: .

Input
The first line contains an integer n (1 ≤ n ≤ 105) — the number of people.

The next n lines each contains two strings. The i-th line contains strings fi and si (1 ≤ |fi|, |si| ≤ 50) — the first name and last name of the i-th person. Each string consists only of lowercase English letters. All of the given 2n strings will be distinct.

The next line contains n distinct integers: p1, p2, ..., pn (1 ≤ pi ≤ n).

Output
If it is possible, output "YES", otherwise output "NO".

Sample test(s)
input
3
gennady korotkevich
petr mitrichev
gaoyuan chen
1 2 3
output
NO
input
3
gennady korotkevich
petr mitrichev
gaoyuan chen
3 1 2
output
YES
input
2
galileo galilei
nicolaus copernicus
2 1
output
YES
input
10
rean schwarzer
fei claussell
alisa reinford
eliot craig
laura arseid
jusis albarea
machias regnitz
sara valestin
emma millstein
gaius worzel
1 2 3 4 5 6 7 8 9 10
output
NO
input
10
rean schwarzer
fei claussell
alisa reinford
eliot craig
laura arseid
jusis albarea
machias regnitz
sara valestin
emma millstein
gaius worzel
2 4 9 6 5 7 1 3 8 10
output
YES
Note
In example 1 and 2, we have 3 people: tourist, Petr and me (cgy4ever). You can see that whatever handle is chosen, I must be the first, then tourist and Petr must be the last.

In example 3, if Copernicus uses "copernicus" as his handle, everything will be alright.

*/