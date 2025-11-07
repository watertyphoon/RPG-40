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

int main() {
	puzzleWordle();
}
