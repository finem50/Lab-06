//P15_1.cpp - Program to demonstrate the function head_insert.
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

struct Node{
  string item;
  int count;
  Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, string an_item, int a_number);
void show_list(NodePtr& head);

int main(){

  NodePtr head = NULL;
  head_insert(head, "Tea", 2);
  head_insert(head, "Jam", 3);
  head_insert(head, "Rolls", 10);

  show_list(head);

  return 0;
}

void head_insert(NodePtr& head, string an_item, int a_number){
  NodePtr temp_ptr;
  temp_ptr = new Node;

  temp_ptr -> item = an_item;
  temp_ptr -> count = a_number;

  temp_ptr -> link = head;
  head = temp_ptr;
}

void show_list(NodePtr& head){
  NodePtr here = head;

  while(here != NULL){
    cout << here -> item << "\t";
    cout << here -> count << endl;

    here = here -> link;
  }
}
