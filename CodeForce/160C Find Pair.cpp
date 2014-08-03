/* 5206614	 Nov 24, 2013 11:40:52 AM	Shark	 160C - Find Pair	 GNU C++	Accepted	218 ms	5700 KB */
#include<stdio.h>
#include<algorithm>
#include<map>
struct data{
	long long int count;
	int value;
};
bool cmp(struct data A, struct data B){
	return A.value < B.value;
}
int main(){
	long long int n, k;
	while (scanf("%lld%lld", &n, &k) == 2){
		std::map<long long int, int> T;
		struct data M[100000];
		int ptr = 0;
		long long int a, b, sum, left;
		for (int i = 0; i < n; i++){
			long long int tmp;
			scanf("%lld", &tmp);
			T[tmp]++;
		}
		for (std::map<long long int, int>::iterator iter = T.begin(); iter != T.end(); iter++){
			M[ptr].value = iter->first;
			M[ptr].count = iter->second;
			ptr++;
		}
		std::sort(M, M + ptr, cmp);
		for (a = sum = 0; sum < k; sum += M[a++].count*n);
		sum -= M[--a].count*n;
		for (b = left = 0; left < k - sum; left += M[a].count*M[b++].count);
		b--;
		printf("%d %d\n", M[a].value, M[b].value);
	}
	return 0;
}
/*

C. Find Pair
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got another problem dealing with arrays. Let's consider an arbitrary sequence containing n (not necessarily different) integers a1, a2, ..., an. We are interested in all possible pairs of numbers (ai, aj), (1 ≤ i, j ≤ n). In other words, let's consider all n2 pairs of numbers, picked from the given array.

For example, in sequence a = {3, 1, 5} are 9 pairs of numbers: (3, 3), (3, 1), (3, 5), (1, 3), (1, 1), (1, 5), (5, 3), (5, 1), (5, 5).

Let's sort all resulting pairs lexicographically by non-decreasing. Let us remind you that pair (p1, q1) is lexicographically less than pair (p2, q2) only if either p1 < p2, or p1 = p2 and q1 < q2.

Then the sequence, mentioned above, will be sorted like that: (1, 1), (1, 3), (1, 5), (3, 1), (3, 3), (3, 5), (5, 1), (5, 3), (5, 5)

Let's number all the pair in the sorted list from 1 to n2. Your task is formulated like this: you should find the k-th pair in the ordered list of all possible pairs of the array you've been given.

Input
The first line contains two integers n and k (1 ≤ n ≤ 105, 1 ≤ k ≤ n2). The second line contains the array containing n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109). The numbers in the array can coincide. All numbers are separated with spaces.

Please do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use cin, cout, streams or the %I64d specificator instead.

Output
In the single line print two numbers — the sought k-th pair.

Sample test(s)
input
2 4
2 1
output
2 2
input
3 2
3 1 5
output
1 3
Note
In the first sample the sorted sequence for the given array looks as: (1, 1), (1, 2), (2, 1), (2, 2). The 4-th of them is pair (2, 2).

The sorted sequence for the array from the second sample is given in the statement. The 2-nd pair there is (1, 3).

*/