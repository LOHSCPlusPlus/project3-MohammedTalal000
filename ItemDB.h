#include "ItemClass.h"
#include <fstream>

class videoGameData {
  private:
    videogametype gameArray[100];
    int numGames;
  public:
    videoGameData();
    void read();
    void print(ostream &out);
    void save();
    void remove();
    void add();
    void searchGameByPublisher();
    void searchGameByDeveloper();
    void searchGameByPlatform();
    void searchGameByName();
};