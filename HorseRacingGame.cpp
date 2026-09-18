#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
const int TrackLength = 15;
int KeepGoing = 0;
int horse[5] = {0, 0, 0, 0, 0};
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
			KeepGoing = 1;
		}
	}
}

void Advance( int name) {
	horse[name] = horse[name] + (rand() % 2);
}

int main() {
	srand(time(NULL));
	printTrack();
	cout << "\nPick your favorite horse(press enter when ready to start)";
	cin.get();
	while (KeepGoing < 1) {
		for (int i = 0; i < 5; i++){
			Advance(i);
		}
		printTrack();
		if (KeepGoing != 1){
			cout << "\nPress enter for another turn";
			cin.get();
		}
	}
}
