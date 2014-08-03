/* 5518581	 Dec 25, 2013 3:50:22 PM	Shark	 120C - Winnie-the-Pooh and honey	 GNU C++	Accepted	30 ms	200 KB */
#include<cstdio>
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int ans = 0;
		for (int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			for (int j = 1; j <= 3 && a >= k; j++)
				a -= k;
			ans += a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

C. Winnie-the-Pooh and honey
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
As we all know, Winnie-the-Pooh just adores honey. Ones he and the Piglet found out that the Rabbit has recently gotten hold of an impressive amount of this sweet and healthy snack. As you may guess, Winnie and the Piglet asked to come at the Rabbit's place. Thus, there are n jars of honey lined up in front of Winnie-the-Pooh, jar number i contains ai kilos of honey. Winnie-the-Pooh eats the honey like that: each time he chooses a jar containing most honey. If the jar has less that k kilos of honey or if Winnie-the-Pooh has already eaten from it three times, he gives the jar to Piglet. Otherwise he eats exactly k kilos of honey from the jar and puts it back. Winnie does so until he gives all jars to the Piglet. Count how much honey Piglet will overall get after Winnie satisfies his hunger.

Input
The first line contains two integers n and k (1 ≤ n ≤ 100, 1 ≤ k ≤ 100). The second line contains n integers a1, a2, ..., an, separated by spaces (1 ≤ ai ≤ 100).

Output
Print a single number — how many kilos of honey gets Piglet.

Sample test(s)
input
3 3
15 8 10
output
9

*/