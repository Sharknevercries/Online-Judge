/* 13117160	10194	Football (aka Soccer)	Accepted	C++	0.028	2014-02-10 10:11:45 */
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct team{
	string name;
	int goalScore;
	int goalAgainst;
	int win, tie, loss;
};
bool cmp(struct team A, struct team B){
	int PA, PB;
	PA = A.win * 3 + A.tie;
	PB = B.win * 3 + B.tie;
	if (PA > PB)	return true;
	if (PB > PA)	return false;
	if (A.win > B.win)	return true;
	if (A.win < B.win)	return false;
	if (A.goalScore - A.goalAgainst>B.goalScore - B.goalAgainst)	return true;
	if (A.goalScore - A.goalAgainst<B.goalScore - B.goalAgainst)	return false;
	if (A.goalScore > B.goalScore)	return true;
	if (A.goalScore < B.goalScore)	return false;
	PA = A.win + A.tie + A.loss;
	PB = B.win + B.tie + B.loss;
	if (PA > PB)	return false;
	if (PA < PB)	return true;
	for (int i = 0;; i++){ // ignore case
		char a = A.name[i];
		char b = B.name[i];
		if (a >= 'A'&&a <= 'Z')	a += 32;
		if (b >= 'A'&&b <= 'Z')	b += 32;
		if (a == '\0')	return true;
		if (b == '\0')	return false;
		if (a > b)	return false;
		if (a < b)	return true;
	}
}
int main(){
	int t;
	cin >> t;
	(void)getchar();
	while (t--){
		struct team T[30];
		string tournamentName;
		getline(cin, tournamentName);
		int n, g;
		cin >> n;
		(void)getchar();
		for (int i = 0; i < n; i++){
			getline(cin, T[i].name);
			T[i].goalAgainst = 0;
			T[i].goalScore = 0;
			T[i].loss = T[i].tie = T[i].win = 0;
		}
		cin >> g;
		(void)getchar();
		for (int j = 0; j < g; j++){
			int a, AS = 0, BS = 0;
			string R, A, B;
			getline(cin, R);
			for (a = 0; R[a] != '#'; a++)	A.push_back(R[a]);
			for (a++; R[a] != '@'; a++)	AS = AS * 10 + R[a] - '0';
			for (a++; R[a] != '#'; a++)	BS = BS * 10 + R[a] - '0';
			for (a++; R[a] != '\0'; a++)	B.push_back(R[a]);
			for (int k = 0; k < n; k++){
				if (T[k].name == A){
					T[k].goalScore += AS;
					T[k].goalAgainst += BS;
					if (AS > BS)	T[k].win++;
					if (AS == BS)	T[k].tie++;
					if (AS < BS)	T[k].loss++;
				}
				if (T[k].name == B){
					T[k].goalScore += BS;
					T[k].goalAgainst += AS;
					if (AS < BS)	T[k].win++;
					if (AS == BS)	T[k].tie++;
					if (AS > BS)	T[k].loss++;
				}
			}
		}
		sort(T, T + n, cmp);
		cout << tournamentName << endl;
		for (int i = 0; i < n; i++){
			cout << i + 1 << ") " << T[i].name << " " << T[i].win * 3 + T[i].tie << "p, ";
			cout << T[i].win + T[i].loss + T[i].tie << "g (" << T[i].win << "-" << T[i].tie << "-" << T[i].loss << "), ";
			cout << T[i].goalScore - T[i].goalAgainst << "gd (" << T[i].goalScore << "-" << T[i].goalAgainst << ")" << endl;
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}
/*


Problem A: Football (aka Soccer)

The Problem

Football the most popular sport in the world (americans insist to call it "Soccer", but we will call it "Football"). As everyone knows, Brasil is the country that have most World Cup titles (four of them: 1958, 1962, 1970 and 1994). As our national tournament have many teams (and even regional tournaments have many teams also) it's a very hard task to keep track of standings with so many teams and games played!

So, your task is quite simple: write a program that receives the tournament name, team names and games played and outputs the tournament standings so far.

A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3 points for each win, 1 point for each tie and 0 point for each loss.

Teams are ranked according to these rules (in this order):

Most points earned.
Most wins.
Most goal difference (i.e. goals scored - goals against)
Most goals scored.
Less games played.
Lexicographic order.
The Input

The first line of input will be an integer N in a line alone (0 < N < 1000). Then, will follow N tournament descriptions. Each one begins with the tournament name, on a single line. Tournament names can have any letter, digits, spaces etc. Tournament names will have length of at most 100. Then, in the next line, there will be a number T (1 < T <= 30), which stands for the number of teams participating on this tournament. Then will follow T lines, each one containing one team name. Team names may have any character that have ASCII code greater than or equal to 32 (space), except for '#' and '@' characters, which will never appear in team names. No team name will have more than 30 characters.

Following to team names, there will be a non-negative integer G on a single line which stands for the number of games already played on this tournament. G will be no greater than 1000. Then, G lines will follow with the results of games played. They will follow this format:

team_name_1#goals1@goals2#team_name_2
For instance, the following line:
Team A#3@1#Team B
Means that in a game between Team A and Team B, Team A scored 3 goals and Team B scored 1. All goals will be non-negative integers less than 20. You may assume that there will not be inexistent team names (i.e. all team names that appear on game results will have apperead on the team names section) and that no team will play against itself.
The Output

For each tournament, you must output the tournament name in a single line. In the next T lines you must output the standings, according to the rules above. Notice that should the tie-breaker be the lexographic order, it must be done case insenstive. The output format for each line is shown bellow:

[a]) Team_name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
Where:
[a] = team rank
[b] = total points earned
[c] = games played
[d] = wins
[e] = ties
[f] = losses
[g] = goal difference
[h] = goals scored
[i] = goals against
There must be a single blank space between fields and a single blank line between output sets. See the sample output for examples.
Sample Input

2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D
Sample Output

World Cup 1998 - Group A
1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
2) Norway 5p, 3g (1-2-0), 1gd (5-4)
3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
4) Scotland 1p, 3g (0-1-2), -4gd (2-6)

Some strange tournament
1) Team D 4p, 2g (1-1-0), 1gd (2-1)
2) Team E 3p, 2g (1-0-1), 0gd (3-3)
3) Team A 3p, 3g (0-3-0), 0gd (3-3)
4) Team B 1p, 1g (0-1-0), 0gd (1-1)
5) Team C 1p, 2g (0-1-1), -1gd (3-4)
© 2001 Universidade do Brasil (UFRJ). Internal Contest 2001.

*/