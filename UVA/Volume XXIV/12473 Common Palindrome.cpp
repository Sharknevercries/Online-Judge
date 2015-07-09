/* 15591819	12473	Common Palindrome	Accepted	C++	3.388	2015-06-07 09:20:32 */
#include<bits\stdc++.h>
using namespace std;
string p, q;
int DP[65][65][65][65];
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		cin >> p >> q;
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < p.size(); i++)
			for (int j = 0; j < q.size(); j++)
				if (p[i] == q[j])
					DP[i][i][j][j] = 1;
		for (int a = 0; a < p.size(); a++){
			for (int b = 0; b < q.size(); b++){
				for (int i = 0; i + a < p.size(); i++){
					for (int k = 0; k + b < q.size(); k++){
						int j = i + a;
						int u = k + b;
						if (p[i] == p[j] && p[i] == q[k] && p[i] == q[u] && a && b)
							DP[i][j][k][u] = 2 + DP[i + 1][j - 1][k + 1][u - 1];
						if (i + 1 <= j)	DP[i][j][k][u] = max(DP[i][j][k][u], DP[i + 1][j][k][u]);
						if (j - 1 >= i)	DP[i][j][k][u] = max(DP[i][j][k][u], DP[i][j - 1][k][u]);
						if (k + 1 <= u)	DP[i][j][k][u] = max(DP[i][j][k][u], DP[i][j][k + 1][u]);
						if (u - 1 >= k)	DP[i][j][k][u] = max(DP[i][j][k][u], DP[i][j][k][u - 1]);
					}
				}
			}
		}

						
		printf("Case %d: %d\n", c++, DP[0][p.size() - 1][0][q.size() - 1]);
	}
	return 0;
}
/*

A palindrome is a string that reads the same from the left as it does from the right. Given two strings
A and B, you need to find the length of longest palindrome which is a subsequence of both A and B.
A subsequence is a sequence obtained by deleting zero or more characters from a string.
For example, say, A = “cfcfaafc”, B = “efagfc”. Then the longest palindrome which is a
subsequence of both A and B is “faf”. So the answer is 3.
Input
First line of the input contains a positive integer T (T ≤ 100). Each of the following T cases consists
of 2 lines. These 2 lines contain the strings A and B, respectively. Length of A and B will not be more
than 60. All these strings contain only lowercase letters (‘a’ -‘z’). No empty strings will appear in the
input.
Output
For each case, print a line of the form ‘Case < x >: < y >’, where x is the case number and y is the
length of the longest common palindromic subsequence.
Sample Input
3
cfcfaafc
efagfc
afbcdfca
bcadfcgyfka
palin
drome
Sample Output
Case 1: 3
Case 2: 5
Case 3: 0

*/