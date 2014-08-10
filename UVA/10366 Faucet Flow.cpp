/* 13962586	10366	Faucet Flow	Accepted	C++	0.016	2014-07-29 12:34:58 */
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
#define WIDTH 2
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int L, R;
	while (scanf("%d%d", &L, &R) == 2){
		if (L == 0 && R == 0)	break;
		int H[MAX_N], M = (-1 - L) / 2, posHL = M, posHR = M + 1;
		int posL, posR, VL, VR;
		lli ans = 0;
		for (int i = 0; i <= (R - L) / 2; i++)
			scanf("%d", H + i);

		for (int i = 0; i <= M; i++)
			if (H[posHL] < H[i])
				posHL = i;
		for (int i = (R - L) / 2; i >= M + 1; i--)
			if (H[posHR] < H[i])
				posHR = i;

		if (H[posHR] > H[posHL]){
			int pos;
			for (pos = M + 1; pos <= posHR; pos++)
				if (H[pos] >= H[posHL])
					break;
			posHR = pos;
		}
		else if (H[posHR] < H[posHL]){
			int pos;
			for (pos = M; pos >= posHL; pos--)
				if (H[pos] >= H[posHR])
					break;
			posHL = pos;
		}
		ans += min(H[posHR], H[posHL]) * (posHR - posHL) * WIDTH;

		posL = posHL, posR = posHR;
		VL = VR = NONE;
		while (true){
			if ((VL == 0 || VL == NONE) && H[posHR] >= H[posHL]){
				if (H[posL] <= H[posHR]){
					int pos = posL - 1;
					for (int i = posL - 1; i >= 0; i--)
						if (H[pos] < H[i])
							pos = i;
					if (pos >= 0)
						VL = min(H[pos], H[posHR]) * (posL - pos) * WIDTH;
					else
						break;
					posL = pos;
				}
				else
					VL = NONE;
			}
			if ((VR == 0 || VR == NONE) && H[posHR] <= H[posHL]){
				if (H[posR] <= H[posHL]){
					int pos = posR + 1;
					for (int i = posR + 1; i <= (R - L) / 2; i++)
						if (H[pos] < H[i])
							pos = i;
					if (pos <= (R - L) / 2)
						VR = min(H[pos], H[posHL]) * (pos - posR) * WIDTH;
					else
						break;
					posR = pos;
				}
				else
					VR = NONE;
			}
			int tmp;
			if (VL != NONE && VR != NONE)
				tmp = min(VL, VR), VL -= tmp, VR -= tmp, ans += 2 * tmp;
			else if (VL != NONE)
				tmp = VL, VL -= tmp, ans += tmp;
			else
				tmp = VR, VR -= tmp, ans += tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem E: Faucet Flow

A faucet is pouring water into a long, thin aquarium with various vertical dividers (walls) in it. The aquarium is initially empty, and its bottom is perfectly level. How long will it take for water to spill over its left- or right-most divider? The faucet is above location x=0, and the dividers are located at x=-1, -3, -5, ..., leftx and 1, 3, 5, ..., rightx. The dividers are attached perpendicular to the floor and sides of the aquarium, and have various heights. The aquarium's length is greater than rightx-leftx, its walls are higher than the highest divider, and its width is 1 unit everywhere. Water pours from the faucet at a rate of 1 cubic unit per second. [You may assume that water is an ideal liquid: it always flows downhill and if it cannot flow downhill it spreads at an equal rate in all horizontal directions.]
Input

Each test case consists of two integers leftx (an odd number <= -1) and rightx (an odd number >= 1). Subsequent lines contain the height (a positive integer) of each divider from left to right. There will be no more than 1000 dividers in any test case. Input is terminated with a line containing two zeros.
Output

For each case, output an integer on a single line, indicating how long it will take, in seconds, before water starts spilling over either the left or right divider.
Sample Input

-1 1
3 5
-3 3
4 3 2 1
-3 5
1 2 2 1 1
0 0
Sample Output

6
6
8

*/