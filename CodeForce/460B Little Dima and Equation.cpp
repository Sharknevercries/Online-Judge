/* 7521503	2014-08-20 19:51:00	Shark	460B - Little Dima and Equation	GNU C++	Accepted	15 ms	0 KB */
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
#define MAX_N 1000
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
int check(lli s){
	int res = 0;
	while (s > 0)
		res += s % 10, s /= 10;
	return res;
}
int main(){
	vector<int> ans;
	int a, b, c;
	ans.clear();
	scanf("%d%d%d", &a , &b, &c);
	for (int i = 1; i <= 81; i++){
		lli tmp = b;
		for (int j = 1; j <= a; j++)
			tmp *= i;
		tmp += c;
		if (tmp < 1e9 && check(tmp) == i)
			ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		if (i > 0)	putchar(' ');
		printf("%d", ans[i]);
	}
	putchar('\n');
	return 0;
}
/*

B. Little Dima and Equation
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Dima misbehaved during a math lesson a lot and the nasty teacher Mr. Pickles gave him the following problem as a punishment.

Find all integer solutions x (0 < x < 109) of the equation:

x = b·s(x)a + c, 
where a, b, c are some predetermined constant values and function s(x) determines the sum of all digits in the decimal representation of number x.

The teacher gives this problem to Dima for each lesson. He changes only the parameters of the equation: a, b, c. Dima got sick of getting bad marks and he asks you to help him solve this challenging problem.

Input
The first line contains three space-separated integers: a, b, c (1 ≤ a ≤ 5; 1 ≤ b ≤ 10000;  - 10000 ≤ c ≤ 10000).

Output
Print integer n — the number of the solutions that you've found. Next print n integers in the increasing order — the solutions of the given equation. Print only integer solutions that are larger than zero and strictly less than 109.

Sample test(s)
input
3 2 8
output
3
10 2008 13726
input
1 2 -18
output
0
input
2 2 -1
output
4
1 31 337 967

*/