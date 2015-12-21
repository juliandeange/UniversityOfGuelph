CIS2430 - Assignment 3 - README - Julian De Angelis

**Base code with modifications provided by the professor

General Problem
***************
- This program allows the user to add a book or journal (of type <Reference>) object
to an arrayList using a GUI
- The title keyword are split and added to a hashmap in addition
- The hashmap allows the program to more efficiently search for references that exist
- The program will read TextFields from the GUI and write added references to a file

Features
********
- Takes in user input from the Textfields (Exceptions will be handled (Number format, year range, missing fields))
- The user can select entering a book or journal form the GUI
- Textfields are pulled when the ‘add’ button is pressed
- Creates and object from the data and adds to an arrayList
- Title keywords are tokenized and added to the hashmap to improve search speed
- When adding a reference, the fields entered from the user are written to a text file in the root directory


*** Program is ‘defensive’ as in the user must enter appropriate data in order to add references. Suitable error messages are printed to the TextArea

LIMITATIONS
***********
- TextArea doesn’t have scroll bars


Possible Improvements
*********************
- Adding scrollbars to not disrupt the GUI


