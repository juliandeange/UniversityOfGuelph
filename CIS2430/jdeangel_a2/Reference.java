    /*
     * To change this license header, choose License Headers in Project Properties.
     * To change this template file, choose Tools | Templates
     * and open the template in the editor.
     */

    /**
     *
     * @author juliandeangelis
     */

/**
* Class inherits similar functions that existed in both Book and Journal classes
*/
    public class Reference {

        protected String callNumber;
        protected String title;
        protected int year;


        public boolean keyEquals(Reference other) {
            if( other == null )
                return false;
            else
                return callNumber.equalsIgnoreCase(other.callNumber) &&
                                   year == other.year;
            }


            public static boolean valid(String callNumber, String title, int year) {
                    return callNumber != null && !callNumber.isEmpty() && title != null && !title.isEmpty() && year >= 1000 & year <= 9999;
            }

            // Sets call number for reference
            public boolean setCallNumber(String callNumber) {
                if( callNumber == null || callNumber.isEmpty() ) {
                    return false;
            } else {
                    this.callNumber = callNumber;
                    return true;
                    }
            }

            // Sets title for reference object
            public boolean setTitle(String title) {
                if( title == null || title.isEmpty() ) {
                    return false;
                } else {
                    this.title = title;
                        return true;
                    }
            }

            // Sets year for reference object
            public boolean setYear(int year) {
                if( year <1000 || year > 9999 ) {
                    return false;
                } else {
                    this.year = year;
                    return true;
                    }
            }



            public String getCallNumber() {
                    return callNumber;
            }


            public String getTitle() {
                    return title;
            }


            public int getYear() {
                    return year;
            }

    }

