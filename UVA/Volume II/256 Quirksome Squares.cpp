/* 256 Quirksome Squares Accepted C++ 0.832 2011-02-12 06:26:10 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i,j;
		int max,middle;
		for(i=max=1;i<=n;i++,max*=10);
		for(i=middle=1;i<=n/2;i++,middle*=10);
		for(i=0;i<max;i++){
			int m1,m2;
			m2=i%middle;
			m1=(i-m2)/middle;
			if((m1+m2)*(m1+m2)==i)
				printf("%0*d\n",n,i);
		}
	}
	return 0;
}
/*

3025硂4计讽疭狦р眖い丁ち秨穦眔2计30,25τ2计㎝キよ单ㄓ计и嘿硂贺计quirksome number

(30+25)2=3025

硂拜肈琌倒N计N∽2,4,6,8璶т才┦借┮Τ计
For example4计碞琌眖00009999猔種计玡よ0璶衡ず碞琌弧0001单 (00+01)2 琌4计quirksome number

Input

块碭代刚戈–Τ计NN=2,4,6,8璶―琌碭计quirksome number

Output

癸–块N莱赣璶块┮ΤN计quirksome number–︽パ逼猔種计玡よ0ぃ┛菠ㄒ2计いquirksome number 01ぃ块1


Sample Input

2
2

Sample Output

00
01
81
00
01
81

*/