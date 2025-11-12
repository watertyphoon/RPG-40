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

//Banished Knight
class Knight {
  private:
	bool isAlive;
	string name; //player name
	const string className;
	string characterSymbol;
	int heavyAtk;
	int lightAtk;
	int baseAtk;
	int hp;
	int maxHP; //to keep track of max hp so healing potions dont pass set max hp
	int def; // val incoming attacks are reduced by
	int spd; //aka intitive
	int mp;  //mana for attacks
	int maxMP;
  public:
	Knight(string playerName) {
		bool isAlive = true;
		string name = playerName;
		const string className = "Knight";
		string characterSymbol = "K";
		int heavyAtk = 30;
		int lightAtk = 15;
		int baseAtk = 5;
		int hp = 150;
		int maxHP = hp;
		int def = 3;
		int spd = 3;
		int mp = 100;
		int maxMP = mp;
	}
	void setName(string newName) {
		name = newName;
	}
	void setHeavyAtk(int newHeavyAtk) {
		heavyAtk = newHeavyAtk;
	}
	void setLightAtk(int newLightAtk) {
		lightAtk = newLightAtk;
	}
	void setHP(int newHP) {
		hp = newHP;
	}
	void setMaxHP(int newMaxHP) {
		maxHP = newMaxHP;
	}
	void setDef(int newDef) {
		def = newDef;
	}
	void setSpd(int newSpd) {
		spd = newSpd;
	}
	void setMP(int newMP) {
		mp = newMP;
	}
	void setMaxMP(int newMaxMP) {
		maxMP = newMaxMP;
	}
	string getName() const {
		return name;
	}
	string getClassName() {
		return className;
	}
	int getHeavyAtk() {
		return heavyAtk;
	}
	int getLightAtk() {
		return lightAtk;
	}
	int getBaseAtk() {
		return baseAtk;
	}
	int getHP() {
		return hp;
	}
	int getMaxHP() {
		return maxHP;
	}
	int getDef() {
		return def;
	}
	int getSpd() {
		return spd;
	}
	int getMP() {
		return mp;
	}
	int getMaxMP() {
		return maxMP;
	}
	bool heavyAtkMP() { //check if you have enough mana to do the attack
		if (mp - 10 >= 0) {
			mp -= 10;
			return true;
		}
		return false;
	}
	bool lightAtkMP() {
		if (mp - 6 >= 0) {
			mp -= 6;
			return true;
		}
		return false;
	}
	void hurt(int damage) {
		hp -= damage;
		if (hp <= 0) {
			isAlive = false; //needs to be implemented after fighting mechanic
			// will just stop gameplay output "YOU DIED! GAME OVER" and quit the game
		}
	}
};

