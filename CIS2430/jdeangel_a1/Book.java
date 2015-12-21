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
public class Book {
    
    private String call;
    private String author;
    private String title;
    private String publisher;
    private String year;
  
    /*
    Creates an object for a Book to be added to its ArrayList
    */
    public Book (String c, String a, String t, String p, String y) {
    
        this.call = c;
        this.author = a;
        this.title = t;
        this.publisher = p;
        this.year = y;
        
    }
    
    public String getCall(){
        return call;
    }
    
    public String getAuthor(){
        return author;
    }
    
    public String getTitle(){
        return title;
    }
    
    public String getPublisher(){
        return publisher;
    }
    
    public String getYear(){
        return year;
    }
    
}
