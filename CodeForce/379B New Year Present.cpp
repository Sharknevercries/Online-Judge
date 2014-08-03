/* 5590407	 Dec 31, 2013 11:58:44 AM	Shark	 379B - New Year Present	 GNU C++	Happy New Year!	15 ms	0 KB */
#include<cstdio>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[300], total = 0;
		int pos = 0, way = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", M + i);
			total += M[i];
		}
		while (true){
			if (M[pos] > 0){
				M[pos]--, total--;
				putchar('P');
			}
			if (total == 0)
				break;
			if (way == 0){
				if (pos + 1 < n)
					pos++,putchar('R');
				else
					way = 1, pos--, putchar('L');
			}
			else{
				if (pos - 1 >= 0)
					pos--, putchar('L');
				else
					way = 0, pos++, putchar('R');
			}
		}
		putchar('\n');
	}
	return 0;
}
/*

B. New Year Present
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The New Year is coming! That's why many people today are busy preparing New Year presents. Vasily the Programmer is no exception.

Vasily knows that the best present is (no, it's not a contest) money. He's put n empty wallets from left to right in a row and decided how much money to put in what wallet. Vasily decided to put ai coins to the i-th wallet from the left.

Vasily is a very busy man, so the money are sorted into the bags by his robot. Initially, the robot stands by the leftmost wallet in the row. The robot can follow instructions of three types: go to the wallet that is to the left of the current one (if such wallet exists), go to the wallet that is to the right of the current one (if such wallet exists), put a coin to the current wallet. Due to some technical malfunctions the robot cannot follow two "put a coin" instructions in a row.

Vasily doesn't want to wait for long, so he wants to write a program for the robot that contains at most 106 operations (not necessarily minimum in length) the robot can use to put coins into the wallets. Help him.

Input
The first line contains integer n (2 ≤ n ≤ 300) — the number of wallets. The next line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 300).

It is guaranteed that at least one ai is positive.

Output
Print the sequence that consists of k (1 ≤ k ≤ 106) characters, each of them equals: "L", "R" or "P". Each character of the sequence is an instruction to the robot. Character "L" orders to move to the left, character "R" orders to move to the right, character "P" orders the robot to put a coin in the wallet. The robot is not allowed to go beyond the wallet line. In other words, you cannot give instructions "L" if the robot is at wallet 1, or "R" at wallet n.

As a result of the performed operations, the i-th wallet from the left must contain exactly ai coins. If there are multiple answers, you can print any of them.

Sample test(s)
input
2
1 2
output
PRPLRP
input
4
0 2 0 2
output
RPRRPLLPLRRRP

*/