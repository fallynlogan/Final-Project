#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "project.hpp"

using namespace std;

void addToList(LLNode *prev, LLNode * NewNode);
void printTreeNode(TreeNode * travel);
void printLLNode(LLNode * head);
void search(string title, LLNode * head);

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
    cout << " >> " << travel->title << " by " << travel->lastName << endl;
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
    *right = *p;
    if(sorted)
    {
      *p = *left;
      *left = nullptr;
    }
    else
    {
      *p = tempNode;
      break;
    }
	}
}

/*void ArtMuseum::searchArtist(string firstName, string lastName, LLNode * head)
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
}*/

void ArtMuseum::searchPiece(std::string title)
{
  cout << root->head->title << endl;
  cout << root->head->next->title << endl;
  search(title, root->head);
}

void search(string title, LLNode * head)
{
  cout << "HERE" << endl;
	LLNode * temp = new LLNode;
  cout << temp->title << endl;
	temp = head;
	while(temp)
	{
    cout << "HERE" << endl;
		if(temp->title == title)
    {
      cout << "HERE" << endl;
			cout<<temp->title<<endl;
			cout<<temp->firstName<<endl;
			cout<<temp->lastName<<endl;
			cout<<temp->region<<" ";
			cout<<temp->date<<endl;
			cout<<temp->yearCreated;
			cout<<temp->medium<<endl;
			cout<<temp->description<<endl;
			cout<<temp->galleryNumber<<endl;
		}
		else
			temp = temp->next;
	}
}

/*TreeNode* findNode(TreeNode *n, std::string title){
   if(n != nullptr){
       if(n -> nameChar == title[0])
           return n;
       else if(n -> nameChar > title[0])
           return findNode(n -> leftChild, title);
       else
           return findNode(n -> rightChild, title);
   }
    else
        return nullptr;
}

void ArtMuseum::addPiece(std::string firstName, std::string lastName, std::string region, std::string date, std::string title, std::string yearCreated, std::string medium, std::string aquired, std::string description, int galleryNumber)
{
  TreeNode * location = findNode(root, title);
  if (location == nullptr)
  {
    TreeNode *prev = nullptr;
    TreeNode *temp = root;
    TreeNode * n = new TreeNode;
    n -> nameChar = title[0];
    while(temp != nullptr)
    {
      prev = temp;
      if (n->nameChar < temp->nameChar) temp = temp->leftChild;
      else if(temp = temp->rightChild);
      else
      {
        prev->rightChild = n;
        n->parent = prev;
      }
      temp = nullptr;
      prev = nullptr;

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
      newPiece->aquired = aquired;
    }
  }
  else
  {
    LLNode * current;
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
    newPiece->aquired = aquired;
    if (location->head == nullptr or location->head->title >= newPiece->title)
    {
      newPiece->next = location->head;
      location->head = newPiece;
    }
    else
    {
      current = location->head;
      while(current->next != nullptr and current->next->title < newPiece->title)
      {
        current = current->next;
      }
      newPiece->next = current->next;
      current->next = newPiece;
    }
  }
}*/

void ArtMuseum::addPiece(std::string firstName, std::string lastName, std::string region, std::string date, std::string title, std::string yearCreated, std::string medium, std::string aquired, std::string description, int galleryNumber)
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
  newPiece->aquired = aquired;

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
			if(newNode->nameChar == temp1->nameChar)
      {
				addToList(temp1->head, newPiece);
				flag = 1;
			}
			else if (newNode->nameChar < temp1->nameChar)
				temp1 = temp1->leftChild;
			else if (newNode->nameChar > temp1->nameChar)
				temp1 = temp1->rightChild;

			if(newNode->nameChar < current->nameChar && flag == 0)
      {
				current->leftChild = newNode;
				current->leftChild->head = newPiece;
			}

			if(newNode->nameChar > current->nameChar && flag == 0){
				current->rightChild = newNode;
				current->rightChild->head = newPiece;
			}
			sortTree(&current->head);
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
