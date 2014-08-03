/* 5901267	 Feb 5, 2014 11:06:36 AM	Shark	 387C - George and Number	 GNU C++	Accepted	61 ms	3300 KB */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
bool bigThan(string A, string B){
	if (A.length() > B.length())	return true;
	if (A.length() < B.length())	return false;
	for (int i = 0; i < A.length(); i++){
		if (A[i] > B[i])	return true;
		if (A[i] < B[i])	return false;
	}
	return true;
}
int cal(string S){
	vector<string> Q;
	for (int i = 0; i < S.length(); i++){
		string tmp;
		tmp.push_back(S[i]);
		while (i + 1 < S.length() && S[i + 1] == '0')
			tmp.push_back(S[++i]);
		Q.push_back(tmp);
	}
	if (Q.size() == 1)
		return 1;
	while (true){
		int i; 
		for (i = 1; i < Q.size(); i++){
			if (!bigThan(Q[0], Q[i]))
				break;
		}
		if (i >= Q.size()){
			if (Q.size() == 1)
				return 1;
			else
				return cal(Q[0]) + Q.size() - 1;
		}
		else{
			Q[0] += Q[1];
			Q.erase(Q.begin() + 1);
		}
	}
}
int main(){
	string S;
	while (cin >> S){
		printf("%d\n", cal(S));
	}
	return 0;
}
/*

C. George and Number
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
George is a cat, so he really likes to play. Most of all he likes to play with his array of positive integers b. During the game, George modifies the array by using special changes. Let's mark George's current array as b1, b2, ..., b|b| (record |b| denotes the current length of the array). Then one change is a sequence of actions:

Choose two distinct indexes i and j (1 ≤ i, j ≤ |b|; i ≠ j), such that bi ≥ bj.
Get number v = concat(bi, bj), where concat(x, y) is a number obtained by adding number y to the end of the decimal record of number x. For example, concat(500, 10) = 50010, concat(2, 2) = 22.
Add number v to the end of the array. The length of the array will increase by one.
Remove from the array numbers with indexes i and j. The length of the array will decrease by two, and elements of the array will become re-numbered from 1 to current length of the array.
George played for a long time with his array b and received from array b an array consisting of exactly one number p. Now George wants to know: what is the maximum number of elements array b could contain originally? Help him find this number. Note that originally the array could contain only positive integers.

Input
The first line of the input contains a single integer p (1 ≤ p < 10100000). It is guaranteed that number p doesn't contain any leading zeroes.

Output
Print an integer — the maximum number of elements array b could contain originally.

Sample test(s)
input
9555
output
4
input
10000000005
output
2
input
800101
output
3
input
45
output
1
input
1000000000000001223300003342220044555
output
17
input
19992000
output
1
input
310200
output
2
Note
Let's consider the test examples:

Originally array b can be equal to {5, 9, 5, 5}. The sequence of George's changes could have been: {5, 9, 5, 5} → {5, 5, 95} → {95, 55} → {9555}.
Originally array b could be equal to {1000000000, 5}. Please note that the array b cannot contain zeros.
Originally array b could be equal to {800, 10, 1}.
Originally array b could be equal to {45}. It cannot be equal to {4, 5}, because George can get only array {54} from this array in one operation.
Note that the numbers can be very large.

*/