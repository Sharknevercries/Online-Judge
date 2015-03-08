/* 15098945	10975	Dueue's Quiz	Accepted	C++	1.169	2015-03-07 14:29:02 */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	Node *next[26];
	int id;
	Node(){
		id = -1;
		memset(next, 0, sizeof(next));
	}
};
Node *root;
int d, q, n, m;
int mx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int my[] = { 1, -1, 1, 0, -1, 1, 0, -1 };
char table[105][105]; 
string word[15005];
int occur[15005];
map<string, int> ans;
void insert(string s, int id){
	Node *p = root;
	for (int i = 0; i < s.length(); i++){
		if (!p->next[s[i] - 'a'])
			p->next[s[i] - 'a'] = new Node();
		p = p->next[s[i] - 'a'];
	}
	p->id = id;
}
void release(Node *p){
	queue<Node*> Q;
	Q.push(p);
	while (!Q.empty()){
		Node *q = Q.front();
		Q.pop();
		for (int i = 0; i < 26; i++)
			if (q->next[i])
				Q.push(q->next[i]);
		delete q;
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--){
		printf("Test Case #%d\n", ca++);
		scanf("%d", &d);
		root = new Node();
		for (int i = 0; i < d; i++){
			cin >> word[i];
			insert(word[i], i);
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++){
			printf("Query #%d\n", i + 1);
			ans.clear();
			memset(occur, 0, sizeof(occur));
			scanf("%d%d", &n, &m);
			for (int j = 0; j < n; j++)
				scanf("%s", table[j]);
			for (int j = 0; j < n; j++){
				for (int k = 0; k < m; k++){
					for (int type = 0; type < 8; type++){
						int x = j, y = k;
						Node *p = root;
						while (p && x >= 0 && x < n&&y >= 0 && y < m){
							int c = table[x][y] - 'a';
							if (!p->next[c])	break;
							p = p->next[c];
							if (p->id != -1)
								occur[p->id]++;
							x += mx[type], y += my[type];
						}

					}
				}
			}
			for (int i = 0; i < d; i++)
				ans[word[i]] = occur[i];
			for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
				if (it->second > 0)
					cout << it->first << " " << it->second << endl;
		}
		putchar('\n');
		release(root);
	}
	return 0;
}
/*

Problem L
Dueue¡¦s Quiz
Hesam Dueue Bararie is the showman of a very popular TV quiz: ¡§Bararian Nights¡¨. In this quiz, there is a big table of letters with some words hidden in it among diagonal, vertical or horizontal directions. During the quiz, Dueue tells each one of the contestants a word and they must find the total number of occurrences of that word in the table.
Recently, Milk-Farhaad has decided to participate in this TV quiz and because cheating is permitted during this quiz (!), he wants you to help him by writing a computer program.
By the way, Milk-Farhaad has bought the whole dictionary and configurations of the table from Dueue. All he need is a computer program which calculates the total number of occurrences for each word of the dictionary in the table.
You can see one sample of this table in figure 1. All occurrences of the word ¡§hello¡¨ are circled in that. Also, the total number of occurrences of the word ¡§madam¡¨ is equal to 2 because it must be counted twice: one from left to right and the other one from right to left.



Figure 1. Dueue¡¦s Table

The Input
The first line of the input file is an integer which is the number of test cases. The first line of each test case is an integer  which is the number of words in the dictionary that should be used for this test case.  After that, comes D  lines each of which containing a word, having length of no more than 1000 characters, in the dictionary. Words are all constructed from lowercase letters: a¡Kz.
Then, comes a line containing an integer , the total number of queries for the test case. For each query, there will be two integerswhich are the number of rows and the number of columns of the table respectively. Next, there are M lines each one containing N characters representing the configuration of each table of the quiz.

The Output
For each test case, your program should write a line with the phrase ¡§Test Case #i¡¨ in which i is the index of the current test case starting from 1. Then comes the answer for each query in that test case. The answer to each query starts with a line containing the phrase ¡§Query #j¡¨. Then, all the words from dictionary which actually occurred in the table of that query should be listed one in each line (or each in one line!) together with their total number of occurrences in the given table. These words must be sorted in alphabetical order. There should be an empty line after the output for each test case.


Sample Input
1
4
hello
bye
one
two
2
3 3
bye
okk
res
3 3
one
wzq
too

Sample Output
Test Case #1
Query #1
bye 1
Query #2
one 1
two 1

Amirkabir University of Technology - Local Contest - Round #2

*/