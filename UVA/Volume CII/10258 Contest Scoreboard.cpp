/* 8851194 10258 Contest Scoreboard Accepted C++ 0.008 2011-05-16 12:41:15 */
#include<stdio.h>
#define SOLVED -2147483647 
#define MAX_PENALTY 2147483647
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
struct person{
	int number;
	int solved;
	int penalty;
	int try_solve[10];
};
void SWAP_obj(struct person *x,struct person *y){
	int i;
	SWAP((*x).number,(*y).number);
	SWAP((*x).penalty,(*y).penalty);
	SWAP((*x).solved,(*y).solved);
	for(i=0;i<10;i++)
		SWAP((*x).try_solve[i],(*y).try_solve[i]);
}
void initial(struct person people[]){
	int i,j;
	for(i=0;i<100;i++){
		people[i].number=0;
		people[i].penalty=0;
		people[i].solved=0;
		for(j=0;j<10;j++)
			people[i].try_solve[j]=0;
	}
}
int main(){
	bool first=true;
	int n,i,j,k,l;
	char str[20];
	scanf("%d",&n);
	(void) getchar();
	gets(str);	
	for(i=1;i<=n;i++){		
		struct person people[100];	
		initial(people);
		char c;
		int number,problem,time;
		int index;			
		index=0;
		while(true){
			if(!gets(str)) break;
			if(str[0]=='\0') break; 
			sscanf(str,"%d%d%d %c",&number,&problem,&time,&c);
			for(j=0;j<index;j++)
				if(number==people[j].number){
					if(c=='I'){
						people[j].try_solve[problem]++;						
					}
					else if(c=='C'&&people[j].try_solve[problem]>=0){
						people[j].solved++;
						people[j].penalty+=time+people[j].try_solve[problem]*20;
						people[j].try_solve[problem]=SOLVED;						
					}
					break;
				}
			if(j>=index){
				if(c=='I'){
					people[index].try_solve[problem]++;
					people[index].number=number;
				}
				else if(c=='C'&&people[index].try_solve[problem]>=0){
					people[index].number=number;
					people[index].solved++;
					people[index].penalty+=time+people[j].try_solve[problem]*20;
					people[index].try_solve[problem]=SOLVED;					
				}
				else
					people[index].number=number;
				index++;
			}
		}
		int max_solve;
		for(j=0;j<index;j++)
			for(k=j+1;k<index;k++)			
				if(people[j].solved<people[k].solved) // 最大解題數
					SWAP_obj(&people[j],&people[k]);
		max_solve=people[0].solved;
		while(max_solve>=0){
			for(j=0;j<index;j++)
				for(k=j+1;people[k].solved==max_solve&&people[j].solved==max_solve&&k<index;k++)			
					if(people[j].penalty>people[k].penalty) // 最少懲罰時間
						SWAP_obj(&people[j],&people[k]);			
			max_solve--;
		}
		j=0;
		while(j<index){			
			for(l=j;people[j].solved==people[l].solved&&people[j].penalty==people[l].penalty&&l<index;l++);
			for(;j<l;j++)
				for(k=j+1;k<l;k++)
					if(people[j].number>people[k].number)
						SWAP_obj(&people[j],&people[k]);	
		}
		if(first)
			first=false;
		else
			putchar('\n');
		for(j=0;j<index;j++)
			printf("%d %d %d\n",people[j].number,people[j].solved,people[j].penalty);		
	}
	return 0;
}
/*

Question B - Contest Scoreboard
 
Think the contest score boards are wrong? Here's your chance to come up with the right rankings.
 
Contestants are ranked first by the number of problems solved (the more the better), then by decreasing amounts of penalty time. If two or more contestants are tied in both problems solved and penalty time, they are displayed in order of increasing team numbers.
 A problem is considered solved by a contestant if any of the submissions for that problem was judged correct. Penalty time is computed as the number of minutes it took for the first correct submission for a problem to be received plus 20 minutes for each incorrect submission received prior to the correct solution. Unsolved problems incur no time penalties.
 
Input:
 
The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 

Input consists of a snapshot of the judging queue, containing entries from some or all of contestants 1 through 100 solving problems 1 through 9. Each line of input will consist of three numbers and a letter in the format
 
contestant problem time L 

where L can be C, I, R, U or E. These stand for Correct, Incorrect, clarification Request, Unjudged and Erroneous submission. The last three cases do not affect scoring.
 
Lines of input are in the order in which submissions were received. 

Output:
 
For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 

Output will consist of a scoreboard sorted as previously described. Each line of output will contain a contestant number, the number of problems solved by the contestant and the time penalty accumulated by the contestant. Since not all of contestants 1-100 are actually participating, display only the contestants that have made a submission.
 
Sample Input:

1

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
 
Sample Output:

1 2 66
3 1 11

 */