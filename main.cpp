#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//globle variables: settings
int  seasize = 10, carrier = 1, battleship = 2, submarine = 3, destroyer = 4;
char displaypc = 'n';
char pcstart = 'y';
char chart[10][10];

char alphabet(int num) {//turn number into character
	switch (num) {
	case 1: return 'A';
	case 2: return 'B';
	case 3: return 'C';
	case 4: return 'D';
	case 5: return 'E';
	case 6: return 'F';
	case 7: return 'G';
	case 8: return 'H';
	case 9: return 'I';
	case 10: return 'J';
	default: return 'A';
	}
}
/*
char number(int num) {
//turn number into character
switch (num) {
case A: return 1;
case B: return 2;
case C: return 3;
case D: return 4;
case E: return 5;
case F: return 6;
case G: return 7;
case H: return 8;
case I: return 9;
case J: return 10;
default: return 0;
}
}
*/
void setting() {
	int option;
	system("cls");
	cout << "\n\n*** Setting Menu ***\n";
	cout << "[1] Who starts first\n[2] Display PC's ships\n[3] Sea size\n[4] Number of ships\n[5] Returnto game menu\n";
	cout << "********************";
	cout << endl << "Option (1 - 5):";
	cin >> option;

	switch (option) {
	case 1:
		system("cls");
		cout << "[1] Who starts first" << endl;
		cout << "Who starts first? ";
		if (pcstart == 'y') cout << "( Player First NOW)" << endl;
		else cout << "( Computer First NOW )" << endl;

		cout << "y: player, n: computer" << endl;
		cout << "Please type here: ";
		cin >> pcstart;
		cout << endl;

		if (pcstart == 'y') cout << "Player First" << endl;
		else if (pcstart == 'n') cout << "Computer First" << endl;
		else {
			
			do {
				cout << "Please enter y or n only" << endl;
				cout << "Please type here: ";
				cin >> pcstart;
				cout << endl;
			} while (pcstart != 'y' && pcstart != 'n');

			if (pcstart == 'y') cout << "Player First" << endl;
			else if (pcstart == 'n') cout << "Computer First" << endl;

		}

		cout << "State Updated" << endl;
		system("pause");
		system("cls");
		setting();
		break;

	case 2:
		system("cls");
		cout << "[2] Display PC's ships" << endl;
		cout << "Display PC's ships? ";
		if (displaypc == 'y') cout << "( Display PC's ships NOW)" << endl;
		else cout << "( Not display PC's ships NOW )" << endl;

		cout << "Display = y or Not display = n" << endl;
		cout << "Please type here: ";
		cin >> displaypc;
		cout << endl;

		if (displaypc == 'y') cout << "Display PC's ships" << endl;

		else if (displaypc == 'n') cout << "Not display PC's ships" << endl;

		else {
			do {
				cout << "Please enter y or n only" << endl;
				cout << "Please type here: ";
				cin >> displaypc;
				cout << endl;
			} while (displaypc != 'y' && displaypc != 'n');

			if (displaypc == 'y') cout << "Display PC's ships" << endl;
			else if (displaypc == 'n') cout << "Not display PC's ships" << endl;

		}

		cout << "state updated" << endl;
		system("pause");
		system("cls");
		setting();
		break;

	case 3:
		system("cls");
		cout << "[3] Sea size" << endl;
		cout << "Set sea size (5 to 10) " << "(NOW is " << seasize << " x " << seasize << ")" << endl;
		cout << "Please type here: ";
		cin >> seasize;

		while (seasize != 5 && seasize != 6 && seasize != 7 && seasize != 8 && seasize != 9 && seasize != 10)
		{
			cout << endl;
			cout << "Sea size should be from 5 to 10 " << endl;
			cout << "Please type here: ";
			cin >> seasize;
		}

		cout << endl;
		cout << "Sea size change to " << seasize << " x " << seasize << endl;
		cout << "state updated" << endl;
		system("pause");
		setting();
		break;




	case 4:
		int total_size;

		system("cls");
		cout << "[4] Number of ships" << endl;

		cout << "Carrier from " << carrier << " change to ";
		cin >> carrier;
		cout << "Battleship from " << battleship << " change to ";
		cin >> battleship;
		cout << "Submarine from " << submarine << " change to ";
		cin >> submarine;
		cout << "Destroyer from " << destroyer << " change to ";
		cin >> destroyer;
		total_size = carrier * 5 + battleship * 4 + submarine * 3 + destroyer * 2;
		
		while (total_size > seasize * seasize)
		{
			system("cls");
			cout << endl;
			cout << "SHIPS SIZE do not exceed the SEA SIZE" << endl;
			cout << "Please try again " << "( Sea Size = " << seasize << " x " << seasize << " )" << endl;
			cout << endl;

			cout << "Carrier from " << carrier << " change to ";
			cin >> carrier;
			cout << "Battleship from " << battleship << " change to ";
			cin >> battleship;
			cout << "Submarine from " << submarine << " change to ";
			cin >> submarine;
			cout << "Destroyer from " << destroyer << " change to ";
			cin >> destroyer;
			total_size = carrier * 5 + battleship * 4 + submarine * 3 + destroyer * 2;

		}

		cout << endl;
		cout << "state updated" << endl;
		system("pause");
		system("cls");
		setting();
		break;

	case 5:
		system("pause");
		system("cls");
		break;

	default: system("cls");
		setting();
		break;

	}
}


