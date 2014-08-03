/* 5534492	 Dec 28, 2013 12:04:11 PM	Shark	 336C - Vasily the Bear and Sequence	 GNU C++	Accepted	92 ms	1400 KB */
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[100000];
		vector<int> Q;
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		for (int i = 31; i >= 1; i--){
			long long int tmp = (1 << i) - 1;
			for (int j = n - 1; j >= 0 && M[j] >= (1 << (i - 1)); j--){
				if ((M[j] & (1 << (i - 1)))){
					tmp &= M[j];
					Q.push_back(M[j]);
				}
			}
			if (tmp % (1 << (i - 1)) == 0){
				printf("%d\n", Q.size());
				printf("%d", Q[0]);
				for (int i = 1; i < Q.size(); i++)
					printf(" %d", Q[i]);
				putchar('\n');
				break;
			}
			Q.clear();
		}
	}
	return 0;
}
/*

C. Vasily the Bear and Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasily the bear has got a sequence of positive integers a1, a2, ..., an. Vasily the Bear wants to write out several numbers on a piece of paper so that the beauty of the numbers he wrote out was maximum.

The beauty of the written out numbers b1, b2, ..., bk is such maximum non-negative integer v, that number b1 and b2 and ... and bk is divisible by number 2v without a remainder. If such number v doesn't exist (that is, for any non-negative integer v, number b1 and b2 and ... and bk is divisible by 2v without a remainder), the beauty of the written out numbers equals -1.

Tell the bear which numbers he should write out so that the beauty of the written out numbers is maximum. If there are multiple ways to write out the numbers, you need to choose the one where the bear writes out as many numbers as possible.

Here expression x and y means applying the bitwise AND operation to numbers x and y. In programming languages C++ and Java this operation is represented by "&", in Pascal — by "and".

Input
The first line contains integer n (1 ≤ n ≤ 105). The second line contains n space-separated integers a1, a2, ..., an (1 ≤ a1 < a2 < ... < an ≤ 109).

Output
In the first line print a single integer k (k > 0), showing how many numbers to write out. In the second line print k integers b1, b2, ..., bk — the numbers to write out. You are allowed to print numbers b1, b2, ..., bk in any order, but all of them must be distinct. If there are multiple ways to write out the numbers, choose the one with the maximum number of numbers to write out. If there still are multiple ways, you are allowed to print any of them.

Sample test(s)
input
5
1 2 3 4 5
output
2
4 5
input
3
1 2 4
output
1
4

*/