//Shadow Mage
class Mage {
  private:
	bool isAlive;
	string name; //player name
	const string className;
	string characterSymbol;
	int heavyAtk;
	int lightAtk;
	int baseAtk;
	int hp;
	int maxHP; //to keep track of max hp so healing potions dont pass set max hp
	int def; // val incoming attacks are reduced by
	int spd; //aka intitive
	int mp;  //mana for attacks
	int maxMP;
  public:
	Mage(string playerName) {
		bool isAlive = true;
		string name = playerName;
		const string className = "Mage";
		string characterSymbol = "M";
		int heavyAtk = 40;
		int lightAtk = 20;
		int baseAtk = 5;
		int hp = 100;
		int maxHP = hp;
		int def = 2;
		int spd = 2;
		int mp = 150;
		int maxMP = mp;
	}
	void setName(string newName) {
		name = newName;
	}
	void setHeavyAtk(int newHeavyAtk) {
		heavyAtk = newHeavyAtk;
	}
	void setLightAtk(int newLightAtk) {
		lightAtk = newLightAtk;
	}
	void setHP(int newHP) {
		hp = newHP;
	}
	void setMaxHP(int newMaxHP) {
		maxHP = newMaxHP;
	}
	void setDef(int newDef) {
		def = newDef;
	}
	void setSpd(int newSpd) {
		spd = newSpd;
	}
	void setMP(int newMP) {
		mp = newMP;
	}
	void setMaxMP(int newMaxMP) {
		maxMP = newMaxMP;
	}
	string getName() const {
		return name;
	}
	string getClassName() {
		return className;
	}
	int getHeavyAtk() {
		return heavyAtk;
	}
	int getLightAtk() {
		return lightAtk;
	}
	int getBaseAtk() {
		return baseAtk;
	}
	int getHP() {
		return hp;
	}
	int getMaxHP() {
		return maxHP;
	}
	int getDef() {
		return def;
	}
	int getSpd() {
		return spd;
	}
	int getMP() {
		return mp;
	}
	int getMaxMP() {
		return maxMP;
	}
	bool heavyAtkMP() { //check if you have enough mana to do the attack
		if (mp - 20 >= 0) {
			mp -= 20;
			return true;
		}
		return false;
	}
	bool lightAtkMP() {
		if (mp - 8 >= 0) {
			mp -= 8;
			return true;
		}
		return false;
	}
	void hurt(int damage) {
		hp -= damage;
		if (hp <= 0) {
			isAlive = false; //needs to be implemented after fighting mechanic
			// will just stop gameplay output "YOU DIED! GAME OVER" and quit the game
		}
	}
};

//Puppet
class Puppet {
  private:
	bool isAlive;
	string name; //player name
	const string className;
	string characterSymbol;
	int heavyAtk;
	int lightAtk;
	int baseAtk;
	int hp;
	int maxHP; //to keep track of max hp so healing potions dont pass set max hp
	int def; // val incoming attacks are reduced by
	int spd; //aka intitive
	int mp;  //mana for attacks
	int maxMP;
  public:
	Puppet(string playerName) {
		bool isAlive = true;
		string name = playerName;
		const string className = "Puppet";
		string characterSymbol = "P";
		int heavyAtk = 25;
		int lightAtk = 12;
		int baseAtk = 5;
		int hp = 120;
		int maxHP = hp;
		int def = 3;
		int spd = 4;
		int mp = 120;
		int maxMP = mp;
	}
	void setName(string newName) {
		name = newName;
	}
	void setHeavyAtk(int newHeavyAtk) {
		heavyAtk = newHeavyAtk;
	}
	void setLightAtk(int newLightAtk) {
		lightAtk = newLightAtk;
	}
	void setHP(int newHP) {
		hp = newHP;
	}
	void setMaxHP(int newMaxHP) {
		maxHP = newMaxHP;
	}
	void setDef(int newDef) {
		def = newDef;
	}
	void setSpd(int newSpd) {
		spd = newSpd;
	}
	void setMP(int newMP) {
		mp = newMP;
	}
	void setMaxMP(int newMaxMP) {
		maxMP = newMaxMP;
	}
	string getName() const {
		return name;
	}
	string getClassName() {
		return className;
	}
	int getHeavyAtk() {
		return heavyAtk;
	}
	int getLightAtk() {
		return lightAtk;
	}
	int getBaseAtk() {
		return baseAtk;
	}
	int getHP() {
		return hp;
	}
	int getMaxHP() {
		return maxHP;
	}
	int getDef() {
		return def;
	}
	int getSpd() {
		return spd;
	}
	int getMP() {
		return mp;
	}
	int getMaxMP() {
		return maxMP;
	}
	bool heavyAtkMP() { //check if you have enough mana to do the attack
		if (mp - 8 >= 0) {
			mp -= 8;
			return true;
		}
		return false;
	}
	bool lightAtkMP() {
		if (mp - 3 >= 0) {
			mp -= 3;
			return true;
		}
		return false;
	}
	void hurt(int damage) {
		hp -= damage;
		if (hp <= 0) {
			isAlive = false; //needs to be implemented after fighting mechanic
			// will just stop gameplay output "YOU DIED! GAME OVER" and quit the game
		}
	}
};


