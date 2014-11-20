/* 7779590	2014-09-13 10:40:48	Shark	466B - Wonder Room	GNU C++	Accepted	30 ms	0 KB */
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
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
lli minArea, ansA, ansB;
int main(){
	lli n, a, b;
	while (scanf("%lld%lld%lld", &n, &a, &b) == 3){
		if (a* b >= n * 6)
			printf("%lld\n%lld %lld\n", a*b, a, b);
		else{
			minArea = 1e15;
			lli limit = ceil(sqrt((double)6 * n));
			for (lli i = a > b ? b : a; i <= limit; i++){
				lli j = ceil((double)6 * n / i);
				if (i*j < minArea){
					if (i >= a && j >= b)
						minArea = i*j, ansA = i, ansB = j;
					else if (i >= b && j >= a)
						minArea = i*j, ansA = j, ansB = i;
				}
			}
			printf("%lld\n%lld %lld\n", minArea, ansA, ansB);
		}
	}
	return 0;
}
/*

B. Wonder Room
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The start of the new academic year brought about the problem of accommodation students into dormitories. One of such dormitories has a a × b square meter wonder room. The caretaker wants to accommodate exactly n students there. But the law says that there must be at least 6 square meters per student in a room (that is, the room for n students must have the area of at least 6n square meters). The caretaker can enlarge any (possibly both) side of the room by an arbitrary positive integer of meters. Help him change the room so as all n students could live in it and the total area of the room was as small as possible.

Input
The first line contains three space-separated integers n, a and b (1 ≤ n, a, b ≤ 109) — the number of students and the sizes of the room.

Output
Print three integers s, a1 and b1 (a ≤ a1; b ≤ b1) — the final area of the room and its sizes. If there are multiple optimal solutions, print any of them.

Sample test(s)
input
3 3 5
output
18
3 6
input
2 4 4
output
16
4 4

*/