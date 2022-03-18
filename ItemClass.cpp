#include "ItemClass.h"
#include "ReadUtils.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

videogametype::videogametype() {
  for (int index = 0; index < MAX_CHAR_LEN; index++) {
    name[index] = '\0';
    platform[index] = '\0';
    releaseDate[index] = '\0';
    developer[index] = '\0';
    publisher[index] = '\0';
  }
  numSales = 0;
}

void videogametype::printGames(ostream &out){
    out << name << ";";
    out << numSales << ";";
    out << platform << ";";
    out << releaseDate << ";";
    out << developer << ";";
    out << publisher << endl;
}

void videogametype::readFromUser() {
  cout << "Enter a game name: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(name, videogametype::MAX_CHAR_LEN);
    numSales = readDouble("Enter number of sales: ");
  cout << "Enter a game platform: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(platform, videogametype::MAX_CHAR_LEN);

  cout << "Enter a game release date: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(releaseDate, videogametype::MAX_CHAR_LEN);

  cout << "Enter a game developer: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(developer, videogametype::MAX_CHAR_LEN);

  cout << "Enter a game publisher: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(publisher, videogametype::MAX_CHAR_LEN);
}

void videogametype::readFromFile(ifstream &inFile) {
    inFile.get(name, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> numSales;
    inFile.ignore(100,';');
    inFile.get(platform, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(releaseDate, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(developer, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(publisher, videogametype::MAX_CHAR_LEN, '\n');
    inFile.ignore(100,'\n');
}

bool videogametype::isSamePublisher(const char other[]) {
  if (strcmp(publisher, other) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool videogametype::isSameDeveloper(const char other[]) {
  if (strcmp(developer, other) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool videogametype::isSamePlatform(const char other[]) {
  if (strcmp(platform, other) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool videogametype::isSameName(const char other[]) {
  if (strcmp(name, other) == 0) {
    return true;
  }
  else {
    return false;
  }
}