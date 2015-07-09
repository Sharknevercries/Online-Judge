/* 15454459	10149	Yahtzee	Accepted	C++	0.352	2015-05-09 08:25:41 */
#include<bits\stdc++.h>
using namespace std;
int score[15][15];
int DP[65][10005];
int record[65][10005][13];
inline bool above(int a[], int pt){
	for (int i = 1; i <= 6; i++)
		if (a[i] >= pt)
			return true;
	return false;
}
inline bool shortStraight(int a[]){
	for (int i = 1; i <= 3; i++)
		if (a[i] && a[i + 1] && a[i + 2] && a[i + 3])
			return true;
	return false;
}
inline bool longStraight(int a[]){
	for (int i = 1; i <= 2; i++)
		if (a[i] && a[i + 1] && a[i + 2] && a[i + 3] && a[i + 4])
			return true;
	return false;
}
inline bool fullHouse(int a[]){
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (i != j && a[i] >= 2 && a[j] >= 3)
				return true;
	return false;
}
inline int countDigit(int a){
	int res = 0;
	for (; a > 0; a >>= 1) res += a & 1;
	return res;
}
void solve(){
	memset(DP, -1, sizeof(DP));
	memset(record, 0, sizeof(record));
	DP[0][0] = 0;
	vector<int> digit[14];
	for (int i = 0; i < (1 << 13); i++)
		digit[countDigit(i)].push_back(i);
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < digit[i].size(); j++){
			int state = digit[i][j];
			for (int k = 0; k < 13; k++){
				if (state & (1 << k))	continue;
				int nextState = state | (1 << k);
				for (int sum = 0; sum < 64; sum++){
					if (DP[sum][state] == -1)	continue;
					int nextSum = sum;
					if (k < 6)	nextSum += score[i][k];
					if (nextSum >= 64)	nextSum = 63;
					if (DP[nextSum][nextState] < DP[sum][state] + score[i][k]){
						DP[nextSum][nextState] = DP[sum][state] + score[i][k];
						for (int p = 0; p < 13; p++)
							record[nextSum][nextState][p] = record[sum][state][p];
						record[nextSum][nextState][k] = score[i][k];
					}
				}
			}
		}
	}
	int maxSum = -1, pos = -1;
	for (int i = 63; i >= 0; i--){
		int pt = DP[i][(1 << 13) - 1];
		if (i >= 63)	pt += 35;
		if (maxSum < pt)
			maxSum = pt, pos = i;
	}
	for (int i = 0; i < 13; i++)
		printf("%d ", record[pos][(1 << 13) - 1][i]);
	printf("%d ", pos == 63 ? 35 : 0);
	printf("%d\n", maxSum);
}
int main(){
	//freopen("input.txt", "r", stdin);
	int c = 0, tmp = 0;
	while (scanf("%d",&tmp) == 1){
		if (c == 0)	memset(score, 0, sizeof(score));
		int dice[5], count[7] = { 0 };
		dice[0] = tmp, count[dice[0]]++;
		for (int i = 1; i < 5; i++)
			scanf("%d", dice + i), count[dice[i]]++;
		for (int i = 0; i < 6; i++)
			score[c][i] = count[i + 1] * (i + 1);
		for (int i = 0; i < 6; i++)
			score[c][6] += score[c][i];
		if (above(count, 3))score[c][7] = score[c][6];
		if (above(count, 4))score[c][8] = score[c][6];
		if (above(count, 5))score[c][9] = 50;
		if (shortStraight(count))	score[c][10] = 25;
		if (longStraight(count))	score[c][11] = 35;
		if (fullHouse(count))	score[c][12] = 40;
		c++;
		if (c == 13)
			solve(), c = 0;
	}
	return 0;
}
/*

The game of Yahtzee involves 5 dice, which are thrown in 13 rounds. A score card contains 13
categories; each round may be scored in a category of the player’s choosing, but each category may be
scored only once in the game. The 13 categores are scored as follows:
• ones - sum of all ones thrown
• twos - sum of all twos thrown
• threes - sum of all threes thrown
• fours - sum of all fours thrown
• fives - sum of all fives thrown
• sixes - sum of all sixes thrown
• chance - sum of all dice
• three of a kind - sum of all dice, provided at least three have same value
• four of a kind - sum of all dice, provided at least four have same value
• five of a kind - 50 points, provided all five dice have same value
• short straight - 25 points, provided four of the dice form a sequence (that is, 1,2,3,4 or 2,3,4,5
or 3,4,5,6)
• long straight - 35 points, provided all dice form a sequence (1,2,3,4,5 or 2,3,4,5,6)
• full house - 40 points, provided three of the dice are equal and the other two dice are also equal.
(for example, 2,2,5,5,5)
Each of the last six categories may be scored as 0 if the criteria are not met.
The score for the game is the sum of all 13 categories plus a bonus of 35 points if the sum of the
first six categores (ones to sixes) is 63 or greater.
Your job is to compute the best possible score for a sequence of rounds.
Input
Each line of input contains 5 integers between 1 and 6, indicating the values of the five dice thrown
in each round. There are 13 such lines for each game, and there may be any number of games in the
input data.
Output
Your output should consist of a single line for each game containing 15 numbers: the score in each
category (in the order given), the bonus score (0 or 35), and the total score. If there is more than
categorization that yields the same total score, any one will do.
Sample Input
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 1 1 1 1
6 6 6 6 6
6 6 6 1 1
1 1 1 2 2
1 1 1 2 3
1 2 3 4 5
1 2 3 4 6
6 1 2 6 6
1 4 5 5 5
5 5 5 5 6
4 4 4 5 6
3 1 3 6 3
2 2 2 4 6
Sample Output
1 2 3 4 5 0 15 0 0 0 25 35 0 0 90
3 6 9 12 15 30 21 20 26 50 25 35 40 35 327

*/