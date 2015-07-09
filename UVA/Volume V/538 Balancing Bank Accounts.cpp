/* 13936641	538	Balancing Bank Accounts	Accepted	C++	0.192	2014-07-24 07:37:03 */
/*

Template By Shark

*/
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 30
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int main(){
	int n, m, t = 1;
	while (scanf("%d%d", &n, &m) == 2 && n && m){
		map<string, int> ptr;
		string name[MAX_N];
		int money[MAX_N] = { 0 };
		for (int i = 0; i < n; i++){
			cin >> name[i];
			ptr[name[i]] = i;
		}
		for (int i = 0; i < m; i++){
			string A, B;
			int loan;
			cin >> A >> B >> loan;
			money[ptr[A]] -= loan;
			money[ptr[B]] += loan;
		}
		cout << "Case #" << t++ << endl;
		for (int i = 0; i < n; i++){
			if (money[i] > 0){
				for (int j = 0; j < n && money[i] > 0; j++){
					if (money[j] < 0){
						if (money[i] >= abs(money[j]))
							cout << name[i] << " " << name[j] << " " << abs(money[j]) << endl, money[i] -= abs(money[j]), money[j] = 0;
						else
							cout << name[i] << " " << name[j] << " " << abs(money[i]) << endl, money[j] += money[i], money[i] = 0;
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}
/*

Balancing Bank Accounts
Once upon a time there was a large team coming home from the ACM World Finals. The fifteen travellers were confronted with a big problem:

In the previous weeks, there had been many money transactions between them: Sometimes somebody paid the entrance fees of a theme park for the others, somebody else paid the hotel room, another one the rental car, and so on.

So now the big calculation started. Some people had paid more than others, thus the individual bank accounts had to be balanced again. "Who has to pay whom how much?", that was the question.

As such a calculation is a lot of work, we need a program now that will solve this problem next year.

Input

The input file will contain one or more test cases.
Each test case starts with a line containing two integers: the number of travellers n (  $2 \le n \le 20$) and the number of transactions t ( $1 \le t \le 1000$). On the next n lines the names of the travellers are given, one per line. The names only consist of alphabetic characters and contain no whitespace. On the following t lines, the transactions are given in the format name1 name2 amount where name1 is the person who gave amount dollars to name2 . The amount will always be a non-negative integer less than 10000.

Input will be terminated by two values of 0 for n and t.

Output

For each test case, first print a line saying ``Case #i" where i is the number of the test case.
Then, on the following lines, print a list of transactions that reverses the transactions given in the input, i.e. balances the accounts again. Use the same format as in the input. Print a blank line after each test case, even after the last one.

Additional restrictions:

Your solution must consist of at most n-1 transactions.
Amounts may not be negative, i.e. never output ``A B -20", output ``B A 20" instead.
If there is more than one solution satisfying these restrictions, anyone is fine.

Sample Input

2 1
Donald
Dagobert
Donald Dagobert 15
4 4
John
Mary
Cindy
Arnold
John Mary 100
John Cindy 200
Cindy Mary 40
Cindy Arnold 150
0 0
Sample Output

Case #1
Dagobert Donald 15

Case #2
Mary John 140
Cindy John 10
Arnold John 150

Miguel A. Revilla
1999-01-11

*/