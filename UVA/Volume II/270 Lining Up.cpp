/* 9011740 270 Lining Up Accepted C++ 1.124 2011-07-03 07:24:39 */
#include<stdio.h>
#define MAX 1000
int main(){	
	char str[50];
	int n;
	int x[MAX];
	int y[MAX];
	int index;
	bool first=true;
	scanf("%d",&n);
	(void) getchar();
	(void) getchar();
	for(int t=1;t<=n;t++){
		int max=0;
		index=0;		
		while(gets(str)){
			if(str[0]=='\0')
				break;
			sscanf(str,"%d%d",&x[index],&y[index]);
			index++;
		}
		int i,j,k;
		int count=0;
		for(i=0;i<index;i++)
			for(j=0;j<index&&i!=j;j++){
				for(k=0,count=2;k<index&&k!=i&&k!=j;k++)
					if((y[i]-y[j])*(x[j]-x[k])==(x[i]-x[j])*(y[j]-y[k]))
						count++;
				if(max<count)
					max=count;
			}
		if(!first)
			putchar('\n');
		first=false;
		printf("%d\n",max);
	}
	return 0;
}
/*

``How am I ever going to solve this problem?" said the pilot. 

Indeed, the pilot was not facing an easy task. She had to drop packages at specific points scattered in a dangerous area. Furthermore, the pilot could only fly over the area once in a straight line, and she had to fly over as many points as possible. All points were given by means of integer coordinates in a two-dimensional space. The pilot wanted to know the largest number of points from the given set that all lie on one line. Can you write a program that calculates this number?
 
Your program has to be efficient! 

Input
 
The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The input consists of N pairs of integers, where 1 < N < 700. Each pair of integers is separated by one blank and ended by a new-line character. The list of pairs is ended with an end-of-file character. No pair will occur twice.

Output
 
For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 
The output consists of one integer representing the largest number of points that all lie on one line.

Sample Input
 
1

1 1
2 2
3 3
9 10
10 11 

Sample Output
 
3 

*/