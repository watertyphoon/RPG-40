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
#include "toolbox.h"
//add dictionary later
using namespace std;


vector<string> mapCreation() {
	ifstream map("Maps.csv");
	if(!map) {
		cout << "Bad file" << endl;
		return 0;
	}

	vector
	while (true) {
		
	}
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
	printSlowly(name + ". It suits you, well alright " + name + " which class would you like to be?\n");
	printSlowly("1) Knight\n");
	printSlowly("2) Mage\n");
	printSlowly("3) Puppet\n");
	printSlowly("(press 1, 2, 3, or any other key to quit)\n");
	cin >> choice;
	cout << endl;
	if (!cin || choice > 3) quit();

	vector<string> choiceHolder = {"knight", "mage", "puppet"};
	Player player(choiceHolder.at(choice - 1));
	cerr << choiceHolder.at(choice - 1) << endl;
	printSlowly("Good choice. You are going to be the " + player.symbol + " , Good Luck!.");
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
		if ((m == 'W' || m == UP_ARROW) && cords.at(playerColumn - 1).at(playerRow) != "+") {
			playerColumn--;
		}
		if ((m == 'S' || m == DOWN_ARROW) && cords.at(playerColumn + 1).at(playerRow) != "+") {
			playerColumn++;
		}
		if ((m == 'A' || m == LEFT_ARROW) && cords.at(playerColumn).at(playerRow - 1) != "+") {
			playerRow--;
		}
		if ((m == 'D' || m == RIGHT_ARROW) && cords.at(playerColumn).at(playerRow + 1) != "+") {
			playerRow++;
		}
		cords.at(playerColumn).at(playerRow) = player.symbol;
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












