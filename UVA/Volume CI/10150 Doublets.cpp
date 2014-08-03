/* 13197585	10150	Doublets	Accepted	C++	0.922	2014-02-23 12:33:14 */
#include<cstdio>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
vector<int> con[30000];
char voc[30000][20];
int len[30000];
int path[30000];
bool V[30000];
char A[20], B[20];
int start, dest;
int ptr;
bool BFS(){
	queue<int> Q;
	start = dest = -1;
	memset(V, false, sizeof(V));
	for (int i = 0; i < ptr; i++)
		path[i] = -1;
	for (int i = 0; i < ptr; i++){
		if (strcmp(A, voc[i]) == 0){
			Q.push(i);
			V[i] = true;
			start = i;
		}
	}
	for (int i = 0; i < ptr; i++){
		if (strcmp(B, voc[i]) == 0)
			dest = i;
	}
	if (dest == -1)
		return false;
	while (!Q.empty()){
		int cur = Q.front();	Q.pop();
		if (cur == dest)
			return true;
		for (int i = 0; i < con[cur].size(); i++){
			if (!V[con[cur][i]]){
				Q.push(con[cur][i]);
				path[con[cur][i]] = cur;
				V[con[cur][i]] = true;
			}
		}
	}
	return false;
}
int main(){
	bool first = true;
	char str[20];
	ptr = 0;
	while (gets(str) && sscanf(str, "%s", voc[ptr++]) == 1);
	
	for (int i = 0; i < ptr; i++)
		len[i] = strlen(voc[i]);
	for (int i = 0; i < ptr; i++){
		for (int j = i + 1; j < ptr; j++){
			int count = 0;
			if (len[i] != len[j])
				continue;
			for (int k = 0; k < len[i] && k < len[j]; k++){
				if (voc[i][k] != voc[j][k])
					count++;
				if (count>1)
					break;
			}
			if (count == 1){
				con[i].push_back(j);
				con[j].push_back(i);
			}
		}
	}
	while (scanf("%s%s", A, B) == 2){
		if (!first)
			putchar('\n');
		first = false;
		if (strlen(A) == strlen(B) && BFS()){
			int k = dest, s = 0, record[30000];
			while (k != -1){
				record[s++] = k;
				k = path[k];
			}
			for (k = s - 1; k >= 0; k--)
				printf("%s\n", voc[record[k]]);
		}
		else
			puts("No solution.");
	}
	return 0;
}
/*

Problem B: Doublets

A Doublet is a pair of words that differ in exactly one letter; for example, "booster" and "rooster" or "rooster" and "roaster" or "roaster" and "roasted".
You are given a dictionary of up to 25143 lower case words, not exceeding 16 letters each. You are then given a number of pairs of words. For each pair of words, find the shortest sequence of words that begins with the first word and ends with the second, such that each pair of adjacent words is a doublet. For example, if you were given the input pair "booster" and "roasted", a possible solution would be: ("booster", "rooster", "roaster", "roasted") provided that these words are all in the dictionary.

The Input

Input consists of the dictionary followed by a number of word pairs. The dictionary consists of a number of words, one per line, and is terminated by an empty line. The pairs of input words follow; the words of each pair occur on a line separated by a space.
The Output

For each input pair, print a set of lines starting with the first word and ending with the last. Each pair of adjacent lines must be a doublet. If there are several minimal solutions, any one will do. If there is no solution, print a line: "No solution." Leave a blank line between cases.
Sample Input

booster
rooster
roaster
coasted
roasted
coastal
postal

booster roasted
coastal postal
Output for Sample Input

booster
rooster
roaster
roasted

No solution.

*/