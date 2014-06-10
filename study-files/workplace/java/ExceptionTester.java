import java.io.*;

public class ExceptionTester {
    public static void main (String[] args) {
        int result;
        int number[] = new int[2];
        boolean valid;

        for (int i=0; i<2; i++) {
            valid = false;
            while (!valid) {
                try {
                    System.out.println("Enter number "+(i+1));
                    number[i] = Integer.valueOf(Keyboard.getString()).intValue();
                    valid = true;
                } catch (NumberFormatException e) {
                    System.out.println("Invalid integer entered. Please try again.");
                }
            }
        }
        try {
            result = number[0]/number[1];
            System.out.println(number[0]+"/"+number[1]+"="+result);
        } catch (ArithmeticException e) {
            System.out.println("Second number is 0, cannot do division!");
        }
    }
}
