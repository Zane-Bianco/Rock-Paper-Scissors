// Rock, Paper, Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

void displayScores(int humanWins, int computerWins) {
    //Inputs humanWins and computerWins and outputs the Scores within a string
    cout << "Current Scores: \n";
    cout << "Human: " << humanWins << " wins\n";
    cout << "Computer: " << computerWins << " wins\n";
}

string Computer() {
    //Function to determine computer choice
    random_device engine;
    uniform_int_distribution<int>randomInt(0, 2);
    return engine;
    //randomly picks a number from 0 to 2 and then using the index "options" to find the choice associated with each number and return it
}
string Winner(string humanMove, string computerMove) {
    if (humanMove == computerMove) return "Draw";

    if ((humanMove == "Rock" && computerMove == "Scissors") ||
        (humanMove == "Paper" && computerMove == "Rock") ||
        (humanMove == "Scissors" && computerMove == "Paper")) {
        return "Human";
    }

    return "Computer";
}

string playerChoice() {
    string humanMove;
    cout << "Enter your move (Rock, Paper, Scissors, or Quit): \n";
    cin >> humanMove;
    return humanMove;
}
string playerValidation(string humanMove) {
    //Validate Player's choice
    while (humanMove != "Rock" && humanMove != "Paper" && humanMove != "Scissors" && humanMove != "Quit") {
        cout << "Invalid move! Please enter Rock, Paper, Scissors, or Quit: \n";
        cin >> humanMove;
    }

}
int main()
{
     //Seed Your console time to actually randomize computer's choice with rand()
    int humanWins = 0, computerWins = 0;
    string humanMove, computerMove, roundResult, validatedHumanMove;
    string continuePlaying = "y";

    while (continuePlaying == "y") {
        //Get Human's move
        humanMove = playerChoice();
        validatedHumanMove = playerValidation(humanMove);
        if (humanMove == "Quit") {
            break;
        }
        // Get the computer's move
        computerMove = Computer();
        cout << "Computer chose: " << computerMove << endl;

        // Determine the winner of the round
        roundResult = Winner(humanMove, computerMove);
        if (roundResult == "Human") {
            cout << "You win this round!\n";
            humanWins++;
        }
        else if (roundResult == "Computer") {
            cout << "Computer wins this round.\n";
            computerWins++;
        }
        else {
            cout << "This round is a draw.\n";
        }

        // Display current scores
        displayScores(humanWins, computerWins);
    }

    // End of the tournament, declare the winner
    cout << "\nTournament Over!\n";
    displayScores(humanWins, computerWins);

    if (humanWins > computerWins) {
        cout << "Congratulations! You are the tournament winner!\n";
    }
    else if (computerWins > humanWins) {
        cout << "The computer wins the tournament.\n";
    }
    else {
        cout << "The tournament ends in a draw.\n";
    }

    return 0;
}
