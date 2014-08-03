/* 5448903	 Dec 16, 2013 12:01:18 PM	Shark	 363D - Renting Bikes	 GNU C++	Accepted	 46 ms	 1200 KB */
#include <cstdio>
#include <algorithm>
using namespace std;
int N[100001];
long long int M[100001];
int n, m;
long long int d;
bool judge(int end){
	long long int cost = 0;
	for (int i = n, j = end; j >= 1; j--, i--){
		if (M[j] > N[i])
			cost += M[j] - N[i];
	}
	if (cost <= d)
		return true;
	else
		return false;
}
int main(){
	while (scanf("%d%d%lld", &n, &m, &d) == 3){
		for (int i = 1; i <= n; i++)
			scanf("%d", &N[i]);
		for (int i = 1; i <= m; i++)
			scanf("%lld", &M[i]);
		sort(N + 1, N + n + 1);
		sort(M + 1, M + m + 1);
		int L, R;
		L = 0, R = (m>n ? n : m);
		while (R >= L){
			int M = (L + R) / 2;
			if (judge(M))
				L = M + 1;
			else
				R = M - 1;
		}
		long long int cost = 0, sum = 0, ans;
		for (int i = L - 1, j = n; i >= 1; i--, j--){
			if (M[i] <= N[j])
				sum += M[i];
			if (M[i] > N[j]){
				sum += N[j];
				cost += M[i] - N[j];
			}
		}
		if (sum - d + cost >= 0)
			ans = sum - d + cost;
		else
			ans = 0;
		printf("%d %lld\n", L - 1, ans);
	}
	return 0;
}
/*

D. Renting Bikes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A group of n schoolboys decided to ride bikes. As nobody of them has a bike, the boys need to rent them.

The renting site offered them m bikes. The renting price is different for different bikes, renting the j-th bike costs pj rubles.

In total, the boys' shared budget is a rubles. Besides, each of them has his own personal money, the i-th boy has bi personal rubles. The shared budget can be spent on any schoolchildren arbitrarily, but each boy's personal money can be spent on renting only this boy's bike.

Each boy can rent at most one bike, one cannot give his bike to somebody else.

What maximum number of schoolboys will be able to ride bikes? What minimum sum of personal money will they have to spend in total to let as many schoolchildren ride bikes as possible?

Input
The first line of the input contains three integers n, m and a (1 ≤ n, m ≤ 105; 0 ≤ a ≤ 109). The second line contains the sequence of integers b1, b2, ..., bn (1 ≤ bi ≤ 104), where bi is the amount of the i-th boy's personal money. The third line contains the sequence of integers p1, p2, ..., pm (1 ≤ pj ≤ 109), where pj is the price for renting the j-th bike.

Output
Print two integers r and s, where r is the maximum number of schoolboys that can rent a bike and s is the minimum total personal money needed to rent r bikes. If the schoolchildren cannot rent any bikes, then r = s = 0.

Sample test(s)
input
2 2 10
5 5
7 6
output
2 3
input
4 5 2
8 1 1 2
6 3 7 5 2
output
3 8
Note
In the first sample both schoolchildren can rent a bike. For instance, they can split the shared budget in half (5 rubles each). In this case one of them will have to pay 1 ruble from the personal money and the other one will have to pay 2 rubles from the personal money. In total, they spend 3 rubles of their personal money. This way of distribution of money minimizes the amount of spent personal money.

*/