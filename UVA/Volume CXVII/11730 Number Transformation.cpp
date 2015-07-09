/* 14248518	11730	Number Transformation	Accepted	C++	0.016	2014-09-23 02:43:54 */
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
#define MAX_N 105
#define MAX_M 1005
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
vector<int> prime;
int step[MAX_M];
void makePrime(){
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5, j, gap = 2; i <= 1000; i += gap, gap = 6 - gap){
		for (j = 0; j < prime.size(); j++)
			if (i%prime[j] == 0)
				break;
		if (j >= prime.size())
			prime.push_back(i);
	}
}
int main(){
	makePrime();
	int s, t, c = 1;
	while (scanf("%d%d", &s, &t) == 2 && s && t){
		for (int i = 1; i <= 1000; i++)
			step[i] = INF;
		step[s] = 0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int num = Q.front();	Q.pop();
			for (int i = 0, tmp = num; i < prime.size() && prime[i] <= tmp && tmp > 1; i++){
				if (tmp % prime[i] == 0 && num != prime[i]){
					while (tmp % prime[i] == 0)
						tmp /= prime[i];
					if (num + prime[i] <= t && step[num + prime[i]] > step[num] + 1)
						Q.push(num + prime[i]), step[num + prime[i]] = step[num] + 1;
				}
			}
		}
		if (step[t] == INF)
			printf("Case %d: %d\n", c++, -1);
		else
			printf("Case %d: %d\n", c++, step[t] - step[s]);
	}
	return 0;
}
/*

H
Number Transformation
Input: Standard Input
Output: Standard Output

You are given an integer number S. You can transform any integer number A to another integer number B by adding x to A. This x is an integer number which is a prime factor of A (Please note that 1 and A are not being considered as a factor of A). Now, your task is to find the minimum number of transformations required to transform S to another integer number T.

Input

For each test case, there will be a line with two integers, S (1<=S<=100) & T (1<=T<=1000), as described above. The last test case will be followed by a line with two 0 s denoting end of output. This case should not be processed.

Output

For every test case except the last one, print a line of the form ¡§Case X: Y¡¨ where X is the serial number of output (starting from 1). Y is the minimum number of transformations required to transform S to T. If it is not possible to make T from S with the given rules, Y shall be -1.

Sample Input                                               Output for Sample Input
6 12
6 13
0 0

Case 1: 2
Case 2: -1

Explanation of case 1: You can make 12 from 6 in 2 steps in this way: 6->9->12.
Problem Setter: Mohammad Mahmudur Rahman, Special Thanks: Md. Arifuzzaman Arif

*/