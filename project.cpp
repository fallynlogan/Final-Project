#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "project.hpp"

using namespace std;
void addToList(LLNode *prev, LLNode * NewNode);
void printTreeNode(TreeNode * travel);
void printLLNode(LLNode * head);

ArtMuseum::ArtMuseum()
{
  root = NULL;
}

void DeleteAll(TreeNode * node)
{
	if (node)
  {
    DeleteAll(node -> leftChild);
    LLNode * temp = node -> head;
    while(temp != nullptr)
    {
      LLNode * next = temp -> next;
      delete temp;
      temp = next;
    }
    DeleteAll(node -> rightChild);
    delete node;
  }
}

ArtMuseum::~ArtMuseum()
{
  DeleteAll(root);
  root = NULL;
}

void printLLNode(LLNode * head)
{
  LLNode * travel = new LLNode;
  travel = head;
  if (travel == nullptr) cout << "Nothing in list" << endl;
  while (travel != nullptr)
  {
    cout << " >> " << travel->title << " " << travel->lastName << endl;
    travel = travel->next;
  }
}

void printTreeNode(TreeNode * travel)
{
  if (travel)
  {
    printTreeNode(travel->leftChild);
    cout << "Artist's last name starting with the letter " << travel->nameChar << endl;
    printLLNode(travel->head);
    printTreeNode(travel->rightChild);
  }
}

void ArtMuseum::printInventory()
{
  printTreeNode(root);
}

void ArtMuseum::addPiece(std::string firstName, std::string lastName, std::string region, std::string date, std::string medium, std::string title, std::string description, int galleryNumber, int yearCreated)
{
	LLNode * newPiece = new LLNode;
	newPiece->firstName = firstName;
	newPiece->lastName = lastName;
	newPiece->region = region;
	newPiece->date = date;
	newPiece->medium = medium;
	newPiece->title = title;
	newPiece->description = description;
	newPiece->galleryNumber = galleryNumber;
	newPiece->yearCreated = yearCreated;

	TreeNode * newNode = new TreeNode;
	newNode->nameChar = lastName.at(0);
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	//case 1 nothing in tree
	if(root == NULL)
  {
		root = newNode;
		newNode->parent = NULL;
		newNode->head = newPiece;
		newPiece->next = NULL;
	}
	else
  {
		TreeNode * temp1 = root;
		int flag = 0;
		while(temp1 && flag == 0)
    {
			TreeNode * current = temp1;
			//first node in linked list
			if(newNode->nameChar == temp1->nameChar)
      {
				addToList(temp1->head, newPiece);
				flag = 1;
			}
			//traverse tree
			else if (newNode->nameChar < temp1->nameChar)
				temp1 = temp1->leftChild;
			else if (newNode->nameChar > temp1->nameChar)
				temp1 = temp1->rightChild;

			if(newNode->nameChar < current->nameChar && flag == 0){
				current->leftChild = newNode;
				current->leftChild->head = newPiece;
			}

			if(newNode->nameChar > current->nameChar && flag == 0){
				current->rightChild = newNode;
				current->rightChild->head = newPiece;
			}

			//sortTree(&current->head);
		}
	}
}

void addToList(LLNode *prev, LLNode * NewNode)
{
  LLNode * tempNode = new LLNode;
  tempNode = NewNode;
  tempNode->next = prev->next;
  prev->next = tempNode;
  tempNode = NULL;
}
