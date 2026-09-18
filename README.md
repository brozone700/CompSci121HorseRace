# CompSci121HorseRace
UMAMUSUME
```
#include <iostream>
#include <cstdlib>
#include <ctime>
CONST TrackLength = 15
int KeepGoingGame = 0
int KeepGoingRace = 0
array horse = {0, 0, 0, 0, 0}
string question = "ham"

#next variables are for gambling
int balance = 50
int wager = 0
int chosen = 5
int winner = 0

def printTrack():
    //A track for each horse
    for i in range(5):
        print("\n")
        if (horse[i] != TrackLength):
            for j in range(TrackLength):
                if (j != horse[i]):
                    print(".")
                else:
                    print(i)
        else:
            print(f"Horse {i} wins !!!")
            KeepGoingRace = 1
            if (i == chosen):
                winner = 1
            else:
                winner = 0

def advance(name):
    horse[name] = horse[name] + (rand % 2)

def gambling():
    wager = balance + 1
    chosen = 5
    while (chosen < 0 or chosen > 4):
        print("Pick your favorite horse(0-4): ")
        input(chosen)
        while (wager > balance or wager < 0):
            print("How much of your money would you like to wager?")
            print(f"current balance: {balance}")
            print("Your wager: ")
            input(wager)
            if (wager > balance):
                print("you have to have the money that you want to wager")
            else if (wager < 0):
                print("You can't wager any less than 0")

def race():
    for i in range(5):
        advance(i)
    printTrack()
    if (KeepGoingRace != 1):
        print("Press enter for another turn")
        input()

def main():
    srand(time(NULL))
    while KeepGoingGame < 1:
        printTrack()
        gambling()
        while KeepGoingRace < 1:
            race()
        if (winner == 1):
            winnings = wager * 5
            balance = balance + winnings
            print(f"Wow, you actually won! You won ${winnings}")
        else:
            balance = balance - wager
            print("Better Luck Next Time")
            print(f"Thanks for the ${wager} though :D")
        print("Would you like to play again?")
        print("Anything other than yes will end the game: ")
        input(question)
        if (question != "yes"):
            KeepGoingGame = 1
        else:
            KeepGoingRace = 0
            //resets the horses' positions
            for i in range(5):
                horse[i] = 0
```
