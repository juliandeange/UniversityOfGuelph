
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
public class Journal {
    
    private String call;
    private String title;
    private String org;
    private String year;
    
    /*
    Creates an object for a Journal to be added to its ArrayList
    */
    public Journal (String c, String t, String o, String y) {
        this.call = c;
        this.title = t;
        this.org = o;
        this.year = y;
    }
    
    public String getCall(){
        return call;
    }
    
    public String getTitle(){
        return title;
    }
    
    public String getOrganization(){
        return org;
    }
    
    public String getYear(){
        return year;
    }
       
}
