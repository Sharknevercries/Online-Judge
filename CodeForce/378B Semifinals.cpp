/* 5568005	 Dec 30, 2013 2:01 : 56 PM	Shark	 378B - Semifinals	 GNU C++	Accepted	62 ms	1000 KB */
#include<cstdio>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int A[100000], B[100000];
		bool result[100000][2] = { false };
		for (int i = 0; i < n; i++)
			scanf("%d%d", A + i, B + i);
		for (int i = 0; i < n / 2; i++)
			result[i][0] = result[i][1] = true;
		for (int count = 0, ptrA = 0, ptrB = 0; count < n; count++){
			if (ptrA < n && ptrB < n){
				if (A[ptrA] > B[ptrB])
					result[ptrB++][1] = true;
				else
					result[ptrA++][0] = true;
			}
			else{
				if (ptrA < n)	result[ptrA++][0] = true;
				if (ptrB < n)	result[ptrB++][1] = true;
			}
		}
			
		for (int j = 0; j < 2; j++){
			for (int i = 0; i < n; i++)
				printf("%d", (int)result[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
/*

B. Semifinals
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Two semifinals have just been in the running tournament. Each semifinal had n participants. There are n participants advancing to the finals, they are chosen as follows: from each semifinal, we choose k people (0 ≤ 2k ≤ n) who showed the best result in their semifinals and all other places in the finals go to the people who haven't ranked in the top k in their semifinal but got to the n - 2k of the best among the others.

The tournament organizers hasn't yet determined the k value, so the participants want to know who else has any chance to get to the finals and who can go home.

Input
The first line contains a single integer n (1 ≤ n ≤ 105) — the number of participants in each semifinal.

Each of the next n lines contains two integers ai and bi (1 ≤ ai, bi ≤ 109) — the results of the i-th participant (the number of milliseconds he needs to cover the semifinals distance) of the first and second semifinals, correspondingly. All results are distinct. Sequences a1, a2, ..., an and b1, b2, ..., bn are sorted in ascending order, i.e. in the order the participants finished in the corresponding semifinal.

Output
Print two strings consisting of n characters, each equals either "0" or "1". The first line should correspond to the participants of the first semifinal, the second line should correspond to the participants of the second semifinal. The i-th character in the j-th line should equal "1" if the i-th participant of the j-th semifinal has any chances to advance to the finals, otherwise it should equal a "0".

Sample test(s)
input
4
9840 9920
9860 9980
9930 10020
10040 10090
output
1110
1100
input
4
9900 9850
9940 9930
10000 10020
10060 10110
output
1100
1100
Note
Consider the first sample. Each semifinal has 4 participants. The results of the first semifinal are 9840, 9860, 9930, 10040. The results of the second semifinal are 9920, 9980, 10020, 10090.

If k = 0, the finalists are determined by the time only, so players 9840, 9860, 9920 and 9930 advance to the finals.
If k = 1, the winners from both semifinals move to the finals (with results 9840 and 9920), and the other places are determined by the time (these places go to the sportsmen who run the distance in 9860 and 9930 milliseconds).
If k = 2, then first and second places advance from each seminfial, these are participants with results 9840, 9860, 9920 and 9980 milliseconds.

*/