/* 13072640	10028	Demerit Points	Accepted	C++	0.013	2014-02-02 16:03:07 */
#include<cstdio>
struct date{
	int Y, M, D;
	date(){};
	date(int year, int month, int day){
		Y = year, M = month, D = day;
	}
	void convert(char S[]){
		Y = M = D = 0;
		for (int i = 0; i < 4; i++)
			Y = Y * 10 + S[i] - '0';
		for (int i = 4; i < 6; i++)
			M = M * 10 + S[i] - '0';
		for (int i = 6; i < 8; i++)
			D = D * 10 + S[i] - '0';
	}
	bool after(struct date C){
		return Y>C.Y || (Y == C.Y&&M>C.M) || (Y == C.Y&&M == C.M&&D >= C.D);
	}
	bool before(struct date C){
		return Y<C.Y || (Y == C.Y&&M<C.M) || (Y == C.Y&&M == C.M&&D <= C.D);
	}
};
void showResult(struct date R, int score){
	printf("%04d-%02d-%02d ", R.Y, R.M, R.D);
	if (score == 0)
		puts("No merit or demerit points.");
	else if (score>0)
		printf("%d merit point(s).\n", score);
	else
		printf("%d demerit point(s).\n", -score);
}
void reduceDemerit(int &score){
	int tmp = score + 2;
	if (tmp>0)	tmp = 0;
	if (score / 2 > tmp)
		score /= 2;
	else
		score = tmp;
}
int main(){
	int t;
	scanf("%d", &t);
	(void)getchar();
	(void)getchar();
	while (t--){
		char S[100];
		struct date cur;
		int count = 0;
		int score = 0;
		gets(S);
		cur.convert(S);
		showResult(cur, score);
		while (gets(S)){
			if (S[0] == '\0')
				break;
			int demerit = 0;
			struct date offense;
			offense.convert(S);
			for (int i = 9; S[i] != '\0'; i++)
				demerit = demerit * 10 + S[i] - '0';
			while (offense.after(date(cur.Y + 1, cur.M, cur.D))){
				cur.Y++;
				if (score < 0)
					reduceDemerit(score);
				else{
					if (offense.after(date(cur.Y + 1, cur.M, cur.D)))
						score++, cur.Y++;
					else
						break;
				}
				showResult(cur, score);
			}
			cur = offense;
			if (score > 0){
				if (demerit > score * 2)
					score = score * 2 - demerit;
				else
					score -= demerit / 2;
			}
			else
				score -= demerit;
			showResult(cur, score);
		}
		while (score < 5){
			cur.Y++;
			if (score < 0)
				reduceDemerit(score);
			else
				score++, cur.Y++;
			showResult(cur, score);
		}
		if (t != 0)
			putchar('\n');
	}
	return 0;
}
/*

Problem B: Demerit Points


A province to our west, which shall remain nameless, but whose name does not start with A, B, or S, has a unique system for driver's license demerit and merit points. The system works (more or less) as follows.
A new driver starts with no merit or demerit points. When the driver is convicted of a driving offense, he or she is given between 2 and 15 demerit points, depending on the severity of the offense.

A merit point is given, to a maximum of five, for each interval of two years in which a driver has no offenses and no demerit points. Each merit point cancels up to two demerit points. If a subsequent offense occurs and the number of demerit points exceeds double the number of merit points, the number of demerit points is reduced by double the number of merit points, and the number of merit points is set to 0. If a subsequent offense occurs and the number of demerit points is less than or equal to double the number of merit points, the number of demerit points is reduced to 0, and the number of merit points is reduced by half the number of demerit points. Any fractional merit points are discarded.

Demerit points are reduced whenever a driver has one year free of any driving offense. This reduction decreases the number of demerits by half or by 2, whichever is more. Any fractional or negative demerit points are discarded. This reduction takes place on each anniversary of the most recent offense until no points remain.

If a new offense occurs on the same day as a demerit point reduction or merit point award, the reduction/award is done before the new demerit points are given.

Your job is to read a set of information records for a driver, and to print the number of merit or demerit points at any given time.

Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.

The first line of input contains the date of issue of the license (yyyymmdd) Subsequent lines contain information on offenses, in chronological order. Each such line contains the offense date (yyyymmdd) and the number of points applied (an integer between 2 and 15).

Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.

On the day the license is issued, and on every occasion that the number of merit or demerit points changes, output a line giving the date and the number of points, in the format below.
Output terminates when 5 merit points are accumulated following the last offense.

Sample Input

1

19820508
19830606 2
19830607 2
19891212 15
Sample Output

1982-05-08 No merit or demerit points.
1983-06-06 2 demerit point(s).
1983-06-07 4 demerit point(s).
1984-06-07 2 demerit point(s).
1985-06-07 No merit or demerit points.
1987-06-07 1 merit point(s).
1989-06-07 2 merit point(s).
1989-12-12 11 demerit point(s).
1990-12-12 5 demerit point(s).
1991-12-12 2 demerit point(s).
1992-12-12 No merit or demerit points.
1994-12-12 1 merit point(s).
1996-12-12 2 merit point(s).
1998-12-12 3 merit point(s).
2000-12-12 4 merit point(s).
2002-12-12 5 merit point(s).

*/