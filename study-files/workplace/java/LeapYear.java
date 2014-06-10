import java.util.Scanner;

public class LeapYear {
    public static void main (String[] args) {
        System.out.println("Please input the year :");
		Scanner scan = new Scanner(System.in);
		long year;	
		try {
			year = scan.nextLong();
			if(year%4==0 && year%100!=0 || year%400==0)
				System.out.println(year+" is a leap year!");
			else
				System.out.println(year+" is not a leap year!");
		} catch (Exception e) {
			System.out.println("Invalid year!");
		}
    }
}

