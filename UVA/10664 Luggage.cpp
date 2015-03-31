/* 15250199	10664	Luggage	Accepted	C++	0.015	2015-03-31 17:05:12
 */
#include<bits\stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	getchar();
	while (t--){
		int w[50], n = 0, tmp = 0, sum = 0;
		char str[100000];
		bool DP[500] = { false };
		gets(str);
		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == ' ')
				w[n++] = tmp, tmp = 0;
			else
				tmp = tmp * 10 + str[i] - '0';
		w[n++] = tmp;
		for (int i = 0; i < n; i++)
			sum += w[i];
		if (sum % 2 == 0){
			DP[0] = true;
			for (int i = 0; i < n; i++)
				for (int j = sum; j - w[i] >= 0; j--)
					DP[j] |= DP[j - w[i]];
			puts(DP[sum / 2] ? "YES" : "NO");
		}
		else
			puts("NO");

	}
	return 0;
}
/*

Luggage

Peter and his friends are on holiday, so they have decided to make a trip by car to know the north of Spain. They are seven people and they think that two cars are enough for their luggage.

It’s time to leave… and a heap of suitcases are awaiting out of the cars. The drivers disagree about which suitcase must be put into each boot, because nobody wants one boot to carry more weight than the other one. Is it possible that the two boots load with the same weight? (Obviously without unpacking the suitcases!)
Consider m sets of numbers representing suitcases weights, you must decide for each one, if it is possible to distribute the suitcases into the boots, and the two boots weigh the same.

Input

The first line of the input contains an integer, m, indicating the number of test cases. For each test case, there is a line containing n integers (1£  n £ 20) separated by single spaces. These integers are the weights of each suitcase. The total sum of the weights of all the suitcases is less or equal to 200 kilograms.
Output

The output consists of m lines. The i-th line corresponds with the i-th set of suitcases weight and contains the string “YES” or “NO”, depending on the possibility that the two boots load with the same weight for the respective test case.

Sample Input
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1
Sample Output
NO
YES
YES

*/