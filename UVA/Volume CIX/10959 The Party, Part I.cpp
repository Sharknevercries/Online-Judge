/* 9283281 10959 The Party, Part I Accepted C++ 1.624 2011-09-21 04:58:56 */
#include<stdio.h>
#include<string.h>
struct data{
    int cost;
    int pos;
};
bool table[1000][1000];
bool been[1000];
struct data quene[10000];
int head,tail;
void initial(){
    head=tail=0;
}
void push(int pos,int vertex){
    quene[head].pos=pos;
    quene[head].cost=vertex;
    head++;
}
void pop(int *pos,int *vertex){
    (*pos)=quene[tail].pos;
    (*vertex)=quene[tail].cost;
    tail++;
}
int BFS(int n){
    int pos,vertex;
    while(head>tail){
        pop(&pos,&vertex);
        if(pos==0)
            return vertex;
        for(int i=0;i<n;i++)
            if(!been[i]&&table[pos][i]){
                been[i]=true;
                push(i,vertex+1);
            }
    }
}
int main(){
    bool first=true;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(table,false,sizeof(table));
        
        int n,m,j,k,l;
        scanf("%d%d",&n,&m);
        for(l=0;l<m;l++){
            scanf("%d%d",&j,&k);
            table[j][k]=table[k][j]=true;
        }
        if(!first)
            putchar('\n');
        first=false;
        for(j=1;j<n;j++){
            initial();
            memset(been,false,sizeof(been));            
            push(j,0);
            printf("%d\n",BFS(n));
        }
    }    
    return 0;
}
/*

Don Giovanni likes to dance--especially with girls! And everyone else in the party enjoyed the dance, too. Getting a chance to dance with the host (that is Don Giovanni) is the greatest honour; failing that, dancing with someone who has danced with the host or will dance with the host is the second greatest honour. This can go further. Define the Giovanni number of a person as follows, at the time after the party is over and therefore who has danced with whom is completely known and fixed: 

No one has a negative Giovanni number. 
The Giovanni number of Don Giovanni is 0. 
If a person p is not Don Giovanni himself, and has danced with someone with Giovanni number n, and has not danced with anyone with a Giovanni number smaller than n, then p has Giovanni number n+1. 
If a person's Giovanni number cannot be determined from the above rules (he/she has not danced with anyone with a finite Giovanni number), his/her Giovanni number is . Fortunately, you will not need this rule in this problem. 
Your job is to write a program to compute Giovanni numbers. 

Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 

The first line has two numbers P and D; this means there are P persons in the party (including Don Giovanni) and D dancing couples (P ? 1000 and .) Then D lines follow, each containing two distinct persons, meaning the two persons has danced. Persons are represented by numbers between 0 and P-1; Don Giovanni is represented by 0. 

As noted, we design the input so that you will not need the  rule in computing Giovanni numbers. 

We have made our best effort to eliminate duplications in listing the dancing couples, e.g., if there is a line ``4 7'' among the D lines, then this is the only occurrence of ``4 7'', and there is no occurrence of ``7 4''. But just in case you see a duplication, you can ignore it (the duplication, not the first occurrence). 

Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 

Output P-1 lines. Line i is the Giovanni number of person i, for . Note that it is P-1 because we skip Don Giovanni in the output. 

Sample Input
1

5 6
0 1
0 2
3 2
2 4
4 3
1 2

Sample Output

1
1
2
2

*/
