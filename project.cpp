#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "project.hpp"

using namespace std;

ArtMuseum::ArtMuseum()
{
  root = NULL;
}

ArtMuseum::~ArtMuseum()
{
  DeleteAll(root);
  root = NULL;
}

void ArtMuseum::DeleteAll(TreeNode * node)
{
	if(node -> leftChild) DeleteAll(node -> leftChild);
	if(node -> rightChild) DeleteAll(node -> rightChild);

	LLNode * current = node -> head;
	LLNode * temp = current;

	while(current)
  {
		temp = current;
		cout << "Deleting: "<< current -> title << endl;
		delete current;

		if(temp -> next) current = temp -> next;
		else
			break;
	}
}

void ArtMuseum::printInventory()
{
  printInventory(root);
}

void ArtMuseum::printInventory(TreeNode * node)
{
  if (node -> leftChild) printMovieInventory(node -> leftChild);

  LLNode * current = node -> head;

  while(current)
  {
    cout<< "Piece:  "<< current -> title << " Artist's last name: " << current -> lastName << endl;
    current = current -> next;
  }
  if(node -> rightChild) printMovieInventory(node -> rightChild);
}
