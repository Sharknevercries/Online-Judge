/* 9833508	2015-02-14 19:43:01	Shark	514A - Chewbaсca and Number	GNU C++	Accepted	15 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	char str[100];
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] >= '5' && str[i] <= '9'){
			if (i == 0 && str[i] == '9')	continue;
			str[i] = '0' + '9' - str[i];
		}
	}
	printf("%s\n", str);
	return 0;
}
/*

A. Chewbaсca and Number
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input
The first line contains a single integer x (1 ≤ x ≤ 1018) — the number that Luke Skywalker gave to Chewbacca.

Output
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Sample test(s)
input
27
output
22
input
4545
output
4444

*/