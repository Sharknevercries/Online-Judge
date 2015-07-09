/* 14248398	10490	Mr. Azad and his Son!!!!!	Accepted	C++	0.016	2014-09-23 02:08:28 */
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
#define MAX_N 1000
#define MAX_M 1000
#define MOD 1000000007
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
ull perfectNumber(int n){
	return (ull)pow(2, n - 1) * (pow(2, n) - 1);
}
ull factor(ull s){
	ull sum = 0;
	for (ull i = 1; i <= sqrt((double)s); i++)
		if (s % i == 0)
			sum += i + s / i;
	if (sqrt((double)s) == (ull)sqrt((double)s))
		sum -= sqrt((double)s);
	return sum;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		ull m = perfectNumber(n);
		ull a = factor((ull)pow(2, n - 1));
		ull b = (factor((ull)pow(2, n) - 1));
		if (m == a*b - m)
			printf("Perfect: %llu!\n", m);
		else{
			vector<int> prime;
			prime.push_back(2);
			prime.push_back(3);
			for (int i = 5,j,  gap = 2; i <= 31; i += gap, gap = 6 - gap){
				for (j = 0; j < prime.size(); j++)
					if (i%prime[j] == 0)
						break;
				if (j >= prime.size())
					prime.push_back(i);
			}
			bool isPrime = false;
			for (int i = 0; i < prime.size() && !isPrime; i++)
				if (prime[i] == n)
					isPrime = true;
			if (isPrime)
				puts("Given number is prime. But, NO perfect number is available.");
			else
				puts("Given number is NOT prime! NO perfect number is available.");
		}
	}
	return 0;
}
/*

Problem G
Mr. Azad and His Son!!!!!
Input: standard input
Output: standard output
Time Limit: 4 seconds

There are a lot of Abul Kalam Azad in Bangladesh. But, why is he so special? Not that he is my dad is the only reason. He can wonderfully do some calculation. If anyone gives him any positive integer, he amazingly can say the relative perfect number using the formula 2^(k-1)*(2^k-1) without using neither calculator nor computer. Say, I have told him to find out the relative perfect number of 2, he replies 6 which is a perfect number. But perfect is not possible for all the integers. I have asked him the process, but he says that I should find this thing out by myself how an integer is related to a perfect number. Anyway, I have challenged him that it is very possible for me to do the same calculation using a computer. Although I could not figure out how he can do this, I know that the next ACM Online Programming Contest is near at hand and World's top programmers are available to solve my very simple problem.

Now, you are to write a program for me to win over my dad, which will take input n, and determine the perfect number p.

Input
An integer 1<n<=31 is given in each input line. Input is terminated by a zero in a single line. This input should not be processed. All the output numbers will fit in 64 bit signed integer.

Output
Output will be in the following format:

If perfect number is possible -
Perfect: p!

If perfect number is not possible, but given number is prime -
Given number is prime. But, NO perfect number is available.

If perfect number is not possible and given number is not prime -
Given number is NOT prime! NO perfect number is available.


Sample Input
2
3
6
0

Sample Output
Perfect: 6!
Perfect: 28!
Given number is NOT prime! NO perfect number is available.
Tanzim Saqib

*/