/*lets say the character class has light attack of 5
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
*/
vector<string> mapCreation() {
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

void displayMap(vector <vector<string>> map, const int columns, const int rows) {//displays map....if other maps are made in a simalar fashion then this functions work with that as well
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

void riddles3() {
	string answer;
	cout << "To get through me you must answer my riddles three" << endl;;
	cout << "If you manage to answer them I'll join your party" << endl;
	cout << "Else you will fall victim to my blade" << endl;
	cout << "What has a bank but not funds in it" << endl;
	cout << "What moves about but has no body" << endl;
	cout << "And does...um..other liquidy things" << endl;
	while (true) {
		cout << "What has a bank but no funds in it" << endl;
		cout << "What moves about but has no body" << endl;
		cout << "And does...um..other liquidy things" << endl;
		cin >> answer;
		if (answer == "river" || answer == "River") {
			cout << "Correct, but don't get too confident for this is my easiest riddle" << endl;
			break;
		} else {
			cout << "Inncorrect, try again" << endl;
		}
	}
	cout << "What has hands but no fingers" << endl;
	cout << "What has a face but no flesh or facial feature" << endl;
	cout << "And um...uuuh...other mechinical metallic features" << endl;
	while (true) {
		cin >> answer;
		if (answer == "clock" || answer == "Clock") {
			cout << "Correct again, bravo" << endl;
			cout << "Quite the head you have on your shoulders their buddy" << endl;
			cout << "But don't be hasty for my thrid riddle will surely best you" << endl;
			break;
		} else {
			cout << "See, told you to keep your head about you" << endl;
			cout << "Try again buster" << endl;
		}
	}
	cout << "Great job coming this far but brace yourself for here comes my final riddle" << endl;
	cout << "<in a moncrome voice>" << endl;
	cout << "A man goes out in heavy rain with no protection" << endl;
	cout << "Though, his hair doesn't get wet!" << endl;
	cout << "How did he accomplish such feat of strenght" << endl;
	cin.ignore();
	while (true) {
		getline(cin, answer);
		if (answer == "bald" || answer == "he is bald" || answer == "he has no hair" || answer == "no hair") {
			cout << "HAHAHAHAHA" << endl;
			cout << "No one has ever evaded my blade before" << endl;
			cout << "Now as stated my blade shall now be yours" << endl;
			cout << RED << " <SYSTEM> " << RESET << GREEN << "congratulations " << RESET << YELLOW << "<OBJECT> ";
			cout << RESET << GREEN  << "Phantom-Knight boss has been defeated and has joined your party" << RESET << endl;
			break;
		} else {
			cout << "Now you are witnessing why no one has ever evaded my blade" << endl;
			cout << "Struggle like your life depends on it" << endl;
			cout << "Try again" << endl;
		}
	}
}

int main() {
	string temp;
	vector <string> tempMap = mapCreation();
	vector <vector <string>> map;//our new and improved map
	/*for (int i = 0; i < map.size(); i++) { //keeping this here for now, for testing purposes
		cout << map.at(i) << endl;
	}*/
	//babySudoku();
	temp = tempMap.at(0);
	const int ROWS = temp.size();
	const int COLS = map.size();
	map.resize(COLS, vector<string>(ROWS, ""));
	for (int i = 0; i < COLS; i++) {// i and j will act as you would x and y cords
		temp = tempMap.at(i);
		for (int j = 0; j < temp.size(); j++) {
			map.at(i).at(j) = temp.at(j);
		}
	}
	cout << "row size " << ROWS << endl;
	cout << "column size" << COLS << endl;
	displayMap(map, COLS, ROWS);
	riddles3();
	//the line above ^ displays the whole map, for testing purpases only at the moment

}
