/* 10673 Play with Floor and Ceil Accepted C++ 0.024 2011-01-31 06:08:51 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int i;
		for(i=1;i<=n;i++){			
			long long int x,k;
			long long int p,q;
			long long int s,t;
			long long int temp;
			scanf("%llu%llu",&x,&k);
			s=x/k;
			if(s==(float)x/k)
				t=s;
			else if(s<(float)x/k)
				t=s+1;
			p=q=0;
			if(s==t)				
				while(x!=(p+q)*s){
					if((p+q)*s>x)
						q--;
					else
						p++;}
			else{
				if(s==0)
					q=x;
				else{
					p=x/s;
					if(x%s!=0){
						temp=x%s;
						p-=temp;
						q+=temp;}}}
			printf("%lld %lld\n",p,q);
		}
	}
	return 0;
}
/*

對任何2個整數 x 和 k，存在另2個整數 p 和 q 使得：

要證明上面的式子是一件相當容易的事，所以我們不會要求你去做。我們要你做的事甚至更容易一些。給你 x 和 k 的值，請你找出 p 和 q 使得上面的式子成立。

Input

輸入的第一列有一個整數代表以下共有多少組測試資料（不會超過1000組）。

每組測試資料一列。含有 2 個正整數  x 和 k（均小於 108）。

Output

對每組測試資料輸出一列，含2個整數 p 和 q 。假如存在不只一組答案，輸出任何一個都可以。

但是為了幫助我們讓這個任務簡單一點，請確保 和 這2個值可以以64位元的整數儲存。

Sample Input 

4
5 2
40 2
24444 6
2 3

Sample Output

1 1
1 1
0 6
0 2
 
*/