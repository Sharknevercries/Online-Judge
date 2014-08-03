/* 5443613	 Dec 15, 2013 11:40:16 AM	Shark	 364B - Free Market	 GNU C++	Accepted	31 ms	2500 KB */
#include <cstdio>
#include <string.h>
#define MAX 510000
bool DP[MAX + 1];
int P[MAX + 1];
int main(){
	int n, d;
	while (scanf("%d%d", &n, &d) == 2){
		int C[50], sum = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &C[i]);
		memset(DP, false, sizeof(DP));
		DP[0] = true;
		for (int i = 0; i < n; i++){ // all possible value
			for (int j = MAX; j - C[i] >= 0; j--){
				if (DP[j - C[i]])
					DP[j] = true;
			}
		}
		for (int i = 0; i <= MAX; i++){ // if the total value is not exist, let it be the previous cost value
			if (DP[i])
				P[i] = i;
			else
				P[i] = P[i - 1];
		}
		int price, day;
		price = day = 0;
		while (price != P[price + d]){ // try to exchange
			price = P[price + d];
			day++;
		}
		printf("%d %d\n", price, day);
	}
	return 0;
}
/*

B. Free Market
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
John Doe has recently found a "Free Market" in his city — that is the place where you can exchange some of your possessions for other things for free.

John knows that his city has n items in total (each item is unique). You can bring any number of items to the market and exchange them for any other one. Note that each item is one of a kind and that means that you cannot exchange set {a, b} for set {v, a}. However, you can always exchange set x for any set y, unless there is item p, such that p occurs in x and p occurs in y.

For each item, John knows its value ci. John's sense of justice doesn't let him exchange a set of items x for a set of items y, if s(x) + d < s(y) (s(x) is the total price of items in the set x).

During one day John can exchange only one set of items for something else. Initially, he has no items. John wants to get a set of items with the maximum total price. Find the cost of such set and the minimum number of days John can get it in.

Input
The first line contains two space-separated integers n, d (1 ≤ n ≤ 50, 1 ≤ d ≤ 104) — the number of items on the market and John's sense of justice value, correspondingly. The second line contains n space-separated integers ci (1 ≤ ci ≤ 104).

Output
Print two space-separated integers: the maximum possible price in the set of items John can get and the minimum number of days needed to get such set.

Sample test(s)
input
3 2
1 3 10
output
4 3
input
3 5
1 2 3
output
6 2
input
10 10000
10000 9999 1 10000 10000 10000 1 2 3 4
output
50010 6
Note
In the first sample John can act like this:

Take the first item (1 - 0 ≤ 2).
Exchange the first item for the second one (3 - 1 ≤ 2).
Take the first item (1 - 0 ≤ 2).

*/