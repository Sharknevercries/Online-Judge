/* 15149644	233	Package Pricing	Accepted	C++	0.659	2015-03-15 11:42:33 */
#include<bits\stdc++.h>
using namespace std;
struct Package{
	int label;
	double price;
	int supply[4];
	void init(){
		label = price = 0;
		memset(supply, 0, sizeof(supply));
	}
};
Package P[55];
int need[4];
int minCount[55];
double minCost;
double DP[1024000];
int record[1024000][2];
int digit[4];
int n, m;
bool cmp(Package A, Package B){
	return A.label < B.label;
}
int getIndex(int s[]){
	int res = 0;
	for (int i = 0; i < 4; i++)
		res += s[i] * digit[i];
	return res;
}
void solve(){
	digit[3] = 1;
	digit[2] = digit[3] * (need[3] + 1);
	digit[1] = digit[2] * (need[2] + 1);
	digit[0] = digit[1] * (need[1] + 1);
	int A[4], B[4], maxState = getIndex(need);
	for (int i = 0; i <= maxState; i++)
		DP[i] = 1e+55, record[i][0] = record[i][1] = -1;
	DP[0] = 0;
	for (int i = 0, u, v; i <= maxState; i++){
		u = i;
		for (int j = 0; j < 4; j++)
			A[j] = u / digit[j], u %= digit[j];
		u = i;
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < 4; k++)
				B[k] = min(need[k], A[k] + P[j].supply[k]);
			v = getIndex(B);
			if (DP[v] > DP[u] + P[j].price)
				DP[v] = DP[u] + P[j].price, record[v][0] = j, record[v][1] = u;
		}
	}
	memset(minCount, 0, sizeof(minCount));
	for (int i = maxState; i != -1; i = record[i][1])
		minCount[record[i][0]]++;
	minCost = DP[maxState];
}
int main(){
	while (scanf("%d", &n) == 1){
		while (getchar() != '\n');
		char str[10000], ch;
		int count;
		for (int i = 1; i <= n; i++)
			P[i].init();
		for (int i = 1; i <= n; i++){
			scanf("%d%lf", &P[i].label, &P[i].price);
			gets(str);
			ch = count = 0;
			for (int j = 1, k = 0; str[j] != '\0'; j++){
				if (str[j] >= '0' && str[j] <= '9')
					count = count * 10 + str[j] - '0';
				else if (str[j] >= 'a' && str[j] <= 'd')
					ch = str[j];
				else if ((++k) % 2 == 0)
					P[i].supply[ch - 'a'] += count, count = 0;
			}
			P[i].supply[ch - 'a'] += count;
		}
		sort(P + 1, P + 1 + n, cmp);
		scanf("%d", &m);
		while (getchar() != '\n');
		for (int i = 0; i < m; i++){
			memset(need, 0, sizeof(need));
			gets(str);
			ch = count = 0;
			for (int j = 0, k = 0; str[j] != '\0'; j++){
				if (str[j] >= '0' && str[j] <= '9')
					count = count * 10 + str[j] - '0';
				else if (str[j] >= 'a' && str[j] <= 'd')
					ch = str[j];
				else if ((++k) % 2 == 0)
					need[ch - 'a'] += count, count = 0;
			}
			need[ch - 'a'] += count;
			solve();
			printf("%d:%8.2lf", i + 1, minCost);
			for (int j = 1; j <= n;j++)
				if (minCount[j]){
					printf(" %d", P[j].label);
					if (minCount[j] > 1)
						printf("(%d)", minCount[j]);
				}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
/*


Package Pricing

The Green Earth Trading Company sells 4 different sizes of energy-efficient fluorescent light bulbs for use in home lighting fixtures. The light bulbs are expensive, but last much longer than ordinary incandescent light bulbs and require much less energy. To encourage customers to buy and use the energy- efficient light bulbs, the company catalogue lists special packages which contain a variety of sizes and numbers of the light bulbs. The price of a package is always substantially less than the total price of the individual bulbs in the package. Customers typically want to buy several different sizes and numbers of bulbs. You are to write a program to determine the least expensive collection of packages that satisfy any customer's request.

Input

The input file contains several datasets. Each dataset is divided into two parts. The first one describes the packages which are listed in the catalogue. The second part describes individual customer requests. The 4 sizes of light bulbs are identified in the input file by the characters ``a", ``b", ``c", and ``d".

The first part of the dataset begins with an integer n ( tex2html_wrap_inline44 ) indicating the number of packages described in the catalogue. Each of the n lines that follows is a single package description. A package description begins with a catalogue number (a positive integer) followed by a price (a real number), and then the sizes and corresponding numbers of the light bulbs in the package. Between 1 and 4 different sizes of light bulbs will be listed in each description. The listing format for these size-number pairs is a blank, a character (``a", ``b", ``c", or ``d") representing a size, another blank, and then an integer representing the number of light bulbs of that size in the package. These size-number pairs will not appear in any particular order, and there will be no duplicate sizes listed in any package. The following line describes a package with catalogue number 210 and price $76.95 which contains 3 size ``a" bulbs, 1 size ``c" bulb, and 4 size ``d" bulbs.

210 76.95 a 3 c 1 d 4
The second part of the dataset begins with a line containing a single positive integer m representing the number of customer requests. Each of the remaining m lines is a customer request. A listing of sizes and corresponding numbers of light bulbs constitutes a request. Each list contains only the size-number pairs, formatted the same way that the size-number pairs are formatted in the catalogue descriptions. Unlike the catalogue descriptions, however, a customer request may contain duplicate sizes. The following line represents a customer request for 1 size ``a" bulb, 2 size ``b" bulbs, 2 size ``c" bulbs, and 5 size ``d" bulbs.

a 1 d 5 b 1 c 2 b 1
Output

For each request, print the customer number (1 through m, 1 for the first customer request, 2 for the second,  tex2html_wrap_inline54 , m for the  tex2html_wrap_inline58 customer), a colon, the total price of the packages which constitute the least expensive way to fill the request, and then the combination of packages that the customer should order to fill that request.

Prices should be shown with exactly two significant digits to the right of the decimal. The combination of packages must be written in ascending order of catalogue numbers. If more than one of the same type package is to be ordered, then the number ordered should follow the catalogue number in parentheses. You may assume that each customer request can be filled. In some cases, the least expensive way to fill a customer request may contain more light bulbs of some sizes than necessary to fill the actual request. This is acceptable. What matters is that the customers receive at least what they request.

Print a blank line after each dataset.

Sample Input

5
10 25.00 b 2
502 17.95 a 1
3 13.00 c 1
55 27.50 b 1 d 2 c 1
6 52.87 a 2 b 1 d 1 c 3
6
d 1
b 3
b 3 c 2
b 1 a 1 c 1 d 1 a 1
b 1 b 2 c 3 c 1 a 1 d 1
b 3 c 2 d 1 c 1 d 2 a 1
Sample Output

1:   27.50 55
2:   50.00 10(2)
3:   65.50 3 10 55
4:   52.87 6
5:   90.87 3 6 10
6:  100.45 55(3) 502

*/