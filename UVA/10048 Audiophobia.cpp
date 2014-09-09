/* 14020678	10048	Audiophobia	Accepted	C++	0.026	2014-08-11 07:36:40 */
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
#define MAX_N 105
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int W[MAX_N][MAX_N];
int main(){
	int C, S, Q, c = 1;
	while (scanf("%d%d%d", &C, &S, &Q) == 3){
		if (C == 0 && S == 0 && Q == 0)
			break;
		if (c > 1)	putchar('\n');
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				W[i][j] = INF;
		for (int i = 0; i < S; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			W[a][b] = W[b][a] = w;
		}
		for (int k = 1; k <= C; k++)
			for (int i = 1; i <= C; i++)
				for (int j = 1; j <= C; j++)
					W[i][j] = min(W[i][j], max(W[i][k], W[k][j]));
		printf("Case #%d\n", c++);
		for (int i = 0; i < Q; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if (W[a][b] == INF)
				puts("no path");
			else
				printf("%d\n", W[a][b]);
		}
	}
	return 0;
}
/*


Problem B: Audiophobia
Consider yourself lucky! Consider yourself lucky to be still breathing and having fun participating in this contest. But we apprehend that many of your descendants may not have this luxury. For, as you know, we are the dwellers of one of the most polluted cities on earth. Pollution is everywhere, both in the environment and in society and our lack of consciousness is simply aggravating the situation.
However, for the time being, we will consider only one type of pollution ­- the sound pollution. The loudness or intensity level of sound is usually measured in decibels and sound having intensity level 130 decibels or higher is considered painful. The intensity level of normal conversation is 60­65 decibels and that of heavy traffic is 70­80 decibels.

Consider the following city map where the edges refer to streets and the nodes refer to crossings. The integer on each edge is the average intensity level of sound (in decibels) in the corresponding street.


To get from crossing A to crossing G you may follow the following path: A­C­F­G. In that case you must be capable of tolerating sound intensity as high as 140 decibels. For the paths A­B­E­G, A­B­D­G and A­C­F­D­G you must tolerate respectively 90, 120 and 80 decibels of sound intensity. There are other paths, too. However, it is clear that A­C­F­D­G is the most comfortable path since it does not demand you to tolerate more than 80 decibels.

In this problem, given a city map you are required to determine the minimum sound intensity level you must be able to tolerate in order to get from a given crossing to another.

Input

The input may contain multiple test cases.

The first line of each test case contains three integers  $C (\le 100)$,  $S (\le
1000)$ and  $Q (\le 10000)$ where C indicates the number of crossings (crossings are numbered using distinct integers ranging from 1 to C), S represents the number of streets and Q is the number of queries.

Each of the next S lines contains three integers: c1, c2 and d indicating that the average sound intensity level on the street connecting the crossings c1 and c2 (  $c_1 \ne c_2$) is d decibels.

Each of the next Q lines contains two integers c1 and c2 (  $c_1 \ne c_2$) asking for the minimum sound intensity level you must be able to tolerate in order to get from crossing c1 to crossing c2.

The input will terminate with three zeros form C, S and Q.

Output

For each test case in the input first output the test case number (starting from 1) as shown in the sample output. Then for each query in the input print a line giving the minimum sound intensity level (in decibels) you must be able to tolerate in order to get from the first to the second crossing in the query. If there exists no path between them just print the line ``no path".

Print a blank line between two consecutive test cases.

Sample Input

7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
Sample Output

Case #1
80
60
60

Case #2
40
no path
80


Miguel Revilla
2000-12-26

*/