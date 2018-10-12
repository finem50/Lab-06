#include <iostream>
#include <cstdlib>

using namespace std;

class PartFilledArray{

public:
  PartFilledArray(int array_size);
  PartFilledArray(const PartFilledArray& object);
  ~PartFilledArray();
  void operator = (const PartFilledArray& right_side);
  void add_value(double new_entry);
  //other member functions ...

protected:
  double *a;
  int max_number;
  int number_used;

};

PartFilledArray::PartFilledArray(int array_size) : max_number(array_size), number_used(0){

  a = new double[max_number];
}


PartFilledArray::~PartFilledArray(){}
