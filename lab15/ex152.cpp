//P15_2.cpp - Program to demonstrate the function search

#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

struct Node{
  string item;
  int count, date_item;
  int n_day, n_month, n_year;
  Node *link;
};

struct Date{
  int day;
  int month;
  int year;
};

typedef Node* NodePtr;

NodePtr search(NodePtr head, string an_item);
NodePtr search(NodePtr head, int a_day, int a_month, int a_year);
void head_insert(NodePtr& head, string an_item, int a_day, int a_month,
    int a_year);
void show_list(NodePtr& head);

int main(){

  int choice, search_day, search_month, search_year;

  struct Date Rolls = {8, 10, 2003};
  struct Date Jam = {9, 12, 2003};
  struct Date Tea = {1, 1, 2010};

  NodePtr head = NULL;
  head_insert(head, "Tea", Tea.day, Tea.month, Tea.year);
  head_insert(head, "Jam", Jam.day, Jam.month, Jam.year);
  head_insert(head, "Rolls", Rolls.day, Rolls.month, Rolls.year);

  cout << "List contains:" << endl;
  show_list(head);

  cout << "Would you like to search by item(1) or expiration date(2)?" << endl;
  cin >> choice;

  string target;

  switch(choice){
    case 1: {
      cout << "Enter an item to search for" << endl;
      cin >> target;
      NodePtr result = search(head, target);
      if(result == NULL)
        cout << target << " is not on the list." << endl;
      else
        cout << target << " is on the list." << endl;

      break;

    }

    case 2:{
      cout << "Enter a date to search for" << "\nDay: ";
      cin >> search_day;
      cout << "Month: ";
      cin >> search_month;
      cout << "Year: ";
      cin >> search_year;
      NodePtr date_result = search(head, search_day, search_month, search_year);
      if(date_result == NULL)
        cout << search_day << "/" << search_month << "/" << search_year <<
          " is not on the list." << endl;
      else
        cout << search_day << "/" << search_month << "/" << search_year <<
          " is on the list." << endl;

      break;
    }

  }

  return 0;
}

NodePtr search(NodePtr head, string target){
  //Point to the head node
  NodePtr here = head;

  //If the list is empty nothing to search
  if(here == NULL){
    return NULL;

  }else{
    //While you have still items and you haven't found the target yet
    while (here -> item != target && here -> link != NULL)
      here = here -> link;

    //Found the target, return the pointer at that location
    if(here -> item == target)
      return here;

    //Search unsuccessful, return NULL
    else
      return NULL;
  }
}

//Overloaded search function for searching date instead of item name
NodePtr search(NodePtr head, int a_day, int a_month, int a_year){
  //Point to the head node
  NodePtr here = head;

  //If the list is empty nothing to search
  if(here == NULL){
    return NULL;

  }else{
    //While you have still items and you haven't found the target yet
    while (here -> date_item != a_day && here -> link != NULL)
      here = here -> link;

      //Found the target, return the pointer at that location
      if(here -> date_item == a_day && a_month && a_year)
        return here;

      //Search unsuccessful, return NULL
      else
        return NULL;
  }
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
    cout << here -> item << endl;
    cout << here -> n_day << "/";
    cout << here -> n_month << "/";
    cout << here -> n_year << endl;

    here = here -> link;
  }
}
