/* 5526112	 Dec 26, 2013 8:55:48 PM	Shark	 327C - Magic Five	 GNU C++	Accepted	62 ms	100 KB */
#include<cstdio>
#include<cstring>
#define MOD 1000000007
long long int power(long long int x, long long int n){
	if (n == 0)
		return 1;
	long long int tmp = power(x, n >> 1);
	tmp = tmp*tmp%MOD;
	if (n % 2 == 1)
		tmp = tmp*x%MOD;
	return tmp;
}
int main(){
	char S[100001];
	int k;
	while (scanf("%s%d", S, &k) == 2){
		long long int len = strlen(S);
		long long int ans = 0, tmp = 0;
		for (int i = len - 1; i >= 0; i--){
			if (S[i] == '0' || S[i] == '5'){
				ans += power(2, i);
				ans %= MOD;
			}
		}
		
		tmp = power(2, k*len) % MOD - 1;
		tmp = tmp*power(power(2, len) - 1, MOD - 2) % MOD; // Fermat's little theorem
		ans = ans*tmp%MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
/*

C. Magic Five
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a long plate s containing n digits. Iahub wants to delete some digits (possibly none, but he is not allowed to delete all the digits) to form his "magic number" on the plate, a number that is divisible by 5. Note that, the resulting number may contain leading zeros.

Now Iahub wants to count the number of ways he can obtain magic number, modulo 1000000007 (109 + 7). Two ways are different, if the set of deleted positions in s differs.

Look at the input part of the statement, s is given in a special form.

Input
In the first line you're given a string a (1 ≤ |a| ≤ 105), containing digits only. In the second line you're given an integer k (1 ≤ k ≤ 109). The plate s is formed by concatenating k copies of a together. That is n = |a|·k.

Output
Print a single integer — the required number of ways modulo 1000000007 (109 + 7).

Sample test(s)
input
1256
1
output
4
input
13990
2
output
528
input
555
2
output
63
Note
In the first case, there are four possible ways to make a number that is divisible by 5: 5, 15, 25 and 125.

In the second case, remember to concatenate the copies of a. The actual plate is 1399013990.

In the third case, except deleting all digits, any choice will do. Therefore there are 26 - 1 = 63 possible ways to delete digits.

*/