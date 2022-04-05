////
// Name: Josh Valerio
// Section: CS 131 - 2830
// Program Name: Steer the rat into the right hole
//
// Description: The goal of this program is to show our knowledge from Lectures 1 to 4.
//				This program is designed to output a new outcome via the console every time the user plays with the rand function
//				The program will continuing looping as long as the user has greater than $0
////

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	srand(3);
	int inhand_cash = 500;
	int bet_amount = 0; 
	int userHole;
	int cheeseHole;
	char exitCheck;

	cout << "My name is Josh Valerio." << endl;
	cout << "Program 2: Steer the rat into the right hole." << endl;
	cout << setfill('-') << setw(45) << "-" << endl << endl;
	cout << "Your goal is to correctly guide a rat to a hole with cheese.\n"
		<< "Each guess requires cash, but you're free to leave whenever with your earnings." << endl << endl;
	cout << setw(45) << "-" << endl << endl;

	// Receiving and checking user's bet
	while (inhand_cash > 0) {
		cout << "You have $ " << inhand_cash << endl;
		cout << "Make a bet $ ";
		while (!(cin >> bet_amount) || (bet_amount <= 0) || (bet_amount > inhand_cash)) {
			cout << "Enter a valid bet in numerical form! $ ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		inhand_cash = inhand_cash - bet_amount;

	// Receving and checking user's hole guess
		cout << "\nGuess the hole with the cheese inside!\n\n";
		cout << setfill(' ') << "Hole 1" << setw(16) << "Hole 2" << setw(22) << "Hole 3\n";
		cout << "You guess hole ";
		cin >> userHole;
		cheeseHole = rand() % 3 + 1;
		cout << "The cheese was in hole " << cheeseHole << endl;
		if (userHole == cheeseHole) {
			cout << "You guessed right!" << endl;
			inhand_cash = inhand_cash + 2 * bet_amount;
		}
		else {
			cout << "You guessed wrong!" << endl;
		}

	// Checking if the user has zero dollars
		if (inhand_cash <= 0) {
			break;
		}

		cout << "You have $ " << inhand_cash<< endl;

	// Asking user if they want to play again
		cout <<	"Would you like to continue playing? (y/n)";
		cin >> exitCheck;
		if (exitCheck == 'n' || exitCheck == 'N') {
			break;
		}
		cout << setw(45) << "-" << endl;
	}

	cout << "Thanks for playing! You had $ " << inhand_cash << ".\n";

	system("pause");
	return 0;
}