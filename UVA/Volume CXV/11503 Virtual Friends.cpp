/* 13988560	11503	Virtual Friends	Accepted	C++	1.979	2014-08-04 09:10:43 */
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
#define MAX_N 100005
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int G[MAX_N];
int C[MAX_N];
int find(int x){
	return x == G[x] ? x : G[x] = find(G[x]);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		for (int i = 1; i < MAX_N; i++)
			G[i] = i, C[i] = 1;
		int n, ptr = 1;
		map<string, int> M;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			string a, b;
			cin >> a >> b;
			if (M[a] == 0) M[a] = ptr++;
			if (M[b] == 0) M[b] = ptr++;
			int x = find(M[a]);
			int y = find(M[b]);
			if (x != y){
				G[y] = x;
				C[x] += C[y];
			}
			printf("%d\n", C[x]);
		}
	}
	return 0;
}
/*

Problem C: Virtual Friends

These days, you can do all sorts of things online. For example, you can use various websites to make virtual friends. For some people, growing their social network (their friends, their friends' friends, their friends' friends' friends, and so on), has become an addictive hobby. Just as some people collect stamps, other people collect virtual friends.
Your task is to observe the interactions on such a website and keep track of the size of each person's network.

Assume that every friendship is mutual. If Fred is Barney's friend, then Barney is also Fred's friend.

Input Specification

The first line of input contains one integer specifying the number of test cases to follow. Each test case begins with a line containing an integer F, the number of friendships formed, which is no more than 100 000. Each of the following F lines contains the names of two people who have just become friends, separated by a space. A name is a string of 1 to 20 letters (uppercase or lowercase).
Sample Input

1
3
Fred Barney
Barney Betty
Betty Wilma
Output Specification

Whenever a friendship is formed, print a line containing one integer, the number of people in the social network of the two people who have just become friends.
Output for Sample Input

2
3
4
Ondřej Lhoták

*/