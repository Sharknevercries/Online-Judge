/* 14158382	12086	Potentiometers	Accepted	C++	0.312	2014-09-06 14:57:20 */
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
#define MAX_N 200001
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
int S[MAX_N];
int T[4 * MAX_N];
int n;
void update(int s, int value){
	for (; s <= n; s += s&-s)
		T[s] += value;
}
int query(int s){
	int res = 0;
	for (; s > 0; s -= s&-s)
		res += T[s];
	return res;
}
int main(){
	int t = 1;
	while (scanf("%d", &n) == 1 && n){
		if (t > 1)putchar('\n');
		printf("Case %d:\n", t++);
		memset(T, 0, sizeof(T));
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		for (int i = 1; i <= n; i++)
			update(i, S[i]);
		char com[5];
		while (scanf("%s", com) == 1){
			if (com[0] == 'E')break;
			int a, b;
			scanf("%d%d", &a, &b);
			if (com[0] == 'M')
				printf("%d\n", query(b) - query(a - 1));
			else
				update(a, b - S[a]), S[a] = b;
		}
	}
	return 0;
}/*
 
 A potentiometer, or potmeter for short, is an electronic device with a variable electric resistance. It
has two terminals and some kind of control mechanism (often a dial, a wheel or a slide) with which the
resistance between the terminals can be adjusted from zero (no resistance) to some maximum value.
Resistance is measured in Ohms, and when two or more resistors are connected in series (one after the
other, in a row), the total resistance of the array is the sum of the resistances of the individual resistors.
In this problem we will consider an array of N potmeters, numbered 1 to N from left to right. The
left terminal of some potmeter numbered x is connected to the right terminal of potmeter x − 1, and
its right terminal to the left terminal of potmeter x + 1. The left terminal of potmeter 1 and the right
terminal of potmeter N are not connected.
Initially all the potmeters are set to some value between 0 and 1000 Ohms. Then we can do two
things:
• Set one of the potmeters to another value.
• Measure the resistance between two terminals anywhere in the array.
Input
The input consists less than 3 cases. Each case starts with N, the number of potmeters in the array,
on a line by itself. N can be as large as 200000. Each of next N lines contains one numbers between 0
and 1000, the initial resistances of the potmeters in the order 1 to N. Then follow a number of actions,
each on a line by itself. The number of actions can be as many as 200000. There are three types of
action:
• “S x r” - set potmeter x to r Ohms. x is a valid potmeter number and r is between 0 and 1000.
• “M x y” - measure the resistance between the left terminal of potmeter x and the right terminal
of potmeter y. Both numbers will be valid and x is smaller than or equal to y.
• “END” - end of this case. Appears only once at the end of a list of actions.
A case with N = 0 signals the end of the input and it should not be processed.
Output
For each case in the input produce a line ‘Case n:’, where n is the case number, starting from 1.
For each measurement in the input, output a line containing one number: the measured resistance
in Ohms. The actions should be applied to the array of potmeters in the order given in the input.
Print a blank line between cases.
Warning: Input Data is pretty big (∼ 8 MB) so use faster IO.
Sample Input
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0
Sample Output
Case 1:
100
300
300
200
Case 2:
55

*/