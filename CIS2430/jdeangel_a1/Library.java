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
public class Library {
    
    // ArrayLists to hold objects for either a book or a Journal
    ArrayList<Book> books = new ArrayList<Book>();
    ArrayList<Journal> journals = new ArrayList<Journal>();
    
    /*
    addBook and addJournal will add object to their
    corresponding ArrayLists
    */
    
    public void addBook(Book b) {
        this.books.add(b);
    }
    
    public void addJournal(Journal j) {
        this.journals.add(j);
    }
    
}
