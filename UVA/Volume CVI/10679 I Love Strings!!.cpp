/* 13240397	10679	I Love Strings!!	Accepted	C++	0.659	2014-03-01 09:59:52 */
#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct node{
    struct node *L[52], *suffix, *dic;
    int index;
    node(){
        for(int i = 0; i < 52; i++)
            L[i] = NULL;
        suffix = dic = NULL;
        index = -1;
    } ;
};
bool found[1000];
int equiv[1000];
struct node *root;
int n;
void add(string s, int index){
    struct node *cur = root;
    for(int i = 0; i < s.length(); i++){
		int ptr;
		if (s[i] >= 'A' && s[i] <= 'Z')
			ptr = s[i] - 'A';
		else
			ptr = s[i] - 'a' + 26;
        if(cur->L[ptr] == NULL)
            cur->L[ptr] = new node;
        cur = cur->L[ptr];
    }
    if(cur->index == -1)
        cur->index = index;
    else
        equiv[index] = cur->index;
}
void free(struct node *cur){
    for(int i = 0; i < 52; i++)
        if(cur->L[i] != NULL)
            free(cur->L[i]);
    delete cur;
}
void build(){
    queue<struct node*> Q;
    Q.push(root);
    while(!Q.empty()){
        struct node *cur = Q.front();
        Q.pop();
        for(int i = 0; i < 52; i++){
            if(cur->L[i] != NULL){
                struct node *target = cur->suffix;
                while(target != NULL && target->L[i] == NULL)
                    target = target->suffix;
                if(target != NULL)
                    cur->L[i]->suffix = target->L[i];
                else
                    cur->L[i]->suffix = root;

                target = cur->L[i]->suffix;
                if(target->index != -1)
                    cur->L[i]->dic = target;
                else
                    cur->L[i]->dic = target->dic;
                Q.push(cur->L[i]);
            }
        }
    }
}
void match(string s){
    struct node *cur = root;
    for(int i = 0; i < s.length(); i++){
		int ptr;
		if (s[i] >= 'A'&&s[i] <= 'Z')
			ptr = s[i] - 'A';
		else
			ptr = s[i] - 'a' + 26;
        while(cur != NULL && cur->L[ptr] == NULL)
            cur = cur->suffix;
        if(cur != NULL)
            cur = cur->L[ptr];
        else
            cur = root;
        for(struct node *next = cur; next != NULL; next = next->dic)
            if(next->index != -1)
                found[next->index] = true;
    }
}
int main(){ // AC algorithm
    int t;
    cin >> t;
    while(t--){
        memset(found, false, sizeof(found));
        memset(equiv, -1, sizeof(equiv));
        root = new node;
        string S;
        cin >> S >> n;
        for(int i = 0; i < n; i++){
            string Q;
            cin >> Q;
            add(Q, i);
        }
        build();
        match(S);
        free(root);
        for(int i = 0; i < n; i++){
            if(found[i] || (equiv[i] != -1 && found[equiv[i]]))
                puts("y");
            else
                puts("n");
        }
    }
    return 0;
}
/*

I love Strings!!!

Input / Output: standard I/O
Time Limit: 4 sec
Hmmmmmm¡K¡K¡K¡Kstrings again :) Then it must be an easy task for you. Well¡K¡Kyou are given with a string S of length not more than 100,000 characters (only ¡¥a¡¦-¡¥z¡¦ and ¡¥A¡¦ ¡V ¡¥Z¡¦). Then follows q (q < 1000) queries where each query contains a string T of maximum length 1,000 (also contains only ¡¥a¡¦-¡¥z¡¦ and ¡¥A¡¦ ¡V ¡¥Z¡¦). You should determine whether or not T is a substring of S.

Input
First line contains an integer k (k < 10) telling the number of test cases to follow. Each test case begins with S. It is followed by q. After this line there are q lines each of which has a string T as defined before.

Output
For each query print ¡¥y¡¦ if it is a substring of S or ¡¥n¡¦ otherwise followed by a new line. See the sample output below.

Sample Input
2
abcdefghABCDEFGH
2
abc
abAB
xyz
1
xyz

Sample Output
y
n
y

Mohammad Sajjad Hossain

*/