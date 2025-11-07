//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "/public/colors.h"
#include <thread>
#include < limits>
#include <chrono>
//add dictionary later

using namespace std;



//lets say the character class has light attack of 5
void lightAttack(Character& player, Character& enemy) { 
	cout << "You sent out a light Attack!\n"; 
	cout << "You did 5 attack damage to " << enemy.getName() << endl; 
	enemy.setHp(enemy.getHp - 5);
} 


//lets say the character class has light attack of 8
void heavyAttack() { 
	cout << "You sent out a heavy Attack!\n"; 
	cout << "You did 8 attack damage to " << enemy.getName() << endl; 
	enemy.setHp(enemy.getHp - 8);
}


void menu(const Character& player) { //placeholder function will expand upon further later...
	int temp;
	cout << "1) Stats (press 1)\n"; 
	cout << "2) Inventory (press 2)\n" 
	cout << "3) Quit (press 3)\n";
	cin >> temp; 
	if(temp == 1) { //waiting for the character class to be uploaded :p
		cout << "Name: " << player.getName() << endl; 
		cout << "Class: " << player.getClass() << endl; //needs to be implemented, just return string of the class type "Knight"
		cout << "HP: " << player.getHP() "/" << player.getMaxHp() << endl; 
		cout << "Defense: " << player.getDef() << endl; 
		cout << "Speed: " << player.getSpd() << endl; //needs to be implemented 
	}
	else if (temp == 2) { 
		cout << "Items in Inventory: \n"; 
		cout << "1) Map\n"; 
		cout << "2) " << player.getWeapon() << endl; //needs to be implemented
		cout << "3) Healing Potion (+5 HP)" << endl; 

	}
}


void puzzleWordle() {
	int attempts = 0;
	string guess;
	cout << "Enter 5 letter word" << endl;
	while (attempts < 6) {
		cin >> guess;
		if (guess.size() > 5 || guess.size() < 5) {
			cout << "TRY AGAIN" << endl;
			continue;
		}
		if (guess == "horse") {
			cout << "YOU WIN!" << endl;
			break;
		} else {
			cout << guess << endl;
			//remember to add color to the letters here later
		}
		attempts = attempts + 1;
	}
}
//// utlities///
void printSlow(cont string& s, int ms_per_char) { for (char c : s) {cout << c << flush; if (ms_per_char > 0 && ! isspace(static_cast < unsigned char >(c))) {this_thread::sleep_for(chrono::milliseconds(ms_per_char));
}
	}
		}

/// enter button
 void pauseEnter() { cout "\n(Press Enter) ";
	 cin.ignore(numeric_limits<streamsize>::max(), '\n'); }


	 /// valid inputs 
	 int readInt( int lo, int hi) { while (true) { cout << "> ";
		 int x;
		 if (cin >> x && x >= lo && x <= hi) {cin.ignore(numeric_limits<streamsize>::max(),'\n');
			 return x;
		 }
		 
	 cout << "Please enter number from " << lo << " to " << hi << ".\n";
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
	 }
	 }
///Read a non-empty line
string readLineNonEmpty(cont string& prompt) { while (true) {while (true) { cout << prompt;
	string s;
	if(!getline(cin,s)) return "Player";
	// trim spaces
	size_t a = s.find_first_not_of(" \t\r\n");
	size_t b = s.find_last_not_of(" \t\r\n");
	if (a != strong::npos) { return s.substr(a, b - a + 1);
	} cout << "please enter something .\n";
}

////Data model (player info "class 'difficulty"

class RPG {
	public:
	void run () { bool running = true; 
		while (running) { clearScreen();
			banner();
			cout << " 1) New Game\n";
			cout << " 2) Continue\n";
			cout << " 3) options\n";
			cout << " 4) credits\n";
			cout << " 5) Exit\n";
			int c = readInt(1,5);
			switch (c) {
				case 1: newGame(); break;
				case 2: continueGame(); break;
				case 3: optinousMenus(); break;
				case 4: credits (); break;
				case 5: running = false; break;
				}
		}
		cout << "\nFarewell, adventure

 



int main() {

	puzzleWordle();
}
