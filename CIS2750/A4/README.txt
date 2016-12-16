Julian De Angelis 0873694
CIS 2750 - A4
-------------------------

GENERAL NOTES
-------------

****UNTAR WITH: “tar -xf A4.tar”

> a4.php loads a webpage with 3 buttons being Convert, Upload, and DB Store

> Below are 2 list of .txt and .html files that are in the ./files directory
  and those stored in the database (which have just the name from the name
  column in the database)

> Buttons are fully functional

> Uploading a file adds the file from the local computer to the ./files directory
  from where a4.php is being ran
  (** User is allowed to upload any file **)

> Convert button will ask user to enter a text file from a list of text files
  stored on the server. It will only output a .html file to the ./files folder
  if the file typed in exists, otherwise nothing will occur (C program handles
  files that dont exist)

> When a file is uploaded to the server, converted, or DB Stored the a4.php 
  needs to be refreshed to show the new files

> Clicking on a .txt or .html file will hyperlink it to the page displaying
  it properly

> Database table is named "HTMLTable"

> db.c is compiled in addition to a4.c when make is typed


REQUIREMENTS AND OTHER NOTES
----------------------------
> When converting a file, the .txt files MUST be in the ./files folder. My C
  program is written such that it looks for the file in a ./files folder.
  EX/ user wants to convert "test.txt", click convert button, type "test.txt"
      and C program looks for "test.txt" (of files/test.txt) in ./files of 
      where a3.php is ran.

> The proper permissions need to be applied to the files directory (having
  rx for files and rwx for directories), .txt .html and .info files in 
  order for my program files to be able to access them and modify or 
  write and read to folders neccessary

> There should be no issues memory leaks when ran with valgrind

> When using DB Store it adds the flag -db on the command line. My program (if
  ran form the command line) looks at argv[2] to be -db for adding to database
  EX/    ./a4 FILE.txt -db

