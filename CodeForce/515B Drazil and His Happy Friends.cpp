/* 9902840	2015-02-17 22:02:37	Shark	515B - Drazil and His Happy Friends	GNU C++	Accepted	31 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int n, m;
bool A[105] = { false }, B[105] = { false };
int gcd(int a, int b){
	int r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
bool check(){
	for (int i = 0; i < n; i++)
		if (!A[i])
			return false;
	for (int i = 0; i < m; i++)
		if (!B[i])
			return false;
	return true;
}
int main(){
	scanf("%d%d", &n, &m);
	int b, g;
	scanf("%d", &b);
	for (int i = 0; i < b; i++){
		int p;
		scanf("%d", &p);
		A[p] = true;
	}
	scanf("%d", &g);
	for (int i = 0; i < g; i++){
		int p;
		scanf("%d", &p);
		B[p] = true;
	}
	int time = n*m / gcd(n, m);
	while (true){
		bool tag = false;
		for (int i = 0; i < time; i++){
			int p = i%n, q = i%m;
			bool res = A[p] | B[q];
			if (A[p] != res || B[q] != res)
				tag = true;
			A[p] = B[q] = res;
		}
		if (!tag)
			break;
	}
	puts(check() ? "Yes" : "No");
	return 0;
}
/*

B. Drazil and His Happy Friends
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Drazil has many friends. Some of them are happy and some of them are unhappy. Drazil wants to make all his friends become happy. So he invented the following plan.

There are n boys and m girls among his friends. Let's number them from 0 to n - 1 and 0 to m - 1 separately. In i-th day, Drazil invites -th boy and -th girl to have dinner together (as Drazil is programmer, i starts from 0). If one of those two people is happy, the other one will also become happy. Otherwise, those two people remain in their states. Once a person becomes happy (or if he/she was happy originally), he stays happy forever.

Drazil wants to know whether he can use this plan to make all his friends become happy at some moment.

Input
The first line contains two integer n and m (1 ≤ n, m ≤ 100).

The second line contains integer b (0 ≤ b ≤ n), denoting the number of happy boys among friends of Drazil, and then follow b distinct integers x1, x2, ..., xb (0 ≤ xi < n), denoting the list of indices of happy boys.

The third line conatins integer g (0 ≤ g ≤ m), denoting the number of happy girls among friends of Drazil, and then follow g distinct integers y1, y2, ... , yg (0 ≤ yj < m), denoting the list of indices of happy girls.

It is guaranteed that there is at least one person that is unhappy among his friends.

Output
If Drazil can make all his friends become happy by this plan, print "Yes". Otherwise, print "No".

Sample test(s)
input
2 3
0
1 0
output
Yes
input
2 4
1 0
1 2
output
No
input
2 3
1 0
1 1
output
Yes
Note
By  we define the remainder of integer division of i by k.

In first sample case:

On the 0-th day, Drazil invites 0-th boy and 0-th girl. Because 0-th girl is happy at the beginning, 0-th boy become happy at this day.
On the 1-st day, Drazil invites 1-st boy and 1-st girl. They are both unhappy, so nothing changes at this day.
On the 2-nd day, Drazil invites 0-th boy and 2-nd girl. Because 0-th boy is already happy he makes 2-nd girl become happy at this day.
On the 3-rd day, Drazil invites 1-st boy and 0-th girl. 0-th girl is happy, so she makes 1-st boy happy.
On the 4-th day, Drazil invites 0-th boy and 1-st girl. 0-th boy is happy, so he makes the 1-st girl happy. So, all friends become happy at this moment.

*/