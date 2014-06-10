public class Book {
	private String title;
	private String author;
	private double price;
	public Book (String title, String author, double price) {
		this.title = title;
		this.author = author;
		this.price = price;
	}
	public String getTitle() {
		return title;
	}
	public String getAuthor() {
		return author;
	}
	public double getPrice() {
		return price;
	}
}

public class Labrary {
    public static void main (String[] args) {
		Book book = new Book("Java从入门到精通(第2版)", "明日科技", 59.8);
		System.out.println("Title : "+book.getTitle());
        System.out.println("Author : "+book.getAuthor());
		System.out.println("Price : "+book.getPrice());
    }
}

