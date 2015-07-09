/* 14166343	1195	Calling Extraterrestrial Intelligence Again	Accepted	C++	0.216	2014-09-08 08:44:24 */
// C++
#include<iostream>
#include<stack>
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
#define MAX_N 100000
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
struct data{
	int m, p, q;
};
vector<int> prime;
vector<data> mul;
void makePrime(){
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5,j, gap = 2; i <= MAX_N; i += gap, gap = 6 - gap){
		for (j = 0; j < prime.size(); j++)
			if (i%prime[j] == 0)
				break;
		if (j >= prime.size())
			prime.push_back(i);
	}
}
bool cmp(data A, data B){
	return A.m < B.m;
}
void makeMul(){
	for (int i = 0; i < prime.size(); i++){
		for (int j = i; j < prime.size(); j++){
			if ((lli)prime[i] * prime[j] > MAX_N)break;
			mul.push_back(data{ prime[i] * prime[j], prime[i], prime[j] });
		}
	}
	sort(mul.begin(), mul.end(), cmp);
}
int main(){
	makePrime();
	makeMul();
	int m, a, b;
	while (scanf("%d%d%d", &m, &a, &b) == 3){
		if (m == 0 && a == 0 && b == 0)break;
		int L = 0, R = mul.size() - 1;
		while (R >= L){
			int mid = (L + R) / 2;
			if (mul[mid].m > m)
				R = mid - 1;
			else
				L = mid + 1;
		}
		for (int i = L - 1; i >= 0; i--){
			if (a *mul[i].q <= mul[i].p *b){
				printf("%d %d\n", mul[i].p, mul[i].q);
				break;
			}
		}
	}
	return 0;
}
/*

A message from humans to extraterrestrial inteIigence was sent through the Arecibo radio telescope in Puerto Rico on the afternoon of Saturday November l6, l974. The message consisted of l679 bits and was meant to be translated to a rectangular picture with 23 x 73 pixels. Since both 23 and 73 are prime numbers, 23 x 73 is the unique possible size of the translated rectangular picture each edge of which is longer than l pixel. Of course, there was no guarantee that the receivers would try to translate the message to a rectangular picture. Even if they would, they might put the pixels into the rectangle incorrectly. The senders of the Arecibo message were optimistic.


We are planning a similar project. Your task in the project is to find the most suitable width and height of the translated rectangular picture. The term ``most suitable'' is defined as follows. An integer m greater than 4 is given. A positive fraction a/b less than or equal to 1 is also given. The area of the picture should not be greater than m . Both of the width and the height of the translated picture should be prime numbers. The ratio of the width to the height should not be less than a/b nor greater than 1. You should maximize the area of the picture under these constraints.


In other words, you will receive an integer m and a haction a/b . It holds that m > 4 and 0 < a/b$ \le$1 . You should find the pair of prime numbers p, q such that pq$ \le$m and a/b$ \le$p/q$ \le$1 , and furthermore, the product pq takes the maximum value among such pairs of two prime numbers. You should report p and q as the ``most suitable'' width and height of the translated picture.

Input

The input is a sequence of at most 2000 triplets of positive integers, delimited by a space character in between. Each line contains a single triplet. The sequence is followed by a triplet of zeros, 0 0 0, which indicates the end of the input and should not be treated as data to be processed.


The integers of each input triplet are the integer m , the numerator a , and the denominator b described above, in this order. You may assume 4 < m$ \le$100000 and 1$ \le$a$ \le$b$ \le$1000 .

Output

The output is a sequence of pairs of positive integers. The i -th output pair corresponds to the i -th input triplet. The integers of each output pair are the width p and the height q described above, in this order.


Each output line contains a single pair. A space character is put between the integers as a delimiter. No other characters should appear in the output.

Sample Input

5 1 2
99999 999 999
1680 5 16
1970 1 1
2002 4 11
0 0 0
Sample Output

2 2
313 313
23 73
43 43
37 53

*/