#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Pair{

public:
  Pair();
  Pair(T first_value, T second_value);
  void set_element(int position, T value);

  T_get_element(int position) const;

private:
  T first;
  T second;
};

template <class T>
void Pair<T>::set_element(int position, T value){

  if(position == 1)
    first = value;

  else if(position == 2)
    second = value;

  else{
    cout << "Error: Illegal pair positioning. \n";
    exit(1);
  }
}

template <class T>
Pair<T>::Pair(T first_value, T second_value) : first(first_value), second(second_value){
  //empty body
}
