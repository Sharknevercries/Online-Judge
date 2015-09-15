/* 15881355	10453	Make Palindrome	Accepted	C++	0.527	2015-08-05 07:05:05 */
#include<bits\stdc++.h>
using namespace std;
char str[1005];
int DP[1005][1005];
int record[1005][1005];
int DFS(int a, int b) {
  if (a > b) return 0;
  if (DP[a][b] != -1)  return DP[a][b];
  if (str[a] == str[b])
    record[a][b] = 0, DP[a][b] = DFS(a + 1, b - 1);
  else {
    int res1 = DFS(a + 1, b);
    int res2 = DFS(a, b - 1);
    if (res1 < res2)
      record[a][b] = 1, DP[a][b] = res1 + 1;
    else
      record[a][b] = -1, DP[a][b] = res2 + 1;
  }
  return DP[a][b];
}
void print(int a, int b) {
  if (a > b) return;
  if (a == b) { putchar(str[a]); return; }
  if (record[a][b] == 0) {
    putchar(str[a]);
    print(a + 1, b - 1);
    putchar(str[a]);
  }
  else if (record[a][b] == 1) {
    putchar(str[a]);
    print(a + 1, b);
    putchar(str[a]);
  }
  else {
    putchar(str[b]);
    print(a, b - 1);
    putchar(str[b]);
  }
}
int main() {
  while (scanf("%s", str) == 1) {
    memset(DP, -1, sizeof(DP));
    printf("%d ", DFS(0, strlen(str) - 1));
    print(0, strlen(str) - 1);
    putchar('\n');
  }
  return 0;
}
/*

By definition palindrome is a string which is not changed when reversed. ：MADAM； is a nice example of
palindrome. It is an easy job to test whether a given string is a palindrome or not. But it may not be
so easy to generate a palindrome.
Here we will make a palindrome generator which will take an input string and return a palindrome.
You can easily verify that for a string of length n, no more than (n?1) characters are required to make
it a palindrome. Consider ．abcd・ and its palindrome ．abcdcba・ or ．abc・ and its palindrome ．abcba・.
But life is not so easy for programmers!! We always want optimal cost.
And you have to find the minimum number of characters required to make a given string to a
palindrome if you are allowed to insert characters at any position of the string.
Input
Each input line consists only of lower case letters. The size of input string will be at most 1000. Input
is terminated by EOF.
Output
For each input print the minimum number of characters and such a palindrome separated by one space
in a line. There may be many such palindromes. Any one will be accepted.
Sample Input
abcd
aaaa
abc
aab
abababaabababa
pqrsabcdpqrs
Sample Output
3 abcdcba
0 aaaa
2 abcba
1 baab
0 abababaabababa
9 pqrsabcdpqrqpdcbasrqp

*/