/* 6763649	 Jun 1, 2014 2:19:07 PM	Shark	 435A - Queue on Bus Stop	 GNU C++	Accepted	 15 ms	 0 KB */
#include<cstdio>
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int S[100], ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		for (int i = 0, cap = 0; i < n; cap = 0){
			while (i < n && cap + S[i] <= m)
				cap += S[i++];
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

A. Queue on Bus Stop
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
It's that time of the year when the Russians flood their countryside summer cottages (dachas) and the bus stop has a lot of people. People rarely go to the dacha on their own, it's usually a group, so the people stand in queue by groups.

The bus stop queue has n groups of people. The i-th group from the beginning has ai people. Every 30 minutes an empty bus arrives at the bus stop, it can carry at most m people. Naturally, the people from the first group enter the bus first. Then go the people from the second group and so on. Note that the order of groups in the queue never changes. Moreover, if some group cannot fit all of its members into the current bus, it waits for the next bus together with other groups standing after it in the queue.

Your task is to determine how many buses is needed to transport all n groups to the dacha countryside.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 100). The next line contains n integers: a1, a2, ..., an (1 ≤ ai ≤ m).

Output
Print a single integer — the number of buses that is needed to transport all n groups to the dacha countryside.

Sample test(s)
input
4 3
2 3 2 1
output
3
input
3 4
1 2 1
output
1

*/