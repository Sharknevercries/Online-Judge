#include<cstdio>
#include<string.h>
#include<algorithm>
#define BONUS 35
int score[13][13];
int DP[1 << 13][64];
int record[1 << 13][64][2];
bool short_straight(int input[]){
	for (int i = 0; i < 3; i++){
		if (input[i] + 1 == input[i + 1] && input[i + 1] + 1 == input[i + 2] && input[i + 2] + 1 == input[i + 3])
			return true;
	}
	return false;
}
bool long_straight(int input[]){
	for (int i = 0; i < 2; i++){
		if (input[i] + 1 == input[i + 1] && input[i + 1] + 1 == input[i + 2] && input[i + 2] + 1 == input[i + 3] && input[i + 3] + 1 == input[i + 4])
			return true;
	}
	return false;
}
bool full_house(int input[]){
	return (input[0] == input[1] && input[2] == input[4]) || (input[0] == input[2] && input[3] == input[4]);
}
void analysis(int input[][5]){
	for (int i = 0; i < 13; i++){
		std::sort(input[i], input[i] + 5);
		int count[7] = { 0 };
		bool two = false, three = false;
		for (int j = 0; j < 5; j++)
			count[input[i][j]]++;
		for (int j = 1; j <= 6; j++)
			score[i][j - 1] = count[j] * j;
		for (int j = 1; j <= 6; j++)
			score[i][6] += score[i][j - 1];
		if (input[i][0] == input[i][2] || input[i][1] == input[i][3] || input[i][2] == input[i][4])
			score[i][7] = score[i][6];
		if (input[i][0] == input[i][3] || input[i][1] == input[i][4])
			score[i][8] = score[i][6];
		if (input[i][0] == input[i][4])
			score[i][9] = 50;
		if (short_straight(input[i]))
			score[i][10] = 25;
		if (long_straight(input[i]))
			score[i][11] = 35;
		if (full_house(input[i]))
			score[i][12] = 40;
	}
}
int main(){
	int input[13][5];
	char str[100];
	while (gets(str) && sscanf(str, "%d%d%d%d%d", input[0], input[0] + 1, input[0] + 2, input[0] + 3, input[0] + 4) == 5){
		for (int i = 1; i < 13; i++){
			gets(str);
			sscanf(str, "%d%d%d%d%d", input[i], input[i] + 1, input[i] + 2, input[i] + 3, input[i] + 4);
		}
		memset(score, 0, sizeof(score));
		analysis(input);
		memset(DP, -1, sizeof(DP));
		DP[0][0] = 0;
		for (int i = 0; i < (1 << 13); i++){
			for (int k = 0; k < 13; k++){
				if (!(i & (1 << k))){
					int j = 0;
					for (int p = i; p > 0; p >>= 1){
						if (p & 1 == 1)
							j++;
					}
					for (int s = 0; s < 64; s++){
						int t;
						if (k < 6)
							t = s + score[j][k] >= 63 ? 63 : s + score[j][k];
						else
							t = s;
						if (DP[i][s] > -1 && DP[i | (1 << k)][t] < DP[i][s] + score[j][k]){
							DP[i | (1 << k)][t] = DP[i][s] + score[j][k];
							record[i | (1 << k)][t][0] = k;
							record[i | (1 << k)][t][1] = s;
						}
					}
				}
			}
		}
		int max = -1, prev_six = -1, res[13];
		bool have_bonus = false;
		for (int i = 0; i < 63; i++){
			if (DP[(1 << 13) - 1][i] > max)
				max = DP[(1 << 13) - 1][i], prev_six = i;
		}
		if (DP[(1 << 13) - 1][63] > -1 && DP[(1 << 13) - 1][63] + BONUS > max)
			max = DP[(1 << 13) - 1][63] + BONUS, prev_six = 63, have_bonus = true;
		for (int i = 12, j = (1 << 13) - 1; i >= 0; i--){
			res[i] = record[j][prev_six][0];
			prev_six = record[j][prev_six][1];
			j ^= (1 << res[i]);
		}

		for (int i = 0; i < 13; i++){
			for (int j = 0; j < 13; j++){
				if (res[j] == i)
					printf("%d ", score[j][i]);
			}
		}
		printf("%d ", have_bonus ? 35 : 0);
		printf("%d", max);
        putchar('\n');
	}
	return 0;
}
