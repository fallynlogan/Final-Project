#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "project.hpp"

using namespace std;

void addToList(LLNode *prev, LLNode * NewNode);
void printTreeNode(TreeNode * travel);
void search(string title, LLNode * head);
void dispInOrder(TreeNode *n);
void regionRecur(TreeNode * current);
void searchArtistRecur(TreeNode * node, string firstName, string lastName);

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

void dispInOrder(TreeNode *n)
{
    if(!n) return;
    dispInOrder(n -> leftChild);
    cout << "Pieces starting with letter: " << n -> nameChar  << endl;
    LLNode *temp = n -> head;
    while(temp != nullptr)
    {
        cout << " >> " << temp -> title << " by " << temp -> lastName << endl;
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

void searchArtistRecur(TreeNode * node, string firstName, string lastName)
{
  if(!node) return;
  searchArtistRecur(node -> leftChild, firstName, lastName);
  LLNode *temp = node -> head;
  while(temp != nullptr)
  {
      if (lastName.compare(temp->lastName) == 0 and firstName.compare(temp->firstName) == 0)
      {
        cout << temp->title << endl;
      }
      temp = temp->next;
  }
  searchArtistRecur(node -> rightChild, firstName, lastName);
}

void ArtMuseum::searchArtist(string firstName, string lastName)
{
  cout << endl << "Pieces by " << firstName << " " << lastName << ":" << endl;
  searchArtistRecur(root, firstName, lastName);
}

void ArtMuseum::searchPiece(std::string title)
{
  TreeNode * temp = findNode(root, title);
  cout << endl;
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
      cout<<"    Title:           " << temp->title<< endl;
      cout<<"    Artist:          " <<temp->firstName<< " ";
      cout<<temp->lastName<<endl;
      cout<<"    Region:          " <<temp->region<<" ";
      cout<<temp->date<<endl;
      cout<<"    Year Created:    " <<temp->yearCreated<<endl;
      cout<<"    Medium:          " <<temp->medium<<endl;
      cout<<"    Description      " <<temp->description<<endl;
      cout<<"    Gallery Number:  " <<temp->galleryNumber<<endl;
      cout<<"    Aquired:         " <<temp->aquired<<endl;
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
    n->head = newPiece;
    newPiece->next=NULL;

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

void galleryListRecur(TreeNode * current, int galleryNumber)
{
  if (!current) return;
  galleryListRecur(current->leftChild, galleryNumber);
  LLNode * temp = current->head;
  while (temp != nullptr)
  {
    if(temp->galleryNumber == galleryNumber)
    {
      cout<< "     " << temp->title<<endl<< "      " << temp->firstName<<" "<<temp->lastName<<endl<<" "<<endl;
    }
    temp = temp->next;
  }
  galleryListRecur(current->rightChild, galleryNumber);
}

void ArtMuseum::galleryList(int galleryNumber)
{
  cout<< endl << "Pieces in gallery number: "<<galleryNumber<<endl<<endl;
  galleryListRecur(root, galleryNumber);
}

HashTable::HashTable(int bsize)
{
    this -> tableSize = bsize;
    hashTable = new hashNode*[tableSize];
    for(int i=0; i<bsize; i++) hashTable[i] = nullptr;
}

bool HashTable::isInTable(string data)
{
  int index = getHash(data);
  hashNode * temp = hashTable[index];
  while (temp && temp->data != data) temp = temp->next;
  if (temp) return true;
  else return false;
}

void HashTable::insertItem(string key){
    if (!isInTable(key))
    {
      hashNode * temp = new hashNode;
      temp->data = key;
      temp->count = 0;
      temp->next = nullptr;

      int index = getHash(key);
      if (hashTable[index]) numCollisions++;
      temp->next = hashTable[index];
      hashTable[index] = temp;
      numItems++;
      addCount(key);
    }
    else addCount(key);
}

void HashTable::addCount(string key)
{
  int index = getHash(key);
  hashNode * temp = hashTable[index];
  while(temp->data != key) temp = temp->next;
  temp->count++;
}

unsigned int HashTable::getHash(string key)
{
  unsigned int hashValue = 5381;
  int length = key.length();
  for (int i = 0; i < length; i++) hashValue = ((hashValue<<5)+hashValue) + key[i];
  hashValue %= tableSize;
  return hashValue;
}

void HashTable::printTop(int n)
{
    int i, j, k;
    hashNode ** top = new hashNode * [n];
    for (i = 0; i < n; i++)
    {
      top[i] = nullptr;
    }
    for (i = 0; i < tableSize; i++)
    {
      hashNode * temp = hashTable[i];
      while(temp)
      {
        for (j = 0; j < n && top[j]; j++)
          if (temp->count > top[j]->count) break;
        if (j < n)
        {
          for (k = n-1; k >= j; k--)
            if (k+1 != n) top[k+1] = top[k];
          top[j] = temp;
        }
        temp = temp->next;
      }
    }
    for (i = 0; i < n; i++)
    {
      hashNode * temp = top[i];
      if (temp) cout << "     " << temp->data << endl;
    }
    delete[] top;
}
