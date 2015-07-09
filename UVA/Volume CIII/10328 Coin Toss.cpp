/* 15250120	10328	Coin Toss	Accepted	C++	2.279	2015-03-31 16:48:02 */
#include<bits\stdc++.h>
using namespace std;
char DP[105][105][105][105];
inline void add(char str1[], char str2[], char res[]){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int reslen = max(len1, len2) + 1;
	int i, j, k, carry, tmp;
	for (int i = 0; i < reslen; i++)
		res[i] = '0';
	res[reslen] = '\0';
	for (i = len1 - 1, j = len2 - 1, k = reslen - 1, carry = 0; i >= 0 || j >= 0;){
		tmp = carry;
		if (i >= 0)	tmp += str1[i--] - '0';
		if (j >= 0)	tmp += str2[j--] - '0';
		carry = tmp / 10;
		tmp %= 10;
		res[k--] += tmp;
	}
	res[k] += carry;
	if (res[0] == '0')
		for (int i = 0; i < reslen; i++)
			res[i] = res[i + 1];
}
int main(){
	char sw[105];
	for (int i = 0; i <= 103; i++)
		for (int j = 0; j <= 103; j++)
			for (int k = 0; k <= 103; k++)
				DP[i][j][k][0] = '0', DP[i][j][k][1] = '\0';
	DP[0][0][0][0] = '1';
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			for (int k = 0; k <= 100; k++){
				if (k >= j){
					add(DP[i + 1][k + 1][k + 1], DP[i][j][k], sw);
					memcpy(DP[i + 1][k + 1][k + 1], sw, sizeof(sw));
				}
				else{
					add(DP[i + 1][j][k + 1], DP[i][j][k], sw);
					memcpy(DP[i + 1][j][k + 1], sw, sizeof(sw));
				}
				add(DP[i + 1][j][0], DP[i][j][k], sw);
				memcpy(DP[i + 1][j][0], sw, sizeof(sw));
			}
		}
	}
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		char res[105] = "0";
		for (int i = m; i <= n; i++){
			for (int j = 0; j <= n; j++){
				add(res, DP[n][i][j], sw);
				memcpy(res, sw, sizeof(sw));
			}
		}
		printf("%s\n", res);
	}
	return 0;
}
/*

Toss is an important part of any event. When everything becomes equal toss is the ultimate decider.
Normally a fair coin is used for Toss. A coin has two sides head(H) and tail(T). Superstition may work
in case of choosing head or tail. If anyone becomes winner choosing head he always wants to choose
head. Nobody believes that his winning chance is 50-50. However in this problem we will deal with a
fair coin and n times tossing of such a coin. The result of such a tossing can be represented by a string.
Such as if 3 times tossing is used then there are possible 8 outcomes.
HHH HHT HTH HTT THH THT TTH TTT
As the coin is fair we can consider that the probability of each outcome is also equal. For simplicity
we can consider that if the same thing is repeated 8 times we can expect to get each possible sequence
once.
In the above example we see 1 sequence has 3 consecutive H, 3 sequence has 2 consecutive H and 7
sequence has at least single H. You have to generalize it. Suppose a coin is tossed n times. And the
same process is repeated 2n times. How many sequence you will get which contains a sequence of H of
length at least k.
Input
The input will start with two positive integer, n and k (1 ≤ k ≤ n ≤ 100). Input is terminated by
EOF.
Output
For each test case show the result in a line as specified in the problem statement.
Sample Input
4 1
4 2
4 3
4 4
6 2
Sample Output
15
8
3
1
43

*/