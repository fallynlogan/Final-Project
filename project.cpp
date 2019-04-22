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
void dispInOrder(TreeNode *n);

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

void dispInOrder(TreeNode *n)
{
    if(!n)
        return;
    dispInOrder(n -> leftChild);
    cout << "Pieces starting with letter: " << n -> nameChar  << endl;
    LLNode *temp = n -> head;
    while(temp != nullptr)
    {
        cout << " >> " << temp -> title << " " << temp -> lastName << endl;
        temp = temp -> next;
    }
    dispInOrder(n -> rightChild);
}

void ArtMuseum :: printInventory()
{
    dispInOrder(root);
}

TreeNode* findNode(TreeNode *n, std::string title)
{
   if(n != nullptr)
   {
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

/*void ArtMuseum::searchArtist(string firstName, string lastName)
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
  TreeNode * temp = findNode(root, title);
  search(title, temp->head);
}

void search(string title, LLNode * head)
{
  LLNode * temp = new LLNode;
  temp = head;
  while(temp)
  {
    if(temp->title == title)
    {
      cout<<temp->title<<endl;
      cout<<temp->firstName<<endl;
      cout<<temp->lastName<<endl;
      cout<<temp->region<<" ";
      cout<<temp->date<<endl;
      cout<<temp->yearCreated;
      cout<<temp->medium<<endl;
      cout<<temp->description<<endl;
      cout<<temp->galleryNumber<<endl;
      break;
    }
    else
      temp = temp->next;
  }
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
      else temp = temp->rightChild;
    }
    if (prev == nullptr) root = n;
    else if (n->nameChar < prev->nameChar)
    {
      prev->leftChild = n;
      n->parent = prev;
    }
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
}

void galleryListLL(LLNode * temp, int galleryNumber)
{
  while(temp!=nullptr)
  {
    if(temp->galleryNumber == galleryNumber)
    {
      cout<<temp->title<<endl<<temp->firstName<<" "<<temp->lastName<<endl<<" "<<endl;
      temp = temp->next;
    }
    else
    {
      temp = temp->next;
    }
  }
}

void galleryListRecur(TreeNode * current, int galleryNumber)
{ //pre order traversal 
  galleryListLL(current->head, galleryNumber);

  galleryListRecur(current->leftChild, galleryNumber);
  galleryListRecur(current->rightChild, galleryNumber);
}

void ArtMuseum::galleryList(int galleryNumber)
{
  cout<<"Pieces in gallery number: "<<galleryNumber<<endl;
  galleryListRecur(root, galleryNumber);
}

