/* 10726032	2015-04-15 06:45:15	Shark	535D - Tavas and Malekas	GNU C++	Accepted	186 ms	9900 KB */
#include<bits\stdc++.h>
#define MOD 1000000007
using namespace std;
int n, m, x[1000005];
string s;
int f[1000005];
long long power(int a, int b){
	if (b == 0)	return 1;
	if (b % 2 == 0){
		long long tmp = power(a, b / 2);
		return tmp * tmp % MOD;
	}
	else
		return a * power(a, b - 1) % MOD;

}
long long solve(){
	int empty = 0, R = 0, len = s.length();
	for (int i = 1; i < m; i++){
		int delta = x[i] - x[i - 1], j = f[len - 1];
		if (delta >= len)	continue;
		while (j >= 0 && delta != len - j - 1)	j = f[j];
		if (j < 0)	return 0;
	}
	for (int i = 0; i < m; i++){
		if (x[i] >= R)
			empty += x[i] - R;
		R = x[i] + len;
	}
	if (n > R)
		empty += n - R;
	return power(26, empty);
}
int main(){
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 0; i < m; i++)
		scanf("%d", x + i), x[i]--;
	memset(f, 0, sizeof(f));
	for (int i = 1, j = f[0] = -1; i < s.length(); i++){
		while (j >= 0 && s[j + 1] != s[i])
			j = f[j];
		if (s[j + 1] == s[i])	j++;
		f[i] = j;
	}
	printf("%lld\n", solve());
	return 0;
}
/*

D. Tavas and Malekas
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Tavas is a strange creature. Usually "zzz" comes out of people's mouth while sleeping, but string s of length n comes out from Tavas' mouth instead.


Today Tavas fell asleep in Malekas' place. While he was sleeping, Malekas did a little process on s. Malekas has a favorite string p. He determined all positions x1 < x2 < ... < xk where p matches s. More formally, for each xi (1 ≤ i ≤ k) he condition sxisxi + 1... sxi + |p| - 1 = p is fullfilled.

Then Malekas wrote down one of subsequences of x1, x2, ... xk (possibly, he didn't write anything) on a piece of paper. Here a sequence b is a subsequence of sequence a if and only if we can turn a into b by removing some of its elements (maybe no one of them or all).

After Tavas woke up, Malekas told him everything. He couldn't remember string s, but he knew that both p and s only contains lowercase English letters and also he had the subsequence he had written on that piece of paper.

Tavas wonders, what is the number of possible values of s? He asked SaDDas, but he wasn't smart enough to solve this. So, Tavas asked you to calculate this number for him.

Answer can be very large, so Tavas wants you to print the answer modulo 109 + 7.

Input
The first line contains two integers n and m, the length of s and the length of the subsequence Malekas wrote down (1 ≤ n ≤ 106 and 0 ≤ m ≤ n - |p| + 1).

The second line contains string p (1 ≤ |p| ≤ n).

The next line contains m space separated integers y1, y2, ..., ym, Malekas' subsequence (1 ≤ y1 < y2 < ... < ym ≤ n - |p| + 1).

Output
In a single line print the answer modulo 1000 000 007.

Sample test(s)
input
6 2
ioi
1 3
output
26
input
5 2
ioi
1 2
output
0
Note
In the first sample test all strings of form "ioioi?" where the question mark replaces arbitrary English letter satisfy.

Here |x| denotes the length of string x.

Please note that it's possible that there is no such string (answer is 0).

*/