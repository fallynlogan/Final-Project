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
