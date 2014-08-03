/* 5408070	 Dec 11, 2013 11:47:13 AM	Shark	 367C - Sereja and the Arrangement of Numbers	 GNU C++	Accepted	 46 ms	 15600 KB */
#include<cstdio>
#include<algorithm>
struct data{
	int ID, price;
};
bool cmp(struct data A, struct data B){
	return A.price > B.price;
}
struct data M[2000000];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i < m; i++)
			scanf("%d%d", &M[i].ID, &M[i].price);
		std::sort(M, M + m, cmp);
		int count = 1;
		while (true){
			long long size;
			if (count == 1 || count == 2)
				size = count;
			else if (count % 2 == 0) // F(n) = F(n-1) + 2 + floor((n-3)/2)*3 + 2 , n=4, 6, 8, ...
				size = (long long)(count - 1)*(count - 2) / 2 + 5 + ((count - 3) / 2) * 3;
			else                     // F(n) = n*(n-1)/2 + 1 , n=3, 5, 7, ...
				size = (long long)count*(count - 1) / 2 + 1;
			if (size <= n)
				count++;
			else
				break;
		}
		count--;
		long long int ans = 0;
		for (int i = 0; i < count&&i < m; i++)
			ans += M[i].price;
		printf("%lld\n", ans);
	}
	return 0;
}
/*

C. Sereja and the Arrangement of Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's call an array consisting of n integer numbers a1, a2, ..., an, beautiful if it has the following property:

consider all pairs of numbers x, y (x ≠ y), such that number x occurs in the array a and number y occurs in the array a;
for each pair x, y must exist some position j (1 ≤ j < n), such that at least one of the two conditions are met, either aj = x, aj + 1 = y, or aj = y, aj + 1 = x.
Sereja wants to build a beautiful array a, consisting of n integers. But not everything is so easy, Sereja's friend Dima has m coupons, each contains two integers qi, wi. Coupon i costs wi and allows you to use as many numbers qi as you want when constructing the array a. Values qi are distinct. Sereja has no coupons, so Dima and Sereja have made the following deal. Dima builds some beautiful array a of n elements. After that he takes wi rubles from Sereja for each qi, which occurs in the array a. Sereja believed his friend and agreed to the contract, and now he is wondering, what is the maximum amount of money he can pay.

Help Sereja, find the maximum amount of money he can pay to Dima.

Input
The first line contains two integers n and m (1 ≤ n ≤ 2·106, 1 ≤ m ≤ 105). Next m lines contain pairs of integers. The i-th line contains numbers qi, wi (1 ≤ qi, wi ≤ 105).

It is guaranteed that all qi are distinct.

Output
In a single line print maximum amount of money (in rubles) Sereja can pay.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Sample test(s)
input
5 2
1 2
2 3
output
5
input
100 3
1 2
2 1
3 1
output
4
input
1 2
1 1
2 100
output
100
Note
In the first sample Sereja can pay 5 rubles, for example, if Dima constructs the following array: [1, 2, 1, 2, 2]. There are another optimal arrays for this test.

In the third sample Sereja can pay 100 rubles, if Dima constructs the following array: [2].

*/