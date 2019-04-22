#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/* Linked List node structure that will be stored at each node in the BST*/
struct LLNode
{
	std::string firstName; //first name of artist
	std::string lastName; //last name of artist
	std::string region; //region artist is from -- if artist unknown region piece originated
	std::string date; //when the artist was born & died (if deceased)
	std::string medium; //the medium
	std::string title; //title of the art
	std::string description; //description of the piece
	int galleryNumber; //what gallery number the piece is in if on display
	//int piecesAtCU; //how many pieces by that artist are in CU's collection
	std::string yearCreated; //when the piece was created
  std::string aquired; //how the piece was aquired

	LLNode * next; //pointer to the next node

	LLNode(){}
};

struct TreeNode
{
	char nameChar;//first letter of last name (A,B,C.. ect. )

	TreeNode *parent = NULL;
	TreeNode *leftChild = NULL;
	TreeNode *rightChild = NULL;
	LLNode * head = NULL;
};

class ArtMuseum
{
	public:
		ArtMuseum();
		~ArtMuseum();
		void addPiece(std::string firstName, std::string lastName, std::string region, std::string date, std::string title, std::string yearCreated, std::string medium, std::string aquired, std::string description, int galleryNumber);
		void searchPiece(std::string title);
		//void learnAbout(); //thought this could be cool... just a random display
		//void printFacts(std::string title); //displays the general info about a specified piece
		//void largestRegion(); //counts all the known regions that pieces were created in and lists the top 5
		void galleryList(int galleryNumber); //lists all pieces in a specific gallery
		//void isMore(std::string firstName, std::string lastName); //counts how many pieces in collection artist has
		//void displayIsMore(); //lists the top 3 artist that have the most pieces in the collection 
    	void printInventory();

	private:
		TreeNode * root;
};

#endif
