#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, computerChoice;
    const char *choices[] = {"Rock", "Paper", "Scissors"};

    // Seed the random number generator
    srand(time(0));

    // Display the options to the user
    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Please select:\n");
    printf("0 - Rock\n");
    printf("1 - Paper\n");
    printf("2 - Scissors\n");
    printf("Enter your choice (0-2): ");
    scanf("%d", &userChoice);

    // Validate user input
    if (userChoice < 0 || userChoice > 2) {
        printf("Invalid choice! Please select 0, 1, or 2.\n");
        return 1; // Exit the program with an error code
    }

    // Generate a random number between 0 and 100
    int randomNum = rand() % 101;

    // Determine computer's choice based on the random number
    if (randomNum >= 0 && randomNum <= 33) {
        computerChoice = 0; // Rock
    } else if (randomNum > 33 && randomNum <= 66) {
        computerChoice = 1; // Paper
    } else {
        computerChoice = 2; // Scissors
    }

    // Display choices
    printf("You chose: %s\n", choices[userChoice]);
    printf("Computer chose: %s\n", choices[computerChoice]);

    // Determine the winner
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 0 && computerChoice == 2) || // Rock beats Scissors
               (userChoice == 1 && computerChoice == 0) || // Paper beats Rock
               (userChoice == 2 && computerChoice == 1)) { // Scissors beats Paper
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}