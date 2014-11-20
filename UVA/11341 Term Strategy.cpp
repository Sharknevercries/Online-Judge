/* 14188404	11341	Term Strategy	Accepted	C++	0.012	2014-09-12 06:04:11 */
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
#define MAX_N 15
#define MAX_M 105
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
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d%d", &n, &m);
		int S[MAX_N][MAX_M];
		int DP[MAX_N][MAX_M] = { 0 };
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &S[i][j]);
		for (int i = 1; i <= m; i++)
			if (S[1][i] >= 5)
				DP[1][i] = S[1][i];
		for (int i = 2; i <= n; i++)
			for (int j = m; j >= 1; j--)
				for (int k = 1; k <= j; k++)
					if (S[i][k] >= 5 && DP[i - 1][j - k] != 0)
						DP[i][j] = max(DP[i][j], DP[i - 1][j - k] + S[i][k]);
		if (DP[n][m] == 0)
			puts("Peter, you shouldn't have played billiard that much.");
		else
			printf("Maximal possible average mark - %.2lf.\n", (double)DP[n][m] / n + 1e-9);
	}
	return 0;
}
/*

B - Term Strategy

Time Limit: 1 sec
Memory Limit: 16MB

Student Peter was playing billiard all the term and for that reason he missed all his lectures. Unfortunately that's the time for term exams which Peter must pass.

Peter has N (1 <= N <= 10) courses, because he completely failed the previous term exams so he has to pass them too. He is already late with his exams and the deadline is coming. He agreed with all teachers to pass all the exams in one day. The idea he followed is - "Everything or nothing". After he made some considerations and an assumption that we'll play billiard only 5 hours a day, he counted the number of hours he has left to get himself prepared for exams. He has concluded that he has M (0 < M <= 100) hours to get prepared. While he is preparing he has to read at least the name of the subject he is preparing for. Because of this difficult task he's preparing for at least one hour for each exam. If he has no time to prepare for exam - he fails it.

Exam is evaluated using 10-grade system. To pass an exam Peter has to receive at least 5. Also Peter is a greedy person and he wants to have the highest average mark that is possible.

As Peter is perfectly aware of his abilities he made a table L. Each line of this table represents a course and each column represents a number of hours Peter is preparing for a particular exam. Element Lij of the table means, that for i-th exam Peter devotes j-th hours of his available time. It is known that the more Peter is getting prepared for a particular exam the highest mark he receives, i.e. Li j = Li j+1 for each 1 <= i <= N ir 1 <= j <= M - 1.

Suddenly Peter remembers that he has a good friend. You're actually the person he remembered. So as he is completely desperate he asks for your help! Help Peter in his mission of passing exams and achieving the maximum possible average mark.

INPUT:

The number of tests T (T < 100) is given on the first line of input. First line of each test contains two integers N and M. Then N lines follow each containing M integers which define Li j element.
OUTPUT:

For each test case find whether Peter passes all exams. If he is that lucky to pass them print line: "Maximal possible average mark - S." (The result must be rounded to 2 digits after decimal point).
In case when he is not that lucky, and he has at least one exam that he`s unable to pass in given time limits print a line "Peter, you shouldn`t have played billiard that much.".

SAMPLE INPUT:

2
4 5
5 5 6 7 8
5 5 6 7 8
5 6 7 8 8
6 7 8 9 9
4 5
4 5 6 7 8
4 5 6 7 8
5 6 7 8 8
6 7 8 9 9
SAMPLE OUTPUT:

Maximal possible average mark - 5.50.
Peter, you shouldn't have played billiard that much.
Problem setters: Aleksej Viktorchik, Leonid Shishlo.
Huge Easy Contest #1

*/