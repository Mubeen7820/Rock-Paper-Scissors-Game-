#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string getComputerChoice() {
    string choices[3] = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}

string decideWinner(string user, string computer) {
    if (user == computer) return "It's a tie!";
    if ((user == "rock" && computer == "scissors") ||
        (user == "paper" && computer == "rock") ||
        (user == "scissors" && computer == "paper")) {
        return "You win!";
    }
    return "Computer wins!";
}

string toLower(string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string normalizeInput(string input) {
    input = toLower(input);
    if (input == "r") return "rock";
    if (input == "p") return "paper";
    if (input == "s") return "scissors";
    if (input == "rock" || input == "paper" || input == "scissors") return input;
    return ""; 
}

int main() {
    srand(time(0)); 
    string userInput, userChoice, computerChoice, playAgain;

    cout << "Welcome to Rock-Paper-Scissors Game!" << endl;
    cout << "Enter R for Rock, P for Paper, S for Scissors or use full words." << endl;

    do {
        cout << "\nEnter your choice (R/P/S or rock/paper/scissors): ";
        cin >> userInput;

        userChoice = normalizeInput(userInput);

        if (userChoice == "") {
            cout << "Invalid input! Please try again." << endl;
            continue;
        }

        computerChoice = getComputerChoice();

        cout << "You chose: " << userChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;
        cout << decideWinner(userChoice, computerChoice) << endl;

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == "y" || playAgain == "Y");

    cout << "\nThanks for playing! Goodbye!" << endl;
    return 0;
}

