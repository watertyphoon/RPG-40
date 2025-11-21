#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "/public/colors.h"
using namespace std;

class Moves {
  private:
	string name;
	int mpCost;
	int dmg;

  public:
	//Constructers
	Moves() {
		name = "";
		mpCost = 0;
		dmg = 0;
	}
	Moves(string atkName, int mp, int atk) {
		name = atkName;
		mpCost = mp;
		dmg = atk;
	}

	//Setters (Yes i know this might be unused)
	void setName(string atkName) {name = atkName;}
	void setMpCost(int mp) {mpCost = mp;}
	void setDmg(int atk) {dmg = atk;}

	//Getters
	string getMoveName() {return name;}
	int getDMG() {return dmg;}
	int getMPCost() {return mpCost;}
};
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
		newPlayer.setHp(750);
		newPlayer.setMaxHp(750);
		newPlayer.setDef(3);
		newPlayer.setSPD(3);
		newPlayer.setMp(900);
		newPlayer.setMaxMp(900);
		return newPlayer;
	} else if (playerClass == "2") { //ai debuged if -> else if when player picks 2 the last else statement executes and makes him a knight instead
		newPlayer.setSymbol("M");
		newPlayer.setName(playerName);
		newPlayer.setClass("Mage");
		newMoves = {{"bonk", 0, 5}, {"magic missile", 8, 20}, {"FIREBALL", 20, 40}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(400);
		newPlayer.setMaxHp(400);
		newPlayer.setDef(2);
		newPlayer.setSPD(2);
		newPlayer.setMp(350);
		newPlayer.setMaxMp(350);
		return newPlayer;
	} else if (playerClass == "3") {
		newPlayer.setSymbol("P");
		newPlayer.setName(playerName);
		newPlayer.setClass("Puppet");
		newMoves = {{"desperation slap", 0, 5}, {"Scissor Cross", 3, 12}, {"One Thousand Threads", 8, 25}};
		newPlayer.setPlayerAttacks(newMoves);
		newPlayer.setHp(220);
		newPlayer.setMaxHp(220);
		newPlayer.setDef(3);
		newPlayer.setSPD(4);
		newPlayer.setMp(420);
		newPlayer.setMaxMp(420);
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
