/*
 * 通过异或运算实现两个变量的呼唤
 */
import java.util.Scanner;

public class Reverse {
    public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
        System.out.println("Please input A :");
		long A = scan.nextLong();
		System.out.println("Please input B :");
		long B = scan.nextLong();
		System.out.println("A = "+A+"\tB = "+B);
		System.out.println("Now we change the two value :");
		A = A^B;
		B = B^A;
		A = A^B;
		System.out.println("A = "+A+"\tB = "+B);
    }
}

