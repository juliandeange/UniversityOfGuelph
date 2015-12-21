import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.io.*;
        

/** LibrarySearch class
 *
 * @author Fei Song / Julian De Angelis
 *
 * A class that adds, maintains, and searches for books and journals.
 *
 * Copyright: This code is intended to help you with the implementation of your assignments for CIS*2430 (Fall 2015).  
 *   You are allowed to use it as a starting point for your Assignments Two and Three, but you need to acknowledge it 
 *   in your README file.  Any use, sharing, or re-distribution beyond this course is prohibited.
 */

public class LibrarySearch extends Reference {
        
        // Creates refernce arraylist to hold the entries
        private ArrayList<Reference> references;
        
        // Creates hashmap to hold title keywords for efficient searching
        private HashMap<String, ArrayList<Integer>> map = new HashMap<String, ArrayList<Integer>>();
	
	public static final String[] REFERENCE_TYPES = new String[]{"book", "journal", "b", "j"};

	/**
	 * Create an instance of LibrarySearch
	 */
	public LibrarySearch() {
		references = new ArrayList<Reference>();
	}

	// Takes in a reference object and adds it to the Reference arraylist
	private boolean addReference( Reference reference ) {
            
		for( int i = 0; i < references.size(); i++ ) 
			if( references.get(i).keyEquals(reference) )
				return false;
		references.add( reference );
                
                String title = reference.getTitle();
                String[] tokens = title.split(" ");

                int index = references.indexOf(reference);

                for (String token : tokens) {
                    String key = token.toLowerCase();
                    ArrayList<Integer> list = map.get(key);
                if (list == null) {
                    list = new ArrayList<Integer>();
		map.put(key, list);
                }

                if (!list.contains(index)) {
                    list.add(index);
                }
            }    
            return true;
	}
	
