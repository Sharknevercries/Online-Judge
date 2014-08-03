/* 9379778 793 Network Connections Accepted C++ 0.032 2011-10-17 06:23:32 */
#include<stdio.h>
int parent[1001];
int find(int x){	
	return x==parent[x] ? x : (parent[x]=find(parent[x])) ;
}
void connect(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return ;
	parent[a]=b;	
}
int ask(int a,int b){
	a=find(a);
	b=find(b);
	if( parent[a] == parent[b] )
		return true;
	else
		return false;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		if(i!=1)
			putchar('\n');
		char str[100];
		int sure,unsure;
		int n;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			parent[j]=j;

		sure=unsure=0;
		(void)getchar();
		while(gets(str)){
			if(str[0]=='\0')
				break;
			char c;
			int j,a,b,temp;
			c=str[0];
			for(j=2,temp=0;str[j]!=' '&&str[j]!='\0';j++)
				temp=temp*10+str[j]-'0';
			a=temp;
			for( j+=1,temp=0 ; str[j]!=' '&&str[j]!='\0' ; j++)
				temp=temp*10+str[j]-'0';
			b=temp;
			if(c=='c')
				connect(a,b);
			else if(ask(a,b))
				sure++;
			else
				unsure++;
		}
		printf("%d,%d\n",sure,unsure);
	}
	return 0;
}
/*

Bob, who is a network administrator, supervises a network of computers. He is keeping a log connections between the computers in the network. Each connection is bi-directional. Two computers are interconnected if they are directly connected or if they are interconnected with the same computer. Occasionally, Bob has to decide, quickly, whether two given computers are connected, directly or indirectly, according to the log information.
 
Write a program which based on information input from a text file counts the number of successful and the number of unsuccessful answers to the questions of the kind :
 
is computeri interconnected with computerj ? 

Input and Output 

The first line of the input contains the number of dataset, and it's followed by a blank line. Each dataset is defined as follows: 1. The number of computers in the network (a strictly positive integer); 2. A list of pairs of the form: (a) c computeri computerj, where computeri and computerj are integers from 1 to . A pair of this form shows that computeri and computerj get interconnected. (b) q computeri computerj, where computeri and computerj are integers from 1 to . A pair of this form stands for the question: is computeri interconnected with computerj?
 There's a blank line between datasets. 

Each pair is on a separate line. Pairs can appear in any order, regardless of their type. The log is updated after each pair of type (a) and each pair of type (b) is processed according to the current network configuration.
 
For example, the input file illustrated in the sample below corresponds to a network of 10 computers and 7 pairs. There are N1 successfully answered questions and N2 unsuccessfully answered questions. The program prints these two numbers to the standard output on the same line, in the order: successful answers, unsuccessful answers, as shown in the sample output. Print a blank line between datasets.
 
Sample Input  

1

10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

 Sample Input  

1,2

--------------------------------------------------------------------------------

Miguel Revilla 
2001-01-05 

*/