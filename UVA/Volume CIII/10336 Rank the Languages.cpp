/* 9110547 10336 Rank the Languages	Accepted C++ 0.012 2011-08-03 13:15:12 */
#include<stdio.h>
#define YES 1
#define NO 0
struct data{
	char alpha;
	int count;
};
struct data result[1000];
int index;
void swap(struct data *s1,struct data *s2){
	int temp1;
	char temp2;

	temp1=(*s1).count;
	(*s1).count=(*s2).count;
	(*s2).count=temp1;

	temp2=(*s1).alpha;
	(*s1).alpha=(*s2).alpha;
	(*s2).alpha=temp2;
}
void qsort(int left,int right){
	if(right>left){
		int next,split;
		split=left;
		for(next=left+1;next<=right;next++)
			if(result[left].count<result[next].count||(result[left].alpha>result[next].alpha&&result[left].count==result[next].count)){
				split++;
				swap(&result[split],&result[next]);
			}
		swap(&result[left],&result[split]);
		qsort(left,split-1);
		qsort(split+1,right);
	}
}
void count_in(char table[][500],int row,int cul){
	int i;
	for(i=0;i<index;i++)
		if(result[i].alpha==table[row][cul]){
			result[i].count++;
			break;
		}
	if(i>=index){
		result[index].alpha=table[row][cul];
		result[index++].count=1;
	}
}
void DFS(char table[][500],bool search[][500],int row,int cul,int max_row,int max_cul,char alpha){
	if(!search[row][cul]&&table[row][cul]==alpha){
		search[row][cul]=true;
		if(row+1<max_row&&!search[row+1][cul])
			DFS(table,search,row+1,cul,max_row,max_cul,alpha);		
		if(cul+1<max_cul&&!search[row][cul+1])
			DFS(table,search,row,cul+1,max_row,max_cul,alpha);
		if(row-1>=0&&!search[row-1][cul])
			DFS(table,search,row-1,cul,max_row,max_cul,alpha);
		if(cul-1>=0&&!search[row][cul-1])
			DFS(table,search,row,cul-1,max_row,max_cul,alpha);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		char table[500][500];
		bool search[500][500]={NO};
		int row,cul;
		scanf("%d%d",&row,&cul);
		(void) getchar();
		for(int i=0;i<row;i++)
			gets(table[i]);
		index=0;
		for(int i=0;i<row;i++)
			for(int j=0;j<cul;j++)
				if(!search[i][j]){
					count_in(table,i,j);
					DFS(table,search,i,j,row,cul,table[i][j]);
				}
		qsort(0,index-1);
		printf("World #%d\n",t);
		for(int i=0;i<index;i++)
			printf("%c: %d\n",result[i].alpha,result[i].count);

	}
	return 0;
}
/*

You might have noticed that English and Spanish are spoken in many areas all over the world. Now it would be nice to rank all languages according to the number of states where they are spoken.

Problem

You're given a map which shows the states and the languages where they are spoken. Look at the following map:

ttuuttdd
ttuuttdd
uuttuudd
uuttuudd

The map is read like this: Every letter stands for a language and states are defined as connected areas with the same letter. Two letters are "connected" if one is at left, at right, above or below the other one. So in the above map, there are three states where the language "t" is spoken, three where "u" is spoken and one state where people speak "d".

Your job is to determine the number of states for each language and print the results in a certain order.

Input

The first line contains the number of test cases N. Each test case consists of a line with two numbers H and W, which are the height and the width of the map. Then follow H lines with a string of W letters. Those letters will only be lowercase letters from "a" to "z".

Output

For each test case print "World #n", where n is the number of the test case. After that print a line for each language that appears in the test case, which contains the language, a colon, a space and the number of states, where that language is spoken. These lines have to be ordered decreasingly by the number of states. If two languages are spoken in the same number of states, they have to appear alphabetically, which means language "i" comes before language "q", for example.

Sample Input

2
4 8
ttuuttdd
ttuuttdd
uuttuudd
uuttuudd
9 9
bbbbbbbbb
aaaaaaaab
bbbbbbbab
baaaaacab
bacccccab
bacbbbcab
bacccccab
baaaaaaab
bbbbbbbbb
Sample Output

World #1
t: 3
u: 3
d: 1
World #2
b: 2
a: 1
c: 1 

Stefan Pochmann
 
 */