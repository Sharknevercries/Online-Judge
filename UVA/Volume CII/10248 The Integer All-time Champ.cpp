/* 15345501	10248	The Integer All-time Champ	Accepted	C++	0.032	2015-04-18 15:59:49 */
#include<bits\stdc++.h>
using namespace std;
int G[15][15];
int in[15], out[15];
char path[10005];
int ptr;
bool V[10];
void DFS(int cur){
	V[cur] = true;
	path[ptr++] = '0' + cur;
	bool found = false;
	for (int i = 0; i < 10 && !found; i++){
		if (G[cur][i] > 0 && out[i] > 0){
			in[i]--, out[cur]--;
			G[cur][i]--;
			DFS(i);
			found = true;
		}
	}
	for (int i = 0; i < 10 && !found; i++){
		if (G[cur][i] > 0){
			in[i]--, out[cur]--;
			G[cur][i]--;
			DFS(i);
			found = true;
		}
	}
}
void eularPath(){
	while (true){
		int s = -1;
		for (int i = 0; i < 10 && s == -1; i++)
			if (out[i] > in[i])
				s = i;
		for (int i = 0; i < 10 && s == -1; i++)
			if (out[i] > 0)
				s = i;
		if (s == -1)break;
		DFS(s);
	}
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		memset(G, 0, sizeof(G));
		memset(V, false, sizeof(V));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int i = max(10, n); i <= m; i++){
			G[i / 10][i % 10]++;
			in[i % 10]++, out[i / 10]++;
		}
		ptr = 0;
		eularPath();
		for (int i = n; i <= m && i < 10; i++)
			if (!V[i])
				path[ptr++] = '0' + i;
		path[ptr++] = '\0';
		puts(path);
	}
	return 0;
}
/*

As Alan Turing and his friend David Champernowne gave the name “The All-time Champ” number
(as a joke with the David surname) to the trascendental constant 0.1234567891011 . . . obtained by
concatenating the positive integers and interpreting them as decimal digits to the right of a decimal
point, let us nominate “All-time Champ Integers” to the numbers constructed by concatenating the
digits of a set of consecutive integers.
Given two natural numbers 0 < m ≤ n, there is a such integer, but there are other natural numbers
that contain, as substrings, all the numbers between m and n, both included. For example for m = 1
and n = 13, possible solutions are 12345678910111213 (the corresponding “Champ”), 1011213456789
or 1101213456789. We can see that the last two numbers have only 13 digits as against the 17 of the
“Champ”.
Your task is to find out the shortest such integer.
Input
The input file contains several lines of input. Each line contains two natural numbers m and n(0 <
m ≤ n < 100). Input is terminated by end of file.
Output
For each line of input produce one line of output. This line contain the shortest integer that contains
as substring all the numbers between m and n (both included). There may be more than one solution.
We will accept any one of the solutions.
Sample Input
1 13
1 4
13 14
11 12
Sample Output
1101213456789
1234
1314
112

*/