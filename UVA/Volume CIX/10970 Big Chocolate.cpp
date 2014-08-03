/* 9047194 10970 Big Chocolate Accepted C++ 0.084 2011-07-14 04:47:26 */
#include<stdio.h>
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)==2){
		printf("%d\n",(n-1)+(m-1)*n);
	}
	return 0;
}
/*

Mohammad has recently visited Switzerland. As he loves his friends very much, he decided to buy some chocolate for them, but as this fine chocolate is very expensive(You know Mohammad is a little BIT stingy!), he could only afford buying one chocolate, albeit a very big one (part of it can be seen in figure 1) for all of them as a souvenir. Now, he wants to give each of his friends exactly one part of this chocolate and as he believes all human beings are equal (!), he wants to split it into equal parts.

The chocolate is an  rectangle constructed from  unit-sized squares. You can assume that Mohammad has also  friends waiting to receive their piece of chocolate.

To split the chocolate, Mohammad can cut it in vertical or horizontal direction (through the lines that separate the squares). Then, he should do the same with each part separately until he reaches  unit size pieces of chocolate. Unfortunately, because he is a little lazy, he wants to use the minimum number of cuts required to accomplish this task.

Your goal is to tell him the minimum number of cuts needed to split all of the chocolate squares apart.

Figure 1. Mohammad¡¦s chocolate

The Input 

The input consists of several test cases. In each line of input, there are two integers , the number of rows in the chocolate and , the number of columns in the chocolate. The input should be processed until end of file is encountered.

The Output 

For each line of input, your program should produce one line of output containing an integer indicating the minimum number of cuts needed to split the entire chocolate into unit size pieces.

Sample Input
2 2
1 1
1 5 

Sample Output
3
0
4

--------------------------------------------------------------------------------

 Amirkabir University of Technology - Local Contest - Round #2 

*/