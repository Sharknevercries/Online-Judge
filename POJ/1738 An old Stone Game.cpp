/* 13931164	840502	1738	Accepted	22940K	2891MS	G++	1406B	2015-03-05 17:33:42 */
#include<bits\stdc++.h>
using namespace std;
int m[50005], n;
struct Node{
	int value;
	Node *next, *prev;
	Node(int value) :value(value){
		next = prev = NULL;
	}
	Node(){}
};
Node *head, *last;
int main(){
	while (scanf("%d", &n) == 1 && n){
		head = last = NULL;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", m + i);
		m[0] = m[n + 1] = 1e9;
		int size = n + 2;
		for (int i = 0; i <= n + 1; i++){
			Node *newNode = new Node(m[i]);
			if (head == NULL)
				head = newNode, last = head;
			else{
				last->next = newNode;
				newNode->prev = last;
				last = last->next;
			}
		}
		while (size > 3){
			Node *cur = head, *k;
			while (!cur->prev || cur->prev->value > cur->next->value)	cur = cur->next;
			int tmp = cur->prev->value + cur->value;
			cur->next->prev = cur->prev->prev;
			cur->prev->prev->next = cur->next;
			k = cur->prev->prev;
			cur = new Node(tmp);
			while (k->value <= tmp)
				k = k->prev;
			cur->next = k->next;
			cur->prev = k;
			k->next->prev = cur;
			k->next = cur;
			cur = cur->prev;
			ans += tmp;
			size--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

An old Stone Game
Time Limit: 5000MS		Memory Limit: 30000K
Total Submissions: 2875		Accepted: 755
Description

There is an old stone game.At the beginning of the game the player picks n(1<=n<=50000) piles of stones in a line. The goal is to merge the stones in one pile observing the following rules:
At each step of the game,the player can merge two adjoining piles to a new pile.The score is the number of stones in the new pile.
You are to write a program to determine the minimum of the total score.
Input

The input contains several test cases. The first line of each test case contains an integer n, denoting the number of piles. The following n integers describe the number of stones in each pile at the beginning of the game.
The last test case is followed by one zero.
Output

For each test case output the answer on a single line.You may assume the answer will not exceed 1000000000.
Sample Input

1
100
3
3 4 3
4
1 1 1 1
0
Sample Output

0
17
8
Source

LouTiancheng@POJ

*/