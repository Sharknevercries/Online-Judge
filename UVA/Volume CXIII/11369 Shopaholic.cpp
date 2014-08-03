/* 9058649 11369 Shopaholic Accepted C++ 0.056 2011-07-18 13:25:38 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
#define MAX 20001
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int m[MAX];
		bool part[MAX]={false};
		int j,k;
		int n;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
			scanf("%d",&m[j]);

		int left,next,key,split;
		for(left=1;left<=n;left++){
			while(!part[left]){
				key=m[left];
				split=left;
				for(next=left+1;next<=n&&!part[next];next++)
					if(key<m[next]){
						split++;
						SWAP(m[next],m[split]);
					}
				SWAP(m[left],m[split]);
				part[split]=true;
			}
		}

		int money,count;
		for(j=1,money=count=0;j<=n;j++){
			count++;
			if(count==3)
				money+=m[j],count=0;
		}
		printf("%d\n",money);
	}
	return 0;
}
/*

Lindsay is a shopaholic. Whenever there is a discount of the kind where you can buy three items and only pay for two, she goes completely mad and feels a need to buy all items in the store. You have given up on curing her for this disease, but try to limit its effect on her wallet.
 
You have realized that the stores coming with these offers are quite selective when it comes to which items you get for free; it is always the cheapest ones. As an example, when your friend comes to the counter with seven items, costing 400, 350, 300, 250, 200, 150, and 100 dollars, she will have to pay 1500 dollars. In this case she got a discount of 250 dollars. You realize that if she goes to the counter three times, she might get a bigger discount. E.g. if she goes with the items that costs 400, 300 and 250, she will get a discount of 250 the first round. The next round she brings the item that costs 150 giving no extra discount, but the third round she takes the last items that costs 350, 200 and 100 giving a discount of an additional 100 dollars, adding up to a total discount of 350.
 
Your job is to find the maximum discount Lindsay can get. 

Input  

The first line of input gives the number of test scenarios, 1t20 . Each scenario consists of two lines of input. The first gives the number of items Lindsay is buying, 1n20000 . The next line gives the prices of these items, 1pi20000 .
 
Output  

For each scenario, output one line giving the maximum discount Lindsay can get by selectively choosing which items she brings to the counter at the same time.
 
Sample Input  

1 
6 
400 100 200 350 300 250

 Sample Output  
 
400

--------------------------------------------------------------------------------

*/