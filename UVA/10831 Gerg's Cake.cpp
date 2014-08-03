/* 13807858	10831	Gerg's Cake	Accepted	C++	0.012	2014-06-29 07:39:56 */
/*

c = n^2 = a mod p, according to the description
by fermat's little theorem c^(p-1) = 1 mod p, c and p are relatively prime
(c^2) ^ ((p-1)/2) = 1 mod p => a ^ ((p-1)/2) = 1 mod p

*/
#include<cstdio>
#include<math.h>
bool solve(long long int a, long long int p){
	if (a % p == 0)	return true;
	long long int x, y, z;
	x = 1, y = (p - 1) / 2, z = a;
	while (y > 0){
		if ((y & 1) == 1)
			x = (x * z) % p;
		z *= z, z %= p;
		y >>= 1;
	}
	return x == 1;
}
int main(){
	long long int a, p;
	while (scanf("%lld%lld", &a, &p) == 2){
		if (a == -1 && p == -1)	break;
		printf("%s\n", solve(a, p) ? "Yes" : "No");
	}
	return 0;
}
/*

Problem B
GergÅfs Cake
Input: Standard Input
Output: Standard Output

Gerg is having a party, and he has invited his friends. p of them have arrived already, but a are running late. To occupy his guests, he tried playing some team games with them, but he found that it was impossible to divide the p guests into any number of equal-sized groups of more than one person.
Luckily, he has a backup plan - a cake that he would like to share between his friends. The cake is in the shape of a square, and Gerg insists on cutting it up into equal-sized square pieces. He wants to reserve one slice for each of the a missing friends, and the rest of the slices have to be divided evenly between the p remaining guests. He does not want any cake himself. Can he do it?

Input
The input will consist of several test cases. Each test case will be given as a non-negative integer a and a positive integer p as specified above, on a line. Both a and p will fit into a 32-bit signed integer. The last line will contain "-1 -1" and should not be processed.

Output
For each test case, output "Yes" if the cake can be fairly divided and "No" otherwise.

Sample Input                               Output for Sample Input
1 3
1024 17
2 101
0 1
-1 -1
Yes
Yes
No
Yes
Problem setter: Igor Naverniouk
Special Thanks: Derek Kisman

*/