/* 5444240	 Dec 15, 2013 1:51:28 PM	Shark	 364C - Beautiful Set	 GNU C++	Accepted	15 ms	400 KB */
#include <cstdio>
#include <string.h>
#include <map>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		int ans[10001];
		bool found = false;
		long long int limit = 2 * n*n;
		for (int i = 1; !found; i++){
			map<int, int> used;
			int add[10001], ptr = 0, count = 0;
			for (int j = 0; j < i; j++)
				used[prime[j]] = true, add[ptr++] = prime[j], ans[count++] = prime[j];
			while (count < n){
				int tmp[10001], tmpptr = 0;
				for (int j = 0; j < i; j++){
					for (int k = 0; k < ptr; k++){
						if (add[k] * prime[j] <= limit){
							used[add[k] * prime[j]]++;
							if (used[add[k] * prime[j]] == 1)
								tmp[tmpptr++] = add[k] * prime[j], ans[count++] = add[k] * prime[j];
						}
					}
				}
				if (ptr == 0) // can not found more
					break;
				ptr = tmpptr;
				for (int j = 0; j < tmpptr; j++)
					add[j] = tmp[j];
			}
			if (n <= count){
				printf("%d", ans[0]);
				for (int j = 1; j < n; j++)
					printf(" %d", ans[j]);
				putchar('\n');
				found = true;
			}
		}
	}
	return 0;
}
/*

C. Beautiful Set
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
We'll call a set of positive integers a beautiful if the following condition fulfills: for any prime p, if , then . In other words, if one number from the set is divisible by prime p, then at least half of numbers from the set is divisible by p.

Your task is to find any beautiful set, where the number of elements is equal to k and each element doesn't exceed 2k2.

Input
The first line contains integer k (10 ≤ k ≤ 5000) that shows how many numbers the required beautiful set should have.

Output
In the first line print k space-separated integers that are a beautiful set. If there are multiple such sets, you are allowed to print any of them.

Sample test(s)
input
10
output
16 18 24 27 36 48 54 72 108 144

*/