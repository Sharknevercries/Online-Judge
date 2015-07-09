/* 15249572	10042	Smith Numbers	Accepted	C++	0.105	2015-03-31 14:58:20 */
#include<bits\stdc++.h>
using namespace std;
int prime[70000], ptr;
int w[70000];
int split(int s){
	int res = 0;
	for (int i = s; i > 0; i /= 10)
		res += i % 10;
	return res;
}
inline void make_prime(){
	int limit = sqrt(1e9);
	ptr = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (int i = 5, j, gap = 2; i <= limit; i += gap, gap = 6 - gap){
		for (j = 0; j < ptr; j++)
			if (i % prime[j] == 0)
				break;
		if (j >= ptr)
			prime[ptr++] = i;
	}
	for (int i = 0; i < ptr; i++)
		w[i] = split(prime[i]);
}
int main(){
	make_prime();
	int t;
	scanf("%d", &t);
	while (t--){
		int n, ans;
		scanf("%d", &n);
		for (ans = n + 1;; ans++){
			bool flag = false;
			int sum1 = split(ans), sum2 = 0, s = ans;
			for (int i = 0; i < ptr; i++)
				if (ans == prime[i])
					flag = true;
			if (flag)	continue;
			for (int i = 0; i < ptr; i++){
				while (s % prime[i] == 0){
					sum2 += w[i];
					s /= prime[i];
				}
			}
			if (sum2 == 0)	continue;
			if (s > 1)
				sum2 += split(s);
			if (sum1 == sum2)
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

While skimming his phone directory in 1982, Albert Wilansky, a mathematician of Lehigh University,
noticed that the telephone number of his brother-in-law H. Smith had the following peculiar property:
The sum of the digits of that number was equal to the sum of the digits of the prime factors of that
number. Got it? Smith’s telephone number was 493-7775. This number can be written as the product
of its prime factors in the following way:
4937775 = 3 · 5 · 5 · 65837
The sum of all digits of the telephone number is 4 + 9 + 3 + 7 + 7 + 7 + 5 = 42, and the sum of the
digits of its prime factors is equally 3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42. Wilansky was so amazed by his
discovery that he named this type of numbers after his brother-in-law: Smith numbers.
As this observation is also true for every prime number, Wilansky decided later that a (simple and
unsophisticated) prime number is not worth being a Smith number and he excluded them from the
definition.
Wilansky published an article about Smith numbers in the Two Year College Mathematics Journal
and was able to present a whole collection of different Smith numbers: For example, 9985 is a Smith
number and so is 6036. However, Wilansky was not able to give a Smith number which was larger than
the telephone number of his brother-in-law. It is your task to find Smith numbers which are larger
than 4937775.
Input
The input consists of several test cases, the number of which you are given in the first line of the input.
Each test case consists of one line containing a single positive integer smaller than 109
.
Output
For every input value n, you are to compute the smallest Smith number which is larger than n and
print each number on a single line. You can assume that such a number exists.
Sample Input
1
4937774
Sample Output
4937775

*/