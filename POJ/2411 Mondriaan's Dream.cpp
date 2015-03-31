/* 14026574	840502	2411	Accepted	900K	563MS	G++	1227B	2015-03-30 17:05:57 */
#include<bits\stdc++.h>
#define N 11
using namespace std;
int w, h;
bool legal[2050];
long long DP[2050][15];
bool check(int state){
	int count = 0;
	while (state > 0){
		if (state & 1)
			count++;
		else if (count & 1)
			return false;
		state >>= 1;
	}
	if (count & 1)
		return false;
	return true;
}
int main(){
	for (int state = 0; state < (1 << N); state++)
		legal[state] = check(state);
	while (scanf("%d%d", &h, &w) == 2){
		if (h == 0 && w == 0)	break;
		memset(DP, 0, sizeof(DP));
		for (int state = 0; state < (1 << w); state++)
			if (legal[state])
				DP[state][0] = 1;
		for (int i = 1; i < h; i++){
			for (int state1 = 0; state1 < (1 << w); state1++){
				for (int state2 = 0; state2 < (1 << w); state2++){
					if ((state1 | state2) != (1 << w) - 1)	continue;
					if (!legal[state1 & state2])	continue;
					DP[state1][i] += DP[state2][i - 1];
					/*
					以 1 表示已放置方塊(橫的)； 0 表示未放置(豎的)
					每一行狀態連續1的數量為偶數

					11011
					11011
					-----
					11111

					兩行都放置豎的會合成 1
					
					*/
				}
			}
		}
		printf("%lld\n", DP[(1 << w) - 1][h - 1]);
	}
	return 0;
}
/*

Mondriaan's Dream
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 12504		Accepted: 7303
Description

Squares and rectangles fascinated the famous Dutch painter Piet Mondriaan. One night, after producing the drawings in his 'toilet series' (where he had to use his toilet paper to draw on, for all of his paper was filled with squares and rectangles), he dreamt of filling a large rectangle with small rectangles of width 2 and height 1 in varying ways.


Expert as he was in this material, he saw at a glance that he'll need a computer to calculate the number of ways to fill the large rectangle whose dimensions were integer values, as well. Help him, so that his dream won't turn into a nightmare!
Input

The input contains several test cases. Each test case is made up of two integer numbers: the height h and the width w of the large rectangle. Input is terminated by h=w=0. Otherwise, 1<=h,w<=11.
Output

For each test case, output the number of different ways the given rectangle can be filled with small rectangles of size 2 times 1. Assume the given large rectangle is oriented, i.e. count symmetrical tilings multiple times.
Sample Input

1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
Sample Output

1
0
1
2
3
5
144
51205
Source

Ulm Local 2000

*/