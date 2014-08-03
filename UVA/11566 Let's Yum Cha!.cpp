/* 12424130	11566	Let's Yum Cha!	Accepted	C++	0.048	2013-09-30 16:27:18 */
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
#define MAXN 20
#define MAXX 200
#define MAXK 200
int P[MAXK+1];
int V[MAXK+1];
int DP[MAXX*MAXN+1][2*MAXN+1];
int round(int S){
	S*=11;
	if( S%10==0 )
		return S/10;
	else
		return (S/10)+1;
}
int main(){
	int N,X,T,K;
	while( scanf("%d%d%d%d",&N,&X,&T,&K)==4 ){
		if( N==0&&X==0&&T==0&&K==0 )
			break;
		N++;
		for(int i=1;i<=K;i++){
			scanf("%d",&P[i]);
			int sum=0,tmp;
			for(int j=1;j<=N;j++){
				scanf("%d",&tmp);
				sum+=tmp;
			}
			V[i]=sum;
		}
		memset(DP,0,sizeof(DP));
		for(int i=1;i<=K;i++)
			for(int j=1;j<=2;j++)
				for(int k=N*X;k>=P[i];k--)
					for(int p=1;p<=2*N;p++)
						DP[k][p]=MAX(DP[k][p],DP[k-P[i]][p-1]+V[i]);

		int max=0;
		for(int i=1;i<=N*X;i++)
			if( round(i+T*N)<=X*N )
				for(int j=1;j<=2*N;j++)
					max=MAX(max,DP[i][j]);
		printf("%.2lf\n",(double)max/N);
	}
	return 0;
}
/*


Problem B: Let's Yum Cha!

Introduction

Yum cha, a term in Cantonese, literally meaning "drinking tea", refers to the custom of eating small servings of different foods (dim sum) while sipping Chinese tea. It is an integral part of the culinary culture of Guangdong and Hong Kong. For Cantonese people, to yum cha is a tradition on weekend mornings, and whole families gather to chat and eat dim sum and drink Chinese tea. The tea is important, for it helps digest the foods. In the past, people went to a teahouse to yum cha, but dim sum restaurants have been gaining overwhelming popularity recently.


Dim Sum literally means "touch your heart", which consists of a wide spectrum of choices, including combinations of meat, seafood, vegetables, as well as desserts and fruit. Dim sum can be cooked, inter alia, by steaming and deep-frying. The various items are usually served in a small steamer basket or on a small plate. The serving sizes are usually small and normally served as three or four pieces in one dish. Because of the small portions, people can try a wide variety of food.

Some well-known dim sums are:

Har gow: A delicate steamed dumpling with shrimp filling and thin (almost translucent) wheat starch skin. It is one of my favourite dim sum.
Siu mai: A small steamed dumpling with pork inside a thin wheat flour wrapper. It is usually topped off with crab roe and mushroom.
Char siu bau: A bun with Cantonese barbeque-flavoured pork and onions inside. It is probably the most famous dim sum around the world.
Sweet cream bun: A steamed bun with milk custard filling. It is sweet and spongy.
Spring roll: Consists of sliced carrot, wood-ear fungus, and sometimes meat, rolled inside a thin flour skin and deep-fried. It is crispy and delicious.
The picture on the right shows some of the dim sums mentioned above. Can you name them?

Description

Today you go to yum cha with N friends. You and your friends have agreed that everyone will pay the same amount of money (to within one dollar), and each and every one of you will pay at most $x. In the restaurant there are K kinds of dim sums to choose from. Every one of you has assigned an integer "favour index" to each dim sum, ranging from 0 to 10.

Now you are responsible for choosing what dim sums to order. You wanted to maximize your total "favour value" from dim sums you choose, but you will certainly get beaten by all your friends if you ignore their interest. Therefore, you shall maximize the mean of the total favour value everyone gets (computed using the formula ) instead. Note that even though we are considering the "mean favour value", this does not imply that everyone can actually get a piece of every ordered item!! Anyway, since you are very good friends, you will certainly find some ways to share the food so that everyone is happy, right? :-)

Since you would like to try more different kinds of dim sums, you shall NOT order more than 2 dishes of a same type of dim sum. Also, since you do not want to waste food, you shall NOT order more than 2(N+1) dishes in total (i.e. 2 dishes for each of you).

When computing the amount of money to be paid we shall NOT just add up the prices of the dim sums. We also need to take care of the following two charges:

Tea charge: everyone is charged $T for the tea provided.
10% service charge: you need to pay 10% of (Dim sum prices + Tea charge) as service charge. This value is to be rounded up to the nearest dollar.
Input

Input consists of no more than 25 test cases. Each case begins with four integers N, x, T and K, whose meanings have been explained above. Then comes K lines, each giving the information of one particular dim sum. The first integer is the price of the dim sum, followed by your favour index, then N integers which are the favour indices of your N friends.

Input ends with a line with four zeros.

Output

For each case, your program should give the optimal mean favour value, correct to 2 decimal places. This value is always positive.

Sample Input

3 10 5 2
6 7 5 6 9
10 9 10 10 8
0 0 0 0
Sample Output

16.00
Constraints

1 ≤ N ≤ 10
1 ≤ x ≤ 100
0 ≤ T ≤ 20
1 ≤ K ≤ 100
$1 ≤ price of a dim sum ≤ $100.
Problemsetter: Mak Yan Kei
Some references (including the photo) are taken from Wikipedia: http://en.wikipedia.org/wiki/Dim_Sum

*/