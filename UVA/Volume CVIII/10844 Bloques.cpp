/* 13821295	10844	Bloques	Accepted	C++	2.686	2014-07-02 07:42:10 */
/*

Bell 數
1
1	2
2	3	5
5	7	10	15
15	20	27	37	52
52	...

*/
#include<cstdio>
#include<string.h>
#define SWAP(x,y) {	int tmp=x;	x=y;	y=tmp;	}
char T[2][910][2000];
char ans[910][2000];
void sum(char s1[], char s2[], char res[]){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int reslen = len1 > len2 ? len1 + 1 : len2 + 1;
	int i, j, k, tmp;
	res[reslen] = '\0';
	for (i = len1 - 1, j = len2 - 1, k = reslen - 1, tmp = 0; i >= 0 || j >= 0;){
		if (i >= 0)	tmp += s1[i--] - '0';
		if (j >= 0)	tmp += s2[j--] - '0';
		res[k--] = tmp % 10 + '0';
		tmp /= 10;
	}
	res[k] = tmp + '0';
	for (k = 0; res[k] == '0'; k++);
	for (i = 0; res[i + k] != '\0'; i++)
		res[i] = res[i + k];
	res[i] = '\0';
}
void copy(char dest[], char src[]){
	int i;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
void solve(){
	int pre = 0, cur = 1;
	T[0][0][0] = '1', T[0][0][1] = '\0';
	memcpy(ans[0], T[0][0], sizeof(T[0][0]));
	for (int i = 1; i <= 900; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0)
				copy(T[cur][j], T[pre][i - 1]);
			else
				sum(T[pre][j - 1], T[cur][j - 1], T[cur][j]);
			if (j == i)
				copy(ans[i], T[cur][j]);
		}
		SWAP(pre, cur);
	}
}
int main(){
	solve();
	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("%d, %s\n", n, ans[n - 1]);
	}
	return 0;
}
/*

Problem E
Bloques
Time Limit: 2 seconds
Little Joan has N blocks,all of them of different sizes. He is playing to build cities in the beach. A city is just a collection of buildings.

A single block over the sand can be considered as a building. Then he can construct higher buildings by putting a block above any other block. At most one block can be put immediately above any other block. However he can stack several blocks together to construct a building. However, it�s not allowed to put bigger blocks on top of smaller ones, since the stack of blocks may fall. A block can be specified by a natural number that represents its size.

It doesn�t matter the order among buildings. That is:

1 3
2 4
is the same configuration as:
3 1
4 2
Your problem is to compute the number of possible different cities using N blocks. We say that #(N) gives the number of different cities of size N. If N=2, for instance, there are only two possible cities:

City #1:
1 2
In this city both blocks of size 1 and 2 are put over the sand.

City #2:
1
2
In this city block of size 1 is over block is size 2, and block of size 2 is over the sand.

So, #(2)=2.

Input
A sequence of non-negative integer numbers, each of one in different line. All of them but the last one are natural numbers. The last one is 0 and means the end. Each natural number is less than 900.

Output
For each natural number I in the input, you must write a line with the pair of numbers I, #(I).

Sample Input	Sample Output
2
3
0
2, 2
3, 5
Problemsetter: Dr. Mauricio Javier Osorio Galindo

*/