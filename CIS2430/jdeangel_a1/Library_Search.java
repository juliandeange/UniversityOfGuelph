import java.util.Scanner;
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author juliandeangelis
 */
public class Library_Search {
    public static void main (String [] args) {
        
        String choice = ""; 
        String bookCall;
        String bookAuth;
        String bookTitle;
        String bookPub;
        String bookYear;
        
        String joCall;
        String joTitle;         //Declaration of Variables
        String joOrg;
        String joYear;
        
        String sCall;
        String sTitle;
        String sYear;
        
        System.out.println(" ");
        System.out.println("Library search ...");
        
        Library lib = new Library();
        
        Scanner in = new Scanner(System.in);
        
        // Will execute loop until user wants to quit
        while ((choice.equals("quit") == false)) {
            
            System.out.println(" ");
            System.out.println("***********************************************************");
            System.out.println("Would you like to add an entry, search archives, or quit?");
            System.out.println("Please enter:");
            System.out.println("Add");
            System.out.println("Search");
            System.out.println("Quit");
            System.out.println("***********************************************************");
            
        
            choice = in.nextLine();
            choice = choice.toLowerCase();
            
            // will exit the loop
            if (choice.equals("q"))
                break;
            
            /*
            If user wants to add it will take in required fields
            User will be asked if they want to add a book or a journal
            */
            if (choice.equals("add")) {
                System.out.print("Do you want to add a (Book) or (Journal)?");
                String add = in.nextLine();
                add = add.toLowerCase();
                
                // Will add the the book ArrayList
                // Gets user input for fields in object
                if (add.equals("book")) {
                    
                    System.out.print("Call number:");
                    bookCall = in.nextLine();
                    bookCall = bookCall.toLowerCase();
              
                    System.out.print("Author:");
                    bookAuth = in.nextLine();
                    bookAuth = bookAuth.toLowerCase();
                    
                    System.out.print("Title:");
                    bookTitle = in.nextLine();
                    bookTitle = bookTitle.toLowerCase();
                    
                    System.out.print("Publisher:");
                    bookPub = in.nextLine();
                    bookPub = bookPub.toLowerCase();
                    
                    System.out.print("Year:");
                    bookYear = in.nextLine();
                    
                    Book b = new Book(bookCall, bookAuth, bookTitle, bookPub, bookYear);
                    lib.addBook(b);
                    
                }
                
                // Will get user input for fields to add to Journal object
                // Object will be added to the ArrayList for Journals
                else if (add.equals("journal")) {
                    System.out.print("Call number:");
                    joCall = in.nextLine();
                    joCall = joCall.toLowerCase();
                   
                    System.out.print("Title:");
                    joTitle = in.nextLine();
                    joTitle = joTitle.toLowerCase();
                   
                    System.out.print("Organization:");
                    joOrg = in.nextLine();
                    joOrg = joOrg.toLowerCase();
                   
                    System.out.print("Year");
                    joYear = in.nextLine();
                    
                    Journal j = new Journal(joCall, joTitle, joOrg, joYear);
                    lib.addJournal(j);
                  
                }
                
                else {
                    System.out.println("not an option");
                    continue;
                }
            }// end if-add 
            
            //Takes in user input that will search the ArrayLists for matches
            else if (choice.equals("search")) {
            
                System.out.println("Please enter the search fields:");
                System.out.print("Call Number:");
                sCall = in.nextLine();
                sCall = sCall.toLowerCase();
               
                System.out.print("Title:");
                sTitle = in.nextLine();
                sTitle = sTitle.toLowerCase();
               
                System.out.print("Year:");
                sYear = in.nextLine();
               
                System.out.println("Results:");
                System.out.print("********");
                System.out.println(" ");
                System.out.println("Book result(s):  ('Call Number', 'Author', 'Publisher', 'Title', 'Year')");
                System.out.println(" ");
                
                //Compares user entered fields with objects in arrayList
                //and displays the results to the user
                for (Book book: lib.books) {
                   
                    if (sCall.equals(book.getCall())) {
                        System.out.print(book.getCall());
                        System.out.print(", " + book.getAuthor());
                        System.out.print(", " + book.getPublisher());
                        System.out.print(", " + book.getTitle());
                        System.out.print(", " + book.getYear());
                    }
                   
                   if (sTitle.equals(book.getTitle())) {
                        System.out.println(" ");
                        System.out.print(book.getCall());
                        System.out.print(", " + book.getAuthor());
                        System.out.print(", " + book.getPublisher());
                        System.out.print(", " + book.getTitle());
                        System.out.print(", " + book.getYear());
                    }

                   if (sYear.equals(book.getYear())) {
                        System.out.println(" ");
                        System.out.print(book.getCall());
                        System.out.print(", " + book.getAuthor());
                        System.out.print(", " + book.getPublisher());
                        System.out.print(", " + book.getTitle());
                        System.out.print(", " + book.getYear());
                    }
                }
                
                System.out.println(" ");
                System.out.println("Journal result(s):  ('Call Number', 'Title', 'Organization', 'Year')");
                
                //Looks through Journal ArrayList for user input that
                //matches the Strings inside objects
                for (Journal journal : lib.journals) {
                    
                    if (sCall.equals(journal.getCall())) {
                        System.out.println(" ");
                        System.out.print(journal.getCall());
                        System.out.print(", " + journal.getTitle());
                        System.out.print(", " + journal.getOrganization());
                        System.out.print(", " + journal.getYear());
                    }
                    
                    if (sTitle.equals(journal.getTitle())) {
                        System.out.println(" ");
                        System.out.print(journal.getCall());
                        System.out.print(", " + journal.getTitle());
                        System.out.print(", " + journal.getOrganization());
                        System.out.print(", " + journal.getYear());
                    }
                    
                    if (sYear.equals(journal.getYear())) {
                        System.out.println(" ");
                        System.out.print(journal.getCall());
                        System.out.print(", " + journal.getTitle());
                        System.out.print(", " + journal.getOrganization());
                        System.out.print(", " + journal.getYear());
                    }// end sYear if 
                }// end journal loop
            }// end search if
        }// end quit while
    }// end main
}// end class
