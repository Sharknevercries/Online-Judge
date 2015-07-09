/* 14016912	10349	Antenna Placement	Accepted	C++	0.016	2014-08-10 10:40:01 */
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
#define MAX_N 50
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int n, m;
vector<int> E[MAX_N * MAX_N];
bool V[MAX_N * MAX_N];
int match[MAX_N * MAX_N];
char T[MAX_N][MAX_N];
int convert(int a, int b){
	return a * m + b;
}
bool DFS(int source){
	for (int i = 0; i < E[source].size(); i++){
		int target = E[source][i];
		if (!V[target]){
			V[target] = true;
			if (match[target] == NONE || DFS(match[target])){
				match[target] = source, match[source] = target;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				E[convert(i,j)].clear();
		for (int i = 0; i < n; i++)
			scanf("%s", T[i]);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (T[i][j] == 'o')	continue;
				for (int k = 0; k < 4; k++){
					int nextX = j + mx[k], nextY = i + my[k];
					if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || T[nextY][nextX] == 'o')
						continue;
					E[convert(i, j)].push_back(convert(nextY, nextX));
				}
			}
		}
		int ans = 0;
		memset(match, NONE, sizeof(match));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (T[i][j] == '*' && match[convert(i, j)] == NONE){
					memset(V, false, sizeof(V));
					if (DFS(convert(i, j)))
						ans++;
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (T[i][j] == '*' && match[convert(i, j)] == NONE)
					ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem E
Antenna Placement
Input: standard input
Output: standard output
Time Limit: 1 second
Memory Limit: 32 MB

The Global Aerial Research Centre has been allotted the task of building the fifth generation of mobile phone nets in Sweden. The most striking reason why they got the job, is their discovery of a new, highly noise resistant, antenna. It is called 4DAir, and comes in four types. Each type can only transmit and receive signals in a direction aligned with a (slightly skewed) latitudinal and longitudinal grid, because of the interacting electromagnetic field of the earth. The four types correspond to antennas operating in the directions north, west, south, and east, respectively. Below is an example picture of places of interest, depicted by twelve small rings, and nine 4DAir antennas depicted by ellipses covering them.

Obviously, it is desirable to use as few antennas as possible, but still provide coverage for each place of interest. We model the problem as follows: Let A be a rectangular matrix describing the surface of Sweden, where an entry of A either is a point of interest, which must be covered by at least one antenna, or empty space. Antennas can only be positioned at an entry in A. When an antenna is placed at row r and column c, this entry is considered covered, but also one of the neighbouring entries (c+1,r),(c,r+1),(c-1,r), or (c,r-1), is covered depending on the type chosen for this particular antenna. What is the least number of antennas for which there exists a placement in A such that all points of interest are covered?

Input
On the first row of input is a single positive integer n, specifying the number of scenarios that follow. Each scenario begins with a row containing two positive integers h and w, with 1<h<40 and 0<w<10. Thereafter is a matrix presented, describing the points of interest in Sweden in the form of h lines, each containing w characters from the set [．*・,・o・]. A ．*・-character symbolises a point of interest, whereas a ．o・-character represents open space.
Output
For each scenario, output the minimum number of antennas necessary to cover all ．*・-entries in the scenario・s matrix, on a row of its own.

Sample Input
2
7 9
ooo**oooo
**oo*ooo*
o*oo**o**
ooooooooo
*******oo
o*o*oo*oo
*******oo
10 1
*
*
*
o
*
*
*
*
*
*

Sample Output
17
5
Swedish National Contest.

*/