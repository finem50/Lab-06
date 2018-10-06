//This is a generic sorting function

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

template <class T>
void swap_values(T& variable1, T& variable2){

  T temp;

  temp = variable1;
  variable1 = variable2;
  variable2 = temp;
}

template <class BaseType>
int index_of_smallest(const BaseType a[], int start_index, int number_used){

  BaseType min = a[start_index];
  int index_of_min = start_index;

  for (int index = start_index + 1; index < number_used; index ++){
    if (a[index] < min){
      min = a[index];
      index_of_min = index;
      //min is the smallest of a[start_index] through a[index]

    }

  }

  return index_of_min;
}

template <class BaseType>
void sort(BaseType a[], int number_used){

  int index_of_next_smallest;
  for (int index = 0; index < number_used - 1; index++){
    //Place the correct value in a[index]:
    index_of_next_smallest = index_of_smallest(a, index, number_used);
    swap_values(a[index], a[index_of_next_smallest]);
    //a[0] <= a[1] <= ... <= a[index] are the smallest of the original array
    //elements. The rest of the elements are in the remaining positions.

  }
}

template <class BaseType>
void search(const BaseType array[], int first, int last, BaseType key, bool& found, int& location){

  int mid;
  if(first > last){
    found = false;

  }else{
    mid = (first + last) / 2;

    if(key == array[mid]){
      found = true;
      location = mid;

    }else if(key < array[mid]){
      search(array, first, mid - 1, key, found, location);

    }else if(key > array[mid]){
      search(array, mid + 1, last, key, found, location);

    }

  }
}


int main(){

  int a[ARRAY_SIZE] = {1, 2, 3, 4, 8, 9, 20, 3, 2, 10};
  double b[ARRAY_SIZE] = {1.1, 2.3, 3.2, 4.1, 8.3, 9.4, 20.5, 3.0, 2.1, 10.0};
  char c[ARRAY_SIZE] = {'G', 'E', 'N', 'E', 'R', 'I', 'C'};
  int i, location;
  int iKey;
  double dKey;
  char cKey;
  bool found;
  char choice;
  const int final_index = ARRAY_SIZE - 1;

  cout << "Would you like to operate with an array of type integer (a), double (b)"
        << " or char (c)?\n";
  cin >> choice;

  switch(choice){

    case 'a':
      cout << "The contents of the integer array: " << endl;
      for (i = 0; i < ARRAY_SIZE; i++){
        cout << a[i] << " ";
      }
      cout << endl;

      cout << "The contents of the array after sorting:\n";
      sort(a, ARRAY_SIZE);
      for(i = 0; i < ARRAY_SIZE; i++){
        cout << a[i] << " ";
      }
      cout << endl;

      cout << "Enter number to be located: ";
      cin >> iKey;
      search(a, 0, final_index, iKey, found, location);

      if(found)
        cout << iKey << " is in index location " << location << endl;

      else
        cout << iKey << " is not in the array." << endl;

      break;


    case 'b':
      cout << "The contents of the double array: " << endl;
      for (i = 0; i < ARRAY_SIZE; i++){
        cout << b[i] << " ";
      }
      cout << endl;

      cout << "The contents of the array after sorting:\n";
      sort(b, ARRAY_SIZE);
      for(i = 0; i < ARRAY_SIZE; i++){
        cout << b[i] << " ";
      }
      cout << endl;

      cout << "Enter number to be located: ";
      cin >> dKey;
      search(b, 0, final_index, dKey, found, location);

      if(found)
        cout << dKey << " is in index location " << location << endl;

      else
        cout << dKey << " is not in the array." << endl;

      break;


    case 'c':
      cout << "The contents of the character array: " << endl;
      for (i = 0; i < ARRAY_SIZE; i++){
        cout << c[i] << " ";
      }
      cout << endl;

        cout << "The contents of the array after sorting:\n";
      sort(c, ARRAY_SIZE);
      for(i = 0; i < ARRAY_SIZE; i++){
        cout << c[i] << " ";
      }
      cout << endl;

      cout << "Enter character to be located: ";
      cin >> cKey;
      search(c, 0, final_index, cKey, found, location);

      if(found)
        cout << cKey << " is in index location " << location << endl;

      else
        cout << cKey << " is not in the array." << endl;

      break;

  }


  return 0;
}
