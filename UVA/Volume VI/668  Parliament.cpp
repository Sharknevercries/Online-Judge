/* 9031107 668 Parliament Accepted C++ 0.056 2011-07-09 07:33:19 */
#include<stdio.h>
int result[1001][50];
int index[1001]={0};
void copy(int m){
	for(int i=0;i<index[m-1];i++)
		result[m][i]=result[m-1][i];
	index[m]=index[m-1];
}
void get_result(){
	int max,pos,max_pos;

	result[5][0]=2;
	result[5][1]=3;	
	index[5]=2;
	max=3,max_pos=pos=1;
	for(int m=6;m<=1000;m++){
		copy(m);
		if(result[m][0]!=2&&result[m][pos]-result[m][pos-1]==2){
			for(max_pos++,pos=0;pos<=max_pos;pos++)
				result[m][pos]=pos+2;
			index[m]=max_pos+1;
		}
		else if(result[m][pos]+1<=max)
			result[m][pos]++;		
		else{
			while(pos>=0&&result[m][pos]+1>max-(max_pos-pos))
				pos--;
			if(pos>=0)
				result[m][pos]++;
			else
				max++,result[m][max_pos]++;
		}
		pos=max_pos;
	}
}
int main(){
	get_result();
	bool first=true;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(!first)
			putchar('\n');
		first=false;
		int t;
		scanf("%d",&t);

		printf("%d",result[t][0]);
		for(int j=1;j<index[t];j++)
			printf(" %d",result[t][j]);
		putchar('\n');

	}
	return 0;
}
/*

New convocation of The Fool Land's Parliament consists of N delegates. According to the present regulation delegates should be divided into disjoint groups of different sizes and every day each group has to send one delegate to the conciliatory committee. The composition of the conciliatory committee should be different each day. The Parliament works only while this can be accomplished.

You are to write a program that will determine how many delegates should contain each group in order for Parliament to work as long as possible.

Input 

The first line of the input is an integer M, then a blank line followed by M datasets. There is a blank line between datasets. Each dataset contains a single integer N (  ).

Output 

For each dataset, write to the output file the sizes of groups that allow the Parliament to work for the maximal possible time. These sizes should be printed on a single line in ascending order and should be separated by spaces. Print a blank line between datasets.

Sample Input 

1

31

Sample Output 

2 3 5 6 7 8


Miguel Revilla 
2000-05-22

*/