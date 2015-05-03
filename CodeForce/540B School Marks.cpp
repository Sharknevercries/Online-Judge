/* 10950742	2015-04-30 21:08:04	* Shark	540B - School Marks	GNU C++	Accepted	31 ms	2000 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	int n, k, p, x, y, a[1005];
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	for (int i = 0; i < k; i++)
		scanf("%d", a + i);
	sort(a, a + k);
	int L = n / 2, R = n / 2 + 1, remain = x;
	for (int i = 0; i < k; i++){
		remain -= a[i];
		if (a[i] >= y)
			R--;
		else
			L--;
	}
	if (R < 0) L += R, R = 0;
	if (remain >= L * 1 + R * y && L >= 0){
		for (int i = 0; i < L; i++)
			printf("1 ");
		for (int i = 0; i < R; i++)
			printf("%d ", y);
	}
	else
		printf("-1\n");
	return 0;
}
/*

B. School Marks
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Vova studies programming in an elite school. Vova and his classmates are supposed to write n progress tests, for each test they will get a mark from 1 to p. Vova is very smart and he can write every test for any mark, but he doesn't want to stand out from the crowd too much. If the sum of his marks for all tests exceeds value x, then his classmates notice how smart he is and start distracting him asking to let them copy his homework. And if the median of his marks will be lower than y points (the definition of a median is given in the notes), then his mom will decide that he gets too many bad marks and forbid him to play computer games.

Vova has already wrote k tests and got marks a1, ..., ak. He doesn't want to get into the first or the second situation described above and now he needs to determine which marks he needs to get for the remaining tests. Help him do that.

Input
The first line contains 5 space-separated integers: n, k, p, x and y (1 ≤ n ≤ 999, n is odd, 0 ≤ k < n, 1 ≤ p ≤ 1000, n ≤ x ≤ n·p, 1 ≤ y ≤ p). Here n is the number of tests that Vova is planned to write, k is the number of tests he has already written, p is the maximum possible mark for a test, x is the maximum total number of points so that the classmates don't yet disturb Vova, y is the minimum median point so that mom still lets him play computer games.

The second line contains k space-separated integers: a1, ..., ak (1 ≤ ai ≤ p) — the marks that Vova got for the tests he has already written.

Output
If Vova cannot achieve the desired result, print "-1".

Otherwise, print n - k space-separated integers — the marks that Vova should get for the remaining tests. If there are multiple possible solutions, print any of them.

Sample test(s)
input
5 3 5 18 4
3 5 4
output
4 1
input
5 3 5 16 4
5 5 5
output
-1
Note
The median of sequence a1, ..., an where n is odd (in this problem n is always odd) is the element staying on (n + 1) / 2 position in the sorted list of ai.

In the first sample the sum of marks equals 3 + 5 + 4 + 4 + 1 = 17, what doesn't exceed 18, that means that Vova won't be disturbed by his classmates. And the median point of the sequence {1, 3, 4, 4, 5} equals to 4, that isn't less than 4, so his mom lets him play computer games.

Please note that you do not have to maximize the sum of marks or the median mark. Any of the answers: "4 2", "2 4", "5 1", "1 5", "4 1", "1 4" for the first test is correct.

In the second sample Vova got three '5' marks, so even if he gets two '1' marks, the sum of marks will be 17, that is more than the required value of 16. So, the answer to this test is "-1".

*/