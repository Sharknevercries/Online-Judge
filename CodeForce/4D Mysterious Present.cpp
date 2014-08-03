/* 5352790	 Dec 5, 2013 1:02:23 PM	Shark	 4D - Mysterious Present	 GNU C++	Accepted	92 ms	100 KB */
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
struct data{
	int W, H;
	int ID;
	bool operator> (struct data T){
		return this->H > T.H&&this->W > T.W;
	}
};
bool cmp(struct data A, struct data B){
	return A.W < B.W || (A.W == B.W&&A.H < B.H);
}
int main(){
	int n;
	struct data M[5001];
	while (scanf("%d", &n) == 1){
		int DP[5001] = { 0 };
		int P[5001];
		for (int i = 0; i <= n; i++){
			scanf("%d%d", &M[i].W, &M[i].H);
			M[i].ID = i;
		}
		std::sort(M + 1, M + 1 + n, cmp);
		DP[0] = 0, P[0] = -1;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < i; j++){
				if (M[i] > M[j] && M[i] > M[0]){
					if (DP[j] + 1 > DP[i])
						DP[i] = DP[j] + 1, P[i] = j;
				}
			}
		}
		int max = 0, ptr;
		for (int i = 1; i <= n; i++){
			if (DP[i] > max)
				max = DP[i], ptr = i;
		}
		printf("%d\n", max);
		if (max > 0){
			int tmp[5001], s = max - 1;
			while (s >= 0){
				tmp[s--] = M[ptr].ID;
				ptr = P[ptr];
			}
			printf("%d", tmp[0]);
			for (int i = 1; i < max; i++)
				printf(" %d", tmp[i]);
			putchar('\n');
		}
	}
	return 0;
}
/*

D. Mysterious Present
time limit per test2 seconds
memory limit per test64 megabytes
inputstandard input
outputstandard output
Peter decided to wish happy birthday to his friend from Australia and send him a card. To make his present more mysterious, he decided to make a chain. Chain here is such a sequence of envelopes A = {a1,  a2,  ...,  an}, where the width and the height of the i-th envelope is strictly higher than the width and the height of the (i  -  1)-th envelope respectively. Chain size is the number of envelopes in the chain.

Peter wants to make the chain of the maximum size from the envelopes he has, the chain should be such, that he'll be able to put a card into it. The card fits into the chain if its width and height is lower than the width and the height of the smallest envelope in the chain respectively. It's forbidden to turn the card and the envelopes.

Peter has very many envelopes and very little time, this hard task is entrusted to you.

Input
The first line contains integers n, w, h (1  ≤ n ≤ 5000, 1 ≤ w,  h  ≤ 106) — amount of envelopes Peter has, the card width and height respectively. Then there follow n lines, each of them contains two integer numbers wi and hi — width and height of the i-th envelope (1 ≤ wi,  hi ≤ 106).

Output
In the first line print the maximum chain size. In the second line print the numbers of the envelopes (separated by space), forming the required chain, starting with the number of the smallest envelope. Remember, please, that the card should fit into the smallest envelope. If the chain of maximum size is not unique, print any of the answers.

If the card does not fit into any of the envelopes, print number 0 in the single line.

Sample test(s)
input
2 1 1
2 2
2 2
output
1
1
input
3 3 3
5 4
12 11
9 8
output
3
1 3 2

*/