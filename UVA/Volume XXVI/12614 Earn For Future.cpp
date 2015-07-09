/* 13062009	12614	Earn For Future	Accepted	C++	0.016	2014-01-31 13:46:56 */
#include<cstdio>
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		int n;
		int ans = 0;
		int M[50];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		for (int i = 0; i < n; i++){
			if (M[i]>ans)
				ans = M[i];
		}
		printf("Case %d: %d\n", c, ans);
		c++;
	}
	return 0;
}
/*


Earn For Future!
In a lazy afternoon the great Froogrammer came to realize that, to make his future plans successful he needs a lot of money. To make some quick cash he decided to go to the casino to play a game. The rule of the game is the following:

The player is given N cards. Each card has a non-negative integer printed in it.
The player will choose some cards from the given cards.
The bitwise AND value of the chosen cards will be calculated and the player will be given the same amount of money. (i.e. equal to the bitwise AND value of the chosen cards).
After getting N cards Froogrammer was in a fix as usual. He could not decide which of the cards to choose. So he called you to help him. Please tell him the maximum amount he can win from these set of cards. If you are confused about bitwise AND operation see the notes section below.

Input

The first line of input will contain the number of test cases T (T < 101). Then there will be T test cases. Each of the test cases will start with an integer N ( 0 < N < 31) denoting the number of cards. Then the following line will contain N non-negative integers Ci ( 0$ \le$Ci < 231) separated by space, denoting the numbers printed on each of the cards.

Output

For each test case print one line of output denoting the case number and the maximum amount Froogrammer can win. See sample output for exact format.


Note:

A bitwise AND takes two binary representations of equal length and performs the logical AND operation on each pair of corresponding bits. The resulting bit of a position is 1 if the bit at that position of both numbers is 1; otherwise, that bit is 0.

For example:

0101 (decimal 5)
AND 0011 (decimal 3)
= 0001 (decimal 1)
Sample Input

1
2
0 1
Sample Output

Case 1: 1

Problemsetter: Abu Obaida Opu
Special Thanks: Towhidul Islam Talukder

*/