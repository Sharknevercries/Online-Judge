/* 13385209	10069	Distinct Subsequences	Accepted	C++	0.039	2014-03-25 06:27:20 */
#include<cstdio>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
void add(char str1[],char str2[],char res[]){
    int len1=strlen(str1);
    int len2=strlen(str2);
    int reslen=MAX(len1,len2)+1;
    int i,j,k,carry,tmp;
    for(int i=0;i<reslen;i++)   res[i]='0';
    res[reslen]='\0';
    for(i=len1-1,j=len2-1,k=reslen-1,carry=tmp=0;i>=0||j>=0;k--){
        tmp=0;
        if(i>=0)    tmp+=str1[i--]-'0';
        if(j>=0)    tmp+=str2[j--]-'0';
        tmp+=carry;
        if(tmp>=10)
            carry=1,tmp-=10;
        else
            carry=0;
        res[k]=tmp+'0';
    }
    res[0]='0'+carry;
    if(res[0]=='0')
        for(int i=0;i<reslen;i++)
            res[i]=res[i+1];
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char S[10001],T[101];
        char DP[101][10000];
        scanf("%s%s",S,T);
        int len=strlen(T);
        for(int i=1;i<=100;i++)
            DP[i][0]='0',DP[i][1]='\0';
        DP[0][0]='1',DP[0][1]='\0';
        for(int i=0;S[i]!='\0';i++){
            for(int j=len-1;j>=0;j--){
                if(S[i]==T[j]){
                    char res[10000];
                    add(DP[j+1],DP[j],res);
                    strcpy(DP[j+1],res);
                }
            }
        }
        printf("%s\n",DP[len]);
    }
}
/*

Problem E
Distinct Subsequences
Input: standard input
Output: standard output

A subsequence of a given sequence is just the given sequence with some elements (possibly none) left out. Formally, given a sequence X = x1x2¡Kxm, another sequence Z = z1z2¡Kzk is a subsequence of X if there exists a strictly increasing sequence <i1, i2, ¡K, ik> of indices of X such that for all j = 1, 2, ¡K, k, we have xij = zj. For example, Z = bcdb is a subsequence of X = abcbdab with corresponding index sequence < 2, 3, 5, 7 >.
In this problem your job is to write a program that counts the number of occurrences of Z in X as a subsequence such that each has a distinct index sequence.

Input
The first line of the input contains an integer N indicating the number of test cases to follow.
The first line of each test case contains a string X, composed entirely of lowercase alphabetic characters and having length no greater than 10,000. The second line contains another string Z having length no greater than 100 and also composed of only lowercase alphabetic characters. Be assured that neither Z nor any prefix or suffix of Z will have more than 10100 distinct occurrences in X as a subsequence.

Output
For each test case in the input output the number of distinct occurrences of Z in X as a subsequence. Output for each input set must be on a separate line.

Sample Input
2
babgbag
bag
rabbbit
rabbit

Sample Output
5
3
____________________________________________________________________________________
Rezaul Alam Chowdhury

*/