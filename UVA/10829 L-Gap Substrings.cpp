/* 15098115	10829	L-Gap Substrings	Accepted	C++	0.492	2015-03-07 11:32:16 */
#include<bits\stdc++.h>
#define N 100005
using namespace std;
char s[N], str[N];
int sa[N], height[N];
int grade[N], sa2[N];
int c[N];
int rmq[N][20];
int n, mid, g;
void buildSA(int m){
	// suffix array
	for (int i = 0; i < m; i++)	c[i] = 0;
	for (int i = 0; i < n; i++)	c[grade[i] = s[i]]++;
	for (int i = 1; i < m; i++)	c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)	sa[--c[s[i]]] = i;
	for (int i = 1; i < n; i *= 2){
		int r = 0;
		for (int j = n - i; j < n; j++)	sa2[r++] = j;
		for (int j = 0; j < n; j++)
			if (sa[j] >= i)
				sa2[r++] = sa[j] - i;
		for (int j = 0; j < m; j++)	c[j] = 0;
		for (int j = 0; j < n; j++)	c[grade[sa2[j]]]++;
		for (int j = 1; j < m; j++)	c[j] += c[j - 1];
		for (int j = n - 1; j >= 0; j--)	sa[--c[grade[sa2[j]]]] = sa2[j];
		int *newgrade = sa2;
		newgrade[sa[0]] = r = 0;
		for (int j = 1; j < n; j++){
			if (!(grade[sa[j - 1]] == grade[sa[j]] && grade[sa[j - 1] + i] == grade[sa[j] + i]))
				r++;
			newgrade[sa[j]] = r;
		}
		swap(grade, sa2);
		if (r == n - 1)	break;
		m = r + 1;
	}
	// height
	for (int i = 0; i < n; i++)	grade[sa[i]] = i;
	for (int i = 0, k = 0; i < n - 1; i++){
		if (k) k--;
		int j = sa[grade[i] - 1];
		while (s[i + k] == s[j + k])k++;
		height[grade[i]] = k;
	}
}
int queryRMQ(int L, int R){
	if (L > R) swap(L, R);
	L++;
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1)	k++;
	return min(rmq[L][k], rmq[R - (1 << k) + 1][k]);
}
void solve(){
	long long int ans = 0;
	for (int d = 1; d <= mid / 2; d++){
		for (int i = 0; i<mid; i += d){
			int j = i + d + g, sum = 0;
			if (j < mid)
				sum += min(queryRMQ(grade[i], grade[j]), d);
			if (i - 1 >= 0)
				sum += min(queryRMQ(grade[n - i - 1], grade[n - j - 1]), d - 1);
			ans += max(0, sum - d + 1);
		}
	}
	printf("%lld\n", ans);
}
void buildRMQ(){
	for (int i = 0; i < n; i++)
		rmq[i][0] = height[i];
	for (int d = 1; (1 << d) <= n; d++)
		for (int i = 0; i + (1 << d) - 1 < n; i++)
			rmq[i][d] = min(rmq[i][d - 1], rmq[i + (1 << (d - 1))][d - 1]);
}
int main(){
	int t, ca = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%s", &g, s);
		n = strlen(s);
		s[n] = '$', mid = n;
		for (int i = 0; i < n; i++)
			s[n + i + 1] = s[n - i - 1];
		mid = n;
		s[n * 2 + 1] = 0;
		n = (n + 1) * 2;
		buildSA(256);
		buildRMQ();
		printf("Case %d: ", ca++);
		solve();
	}
	return 0;
}
/*
1
1 aaa
Problem J
L-Gap Substrings
Input: Standard Input
Output: Standard Output
If a string is in the form UVU, where U is not empty, and V has exactly L characters, we say UVU is an L-Gap string. For example, abcbabc is a 1-Gap string. xyxyxyxyxy is both a 2-Gap string and also a 6-Gap string, but not a 10-Gap string (because U is non-empty).

Given a string s, and a positive integer g, you are to find the number of g-Gap substrings in s. s contains lower-case letters only, and has at most 50,000 characters.



Input
The first line contains a single integer t(1<=t<=10), the number of test cases. Each of the t followings contains an integer g(1<=g<=10) followed by a string s.

Output
For each test case, print the case number and the number of g-Gap substrings. Look at the output for sample input for details.

Sample Input                               Output for Sample Input
2
1 bbaabaaaaa
5 abxxxxxab

Case 1: 7
Case 2: 1

Problem setter: Rujia Liu
Special Thanks: Shahriar Manzoor (Diagram)

*/