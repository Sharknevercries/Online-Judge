/* 7450650	2014-08-15 11:06:57	Shark	A - Chinese Girls' Amusement	GNU C++	Accepted	30 ms	200 KB */
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
#define MAX_N 5000
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
char S[MAX_N];
char *res;
int len;
bool isOdd(){
	return (S[len - 1] - '0') % 2;
}
char *div2(char *p){
	for (int i = 0; i < len; i++){
		if (S[i] & 1)
			S[i + 1] += 10;
		S[i] >>= 1;
	}
	S[len] = 0;
	while (*p == 0)
		p++;
	return p;
}
char *dec(char *p){
	int i = len - 1;
	while (p[i] == 0)
		p[i--] = 9;
	p[i]--;
	while (*p == 0)
		++p;
	return p;
}
int main(){
	freopen("china.in", "r", stdin);
	freopen("china.out", "w", stdout);
	while (gets(S)){
		len = strlen(S);
		for (int i = 0; i < len; i++)
			S[i] -= '0';
		if (isOdd())
			res = div2(S);
		else{
			res = div2(S);
			res = dec(S);
			if (!isOdd())
				res = dec(S);
		}
		for (int i = 0; i < len; i++)
			S[i] += '0';
		puts(res);
	}
	return 0;
}