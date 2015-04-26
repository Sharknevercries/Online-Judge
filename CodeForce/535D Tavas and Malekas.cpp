/* 10716074	2015-04-14 20:46:13	Shark	536A - Tavas and Karafs	GNU C++	Accepted	109 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
long long A, B, n;
long long l, m, t;
bool solve(long long target){
	if (A + B*(l - 1) > t)
		return false;
	if (A + B*(target - 1) > t)
		return false;
	if (target - l + 1 <= m)
		return A + B*(target - 1) <= t;
	else
		return (2 * A + (target + l - 2) * B) * (target - l + 1) / 2 <= t*m;
}
int main(){
	scanf("%lld%lld%lld", &A, &B, &n);
	for (int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &l, &t, &m);
		long long L = l, R = 1e7;
		while (L <= R){
			long long mid = (L + R) / 2;
			if (solve(mid))
				L = mid + 1;
			else
				R = mid - 1;
		}
		if (R < l)
			puts("-1");
		else
			printf("%lld\n", L - 1);
	}
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