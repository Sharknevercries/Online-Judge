/* 5708957	 Jan 17, 2014 1:40:12 PM	Shark	 304B - Calendar	 GNU C++	Accepted	62 ms	0 KB */
#include<cstdio>
#define lear(x) ( (x % 400 == 0)||(x % 4 == 0&&x % 100 != 0) )
struct data{
	int Y, M, D;
};
bool bigger(struct data A, struct data B){
	if (A.Y > B.Y)
		return true;
	else if (A.Y == B.Y&&A.M > B.M)
		return true;
	else if (A.Y == B.Y&&A.M == B.M&&A.D > B.D)
		return true;
	else
		return false;
}
int main(){
	struct data A, B;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%4d:%2d:%2d%4d:%2d:%2d", &A.Y, &A.M, &A.D, &B.Y, &B.M, &B.D) == 6){
		if (bigger(A, B)){
			struct data tmp = A;
			A = B;
			B = tmp;
		}
		int ans = 0;
		while (true){
			if (A.Y == B.Y&&A.M == B.M&&A.D == B.D)
				break;
			A.D++, ans++;
			if (A.M == 2 && lear(A.Y)){
				if (A.D > month[A.M] + 1)
					A.D = 1, A.M++;
			}
			else if (A.D > month[A.M])
				A.D = 1, A.M++;
			if (A.M > 12)
				A.M = 1, A.Y++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

B. Calendar
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Calendars in widespread use today include the Gregorian calendar, which is the de facto international standard, and is used almost everywhere in the world for civil purposes. The Gregorian reform modified the Julian calendar's scheme of leap years as follows:

Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100; the centurial years that are exactly divisible by 400 are still leap years. For example, the year 1900 is not a leap year; the year 2000 is a leap year.


In this problem, you have been given two dates and your task is to calculate how many days are between them. Note, that leap years have unusual number of days in February.

Look at the sample to understand what borders are included in the aswer.

Input
The first two lines contain two dates, each date is in the format yyyy:mm:dd (1900 ≤ yyyy ≤ 2038 and yyyy:mm:dd is a legal date).

Output
Print a single integer — the answer to the problem.

Sample test(s)
input
1900:01:01
2038:12:31
output
50768
input
1996:03:09
1991:11:12
output
1579

*/