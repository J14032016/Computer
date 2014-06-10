public class Test {
    public static void main (String[] args) {
		Circle circle = new Circle(2);
        System.out.println("The area of the circle is "+circle.getArea());
		Rectangle rectangle = new Rectangle(2, 3);
		System.out.println("The area of the rectangle is "+rectangle.getArea());
    }
}

