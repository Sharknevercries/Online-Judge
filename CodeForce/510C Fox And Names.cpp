/* 9682923	2015-02-02 20:05:42	Shark	512A - Fox And Names	GNU C++	Accepted	30 ms	100 KB */
#include<bits\stdc++.h>
using namespace std;
int in[26];
bool V[26];
vector<int> E[26];
string S[105];
bool deal(int a, int b){
	for (int i = 0; i < S[a].length() && i < S[b].length(); i++){
		if (S[a][i] == S[b][i])	
			continue;
		else{
			in[S[b][i] - 'a']++;
			E[S[a][i] - 'a'].push_back(S[b][i] - 'a');
			return true;
		}
	}
	if (S[a].length() > S[b].length())
		return false;
	else
		return true;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> S[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (!deal(i, j)){
				cout << "Impossible" << endl;
				return 0;
			}
	queue<int> Q;
	for (int i = 0; i < 26; i++)
		if (in[i] == 0)
			Q.push(i), V[i] = true;
	string ans = "";
	while (!Q.empty()){
		int cur = Q.front();
		Q.pop();
		ans.push_back('a' + cur);
		for (int i = 0; i < E[cur].size(); i++){
			if (!V[E[cur][i]]){
				in[E[cur][i]]--;
				if (in[E[cur][i]] == 0)
					V[E[cur][i]] = true, Q.push(E[cur][i]);
			}
		}
			
	}
	if (ans.length() != 26)
		cout << "Impossible" << endl;
	else
		cout << ans << endl;
	return 0;
}
/*

A. Fox And Names
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel is going to publish a paper on FOCS (Foxes Operated Computer Systems, pronounce: "Fox"). She heard a rumor: the authors list on the paper is always sorted in the lexicographical order.

After checking some examples, she found out that sometimes it wasn't true. On some papers authors' names weren't sorted in lexicographical order in normal sense. But it was always true that after some modification of the order of letters in alphabet, the order of authors becomes lexicographical!

She wants to know, if there exists an order of letters in Latin alphabet such that the names on the paper she is submitting are following in the lexicographical order. If so, you should find out any such order.

Lexicographical order is defined in following way. When we compare s and t, first we find the leftmost position with differing characters: si ≠ ti. If there is no such position (i. e. s is a prefix of t or vice versa) the shortest string is less. Otherwise, we compare characters si and ti according to their order in alphabet.

Input
The first line contains an integer n (1 ≤ n ≤ 100): number of names.

Each of the following n lines contain one string namei (1 ≤ |namei| ≤ 100), the i-th name. Each name contains only lowercase Latin letters. All names are different.

Output
If there exists such order of letters that the given names are sorted lexicographically, output any such order as a permutation of characters 'a'–'z' (i. e. first output the first letter of the modified alphabet, then the second, and so on).

Otherwise output a single word "Impossible" (without quotes).

Sample test(s)
input
3
rivest
shamir
adleman
output
bcdefghijklmnopqrsatuvwxyz
input
10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooooooo
subscriber
rowdark
tankengineer
output
Impossible
input
10
petr
egor
endagorion
feferivan
ilovetanyaromanova
kostka
dmitriyh
maratsnowbear
bredorjaguarturnik
cgyforever
output
aghjlnopefikdmbcqrstuvwxyz
input
7
car
care
careful
carefully
becarefuldontforgetsomething
otherwiseyouwillbehacked
goodluck
output
acbdefhijklmnogpqrstuvwxyz

*/