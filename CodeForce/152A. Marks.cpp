/* 1240707	 Feb 28, 2012 11:23:26 AM	Shark	 152A - Marks	 GNU C++	Accepted	 30 ms	 1400 K */
#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		char M[100][101];
		char max[100];
		for(int i=0;i<n;i++)
			scanf("%s",M[i]);
		for(int i=0;i<m;i++){
			max[i]='0';
			for(int j=0;j<n;j++)
				if(M[j][i]>max[i])
					max[i]=M[j][i];
		}
		int count=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(M[i][j]==max[j]){
					count++;
					break;
				}
		printf("%d\n",count);
	}
	return 0;
}
/*

Vasya, or Mr. Vasily Petrov is a dean of a department in a local university. After the winter exams he got his hands on a group's gradebook.

Overall the group has n students. They received marks for m subjects. Each student got a mark from 1 to 9 (inclusive) for each subject.

Let's consider a student the best at some subject, if there is no student who got a higher mark for this subject. Let's consider a student successful, if there exists a subject he is the best at.

Your task is to find the number of successful students in the group.

Input

The first input line contains two integers n and m (1 ≤ n, m ≤ 100) — the number of students and the number of subjects, correspondingly. Next n lines each containing m characters describe the gradebook. Each character in the gradebook is a number from 1 to 9. Note that the marks in a rows are not sepatated by spaces.

Output

Print the single number — the number of successful students in the given group.

input

3 3
223
232
112
3 5
91728
11828
11111

output

2
3

Note

In the first sample test the student number 1 is the best at subjects 1 and 3, student 2 is the best at subjects 1 and 2, but student 3 isn't the best at any subject.

In the second sample test each student is the best at at least one subject.

*/