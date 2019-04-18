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

  int totalPiecesCount = 0;
  bool run = true;

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
    string movietitle;
    menu();
    cin >> choice;
    switch (choice){
      case '1':
        break;
      case '2':
        break;
      case '3':
        break;
      case '4':
        break;
      case '5':
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
    cout  <<  "3. Find all pieces in a gallery"  <<  endl ;
    cout  <<  "4. General information" << endl;
    cout  <<  "5. Quit" << endl;
}
