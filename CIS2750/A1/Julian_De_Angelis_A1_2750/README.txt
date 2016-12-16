Julian De Angelis 0873694
CIS 2750 - A1

All functions written have been tested and should be working properly. The
only issue occurred on occasion is in proccessStrings(). If a string being processed
has many consecutive newline ‘\n’ or ‘\r’ characters at the end of a string, it
may not be processed correctly … This is an isolated incident.

An example of a string that could cause this issue is: 
“This is a string\n\n\n\n\r\r\n\n\n”.

***This is the only known issue I came across when testing that I am aware of, it only happened sometimes.