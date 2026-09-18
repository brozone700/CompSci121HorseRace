#include <iostream>
#include <cstdlib>
#include <ctime>
const int TrackLength = 15;
int KeepGoing = 0;
int horse[5] = {0, 0, 0, 0, 0};
int x;
void printTrack() {
	for ( int i = 0; i < 5; i++) {
		cout << "\n";
		for ( int j = 0; j < TrackLength; j++) {
			if (horse[i] != TrackLength){
				if ( j != horse[i]) {
					cout << ".";
				}else{
					cout << i;
				}
			} else {
				cout << "Horse " j " wins !!!";
				KeepGoing = 1
			}
		}
	}
}

void advance(name) {
	srand(time(NULL));
	horse[name] = horse[name] + (rand % 1);
}

void main() {
	printTrack();
	cout << "Pick your favorite horse(press enter when ready to start)";
	cin >> x;
	while (KeepGoing < 1) {
		for (int i = 0; i < 5; i++){
			advance(horse[i]);
		}
		printTrack();
		cout << "Press enter for another turn";
		cin >> x;
	}
}
