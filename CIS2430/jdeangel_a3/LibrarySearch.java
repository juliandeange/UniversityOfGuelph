
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.io.*;

import javax.swing.*;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Color;
import javax.swing.Box;
import java.awt.event.ItemListener;
import java.awt.*;

/**
 * LibrarySearch class
 *
 * @author Fei Song / Julian De Angelis
 *
 * A class that adds, maintains, and searches for books and journals.
 *
 * Copyright: This code is intended to help you with the implementation of your
 * assignments for CIS*2430 (Fall 2015). You are allowed to use it as a starting
 * point for your Assignments Two and Three, but you need to acknowledge it in
 * your README file. Any use, sharing, or re-distribution beyond this course is
 * prohibited.
 */
public class LibrarySearch extends Reference {

    /**
     * Theses variables are static so that the TextFields an comboboxes can be
     * accessed from anywhere in the class when adding or searching the
     * references
     */
    static LibrarySearch library = new LibrarySearch();

    static JButton reset = new JButton("Reset");
    static JButton add = new JButton("Add");
    static JButton searchButton = new JButton("Search");
    static JTextArea messages = new JTextArea(7, 10);

    static JComboBox choices = new JComboBox();

    static JTextField callField = new JTextField("", 20);
    static JTextField titleField = new JTextField("", 20);
    static JTextField sYearTF = new JTextField("", 20);
    static JTextField eYearTF = new JTextField("", 20);
    static JComboBox refTypeB = new JComboBox();
    static JTextField bCallNoTF = new JTextField("", 20);
    static JTextField bAuthTF = new JTextField("", 20);
    static JTextField bTitleTF = new JTextField("", 20);
    static JTextField bPubTF = new JTextField("", 20);
    static JTextField bYearTF = new JTextField("", 20);
    static JTextField jCallTF = new JTextField("", 20);
    static JTextField jTitleTF = new JTextField("", 20);
    static JTextField jOrgTF = new JTextField("", 20);
    static JTextField jYearTF = new JTextField("", 20);

    static ButtonHandler listener = new ButtonHandler();

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
    private boolean addReference(Reference reference) {

        for (int i = 0; i < references.size(); i++) {
            if (references.get(i).keyEquals(reference)) {
                return false;
            }
        }
        references.add(reference);

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
     * Function gets required fields form textFields and creates object to be
     * added to the arrayList
     *
     * Function also exports the added data to a text file "AddedRefs.txt" in
     * the root directory
     */
    public void add() {
        String type = String.valueOf(refTypeB.getSelectedItem());
        String fileName = "AddedRefs.txt";

        //String selected = String.valueOf(refTypeB.getSelectedItem());
        messages.setText("");

        try {

            // Opens file and creates a writer to the file
            FileWriter f = new FileWriter(fileName, true);
            BufferedWriter write = new BufferedWriter(f);

            write.newLine();

            /* gets input from TextField */
            String callNumber = "";
            if (type.equalsIgnoreCase("book")) {
                callNumber = bCallNoTF.getText();
                if (callNumber.isEmpty()) {
                    messages.append("You need enter a value for Call Number\n");
                    return;
                }
            } else if (type.equalsIgnoreCase("journal")) {
                callNumber = jCallTF.getText();
            }
            if (callNumber.isEmpty()) {
                messages.append("You need to enter a value for Call Number\n");
                return;
            }

            String authors = "";
            if (type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b")) {
                authors = bAuthTF.getText();
            }

            String title = "";
            if (type.equalsIgnoreCase("book")) {
                title = bTitleTF.getText();
                if (title.isEmpty()) {
                    messages.append("You need to enter a value for title\n");
                    return;
                }
            } else if (type.equalsIgnoreCase("journal")) {
                title = jTitleTF.getText();
                if (title.isEmpty()) {
                    messages.append("You need to enter a value for title\n");
                    return;
                }
            }

            String publisher = "";
            if (type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b")) {
                publisher = bPubTF.getText();
            }

            String organizer = "";
            if (type.equalsIgnoreCase("journal") || type.equalsIgnoreCase("j")) {
                organizer = jOrgTF.getText();
            }

            int year = 0;
            do {
                String yearValue = "";

                if (type.equalsIgnoreCase("book")) {
                    yearValue = bYearTF.getText();
                    if (yearValue.isEmpty()) {
                        messages.append("You need to enter a value for year\n");
                        return;
                    }
                } else if (type.equalsIgnoreCase("journal")) {
                    yearValue = jYearTF.getText();
                    if (yearValue.isEmpty()) {
                        messages.append("You need to enter a value for year\n");
                        return;
                    }
                }
                try {
                    year = yearValue.isEmpty() ? 0 : Integer.parseInt(yearValue);
                } catch (NumberFormatException e) {
                    messages.append("You entered an invalid year format\n");
                    return;
                }

                if (year < 1000 || year > 9999) {
                    messages.append("Year must be >= 1000 and <= 9999");
                    return;
                }

            } while (year < 1000 || year > 9999);

            boolean result = true;
            if (type.equalsIgnoreCase("book") || type.equalsIgnoreCase("b")) {
                result = addReference(new Book(callNumber, authors, title, publisher, year));
            } else {
                result = addReference(new Journal(callNumber, title, organizer, year));
            }
            if (!result) {
                System.out.println("Add failed: there is another reference with the same call number and year");
            }

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

                write.write(("type = '" + type + "'"));
                write.newLine();
                write.write(("callnumber = '" + callNumber + "'"));
                write.newLine();
                write.write(("authors = '" + authors + "'"));
                write.newLine();
                write.write(("title = '" + title + "'"));
                write.newLine();
                write.write(("publisher = '" + publisher + "'"));
                write.newLine();
                write.write(("year = '" + year + "'"));
                write.newLine();

                write.close();

            }

            if (type.equalsIgnoreCase("journal") || type.equalsIgnoreCase("j")) {

                write.write(("type = '" + type + "'"));
                write.newLine();
                write.write(("callnumber = '" + callNumber + "'"));
                write.newLine();
                write.write(("title = '" + title + "'"));
                write.newLine();
                write.write(("organization = '" + organizer + "'"));
                write.newLine();
                write.write(("year = '" + year + "'"));
                write.newLine();

                write.close();
            }

            // Makes sure the file exists 
        } catch (IOException e) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

    }

