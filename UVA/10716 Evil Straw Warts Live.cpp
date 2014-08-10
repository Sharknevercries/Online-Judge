/* 13966450	10716	Evil Straw Warts Live	Accepted	C++	0.016	2014-07-30 08:51:56 */
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
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		string S;
		cin >> S;
		int count[26] = { 0 }, odd = 0;
		for (int i = 0; i < S.length(); i++)
			count[S[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			if (count[i] % 2 == 1)
				odd++;
		if ((S.length() % 2 == 0 && odd > 0) || (S.length() % 2 == 1 && odd > 1))
			puts("Impossible");
		else{
			int step = 0;
			for (int i = 0, j = S.length() - 1; i < j; i++, j--){
				int posL, posR;
				for (posR = j; posR > i; posR--)
					if (S[i] == S[posR])
						break;
				for (posL = i; posL < j; posL++)
					if (S[j] == S[posL])
						break;
				if (j - posR > posL - i){
					step += posL - i;
					for (int k = posL - 1; k >= i; k--)
						swap(S[k], S[k + 1]);
				}
				else{
					step += j - posR;
					for (int k = posR + 1; k <= j; k++)
						swap(S[k], S[k - 1]);
				}
			}
			printf("%d\n", step);
		}
	}
	return 0;
}
/*

Problem D: Evil Straw Warts Live

A palindrome is a string of symbols that is equal to itself when reversed. Given an input string, not necessarily a palindrome, compute the number of swaps necessary to transform the string into a palindrome. By swap we mean reversing the order of two adjacent symbols. For example, the string "mamad" may be transformed into the palindrome "madam" with 3 swaps:
swap "ad" to yield "mamda"
swap "md" to yield "madma"
swap "ma" to yield "madam"
The first line of input gives n, the number of test cases. For each test case, one line of input follows, containing a string of up to 100 lowercase letters. Output consists of one line per test case. This line will contain the number of swaps, or "Impossible" if it is not possible to transform the input to a palindrome.

Sample Input

3
mamad
asflkj
aabb
Output for Sample Input

3
Impossible
2
Gordon V. Cormack

*/