#include "project.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu();

string firstName, lastName, region, date, medium, title, description;
int galleryNumber, yearCreated;

int main(int argc, char ** argv)
{
  //opens file from command line
  ifstream inFile;
  inFile.open(argv[1]);
  TreeNode art;

  int totalPiecesCount = 0;
  bool run = true;
  string title, artist;

  while (!inFile.eof())
  {
    getline(inFile, firstName, ',');
    getline(inFile, laseName, ',');
    getline(inFile, region, ',');
    getline(inFile, date, ',');
    getline(inFile, medium, ',');
    getline(inFile, title, ',');
    getline(inFile, description, ',');
    getline(inFile, galleryNumber, ',');
    getline(inFile, yearCreated, ',\n');

    addPeice(firstName, lastName, region, date, medium, title, description, stoi(galleryNumber), stoi(yearCreated));
    totalPiecesCount++;
  }

  while(run)
  {
    char choice;
    menu();
    cin >> choice;
    switch (choice)
    {
      case '1':
        cout << "---------- Enter the artwork's title ----------" << endl;
        getchar();
        getline(cin, title);
        art.searchPiece(title);
        break;
      case '2':
        cout << "---------- Enter the artwork's title ----------" << endl;
        getchar();
        getline(cin, artist);
        art.searchArtist(artist);
        break;
      case '3':
        cout << "---------- Printing all pieces and artists ----------" << endl;
        art.printInventory();
        break;
      case '4':
        break;
      case '5':
        break;
      case '6':
        run = false;
        break;
      default:
        break;
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
