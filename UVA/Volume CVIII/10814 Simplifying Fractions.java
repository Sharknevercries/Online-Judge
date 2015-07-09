/* 14032687	10814	Simplifying Fractions	Accepted	JAVA	0.205	2014-08-13 10:23:02 */
import java.math.*;
import java.io.*;
import java.util.*;
public class Q10814_Simplifying_Fractions {
	public static void main(String[] args) {
		Scanner input = new Scanner(new BufferedInputStream(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int t = input.nextInt();
		while(t-- > 0){
			BigInteger p = new BigInteger(input.next());
			String op = input.next();
			BigInteger q = new BigInteger(input.next());
			BigInteger gcd = GCD(p, q);
			p = p.divide(gcd);
			q = q.divide(gcd);
			output.println(p.toString() + " / " + q.toString());
		}
		output.close();
	}
	public static BigInteger GCD(BigInteger a, BigInteger b){
		while(!b.equals(new BigInteger("0"))){
			BigInteger tmp = b;
			b = a.mod(b);
			a = tmp;
		}
		return a;
	}
}
/*


Problem A: Simplifying Fractions

Time limit: 1 second

You are to write a program that reduces a fraction into its lowest terms.

Input

The first line of the input file gives the number of test cases N (≤ 20). Each of the following N lines contains a fraction in the form of p / q (1 ≤ p, q ≤ 1030).

Output

For each test case, output the fraction after simplification.

Sample Input

4
1 / 2
2 / 4
3 / 3
4 / 2
Sample Output

1 / 2
1 / 2
1 / 1
2 / 1

*/