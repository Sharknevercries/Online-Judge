/* 12438420	10142	Australian Voting	Accepted	C++	0.052	2013-10-03 06:22:29 */
#include<stdio.h>
#include<stdlib.h>
int main(){
	bool first=true;
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		char str[20][81];
		bool fail[20];
		int rank[1000][20];
		int ticket[20];
		int n;
		scanf("%d",&n);
		(void) getchar();
		for(int i=0;i<n;i++)
			gets(str[i]);
		
		int people=0;
		char tmp[1000];
		while( gets(tmp) ){
			if( tmp[0]=='\0' )
				break;
			int count=0,k=0;
			for(int i=0;tmp[i]!='\0';i++)
				if( tmp[i]==' ' )
					rank[people][k++]=count-1,count=0;
				else
					count=count*10+tmp[i]-'0';
			rank[people++][k++]=count-1;
		}
		for(int i=0;i<n;i++)
			fail[i]=false;

		if( !first )
			putchar('\n');
		first=false;

		int exist=n;
		while( true ){
			int min=2e9;
			bool found=false;

			for(int i=0;i<n;i++)
				ticket[i]=0;
			for(int i=0;i<people;i++){
				for(int j=0;j<n;j++)
					if( !fail[rank[i][j]] ){
						ticket[rank[i][j]]++;
						break;
					}
			}
			for(int i=0;i<n;i++){
				if( ticket[i]>people/2.0 ){ // 筁秤
					printf("%s\n",str[i]);
					found=true;
				}
				if( !fail[i]&&min>ticket[i] )
					min=ticket[i];
			}
			if( found )
				break;

			for(int i=0;i<n;i++)
				if( ticket[i]==min ) // 瞊∣程布计
					fail[i]=true,exist--;
			if( exist<=0 ){ // 瞊∣璝计箂玥圾Ы(tie)
				for(int i=0;i<n;i++)
					if( ticket[i]==min )
						printf("%s\n",str[i]);
				break;
			}
		}
		
	}
	return 0;
}
/*

Problem D - Australian Voting

Australian ballots require that the voter rank the candidates in order of choice. Initially only the first choices are counted and if one candidate receives more than 50% of the vote, that candidate is elected. If no candidate receives more than 50%, all candidates tied for the lowest number of votes are eliminated. Ballots ranking these candidates first are recounted in favour of their highest ranked candidate who has not been eliminated. This process continues [that is, the lowest candidate is eliminated and each ballot is counted in favour of its ranked non-eliminated candidate] until one candidate receives more than 50% of the vote or until all candidates are tied.
Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The first line of input is an integer n <= 20 indicating the number of candidates. The next n lines consist of the names of the candidates in order. Names may be up to 80 characters in length and may contain any printable characters. Up to 1000 lines follow; each contains the contents of a ballot. That is, each contains the numbers from 1 to n in some order. The first number indicates the candidate of first choice; the second number indicates candidate of second choice, and so on.

Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
The Output consists of either a single line containing the name of the winner or several lines containing the names of the candidates who tied.

Sample Input

1

3
John Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2
Output for Sample Input

John Doe

*/