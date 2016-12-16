Julian De Angelis 0873694
CIS 2750 - A3
-------------------------

GENERAL NOTES
-------------

> a3.php loads a webpage with 2 buttons being Convert and Upload along the top

> Below are 2 list of .txt and .html files that are in the ./files directory
  of where a3.php is being loaded from

> Buttons are fully functional, but open separate tabs to upload and convert 
  files instead of a popup window

> Uploading a file adds the file from the local computer to the ./files directory
  from where a3.php is being ran
  (** User is allowed to upload any file **)

> Convert button will ask user to enter a text file from a list of text files
  stored on the server. It will only output a .html file to the ./files folder
  if the file typed in exists, otherwise nothing will occur (C program handles
  files that dont exist)

> When a file is uploaded to the server, or converted the a3.php needs to be
  refreshed to show the new files

> Clicking on a .txt or .html file will hyperlink it to the page displaying
  it properly


REQUIREMENTS AND OTHER NOTES
----------------------------
> When converting a file, the .txt files MUST be in the ./files folder. My C
  program is written such that it looks for the file in a ./files folder.
  EX/ user wants to convert "test.txt", click convert button, type "test.txt"
      and C program looks for "test.txt" in ./files of where a3.php is ran.

> On my computer I needed to run "chmod 777 files/" and "chmod -R files/" to give
  full permissions to .txt and .html in the ./files so that my a3.php is able to read and write files to and from. Again, this depends on the directory in which
  it is being ran in.

> Used "chmod -R 777 /srv/www/jdeangel/" but this would have to be to the
  directory where the files are stored

> There should be no issues memory leaks when ran with valgrind

