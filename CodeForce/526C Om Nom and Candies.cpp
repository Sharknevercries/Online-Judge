/* 10645223	2015-04-10 06:12:19	Shark	C - Om Nom and Candies	GNU C++	Accepted	30 ms	8 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	long long int n, wb, hb, wr, hr;
	long long ans = 0; 
	scanf("%lld%lld%lld%lld%lld", &n, &hr, &hb, &wr, &wb);
	int limit = sqrt((double)n);
	for (int i = 0; i <= limit && n - i * wr > 0; i++)
		ans = max(ans, i * hr + (n - i * wr) / wb * hb);
	for (int i = 0; i <= limit && n - i * wb > 0; i++)
		ans = max(ans, i * hb + (n - i * wb) / wr * hr);
	printf("%lld\n", ans);
	return 0;
}
/*

C. Om Nom and Candies
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A sweet little monster Om Nom loves candies very much. One day he found himself in a rather tricky situation that required him to think a bit in order to enjoy candies the most. Would you succeed with the same task if you were on his place?


One day, when he came to his friend Evan, Om Nom didn't find him at home but he found two bags with candies. The first was full of blue candies and the second bag was full of red candies. Om Nom knows that each red candy weighs Wr grams and each blue candy weighs Wb grams. Eating a single red candy gives Om Nom Hr joy units and eating a single blue candy gives Om Nom Hb joy units.

Candies are the most important thing in the world, but on the other hand overeating is not good. Om Nom knows if he eats more than C grams of candies, he will get sick. Om Nom thinks that it isn't proper to leave candy leftovers, so he can only eat a whole candy. Om Nom is a great mathematician and he quickly determined how many candies of what type he should eat in order to get the maximum number of joy units. Can you repeat his achievement? You can assume that each bag contains more candies that Om Nom can eat.

Input
The single line contains five integers C, Hr, Hb, Wr, Wb (1 ≤ C, Hr, Hb, Wr, Wb ≤ 109).

Output
Print a single integer — the maximum number of joy units that Om Nom can get.

Sample test(s)
input
10 3 5 2 3
output
16
Note
In the sample test Om Nom can eat two candies of each type and thus get 16 joy units.

*/