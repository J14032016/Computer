/*
如果一个整数左移运算n位，就相当于这个整数乘以2的n次方
 */
import java.util.Scanner;

public class MovePosition {
    public static void main (String[] args) {
        System.out.println("Please input a number :");
		Scanner scan = new Scanner(System.in);
		long num = scan.nextLong();
		long result = num<<1; // move left = multiplied by 2
		System.out.println(num+" * 2 = "+result);
    }
}

