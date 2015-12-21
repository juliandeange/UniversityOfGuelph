#include <stdio.h>
#include <ctype.h>

int check4Pangram(int isPangram);
int missingLetters(char lUsed[26]);

int main(){

    printf("\n");

    //Declaration of variables
    char uPhrase;
    int letIndexNum, isPangram;
    char letUsed[26] = { 0 };

    printf("Please enter a sentence:\n");

    /*
    - Function continues to get input from the user until
    the enter button is pressed
    - If character is not an 'alphabetical' value, it is discarced
    - Alphbetical values are converted to lower case
    */
    while(1){

        uPhrase = getchar();
        if (uPhrase == EOF || uPhrase == '\n') break;

        if (!isalpha(uPhrase)){
            continue;
        }

        uPhrase = tolower(uPhrase); 


        /*
        - Takes one character at a time and calculates it alphabetical
        position between 0 and 25
        - Gives letter position in array a value of 1 (means that the
        specific letter has been used at least once)
        */

        letIndexNum = uPhrase - 'a';
        letUsed[letIndexNum] = 1;
        isPangram = 1;

        /*
        - If any values in the letter array are not assigned a
        value of 1 (ie. that letter was not used)
        - Phrase is not a pangram
        */
        for (int i = 0; i < 26; ++i){
            if (letUsed[i] == 0)
                isPangram = 0;
        }
     }

    check4Pangram(isPangram);
    missingLetters(letUsed);

    printf("\n");
    return 0;

}


int check4Pangram(int isPangram){
    
        //Print statements, if pangram or not
    
        if (isPangram == 1){
            printf("You entered a pangram\n");
            printf("No letters");
        }
        else if (isPangram == 0){
            printf("You did not enter a pangram\n");
            printf("The following letter(s):\n");
        }

        return 0;

}

int missingLetters(char lUsed[26]){


    /*
    - If value in array is '= 0', the position in array is
    added to the ASCII value of 'a' and the character value 
    is printed

    ex/ 'c' was not used ... c = index number 2 in array...
        ... 2 + 'a'(97) = 'c'(99) 

    */
    for(int i = 0; i < 26; ++i){
        if (lUsed[i] == 0){
            char missingL = i + 'a';
            printf("%c", missingL);
            printf(" ");
        }
    }
    printf(" are missing\n");
    return 0;

}
