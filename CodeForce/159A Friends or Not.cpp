/* 4857154	 Oct 24, 2013 10:11:47 AM	Shark	 159A - Friends or Not	 GNU C++	Accepted	62 ms	100 KB */
#include<stdio.h>
#include<string.h>
struct data{
	char A[21];
	char B[21];
	int time;
};
struct data S[1000];
struct data ans[1000];
int ptr;
void printIntoAns(char *A,char *B){
	int i;
	for(i=0;i<ptr;i++)
		if( (!strcmp(A,ans[i].A)&&!strcmp(B,ans[i].B))||(!strcmp(A,ans[i].B)&&!strcmp(B,ans[i].A)) )
			break;
	if( i>=ptr ){
		strcpy(ans[ptr].A,A);
		strcpy(ans[ptr].B,B);
		ptr++;
	}
}
int main(){
	int n,d;
	while( scanf("%d%d",&n,&d)==2 ){
		for(int i=0;i<n;i++)
			scanf("%s%s%d",S[i].A,S[i].B,&S[i].time);
		ptr=0;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				char *A1=S[i].A;
				char *B1=S[i].B;
				char *A2=S[j].A;
				char *B2=S[j].B;
				if( (!strcmp(A1,B2)&&!strcmp(B1,A2))&&S[j].time-S[i].time<=d&&S[j].time-S[i].time>0 )
					printIntoAns(A1,B1);
			}
		printf("%d\n",ptr);
		for(int i=0;i<ptr;i++)
			printf("%s %s\n",ans[i].A,ans[i].B);
	}
	return 0;
}
/*

A. Friends or Not
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus has a hobby — he develops an unusual social network. His work is almost completed, and there is only one more module to implement — the module which determines friends. Oh yes, in this social network one won't have to add friends manually! Pairs of friends are deduced in the following way. Let's assume that user A sent user B a message at time t1, and user B sent user A a message at time t2. If 0 < t2 - t1 ≤ d, then user B's message was an answer to user A's one. Users A and B are considered to be friends if A answered at least one B's message or B answered at least one A's message.

You are given the log of messages in chronological order and a number d. Find all pairs of users who will be considered to be friends.

Input
The first line of the input contains two integers n and d (1 ≤ n, d ≤ 1000). The next n lines contain the messages log. The i-th line contains one line of the log formatted as "Ai Bi ti" (without the quotes), which means that user Ai sent a message to user Bi at time ti (1 ≤ i ≤ n). Ai and Bi are non-empty strings at most 20 characters long, consisting of lowercase letters ('a' ... 'z'), and ti is an integer (0 ≤ ti ≤ 10000). It is guaranteed that the lines are given in non-decreasing order of ti's and that no user sent a message to himself. The elements in the lines are separated by single spaces.

Output
In the first line print integer k — the number of pairs of friends. In the next k lines print pairs of friends as "Ai Bi" (without the quotes). You can print users in pairs and the pairs themselves in any order. Each pair must be printed exactly once.

Sample test(s)
input
4 1
vasya petya 1
petya vasya 2
anya ivan 2
ivan anya 4
output
1
petya vasya
input
1 1000
a b 0
output
0
Note
In the first sample test case Vasya and Petya are friends because their messages' sending times are one second apart. Anya and Ivan are not, because their messages' sending times differ by more than one second.

*/