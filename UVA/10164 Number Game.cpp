/* 15191527	10164	Number Game	Accepted	C++	0.022	2015-03-21 12:24:56 */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	int value;
	int L, R;
};
int n;
int a[2055];
Node T[20][2055];
bool first;
void travel(int level, int pos){
	if (level == 0){
		if (!first)putchar(' ');
		first = false;
		printf("%d", T[level][pos].value);
		return;
	}
	travel(level - 1, T[level][pos].L);
	travel(level - 1, T[level][pos].R);
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < 2 * n - 1; i++)
			scanf("%d", a + i);
		for (int i = 0; i < 2 * n - 1; i++)
			T[0][i].L = T[0][i].R = i, T[0][i].value = a[i];
		int N = 2 * n - 1, level = 1;
		while (N > 1){
			int odd = -1, even = -1, ptr = 0;
			for (int i = 0; i < N; i++){
				if (T[level - 1][i].value & 1){
					if (odd == -1)
						odd = i;
					else{
						T[level][ptr].L = odd;
						T[level][ptr].R = i;
						T[level][ptr].value = (T[level - 1][odd].value + T[level - 1][i].value) / 2;
						ptr++;
						odd = -1;
					}
				}
				else{
					if (even == -1)
						even = i;
					else{
						T[level][ptr].L = even;
						T[level][ptr].R = i;
						T[level][ptr].value = (T[level - 1][even].value + T[level - 1][i].value) / 2;
						ptr++;
						even = -1;
					}
				}
			}
			N /= 2, level++;
		}
		first = true;
		puts("Yes");
		travel(level - 1, 0);
		putchar('\n');
	}
	return 0;
}
/*

Let’s play a number game. I will give you 2N − 1 (N = 2k
, k = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) numbers, each
number is a positive integer not bigger than 1000. Can you choose N of them, and add them all to a
integer S, to make that S/N is a integer? If there are many solutions, you can only find one of them.
Input
The input file contains several scenarios. Each of them consists of 2 lines.
For each scenario, the first line is a number N, the second line consist of 2N − 1 numbers. There is
a space between two numbers.
Output
For each scenario, print a single line ‘No’ if you can’t find an answer. Otherwise print a line ‘Yes’, and
then the other line containing N numbers (in any order), there should be a space between two numbers.
Sample Input
2
1 2 3
4
1 2 3 4 5 6 7
0
Sample Output
Yes
1 3
Yes
1 3 5 7

*/