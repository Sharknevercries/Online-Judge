/* 15387457	11031	Looking for a Subset	Accepted	C++	0.172	2015-04-26 06:40:57 */
#include<bits\stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	int n, q, c = 1;
	while (scanf("%d%d", &n, &q) == 2){
		if (n == 0 && q == 0)	break;
		int w[10005], pos[10005];
		int LIS[10005], size = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", w + i);
		LIS[size++] = -w[n - 1], pos[n - 1] = size;
		for (int i = n - 2; i >= 0; i--){
			if (LIS[size - 1] < -w[i])
				LIS[size++] = -w[i], pos[i] = size;
			else{
				int p = lower_bound(LIS, LIS + size, -w[i]) - LIS;
				LIS[p] = -w[i], pos[i] = p + 1;
			}
		}
		printf("Set %d:\n", c++);
		for (int i = 0; i < q; i++){
			int length, path[10005];
			scanf("%d", &length);
			printf("  Subset %d:\n", i + 1);
			if (length <= size){
				for (int j = length, k = 0, prev = 1e9; j > 0; k++)
					if (pos[k] >= j && prev > pos[k])
						path[j--] = w[k], prev = pos[k];
				printf("   ");
				for (int j = length; j >= 1; j--)
					printf(" %d", path[j]);
				putchar('\n');
			}
			else
				puts("    Impossible");
		}
	}
	return 0;
}
/*


Problem E

Looking for a Subset

Time limit: 2 seconds


Given a set S = { a1, a2, a3, ... , an }, you have to find a subset of S, P = { ax1, ax2, ax3, ... , axm } such that ( x1 < x2 < ... < xm ) and ( ax1< ax2< ... < axm ). If there are several subsets possible then you should find the subset where x1 is minimum. If there is still a tie then check for the lowest x2 and so on.

Input
The input file contains several sets of inputs. The total number of test cases will be less than 25. The description of each set is given below:

Each case starts with two integers n (1 ≤ n ≤ 10000) and q (1 ≤ q ≤ 100), q is the number of queries. The next line contains n integers (seperated by a space) denoting a1, a2, a3, ... , an respectively. And the next q lines, each contains an integer denoting m (1 ≤ m ≤ n). There is no number in the input file that contains more than 8 digits.

The input will be terminated by the case where n = q = 0. And this case should not be processed.

Output
For each case in the input, you should first print the case number starting from 1.
Then for each query first print the query number starting from 1. And for each m you have to find the result.
If there exists a subset as described above you should print the elements of the subset in a single line. The numbers should be seperated by a space.
Otherwise print ``Impossible'' without the quotes.

See the sample input-output for more details. Output should be formatted like the sample output.


Sample Input

Output for Sample Input

6 3
3 4 1 2 3 6
6
4
5
6 2
2 4 6 1 3 5
3
4
0 0

Set 1:
Subset 1:
Impossible
Subset 2:
1 2 3 6
Subset 3:
Impossible
Set 2:
Subset 1:
2 4 6
Subset 2:
Impossible



ProblemSetter: Jane Alam Jan
Special Thanks: Sohel Hafiz
Next Generation Contest 2


Note:

#1

The output for the first sample case should be: (replacing every space by a `.')

Set.1:
..Subset.1:
....Impossible
..Subset.2:
....1.2.3.6
..Subset.3:
....Impossible

#2

You are advised not to use cin and cout for this problem.

*/