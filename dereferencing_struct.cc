// This example is meant to see if passing a reference of an object to another 
// function by dereferencing its pointer will allow operations done in the 
// function to change the original object.

// Turns out, the function does change the original object.

#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct Struct
{
  int value1;
  int value2;
} Struct;

void modify_struct(Struct& data)
{
  data.value1 *= 2;
  data.value2 *= 3;
}

int main()
{
  Struct data;
  data.value1 = 5;
  data.value2 = 6;
  Struct* data_pointer = &data;

  cout << "Original data:\n" << "value1: " << data.value1 << endl;
  cout << "value2: " << data.value2 << endl;

  modify_struct(*data_pointer);

  cout << endl << "Data after function call:\n" 
    << "value1: " << data.value1 << endl;
  cout << "value2: " << data.value2 << endl;

  return EXIT_SUCCESS;
}