void sea() {
	cout << "   ";
	for (int c = 0; c < seasize; c++) {
		cout << right << setw(2) << c;
	}
	cout << endl << "  +-";
	for (int c = 0; c < seasize; c++) {
		cout << "--";
	}
	cout << "+";


	for (int row = 1; row <= seasize; row++) {
		cout << endl << alphabet(row) << " | ";
		for (int col = 1; col <= seasize; col++) {
			cout << chart[row][col] << " ";
		}
		cout << "|";

	}
	cout << endl << "  +-";
	for (int c = 0; c < seasize; c++) {
		cout << "--";
	}
	cout << "+";
}


void clear() {
	for (int c = 1; c <= 10; c++) {
		for (int cc = 1; c <= 10; c++) {
			chart[c][cc] = ' ';
		}
	}
};

void arrange() {
	for (int c = 1; c <= carrier; c++) {
		cout << "Input coordinate of carrier " << c << ": ";
	}
	for (int c = 1; c <= battleship; c++) {}
	for (int c = 1; c <= submarine; c++) {}
	for (int c = 1; c <= destroyer; c++) {}

}

void game() {
	sea();

}

void instructions() {
	// option 3: Instructions 








	system("pause");

}

void credits() {
	// option 4: Credits 
	
	cout << endl;
	cout << "Student Full Name		Student ID		Class" << endl;
	cout << "Choi Yiu Tung			16152710A		202C" << endl;
	cout << "Lee Chung Chak			16070266A		202A" << endl;
	cout << "Hung Kam Chung			16016760A		202B" << endl;
	cout << "Li Man Fung			16091471A		202B" << endl;
	cout << "Leung Kwan Ho			16071890A		202B" << endl;
	cout << "Leung Man Hin			16137324A		202C" << endl;
	cout << endl;

	system("pause");

}

int main() {

	int choice;

	cout << "\nWelcome Captain!";//welcome massage
	cout << "\n\n*** Game Menu ***\n";
	cout << "[1] Start Game\n[2] Setting\n[3] Instruction\n[4] Credits\n[5] Exit\n";
	cout << "*****************";
	cout << endl << "Option (1 - 5):";
	cin >> choice;

	switch (choice) {
	case 1:	game();
		system("cls");
		main();
		break;

	case 2:	setting();
		system("cls");
		main();
		break;

	case 3:	instructions();
		system("cls");
		main();
		break;

	case 4:	credits();
		system("cls");
		main();
		break;

	case 5:	break;

	default: system("cls");
		cout << "Please input 1-5" << endl;
		main();

	}

}
