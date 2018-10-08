//Program to demonstrate the function insert.
//It asks users to input an item and the count and will ask
//them where they want to insert the new node. If the request
//is valid, the new node will be inserted.

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

void remove(NodePtr after_me, string an_item);
void insert(NodePtr after_me, string an_item, int a_number);
void head_insert(NodePtr& head, string an_item, int a_number);
void show_list(NodePtr& head);
NodePtr search(NodePtr head, string target);

int main(){

  string new_item, target;
  int new_count, choice;
  NodePtr head = NULL;
  head_insert(head, "Tea", 2);
  head_insert(head, "Jam", 3);
  head_insert(head, "Rolls", 10);

  cout << "List contains: " << endl;
  show_list(head);

  NodePtr after_me = head;
  after_me = after_me -> link;

  cout << "Would you like to insert(1) or delete(2) an item?" << endl;
  cin >> choice;

  switch(choice){

    case 1:{
      cout << "Enter the item you wish to insert (string) \n";
      cin >> new_item;
      cout << "Enter the count of new item \n";
      cin >> new_count;

      cout << "Enter the item after which you want to insert the new node" << endl;
      cin >> target;
      after_me = search(head, target);

      if(after_me != NULL){
        cout << "\nWill insert " << new_item << " with count" << endl
            << new_count << " after the node with "
            << (after_me -> item) << endl << endl;
        insert(after_me, new_item, new_count);

        cout << "List now contains:" << endl;
        show_list(head);
      }else{
        cout << "I can't find " << target
            << " in the list, so I can't insert anything \n";
      }

      break;
    }

    case 2:{

    }
  }



  return 0;
}

void remove(struct Node *head, struct Node *n){
  //Node before target must point to node after target


}

//Uses cstddef:
void insert(NodePtr after_me, string an_item, int a_number){
  NodePtr temp_ptr;
  temp_ptr = new Node;

  temp_ptr -> item = an_item;
  temp_ptr -> count = a_number;

  temp_ptr -> link = after_me -> link;
  after_me -> link = temp_ptr;
}

//Uses cstddef:
void head_insert(NodePtr& head, string an_item, int a_number){
  NodePtr temp_ptr;
  temp_ptr = new Node;

  temp_ptr -> item = an_item;
  temp_ptr -> count = a_number;

  temp_ptr -> link = head;
  head = temp_ptr;
}

//Uses iostream and cstddef:
void show_list(NodePtr& head){
  NodePtr here = head;

  while(here != NULL){
    cout << here -> item << "\t";
    cout << here -> count << endl;
    here = here -> link;
  }
}

NodePtr search(NodePtr head, string target){
  //Point to the head Node
  NodePtr here = head;

  //If the list is empty nothing to search
  if(here == NULL){
    return NULL;
    
  }else{
    //While you have still items and you haven't found the target yet
    while(here -> item != target && here -> link != NULL)
      here = here -> link;
      //Found the target, return the pointer at that location
      if(here -> item == target)
        return here;
      //Search unsuccessful, return Null
      else
        return NULL;

  }
}
