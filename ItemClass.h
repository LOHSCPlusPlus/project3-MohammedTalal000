#include <fstream>
using namespace std;
class videogametype {
  private:
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double numSales;
    char platform[MAX_CHAR_LEN];
    char releaseDate[MAX_CHAR_LEN];
    char developer[MAX_CHAR_LEN];
    char publisher[MAX_CHAR_LEN];
  public:
    videogametype();
    bool isSamePublisher(const char other[]);
    bool isSameDeveloper(const char other[]);
    bool isSamePlatform(const char other[]);
    bool isSameName(const char other[]);
    void printGames(ostream &out);
    void readFromUser();
    void readFromFile(ifstream &inFile);
    
};