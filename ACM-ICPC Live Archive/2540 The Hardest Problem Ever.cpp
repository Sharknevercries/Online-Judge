/* 1472551	2540	The Hardest Problem Ever	Accepted	C++	0.003	2014-06-25 13:59:03 */
#include<cstdio>
#include<string.h>
char convert(char c){
	return (c - 'A' + 21) % 26 + 'A';
}
int main(){
	char S[10000];
	while (gets(S)){
		if (strcmp(S, "ENDOFINPUT") == 0)
			break;
		gets(S);
		for (int i = 0; S[i] != '\0'; i++)
			if (S[i] >= 'A'&&S[i] <= 'Z')
				S[i] = convert(S[i]);
		puts(S);
		gets(S);
	}
	return 0;
}
/*

Julius Caesar lived in a time of danger and intrigue. The hardest situation Caesar ever faced was keeping himself alive. In order for him to survive, he decided to create one of the first ciphers. This cipher was so incredibly sound, that no one could figure it out without knowing how it worked.

You are a sub captain of Caesar's army. It is your job to decipher the messages sent by Caesar and provide to your general. The code is simple. For each letter in a plaintext message, you shift it five places to the right to create the secure message (i.e., if the letter is 'A', the cipher text would be 'F'). Since you are creating plain text out of Caesar's messages, you will do the opposite:

Cipher text
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

Plain text
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
Only letters are shifted in this cipher. Any non-alphabetical character should remain the same, and all alphabetical characters will be upper case.

Input

Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets. All characters will be uppercase.

A single data set has 3 components:
Start line - A single line, "START"
Cipher message - A single line containing from one to two hundred characters, inclusive, comprising a single message from Caesar
End line - A single line, "END"
Following the final data set will be a single line, "ENDOFINPUT".

Output

For each data set, there will be exactly one line of output. This is the original message by Caesar.

Sample Input

START
NS BFW, JAJSYX TK NRUTYFSHJ FWJ YMJ WJXZQT TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
Sample Output

IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE

*/