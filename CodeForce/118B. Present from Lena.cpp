/* 1204316	 Feb 19, 2012 7:21:17 PM	Shark	 118B - Present from Lena	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<=n;i++){
			for(int j=1;j<=n-i;j++)
				printf("  ");
			printf("0");
			for(int j=1;j<=i;j++)
				printf(" %d",j);
			for(int j=i-1;j>=0;j--)
				printf(" %d",j);
			putchar('\n');
		}
		for(int i=n-1;i>=0;i--){
			for(int j=1;j<=n-i;j++)
				printf("  ");
			printf("0");
			for(int j=1;j<=i;j++)
				printf(" %d",j);
			for(int j=i-1;j>=0;j--)
				printf(" %d",j);
			putchar('\n');
		}
	}
	return 0;
}
/*

Vasya's birthday is approaching and Lena decided to sew a patterned handkerchief to him as a present. Lena chose digits from 0 to n as the pattern. The digits will form a rhombus. The largest digit n should be located in the centre. The digits should decrease as they approach the edges. For example, for n = 5 the handkerchief pattern should look like that:

          0
        0 1 0
      0 1 2 1 0
    0 1 2 3 2 1 0
  0 1 2 3 4 3 2 1 0
0 1 2 3 4 5 4 3 2 1 0
  0 1 2 3 4 3 2 1 0
    0 1 2 3 2 1 0
      0 1 2 1 0
        0 1 0
          0
Your task is to determine the way the handkerchief will look like by the given n.

Input

The first line contains the single integer n (2 ≤ n ≤ 9).

Output

Print a picture for the given n. You should strictly observe the number of spaces before the first digit on each line. Every two adjacent digits in the same line should be separated by exactly one space. There should be no spaces after the last digit at the end of each line.

input

2
3

output

    0
  0 1 0
0 1 2 1 0
  0 1 0
    0
      0
    0 1 0
  0 1 2 1 0
0 1 2 3 2 1 0
  0 1 2 1 0
    0 1 0
      0

*/