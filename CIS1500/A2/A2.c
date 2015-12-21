/********************************************A2.c****************************
Student Name: Julian De Angelis              Student Number:  0873694
Date: October 17, 2014                       Course Name: CIS1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){

    int uChoice;
    int cChoice;
    int uWins = 0;
    int cWins = 0;
    int nTies = 0;
    int nGames;
    int pGames;
    
    printf("Game of Rock Paper Scissors\n");
    printf("Rock crushes Scissors, Paper covers Rock, and Scissors cuts Paper\n");
    printf("1 = Rock    2 = Paper    3 = Scissors\n");
    printf("How many games do you want to play?\n");
    scanf("%d",&nGames);     
    printf("\n");

    for (int i = 0; i < nGames; i = i+1){
    
        pGames = pGames + 1;
    
        do{
            srand(time(NULL));
            cChoice = (rand() % 3) + 1;

            printf("\n");

            printf("Game Number %d\n",pGames);
            
            printf("Whats your choice\n");
            printf("1 = Rock    2 = Paper    3 = Scissors\n");
            scanf("%d",&uChoice);

   
            if (uChoice == 1 && cChoice == 2){
                // Computer Wins
                printf("The computer chose Paper\n");
                printf("The computer wins\n");
                cWins++;
        }

            else if (uChoice == 1 && cChoice == 3){
                // User Wins
                printf("The computer chose Scissors\n");
                printf("You Win!\n");
                uWins++;
        }

            else if (uChoice == 2 && cChoice == 1){
                // User Wins
                printf("The computer chose Rock\n");
                printf("You Win!\n");
                uWins++;
        }

            else if (uChoice == 2 && cChoice == 3){
                // Computer Wins
                printf("The computer chose Scissors\n");
                printf("The computer wins\n");
                cWins++;
        }

            else if (uChoice == 3 && cChoice == 1){
                // Computer Wins
                printf("The computer chose Rock\n");
                printf("The computer wins\n");
                cWins++;
        }

            else if (uChoice == 3 && cChoice == 2){
                // User Wins
                printf("The computer chose Paper\n");
                printf("You Win!\n");
                uWins++;

        }

            else if (uChoice == 1 && cChoice == 1){
                //Tie
                printf("You both chose Rock\n");
                printf("Tie Game\n");
                nTies++;
        }    

            else if (uChoice == 2 && cChoice == 2){
                //Tie
                printf("You both chose Paper\n");
                printf("Tie Game\n");
                nTies++;
        }

            else if (uChoice == 3 && cChoice == 3){
                //Tie
                printf("You both chose Scissors\n");
                printf("Tie Game\n");
                nTies++;
        }

            else{
                printf("You entered an invalid value\n");
                printf("Try again\n");
                
        }

    }while (uChoice > 3 || uChoice <1);

    }// end for loop

    printf("\n");
    printf("You won %d time(s)\n",uWins);
    printf("The computer won %d time(s)\n",cWins);
    printf("The game was a tie %d time(s)\n",nTies);
    printf("Thanks for playing!\n");

    return 0;
}// end main
