/* 13066413	12394	Peer Review	Accepted	C++	0.032	2014-02-01 09:57:34 */
#include<cstdio>
#include<cstring>
struct paper{
	char name[15];
	int request[5];
	bool violation;
};
int main(){
	int K, N;
	while (scanf("%d%d", &K, &N) == 2){
		if (K == 0 && N == 0)
			break;
		struct paper P[1001];
		int review[1001] = { 0 };
		int ans = 0;
		for (int i = 1; i <= N; i++){
			scanf("%s", P[i].name);
			for (int j = 0; j < K; j++)
				scanf("%d", &P[i].request[j]);
			P[i].violation = false;
		}
		for (int i = 1; i <= N; i++){
			bool V[1001] = { false };
			for (int j = 0; j < K; j++){
				int ptr = P[i].request[j];
				if (strcmp(P[i].name, P[ptr].name) == 0)
					P[ptr].violation = true;
				if (V[ptr])
					P[ptr].violation = true;
				review[ptr]++;
				V[ptr] = true;
			}
		}
		for (int i = 1; i <= N; i++){
			if (review[i] != K)
				ans++;
			else if (P[i].violation)
				ans++;
		}
		if (ans == 0)
			printf("NO PROBLEMS FOUND\n");
		else if (ans == 1)
			printf("1 PROBLEM FOUND\n");
		else
			printf("%d PROBLEMS FOUND\n", ans);
	}
	return 0;
}
/*

Peer Review
For scientific conferences, scientists submit papers presenting their ideas, and then review each other's papers to make sure only good papers are presented at the conference. Each paper must be reviewed by several scientists, and scientists must not review papers written by people they collaborate with (including themselves), or review the same paper more than once.

You have been asked to write a program to check if your favorite conference is doing things right. Whether a paper is being reviewed too much, too little, or by the wrong people - the organizers must know before it is too late!

Input

The first line in each test case has two integers, K ( 2$ \le$K$ \le$5) and N ( 1$ \le$N$ \le$1000). K is the number of reviews that each paper will receive, while N is the number of papers to be reviewed. The conference only accepts papers with a single author, and authors can only present a single paper at the conference.

Each of the next N lines describes an author and includes the name of the institution to which the author belongs, followed by the list of the K papers he or she has been requested to review. It is assumed that researchers from the same institution collaborate with each other, whereas researchers from different institutions don't. All institution names are shorter than 10 characters, and contain only upper or lowercase letters and no whitespace. Since we have as many papers as authors, papers are identified by their author's index; paper 1 was written by the first author in the list, and paper N was written by the last author.

The end of the test cases is marked with a line containing K = 0 and N = 0. You should generate no output for this line.

Output

For each test case, your program should output NO PROBLEMS FOUND (if all rules are being followed) or P PROBLEMS FOUND, where P is the number of rule violations found (counting at most 1 violation per paper). If there is exactly one rule violation overall, your program should output 1 PROBLEM FOUND.

Sample Input

2 3
UCM 2 3
UAM 1 3
UPM 1 2
2 3
UCM 2 3
UAM 1 2
UPM 2 2
0 0
Sample Output

NO PROBLEMS FOUND
3 PROBLEMS FOUND

*/