/* 13988231	10507	Waking up brain	Accepted	C++	0.019	2014-08-04 08:25:18 */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		vector<int> C[30];
		bool used[30] = { false };
		bool awaked[30] = { false };
		char S[100];
		scanf("%s", S);
		for (int i = 0; S[i] != '\0'; i++)
			used[S[i] - 'A'] = awaked[S[i] - 'A'] = true;
		for (int i = 0; i < m; i++){
			char tmp[100];
			scanf("%s", tmp);
			used[tmp[0] - 'A'] = used[tmp[1] - 'A'] = true;
			C[tmp[0] - 'A'].push_back(tmp[1] - 'A');
			C[tmp[1] - 'A'].push_back(tmp[0] - 'A');
		}
		int year = 0;
		while (true){
			vector<int> awake;
			for (int i = 0; i < 26; i++){
				if (!awaked[i]){
					int count = 0;
					for (int j = 0; j < C[i].size(); j++)
						if (C[i][j] != i && awaked[C[i][j]])
							count++;
					if (count >= 3)
						awake.push_back(i);
				}
			}
			if (awake.size() == 0)	break;
			for (int i = 0; i < awake.size(); i++)
				awaked[awake[i]] = true;
			year++;
		}
		int countAwake = 0;
		for (int i = 0; i < 26; i++)
			if (awaked[i])
				countAwake++;
		if (countAwake == n)
			printf("WAKE UP IN, %d, YEARS\n", year);
		else
			puts("THIS BRAIN NEVER WAKES UP");
	}
	return 0;
}
/*

Problem H
Waking up brain

Most recent researches on Neuroanatomy have permitted us of identifying a series of large electric signal transmision route connecting different areas of the brain. Even more, it has been found that if one slept area X of the brain is directly connected to at least three awake areas for a year, the X area will wake up. There is evidence of when an area X of the brain wakes up, it remains awake. Let A, B, C... the different areas of the brain and let´s imagine a brain with some initially slept areas, interconnected one another. If three of these areas wake up by direct stimulation according to the previous researches, how many years will all the slept areas take to wake up?

Input
The input file contains several test cases, each of them as described below. There is a blank line between two consecutive inputs.
·          The first line of the input is an integer, 3 £ N £ 26, that indicates the number of slept areas.
·          The second line of the input is an integer M ³ 0, that indicates the number of connections (if A is connected to B, then B is connected to A, but it counts only once).
·          The third line consists of three characters that indicate which areas have wake up by direct stimulation.
·          The remaining M lines consist of two characters each one, that indicate the different conections between areas of the brain, one line per conection.

Output
The output is only one line with one of the following text messages:

·          “THIS BRAIN NEVER WAKES UP”
·          “WAKE UP IN, “ n “, YEARS”, where n is the number of the years all the brain has taken to wake up.

Sample Input
6
11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH

Sample Output
WAKE UP IN, 3, YEARS

*/