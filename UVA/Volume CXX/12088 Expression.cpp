/* 15592644	12088	Expression	Accepted	C++	0.003	2015-06-07 12:16:08 */
#include<bits\stdc++.h>
using namespace std;
int n;
char str[2005], tmp[2005];
int digit[10];
bool sign[2005];
char num[2005][2005];
int len[2005];
int DFS(int pos, bool flag1){
	bool flag2 = flag1;
	for (; str[pos] != '\0'; pos++){
		if (str[pos] == '(')
			pos = DFS(pos + 1, flag2);
		else if (str[pos] == ')')
			return pos;
		else if (str[pos] == '-')
			flag2 = !flag1;
		else if (str[pos] == '+')
			flag2 = flag1;
		else {
			while (str[pos] !='\0' && str[pos] == '#')
				len[n]++, pos++;
			pos--;
			sign[n++] = flag2;
		}
	}
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	getchar();
	while (t--){
		gets(str);
		gets(tmp);
		memset(digit, 0, sizeof(digit));
		for (int i = 0; tmp[i] != '\0'; i++)
			digit[tmp[i] - '0']++;
		n = 0;
		memset(len, 0, sizeof(len));
		memset(sign, false, sizeof(sign));
		DFS(0, false);
		for (int i = 0; i < n; i++)
			num[i][len[i]] = '\0';
		for (int i = 9; i >= 0;i--){
			while (digit[i] > 0){
				int mj = -1, maxLen = 0;
				for (int j = n - 1; j >= 0; j--)
					if (!sign[j] && maxLen < len[j])
						maxLen = len[j], mj = j;
				if (mj == -1)
					break;
				num[mj][--len[mj]] = '0' + i;
				digit[i]--;
			}
		}
		for (int i = 0; i <= 9; i++){
			while (digit[i] > 0){
				int mj = -1, maxLen = 0;
				for (int j = 0; j < n; j++)
					if (sign[j] && maxLen < len[j])
						maxLen = len[j], mj = j;
				if (mj == -1)
					break;
				num[mj][--len[mj]] = '0' + i;
				digit[i]--;
			}
		}
		for (int i = 0; i < n; i++)
			reverse(num[i], num[i] + strlen(num[i]));
		printf("Case %d:\n", c++);
		long long ans = 0;
		for (int i = 0, j = 0; str[i] != '\0'; i++){
			if (str[i] != '#')
				putchar(str[i]);
			else{
				while (str[i] != '\0' && str[i] == '#')	i++;
				i--;
				printf("%s", num[j++]);
			}
		}
		putchar('\n');
		for (int i = 0; i < n; i++){
			long long s = 0;
			for (int j = 0; num[i][j] != '\0'; j++)
				s = s * 10 + num[i][j] - '0';
			if (sign[i])	s *= -1;
			ans += s;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Professor Conrad loves to work with expressions and we all know that there are many well known
techniques to evaluate expressions. After teaching his class about evaluating expression he gives his
class a bit tricky assignment. As usual being the most brilliant programmer of the class, your classmates
have grasped you to do the assignment for them. The assignment is stated below:
You are given an expression consisting only brackets, blank spaces and +/− operators and
also some digits. You have to place the given digits in the blank spaces in such a way so
that the value of the expression is maximum.
Input
First line of the input file contains an integer N (N ≤ 505) which denotes how many sets of inputs will
be there. The description of each set is given below.
First line of each set contains a correct expression and the second line contains a sequence of digits.
You can put any of this one of these digits in the blank spaces of the expression. In the input the blank
spaces are denoted with ‘#’ characters. You can assume that
(a) The number of ‘#’ signs in the expression and the number of given digits will be equal
(b) There will be maximum eight consecutive ‘#’ signs in the given expression
(c) The length of the expression will be less than 200
Output
For each set of input produce three lines of output. First line contains the serial of output, the second
line contains the expression which produces maximum value and the third line contains this maximum
value. If more than one expression produces maximum value then output the lexicographically smallest
one. You can assume that
(a) the maximum value of the expression will fit in a 32-bit signed integer
(b) Numbers in the expression can have leading zeroes.
Sample Input
3
##-(##+###)
3333333
#+#
31
#-#
31
Sample Output
Case 1:
33-(33+333)
-333
Case 2:
1+3
4
Case 3:
3-1
2

*/