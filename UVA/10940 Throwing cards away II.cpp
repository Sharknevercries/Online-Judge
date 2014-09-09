/* 14063310	10940	Throwing cards away II	Accepted	C++	0.039	2014-08-19 07:40:02 */
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
#define MAX_N 1000
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
int odd(int);
int even(int);
int odd(int n){
	if (n == 1)	return 1;
	int left = n / 2;
	if (left == 1)	return 2;
	if (n % 2 == 1)	return even(left) * 2;
	else			return odd(left) * 2;
}
int even(int n){
	int left = n - n / 2;
	if (left == 1)	return 1;
	if (n % 2 == 1)	return odd(left) * 2 - 1;
	else			return even(left) * 2 - 1;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("%d\n", odd(n));
	}
	return 0;
}
/*

Problem G: Throwing cards away II

Given is an ordered deck of n cards numbered 1 to n with card 1 at the top and card n at the bottom. The following operation is performed as long as there are at least two cards in the deck:
Throw away the top card and move the card that is now on the top of the deck to the bottom of the deck.

Your task is to find the last, remaining card.

Each line of input (except the last) contains a positive number n ≤ 500000. The last line contains 0 and this line should not be processed. For each number from input produce one line of output giving the last remaining card. Input will not contain more than 500000 lines.

Sample input

7
19
10
6
0
Output for sample input

6
6
4
4
Folklore, adapted by Piotr Rudnicki

*/