//P15_1.cpp - Program to demonstrate the function head_insert.
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

struct Node{
  string item;
  int n_day, n_month, n_year;
  Node *link;
};

struct Date{
  int day;
  int month;
  int year;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, string an_item, int a_day, int a_month,
    int a_year);
void show_list(NodePtr& head);

int main(){
  struct Date Rolls = {8, 10, 2003};

  struct Date Jam = {9, 12, 2003};

  struct Date Tea = {1, 1, 2010};

  NodePtr head = NULL;
  head_insert(head, "Tea", Tea.day, Tea.month, Tea.year);
  head_insert(head, "Jam", Jam.day, Jam.month, Jam.year);
  head_insert(head, "Rolls", Rolls.day, Rolls.month, Rolls.year);

  show_list(head);

  return 0;
}

void head_insert(NodePtr& head, string an_item, int a_day, int a_month,
                  int a_year){
  NodePtr temp_ptr;
  temp_ptr = new Node;

  temp_ptr -> item = an_item;
  temp_ptr -> n_day = a_day;
  temp_ptr -> n_month = a_month;
  temp_ptr -> n_year = a_year;

  temp_ptr -> link = head;
  head = temp_ptr;
}

void show_list(NodePtr& head){
  NodePtr here = head;

  while(here != NULL){
    cout << here -> item << "\t";
    cout << here -> n_day << "/";
    cout << here -> n_month << "/";
    cout << here -> n_year << endl;

    here = here -> link;
  }
}
