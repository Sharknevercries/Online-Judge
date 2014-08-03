/* 6807622	 2014-06-04 20:52:24	Shark	 B - Devu, the Dumb Guy	 GNU C++	Accepted	 46 ms	 400 KB */
#include<cstdio>
#include<algorithm>
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int S[100000];
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		std::sort(S, S + n);
		long long int ans = 0;
		for (int i = 0; i < n; i++){
			ans += (long long int)S[i] * (m--);
			if (m == 0) m = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

B. Devu, the Dumb Guy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Devu is a dumb guy, his learning curve is very slow. You are supposed to teach him n subjects, the ith subject has ci chapters. When you teach him, you are supposed to teach all the chapters of a subject continuously.

Let us say that his initial per chapter learning power of a subject is x hours. In other words he can learn a chapter of a particular subject in x hours.

Well Devu is not complete dumb, there is a good thing about him too. If you teach him a subject, then time required to teach any chapter of the next subject will require exactly 1 hour less than previously required (see the examples to understand it more clearly). Note that his per chapter learning power can not be less than 1 hour.

You can teach him the n subjects in any possible order. Find out minimum amount of time (in hours) Devu will take to understand all the subjects and you will be free to do some enjoying task rather than teaching a dumb guy.

Please be careful that answer might not fit in 32 bit data type.

Input
The first line will contain two space separated integers n, x (1 ≤ n, x ≤ 105). The next line will contain n space separated integers: c1, c2, ..., cn (1 ≤ ci ≤ 105).

Output
Output a single integer representing the answer to the problem.

Sample test(s)
input
2 3
4 1
output
11
input
4 2
5 1 2 1
output
10
input
3 3
1 1 1
output
6
Note
Look at the first example. Consider the order of subjects: 1, 2. When you teach Devu the first subject, it will take him 3 hours per chapter, so it will take 12 hours to teach first subject. After teaching first subject, his per chapter learning time will be 2 hours. Now teaching him second subject will take 2 × 1 = 2 hours. Hence you will need to spend 12 + 2 = 14 hours.

Consider the order of subjects: 2, 1. When you teach Devu the second subject, then it will take him 3 hours per chapter, so it will take 3 × 1 = 3 hours to teach the second subject. After teaching the second subject, his per chapter learning time will be 2 hours. Now teaching him the first subject will take 2 × 4 = 8 hours. Hence you will need to spend 11 hours.

So overall, minimum of both the cases is 11 hours.

Look at the third example. The order in this example doesn't matter. When you teach Devu the first subject, it will take him 3 hours per chapter. When you teach Devu the second subject, it will take him 2 hours per chapter. When you teach Devu the third subject, it will take him 1 hours per chapter. In total it takes 6 hours.

*/