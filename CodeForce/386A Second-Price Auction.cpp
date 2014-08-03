/* 5831007	 Jan 29, 2014 1:30:36 PM	Shark	 386A - Second-Price Auction	 GNU C++	Accepted	15 ms	0 KB */
#include<cstdio>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[1000];
		int first, sec, ptrf, ptrs;
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		first = sec = 0;
		ptrf = ptrs = -1;
		for (int i = 0; i < n; i++){
			if (M[i]>first){
				sec = first, ptrs = ptrf;
				first = M[i], ptrf = i + 1;
			}
			else if (M[i]>sec)
				sec = M[i], ptrs = i + 1;
		}
		printf("%d %d\n", ptrf, sec);
	}
	return 0;
}
/*

A. Second-Price Auction
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
In this problem we consider a special type of an auction, which is called the second-price auction. As in regular auction n bidders place a bid which is price a bidder ready to pay. The auction is closed, that is, each bidder secretly informs the organizer of the auction price he is willing to pay. After that, the auction winner is the participant who offered the highest price. However, he pay not the price he offers, but the highest price among the offers of other participants (hence the name: the second-price auction).

Write a program that reads prices offered by bidders and finds the winner and the price he will pay. Consider that all of the offered prices are different.

Input
The first line of the input contains n (2 ≤ n ≤ 1000) — number of bidders. The second line contains n distinct integer numbers p1, p2, ... pn, separated by single spaces (1 ≤ pi ≤ 10000), where pi stands for the price offered by the i-th bidder.

Output
The single output line should contain two integers: index of the winner and the price he will pay. Indices are 1-based.

Sample test(s)
input
2
5 7
output
2 5
input
3
10 2 8
output
1 8
input
6
3 8 2 9 4 14
output
6 9

*/