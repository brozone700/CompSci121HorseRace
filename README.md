# CompSci121HorseRace
UMAMUSUME
```
#include <iostream>
#include <cstdlib>
#include <ctime>
int TrackLength = 15
int KeepGoing = 0
array horse = {0, 0, 0, 0, 0}
def printTrack():
    for i in range(5):
        print("\n")
        for j in range(TrackLength):
            if (horse[i] != TrackLength - 1):
                if (j != horse[i]):
                    print(".")
                else:
                    print(i)
            else:
                
def advance(name):
    srand(time(NULL))
    horse[name] = horse[name] + (rand % 1)

def main():
    while KeepGoing > 0:
        printTrack()
        for i in range(5):
            advance(horse[i])
        print("Press enter for another turn)
        input()
 
```
