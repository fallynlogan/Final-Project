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
	char nameChar;//first letter of title (A,B,C.. ect. )

	TreeNode *parent = NULL;
	TreeNode *leftChild = NULL;
	TreeNode *rightChild = NULL;
	LLNode * head = NULL;
};

struct hashNode
{
	std::string data;
	int count;
	struct hashNode* next;
};

class ArtMuseum
{
	public:
		ArtMuseum();
		~ArtMuseum();
		void addPiece(std::string firstName, std::string lastName, std::string region, std::string date, std::string title, std::string yearCreated, std::string medium, std::string aquired, std::string description, int galleryNumber);
		void searchPiece(std::string title);
		void searchArtist(std::string firstName, std::string lastName);
		void galleryList(int gallery); //lists all pieces in a specific gallery
    void printInventory();

	private:
		TreeNode * root;
};

class HashTable
{
	int tableSize;
	hashNode ** hashTable;
	int numItems;
	int numCollisions;
	unsigned int getHash(std::string region);

	public:
		HashTable(int bsize);
		void insertItem(std::string key);
		void addCount(std::string key);
		void printTop(int n);
		bool isInTable(std::string data);
};

#endif
