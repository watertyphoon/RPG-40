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
#include <chrono>
#include <thread>
#include <sstream>
#include <string>
#include <cctype>
//add dictionary later
using namespace std;

class Moves {
	public:
		string name;
		string disc;
		int cost;
		int dmg;

		Moves(string atkName = "Just Attack",  int mp = 0, int atk = 1, string atkDisc = "strike dealing ") {
			name = atkName;
			disc = atkDisc;
			cost = mp;
			dmg = atk;
		}
};

class Player {
	private:
		//Private
		int hp;
		int maxHp; //to keep track of max hp so healing potions dont pass set max hp
		int mp; //mana for attacks
		int maxMp;
	public:
		//Public variables.
		string name; //player name
		string className;
		string symbol;
		vector<Moves> atk;
		int def; //val incoming attacks are reduced by
		int spd; //aka intitive

		//Setters
		void setHp(int newHp) {
			hp = newHp;
			if(hp > maxHp) {
				hp = maxHp;
			}
		}
		void setMaxHp(int newMaxHp) {
			maxHp = newMaxHp;
			if(hp > maxHp) {
				hp = maxHp;
			}
		}
		void setMp(int newMp) {
			mp = newMp;
			if(mp > maxMp) {
				mp = maxMp;
			}
		}
		void setMaxMp(int newMaxMp) {
			maxMp = newMaxMp;
			if(mp > maxMp) {
				mp = maxMp;
			}
		}
		//Getters
		int getHp() {
			return hp;
		}
		int getMaxHp() {
			return maxHp;
		}
		int getMp() {
			return mp;
		}
		int getMaxMp() {
			return maxMp;
		}
		bool isDead() {
			return hp < 0;
		}
		//Functions/Methods
		void hurt(int dmg) {
			hp -= dmg;
		}
		void attack(Player target, int choice = 0) {
			Moves move = atk.at(choice);
			if(move.cost <= mp) {
				target.hurt(move.dmg);
				mp -= move.cost;
			}
		}
		

		//Consturcter
		Player(string playerName = "You", string playerClass = "knight") {
			if(playerClass == "knight") {
				symbol = "K";
				atk = {{"slash",0,5}, {"light atk",6,15}, {"Smite",10,30}};
				hp = 150;
				maxHp = hp;
				def = 3;
				spd = 3;
				mp = 100;
				maxMp = mp;
			}
			if(playerClass == "mage") {
				symbol = "M";
				atk = {{"bonk",0,5}, {"magic missile",8,20}, {"FIREBALL",20,40}};
				hp = 100;
				maxHp = hp;
				def = 2;
				spd = 2;
				mp = 150;
				maxMp = mp;
			}
			if(playerClass == "puppet") {
				symbol = "P";
				atk = {{"desperation slap",0,5}, {"light atk",3,12}, {"heavy atk",8,25}};
				hp = 120;
				maxHp = hp;
				def = 3;
				spd = 4;
				mp = 120;
				maxMp = mp;
			}
			else {
				className = "knight";
				symbol = "K";
				atk = {{"slash",0,5}, {"light atk",6,15}, {"Smite",10,30}};
				hp = 150;
				maxHp = hp;
				def = 3;
				spd = 3;
				mp = 100;
				maxMp = mp;
			}
		}
};

//Banished Knight
//Shadow Mage
//Puppet

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

