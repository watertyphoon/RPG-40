#define TOOLBOX_H

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
		if (hp > maxHp) {
			hp = maxHp;
		}
	}
	void setMaxHp(int newMaxHp) {
		maxHp = newMaxHp;
		if (hp > maxHp) {
			hp = maxHp;
		}
	}
	void setMp(int newMp) {
		mp = newMp;
		if (mp > maxMp) {
			mp = maxMp;
		}
	}
	void setMaxMp(int newMaxMp) {
		maxMp = newMaxMp;
		if (mp > maxMp) {
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
		if (move.cost <= mp) {
			target.hurt(move.dmg);
			mp -= move.cost;
		}
	}


	//Consturcter
	Player(string playerClass = "knight") {
		if (playerClass == "knight") {
			symbol = "K";
			atk = {{"slash", 0, 5}, {"light atk", 6, 15}, {"Smite", 10, 30}};
			hp = 150;
			maxHp = hp;
			def = 3;
			spd = 3;
			mp = 100;
			maxMp = mp;
		} else if (playerClass == "mage") {
			symbol = "M";
			atk = {{"bonk", 0, 5}, {"magic missile", 8, 20}, {"FIREBALL", 20, 40}};
			hp = 100;
			maxHp = hp;
			def = 2;
			spd = 2;
			mp = 150;
			maxMp = mp;
		} else if (playerClass == "puppet") {
			symbol = "P";
			atk = {{"desperation slap", 0, 5}, {"light atk", 3, 12}, {"heavy atk", 8, 25}};
			hp = 120;
			maxHp = hp;
			def = 3;
			spd = 4;
			mp = 120;
			maxMp = mp;
		} else {
			className = "knight";
			symbol = "K";
			atk = {{"slash", 0, 5}, {"light atk", 6, 15}, {"Smite", 10, 30}};
			hp = 150;
			maxHp = hp;
			def = 3;
			spd = 3;
			mp = 100;
			maxMp = mp;
		}
	}
};

