//Program to demonstrate iterative version of binary search.
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

template <class BaseType>
void search(const BaseType a[], int low_end, int high_end, BaseType key,
              bool& found, int& location);

//Precondition: a[low_end] through a[high_end] are sorted in increasing order.
//Postcondition: If key is not one of the values a[low_end] through a[high_end],
// then found == false; otherwise a[location] == key and found == true.

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
void search(const BaseType a[], int low_end, int high_end, BaseType key,
                bool& found, int& location){

    int first = low_end;
    int last = high_end;
    int mid;

    found = false; //so far
    while((first <= last) && !(found)){
      mid = (first + last) / 2;
      if(key == a[mid]){
        found = true;
        location = mid;
      }else if(key < a[mid]){
        last = mid - 1;
      }else if(key > a[mid]){
        first = mid + 1;
      }
    }
}
