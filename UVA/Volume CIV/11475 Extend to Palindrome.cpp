/* 13058202	11475	Extend to Palindrome	Accepted	C++	0.035	2014-01-30 16:59:03 */
#include<cstdio>
#include<cstring>
#define MAX 100000
int main(){
	char S1[MAX + 1];
	char S2[MAX + 1];
	int pre[MAX + 1];
	while (scanf("%s", S1) == 1){
		int len = strlen(S1);
		int i, j;
		for (i = len - 1, j = 0; i >= 0; i--, j++)
			S2[j] = S1[i];
		S2[len] = '\0';

		for (i = 1, j = pre[0] = -1; S2[i] != '\0'; i++){
			while (j >= 0 && S2[i] != S2[j + 1])
				j = pre[j];
			if (S2[j + 1] == S2[i])
				j++;
			pre[i] = j;
		}

		for (i = 0, j = -1; S1[i] != '\0'; i++){
			while (j >= 0 && S2[j + 1] != S1[i])
				j = pre[j];
			if (S2[j + 1] == S1[i])
				j++;
		}
		printf("%s%s\n", S1, &S2[j + 1]);
	}
	return 0;
}
/*

Problem E
Extend to Palindromes
Time Limit : 3 seconds

Your task is, given an integer N, to make a palidrome (word that reads the same when you reverse it) of length at least N. Any palindrome will do. Easy, isn't it? That's what you thought before you passed it on to your inexperienced team-mate. When the contest is almost over, you find out that that problem still isn't solved. The problem with the code is that the strings generated are often not palindromic. There's not enough time to start again from scratch or to debug his messy code. Seeing that the situation is desperate, you decide to simply write some additional code that takes the output and adds just enough extra characters to it to make it a palindrome and hope for the best. Your solution should take as its input a string and produce the smallest palindrome that can be formed by adding zero or more characters at its end.

Input

Input will consist of several lines ending in EOF. Each line will contain a non-empty string made up of upper case and lower case English letters ('A'-'Z' and 'a'-'z'). The length of the string will be less than or equal to 100,000.

Output

For each line of input, output will consist of exactly one line. It should contain the palindrome formed by adding the fewest number of extra letters to the end of the corresponding input string.

Sample Input
Sample Output

aaaa
abba
amanaplanacanal
xyz
aaaa
abba
amanaplanacanalpanama
xyzyx

Problem Setter: Muntasir Azam Khan
Special Thanks: Rakibul Hossain
Next Generation Contest 5

*/