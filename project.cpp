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


void addPeice(std::string firstName, std::string lastName, std::string region, std::string date, std::string medium, std::string title, std::string description, int galleryNumber, int yearCreated)
{
	LLNode * newPeice = new LLNode;
	newPeice->firstName = firstName;
	newPeice->lastName = lastName;
	newPeice->region = region;
	newPeice->date = date;
	newPeice->medium = medium;
	newPeice->title = title;
	newPeice->description = description;
	newPeice->galleryNumber = galleryNumber;
	newPeice->yearCreated = yearCreated;

	TreeNode * newNode = new TreeNode;
	newNode->nameChar = lastName.at(0);
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	//case 1 nothing in tree 
	if(root == NULL){
		root = newNode;
		newNode->parent = NULL;
		newNode->head = newMovie;
		newPeice->next = NULL;
	}
	else{
		TreeNode * temp1 = root;
		TreeNode * current - NULL;
		int flag = 0;
		while(temp1 && flag == 0){
			current = temp1;
			//first node in linked list
			if(newNode->nameChar == temp1->nameChar){
				addToList(temp1->head, newPeice);
				flag = 1;
			}
			//traverse tree
			else if (newNode->nameChar < temp1->nameChar)
				temp1 = temp1->leftChild;
			else if (newNode->nameChar > temp1->nameChar)
				temp1 = temp1->rightChild;

			if(newNode->nameChar < current->nameChar && flag == 0){
				current->leftChild = newNode;
				current->leftChild->head = newPeice;
			}

			if(newNode->nameChar > current->nameChar && flag == 0){
				current->rightChild = newNode;
				current->rightChild->head = newPeice;
			}

			//sortTree(&current->head);
		}
	}
}


void addToList(LLNode *prev, LLNode * NewNode){
  LLNode * tempNode = new LLNode;
  tempNode = NewNode;
  tempNode->next = prev->next;
  prev->next = tempNode;
  tempNode = NULL;
}

void sortTree(LLNode ** p)
{
	LLNode * tempNode = *p;
	*p = NULL;
	while(tempNode)
	{
		LLNode ** left = &tempNode;
		LLNode ** right = &tempNode->next;
		bool sorted = false;
		while(*right)
		{
			if((*right)->lastName < (*left)->lastName)
			{
				std::swap(*left, *right);
				std::swap((*left)->next, (*right)->next);
				left = &(*left)->next;
				sorted = true;
			}
			else
			{
				left = right;
				right = &(*right)->next;
			}
		}
	}
}

void searchArtist(std::firstName, std::lastName, LLNode * head)
{
	LLNode * temp = new LLNode;
	temp = head;
	while(temp)
	{
		if(temp->firstName == firstName && temp->lastName == lastName)
			cout<<temp->title<<endl;
		else
			temp = temp->next;
	}
}
