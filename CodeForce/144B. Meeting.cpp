/* 1308994	 Mar 7, 2012 6:20:41 PM	Shark	 144B - Meeting	 GNU C++	Accepted	 30 ms	 1400 KB */
#include<stdio.h>
#define SQUARE(x) ( (x)*(x) )
typedef struct data{
	int X,Y,R;
}MAKE;
MAKE point[1000];
int main(){
	int x1,x2,y1,y2;
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&point[i].X,&point[i].Y,&point[i].R);

		if( (x1<x2&&y1>y2) ){	int temp=y1;	y1=y2;		y2=temp;	}
		else if( (x1>x2&&y2>y1) ){	int temp=x1;	x1=x2;		x2=temp;	}
		else if( (x1>x2&&y1>y2) ){	int temp=x1; x1=x2; x2=temp; temp=y1; y1=y2; y2=temp;	}

		int count= ((x2-x1)+(y2-y1))*2;
		for(int i=x1;i<=x2;i++){
			for(int j=0;j<n;j++)
				if( SQUARE(i-point[j].X)+SQUARE(y1-point[j].Y)<=SQUARE(point[j].R) ){
					count--;
					break;
				}
			for(int j=0;j<n;j++)
				if( SQUARE(i-point[j].X)+SQUARE(y2-point[j].Y)<=SQUARE(point[j].R) ){
					count--;
					break;
				}
		}
		for(int i=y1+1;i<=y2-1;i++){
			for(int j=0;j<n;j++)
				if( SQUARE(x1-point[j].X)+SQUARE(i-point[j].Y)<=SQUARE(point[j].R) ){
					count--;
					break;
				}
			for(int j=0;j<n;j++)
				if( SQUARE(x2-point[j].X)+SQUARE(i-point[j].Y)<=SQUARE(point[j].R) ){
					count--;
					break;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}
/*

The Super Duper Secret Meeting of the Super Duper Secret Military Squad takes place in a Super Duper Secret Place. The place is an infinite plane with introduced Cartesian coordinate system. The meeting table is represented as a rectangle whose sides are parallel to the coordinate axes and whose vertexes are located at the integer points of the plane. At each integer point which belongs to the table perimeter there is a chair in which a general sits.

Some points on the plane contain radiators for the generals not to freeze in winter. Each radiator is characterized by the number ri — the radius of the area this radiator can heat. That is, if the distance between some general and the given radiator is less than or equal to ri, than the general feels comfortable and warm. Here distance is defined as Euclidean distance, so the distance between points (x1, y1) and (x2, y2) is 

Each general who is located outside the radiators' heating area can get sick. Thus, you should bring him a warm blanket. Your task is to count the number of warm blankets you should bring to the Super Duper Secret Place.

The generals who are already comfortable do not need a blanket. Also the generals never overheat, ever if they are located in the heating area of several radiators. The radiators can be located at any integer points on the plane, even inside the rectangle (under the table) or on the perimeter (directly under some general). Even in this case their radius does not change.

Input

The first input line contains coordinates of two opposite table corners xa, ya, xb, yb (xa ≠ xb, ya ≠ yb). The second line contains integer n — the number of radiators (1 ≤ n ≤ 103). Then n lines contain the heaters' coordinates as "xi yi ri", the numbers are separated by spaces. All input data numbers are integers. The absolute value of all coordinates does not exceed 1000, 1 ≤ ri ≤ 1000. Several radiators can be located at the same point.

Output

Print the only number — the number of blankets you should bring.

input

2 5 4 2
3
3 1 2
5 3 1
1 3 2
5 2 6 3
2
6 2 2
6 5 3

output

4
0

Note

In the first sample the generals are sitting at points: (2, 2), (2, 3), (2, 4), (2, 5), (3, 2), (3, 5), (4, 2), (4, 3), (4, 4), (4, 5). Among them, 4 generals are located outside the heating range. They are the generals at points: (2, 5), (3, 5), (4, 4), (4, 5).

In the second sample the generals are sitting at points: (5, 2), (5, 3), (6, 2), (6, 3). All of them are located inside the heating range.

*/