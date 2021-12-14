// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;


enum types { rock, paper, scissors }player1,player2;
types play();
void findWinner(types, types);


int main()
{

	cout << "Rock, Paper, Scissors: Man vs. Machine" << endl<<endl;
	cout << "Player1 selection:" << endl;
	player1 = play();
	cout << "Player2 selection:" << endl;
	player2 = play();
	cout << endl;
	findWinner(player1, player2);
	return 0;
}

types play() {
	MARKER1:cout << "What would you like to Play?" << endl;
	cout << "'R' for Rock..." << endl;
	cout << "'P' for Paper..." << endl;
	cout << "'S' for Scissors..." << endl;
	cout << "So... What'll it be?";
	char selection;
	cin >> selection;
	selection = static_cast<int>(selection);
	selection=toupper(selection);
	selection = static_cast<char>(selection);

	switch (selection)
	{
	case 'R':
		return rock;
	case 'P':
		return paper;
	case 'S':
		return scissors;
	default:
		cout << "Input Error: Please Input 'R', 'P', or 'S'!!!" << endl<<endl;
		goto MARKER1;
		break;
	}

}

void findWinner(types p1, types p2) {
	if (p1 == p2) {
		cout << "No Winner!!!" << endl;
		return;
	}
	else if (p1 == rock) {
		if (p2 == paper) {
			cout << "Player2 Wins!!!" << endl;
			return;
		}
		if (p2 == scissors) {
			cout << "Player1 Wins!!!" << endl;
			return;
		}
	}
	else if (p1 == paper) {
		if (p2 == scissors) {
			cout << "Player2 Wins!!!" << endl;
			return;
		}
		if (p2 == rock) {
			cout << "Player1 Wins!!!" << endl;
			return;
		}
	}

	else if (p1 == paper) {
		if (p2 == scissors) {
			cout << "Player2 Wins!!!" << endl;
			return;
		}
		if (p2 == rock) {
			cout << "Player1 Wins!!!" << endl;
			return;
		}
	}
}