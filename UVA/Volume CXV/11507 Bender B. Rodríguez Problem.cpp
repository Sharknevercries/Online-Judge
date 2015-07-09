/* 13987821	11507	Bender B. Rodríguez Problem	Accepted	C++	0.052	2014-08-04 07:31:17 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		int way = 0; // +x 0, +y 2, +z 4
		for (int i = 0; i < n - 1; i++){
			char S[100];
			scanf("%s", S);
			if (strcmp(S, "No") == 0)	continue;
			if (strcmp(S, "+y") == 0){
				switch (way){
				case 0:way = 2;	break;
				case 1:way = 3;	break;
				case 2:way = 1;	break;
				case 3:way = 0;	break;
				case 4:way = 4;	break;
				case 5:way = 5;	break;
				}
			}
			if (strcmp(S, "-y") == 0){
				switch (way){
				case 0:way = 3;	break;
				case 1:way = 2;	break;
				case 2:way = 0;	break;
				case 3:way = 1;	break;
				case 4:way = 4;	break;
				case 5:way = 5;	break;
				}
			}
			if (strcmp(S, "+z") == 0){
				switch (way){
				case 0:way = 4;	break;
				case 1:way = 5;	break;
				case 2:way = 2;	break;
				case 3:way = 3;	break;
				case 4:way = 1;	break;
				case 5:way = 0;	break;
				}
			}
			if (strcmp(S, "-z") == 0){
				switch (way){
				case 0:way = 5;	break;
				case 1:way = 4;	break;
				case 2:way = 2;	break;
				case 3:way = 3;	break;
				case 4:way = 0;	break;
				case 5:way = 1;	break;
				}
			}
		}
		if (way == 0)	puts("+x");
		if (way == 1)	puts("-x");
		if (way == 2)	puts("+y");
		if (way == 3)	puts("-y");
		if (way == 4)	puts("+z");
		if (way == 5)	puts("-z");
	}
	return 0;
}
/*

Bender B. Rodríguez Problem
Bender is a robot built by Mom's Friendly Robot Company at its plant in Tijuana, Mexico in 2996 . He is a Bending-Unit 22, serial number 2716057 and chassis number 1729 . He was created for the task of bending metal wires.

Bender needs to bend a wire of length L (L$ \geq$ 2 an integer). The wire is represented in the Bender's brain (a MOS Technology 6502 microprocessor) as a line stucked in the origin of a tridimensional cartesian coordinate system, and extended along the x positive axis (+x), so that the fixed extreme of the wire is in the coordinate (0,0,0) and the free extreme of the wire is in the coordinate (L,0,0).

\epsfbox{p11507a.eps}

Bender bends the wire at specific points, starting at the point (L-1,0,0) and ending at the point (1,0,0). For each i from L-1 to 1, Bender can take one of the following decisions:

Not to bend the wire at point (i,0,0).
To bend the wire at point (i,0,0) an angle of  $ {\frac{{\pi}}{{2}}}$ to be parallel to the axis +y, -y, +z or -z.

For example, if L=3 and Bender bends the wire at (2,0,0) on the +y axis direction, and at (1,0,0) on the -y axis direction, the result would be:

\epsfbox{p11507b.eps}

Given a sequence of bends, you must determine what direction is pointed by the last segment of the wire (+x in the example). You can suppose that the wire can intercept itself, after all it is the future!

Input

The first line of each test case gives an integer L (2$ \leq$ L$ \leq$ 100000) indicating the length of the wire.

The second line of each test case contains the L-1 decisions taken by Bender at each point, separated by spaces. The j-th decision in the list (for each 1$ \leq$ j$ \leq$ L-1) corresponds to the decision taken at the point (L-j,0,0), and must be one of the following:

No if the wire isn't bended at point (L-j,0,0).
+y if the wire is bended at point (L-j,0,0) on the +y axis.
-y if the wire is bended at point (L-j,0,0) on the -y axis.
+z if the wire is bended at point (L-j,0,0) on the +z axis.
-z if the wire is bended at point (L-j,0,0) on the -z axis.
The end of the input is indicated when L=0.

Output

For each case in the input, print one line with the direction pointed by the last segment of the wire, +x, -x, +y, -y, +z or -z depending on the case.

Sample Input

3
+z -z
3
+z +y
2
+z
4
+z +y +z
5
No +z No No
0
Sample Output

+x
+z
+z
-x
+z

Colombia'2008

*/