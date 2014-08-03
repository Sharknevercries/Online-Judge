/* 102 Ecological Bin Packing Accepted C++ 0.032 2011-02-09 04:46:35 */
#include<stdio.h>
#define INT_MAX 2147483647
int main(){
	int B[3],G[3],C[3];
	while(scanf("%d%d%d%d%d%d%d%d%d",&B[0],&G[0],&C[0],&B[1],&G[1],&C[1],&B[2],&G[2],&C[2])==9){
		char str[4];		
		str[3]='\0';
		int k;
		int min=INT_MAX,type=0;
		if((k=B[1]+B[2]+C[0]+C[2]+G[0]+G[1])<min) // BCG type 1
			min=k,type=1;
		if((k=B[1]+B[2]+C[0]+C[1]+G[0]+G[2])<min) // BGC type 2
			min=k,type=2;
		if((k=B[0]+B[2]+C[1]+C[2]+G[0]+G[1])<min) // CBG type 3
			min=k,type=3;
		if((k=B[0]+B[1]+C[1]+C[2]+G[0]+G[2])<min) // CGB type 4
			min=k,type=4;
		if((k=B[0]+B[2]+C[0]+C[1]+G[1]+G[2])<min) // GBC type 5
			min=k,type=5;
		if((k=B[0]+B[1]+C[0]+C[2]+G[1]+G[2])<min) // GCB type 6
			min=k,type=6;
		switch(type){
			case 1:
				printf("BCG %d\n",min); break;
			case 2:
				printf("BGC %d\n",min); break;
			case 3:
				printf("CBG %d\n",min); break;
			case 4:
				printf("CGB %d\n",min); break;
			case 5:
				printf("GBC %d\n",min); break;
			case 6:
				printf("GCB %d\n",min); break;}
	}
	return 0;
}
/*

Τ3表ノㄓ杆Μ件瞺件瞺肅︹Τ贺茨︹Brown厚︹Green硓︹Clear硂拜肈柑и穦禗–表件瞺肅︹の计秖瞷璶穐簿表件瞺ㄏ眔程–表柑常Τ虫肅︹件瞺よ獽Μヴ叭碞琌璶衡程穐簿瞺计安砞–表甧秖礚羆穐簿瞺计ぃ穦禬筁231

Input

–掸代刚戈︽–︽Τ9俱计.玡3材1表柑Brown, Green, Clear肅︹瞺计钡ㄓ3计 材2表柑Brown, Green, Clear肅︹瞺计程3计材3表柑Brown, Green, Clear肅︹瞺计

ㄒ10 15 20 30 12 8 15 8 31 

ボΤ20Clear︹件瞺材1表12Green︹件瞺材2表15Brown︹件瞺材3表

Output

癸–掸代刚戈块3表ず程ぇ件瞺肅︹の程穐簿瞺计叫糶'G' 'B' 'C' だ厚︹Green茨︹Brown硓︹Clear

ㄒBCG 30

程穐簿挡狦材1表ず件瞺肅︹Brown材2表ず件瞺肅︹Clear材3表ず件瞺肅︹Green.羆穐簿30件瞺

狦程穐簿瞺计Τ舱舱叫块ㄥ抖程ê舱氮

Sample input

1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10

Sample Output

BCG 30
CBG 50

*/