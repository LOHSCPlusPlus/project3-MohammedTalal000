#include "ItemDB.h"
#include "ReadUtils.h"
#include <iostream>
using namespace std;

void displayMenu(videoGameData &games){
  int option = 0;
  int perameter = 0;
  while (option != 7) {
    cout << endl << "1: Display the game list" << endl;
    cout << "2: Remove a game from the list" << endl;
    cout << "3: Add a game to the list" << endl;
    cout << "4: Search game by perameter" << endl;
    cout << "5: Reload original data" << endl;
    cout << "6: Save current data" << endl;
    cout << "7: Quit" << endl;
    option = readInt("Enter an option: ");
  
    if(option == 1) {
      games.print(cout);
    }
    else if (option == 2) {
      games.remove();
    }
    else if (option == 3) {
     games.add();
    }
    else if (option == 4) {
      cout << "1) By Name" << endl;
      cout << "2) By platform" << endl;
      cout << "3) By developer" << endl;
      cout << "4) By publisher" << endl;
      perameter = readInt("Enter perameter: ");
      cin.ignore();
      if (perameter == 1) {
        games.searchGameByName();
      }
      else if (perameter == 2) {
        games.searchGameByPlatform();
      }
      else if (perameter == 3) {
        games.searchGameByDeveloper();
      }
      else if (perameter == 4) {
        games.searchGameByPublisher();
      }
      else {
        cout << "Invalid Option!!!";
      }
    }
    else if (option == 5) {
      games.read();
    }
    else if (option == 6) {
      games.save();
    }
    else if (option == 7) {
      break;
    }
    else {
      cout << "Invalid Option!!!";
    }
  }
}



int main() {
  videoGameData games;
  displayMenu(games);
}