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
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
//add dictionary later

using namespace std;

class Character {
  private:
	int hp;
	int maxHp;
  public:
	//Public data
	string name = "Among us";
	string className = "Gambler";
	int x, y;
	int def;
	int spd;
	//Getters
	int getHP() {
		return hp;
	}
	int getMaxHp() {
		return maxHp;
	}
	//Setters
	void setHP(int newHp, bool ignoreMax = false) {
		hp = newHp;
		if (hp > maxHp && !ignoreMax) {
			hp = maxHp;
		}
	}
	void setMaxHp(int newMax) {
		maxHp = newMax;
		if (hp > maxHp) {
			hp = maxHp;
		}
	}

	//Methods
	void hurt(int damage, bool ignoreMax = false) { //Yes you can deal negative to heal the character.
		hp -= damage;
		if (hp > maxHp && !ignoreMax) {
			hp = maxHp;
		}
	}
	bool isDead() {
		return hp < 0;
	}

	//Consturcter thing.
	Character(int health = 100, string itsName = "NO NAME", int posX = -1, int  posY = -1) {
		maxHp = health;
		hp = maxHp;
		name = itsName;
		x = posX;
		y = posY;
	}
};

//lets say the character class has light attack of 5
void lightAttack(Character& player, Character& enemy) {
	cout << "You sent out a light Attack!\n";
	cout << "You did 5 attack damage to " << enemy.name << endl;
	enemy.hurt(5);
}


//lets say the character class has light attack of 8
void heavyAttack(Character& player, Character& enemy) {
	cout << "You sent out a heavy Attack!\n";
	cout << "You did 8 attack damage to " << enemy.name << endl;
	enemy.hurt(8);
}


void menu(const Character& player) { //placeholder function will expand upon further later...
	int temp;
	cout << "1) Stats (press 1)\n";
	cout << "2) Inventory (press 2)\n";
	cout << "3) Quit (press 3)\n";
	set_raw_mode(false);
	while (true) {
		cin >> temp;
		clearscreen();
		movecursor(0, 0);
		if (temp == 1) { //waiting for the character class to be uploaded :p
			cout << "Name: " << player.name << endl;
			//cout << "Class: " << player.class << endl; //needs to be implemented, just return string of the class type "Knight"
			//cout << "HP: " << player.getHP() "/" << player.getMaxHp() << endl;
			//cout << "Defense: " << player.getDef() << endl;
			//cout << "Speed: " << player.getSpd() << endl; //needs to be implemented
		} else if (temp == 2) {
			cout << "Items in Inventory: \n";
			cout << "1) Map\n";
			//cout << "2) " << player.getWeapon() << endl; //needs to be implemented
			cout << "3) Healing Potion (+5 HP)" << endl;
		} else {
			break;
		}
	}

}

vector <string> mapCreation() {
	vector <string> mapData;
	ifstream map("Maps.csv");
	string temp;
	while (map >> temp) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp.find(",") != string::npos) {
				temp.replace(temp.find(","), 1, "");
			}
		}
		mapData.push_back(temp);
	}
	return mapData;
}

void displayMap(vector <vector<string>> map, int columns, int rows) {//displays map....if other maps are made in a simalar fashion then this functions work with that as well
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			cout << map.at(i).at(j);
		}
		cout << endl;
	}
}

string sudokuAnswers(int row, int column) {
	string answer;
	vector <vector<string>> board = {
		{"2", "4", "1", "3"},
		{"3", "1", "4", "2"},
		{"4", "3", "2", "1"},
		{"1", "2", "3", "4"}
	};
	answer = board.at(row - 1).at(column - 1);
	return answer;
}

void babySudoku() {
	vector <vector<string>> board(4, vector<string>(4, "*"));
	board.at(0).at(0) = "2";
	board.at(1).at(2) = "4";
	board.at(2).at(1) = "3";
	board.at(3).at(3) = "4";
	int userRow = 0;
	int userColumn = 0;
	int solved = 0;
	int bounds = 0;
	string guess;
	string answer;
	string temp;
	cout << "Guess I'll go a little easy on you" << endl;
	cout << "Lets see if you can beat me in this battle of minds" << endl;
	while (true) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				temp = board.at(i).at(j);
				if (isdigit(static_cast<unsigned char>(temp.at(0)))) {
					cout << GREEN << board.at(i).at(j) << RESET;
					solved = solved + 1;
				} else {
					cout << RED << board.at(i).at(j) << RESET;
				}
			}
			cout << endl;
		}
		if (solved == 16) {
			cout << "I can't believe it you beat me!" << endl;
			cout << RED << "SYSTEM" << GREEN << "<congrats you beat boss Yuki-Onna>" << RESET << endl;
			break;
		}
		solved = 0;
		cout << "choose which square you want to edit" << endl;
		cin >> userRow >> userColumn;
		if (userRow == 1 && userColumn == 1) {
			cout << "You idiot! That square is your free space!" << endl;
			continue;
		} else if (userRow == 2 && userColumn == 3) {
			cout << "You idiot! That square is your free space!" << endl;
			continue;
		} else if (userRow == 3 && userColumn == 2) {
			cout << "You idiot! That square is your free space!" << endl;
			continue;
		} else if (userRow == 4 && userColumn == 4) {
			cout << "You idiot! That square is your free space!" << endl;
			continue;
		} else if (userRow > 4 || userRow <= 0 || userColumn > 4 || userColumn <= 0) {
			cout << "Your hand gets slapped" << endl;
			cout << "Hey stop writing on the table, you brainles savage!!!" << endl;
			continue;
		} else if (!cin) {
			cout << "You know that isn't a number right?" << endl;
			continue;
		}
		cout << "Make your feeble attempt to answer" << endl;
		cin >> guess;
		bounds = stoi(guess);
		if (bounds <= 0 || bounds > 4) {
			cout << "Congrats you have exceeded my expectations" << endl;
		} else if (!isdigit(static_cast<unsigned char>(guess.at(0)))) {
			cout << "Are you writing in a different language cause that ain't a number" << endl;
		}
		answer = sudokuAnswers(userRow, userColumn);
		if (answer == guess) {
			cout << "That is surprising you got something right" << endl;
			board.at(userRow - 1).at(userColumn - 1) = answer;
		} else {
			cout << "HAHAHAH just as I expected" << endl;;
		}
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
	string temp;
	vector <string> map = mapCreation();
	vector <vector <string>> cords;//our new and improved map
	/*for (int i = 0; i < map.size(); i++) { //keeping this here for now, for testing purposes
		cout << map.at(i) << endl;
	}*/
	babySudoku();
	/*temp = map.at(0);
	int rowSize = temp.size();
	int columnSize = map.size();
	cords.resize(columnSize, vector<string>(rowSize, ""));
	for (int i = 0; i < columnSize; i++) {// i and j will act as you would x and y cords
		temp = map.at(i);
		for (int j = 0; j < temp.size(); j++) {
			cords.at(i).at(j) = temp.at(j);
		}
	}*/

	//displayMap(cords, columnSize, rowSize);
	//the line above ^ displays the whole map, for testing purpases only at the moment

}
