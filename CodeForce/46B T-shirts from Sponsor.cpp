/* 5207840	 Nov 24, 2013 3:26:27 PM	Shark	 46B - T-shirts from Sponsor	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
int query(int M[], char S[]){
	int priority[5];
	if (strcmp("S", S) == 0)
		priority[0] = 0, priority[1] = 1, priority[2] = 2, priority[3] = 3, priority[4] = 4;
	else if (strcmp("M", S) == 0)
		priority[0] = 1, priority[1] = 2, priority[2] = 0, priority[3] = 3, priority[4] = 4;
	else if (strcmp("L", S) == 0)
		priority[0] = 2, priority[1] = 3, priority[2] = 1, priority[3] = 4, priority[4] = 0;
	else if (strcmp("XL", S) == 0)
		priority[0] = 3, priority[1] = 4, priority[2] = 2, priority[3] = 1, priority[4] = 0;
	else
		priority[0] = 4, priority[1] = 3, priority[2] = 2, priority[3] = 1, priority[4] = 0;
	for (int i = 0; i < 5; i++){
		if (M[priority[i]]>0){
			M[priority[i]]--;
			return priority[i];
		}
	}
}
int main(){
	int M[5], n;
	for (int i = 0; i < 5; i++)
		scanf("%d", &M[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char S[10];
		int result;
		scanf("%s", S);
		result = query(M, S);
		switch (result){
		case 4:	puts("XXL");	break;
		case 3:	puts("XL");	break;
		case 2:	puts("L");	break;
		case 1:	puts("M");	break;
		case 0:	puts("S");	break;
		}
	}
	return 0;
}
/*

B. T-shirts from Sponsor
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day a well-known sponsor of a well-known contest decided to give every participant of the contest a T-shirt as a present. A natural problem occurred: on the one hand, it is not clear how many T-shirts of what sizes should be ordered, and on the other hand, one doesn't want to order too many T-shirts (and we do not exactly paper the walls with the oversupply). After considerable brain racking and some pre-estimating, the sponsor representatives ordered a certain number of T-shirts of sizes S, M, L, XL and XXL. The T-shirts turned out to bring good luck, that's why on the contest day there built up a line of K participants willing to get one. Every contestant is characterized by his/her desired T-shirt size (so it happens that for all the participants it is also one of the sizes S, M, L, XL and XXL). The participants come up to get a T-shirt one by one and try to choose the most suitable one, choosing it like this. If there is still a T-shirt of the optimal size left, that he/she takes it without further ado. Otherwise the contestant would prefer to choose a T-shirt with the size as close to the optimal one as possible (the distance between neighboring sizes is considered equal to one). If the variant of choice is not unique, the contestant will take a T-shirt of a bigger size (in case he/she grows more). For example, for a person whose optimal size is L the preference list looks like this: L, XL, M, XXL, S. Using the data on how many T-shirts of every size had been ordered by the organizers, on the size of contestants in the line determine who got a T-shirt of what size.

Input
The first line contains five non-negative integers NS, NM, NL, NXL, NXXL not exceeding 1000 which represent the number of T-shirts of the corresponding sizes. The second line contains an integer K (1 ≤ K ≤ 1000) which represents the number of participants. The next K lines contain the optimal T-shirt sizes for the contestants. The sizes are given in the order in which the participants stand in the line. It is guaranteed that NS + NM + NL + NXL + NXXL ≥ K.

Output
For each contestant, print a line containing the size of the T-shirt he/she got.

Sample test(s)
input
1 0 2 0 1
3
XL
XXL
M
output
XXL
L
L

*/