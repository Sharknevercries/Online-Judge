/* 13066640	12439	February 29	Accepted	C++	0.019	2014-02-01 11:09:30 */
#include<cstdio>
#include<cstring>
struct date{
	int Y, M, D;
	char S[100];
	void convert(){
		char month[12][15] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		for (M = 1; M <= 12 && strcmp(S, month[M - 1]) != 0; M++);
	}
	bool after(int year, int month, int day){
		return Y > year || (Y == year&&M > month) || (Y == year&&M == month&&D >= day);
	}
	bool before(int year, int month, int day){
		return Y < year || (Y == year&&M < month) || (Y == year&&M == month&&D <= day);
	}
};
bool isLeap(int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		struct date A, B;
		int ans = 0;
		int start, end;
		scanf("%s%d,%d", A.S, &A.D, &A.Y);
		scanf("%s%d,%d", B.S, &B.D, &B.Y);
		A.convert();
		B.convert();
		if (A.after(B.Y, B.M, B.D)){
			struct date tmp = A;
			A = B;
			B = tmp;
		}
		for (start = A.Y + 1; start % 4 != 0; start++);
		for (end = B.Y - 1; end % 4 != 0; end--);
		if (end - start >= 0)	ans += (end - start) / 4 + 1;
		for (; start % 100 != 0; start++);
		for (; end % 100 != 0; end--);
		if (end - start >= 0)	ans -= (end - start) / 100 + 1;
		for (; start % 400 != 0; start++);
		for (; end % 400 != 0; end--);
		if (end - start >= 0)	ans += (end - start) / 400 + 1;

		if (A.Y == B.Y){
			int year = A.Y;
			if (isLeap(year) && A.before(year, 2, 29) && B.after(year, 2, 29))
				ans++;
		}
		else{
			if (isLeap(A.Y) && A.before(A.Y, 2, 29))
				ans++;
			if (isLeap(B.Y) && B.after(B.Y, 2, 29))
				ans++;
		}
		printf("Case %d: %d\n", i + 1, ans);
	}
	return 0;
}
/*


G
February 29
It is 2012, and it's a leap year. So there is a "February 29" in this year, which is called leap day. Interesting thing is the infant who will born in this February 29, will get his/her birthday again in 2016, which is another leap year. So February 29 only exists in leap years. Does leap year comes in every 4 years? Years that are divisible by 4 are leap years, but years that are divisible by 100 are not leap years, unless they are divisible by 400 in which case they are leap years.

In this problem, you will be given two different date. You have to find the number of leap days in between them.

Input
The first line of input will contain T (≤ 500) denoting the number of cases.

Each of the test cases will have two lines. First line represents the first date and second line represents the second date. Note that, the second date will not represent a date which arrives earlier than the first date. The dates will be in this format - "month day, year", See sample input for exact format. You are guaranteed that dates will be valid and the year will be in between 2 * 103 to 2 * 109. For your convenience, the month list and the number of days per months are given below. You can assume that all the given dates will be a valid date.

Output
For each case, print the case number and the number of leap days in between two given dates (inclusive).

Sample Input
Output for Sample Input
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012
Case 1: 1
Case 2: 0
Case 3: 1
Case 4: 3
Note
The names of the months are {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" and "December"}. And the numbers of days for the months are {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 and 31} respectively in a non-leap year. In a leap year, number of days for February is 29 days; others are same as shown in previous line.
Problem Setter: Md. Arifuzzaman Arif, Special Thanks: Jane Alam Jan

*/