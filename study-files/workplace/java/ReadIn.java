import java.util.Scanner;

public class ReadIn {
    public static void main (String[] args) {
        System.out.println("Please input a string :");
        Scanner scan = new Scanner(System.in);
		String readin = scan.nextLine();
        System.out.println("The string you just input is : "+readin);
    }
}

