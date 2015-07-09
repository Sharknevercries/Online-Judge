/* 13966062	10602	Editor Nottoobad	Accepted	C++	0.022	2014-07-30 07:44:36 */
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
vector<string> word;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		word.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			word.push_back(tmp);
		}
		sort(word.begin(), word.end());
		int ans = word[0].length();
		for (int i = 1, j; i < n; i++){
			for (j = 0; j < word[i].length(); j++)
				if (word[i - 1][j] != word[i][j])
					break;
			ans += word[i].length() - j;
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; i++)
			cout << word[i] << endl;
	}
	return 0;
}
/*

Problem C
EDITOR NOTTOOBAD

Company Macrohard has released it’s new version of editor Nottoobad, which can understand a few voice commands. Unfortunately, there are only two voice commands that it can understand – “repeat the last word”, “delete the last symbol”. However, when one uses “repeat the last word” the editor inserts a blank that separates the words. But the company claims that it is possible to type much faster – simply by less number of presses. For example, such a phrase like “this thin thing” requires only 6 presses of the keyboard.

Action
Number
of presses
Content of the document
Press "this"
4
This
Say “repeat the last word”
0
this this
Say “delete the last symbol”
0
this thi
Press "n"
1
this thin
Say “repeat the last word”
0
this thin thin
Press "g"
1
this thin thing

In order to increase the popularity of it’s product the company decided to organize a contest where the winner will be a person who types a given number of words with minimum number of presses. Moreover, the first word must be typed first, and all the others can be typed in arbitrary order. So, if words “apple”, “plum” and “apricote” must be typed, the word “apple” must be typed first, and the words “plum” and “apricote” can be switched. And the most important for you – you are going to take part in the contest and you have a good friend in the company, who told you the word which will be used in the contest. You want be a winner J, so you have to write a program which finds the order of the words, where the number of presses will be minimum.

Input
The first line of the input contains the T (1≤T≤15) the number of test cases. Then T test cases follow. The first line of each test contains a number N (1≤N≤100) – the number of words that must be pressed. Next N lines contain words – sequences of small Latin letters, not longer than 100 symbols. Remember that the first word must be pressed first!

Output
The first line of the output contains number X - the minimum number of presses, which one has to do in order to type all the words using editor Nottoobad. Next N lines contain the words in that minimum order. If there are several solutions, you can output one of them.

Sample Input
Sample Output
3
3
this
thin
thing
4
popcorn
apple
apricote
plum
2
hello
hello
6
this
thin
thing
21
popcorn
plum
apricote
apple
5
hello
hello

Problem source: Russian National Team Olympiad 2000
Problem author: Andrew Stankevich
Problem translation: Dmytro Chernysh
Problem solution: Andrew Stankevich, Dmytro Chernysh

*/