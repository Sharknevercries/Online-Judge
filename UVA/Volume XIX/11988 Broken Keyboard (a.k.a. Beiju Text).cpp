/* 13997300	11988	Broken Keyboard (a.k.a. Beiju Text)	Accepted	C++	0.248	2014-08-06 06:58:56 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
#include<list>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
struct node{
	char ch;
	node *next, *prev;
};
node *a, *b, *cur;
void insert(char ch){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->ch = ch, newnode->next = newnode->prev = NULL;
	if (cur == NULL){
		a = newnode, b = (node*)malloc(sizeof(node));
		b->ch = '\0';
		a->next = cur = b, b->next = NULL, b->prev = a;
	}
	else{
		if (cur->prev != NULL){
			newnode->next = cur, newnode->prev = cur->prev;
			cur->prev->next = newnode, cur->prev = newnode;
		}
		else
			newnode->next = cur, cur->prev = newnode, a = newnode;
	}
}
void del(node *cur){
	if (cur->next != NULL)
		del(cur->next);
	free(cur);
}
int main(){
	char S[100005];
	while (gets(S)){
		a = b = cur = NULL;
		for (int i = 0; S[i] != '\0'; i++){
			if (S[i] == '[')
				cur = a;
			else if (S[i] == ']')
				cur = b;
			else
				insert(S[i]);
		}
		for (node *ptr = a; ptr != b; ptr = ptr->next)
			putchar(ptr->ch);
		putchar('\n');
		del(a);
	}
	return 0;
}
/*

Problem B

Broken Keyboard (a.k.a. Beiju Text)

You're typing a long text with a broken keyboard. Well it's not so badly broken. The only problem with the keyboard is that sometimes the "home" key or the "end" key gets automatically pressed (internally).

You're not aware of this issue, since you're focusing on the text and did not even turn on the monitor! After you finished typing, you can see a text on the screen (if you turn on the monitor).

In Chinese, we can call it Beiju. Your task is to find the Beiju text.

Input

There are several test cases. Each test case is a single line containing at least one and at most 100,000 letters, underscores and two special characters '[' and ']'. '[' means the "Home" key is pressed internally, and ']' means the "End" key is pressed internally. The input is terminated by end-of-file (EOF). The size of input file does not exceed 5MB.

Output

For each case, print the Beiju text on the screen.

Sample Input

This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
Output for the Sample Input

BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
Rujia Liu's Present 3: A Data Structure Contest Celebrating the 100th Anniversary of Tsinghua University
Special Thanks: Yiming Li
Note: Please make sure to test your program with the gift I/O files before submitting!

*/