/* 9194198 496 Simply Subsets Accepted C++ 0.008 2011-08-27 05:06:23 */
#include<stdio.h>
#define SWAP(x,y) {	int temp=x; x=y; y=temp; }
int readin(int m[],int *index){
	int i,j,temp;
	char c;
	bool first_blank=true;
	for((*index)=temp=0;;){
		c=getchar();
		if(c>='0'&&c<='9')
			temp=temp*10+c-'0';
		else{
			if(first_blank&&(c=='\n'||c=='\0'||c==EOF))	break;
			
			for(i=0;i<(*index);i++)
				if(m[i]==temp)
					break;
			if(i>=(*index))
				m[(*index)++]=temp;
			if(c=='\n'||c=='\0'||c==EOF)
				break;
			temp=0;
		}
		first_blank=false;		
	}		
	if(c==EOF)
		return false;
	return true;
}
void qsort(int m[],int left,int right){
	if(right>left){
		int split,next;
		split=left;
		for(next=split+1;next<=right;next++)
			if(m[left]>m[next]){
				split++;
				SWAP(m[next],m[split]);
			}
		SWAP(m[left],m[split]);
		qsort(m,left,split-1);
		qsort(m,split+1,right);
	}
}
void compare(int m1[],int index1,int m2[],int index2){
	bool equal;
	bool m1_contain_m2;
	bool m2_contain_m1;
	bool disjoint;
	int i,j,k;
	equal=m1_contain_m2=m2_contain_m1=disjoint=true;

	for(i=j=0;i<index1&&j<index2;){
		if(m1[i]!=m2[j]){
			if(m1[i]<m2[j])
				i++,m2_contain_m1=false;
			else
				j++,m1_contain_m2=false;
			equal=false;
		}
		else
			i++,j++,disjoint=false;
	}
	if(i<index1)
		equal=m2_contain_m1=false;
	if(j<index2)
		equal=m1_contain_m2=false;	
	if(equal)
		puts("A equals B");
	else if(m1_contain_m2)
		puts("B is a proper subset of A");
	else if(m2_contain_m1)
		puts("A is a proper subset of B");
	else if(disjoint)
		puts("A and B are disjoint");				
	else
		puts("I'm confused!");
}
int main(){
	while(true){
		int m1[100],m2[100];
		int index1,index2;
		if(!readin(m1,&index1))
			break;
		if(!readin(m2,&index2))
			break;		
		qsort(m1,0,index1-1);
		qsort(m2,0,index2-1);
		compare(m1,index1,m2,index2);
	}
	return 0;
}
/*

After graduating from the University of Notre Dame, you obtained a job at Top Shelf Software, Inc., as an entry-level computer engineer. On the first day, your manager sits down with you and tasks you with the following job: ``We want to see how well you understand computer programming and the abstract science behind it. As an evaluation for all of our new hires, we require them to write a program to determine the relationship between pairs of sets. I'm quite sure that you'll do well; my confidence is high. Here's a list of requirements for what the program should do. Good luck.''
 
Input
 
Your program should accept an even number of lines of text. Each pair of lines will represent two sets; the first line represents set A, the second line represents set B. Each line of text (set) will be a list of distinct integers.
 
Output
 
After each pair of lines has been read in, the sets should be compared and one of the following responses should be output:
 • A is a proper subset of B
• B is a proper subset of A
• A equals B
• A and B are disjoint
• I'm confused! 

Sample Input
 
55 27
55 27
9 24 1995
9 24
1 2 3
1 2 3 4
1 2 3
4 5 6
1 2
2 3 

Sample Output
 
A equals B
B is a proper subset of A
A is a proper subset of B
A and B are disjoint
I'm confused! 

*/