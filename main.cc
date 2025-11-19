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
#include <cstdlib>
#include <ctime>
//add dictionary later
using namespace std;

class Moves {
  private:
	string name;
	int mpCost;
	int dmg;

  public:
	Moves();
	Moves(string atkName, int mp, int atk);
	void setMoves(string atkName, int mp, int atk);
	string getMoveName();
	int getDMG();
	int getMPCost();
};

Moves::Moves() {
	name = "";
	mpCost = 0;
	dmg = 0;
}
Moves::Moves(string atkName, int mp, int atk) {
	setMoves(atkName, mp, atk);
}
void Moves::setMoves(string atkName,  int mp, int atk) {
	name = atkName;
	mpCost = mp;
	dmg = atk;
}

int Moves::getDMG() {
	return dmg;
}
string Moves::getMoveName() {
	return name;
}
int Moves::getMPCost() {
	return mpCost;
}

class Player {
  private:
	//Private
	string name;
	string className;
	string symbol;
	int hp;
	int maxHp; //to keep track of max hp so healing potions dont pass set max hp
	int mp; //mana for attacks
	int maxMp;
	int spd;
	int def;
	vector <Moves> playerAttacks;
  public:
	//Setters
	Player createPlayer(string playerName, string playerClass);
	void printPlayerMoves();
	void setSymbol(string playerSymbol);
	void setHp(int newHp);
	void setMaxHp(int newMaxHp);
	void setMp(int newMp);
	void setMaxMp(int newMaxMp);
	void setSPD(int speed);
	void setDef(int defesnse);
	void setPlayerAttacks(vector <Moves> moves);
	void setClass(string playerClass);
	void setName(string playerName);
	//Getters
	int getHp();
	int getMaxHp();
	int getMp();
	int getMaxMp();
	int getSPD();
	int getDef();
	int getPower(int choice);
	int getCost(int choice);
	string getSymbol();
	string getClass();
	string getName();
};
void Player::printPlayerMoves() {
	for (int i = 0; i < playerAttacks.size(); i++) {
		cout << BLUE << (i + 1) << "): ";
		cout << playerAttacks.at(i).getMoveName() << endl;
		cout << "DAMAGE: " << playerAttacks.at(i).getDMG() << endl;
		cout << "MP COST: " << playerAttacks.at(i).getMPCost() << endl;
		cout << RESET << endl;
	}
}
void Player::setHp(int newHp) {
	hp = newHp;
}
void Player::setMaxHp(int newMaxHp) {
	maxHp = newMaxHp;
}
void Player::setMp(int newMp) {
	mp = newMp;
}
void Player::setMaxMp(int newMaxMp) {
	maxMp = newMaxMp;
}
void Player::setSPD(int speed) {
	spd = speed;
}
void Player::setDef(int defense) {
	def = defense;
}
void Player::setSymbol(string playerSymbol) {
	symbol = playerSymbol;
}
void Player::setPlayerAttacks(vector <Moves> moves) {
	playerAttacks = moves;
}
void Player::setClass(string playerClass) {
	className = playerClass;
}
void Player::setName(string playerName) {
	name = playerName;
}
//Getters
string Player::getClass() {
	return className;
}
string Player::getName() {
	return name;
}
int Player::getHp() {
	return hp;
}
int Player::getMaxHp() {
	return maxHp;
}
int Player::getMp() {
	return mp;
}
int Player::getMaxMp() {
	return maxMp;
}
int Player::getSPD() {
	return spd;
}
int Player::getDef() {
	return def;
}
int Player::getPower(int choice) {
	return playerAttacks.at(choice - 1).getDMG();
}
int Player::getCost(int choice) {
	return playerAttacks.at(choice - 1).getMPCost();
}
string Player::getSymbol() {
	return symbol;
}

