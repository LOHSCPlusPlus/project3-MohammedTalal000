#include "ItemDB.h"
#include "ReadUtils.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

videoGameData::videoGameData() {
  numGames = 0;
  read();
}

void videoGameData::read() {
  ifstream gameFile("videogamesOriginal.txt");
    numGames = 0;
    while(gameFile.peek() != EOF && numGames < 100) {
        gameArray[numGames].readFromFile(gameFile);
        numGames++;
    }
}

void videoGameData::print(ostream &out) {
  for (int index = 0; index < numGames; index++) {
    out << "Index " << index << ": ";
    gameArray[index].printGames(out);
  }
}

void videoGameData::save() {
  ofstream outFile("videogames.txt");
    for (int index = 0; index < numGames; index++) {
        gameArray[index].printGames(outFile);
    }
}

void videoGameData::remove() {
  int index = 0;
  index = readInt("Enter the index you want to remove: ");
  for (index; index < numGames; index++) {
    gameArray[index] = gameArray[index + 1];
  }
}

void videoGameData::add() {
  gameArray[numGames].readFromUser();
  numGames++;
}

void videoGameData::searchGameByPublisher() {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the publisher: ";
  cin.getline(selecInput, 100);
  cout << endl;
  
  for(int counter = 0; counter < numGames; counter++) {
    if (gameArray[counter].isSamePublisher(selecInput) == true) {
      cout << "Index " << counter << ": ";
      gameArray[counter].printGames(cout);
    }
  }
}

void videoGameData::searchGameByDeveloper() {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the developer: ";
  cin.getline(selecInput, 100);
  cout << endl;
  
  for(int counter = 0; counter < numGames; counter++) {
    if (gameArray[counter].isSameDeveloper(selecInput) == true) {
      cout << "Index " << counter << ": ";
      gameArray[counter].printGames(cout);
    }
  }
}

void videoGameData::searchGameByPlatform() {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the platform: ";
  cin.getline(selecInput, 100);
  cout << endl;
  
  for(int counter = 0; counter < numGames; counter++) {
    if (gameArray[counter].isSamePlatform(selecInput) == true) {
      cout << "Index " << counter << ": ";
      gameArray[counter].printGames(cout);
    }
  }
}

void videoGameData::searchGameByName() {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the Name: ";
  cin.getline(selecInput, 100);
  cout << endl;
  
  for(int counter = 0; counter < numGames; counter++) {
    if (gameArray[counter].isSameName(selecInput) == true) {
      cout << "Index " << counter << ": ";
      gameArray[counter].printGames(cout);
    }
  }
}