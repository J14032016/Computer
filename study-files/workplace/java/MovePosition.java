/*
���һ��������������nλ�����൱�������������2��n�η�
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