//Consturcter
Player Player::createPlayer(string playerName, string playerClass) {
	Player newPlayer;
	vector <Moves> newMoves;
	if (playerClass == "1") {
		newPlayer.setSymbol("K");
		newPlayer.setName(playerName);
		newPlayer.setClass("Knight");
		newMoves = {{"slash", 0, 5}, {"Hurricane Rush", 6, 15}, {"Boreas' Devastation", 10, 30}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(150);
		newPlayer.setMaxHp(150);
		newPlayer.setDef(3);
		newPlayer.setSPD(3);
		newPlayer.setMp(100);
		newPlayer.setMaxMp(100);
		return newPlayer;
	} else if (playerClass == "2") { //if -> else if when player picks 2 the last else statement executes and makes him a knight instead
		newPlayer.setSymbol("M");
		newPlayer.setName(playerName);
		newPlayer.setClass("Mage");
		newMoves = {{"bonk", 0, 5}, {"magic missile", 8, 20}, {"FIREBALL", 20, 40}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(100);
		newPlayer.setMaxHp(100);
		newPlayer.setDef(2);
		newPlayer.setSPD(2);
		newPlayer.setMp(150);
		newPlayer.setMaxMp(150);
		return newPlayer;
	} else if (playerClass == "3") {
		newPlayer.setSymbol("P");
		newPlayer.setName(playerName);
		newPlayer.setClass("Puppet");
		newMoves = {{"desperation slap", 0, 5}, {"Scissor Cross", 3, 12}, {"One Thousand Threads", 8, 25}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(120);
		newPlayer.setMaxHp(120);
		newPlayer.setDef(3);
		newPlayer.setSPD(4);
		newPlayer.setMp(120);
		newPlayer.setMaxMp(120);
		return newPlayer;
	} else {
		newPlayer.setSymbol("K");
		newPlayer.setName(playerName);
		newPlayer.setClass("Knight");
		newMoves = {{"slash", 0, 5}, {"Hurricane Rush", 6, 15}, {"Boreas' Devastation", 10, 30}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(150);
		newPlayer.setMaxHp(150);
		newPlayer.setDef(3);
		newPlayer.setSPD(3);
		newPlayer.setMp(100);
		newPlayer.setMaxMp(100);
		return newPlayer;
	}
}

class Enemy {
  private:
	string enemyName;
	int maxHP;
	int HP;
	int ATK;
	int SPD;
  public:
	Enemy encounterEnemy();
	void setName(string name);
	void setHP(int hitPoints);
	void setMaxHP(int MAX);
	void setAttack(int attack);
	void setInitiative(int intiative);
	string getName();
	int getHP();
	int getMaxHP();
	int getAttack();
	int getInitiative();
};

void Enemy::setName(string name) {
	enemyName = name;
}

void Enemy::setHP(int hitPoints) {
	HP = hitPoints;
}

void Enemy::setMaxHP(int MAX) {
	maxHP = MAX;
}

void Enemy::setAttack(int attack) {
	ATK = attack;
}

void Enemy::setInitiative(int intiative) {
	SPD = intiative;
}

string Enemy::getName() {
	return enemyName;
}

int Enemy::getHP() {
	return HP;
}

int Enemy::getMaxHP() {
	return maxHP;
}

int Enemy::getAttack() {
	return ATK;
}

int Enemy::getInitiative() {
	return SPD;
}

Enemy Enemy::encounterEnemy() {//decides which enemy you encounter
	Enemy enemy;
	int encounter = 0;
	srand(time(0));
	encounter = rand() % 5;
	if (encounter == 0) {
		enemy.setName("Wolpertinger");//essentially mutant bunnies, its from folklore
		enemy.setMaxHP(20);
		enemy.setHP(20);
		enemy.setAttack(5);
		enemy.setInitiative(2);
		return enemy;
	} else if (encounter == 1) {
		enemy.setName("Gashadokuro");//a gaint skeleton ghost thing
		enemy.setMaxHP(45);
		enemy.setHP(45);
		enemy.setAttack(6);
		enemy.setInitiative(-1);
		return enemy;
	} else if (encounter == 2) {
		enemy.setName("Manananggal");//bat equivalent of sirens in filipino folklore
		enemy.setMaxHP(30);
		enemy.setHP(30);
		enemy.setAttack(8);
		enemy.setInitiative(3);
		return enemy;
	} else {
		enemy.setName("Mellisian Bee Swarm");//mythical bees led by the first queen bee Melissa
		enemy.setMaxHP(40);
		enemy.setHP(40);
		enemy.setAttack(4);
		enemy.setInitiative(3);
		return enemy;
	}
}

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
	ifstream map("mazetest.txt");
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
int trueColumn(int column) {
	int truth = 0;
	if (column  == 1) {
		truth = 1;
	} else if (column == 2) {
		truth = 3;
	} else if (column == 3) {
		truth = 5;
	} else if (column == 4) {
		truth = 7;
	} else if (column == 5) {
		truth = 9;
	}
	return truth;
}
void BoltorbFlip() {
	int bombsLeft = 6;
	int bombs = 0;
	int row = 0;
	int column = 0;
	int twoCoins = 2;
	int threeCoins = 2;
	int temp = 0;
	int userRow = 0;
	int userColumn = 0;
	int add = 1;
	srand(time(0));
	vector <vector <string>> board = {
		{" ", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "💣"},//wach row is size 14 but goes up to 13
		{"|", "x", " ", "x", " ", "x", " ", "x", " ", "x", "|", "5", "|", " "},//columns are of size 10 but 9
		{"|", "x", " ", "x", " ", "x", " ", "x", " ", "x", "|", "5", "|", " "},
		{"|", "x", " ", "x", " ", "x", " ", "x", " ", "x", "|", "5", "|", " "},
		{"|", "x", " ", "x", " ", "x", " ", "x", " ", "x", "|", "5", "|", " "},
		{"|", "x", " ", "x", " ", "x", " ", "x", " ", "x", "|", "5", "|", " "},
		{" ", "-", "-", "-", "-", "-", "-", "-", "-", "-", " ", " ", " ", " "},
		{" ", "5", " ", "5", " ", "5", " ", "5", " ", "5", " ", " ", " ", " "},
		{" ", "-", "-", "-", "-", "-", "-", "-", "-", "-", " ", " ", " ", " "},
		{" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "💣"}
	};
	vector <vector <int>> hiddenBoard = {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
	};
	while (bombsLeft > 0) { //assigning bomb locations
		row = rand() % 5;
		column = rand() % 5;
		if (hiddenBoard.at(column).at(row) == 0) {
			continue;
		} else {
			hiddenBoard.at(column).at(row) = 0;
			bombsLeft -= 1;
		}
	}

	while (twoCoins > 0 && threeCoins > 0) {//assgins 2 and 3 coin locations
		row = rand() % 5;
		column = rand() % 5;
		if (hiddenBoard.at(column).at(row) == 2 || hiddenBoard.at(column).at(row) == 3 || hiddenBoard.at(column).at(row) == 0) {
			continue;//this checks if a coin or bomb is already there
		} else {
			temp = rand() % 2;
			if (temp == 0 && twoCoins != 0) {
				hiddenBoard.at(column).at(row) = 2;
				twoCoins -= 1;
			} else if (temp == 1 && threeCoins != 0) {
				hiddenBoard.at(column).at(row) = 3;
				threeCoins -= 1;
			}
		}
	}

	bombs = 0;

	for (int i = 0; i < hiddenBoard.size(); i++) {//establishes the "hints" on the sides
		for (int j = 0; j < hiddenBoard.at(i).size(); j++) {
			temp += hiddenBoard.at(i).at(j);
			if (hiddenBoard.at(i).at(j) == 0) {
				bombs += 1;
			}
		}
		board.at(i + 1).at(11) = to_string(temp);
		board.at(i + 1).at(13) = to_string(bombs);
		temp = 0;
		bombs = 0;
		for (int k = 0; k < hiddenBoard.size(); k++) {//establishes the hints at the bottom of the board
			temp += hiddenBoard.at(k).at(i);
			if (hiddenBoard.at(k).at(i) == 0) {
				bombs += 1;
			}
		}
		board.at(9).at(i + add) = to_string(bombs);
		board.at(7).at(i + add) = to_string(temp);
		/*if (i == 0) {
			board.at(9).at(1) = to_string(bombs);
			board.at(7).at(1) = to_string(temp);
			cordMatcher = 1;
		} else {
			board.at(9).at(i + 2) = to_string(bombs);
			board.at(7).at(i + 2) = to_string(temp);
		}*/
		add += 1;
		temp = 0;
		bombs = 0;
	}

	cout << RED << "SYSTEM" << RESET << GREEN << " <CONGRATULATIONS ON MAKING IT THIS FAR USER -------" << endl;
	cout << endl;
	cout << "BUT YOU WON'T ESCAPE THIS PlaCe>" << RESET << endl;
	cout << endl;
	cout << RED << "SYSTEM" << RESET << GREEN << " <WELCOME TO VolT.....FOR LEGAL REASONS NAME HAS CHANGED TO BOLTORB FLIP" << endl;
	cout << "IN THIS PUZZLE YOU WILL HAVE TO FIND ALL NONE 1 COINS HIDDEN FROM VIEW" << endl;
	cout << "USER BE CAUTIONED THERE ARE VOLToR....NAME AHS BEEN CAHNGED TO BOMBS THAT WILL EXPLODE IF FOUND" << endl;
	cout << "NOW BEGIN!>" << endl;
	cout << endl;
	cout << "<chose which square to uncover by typing the row number then column number each starting from 1 and 5 long>" << RESET << endl;
	cout << endl;
	//cin >> userRow;
	//cin >> userColumn;
	twoCoins = 2;
	threeCoins = 2;
	while (true) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.at(i).size(); j++) {
				cout << board.at(i).at(j);
			}
			cout << endl;
		}
		int location = 0;
		cin >> row;
		cin >> column;
		if (!cin) {
			cout << "INVALID INPUT" << endl;
		}
		if (row == 6 && column == 7) {
			cout << "<IMPOSSIBLE how did you know the code>" << endl;
			cout << "<CONGRADULATIONS YOU WON!>" << endl;
			break;
		}
		if (row <= 0 || row >= 6 || column <= 0 || column >= 6) {
			cout << "INVALID INPUT TRY AGAIN" << endl;
		}
		if (hiddenBoard.at(row - 1).at(column - 1) == 0) {
			cout << "<OOPS YOU PICKED A BOMB>" << endl;
			//here is where the die function would go
		} else if (hiddenBoard.at(row - 1).at(column - 1) == 2) {
			location = trueColumn(column);
			board.at(row).at(location) = "2";
			twoCoins -= 1;
		} else if (hiddenBoard.at(row - 1).at(column - 1) == 3) {
			location = trueColumn(column);
			board.at(row).at(location) = "3";
			threeCoins -= 1;
		} else if (hiddenBoard.at(row - 1).at(column - 1) == 1) {
			location = trueColumn(column);
			board.at(row).at(location) = "1";
		}
		if (threeCoins <= 0 && twoCoins <= 0) {
			cout << "<CONGRADULATIONS YOU WON>" << endl;
			break;
		}
	}
}
string whatRock(int move) {
	string str;
	if (move == 1) {
		str = "PAPER";
	} else if (move == 2) {
		str = "ROCK";
	} else if (move == 3) {
		str = "SCISSORS";
	}
	return str;
}
void rockPS() {
	srand(time(0));
	int wins = 0;
	int opponent = 0;
	int playerInput = 0;
	cout << "if you can beat in thisssss bessst of three I'll let you go ssssspotlesssss from here" << endl;
	cout << "1.) paper 2.) rock 3.) scissors" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "1.....2....3" << endl;
		opponent = (rand() % 3) + 1;

		if (playerInput == opponent) {
			cout << "your opponent used " << whatRock(opponent) << " against your " << whatRock(playerInput) << endl;
			cout << "It's a TIE!\n";
			i --;
		} else if ((playerInput == 1 && opponent == 2) || (playerInput == 2 && opponent == 3) || (playerInput == 3 && opponent == 1)) {
			wins++;
			cout << "your opponent used " << whatRock(opponent) << " against your " << whatRock(playerInput) << endl;
			cout << "YOU WIN this round!\n";
		} else {
			cout << "your opponent used " << whatRock(opponent) << " against your " << whatRock(playerInput) << endl;
			cout << "You LOSE this round.\n";
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

void Combat(Player& player) {
	clearscreen();
	Enemy enemy;
	vector <string> monsterDisplay = {
		"__________________________________________________", // don't "fix" fixes itself when displayed
		"|                                                |",
		"|                                                |",
		"|                                                |",
		"|                                                |",
		"|                  .-----.,,----,                |",
		"|                 /       |    |                 |",
		"|                / ^ ^ \\  |----'                 |",
		"|               |  (O) (O)  |                    |",
		"|               |    \\ /   /                     |",
		"|               |  /`---'\\ |                     |",
		"|               /  \\=====//  \\                   |",
		"|             /____/     \\____\\                  |",
		"|            // || \\     / || \\\\                 |",
		"|           ((  ' | ' _ ' | '  ))                |",
		"|            \\\\_/ \\_/ (x) \\_/ \\_/                |",
		"|             \\__/  \\  |  /  \\__/                |",
		"|                    \\ | /                       |",
		"|                     \\|/                        |",
		"|                                                |",
		"|                                                |",
		"|                                                |",
		"|                                                |",
		"|                                                |",
		"--------------------------------------------------"
	};
	bool escChance = true;//you only have one chance to escape
	bool isPlayerTurn = true;//keeps track of player turn
	int playerRoll = 0;
	int enemyRoll = 0;
	int playerInput = 0;
	int temp = 0;
	char currChar;
	srand(time(0));
	enemy = enemy.encounterEnemy();
	enemyRoll = ((rand() % 20) + 1) + enemy.getInitiative(); //calculating initiative in the same manner d&d does
	playerRoll = ((rand() % 20) + 1) + player.getSPD();
	for (int i = 0; i < monsterDisplay.size(); i++) {
		//movecursor(0, 102);
		cout << monsterDisplay.at(i) << endl;
	}
	cout << endl;
	//cout << "display size: " << monsterDisplay.size() << endl;
	cout << RED << "SYSTEM" << RESET << endl;
	cout << GREEN << "<initiating system combat assit>" << endl;
	cout << "<Enemy has been identified as " << RED << "<" << enemy.getName() << ">" << RESET << endl;
	if (enemyRoll > playerRoll) {
		isPlayerTurn = false;
		cout << RED << "<the monster got the jump on you>" << RESET << endl;
	}
	while (true) {
		if (isPlayerTurn) {
			cout << YELLOW << "<how will you proceed?>" << RESET << endl;
			cout << BLUE << "1) attack" << endl;
			cout << "2) escape" << RESET << endl;
			cin >> playerInput;
			if (playerInput == 1) {
				cout << GREEN << "<Alright! Lets go on the offensive!>" << RESET << endl;
				cout << YELLOW << "<choose a move to proceed>" << RESET << endl;
				player.printPlayerMoves();
				cin >> playerInput;
				cout << BLUE << "You attacked " << RESET << RED << enemy.getName() << RESET;
				cout << BLUE << " and dealt " << RESET << RED << player.getPower(playerInput) << RESET;
				cout << BLUE << " damage!" << endl;
				temp = enemy.getHP() - player.getPower(playerInput);
				if (temp <= 0) {
					cout << RED << "SYSTEM" << RESET << endl;
					cout << GREEN << "<enemy hp has dropped to zero>" << endl;
					cout << "<leaving combat mode>" << RESET << endl;
					break;
				} else {
					enemy.setHP(temp);
					temp = player.getMp() -  player.getCost(playerInput);
					player.setMp(temp);
					isPlayerTurn = false;
				}
			} else if (playerInput == 2) {
				if (escChance) {
					playerRoll = (rand() % 20) + 1;
					enemyRoll = (rand() % 20) + 1;
					if (playerRoll > enemyRoll) {
						cout << RED << "SYSTEM" << RESET << endl;
						cout << GREEN << "<successfully evaded combat>" << endl;
						cout << "<leaving combat mode>" << RESET << endl;
						break;
					} else {
						cout << RED << "FAILED TO ESCAPE" << endl;
						cout << "<combat is inevitable>" << RESET << endl;
						isPlayerTurn = false;
						escChance = false;
					}
				} else {
					cout << RED << "<combat is inevitable>" << RESET << endl;
					continue;
				}
			}
		} else {
			cout << RED << "<INCOMING ATTACK>" << RESET << endl;
			playerRoll = rand() % 100;
			if (playerRoll == 0) {
				cout << GREEN << "<you barely managed to evade the attack>" << RESET << endl;
			} else {
				cout << RED << "<TOOK DIRECT HIT>" << endl;
				cout << "<....ACCEsSinG DAMAgeS....>" << endl;
			}
			temp = player.getHp() - enemy.getAttack();
			if (temp <= 0) {
				cout << "<...ToOk FATAL amounT oF DAMAGe...>" << RESET << endl;
				//here is where we would implement the die() function
			} else {
				cout << "<took " << enemy.getAttack() << " points of damage>" << RESET << endl;
				player.setHp(temp);
			}
			isPlayerTurn = true;
		}
	}
}

enum playersIntialPosition {STARTxCORD = 49, STARTyCORD = 48};

int main() {
	//BoltorbFlip();
	Player player;
	string temp;
	vector <string> map = mapCreation();
	vector <vector <string>> cords;//our new and improved map
	/*for (int i = 0; i < map.size(); i++) { //keeping this here for now, for testing purposes
		cout << map.at(i) << endl;
	}*/
	//babySudoku();
	temp = map.at(0);
	int rowSize = temp.size(); //aka # of cols
	int columnSize = map.size(); // aka # of rows
	int prevRow = 0;
	int prevColumn = 0;
	int playerRow = STARTyCORD;
	int playerColumn = STARTxCORD;
	int ecounters = 2;
	show_cursor(false);
	string name, strtemp, choice; //name holds player name, strtemp hold temporary string to print slowly, and choice is the character class
	printSlowly("You awake to a room you are unfamiliar with, missing your name and how you got here...");
	cout << endl;
	printSlowly("What name would like to go by?");
	cout << endl;
	cin >> name;
	cout << endl;
	printSlowly("hmmm.");
	cout << endl;
	strtemp = name + ". It suits you, well alright " + name + " which class would you like to be?";
	printSlowly(strtemp);
	cout << endl;
	printSlowly("1) Knight");
	cout << endl;
	printSlowly("2) Mage");
	cout << endl;
	printSlowly("3) Puppet");
	cout << endl;
	printSlowly("(press 1, 2, 3, or any other key to quit)");
	cout << endl;
	cin >> choice;
	if (!cin || (choice != "1" && choice != "2" && choice != "3")) {
		quit();
	}
	cout << endl;
	player = player.createPlayer(name, choice);
	Combat(player);
	strtemp = "";
	strtemp = "Good choice. You are going to be the (" + player.getSymbol() + "), Good Luck!.";
	printSlowly(strtemp);
	cout << endl;
	/*	if (choice == "1") {
			strtemp = "";
			Player player(name, "knight");
			strtemp = "Good choice. You are going to be the " + player.symbol + " , Good Luck!.";
			printSlowly(strtemp);
			cout << endl;
		} else if (choice == "2") {
			Player player(name, "mage");
			strtemp = "Good choice. You are going to be the " + player.symbol + " , Good Luck!.";
			printSlowly(strtemp);
			cout << endl;
		} else if (choice == "3") {
			Player player(name, "puppet");
			strtemp = "Good choice. You are going to be the " + player.symbol + " , Good Luck!.";
			printSlowly(strtemp);
			cout << endl;
		} else {
			quit();
		}
	*/
	//here
	this_thread::sleep_for(chrono::milliseconds(2500));

	movecursor(0, 0);
	clearscreen();
	cords.resize(columnSize, vector<string>(rowSize, ""));
	for (int i = 0; i < columnSize; i++) {// i (y-cord/row) and j (x-cord/col) will act as you would x and y cords
		temp = map.at(i);
		for (int j = 0; j < temp.size(); j++) {
			cords.at(i).at(j) = temp.at(j);
		}
	}
	cords.at(playerRow).at(playerColumn) = player.getSymbol();
//	cout << "number of columns: " << rowSize << endl;
//	cout << "number of rows: " << columnSize << endl;
	displayMap(cords);
	cout << "player location: " << playerColumn << "    " << playerRow << endl; //x,y
	set_raw_mode(true);
	show_cursor(false);
	prevRow = playerRow;
	prevColumn = playerColumn;
	while (true) {
		int m = toupper(quick_read());
		if ((cords.at(playerRow - 1).at(playerColumn) == ".") && (m == 'W' || m == UP_ARROW)) {
			playerRow--; //algebra just checks if its a movable square aka "." if not then you cant cross
		}
		if ((cords.at(playerRow + 1).at(playerColumn) == ".") && (m == 'S' || m == DOWN_ARROW)) {
			playerRow++; //rows are y cord row++ = ⬆️
		}
		if ((cords.at(playerRow).at(playerColumn - 1) == ".") && (m  == 'A' || m == LEFT_ARROW)) {
			playerColumn--;
		}
		if ((cords.at(playerRow).at(playerColumn + 1) == ".") && (m == 'D' || m == RIGHT_ARROW)) {
			playerColumn++; //cols are x cord  col++ = ->
		}
		cords.at(playerRow).at(playerColumn) = player.getSymbol(); //updated .at(x cord).at(y cord) x-> row y-> col
		cords.at(prevRow).at(prevColumn) = "."; // ^^^^ same
		if (!(playerRow == prevRow && playerColumn == prevColumn)) {
			clearscreen();
			movecursor(0, 0);
			displayMap(cords);
			cout << "player location: " << playerColumn << "    " << playerRow << endl; //x,y
			//cout << "[" << cords.at(playerColumn).at(playerRow + 1) << "]";
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








