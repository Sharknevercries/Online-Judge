/* 13917518	907	Winterim Backpacking Trip	Accepted	C++	0.009	2014-07-21 07:16:38 */
/*

Template By Shark

*/
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
int S[MAX_N];
int n, k;
bool check(int max){
	int res = 0, tmp = 0;
	for (int i = 0; i < n + 1; i++){
		if (S[i] > max)	return false;
		if (tmp + S[i] <= max)
			tmp += S[i];
		else
			res++, tmp = S[i];
	}
	res++;
	return res <= k + 1;
}
int main(){
	while (scanf("%d%d", &n, &k) == 2){
		int  sum = 0;
		for (int i = 0; i < n + 1; i++)
			scanf("%d", S + i), sum += S[i];
		int L = 0, R = sum;
		while (R > L){
			int mid = (L + R) / 2;
			if (check(mid))
				R = mid;
			else
				L = mid + 1;
		}
		printf("%d\n", L);
	}
	return 0;
}
/*

Problem C

Winterim Backpacking Trip

This Winter we are going on a trip along the Appalachian Trail. The trail is a continuous marked footpath that goes from Katahdin in Maine to Springer Mountain in Georgia, a distance of about 2160 miles. Even though our trip will only consider some part of the trail, it will be our first real backpacking experience and an excellent opportunity to acquire winter camping skills.

Part of the experience is also the route planning of the trip. We have a list of all possible campsites that we can use along the way and we want to do this trip so that we only stop K nights to camp. We also know in advance the distance between consecutive campsites and we are only allowed to camp at a campsite. Our goal is to plan the trip so that we minimise the maximum amount of walking done in a single day. In other words, if our trip involves 2 nights (3 days of walking), and we walk 9, 10, 5 miles on each day respectively, the cost (maximum amount of walking done in one day) is 10. Another schedule that involves walking 9, 6, 9 miles on each day has cost 9.

Problem

Given the distances between N consecutive campsites of a trail and given the number of nights for your trip, K, your task is to devise a camping strategy for the specified trail such that it minimises the maximum amount of walking done in a single day. Note that the first distance value given is the distance from our start-point of the trail to our 1st campsite, and the last distance value given is the distance from our Nth campsite to our end-point of the trail.

Input

The input file contains several test cases, each of them as describes below.
The first line of input consists of two numbers, the number of campsites (0 < N <= 600) and the number of nights of the trip (0 <= K <= 300). The following N+1 input lines indicate the distance in miles between consecutive campsite locations.

Output

For each test case, on a line by itself, your program must output the maximum amount of walking in a single day for the route that minimises such value.
Sample Input

4 3
7
2
6
4
5
Sample Output

8
Fernando Silva, MIUP'2003
(Portuguese National ACM Programming Contest)

*/