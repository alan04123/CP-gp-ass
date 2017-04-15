#include<iostream>
#include<iomanip>
using namespace std;

//globle variables: settings
int seasize = 10, carrier = 1, battleship = 2, submarine = 3, destroyer = 4;
bool displaypc = false, pcstart = false;
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
        default: return '*';
    }
}

char number(int num) {//turn number into character
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

void setting() {
    int option;
    cout << "\n\n*** Setting Menu ***\n";
    cout << "[1] Who starts first\n[2] Display PC's ships\n[3] Sea size\n[4] Number of ships\n[5] Return to game menu\n";
    cout << "********************";
    cout << endl << "Option (1 - 5):";
    cin >> option;
    switch (option) {
        case 1:	cout << "Let PC start first?(Input 1 for yes 0 for no)"; 
		cin >> pcstart; cout<<"setting complete"; 
		setting();
		break;
		    
        case 2: cout << "Display PC's ships?;(Input 1 for yes 0 for no)"; 
		cin >> displaypc; 
		cout << "setting complete";
		setting();
		break;
		    
        case 3: cout << "Set sea size(5 to 10)"; 
		cin >> seasize;
		cout << "setting complete"; 
		setting();
		break;
		    
        case 4: cout << "Carrier " << carrier << " change to ";
           	cin >> carrier;
            	cout << "Battleship " << battleship << " change to ";
            	cin >> battleship;
            	cout << "Submarine " << submarine << " change to ";
            	cin >> submarine;
            	cout << "Destroyer " << destroyer << " change to ";
            	cin >> destroyer;
		cout << "setting complete"; 
		setting();
		break;
            
        case 5:break;
		    
        default: cout << "Please input 1-5";
		setting();
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
    
    
    for (int row = 1; row<= seasize;row++) {
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

void arrange(){
	int xtemp; ytemp, direction;
    for (int c = 1; c <= carrier; c++) {
        cout << "Input coordinate of carrier(e.g. C2) "<<c<<":";
		

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
	char back;





	cout << "Please enter y to return to the Game Menu" << endl;
	cin >> back;
	if (back != 'y') instructions();
}

void credits() {
	// option 4: Credits 
	char back;

	cout << "Student Full Name		Student ID		Class" << endl;
	cout << "Choi Yiu Tung			16152710A		202C" << endl;
	cout << "Lee Chung Chak			16070266A		202A" << endl;
	cout << "Hung Kam Chung			16016760A		202B" << endl;
	cout << "Li Man Fung			16091471A		202B" << endl;
	cout << "Leung Kwan Ho			16071890A		202B" << endl;
	cout << "Leung Man Hin			16137324A		202C" << endl;
	cout << endl;

	cout << "Please enter y to return to the Game Menu" << endl;
	cin >> back;
	if (back != 'y') credits();	
}


int main() {
	char hi;
	cin >> hi;
	cout << number(hi);
    int choice;
    cout << "\nWelcome Captain!";//welcome massage
    cout << "\n\n*** Game Manu ***\n";
    cout << "[1] Start Game\n[2] Setting\n[3] Instruction\n[4] Credits\n[5] Exit\n";
    cout << "*****************";
    cout << endl << "Option (1 - 5):";
    cin >> choice;
    switch (choice) {
	case 1:	game();
		break;

	case 2:	setting();
		main();
		break;

	case 3:	instructions();
		main();
		break;

	case 4:	credits();
		main();
		break;

	case 5:	break;

	default: cout << "Please input 1-5"; 
		main();

	}
    
}
