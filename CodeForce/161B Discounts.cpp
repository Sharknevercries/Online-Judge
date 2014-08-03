/* 5353407	 Dec 5, 2013 3:17:37 PM	Shark	 161B - Discounts	 GNU C++	Accepted	30 ms	200 KB */
#include<stdio.h>
#include<vector>
#include<algorithm>
struct data{
	int price, type, ID;
	bool used;
};
bool cmp(struct data A, struct data B){
	return A.price > B.price;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		struct data M[1000];
		std::vector<int> S[1000];
		for (int i = 0; i < n; i++){
			scanf("%d%d", &M[i].price, &M[i].type);
			M[i].used = false;
			M[i].ID = i + 1;
			S[i].clear();
		}
		std::sort(M, M + n, cmp);
		double ans = 0;
		int i, ptr = 0;
		for (i = 0; i < n && ptr < m - 1; i++){
			if (M[i].type == 1){
				S[ptr++].push_back(M[i].ID);
				ans += M[i].price * 0.5;
				M[i].used = true;
			}
		}
		for (i = 0; i < n && ptr < m - 1; i++){
			if (M[i].type == 2){
				S[ptr++].push_back(M[i].ID);
				ans += M[i].price;
				M[i].used = true;
			}
		}
		int min = 2e9;
		bool found = false;
		for (i = 0; i < n; i++){
			if (!M[i].used){
				S[ptr].push_back(M[i].ID);
				if (M[i].type == 1)
					found = true;
				ans += M[i].price;
				if (M[i].price < min)
					min = M[i].price;
				M[i].used = true;
			}
		}
		if (found)
			ans -= min*0.5;
		printf("%.1lf\n", ans);
		for (int i = 0; i < m; i++){
			printf("%d", S[i].size());
			for (int j = 0; j < S[i].size(); j++)
				printf(" %d", S[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
/*

B. Discounts
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Polycarpus stopped by a supermarket on his way home. It turns out that the supermarket is having a special offer for stools. The offer is as follows: if a customer's shopping cart contains at least one stool, the customer gets a 50% discount on the cheapest item in the cart (that is, it becomes two times cheaper). If there are several items with the same minimum price, the discount is available for only one of them!

Polycarpus has k carts, and he wants to buy up all stools and pencils from the supermarket. Help him distribute the stools and the pencils among the shopping carts, so that the items' total price (including the discounts) is the least possible.

Polycarpus must use all k carts to purchase the items, no shopping cart can remain empty. Each shopping cart can contain an arbitrary number of stools and/or pencils.

Input
The first input line contains two integers n and k (1 ≤ k ≤ n ≤ 103) — the number of items in the supermarket and the number of carts, correspondingly. Next n lines describe the items as "ci ti" (without the quotes), where ci (1 ≤ ci ≤ 109) is an integer denoting the price of the i-th item, ti (1 ≤ ti ≤ 2) is an integer representing the type of item i (1 for a stool and 2 for a pencil). The numbers in the lines are separated by single spaces.

Output
In the first line print a single real number with exactly one decimal place — the minimum total price of the items, including the discounts.

In the following k lines print the descriptions of the items in the carts. In the i-th line print the description of the i-th cart as "t b1 b2 ... bt" (without the quotes), where t is the number of items in the i-th cart, and the sequence b1, b2, ..., bt (1 ≤ bj ≤ n) gives the indices of items to put in this cart in the optimal distribution. All indices of items in all carts should be pairwise different, each item must belong to exactly one cart. You can print the items in carts and the carts themselves in any order. The items are numbered from 1 to n in the order in which they are specified in the input.

If there are multiple optimal distributions, you are allowed to print any of them.

Sample test(s)
input
3 2
2 1
3 2
3 1
output
5.5
2 1 2
1 3
input
4 3
4 1
1 2
2 2
3 2
output
8.0
1 1
2 4 2
1 3
Note
In the first sample case the first cart should contain the 1st and 2nd items, and the second cart should contain the 3rd item. This way each cart has a stool and each cart has a 50% discount for the cheapest item. The total price of all items will be: 2·0.5 + (3 + 3·0.5) = 1 + 4.5 = 5.5.

*/