/* 13931133	410	Station Balance	Accepted	C++	0.042	2014-07-23 09:34:08 */
/*

Template By Shark

*/
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
vector<int> chamber[MAX_N];
int main(){
	int n, s, t = 1;
	while (scanf("%d%d", &n, &s) == 2){
		int W[MAX_N], sum = 0;
		double ans = 0;
		for (int i = 0; i < s; i++)
			scanf("%d", W + i), sum += W[i];
		for (int i = 0; i < n; i++)
			chamber[i].clear();
		sort(W, W + s);
		printf("Set #%d\n", t++);
		for (int i = s - 1, j = 0, k = 0; i >= 0; i--){
			chamber[j].push_back(W[i]);
			if (k == 0)	j++;
			else	j--;
			if (j >= n)
				k = 1, j--;
		}
		for (int i = 0; i < n; i++){
			int tmp = 0;
			printf("%2d:", i);
			for (int j = 0; j < chamber[i].size(); j++){
				tmp += chamber[i][j];
				printf(" %d", chamber[i][j]);
			}
			putchar('\n');
			ans += abs((double)sum / n - tmp);
		}
		printf("IMBALANCE = %.5lf\n\n", ans);
	}
	return 0;
}
/*

Station Balance

The International Space Station contains many centrifuges in its labs. Each centrifuge will have some number (C) of chambers each of which can contain 0, 1, or 2 specimens. You are to write a program which assigns all S specimens to the chambers such that no chamber contains more than 2 specimens and the following expression for IMBALANCE is minimized.

displaymath38

where:

tex2html_wrap_inline40
is the Chamber Mass of chamber i and is computed by summing the masses of the specimens assigned to chamber i.
AM
is the Average Mass of the chambers and is computed by dividing the sum of the masses of all specimens by the number of chambers (C).
Input

Input to this program will be a file with multiple sets of input. The first line of each set will contain two numbers. The first number ( tex2html_wrap_inline50 ) defines the number of chambers in the centrifuge and the second number ( tex2html_wrap_inline52 ) defines the number of specimens in the input set. The second line of input will contain S integers representing the masses of the specimens in the set. Each specimen mass will be between 1 and 1000 and will be delimited by the beginning or end of the line and/or one or more blanks.

Output

For each input set, you are to print a line specifying the set number (starting with 1) in the format "Set #X" where "X" is the set number.

The next C lines will contain the chamber number in column 1, a colon in column number 2, and then the masses of the specimens your program has assigned to that chamber starting in column 4. The masses in your output should be separated by exactly one blank.

Your program should then print ``IMBALANCE = X" on a line by itself where X is the computed imbalance of your specimen assignments printed to 5 digits of precision to the right of the decimal.

The final line of output for each set should be a blank line. (Follow the sample output format.)

Sample Input

2 3
6 3 8
3 5
51 19 27 14 33
5 9
1 2 3 5 7 11 13 17 19
Sample Output

Set #1
0: 6 3
1: 8
IMBALANCE = 1.00000

Set #2
0: 51
1: 19 27
2: 14 33
IMBALANCE = 6.00000

Set #3
0: 1 17
1: 2 13
2: 3 11
3: 5 7
4: 19
IMBALANCE = 11.60000

*/