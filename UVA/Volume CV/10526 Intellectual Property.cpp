/* 15093094	10526	Intellectual Property	Accepted	C++	0.082	2015-03-06 14:28:58 */
#include<bits\stdc++.h>
using namespace std;
struct Answer{
	int pos, len;
	Answer(int pos, int len) :pos(pos), len(len){}

};
int limit, mid;
char s[300000], str[300000];
int sa[300000], height[300000];
int tmp[2][300000];
int c[300000];
int n;
void concat(char t[]){
	for (int i = 0; t[i] != '\0'; i++)
		s[n++] = t[i];
	s[n++] = '\n';
}
bool cmpPos(Answer A, Answer B){
	if (A.pos == B.pos)
		return A.len > B.len;
	return A.pos < B.pos;
}
bool cmpLen(Answer A, Answer B){
	if (A.len == B.len)
		return A.pos < B.pos;
	return A.len > B.len;
}
void buildSA(int m){
	// suffix array
	int *rank = tmp[0], *sa2 = tmp[1];
	for (int i = 0; i < m; i++)	c[i] = 0;
	for (int i = 0; i < n; i++)	c[rank[i] = s[i]]++;
	for (int i = 1; i < m; i++)	c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)	sa[--c[s[i]]] = i;
	for (int i = 1; i < n; i *= 2){
		int r = 0;
		for (int j = n - i; j < n; j++)	sa2[r++] = j;
		for (int j = 0; j < n; j++)
			if (sa[j] >= i)
				sa2[r++] = sa[j] - i;
		for (int j = 0; j < m; j++)	c[j] = 0;
		for (int j = 0; j < n; j++)	c[rank[sa2[j]]]++;
		for (int j = 1; j < m; j++)	c[j] += c[j - 1];
		for (int j = n - 1; j >= 0; j--)	sa[--c[rank[sa2[j]]]] = sa2[j];
		int *&newRank = sa2;
		newRank[sa[0]] = r = 0;
		for (int j = 1; j < n; j++){
			if (!(rank[sa[j - 1]] == rank[sa[j]] && rank[sa[j - 1] + i] == rank[sa[j] + i]))
				r++;
			newRank[sa[j]] = r;
		}
		swap(rank, sa2);
		if (r == n - 1)	break;
		m = r + 1;
	}
	// height
	for (int i = 0; i < n; i++)	rank[sa[i]] = i;
	for (int i = 0, k = 0; i < n - 1; i++){
		if (k) k--;
		int j = sa[rank[i] - 1];
		while (s[i + k] == s[j + k])k++;
		height[rank[i]] = k;
	}
}
void solve(){
	memset(c, 0, sizeof(c));
	for (int i = 0, k = 0; i < n; i++){
		if (sa[i] < mid)
			k = height[i + 1];
		else{
			k = min(height[i], k);
			c[i] = max(c[i], k);
		}
	}
	for (int i = n - 1, k = 0; i >= 0; i--){
		if (sa[i] < mid)
			k = height[i];
		else{
			c[i] = max(c[i], k);
			k = min(height[i], k);
		}
	}
	vector<Answer> L, ans;
	for (int i = 0; i < n; i++)
		if (c[i] >= 1)
			L.push_back(Answer(sa[i], c[i]));
	sort(L.begin(), L.end(), cmpPos);
	for (int i = 0, k = -1; i < L.size(); i++){
		if (L[i].pos + L[i].len <= k)
			continue;
		ans.push_back(L[i]);
		k = L[i].pos + L[i].len;
	}
	sort(ans.begin(), ans.end(), cmpLen);
	for (int i = 0; i < limit && i < ans.size(); i++){
		printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n", i + 1, ans[i].len, ans[i].pos - mid);
		for (int j = 0; j < ans[i].len; j++)
			putchar(s[ans[i].pos + j]);
		printf("\n");
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ca = 1;
	while (scanf("%d", &limit) == 1 && limit){
		if (ca > 1)	putchar('\n');
		printf("CASE %d\n", ca++);
		gets(str);
		n = 0;
		gets(str);
		while (gets(str) && strcmp(str, "END TDP CODEBASE"))
			concat(str);
		gets(str);
		s[n++] = 1;
		mid = n;
		while (gets(str) && strcmp(str, "END JCN CODEBASE"))
			concat(str);
		s[n++] = '\0';
		buildSA(256);
		solve();
	}
	return 0;
}
/*


Problem A: Intellectual Property

TDP Inc. has decided to sue JCN Inc. for copyright infringement. To this end, TDP wishes to find infringing segments within JCN's code base, to show to selected media representatives. Since TDP has fired all its technical staff, it is looking to hire a consultant to be paid on a contingency basis should the lawsuit be successful. To demonstrate your qualifications for this position, you are to solve the problem on a number of test cases.
Each test case begins with a positive integer k, the number of infringing segments to be found. Following this line are two code bases. The first code base is preceded by the line "BEGIN TDP CODEBASE" and contains a number of lines followed by the line "END TDP CODEBASE". The second code base is preceded by "BEGIN JCN CODEBASE" and followed by "END JCN CODEBASE". The line "END TDP CODEBASE" does not appear in the first code base and the line "END JCN CODEBASE" does not appear in the second. A line containing 0 follows the last test case.

For each test case you should output: (1) a line containing "CASE n" where n is the number of the test case; (2) up to k infringing segments. Each segment should be printed exactly as it appears in the JCN code base (including newlines and whitespace) and should be preceded by a line containing "INFRINGING SEGMENT m LENGTH l POSITION p" where m is the number of the segment within the test case, l is the length of the segment (in characters) and p is the position of the segment (in characters from the start of the JCN codebase). Output an empty line between test cases.

A code base is simply a string of characters. An infringing segment is a non-empty contiguous sequence of characters in the JCN code base that is textually identical to some contiguous sequence of characters in the TDP code base, and is not contained in a larger infringing segment. You should consider all characters in the code base, including spaces and the newline character at the end of each line.

If there are k or fewer common segments, print them all in decreasing order by length; if several segments have the same length, print them in the order they occur in JCN's code base. If there are more than k segments, print the first k according to the given order.

You may assume that no code base contains more than 50,000 characters.

Sample Input

6
BEGIN TDP CODEBASE
the quick brown fox
jumps over the lazy dog.
so there!
END TDP CODEBASE
BEGIN JCN CODEBASE
now is the time for all
good men to come to the aid
of the party.
so there!
END JCN CODEBASE
100
BEGIN TDP CODEBASE
xyzzy
END TDP CODEBASE
BEGIN JCN CODEBASE
xyzzabczzyy
END JCN CODEBASE
0
Output for Sample Input

CASE 1
INFRINGING SEGMENT 1 LENGTH 12 POSITION 64
.
so there!

INFRINGING SEGMENT 2 LENGTH 5 POSITION 6
the
INFRINGING SEGMENT 3 LENGTH 5 POSITION 42
o the
INFRINGING SEGMENT 4 LENGTH 5 POSITION 43
the
INFRINGING SEGMENT 5 LENGTH 5 POSITION 54
the
INFRINGING SEGMENT 6 LENGTH 3 POSITION 15
fo

CASE 2
INFRINGING SEGMENT 1 LENGTH 4 POSITION 0
xyzz
INFRINGING SEGMENT 2 LENGTH 3 POSITION 7
zzy
INFRINGING SEGMENT 3 LENGTH 2 POSITION 10
y

G. Cormack

*/