	/** 
	 * Function asks user for required fields and creates object to be added
         * to the arrayList
         * 
         * Function also exports the added data to a text file "AddedRefs.txt" in the root directory
	 */
	public void add( Scanner input ) {
		String type;
                String fileName = "AddedRefs.txt";
            
            try{
                
                // Opens file and creates a writer to the file
                FileWriter f = new FileWriter(fileName, true);
                BufferedWriter write = new BufferedWriter(f);
                
                
                write.newLine();
             
                
                /*
                Following recieves data from the user about the objects being added
                */
		do {
			System.out.print( "Enter a reference type (book or journal)> " );
                        
			type = input.nextLine();
		} while( !matchedKeyword(type, REFERENCE_TYPES) );
		
                String callNumber = "";
                do {
			System.out.print( "Enter a call number> " );
			callNumber = input.nextLine();
                } while( callNumber.isEmpty() );
		
		String authors = "";
		if( type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b") ) {
			System.out.print("Enter a list of authors separated by comma> ");
			authors = input.nextLine();
		}

                String title = "";
                do {
			System.out.print( "Enter a title> " );
			title = input.nextLine();
                } while( title.isEmpty() );

		String publisher = "";
		if( type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b") ) {
			System.out.print("Enter a publisher> ");
			publisher = input.nextLine();
		}

		String organizer = "";
		if( type.equalsIgnoreCase("journal") || type.equalsIgnoreCase("j") ) {
			System.out.print("Enter an organizer> ");
			organizer = input.nextLine();
		}

		int year = 0;
		do {
			System.out.print("Enter a year (between 1000 and 9999)>");
			String yearValue = input.nextLine();
			year = yearValue.isEmpty() ? 0 : Integer.parseInt(yearValue);
		} while( year < 1000 || year > 9999 );
                
             
		
		boolean result = true;
		if( type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b") )
			result = addReference( new Book(callNumber, authors, title, publisher, year) );
		else
			result = addReference( new Journal(callNumber, title, organizer, year) );
		if( !result ) 
			System.out.println( "Add failed: there is another reference with the same call number and year" );
                
                
                /*
                Adds the references to a textfile in the following format
                
                type = 'book'
                callnumber = '...'
                authors = '...'
                title = '...'
                publisher = '...'
                year = '...'
                
                ---------------OR---------------
                
                type = 'journal'
                callnumber = '...'
                title = '...'
                organization = '...'
                year = '...'
                
                */
                if (type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b")) {
                
                    write.write(("type = '"+type+"'"));
                    write.newLine();
                    write.write(("callnumber = '"+callNumber+"'"));
                    write.newLine();
                    write.write(("authors = '"+authors+"'"));
                    write.newLine();
                    write.write(("title = '"+title+"'"));
                    write.newLine();
                    write.write(("publisher = '"+publisher+"'"));
                    write.newLine();
                    write.write(("year = '"+year+"'"));
                    write.newLine();
                    
                    write.close();
                    
                }
                
                if (type.equalsIgnoreCase("journal") || type.equalsIgnoreCase("j")) {
                    
                    write.write(("type = '"+type+"'"));
                    write.newLine();
                    write.write(("callnumber = '"+callNumber+"'"));
                    write.newLine();
                    write.write(("title = '"+title+"'"));
                    write.newLine();
                    write.write(("organization = '"+organizer+"'"));
                    write.newLine();
                    write.write(("year = '"+year+"'"));
                    write.newLine();
                    
                    write.close();
                }
            
                
                
                
            // Makes sure the file exists 
            } catch (IOException e) {
                 System.out.println("Error writing to file '"+ fileName + "'");
            }
                
	}

	/* 
	 * Check if a keyword is on a list of tokens
	 */
	private boolean matchedKeyword( String keyword, String[] tokens ) {
		for( int i = 0; i < tokens.length; i++ ) 
			if( keyword.equalsIgnoreCase(tokens[i]) )
				return true;
		return false;
	}

	/*
	 * Check if all keywords are in a string 
	 */
	private boolean matchedKeywords( String[] keywords, String title ) {
		String[] tokens = title.split( "[ ,\n]+" );
		for( int i = 0; i < keywords.length; i++ ) 
			if( !matchedKeyword(keywords[i], tokens) )
				return false;
		return true;
	}

	/*
	 * Search for all books that satisfy a search request
	 */
	private void searchReferences( String callNumber, String[] keywords, int startYear, int endYear ) {
		for( int i = 0; i < references.size(); i++ ) 
			if( (callNumber.equals("") || references.get(i).getCallNumber().equalsIgnoreCase(callNumber)) &&
			    (keywords == null || matchedKeywords(keywords, references.get(i).getTitle())) &&
			    (references.get(i).getYear() >= startYear && references.get(i).getYear() <= endYear) )
				System.out.println( references.get(i) ); 
                
            ArrayList<Reference> results = new ArrayList<Reference>();


            if (keywords != null && keywords.length != 0) {
                String first = keywords[0].toLowerCase();
                ArrayList<Integer> original = map.get(first);
                if (original != null) {
                    ArrayList<Integer> list = new ArrayList<Integer>(original);

                    
                    
                    /*
                    Searches the hashmap for title keywords and prints them
                    if a match is found
                    */
                    for (int i = 1; i < keywords.length; i++) {
			ArrayList<Integer> items = map.get(keywords[i]);
			if (items != null) {
                            list.retainAll(items);
			} else {
                            list.clear();
                        }
		}

                    for (Integer index : list) {
                        results.add(references.get(index));
                    }   
                }      
            } else {
                for (Reference reference : references) {
                    results.add(reference);
                }
            }
                for (Reference ref : results) {
                    System.out.println(ref.toString());
                }
	}
	/**
	 * Gather a search request and find the matched books and journals in the related list(s)
	 */ 
	public void search( Scanner input ) {
		
		System.out.print( "Enter a call number> " );
		String callNumber = input.nextLine();

		System.out.print( "Enter title keywords> " );
		String[] keywords = null;
		String line = input.nextLine();
		if( !line.isEmpty() )
			keywords = line.split( "[ ,\n]+" );
                
		int startYear = Integer.MIN_VALUE, endYear = Integer.MAX_VALUE;
		boolean valid;
		do {
			valid = true;
			System.out.print("Enter a time period as startYear-endYear, or year> ");
			line = input.nextLine();
			if( !line.equals("") ) {
				int hyphen = line.indexOf('-');
				if( hyphen < 0 ) 
					startYear = endYear = Integer.parseInt(line);
				else {
					String startValue = line.substring(0, hyphen);
					startYear = startValue.equals("") ? Integer.MIN_VALUE : Integer.parseInt(startValue);
					String endValue = line.substring(hyphen + 1);
					endYear = endValue.equals("") ? Integer.MAX_VALUE : Integer.parseInt(endValue);
					if( startYear > endYear ) 
						valid = false;
				}
			}
		} while( !valid );

		// search for matched references
		System.out.println( "Matched references: " );
		searchReferences( callNumber, keywords, startYear, endYear );
	}
	
        // Main ... Tells user options to choose from
	public static void main( String[] args ) {

            Scanner input = new Scanner( System.in );
            LibrarySearch library = new LibrarySearch();
       	    String command;
            do {
		System.out.print( "Enter add, search, or quit> " );
		command = input.nextLine();
                if( command.equalsIgnoreCase("add") || command.equalsIgnoreCase("a") )
                    library.add( input );
		else if( command.equalsIgnoreCase("search") || command.equalsIgnoreCase("s") )
                    library.search( input );			
		} while( !command.equalsIgnoreCase("quit") && !command.equalsIgnoreCase("q") );
	}
}
