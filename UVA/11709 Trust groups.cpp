/* 14058813	11709	Trust groups	Accepted	C++	0.402	2014-08-18 07:37:57 */
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
#define MAX_N 1005
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
bool instack[MAX_N];
map<string, int> S;
vector<int> E[MAX_N];
int sccCount;
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
			instack[j] = false;
		} while (j != i);
		sccCount++;
	}
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)
			break;
		(void)getchar();
		S.clear();
		for (int i = 0; i < n; i++)
			E[i].clear();
		for (int i = 0; i < n; i++){
			char str[1000];
			gets(str);
			S[str] = i;
		}
		for (int i = 0; i < m; i++){
			char A[1000], B[1000];
			gets(A);
			gets(B);
			int a = S[A], b = S[B];
			E[a].push_back(b);
		}
		memset(V, NONE, sizeof(V));
		memset(instack, false, sizeof(instack));
		t = top = sccCount = 0;
		for (int i = 0; i < n; i++)
			if (V[i] == NONE)
				DFS(i);
		printf("%d\n", sccCount);
	}
	return 0;
}
/*

Trust groups
The personnel department of Association of Cookie Monsters (ACM) has noticed that the productivity of various work groups in the company is not as good as it could be. They have interviewed the employees in the affected groups and they have detected the root of the problem: trust (or, rather, the lack thereof). Some employees do not trust the rest of the group, and this is decreasing their motivation and happiness. The personnel department wants to solve this problem, and has decided to reorganize the groups so that they are stable, i.e., they are formed by people who trust each other. They have asked the employees, and they know the people each employee trusts directly. Moreover, if employee A trusts employee B and employee B trusts employee C, then employee A will trust employee C. And obviously, each employee trusts himself. They want to create as few groups as possible to reduce administration overhead (they also do not want to work too hard).

With this information they have contacted you, and asked you to write a program that finds the minimum number of stable groups that can be created.

Input

The input consists of several test cases. Each test case begins with a line containing two positive integers P and T ( 1$ \le$P$ \le$1000, 0$ \le$T$ \le$999000) separated by a single space. P lines come next, each containing the name of one person. The names will have the following format: surname, a comma, a space and first name (for example McBride, John or Smith, Peter). Both the surname and the first name will be strings of uppercase or lowercase characters (with no blanks or punctuation marks), with a maximum length of 10 characters. There will not be repetitions in the complete names of the people. After the names there will appear T blocks of 2 lines representing the trust relations between people. Each line of the block will contain the name of a person in the same format as before, and the block will mean that the person in the first line trusts the person in the second line. All people appearing in the confidence relations will have appeared in the previous list of P people.
The input will end with the ``phantom'' test case `0 0', which must not be processed.

Output

For each test case, the output will be a line containing a positive integer representing the minimum number of stable groups of people that can be formed.

Sample Input

3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0
Sample Output

2
3

*/