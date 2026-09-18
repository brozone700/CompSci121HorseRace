#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

const int TrackLength = 15;
int KeepGoingGame = 0;
int KeepGoingRace = 0;
int horse[5] = {0, 0, 0, 0, 0};
std::string question = "ham";

//next variables are for gambling
int balance = 50;
int wager = 0;
int chosen = 5;
int winner = 0;

void printTrack() {
	//A track for each horse
	for ( int i = 0; i < 5; i++) {
		cout << "\n";
		if (horse[i] != TrackLength){
			for ( int j = 0; j < TrackLength; j++) {
				if ( j != horse[i]) {
					cout << ".";
				}else{
					cout << i;
				}
			}
		} else {
			cout << "Horse ";
			cout << i;
			cout << " wins !!!";
			KeepGoingRace = 1;
			if ( i == chosen){
				winner = 1;
			}else{
				winner = 0;
			}
		}
	}
}

void Advance( int name) {
	horse[name] = horse[name] + (rand() % 2);
}

void gambling(){
	wager = balance + 1;
	chosen = 5;
	while (chosen < 0 or chosen > 4) {
		cout << "\nPick your favorite horse(0-4): ";
		cin >> chosen;
        	while (wager > balance or wager < 0){
			cout << "\nHow much of your money would you like to wager?";
			cout << "\ncurrent balance: ";
			cout << balance;
			cout << "\nYou're wager: ";
			cin >> wager;
			if (wager > balance){
				cout << "\nyou have to have the money that you want to wager";
			}else if (wager < 0){
				cout << "\nYou can't wager any less than 0";
			}
		}
	}
}

void race() {
	for (int i = 0; i < 5; i++){
		Advance(i);
	}
	printTrack();
        if (KeepGoingRace != 1){
		cout << "\nPress enter for another turn";
		cin.get();
	}
}

int main() {
	srand(time(NULL));
	while (KeepGoingGame < 1){
		printTrack();
		gambling();
		while (KeepGoingRace < 1){
			race();
		}
		if (winner == 1){
			int winnings = wager * 5;
			balance = balance + winnings;
			cout << "\nWow, you actually won! You won $";
			cout << winnings;
		} else {
			balance = balance - wager;
			cout << "\nBetter Luck Next Time";
			cout << "\nThanks for the $";
			cout << wager;
			cout << " though :D";
		}
		cout << "\nWould you like to play again?";
		cout << "\nAnything other than yes will end the game: ";
		cin >> question;
		if (question != "yes"){
			KeepGoingGame = 1;
		}else{
			KeepGoingRace = 0;
			for (int i = 0; i < 5; i++){
				horse[i] = 0;
			}
		}
	}
}
