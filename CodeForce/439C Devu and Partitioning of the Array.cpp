/* 6807090	 2014-06-04 20:46:03	Shark	 C - Devu and Partitioning of the Array	 GNU C++	Accepted	 140 ms	 3400 KB */
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
bool V[100000];
int S[100000];
vector<int> Q[100000];
int n, k, p, ptr;
bool judge(){
	int odd = 0;
	for (int i = 0; i < n; i++)
		if (S[i] % 2 == 1)
			odd++;

	if (odd < k - p)
		return false;
	if ((odd - (k - p)) % 2 == 1)
		return false;

	ptr = 0;
	for (int i = 0; i < n && ptr < k - p; i++)
		if (S[i] % 2 == 1)
			Q[ptr++].push_back(S[i]), V[i] = true;

	for (int i = 0, count = 0; i < n && ptr < k; i++){
		if (!V[i] && S[i] % 2 == 1)
			Q[ptr].push_back(S[i]), count++, V[i] = true;
		if (count >= 2)
			ptr++, count = 0;
	}
	for (int i = 0; i < n && ptr < k; i++)
		if (!V[i])
			Q[ptr++].push_back(S[i]), V[i] = true;

	for (int i = 0; i < n; i++)
		if (!V[i])
			Q[ptr - 1].push_back(S[i]), V[i] = true;
	if (ptr == k)
		return true;
	else
		return false;
}
int main(){
	while (scanf("%d%d%d", &n, &k, &p) == 3){
		memset(V, false, sizeof(V));
		for (int i = 0; i < n; i++)
			Q[i].clear();
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);

		if (!judge())
			printf("NO\n");
		else{
			printf("YES\n");

			for (int i = 0; i < ptr; i++){
				printf("%d", Q[i].size());
				for (int j = 0; j < Q[i].size(); j++)
					printf(" %d", Q[i][j]);
				putchar('\n');
			}
		}
	}
	return 0;
}
/*

C. Devu and Partitioning of the Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Devu being a small kid, likes to play a lot, but he only likes to play with arrays. While playing he came up with an interesting question which he could not solve, can you please solve it for him?

Given an array consisting of distinct integers. Is it possible to partition the whole array into k disjoint non-empty parts such that p of the parts have even sum (each of them must have even sum) and remaining k - p have odd sum? (note that parts need not to be continuous).

If it is possible to partition the array, also give any possible way of valid partitioning.

Input
The first line will contain three space separated integers n, k, p (1???k???n???105; 0???p???k). The next line will contain n space-separated distinct integers representing the content of array a: a1,?a2,?...,?an (1???ai???109).

Output
In the first line print "YES" (without the quotes) if it is possible to partition the array in the required way. Otherwise print "NO" (without the quotes).

If the required partition exists, print k lines after the first line. The ith of them should contain the content of the ith part. Print the content of the part in the line in the following way: firstly print the number of elements of the part, then print all the elements of the part in arbitrary order. There must be exactly p parts with even sum, each of the remaining k - p parts must have odd sum.

As there can be multiple partitions, you are allowed to print any valid partition.

Sample test(s)
input
5 5 3
2 6 10 5 9
output
YES
1 9
1 5
1 10
1 6
1 2
input
5 5 3
7 14 2 9 5
output
NO
input
5 3 1
1 2 3 7 5
output
YES
3 5 1 3
1 7
1 2

*/