/* 13997621	441	Lotto	Accepted	C++	0.018	2014-08-06 08:03:46 */
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
int S[MAX_N];
int T[MAX_N], ptr;
int n;
void DFS(int start){
	if (ptr == 6){
		printf("%d", T[0]);
		for (int i = 1; i < 6; i++)
			printf(" %d", T[i]);
		putchar('\n');
		return;
	}
	for (int i = start; i < n; i++){
		T[ptr++] = S[i];
		DFS(i + 1);
		ptr--;
	}
}
int main(){
	int c = 0;
	while (scanf("%d", &n) == 1 && n){
		if (c++)	putchar('\n');
		ptr = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		sort(S, S + n);
		DFS(0);
	}
	return 0;
}
/*

Lotto

In the German Lotto you have to select 6 numbers from the set {1,2,...,49}.

A popular strategy to play Lotto - although it doesn't increase your chance of winning - is to select a subset S containing k (k>6) of these 49 numbers, and then play several games with choosing numbers only from S.

For example, for k=8 and S = 1,2,3,5,8,13,21,34 there are 28 possible games: [1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34].

Your job is to write a program that reads in the number k and the set S and then prints all possible games choosing numbers only from S.

Input Specification

The input file will contain one or more test cases.

Each test case consists of one line containing several integers separated from each other by spaces. The first integer on the line will be the number k (6 < k < 13). Then k integers, specifying the set S, will follow in ascending order.

Input will be terminated by a value of zero (0) for k.

Output Specification

For each test case, print all possible games, each game on one line.

The numbers of each game have to be sorted in ascending order and separated from each other by exactly one space. The games themselves have to be sorted lexicographically, that means sorted by the lowest number first, then by the second lowest and so on, as demonstrated in the sample output below.

The test cases have to be separated from each other by exactly one blank line. Do not put a blank line after the last test case.

Sample Input

7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
Sample Output

1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34

*/