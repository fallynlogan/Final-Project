#include "project.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void menu();

string firstName, lastName, region, date, medium, title, description, yearCreated, aquired;
int galleryNumber;

int main(int argc, char ** argv)
{
  //opens file from command line
  ifstream inFile;
  inFile.open(argv[1]);
  ArtMuseum art;

  int totalPiecesCount = 0;
  bool run = true;
  string artwork;
  int line = 0;

  while(getline(inFile, artwork, '\n'))
  {
    stringstream comp;
    comp << artwork;
    int galleryNumber, count = 1;
    string firstName, lastName, region, date, medium, title, description, yearCreated;
    while(getline(comp,artwork,','))
    {
      if (count == 1) firstName = artwork;
      else if (count == 2) lastName = artwork;
      else if (count == 3) region = artwork;
      else if (count == 4) date = artwork;
      else if (count == 5) title = artwork;
      else if (count == 6) yearCreated = artwork;
      else if (count == 7) medium = artwork;
      else if (count == 8) aquired = artwork;
      else if (count == 9) description = artwork;
      else if (count == 10) galleryNumber = stoi(artwork);
      count++;
    }
    art.addPiece(firstName, lastName, region, date, title, yearCreated, medium, aquired, description, galleryNumber);
  }

  while(run)
  {
    char choice;
    string title, fn, ln, galleryNumber;
    cout << endl;
    menu();
    cin >> choice;
    cout << endl;
    switch (choice)
    {
      case '1':
        cout << "---------- Enter the artwork's title ----------" << endl;
        getchar();
        getline(cin, title);
        art.searchPiece(title);
        break;
      case '2':
        cout << "---------- Enter the artist's first name ----------" << endl;
        getchar();
        getline(cin, fn);
        cout << "---------- Enter the artist's last name ----------" << endl;
        getline(cin, ln);
        art.searchArtist(fn,ln);
        break;
      case '3':
        cout << "---------- Printing all pieces and artists ----------" << endl;
        art.printInventory();
        break;
      case '4':
        cout << "---------- Enter gallery number ----------" << endl;
        getchar();
        getline(cin, galleryNumber);
        art.galleryList(stoi(galleryNumber));
        break;
      case '5':
        cout << "---------- General Information ----------" << endl;
        art.learnAbout();
        break;
      case '6':
        run = false;
        break;
      default:
        break;
    }
  }
}

void menu()
{
    cout  <<  "======Main Menu======"  <<  endl ;
    cout  <<  "1. Search for a piece"  <<  endl ;
    cout  <<  "2. Search for an artist"  <<  endl ;
    cout  <<  "3. Print all pieces" << endl;
    cout  <<  "4. Find all pieces in a gallery"  <<  endl ;
    cout  <<  "5. General information" << endl;
    cout  <<  "6. Quit" << endl;
}
