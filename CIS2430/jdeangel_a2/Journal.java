/** Journal class
 *
 * @author Fei Song / Julian De Angelis
 *
 * A class for representing and comparing journals.
 *
 * Copyright: This code is intended to help you with the implementation of your assignments for CIS*2430 (Fall 2015).  
 *   You are allowed to use it as a starting point for your Assignments Two and Three, but you need to acknowledge it 
 *   in your README file.  Any use, sharing, or re-distribution beyond this course is prohibited.
 */

public class Journal extends Reference {
	private String organizer;   // organizer of a journal
	
	/**
	 * Create a journal with all the required fields
	 */
	public Journal(String callNumber, String title, String organizer, int year) {
		if( valid(callNumber, title, year) ) {
			this.callNumber = callNumber;
			this.title = title;
			this.organizer = organizer;
			this.year = year;
		} else {			
			System.out.println("Invalid values for creating a journal");
			System.exit(0);
		}
	}
	
	/**
	 * Create a journal with only callNumber, title, and year
	 */
	public Journal(String callNumber, String title, int year) {
		this(callNumber, title, "", year);
	}
	

	/**
	 * Set a new value for organizer
	 */
	public void setOrganizer(String organizer) {
		this.organizer = organizer;
	}


	
	/**
	 * Get the value of organizer
	 */
	public String getOrganizer() {
		return organizer;
	}
	
	
	/**
	 * Check for the equality of two journals
	 */
	public boolean equals(Journal other) {
		if (other == null)
			return false;
		else 
			return callNumber.equalsIgnoreCase(other.callNumber) &&
			       title.equalsIgnoreCase(other.title) &&
			       organizer.equalsIgnoreCase(other.organizer) &&
			       year == other.year;
	}
	

	
	/**
	 * Show the content of a journal in a string
	 */
	public String toString() {
		return "Journal: " + callNumber + ". \"" +
			title + "\". " +
			organizer + ", " + year + ".";
	}
}