void displayMap(vector<vector<string>> map) {//displays map....if other maps are made in a simalar fashion then this functions work with that as well
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++) {
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

void loreItems(int item) {//random items that the player will find scattered around the map that will hint to the world outside and your purpose
	//1 is a chared notebook
	if (item == 1) {
		cout << "As you pick up the near blackedn notebook it crumbles to ashes" << endl;
		cout << "The only thing being left behind a small piece of paper no bigger than a gold coin" << endl;
		cout << "In that piece there is a couple words you can barely make out" << endl;
		cout << "-est subje-" << endl;
		cout << "Though you don't want to dwell on it too long and drop it to the floor and start leaving" << endl;
		cout << "But no matter how much further you walk away you can't shake off the ominous feeling radiating deep from within your stomach" << endl;
	}
}

void printSlowly(string s) {
	for (char c : s) {
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}


void quit() {
	printSlowly("Quitting? Already? Welp, seeya...");
	exit(0);
}





int main() {
	string temp;
	vector <string> map = mapCreation();
	vector <vector <string>> cords;//our new and improved map
	/*for (int i = 0; i < map.size(); i++) { //keeping this here for now, for testing purposes
		cout << map.at(i) << endl;
	}*/
	//babySudoku();
	temp = map.at(0);
	int rowSize = temp.size(); //const?
	int columnSize = map.size(); // const?
	int prevRow = 0;
	int prevColumn = 0;
	int playerRow = 0;
	int playerColumn = 0;
	int ecounters = 2;
	cords.resize(columnSize, vector<string>(rowSize, ""));
	for (int i = 0; i < columnSize; i++) {// i and j will act as you would x and y cords
		temp = map.at(i);
		for (int j = 0; j < temp.size(); j++) {
			cords.at(i).at(j) = temp.at(j);
			if (cords.at(i).at(j) == "?") {
				playerRow = j;
				playerColumn = i;
			}
		}
	}

	clearscreen();
	movecursor(0, 0);
	show_cursor(false);
	string name; //name holds player name, strtemp hold temporary string to print slowly, and choice is the character class
	int choice = -1;
	printSlowly("You awake to a room you are unfamiliar with, missing your name and how you got here...\n");
	printSlowly("What name would like to go by?\n");
	show_cursor(true);
	cin >> name;
	cout << endl;
	show_cursor(false);
	printSlowly("hmmm.\n");
	//strtemp = name + ". It suits you, well alright " + name + " which class would you like to be?\n";
	printSlowly(name + ". It suits you, well alright " + name + " which class would you like to be?\n");
	printSlowly("1) Knight\n");
	printSlowly("2) Mage\n");
	printSlowly("3) Puppet\n");
	printSlowly("(press 1, 2, 3, or any other key to quit)\n");
	cin >> choice;
	cout << endl;
	if(!cin || choice > 3) quit();
	
	vector<string> choiceHolder = {"knight", "mage", "puppet"};
	Player player(name, choiceHolder.at(choice - 1));
	strtemp = "Good choice. You are going to be the " + player.symbol + " , Good Luck!.";
	printSlowly(strtemp);
	cout << endl;

	
	this_thread::sleep_for(chrono::milliseconds(2500));
	movecursor(0, 0);
	clearscreen();
	cout << "row size " << rowSize << endl;
	cout << "column size" << columnSize << endl;
	displayMap(cords);
	cout << "player location: " << playerRow << "    " << playerColumn << endl;
	set_raw_mode(true);
	show_cursor(false);
	prevRow = playerRow;
	prevColumn = playerColumn;
	while (true) {
		int m = toupper(quick_read());
		if (m == 'W' || m == UP_ARROW) {
			playerColumn--;
		}
		if (m == 'S' || m == DOWN_ARROW) {
			playerColumn++;
		}
		if (m == 'A' || m == LEFT_ARROW) {
			playerRow--;
		}
		if (m == 'D' || m == RIGHT_ARROW) {
			playerRow++;
		}
		cords.at(playerColumn).at(playerRow) = "?";
		cords.at(prevColumn).at(prevRow) = ".";
		if (!(playerRow == prevRow && playerColumn == prevColumn)) {
			clearscreen();
			movecursor(0, 0);
			displayMap(cords);
		}
		//ecounters = ecounters * 2;
		prevRow = playerRow;
		prevColumn = playerColumn;
	}
	//	cout << "row size " << ROWS << endl;
//	cout << "column size" << COLS << endl;
//	displayMap(map, COLS, ROWS);
//	riddles3();
	//the line above ^ displays the whole map, for testing purpases only at the moment

}












