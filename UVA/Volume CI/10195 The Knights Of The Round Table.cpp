/* 15491140	10195	The Knights Of The Round Table	Accepted	C++	0.022	2015-05-16 11:27:29 */
#include<bits\stdc++.h>
using namespace std;
const double EPS = 1e-9;
int main(){
	double a, b, c;
	while (scanf("%lf%lf%lf", &a, &b, &c) == 3){
		double s = (a + b + c) / 2;
		double r = sqrt(s * (s - a)*(s - b) * (s - c)) / s;
		if (a == 0 || b == 0 || c == 0)	r = 0;
		printf("The radius of the round table is: %.3lf\n", r + EPS);
	}
	return 0;
}
/*

King Arthur is planning to build the round table in a new room, but this time he wants a room that
have sunlight entering it, so he planned to build a glass roof. He also wishes his round table to shine
during the day, specially at noon, so he wants it to be covered totally by the sunlight. But Lancelot
wants the glass part of the room roof to be triangular (and nobody knows the reason why, maybe he
made a vow or something like that). So, there will be a triangular area in the room which will be all
covered by the sunlight at noon and the round table must be build in this area.
Now, King Arthur wants to build the biggest table that he cans such that it fits in the triangular
sunlighted area. As he is not very good in geometry, he asked Galahad to help him (Lancelot is very
good in geometry, but King Arthur didn’t asked Lancelot to help him because he feared that he would
come up with another strange suggestion).
Can you help Galahad (since he’s not too good with computers) and write a program which gives
the radius of the biggest round table that fits in the sunlighted area? You can assume that the round
table is a perfect circle.
Input
There’ll be an arbitrary number of rooms. Each room is represented by three real numbers (a, b and
c), which stand for the sizes of the triangular sunlighted area. No triangle size will be greater than
1000000 and you may assume that max(a, b, c) ≤ (a + b + c)/2.
You must read until you reach the end of the file.
Output
For each room configuration read, you must print the following line:
The radius of the round table is: r
Where r is the radius of the biggest round table that fits in the sunlighted area, rounded to 3 decimal
digits.
Sample Input
12.0 12.0 8.0

Sample Output
The radius of the round table is: 2.828

*/