    /**
     * Check if a keyword is on a list of tokens
     */
    private boolean matchedKeyword(String keyword, String[] tokens) {
        for (int i = 0; i < tokens.length; i++) {
            if (keyword.equalsIgnoreCase(tokens[i])) {
                return true;
            }
        }
        return false;
    }

    /**
     * Check if all keywords are in a string
     */
    private boolean matchedKeywords(String[] keywords, String title) {
        String[] tokens = title.split("[ ,\n]+");
        for (int i = 0; i < keywords.length; i++) {
            if (!matchedKeyword(keywords[i], tokens)) {
                return false;
            }
        }
        return true;
    }

    /**
     * Search for all books that satisfy a search request
     */
    private void searchReferences(String callNumber, String[] keywords, int startYear, int endYear) {

        messages.setText("");

        for (int i = 0; i < references.size(); i++) {
            if ((callNumber.equals("") || references.get(i).getCallNumber().equalsIgnoreCase(callNumber))
                    && (keywords == null || matchedKeywords(keywords, references.get(i).getTitle()))
                    && (references.get(i).getYear() >= startYear && references.get(i).getYear() <= endYear)) {

            }
        }

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
            messages.append(ref.toString() + "\n");
        }
    }

    /**
     * Gets Strings from TextFields in the search panel and looks through the
     * arraylist and hashmap
     */
    public void search() {

        String callNumber = callField.getText();

        String[] keywords = null;
        String line = titleField.getText();
        if (!line.isEmpty()) {
            keywords = line.split("[ ,\n]+");
        }

        int startYear = Integer.MIN_VALUE, endYear = Integer.MAX_VALUE;
        boolean valid;
        do {
            valid = true;

            String sYear = sYearTF.getText();
            String eYear = eYearTF.getText();

            if (sYear.equals(eYear)) {
                line = sYear;
            } else {
                line = (sYearTF.getText() + "-" + eYearTF.getText());
            }
            try {
                if (!line.equals("")) {
                    int hyphen = line.indexOf('-');
                    if (hyphen < 0) {
                        startYear = endYear = Integer.parseInt(line);
                    } else {

                        String startValue = line.substring(0, hyphen);
                        startYear = startValue.equals("") ? Integer.MIN_VALUE : Integer.parseInt(startValue);
                        String endValue = line.substring(hyphen + 1);
                        endYear = endValue.equals("") ? Integer.MAX_VALUE : Integer.parseInt(endValue);
                        messages.setText("");
                        if (startYear > endYear) {
                            messages.append("The start year must be less than or equal to the end year, try again");
                            sYearTF.setText("");
                            eYearTF.setText("");
                            valid = false;
                        }
                    }
                }

            } catch (NumberFormatException e) {
                sYearTF.setText("");
                eYearTF.setText("");
                messages.setText("You entered an invalid year format");
                return;
            }

        } while (!valid);
        // search for matched references
        searchReferences(callNumber, keywords, startYear, endYear);
    }

    public static void main(String[] args) {

        // Following creates frame and initisl GUI
        JFrame main = new JFrame();
        main.setLayout(new BorderLayout());
        main.setSize(600, 500);
        main.setTitle("Library Search");
        choices.addItem("Commands");
        choices.addItem("Add References");
        choices.addItem("Search References");
        JPanel cmdPanel = new JPanel();
        JLabel label = new JLabel("Commands: ");
        cmdPanel.add(label);
        cmdPanel.add(choices);

        main.add(cmdPanel, BorderLayout.NORTH);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel welcome = new JPanel(new BorderLayout());
        JLabel wLabel = new JLabel("Welcome to Library Search, please choose add or search "
                + "references from above", SwingConstants.CENTER);
        welcome.add(wLabel, BorderLayout.CENTER);
        main.add(welcome, BorderLayout.CENTER);

        JPanel buttons = new JPanel(new GridLayout(3, 0));
        buttons.add(reset);
        buttons.add(add);
        buttons.add(searchButton);

        add.addActionListener(listener);
        reset.addActionListener(listener);
        searchButton.addActionListener(listener);

        main.add(buttons, BorderLayout.EAST);

        JPanel mesPanel = new JPanel(new BorderLayout());
        JLabel mesLabel = new JLabel("Messages / Search Results: ");
        mesPanel.add(mesLabel, BorderLayout.NORTH);
        mesPanel.add(messages, BorderLayout.CENTER);
        messages.setEditable(false);

        main.add(mesPanel, BorderLayout.SOUTH);

        JPanel search = new JPanel(new BorderLayout());
        JLabel searchLabel = new JLabel("Searching References");
        search.add(searchLabel, BorderLayout.NORTH);

        JPanel searchOptions = new JPanel(new GridLayout(4, 0));

        JPanel callPanel = new JPanel();
        JLabel callLabel = new JLabel("Call No: ");
        callPanel.add(callLabel);
        callPanel.add(callField);
        searchOptions.add(callPanel);

        JPanel titlePanel = new JPanel();
        JLabel titleLabel = new JLabel("           Title Keywords: ");
        titlePanel.add(titleLabel);
        titlePanel.add(titleField);
        searchOptions.add(titlePanel);

        JPanel sYearP = new JPanel();
        JLabel sYearL = new JLabel("   Start Year: ");

        sYearP.add(sYearL);
        sYearP.add(sYearTF);
        searchOptions.add(sYearP);

        JPanel eYearP = new JPanel();
        JLabel eYearL = new JLabel("  End Year: ");

        eYearP.add(eYearL);
        eYearP.add(eYearTF);
        searchOptions.add(eYearP);

        JPanel addRef = new JPanel(new BorderLayout());
        JPanel addRefPanel = new JPanel();
        JLabel addRefL = new JLabel("Adding a Reference                                     ");
        addRefPanel.add(addRefL);

        JPanel bookFPanel = new JPanel(new GridLayout(6, 0));

        JPanel bType = new JPanel();
        JLabel bTypeL = new JLabel("Type: ");

        refTypeB.addItem("book");
        refTypeB.addItem("journal");
        bType.add(bTypeL);
        bType.add(refTypeB);
        bookFPanel.add(bType);
        addRefPanel.add(bTypeL);
        addRefPanel.add(refTypeB);
        addRef.add(addRefPanel, BorderLayout.NORTH);

        JPanel bCallNoP = new JPanel();
        JLabel bCallL = new JLabel("Call No: ");
        bCallNoP.add(bCallL);
        bCallNoP.add(bCallNoTF);
        bookFPanel.add(bCallNoP);

        JPanel bAuth = new JPanel();
        JLabel bAuthL = new JLabel("Authors: (Separated by a comma ',')");
        bAuth.add(bAuthL);
        bAuth.add(bAuthTF);
        bookFPanel.add(bAuth);

        JPanel bTitle = new JPanel();
        JLabel bTitleL = new JLabel("Title: ");
        bTitle.add(bTitleL);
        bTitle.add(bTitleTF);
        bookFPanel.add(bTitle);

        JPanel bPub = new JPanel();
        JLabel bPubL = new JLabel("Publisher: ");
        bPub.add(bPubL);
        bPub.add(bPubTF);
        bookFPanel.add(bPub);

        JPanel bYear = new JPanel();
        JLabel bYearL = new JLabel("Year: ");
        bYear.add(bYearL);
        bYear.add(bYearTF);
        bookFPanel.add(bYear);

        addRef.add(bookFPanel, BorderLayout.CENTER);

        JPanel journalFPanel = new JPanel(new GridLayout(5, 0));

        JPanel jCall = new JPanel();
        JLabel jCallL = new JLabel("Call No: ");
        jCall.add(jCallL);
        jCall.add(jCallTF);
        journalFPanel.add(jCall);

        JPanel jTitle = new JPanel();
        JLabel jTitleL = new JLabel("Title: ");
        jTitle.add(jTitleL);
        jTitle.add(jTitleTF);
        journalFPanel.add(jTitle);

        JPanel jOrg = new JPanel();
        JLabel jOrgL = new JLabel("Organization: ");
        jOrg.add(jOrgL);
        jOrg.add(jOrgTF);
        journalFPanel.add(jOrg);

        JPanel jYear = new JPanel();
        JLabel jYearL = new JLabel("Year: ");
        jYear.add(jYearL);
        jYear.add(jYearTF);
        journalFPanel.add(jYear);

        welcome.setVisible(true);
        search.setVisible(false);
        addRef.setVisible(false);
        search.add(searchOptions, BorderLayout.WEST);

        add.setEnabled(false);
        reset.setEnabled(false);
        searchButton.setEnabled(false);

        main.setVisible(true);

        //Listener to ComboBox for add and search
        choices.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected;
                selected = String.valueOf(choices.getSelectedItem());

                if (selected.equals("Add References")) {
                    main.remove(welcome);
                    main.remove(search);
                    search.setVisible(false);
                    welcome.setVisible(false);
                    main.add(addRef, BorderLayout.CENTER);
                    addRef.setVisible(true);

                    add.setEnabled(true);
                    reset.setEnabled(true);
                    searchButton.setEnabled(false);
                } else if (selected.equals("Search References")) {
                    main.remove(welcome);
                    main.remove(addRef);
                    addRef.setVisible(false);
                    welcome.setVisible(false);
                    main.add(search, BorderLayout.CENTER);
                    search.setVisible(true);

                    add.setEnabled(false);
                    reset.setEnabled(true);
                    searchButton.setEnabled(true);
                }
            }
        });

        //Listener to adding a book or journal refernce
        refTypeB.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected;
                selected = String.valueOf(refTypeB.getSelectedItem());

                if (selected.equals("book")) {
                    journalFPanel.setVisible(false);
                    addRef.remove(journalFPanel);
                    bookFPanel.setVisible(true);
                    addRef.add(bookFPanel);
                } else if (selected.equals("journal")) {
                    bookFPanel.setVisible(false);
                    addRef.remove(bookFPanel);
                    journalFPanel.setVisible(true);
                    addRef.add(journalFPanel);
                }
            }
        });
    }

    //Button Listener for add, reset and search buttons
    private static class ButtonHandler implements ActionListener {   //action listener class

        public void actionPerformed(ActionEvent e) {

            if (e.getSource() == add) {
                String selected = String.valueOf(refTypeB.getSelectedItem());
                //String selected = String.valueOf(choices.getSelectedItem());
                if (selected.equals("book")) {
                    library.add();
                } else if (selected.equals("journal")) {
                    library.add();
                }

            } else if (e.getSource() == reset) {
                String search = String.valueOf(choices.getSelectedItem());
                String selected = String.valueOf(refTypeB.getSelectedItem());
                if (selected.equals("book")) {
                    bCallNoTF.setText("");
                    bAuthTF.setText("");
                    bTitleTF.setText("");
                    bPubTF.setText("");
                    bYearTF.setText("");
                } else if (selected.equals("journal")) {
                    jCallTF.setText("");
                    jTitleTF.setText("");
                    jOrgTF.setText("");
                    jYearTF.setText("");
                }
                if (search.equals("Search References")) {
                    callField.setText("");
                    titleField.setText("");
                    sYearTF.setText("");
                    eYearTF.setText("");
                }
            } else if (e.getSource() == searchButton) {
                library.search();
            }
        }
    }
}
