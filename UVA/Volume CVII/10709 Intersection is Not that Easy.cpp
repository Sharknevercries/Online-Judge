/* 13583813	10709	Intersection is Not that Easy	Accepted	C++	0.019	2014-05-03 16:22:58 */
#include<cstdio>
#include<string.h>
#include<math.h>
#define ABS(x) ( (x) >= 0 ? (x) : - (x) )
#define MIN(x, y) ( (x) >= (y) ? (y) : (x) )
#define MAX(x, y) ( (x) >= (y) ? (x) : (y) )
struct point{
	int x, y;
};

int cross(struct point A, struct point B, struct point C, struct point D){
	return (B.x - A.x)*(D.y - C.y) - (D.x - C.x)*(B.y - A.y);
}

int dot(struct point A, struct point B, struct point C, struct point D){
	return (B.x - A.x)*(D.x - C.x) + (B.y - A.y)*(D.y - C.y);
}

double length(struct point A, struct point B){
	int detX = B.x - A.x;
	int detY = B.y - A.y;
	return sqrt((double)(detX * detX + detY * detY));
}

double distance1(struct point A, struct point B, struct point C){
	// point(C) to line(AB)
	return ABS(cross(A, B, A, C)) / length(A, B);
}

double distance2(struct point A, struct point B, struct point C){
	// point(C) to segment(AB)
	if (dot(A, B, A, C) <= 0)	return length(A, C);
	if (dot(A, B, B, C) >= 0)	return length(B, C);
	return distance1(A, B, C);
}

bool intersect(struct point A, struct point B, struct point C){
	// point on line
	return C.x >= MIN(A.x, B.x) && C.x <= MAX(A.x, B.x) && C.y >= MIN(A.y, B.y) && C.y <= MAX(A.y, B.y);
}

bool intersection1(struct point A, struct point B, struct point C, struct point D){
	// two segment line
	int c1 = cross(A, B, A, C);
	int c2 = cross(A, B, A, D);
	int c3 = cross(C, D, C, A);
	int c4 = cross(C, D, C, B);
	if (c1 * c2 < 0 && c3 * c4 < 0)		return true;
	if (c1 == 0 && intersect(A, B, C))  return true;
	if (c2 == 0 && intersect(A, B, D))  return true;
	if (c3 == 0 && intersect(C, D, A))	return true;
	if (c4 == 0 && intersect(C, D, B))	return true;
	return false;
}

bool intersection2(struct point A, struct point B, struct point C, struct point D){
	// one line(AB), one segment line(CD)
	int c1 = cross(A, B, A, C);
	int c2 = cross(A, B, A, D);
	if (c1 * c2 <= 0)	return true;
	return false;
}

int main(){
	struct point P[2][2];
	char type[2][10];
	while (true){
		for (int i = 0; i < 2; i++)
			scanf("%d %d %d %d %s", &P[i][0].x, &P[i][0].y, &P[i][1].x, &P[i][1].y, type[i]);

		if (strcmp(type[0], "END") == 0 && strcmp(type[1], "END") == 0)
			break;
		if (strcmp(type[0], "L") == 0 && strcmp(type[1], "L") == 0){
			// two lines
			if (cross(P[0][0], P[0][1], P[1][0], P[1][1]) != 0)
				printf("%.5lf\n", 0.0);
			else
				printf("%.5lf\n", distance1(P[0][0], P[0][1], P[1][0]));
		}
		else if (strcmp(type[0], "LS") == 0 && strcmp(type[1], "LS") == 0){
			if (intersection1(P[0][0], P[0][1], P[1][0], P[1][1]))
				printf("%.5lf\n", 0.0);
			else{
				double min = 2e9;
				min = MIN(min, distance2(P[0][0], P[0][1], P[1][0]));
				min = MIN(min, distance2(P[0][0], P[0][1], P[1][1]));
				min = MIN(min, distance2(P[1][0], P[1][1], P[0][0]));
				min = MIN(min, distance2(P[1][0], P[1][1], P[0][1]));
				printf("%.5lf\n", min);
			}
		}
		else if (strcmp(type[0], "L") == 0 && strcmp(type[1], "LS") == 0){
			if (intersection2(P[0][0], P[0][1], P[1][0], P[1][1]))
				printf("%.5lf\n", 0.0);
			else{
				double min = 2e9;
				min = MIN(min, distance1(P[0][0], P[0][1], P[1][0]));
				min = MIN(min, distance1(P[0][0], P[0][1], P[1][1]));
				printf("%.5lf\n", min);
			}
		}
		else if (strcmp(type[0], "LS") == 0 && strcmp(type[1], "L") == 0){
			if (intersection2(P[1][0], P[1][1], P[0][0], P[0][1]))
				printf("%.5lf\n", 0.0);
			else{
				double min = 2e9;
				min = MIN(min, distance1(P[1][0], P[1][1], P[0][0]));
				min = MIN(min, distance1(P[1][0], P[1][1], P[0][1]));
				printf("%.5lf\n", min);
			}
		}
	}
	return 0;
}
/*

Problem E
Intersection is not that Easy
Input: Standard Input
Output: Standard Output
Time Limit: 1 Second

In this problem your job is to find the distance between two lines or a line and a line segment or two line segments. Suppose we have two points A(x1,y1) and B(x2,y2) on a two dimensional Cartesian plane. If we connect A and B then we get line segment AB. But if we connect AB and extend it on both side at infinite length then we get line AB.

Input
The input file contains several sets of inputs. The description of each set of input is given below:

The description for each set of input is given in two lines. Each line contains four integers and a string. First line contains x1, y1, x2, y2 and S1 and the second line contains x3, y3, x4, y4 and S2. The value of S1 and S2 can be either ¡§L¡¨ or ¡§LS¡¨ which stands for ¡§Line¡¨ and ¡§Line-segment¡¨ respectively. (x1, y1) and (x2, y2) are the endpoints of first line segment or they are just two different points on the first line depending on the value of S1. The same story applies for the second input line for this set. Input is terminated by a set where the value of S1 and S1 is ¡§END¡¨. This set should not be processed. Point (x1,y1) and (x2,y2) are always different. Similarly point (x3,y3) and (x4,y4) are also always different. All the integers in the input file have absolute value less than 101.

Output
For each set of input you should produce one line of output which contains a single floating-point number indicating the distance between the two lines or line segments or the distance between one line and one line segment. This floating-point number contains five digits after the decimal point. Errors less than 2e-5 will be ignored.

Sample Input                               Output for Sample Input
10 10 20 20 L
-10 ¡V10 19 19 L
10 10 12 13 LS
11 11 19 20 LS
10 10 12 12 END
11 11 23 34 END
0.00000
0.27735

Problem setter: Shahriar Manzoor, EPS.
Special Thanks: Derek Kisman, EPS.

*/