public class Thread {
	public static void main(String[] args) {
		System.out.println("main thread starts");
		FactorialThread thread = new FactorialThread(10);
		thread.run();
		System.out.println("main thread ends");
	}
}

class FactorialThread extends Thread {
	private int num;
	public FactorialThread (int num) {
		this.num = num;
	}
	public void run () {
		int i = num;
		int result = 1;
		System.out.println("new thread started");
		while (i-- > 0) 
			result *= i;	
		System.out.println("The factorial of "+num+" is "+result);
		System.out.println("new thread ends");
	}
}
