/* 1272552	 Mar 4, 2012 11:55:55 AM	Shark	 143A - Help Vasilisa the Wise 2	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int R1,R2,C1,C2,D1,D2;
	while(scanf("%d%d%d%d%d%d",&R1,&R2,&C1,&C2,&D1,&D2)==6){
		int A,B,C,D;
		bool found=false;
		for(A=1;A<=9;A++){
			for(B=1;B<=9;B++){
				for(C=1;C<=9;C++){
					for(D=1;D<=9;D++){
						if( A!=B&&A!=C&&A!=D&&B!=C&&B!=D&&C!=D&&(R1==A+B)&&(R2==C+D)&&(C1==A+C)&&(C2==B+D)&&(D1==A+D)&&(D2==B+C) )
							found=true;
						if(found)	break;
					}
					if(found)	break;
				}
				if(found)	break;
			}
			if(found)	break;
		}
		if(found)
			printf("%d %d\n%d %d\n",A,B,C,D);
		else
			puts("-1");
	}
	return 0;
}
/*

Vasilisa the Wise from the Kingdom of Far Far Away got a magic box with a secret as a present from her friend Hellawisa the Wise from the Kingdom of A Little Closer. However, Vasilisa the Wise does not know what the box's secret is, since she cannot open it again. She hopes that you will help her one more time with that.

The box's lock looks as follows: it contains 4 identical deepenings for gems as a 2 × 2 square, and some integer numbers are written at the lock's edge near the deepenings. The example of a lock is given on the picture below.

The box is accompanied with 9 gems. Their shapes match the deepenings' shapes and each gem contains one number from 1 to 9 (each number is written on exactly one gem). The box will only open after it is decorated with gems correctly: that is, each deepening in the lock should be filled with exactly one gem. Also, the sums of numbers in the square's rows, columns and two diagonals of the square should match the numbers written at the lock's edge. For example, the above lock will open if we fill the deepenings with gems with numbers as is shown on the picture below.

Now Vasilisa the Wise wants to define, given the numbers on the box's lock, which gems she should put in the deepenings to open the box. Help Vasilisa to solve this challenging task.

Input

The input contains numbers written on the edges of the lock of the box. The first line contains space-separated integers r1 and r2 that define the required sums of numbers in the rows of the square. The second line contains space-separated integers c1 and c2 that define the required sums of numbers in the columns of the square. The third line contains space-separated integers d1 and d2 that define the required sums of numbers on the main and on the side diagonals of the square (1 ≤ r1, r2, c1, c2, d1, d2 ≤ 20). Correspondence between the above 6 variables and places where they are written is shown on the picture below. For more clarifications please look at the second sample test that demonstrates the example given in the problem statement.

Output

Print the scheme of decorating the box with stones: two lines containing two space-separated integers from 1 to 9. The numbers should be pairwise different. If there is no solution for the given lock, then print the single number "-1" (without the quotes).

If there are several solutions, output any.

input

3 7
4 6
5 5
11 10
13 8
5 16
1 2
3 4
5 6
10 10
10 10
10 10

output

1 2
3 4
4 7
9 1
-1
-1

Note

Pay attention to the last test from the statement: it is impossible to open the box because for that Vasilisa the Wise would need 4 identical gems containing number "5". However, Vasilisa only has one gem with each number from 1 to 9.

*/