//Program to demonstrate the recursive function for binary search.
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

template <class BaseType>
void search(const BaseType a[], int first, int last, BaseType key, bool& found, int& location);
//Precondition: a[first] through a[last] are stored in increasing order.
//Postcondition: if key is not one of the values a[first] through a[last],
//then found == FALSE; otherwise a[location] == key and found == TRUE.

int main(){

  int a[ARRAY_SIZE];
  char c[ARRAY_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  const int final_index = ARRAY_SIZE - 1;

  int i;
  for (i = 0; i < 10; i++){
    a[i] = 2 * i;
  }

  int int_key, location, choice;
  char cha_key;
  bool found;

  cout << "Would you like to search an array of type integer(1) or char(2)?" << endl;
  cin >> choice;

  switch(choice){
    case 1:
      cout << "Enter number to be located: ";
      cin >> int_key;
      search(a, 0, final_index, int_key, found, location);

      if(found)
        cout << int_key << " is in index location " << location << endl;
      else
        cout << int_key << " is not in the array." << endl;

      break;

    case 2:
      cout << "Enter character to be located: ";
      cin >> cha_key;
      search(c, 0, final_index, cha_key, found, location);

      if(found)
        cout << cha_key << " is in index location " << location << endl;
      else
        cout << cha_key << " is not in the array." << endl;

      break;

    default:
      cout << "That is not a valid input." << endl;
      break;
    }

  return 0;
}

template <class BaseType>
void search(const BaseType a[], int first, int last, BaseType key, bool& found, int& location){

  int mid;
  if(first > last)
    found = false;
  else{
    mid = (first + last) / 2;

    if(key == a[mid]){
      found = true;
      location = mid;
    }else if(key < a[mid]){
      search(a, first, mid - 1, key, found, location);
    }else if(key > a[mid]){
      search(a, mid + 1, last, key, found, location);
    }
  }
}
