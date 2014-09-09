/* 7472873	2014-08-15 21:22:47	Shark	C - Pashmak and Buses	GNU C++	Accepted	171 ms	100 KB */
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
#define MAX_N 1005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct data{
	int S[MAX_N];
};
int n, d, k;
int main(){
	while (scanf("%d%d%d", &n, &k, &d) == 3){
		if (k >= n){
			for (int s = 0; s < d; s++){
				printf("%d", 1);
				for (int i = 2; i <= n; i++)
					printf(" %d", i);
				putchar('\n');
			}
		}
		else if (k == 1)
			puts("-1");
		else{
			vector<data> Q;
			int len = 1;
			while (true){
				data tmp;
				for (int i = 0, j = 1, s = 0; i < n; i++){
					tmp.S[i] = j, s++;
					if (s >= len)	j++, s = 0;
					if (j > k)	j = 1;
				}
				Q.push_back(tmp);
				if (len * k >= n)	break;
				len *= k;
			}
			if (Q.size() > d)
				puts("-1");
			else{
				for (int i = 0; i < Q.size(); i++){
					for (int j = 0; j < n; j++){
						if (j > 0)	putchar(' ');
						printf("%d", Q[i].S[j]);
					}
					putchar('\n');
				}
				for (int i = 0; i < d - Q.size(); i++){
					for (int j = 0; j < n; j++){
						if (j > 0)	putchar(' ');
						printf("%d", 1);
					}
					putchar('\n');
				}
			}
		}
	}
	return 0;
}
/*

C. Pashmak and Buses
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently Pashmak has been employed in a transportation company. The company has k buses and has a contract with a school which has n students. The school planned to take the students to d different places for d days (each day in one place). Each day the company provides all the buses for the trip. Pashmak has to arrange the students in the buses. He wants to arrange the students in a way that no two students become close friends. In his ridiculous idea, two students will become close friends if and only if they are in the same buses for all d days.

Please help Pashmak with his weird idea. Assume that each bus has an unlimited capacity.

Input
The first line of input contains three space-separated integers n, k, d (1 ≤ n, d ≤ 1000; 1 ≤ k ≤ 109).

Output
If there is no valid arrangement just print -1. Otherwise print d lines, in each of them print n integers. The j-th integer of the i-th line shows which bus the j-th student has to take on the i-th day. You can assume that the buses are numbered from 1 to k.

Sample test(s)
input
3 2 2
output
1 1 2
1 2 1
input
3 2 1
output
-1
Note
Note that two students become close friends only if they share a bus each day. But the bus they share can differ from day to day.

*/