/* 5353582	 Dec 5, 2013 3:45:23 PM	Shark	 254B - Jury Size	 GNU C++	Accepted	 30 ms	 200 KB */
#include<stdio.h>
int change(int m, int d){
	int M[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;
	for (int i = 0; i < m - 1; i++)
		days += M[i];
	return days + d;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1){
		int date[500] = { 0 }; // date[101] represents 1/1/2013
		for (int i = 0; i < n; i++){
			int m, d, p, t, tmp;
			scanf("%d%d%d%d", &m, &d, &p, &t);
			tmp = change(m, d) - 1 + 101;
			for (int j = tmp - 1; j >= tmp - t; j--)
				date[j] += p;
		}
		int max = 0;
		for (int i = 0; i < 500; i++){
			if (date[i] > max)
				max = date[i];
		}
		printf("%d\n", max);
	}
	return 0;
}
/*

B. Jury Size
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
In 2013, the writers of Berland State University should prepare problems for n Olympiads. We will assume that the Olympiads are numbered with consecutive integers from 1 to n. For each Olympiad we know how many members of the jury must be involved in its preparation, as well as the time required to prepare the problems for her. Namely, the Olympiad number i should be prepared by pi people for ti days, the preparation for the Olympiad should be a continuous period of time and end exactly one day before the Olympiad. On the day of the Olympiad the juries who have prepared it, already do not work on it.

For example, if the Olympiad is held on December 9th and the preparation takes 7 people and 6 days, all seven members of the jury will work on the problems of the Olympiad from December, 3rd to December, 8th (the jury members won't be working on the problems of this Olympiad on December 9th, that is, some of them can start preparing problems for some other Olympiad). And if the Olympiad is held on November 3rd and requires 5 days of training, the members of the jury will work from October 29th to November 2nd.

In order not to overload the jury the following rule was introduced: one member of the jury can not work on the same day on the tasks for different Olympiads. Write a program that determines what the minimum number of people must be part of the jury so that all Olympiads could be prepared in time.

Input
The first line contains integer n — the number of Olympiads in 2013 (1 ≤ n ≤ 100). Each of the following n lines contains four integers mi, di, pi and ti — the month and day of the Olympiad (given without leading zeroes), the needed number of the jury members and the time needed to prepare the i-th Olympiad (1 ≤ mi ≤ 12, di ≥ 1, 1 ≤ pi, ti ≤ 100), di doesn't exceed the number of days in month mi. The Olympiads are given in the arbitrary order. Several Olympiads can take place in one day.

Use the modern (Gregorian) calendar in the solution. Note that all dates are given in the year 2013. This is not a leap year, so February has 28 days. Please note, the preparation of some Olympiad can start in 2012 year.

Output
Print a single number — the minimum jury size.

Sample test(s)
input
2
5 23 1 2
3 13 2 3
output
2
input
3
12 9 2 1
12 8 1 3
12 8 2 2
output
3
input
1
1 10 1 13
output
1

*/