/** Book class
 *
 * @author Fei Song / Julian De Angelis
 *
 * A class for representing and comparing books.
 * 
 * Copyright: This code is intended to help you with the implementation of your assignments for CIS*2430 (Fall 2015).  
 *   You are allowed to use it as a starting point for your Assignments Two and Three, but you need to acknowledge it 
 *   in your README file.  Any use, sharing, or re-distribution beyond this course is prohibited.
 */

public class Book extends Reference {

	private String authors;     // one or multiple authors separated by commas
	private String publisher;   // publisher of a book
	
	/**
	 * Create a book with all the required fields
	 */
	public Book(String callNumber, String authors, String title, String publisher, int year) {
		if( valid(callNumber, title, year) ) {
			this.callNumber = callNumber;
			this.authors = authors;
			this.title = title;
			this.publisher = publisher;
			this.year = year;
		} else {			
			System.out.println("Invalid values for creating a book");
			System.exit(0);
		}
	}
	
	/**
	 * Create a book with only callNumber, title, and year
	 */
	public Book(String callNumber, String title, int year) {
		this(callNumber, "", title, "", year);
	}
	
	/**
	 * Set a new value for authors
	 */
	public void setAuthors(String authors) {
		this.authors = authors;
	}



	/**
	 * Set a new value for publisher
	 */
	public void setPublisher(String publisher) {
		this.publisher = publisher;
	}

	/**
	 * Get the value of authors
	 */
	public String getAuthors() {
		return authors;
	}
	
	/**
	 * Get the value of publisher
	 */
	public String getPublisher() {
		return publisher;
	}
	/**
	 * Check for the equality of two books
	 */
	public boolean equals(Book other) {
		if (other == null)
			return false;
		else 
			return callNumber.equalsIgnoreCase(other.callNumber) &&
			       authors.equalsIgnoreCase(other.authors) &&
			       title.equalsIgnoreCase(other.title) &&
			       publisher.equalsIgnoreCase(other.publisher) &&
			       year == other.year;
	}

	/**
	 * Show the content of a book in a string
	 */
	public String toString() {
		return "Book: " + callNumber + ". " +
                        authors + ". \"" +
			title + "\". " +
			publisher + ", " + year + ".";
	}
}