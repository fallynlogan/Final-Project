#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

struct TreeNode
{
	char nameChar;//first letter of last name (A,B,C.. ect. )

	TreeNode *parent = NULL;
	TreeNode *leftChild = NULL;
	TreeNode *rightChild = NULL;
	LLNode * head = NULL;
};

/* Linked List node structure that will be stored at each node in the BST*/
struct LLNode
{
	std::string firstName; //first name of artist
	std::string lastName; //last name of artist
	std::string region; //region artist is from -- if artist unknown region peice originated
	std::string date; //when the artist was born & died (if deceased)
	std::string medium; //the medium
	std::string title; //title of the art
	std::string description; //description of the peice
	int galleryNumber; //what gallery number the peice is in if on display
	int peicesAtCU; //how many peices by that artist are in CU's collection
	int yearCreated; //when the peice was created

	LLNode * next; //pointer to the next node

	LLNode(){}
};

class ArtMuseum
{
	public:
		ArtMuseum();
		~ArtMuseum();
   		void deleteAll();
		void addPeice(std::string firstName, std::string lastName, std::string region, std::string date, std::string medium, std::string title, std::string description, int galleryNumber, int yearCreated);
		void searchPeice(std::string title);
		void searchArtist(std::firstName, std::lastName);
		void learnAbout(); //thought this could be cool... just a random display
		void printFacts(std::string title); //displays the general info about a specified peice
		void largestRegion(); //counts all the known regions that peices were created in and lists the top 5
		void galleryList(); //lists all peices in a specific gallery
		void isMore(std::string firstName, std::string lastName); //counts how many peices in collection artist has
		void displayIsMore(); //lists the top 3 artist that have the most peices in the collection
		 void printInventory();
	
	private:
		TreeNode * root;
};

#endif
