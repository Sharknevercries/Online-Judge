/* 8898131 10714 Ants Accepted C++ 0.076 2011-05-29 03:50:55 */
#include<stdio.h>
int table[1000000];
int main(){
	int i,t;
	int n;
	scanf("%d",&n);
	for(t=1;t<=n;t++){
		int shortest,longest;
		int l,m,temp;
		scanf("%d%d",&l,&m);
		for(i=0;i<m;i++)
			scanf("%d",&table[i]);
		shortest=longest=0;
		for(i=0;i<m;i++){
			temp=(l-table[i]<table[i])?table[i]:l-table[i];
			if(longest<temp)
				longest=temp;
			temp=(l-table[i]>table[i])?table[i]:l-table[i];
			if(shortest<temp)
				shortest=temp;
		}
		printf("%d %d\n",shortest,longest);
	}
	return 0;
}
/*

 An army of ants walk on a horizontal pole of length l cm, each with a constant speed of 1 cm/s. When a walking ant reaches an end of the pole, it immediatelly falls off it. When two ants meet they turn back and start walking in opposite directions. We know the original positions of ants on the pole, unfortunately, we do not know the directions in which the ants are walking. Your task is to compute the earliest and the latest possible times needed for all ants to fall off the pole.
 The first line of input contains one integer giving the number of cases that follow. The data for each case start with two integer numbers: the length of the pole (in cm) and n, the number of ants residing on the pole. These two numbers are followed by n integers giving the position of each ant on the pole as the distance measured from the left end of the pole, in no particular order. All input integers are not bigger than 1000000 and they are separated by whitespace.
 
For each case of input, output two numbers separated by a single space. The first number is the earliest possible time when all ants fall off the pole (if the directions of their walks are chosen appropriately) and the second number is the latest possible such time.
 
Sample input
 
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191

 Output for sample input

 4 8
38 207

--------------------------------------------------------------------------------
 Piotr Rudnicki 
 
 */