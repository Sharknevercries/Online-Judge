/* 9038472 291 The House Of Santa Claus Accepted C++ 0.028 2011-07-11 09:21:52 */
#include<stdio.h>
#define through 9
bool table[6][6]={false};
void print(int result[]){
	for(int i=0;i<through;i++)
		printf("%d",result[i]);
	putchar('\n');
}
void initial(){
	table[1][2]=table[2][1]=true;
	table[1][3]=table[3][1]=true;
	table[1][5]=table[5][1]=true;	
	table[2][3]=table[3][2]=true;
	table[2][5]=table[5][2]=true;
	table[3][4]=table[4][3]=true;
	table[3][5]=table[5][3]=true;
	table[4][5]=table[5][4]=true;
}
void DFS(int count,int start,int result[]){
	if(count==through)
		print(result);
	else
		for(int k=1;k<=5;k++)
			if(table[start][k]){
				table[start][k]=table[k][start]=false;
				result[count]=k;
				DFS(count+1,k,result);
				table[start][k]=table[k][start]=true;
			}
}
int main(){
	initial();
	int result[9];
	result[0]=1;
	DFS(1,1,result);
	return 0;
}
/*

In your childhood you most likely had to solve the riddle of the house of Santa Claus. Do you remember that the importance was on drawing the house in a stretch without lifting the pencil and not drawing a line twice? As a reminder it has to look like shown in Figure 1.
   
Figure: The House of Santa Claus
 
Well, a couple of years later, like now, you have to ``draw'' the house again but on the computer. As one possibility is not enough, we require all the possibilities when starting in the lower left corner. Follow the example in Figure 2 while defining your stretch.
   
Figure: This Sequence would give the Outputline 153125432
 
All the possibilities have to be listed in the outputfile by increasing order, meaning that 1234... is listed before 1235... .
 
Output
 
So, an outputfile could look like this: 

12435123
13245123
...
15123421 

*/