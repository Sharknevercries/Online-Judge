/* 5590412	 Dec 31, 2013 11:59:31 AM	Shark	 379C - New Year Ratings Change	 GNU C++	Happy New Year!	218 ms	2300 KB */
#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
	int value;
	int index;
};
struct data M[300000];
bool cmp1(struct data A, struct data B){
	return A.value<B.value;
}
bool cmp2(struct data A, struct data B){
	return A.index<B.index;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int cur = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &M[i].value);
			M[i].index = i;
		}
		sort(M, M + n, cmp1);
		for (int i = 0; i < n; i++){
			if (cur <= M[i].value)
				cur = M[i].value + 1;
			else
				M[i].value = cur, cur++;
		}
		sort(M, M + n, cmp2);
		printf("%d", M[0].value);
		for (int i = 1; i < n; i++)
			printf(" %d", M[i].value);
		putchar('\n');
	}
	return 0;
}
/*

C. New Year Ratings Change
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One very well-known internet resource site (let's call it X) has come up with a New Year adventure. Specifically, they decided to give ratings to all visitors.

There are n users on the site, for each user we know the rating value he wants to get as a New Year Present. We know that user i wants to get at least ai rating units as a present.

The X site is administered by very creative and thrifty people. On the one hand, they want to give distinct ratings and on the other hand, the total sum of the ratings in the present must be as small as possible.

Help site X cope with the challenging task of rating distribution. Find the optimal distribution.

Input
The first line contains integer n (1 ≤ n ≤ 3·105) — the number of users on the site. The next line contains integer sequence a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print a sequence of integers b1, b2, ..., bn. Number bi means that user i gets bi of rating as a present. The printed sequence must meet the problem conditions.

If there are multiple optimal solutions, print any of them.

Sample test(s)
input
3
5 1 1
output
5 1 2
input
1
1000000000
output
1000000000

*/