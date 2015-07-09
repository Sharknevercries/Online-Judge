/* 1474609	3619	Sum of Different Primes	Accepted	C++	0.006	2014-06-29 08:52:48 */
#include<cstdio>
#include<vector>
#include<string.h>
#define N 1120
#define K 14
using namespace std;
vector<int> P;
int DP[1121][15];
void make(){
	P.clear();
	P.push_back(2);
	P.push_back(3);
	int i, j, gap = 2;
	for (i = 5; i <= N; i += gap, gap = 6 - gap){
		for (j = 0; j < P.size(); j++)
			if (i % P[j] == 0)
				break;
		if (j >= P.size())
			P.push_back(i);
	}
}
void solve(){
	make();
	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;
	// prime can't add twice
	for (int k = 0; k < P.size(); k++){
		for (int i = N; i >= 1; i--){
			if (i - P[k] < 0)	break;
			for (int j = K; j >= 1; j--){
				DP[i][j] += DP[i - P[k]][j - 1];
			}
		}
	}
}
int main(){
	solve();

	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		printf("%d\n", DP[n][m]);
	}
	return 0;
}
/*

A positive integer may be expressed as a sum of different prime numbers (primes), in one way or another. Given two positive integers n and k, you should count the number of ways to express n as a sum of k different primes. Here, two ways are considered to be the same if they sum up the same set of the primes. For example, 8 can be expressed as 3 + 5 and 5 + 3 but they are not distinguished.

When n and k are 24 and 3 respectively, the answer is two because there are two sets {2, 3, 19} and {2, 5, 17} whose sums are equal to 24. There are no other sets of three primes that sum up to 24. For n = 24 and k = 2, the answer is three, because there are three sets {5, 19}, {7, 17} and {11, 13}. For n = 2 and k = 1, the answer is one, because there is only one set {2} whose sum is 2. For n = 1 and k = 1, the answer is zero. As 1 is not a prime, you shouldn't count {1}. For n = 4 and k = 2, the answer is zero, because there are no sets of two different primes whose sums are 4.

Your job is to write a program that reports the number of such ways for the given n and k.

Input

The input is a sequence of datasets followed by a line containing two zeros separated by a space. A dataset is a line containing two positive integers n and k separated by a space. You may assume that n$ \le$1120 and k$ \le$14.

Output

The output should be composed of lines, each corresponding to an input dataset. An output line should contain one non-negative integer indicating the number of ways for n and k specified in the corresponding dataset. You may assume that it is less than 231.

Sample Input

24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
1000 10
1120 14
0 0
Sample Output

2
3
1
0
0
2
1
0
1
55
200102899
2079324314

*/